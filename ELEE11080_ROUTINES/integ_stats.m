function [intmin intmax intmean intstd] = integ_stats(integrator)
%
% integ_stats - function plotting an integrator histogram with some statistics
%
% Inputs:
%
% Integrator    Array of integrator output values
%
% Returns:
%
% intmin		Minimum integrator output
% intmax		Maximum integrator output
% intmean		Mean integrator output
% intstd		Standard deviation integrator output
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


figure;
[counts, bins] = hist(integrator, 50);
cntot = sum(counts);
bar(bins, counts/cntot, 'r');
ylabel('Relative frequency (probability density per bin)');
xlabel('Integrator output range (split into 50 bins)');
grid on;

intname = inputname(1);

if ~exist('utstr', 'var')
    tstr = sprintf('Output summary for integrator %s', intname);
else
    tstr = sprintf('Output swing summary for integrator %s\n%s', intname, utstr);
end
title(tstr);

intstd = std(integrator);
intmin = min(integrator);
intmax = max(integrator);
intmean = mean(integrator);
maxcount = max(counts);

grid on;
hold on;

sndrstr = sprintf('MAX = %.3f\nMIN = %.3f\nmean = %.3f\nstd dev = %.3f', intmax, intmin, intmean, intstd);
text(bins(1), 0.95*maxcount/cntot, sndrstr, 'Color', 'b',...
'FontSize', 12, 'FontWeight', 'Bold');
hold off;
end
