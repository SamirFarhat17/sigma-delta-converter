% sweep_dc_bbpwr_notb  - dc sweep a modulator and report baseband powers
%
% This script requires a workspace variable called "target_modulator"
% exists and points to a simulink testbench of a modulator with a const
% input block with value "dcinput" and outputing a workspace variable
% Qout. Do not add ".mdl" to the test bench name.
%
% Default dc step size for the sweep is dcstep = 1m. This can be overriden
% by setting it as a worksapce variable.
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

% Fairly safe to assume the dc STF is symmetric around 0 (assuming no
% offset in the model), so just sweep input range [0,1] and ignore [-1,0).
%
% Default step size is 1/1000 unless the workspace variable
% swpctrl.dcstep is set to override it.

if ~exist('swpctrl', 'var')
	swpctrl.dcstep = 1e-3
end

if ~isfield(swpctrl, 'dcstep')
    swpctrl.dcstep = 1e-3;
end

swpctrl.select = 2;     % dc input in standard test bench
swpctrl.trantime = 0.02;	% Plenty long and this sim takes a long time...
testbench = 'sweep_testbench';
open_system([testbench '.mdl']);
set_param([testbench '/dut'], 'ModelName', [target_modulator '.mdl']);
save_system([testbench '.mdl']);
close_system([testbench '.mdl']);
bdclose([testbench '.mdl']);

swpctrl.testpoints = (0:swpctrl.dcstep:1);
swpctrl.numtests = length(swpctrl.testpoints);
bbpower = zeros(1,swpctrl.numtests); % preallocate results space

for indx = 1:swpctrl.numtests
   input_dc = swpctrl.testpoints(indx); % const input variable name in harness
   SimOut = sim([testbench '.mdl']);
   bbpower(indx) = baseband_power(Qout, Fs, OSR, psdctrl);
end
dbpower = 20*log10(bbpower);
avepower = 20*log10(mean(bbpower));
figure;
plot(swpctrl.testpoints, dbpower, 'g-');
hold on;
plot(swpctrl.testpoints, avepower, 'r-', 'linewidth', 4);
axis([0 1 (avepower-80) max(dbpower)]);
grid on;
tstr = sprintf('baseband noise power versus dc input and average power over all inputs\nfor modulator %s\n%s',target_modulator, utstr);
title(tstr);
xlabel('dc input');
ylabel('total power (dbW)');
tstr = sprintf('Average Base-band power = %.1f dBW', avepower);
text(0.05, max(dbpower)-10, tstr, 'Color', 'r', 'Fontsize', 12,...
'FontWeight', 'Bold');
hold off;
shg;
