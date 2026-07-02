function export_slx_structure()
% Export readable structure from all .slx models in current folder.
% Run this script from the repository root.

outDir = fullfile(pwd, "slx_export");
if ~exist(outDir, "dir")
    mkdir(outDir);
end

models = dir("*.slx");

for k = 1:numel(models)
    modelFile = models(k).name;
    [~, modelName, ~] = fileparts(modelFile);

    fprintf("Loading %s...\n", modelFile);

    try
        load_system(modelFile);
    catch ME
        warning("Failed to load %s: %s", modelFile, ME.message);
        continue;
    end

    safeName = matlab.lang.makeValidName(modelName);

    % Basic model parameters
    modelInfo = struct();
    modelInfo.ModelName = modelName;
    modelInfo.Solver = safeGet(modelName, "Solver");
    modelInfo.FixedStep = safeGet(modelName, "FixedStep");
    modelInfo.SystemTargetFile = safeGet(modelName, "SystemTargetFile");
    modelInfo.HardwareBoard = safeGet(modelName, "HardwareBoard");
    modelInfo.StopTime = safeGet(modelName, "StopTime");

    writeText(fullfile(outDir, safeName + "_model_info.json"), ...
        jsonencode(modelInfo, PrettyPrint=true));

    % Blocks
    blocks = find_system(modelName, ...
        "LookUnderMasks", "all", ...
        "FollowLinks", "on", ...
        "Type", "Block");

    blockRows = {};
    for i = 1:numel(blocks)
        b = blocks{i};

        row = struct();
        row.Path = b;
        row.Name = safeGet(b, "Name");
        row.BlockType = safeGet(b, "BlockType");
        row.MaskType = safeGet(b, "MaskType");
        row.LinkStatus = safeGet(b, "LinkStatus");
        row.ReferenceBlock = safeGet(b, "ReferenceBlock");
        row.SampleTime = safeGet(b, "SampleTime");
        row.Position = safeGet(b, "Position");

        blockRows{end+1} = row; %#ok<AGROW>
    end

    writeText(fullfile(outDir, safeName + "_blocks.json"), ...
        jsonencode(blockRows, PrettyPrint=true));

    % Lines / connectivity
    lines = find_system(modelName, ...
        "FindAll", "on", ...
        "Type", "line");

    lineRows = {};
    for i = 1:numel(lines)
        ln = lines(i);

        row = struct();
        row.SrcBlock = safeGetLine(ln, "SrcBlockHandle");
        row.SrcPort = safeGetLine(ln, "SrcPortHandle");
        row.DstBlock = safeGetLine(ln, "DstBlockHandle");
        row.DstPort = safeGetLine(ln, "DstPortHandle");
        row.Name = safeGetLine(ln, "Name");

        lineRows{end+1} = row; %#ok<AGROW>
    end

    writeText(fullfile(outDir, safeName + "_lines.json"), ...
        jsonencode(lineRows, PrettyPrint=true));

    % Model references
    refs = find_system(modelName, ...
        "LookUnderMasks", "all", ...
        "FollowLinks", "on", ...
        "BlockType", "ModelReference");

    refRows = {};
    for i = 1:numel(refs)
        row = struct();
        row.Path = refs{i};
        row.ModelName = safeGet(refs{i}, "ModelName");
        refRows{end+1} = row; %#ok<AGROW>
    end

    writeText(fullfile(outDir, safeName + "_model_references.json"), ...
        jsonencode(refRows, PrettyPrint=true));

    % Try to export top-level screenshot
    try
        open_system(modelName);
        print(["-s" modelName], "-dpng", "-r200", ...
            fullfile(outDir, safeName + "_top.png"));
    catch ME
        warning("Failed to export screenshot for %s: %s", modelName, ME.message);
    end

    % Stateflow / MATLAB Function blocks
    try
        rt = sfroot;
        charts = rt.find("-isa", "Stateflow.Chart");
        emcharts = rt.find("-isa", "Stateflow.EMChart");

        sfRows = {};
        for i = 1:numel(charts)
            if startsWith(charts(i).Path, modelName)
                row = struct();
                row.Type = "Stateflow.Chart";
                row.Path = charts(i).Path;
                row.Name = charts(i).Name;
                row.Script = "";
                sfRows{end+1} = row; %#ok<AGROW>
            end
        end

        for i = 1:numel(emcharts)
            if startsWith(emcharts(i).Path, modelName)
                row = struct();
                row.Type = "MATLABFunction";
                row.Path = emcharts(i).Path;
                row.Name = emcharts(i).Name;
                row.Script = emcharts(i).Script;
                sfRows{end+1} = row; %#ok<AGROW>
            end
        end

        writeText(fullfile(outDir, safeName + "_stateflow_matlabfunction.json"), ...
            jsonencode(sfRows, PrettyPrint=true));
    catch ME
        warning("Stateflow export failed for %s: %s", modelName, ME.message);
    end

    close_system(modelName, 0);
end

fprintf("Export finished. See folder: %s\n", outDir);

end

function val = safeGet(obj, param)
try
    val = get_param(obj, param);
catch
    val = "";
end
end

function val = safeGetLine(lineHandle, param)
try
    h = get_param(lineHandle, param);
    if isnumeric(h)
        if h == -1
            val = "";
        else
            try
                val = getfullname(h);
            catch
                val = string(h);
            end
        end
    else
        val = h;
    end
catch
    val = "";
end
end

function writeText(path, txt)
fid = fopen(path, "w");
cleanup = onCleanup(@() fclose(fid));
fprintf(fid, "%s", txt);
end
