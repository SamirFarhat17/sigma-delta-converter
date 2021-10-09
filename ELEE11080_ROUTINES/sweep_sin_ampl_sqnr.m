% sweep_sin_ampl_sqnr  - sine sweep a modulator and report sqnr vs. amplitude
%
% ------------------ Begin Copyright notice -----------------------------
%
% COPYRIGHT AND PROPERTY OF DIALOG SEMICONDUCTOR, 2012.
%
% THIS COPYRIGHT NOTICE MUST NOT BE REMOVED OR MODIFIED.
%
% Commerical use is not permitted.
%
% Installation on systems available for use in any way by commercial users
% is not permitted.
%
% Permission for use is granted by Dialog Semiconductor only for the
% purposes of teaching or studying course ELEE11080/PGEE11110 "Sigma
% Delta Data Converters" (or any renamed variant or descendant of
% this course) at the University of Edinburgh.
%
% Personal copying and/or modification is permitted only by students and
% teaching staff of course ELEE11080/PGEE11110 solely for the purposes of
% delivering or studying course ELEE11080/PGEE11110.
%
% All permissions for use of this or modified copies are revoked upon
% ceasation of teaching duties or completion or de-enrollment for any
% reason from course ELEE11080/PGEE11110.
%
% ------------------- End Copyright notice ------------------------------

if ~exist('target_modulator', 'var')
    error(['Please define workspace variable "target_modulator" to'...
        'point to a valid simulink model, e.g. "mod1"']);
end
if ~exist('utstr', 'var')
    utstr = '';
end

swpctrl.select = 1;     % SPTbox sine input in standard test bench

% users might have a short trantime if they have been looking at, e.g. 
% limit cycles transients.
mintrantime = psdctrl.framesize / Fs;
if (swpctrl.trantime < mintrantime)
	errstr = sprintf('swpctrl.trantime is %f seconds, but mininium data length for a single FFT is %f seconds.\nPlease set swpctrl.trantime appropriately!\n', swpctrl.trantime, mintrantime);
	error([errstr]);
end
testbench = 'sweep_testbench';
open_system([testbench '.mdl']);
set_param([testbench '/dut'], 'ModelName', [target_modulator '.mdl']);
save_system([testbench '.mdl']);
close_system([testbench '.mdl']);
bdclose([testbench '.mdl']);

swpctrl.testpoints = logspace(-3,0,61);  % 1 dB steps
swpctrl.numtests = length(swpctrl.testpoints);
sndr = zeros(1,swpctrl.numtests); % preallocate results space
sigpwr = zeros(1,swpctrl.numtests); % preallocate results space

for indx = 1:swpctrl.numtests
   sinamp = swpctrl.testpoints(indx); % Ensure input is "sinamp"!
   SimOut = sim([testbench '.mdl']);
   [sndr(indx) sigpwr(indx)] = baseband_sqnr(Qout, Fs, OSR, sinfreq, psdctrl);
end
figure;
plot(20*log10(swpctrl.testpoints(2:end)), 20*log10(sndr(2:end)), 'b-');
hold on;
plot(20*log10(swpctrl.testpoints(2:end)), 20*log10(sndr(2:end)), 'ro');
grid on;
%title('Signal-to-quantisation-noise-and-distortion versus sine amplitude');
tstr = sprintf('Signal-to-quantisation-noise-and-distortion versus %d Hz sine input amplitude\nfor modulator %s\n%s', round(sinfreq), target_modulator, utstr);
title(tstr);
xlabel('Input amplitude (dBFS)');
ylabel('SQNDR (dB)');
hold off;
shg;
