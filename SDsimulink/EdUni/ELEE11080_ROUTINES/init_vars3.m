% Initialise variables to some vaguely interesting defaults
% just to allow quick up-and-running of the simulink model
%
% Initialisation could also be done via simulink model callbacks, but
% we might want to over-ride defaults, and it's trickier if callbacks
% keep trying to reset variables over existing workspace values...
%
format short g
%
% The following are used by the PSD scripts and/or the DSP toolbox,
% do don't rename them!
%
Fs = 1e6;  % Modulator sampling frequency in Hz.
OSR = 64;  % Oversampling ratio used to define singal band (calculate SQNRs)
%
swpctrl.trantime = 0.032768;	% Default transient simulation time
%
% Set some defaults for the PSD calculations used to compute total powers,
% THD+N ratios etc.
%
psdctrl.framesize = 8192;	 % 4096 is maybe a bit short of resolution.
psdctrl.win = 'blackman-harris';   % Use Blackman-harris for high SQNRs!
psdctrl.winbw = 3;      % Assumed window main lobe 1/2 width for signal power
%
% For sine input, default to a handy (i.e. in bin, no leakage!) tone
% frequency with rms power 0.5^2 = 0.25 (so we can check the signal power
% in the PSD to make sure everything looks sensible before getting
% too carried-away with SNR estimates...)
%
% When changing the frequency, you REALLY want to pick a test frequency that
% hits a PSD bin exactly as, even with windowing, the resulting spectral
% leakage can make a right mess of your SQNR etc. estimates.
%
sinfreq = 4882.8125;   % in Hz. TRY TO HIT A PSD BIN!
sinamp = 1/sqrt(2); % Full-scale is +/1 (quantiser/DAC output range)
%
% default dc input value for the dc simulations
%
input_dc = 0;
%
% Define a few modulator generic control parameters. Individual
% modulator designs can expand this to get mode fine-grained control
% if required. We're just trying to keep it simple for the course
% examples and making a "one size fits none" generic case.
%
modctrl.igain1 = inf;   % Integrator dc gain (pole at z = 1-1/gain)
modctrl.igain2 = inf;
modctrl.igain3 = inf;
modctrl.igain4 = inf;   % 4 integrator gains should be enough default!
%
modctrl.isat1= inf;  % Max integrator output is +/- this number
modctrl.isat2= inf;
modctrl.isat3= inf;
modctrl.isat4= inf;
%
modctrl.qsatin1 = inf;  % Limiting for any pre-quantiser summer
modctrl.qsatin2 = inf;
%
modctrl.qlev1=2;    % Number of quantiser output levels (more than
modctrl.qlev2=2;    % qunatiser if a MASH converter);
modctrl.qlev3=2;
%
modctrl.dgain1 = 0;   % Dither scaling, off by default (0 = none, 1 = full)
modctrl.dgain2 = 0;   % extral (overkill!) MASH dither control
%
modctrl.mgain1 = 1;	% various modulator recombination scaling factors...
modctrl.mgain2 = 1;
modctrl.mgain3 = 1;
%
modctrl.nlg1 = 10; % Nonlinearity model control
modctrl.nlg2 = 10;
modctrl.nlg3 = 10;
%
modctrl.ngain1 = 0; % Thermal noise model level controls (off by default)
modctrl.ngain2 = 0;
modctrl.ngain3 = 0;
%
% DEM examples stuff
%
DACctrl.uelement = [1 1 1]; 	% DAC units elements (add more for > 4 levels)
DACctrl.elecount = 3; 		% How many elements to use (can use < uelements)
DACctrl.dodem = 0;		% DEM enable control: 0 = off, 1 = on
dem_dcin = 0;
dem_select = 4;
dem_sinamp = 0;
dem_sinfreq = 4882.8125;
