% Model         :   PMSM Field Oriented Control
% Description   :   Set Parameters for PMSM Field Oriented Control
% File name     :   mcb_pmsm_foc_sensorless_dyno_f28379d_datascript.m

% Copyright 2021 The MathWorks, Inc.

%% Simulation parameters

%% Set PWM Switching frequency
PWM_frequency 	= 20e3;             %Hz // converter s/w freq
T_pwm           = 1/PWM_frequency;  %s  // PWM switching time period

%% Set Sample Times
Ts          	= T_pwm;        %sec        // simulation time step for controller
Ts_simulink     = T_pwm/2;      %sec        // simulation time step for model simulation
Ts_motor        = T_pwm/2;      %Sec        // Simulation sample time
Ts_inverter     = T_pwm/2;      %sec        // simulation time step for average value inverter
Ts_speed        = 20*Ts;        %Sec        // Sample time for speed controller

%% Set data type for controller & code-gen
% Uncomment the required data type and comment out the other
%dataType = fixdt(1,32,24);    % Fixed point code-generation
dataType = 'single';            % Floating point code-generation

%% System Parameters

% pmsm_motor1 = mcb_SetPMSMMotorParameters('Teknic2310P');
% 
% pmsm_motor2 = mcb_SetPMSMMotorParameters('Teknic2310P');
        pmsm_motor1.model    = 'JIEMEIKANG42JSF360AS-1000';     %           // Manufacturer Model Number
        pmsm_motor1.sn       = '0042';              %           // Manufacturer Model Number
        pmsm_motor1.p        = 4;                  %           // Pole Pairs for the motor
        pmsm_motor1.Rs       = 0.89;               %Ohm        // Stator Resistor
        pmsm_motor1.Ld       = 0.64e-3;             %H          // D-axis inductance value
        pmsm_motor1.Lq       = 0.64e-3;             %H          // Q-axis inductance value
        pmsm_motor1.J        = 2.8e-5;  %Kg-m2      // Inertia in SI units
        pmsm_motor1.B        = 3.5e-4;  %Kg-m2/s    // Friction Co-efficient
        pmsm_motor1.Ke       = 4;               %Bemf Const	// Vpk_LL/krpm
        pmsm_motor1.Kt       = 0.059;             %Nm/A       // Torque constant
        pmsm_motor1.I_rated  = 4;                %A      	// Rated current (phase-peak)
        pmsm_motor1.N_max    = 4000;               %rpm        // Max speed
        pmsm_motor1.PositionOffset = 0.1458;	    %PU position// Position Offset
        pmsm_motor1.QEPSlits = 1000;               %           // QEP Encoder Slits
        pmsm_motor1.FluxPM   = (pmsm_motor1.Ke)/(sqrt(3)*2*pi*1000*pmsm_motor1.p/60); %PM flux computed from Ke
		% pmsm.FluxPM = (pmsm.Kt)/((3/2)*pmsm.p); %PM flux computed from Kt
        pmsm_motor1.T_rated  = mcbPMSMRatedTorque(pmsm_motor1);   %Get T_rated from I_rated

        pmsm_motor2.model    = 'JIEMEIKANG42JSF360AS-1000';     %           // Manufacturer Model Number
        pmsm_motor2.sn       = '0042';              %           // Manufacturer Model Number
        pmsm_motor2.p        = 4;                  %           // Pole Pairs for the motor
        pmsm_motor2.Rs       = 0.89;               %Ohm        // Stator Resistor
        pmsm_motor2.Ld       = 0.64e-3;             %H          // D-axis inductance value
        pmsm_motor2.Lq       = 0.64e-3;             %H          // Q-axis inductance value
        pmsm_motor2.J        = 2.8e-5;  %Kg-m2      // Inertia in SI units
        pmsm_motor2.B        = 3.5e-4;  %Kg-m2/s    // Friction Co-efficient
        pmsm_motor2.Ke       = 4;               %Bemf Const	// Vpk_LL/krpm
        pmsm_motor2.Kt       = 0.059;             %Nm/A       // Torque constant
        pmsm_motor2.I_rated  = 4;                %A      	// Rated current (phase-peak)
        pmsm_motor2.N_max    = 4000;               %rpm        // Max speed
        pmsm_motor2.PositionOffset = 0.1458;	    %PU position// Position Offset
        pmsm_motor2.QEPSlits = 1000;               %           // QEP Encoder Slits
        pmsm_motor2.FluxPM   = (pmsm_motor2.Ke)/(sqrt(3)*2*pi*1000*pmsm_motor2.p/60); %PM flux computed from Ke
		% pmsm.FluxPM = (pmsm.Kt)/((3/2)*pmsm.p); %PM flux computed from Kt
        pmsm_motor2.T_rated  = mcbPMSMRatedTorque(pmsm_motor2);   %Get T_rated from I_rated
        pmsm_motor2.PositionOffset = 0.1485;         % Per-Unit position offset 
%% Target & Inverter Parameters

target = mcb_SetProcessorDetails('F28379D',PWM_frequency);

inverter_motor1 = mcb_SetInverterParameters('BoostXL-DRV8305');
inverter_motor2 = mcb_SetInverterParameters('BoostXL-DRV8305');

%% Calibration section

% Enable automatic calibration of ADC offset for current measurement
inverter_motor1.ADCOffsetCalibEnable = 1; % Enable: 1, Disable:0
inverter_motor2.ADCOffsetCalibEnable = 1; % Enable: 1, Disable:0

% If automatic ADC offset calibration is disabled, uncomment and update the 
% offset values below manually
% inverter_motor1.CtSensAOffset = 2295;
% inverter_motor1.CtSensBOffset = 2285;
% 
% inverter_motor2.CtSensAOffset = 2295;
% inverter_motor2.CtSensBOffset = 2285;

%ADC gain for simulation with BLY motor for simulation
% Update ADC Gain for DRV8305 on motor side
if pmsm_motor1.I_rated < 5
    inverter_motor1.ADCGain = 4;   % ADC Range = +- 4.825A wrt 0-4095 counts
    inverter_motor1.SPI_Gain_Setting = 0x502A;
    
elseif pmsm_motor1.I_rated < 7
    inverter_motor1.ADCGain = 2;   % ADC Range = +- 9.650A wrt 0-4095 counts
    inverter_motor1.SPI_Gain_Setting = 0x5015;

else     
    inverter_motor1.ADCGain = 1;   % ADC Range = +- 19.300A wrt 0-4095 counts       
    inverter_motor1.SPI_Gain_Setting = 0x5000;        
    
end
%Setting inverter_motor2 ADC gain and spi setting same as inverter_motor1
inverter_motor2.ADCGain = inverter_motor1.ADCGain;
inverter_motor2.SPI_Gain_Setting = inverter_motor1.SPI_Gain_Setting;
% Voltage output of inverter current sense circuit
inverter_motor1.ISenseVoltPerAmp = inverter_motor1.ISenseVoltPerAmp * inverter_motor1.ADCGain; 
% Update ISenseMax that is measurable by target ADC
inverter_motor1.ISenseMax = inverter_motor1.ISenseMax * target.ADC_Vref / inverter_motor1.ISenseVref;
% Update ISenseMax according to set ADC gain
inverter_motor1.ISenseMax = inverter_motor1.ISenseMax/inverter_motor1.ADCGain;

% Voltage output of inverter current sense circuit
inverter_motor2.ISenseVoltPerAmp = inverter_motor2.ISenseVoltPerAmp * inverter_motor2.ADCGain; 
% Update ISenseMax that is measurable by target ADC
inverter_motor2.ISenseMax = inverter_motor2.ISenseMax * target.ADC_Vref / inverter_motor2.ISenseVref;
% Update ISenseMax according to set ADC gain
inverter_motor2.ISenseMax = inverter_motor2.ISenseMax/inverter_motor2.ADCGain;

% Max and min ADC counts for current sense offsets for both inverters
inverter_motor1.CtSensOffsetMax = 2500; 
inverter_motor1.CtSensOffsetMin = 1500;

inverter_motor2.CtSensOffsetMax = 2500;
inverter_motor2.CtSensOffsetMin = 1500;


%% Open loop reference values
T_Ref_openLoop          = 1;                     % Sec // Time for open-loop start-up
Speed_openLoop_PU       = 0.1;                   % PU  // Per-Unit speed referene for open-loop start-up
Vd_Ref_openLoop_PU      = 1.2*Speed_openLoop_PU; % Use 1.2x for Dyno setup and 1x for others

%% Derive Characteristics
pmsm_motor1.N_base = mcb_getBaseSpeed(pmsm_motor1,inverter_motor1); %rpm // Base speed of motor at given Vdc
pmsm_motor2.N_base = mcb_getBaseSpeed(pmsm_motor2,inverter_motor2); %rpm // Base speed of motor at given Vdc
% Uncomment below to get motor charecteristics
% mcb_getCharacteristics(pmsm_motor1,inverter_motor1);
% mcb_getCharacteristics(pmsm_motor2,inverter_motor2);

%% PU System details // Set base values for pu conversion

PU_System_motor1 = mcb_SetPUSystem(pmsm_motor1,inverter_motor1);
PU_System_motor2 = mcb_SetPUSystem(pmsm_motor2,inverter_motor2);
%% Set Acceleration
acceleration = 20000/PU_System_motor1.N_base;                  % P.U/Sec // Maximum allowable acceleraton

%% Controller design // Get ballpark values!
% for motor 1 
PI_params_motor1 = mcb.internal.SetControllerParameters(pmsm_motor1,inverter_motor1,PU_System_motor1,T_pwm,2*Ts,Ts_speed);

%Updating delays for simulation
PI_params_motor1.delay_Currents    = 1; %int32(Ts/Ts_simulink);
PI_params_motor1.delay_Position    = 1; %int32(Ts/Ts_simulink);

% Set SMO parameters
smo_motor1 = mcb_ComputeSMOParameters(pmsm_motor1,Ts,PU_System_motor1);

% %Uncomment for frequency domain analysis
% mcb_getControlAnalysis(pmsm_motor1,inverter_motor1,PU_System_motor1,PI_params_motor1,Ts,Ts_speed); 

% for motor 2
PI_params_motor2 = mcb.internal.SetControllerParameters(pmsm_motor2,inverter_motor2,PU_System_motor2,T_pwm,2*Ts,Ts_speed);

%Updating delays for simulation
PI_params_motor2.delay_Currents    = 1; %int32(Ts/Ts_simulink);
PI_params_motor2.delay_Position    = 1; %int32(Ts/Ts_simulink);

% Set SMO parameters
smo_motor2 = mcb_ComputeSMOParameters(pmsm_motor2,Ts,PU_System_motor2);

% %Uncomment for frequency domain analysis
% mcb_getControlAnalysis(pmsm_motor2,inverter_motor2,PU_System_motor2,PI_params_motor2,Ts,Ts_speed); 

%% Displaying model variables
disp(pmsm_motor1);
disp(pmsm_motor2);
disp(inverter_motor1);
disp(inverter_motor2);
disp(target);
disp(PU_System_motor1);
disp(PU_System_motor2);
