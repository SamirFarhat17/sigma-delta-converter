% Qout_SNDR_labbookplot - plot PSD and compute SNDR for a given OSR and
% signal frequency, in a much fancier style good for lab note books.
%
% Assumes a low-pass modulator. Will need modification for bandpass
% designs.
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

% Use Welch method to compute the PSD. This is probably a decent default
% for most work. Modify code to suit if not.
%
% The PSD framesize and window type can be changed from the defaults by
% setting appropriate fields in the workspace control structure "psdctrl".
% The "winbw" control field determines +/- how many bins each side of the signal
% frequency bin should be assumed to contain signal power. This should, at the
% very least, be set to span the main lobe width of whatever window you chose.
%
% NOTE: This PSD routine may be soon superceded in newer versions of MATLAB
% and could be retired without warning. Beware.

h = spectrum.welch;

h.SegmentLength = psdctrl.framesize;
if(psdctrl.framesize > length(Qout))
    warning('MATLAB:baseband_power', 'PSD framesize longer than data!');
end

h.WindowName = psdctrl.win;

Qout = Qout - mean(Qout);
Hpsd = psd(h,Qout,'Fs',Fs);
mypsdpwrs = Hpsd.Data; % Extract data (bin PSDs)...
myfreqs = Hpsd.Frequencies; % ...and bin frequencies.
myfreqs(1) = myfreqs(2)/2; % Can't plot dc term on a log scale, put it at "1/2 bin".
figure;
loglog(myfreqs,sqrt(mypsdpwrs),'r', 'LineWidth', 2)	% plot power specturm
xlabel('Frequency(Hz)', 'FontWeight', 'Bold', 'FontSize', 14);
ylabel('Unit/sqrt(Hz)', 'FontWeight', 'Bold', 'FontSize', 14);
if ~exist('utstr', 'var')
    tstr = 'Modulator output spectral density (Units/sqrt(Hz))';
else
    tstr = sprintf('Modulator output spectral density (Units/sqrt(Hz))\n%s', utstr);
end
title(tstr, 'FontWeight', 'Bold', 'FontSize', 14);

grid on;
hold on;
plot([10 Fs/(2*OSR)], sqrt([0.95 0.95]), 'b--', 'LineWidth', 3);
plot([Fs/(2*OSR) Fs/(2*OSR)], sqrt([0.1*min(mypsdpwrs) 1]), 'b--', 'LineWidth', 3);
plot([Fs/(2*OSR) Fs/2], sqrt([0.1*min(mypsdpwrs) 0.1*min(mypsdpwrs)]), 'b--', 'LineWidth', 3);
text(1.1*Fs/(2*OSR), sqrt(max(mypsdpwrs)), 'Brickwall LPF @ fs/(2.OSR)', ...
'FontSize', 14, 'FontWeight', 'Bold');

% Call baseband_sqnr to get SQNR etc. This means the PSD will be computed again,
% but this script isn't likely to be getting called in repeated loop, so
% the extra milliseconds are unlikely to matter...
%
% compute and return signal to noise and disto ratio in dB

[sndr,sigpwr,bbpwr] = baseband_sqnr(Qout, Fs, OSR, sinfreq, psdctrl);
%fprintf('\nEstimated SNDR %.2f dB\n', 20*log10(sndr));
sndrstr = sprintf('Simulated:\nSQNR = %.1f dB\nENOB = %.1f', 20*log10(sndr), (20*log10(sndr)-1.76)/6.02);
text(myfreqs(1), sqrt(max(mypsdpwrs)), sndrstr, 'FontSize', 14, 'FontWeight', 'Bold');
hold off;
