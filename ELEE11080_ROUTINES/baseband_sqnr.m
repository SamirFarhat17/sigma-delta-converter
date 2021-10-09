function [sqnr,sigpwr,bbpwr] = baseband_sqnr(Qout, Fs, OSR, fsignal_hz, psdctrl)
%
% baseband_sqnr - function returning signal power and baseband SQN(+D)R
%
% Assumes a low-pass modulator. Will need modified for bandpass designs.
%
% Inputs:
%
% Qout          Array of modulator quantised outputs (in decimal)
% Fs            Sampling frequency
% OSR           Oversampling ratio (used to determine baseband upper limit)
% fsignal_hz	Signal fundamental frequency in Hz
% psdctrl       PSD control structure
%
% Returns:
%
% sqnr		Estimate of the SQNR AMPLITUDEs ratio (NOT powers or dB20s!)
% sigpwr	Estimated signal power (useful for PSD sanity checks...)
% bbpwr		Estimated total baseband power including signal
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
    warning('MATLAB:baseband_power', 'PSD framesize longer than total data');
end

if(fsignal_hz < (Fs/psdctrl.framesize))
    warning('MATLAB:baseband_power', 'Accuracy warning - PSD framesize too short for specified signal frequency');
end

h.WindowName = psdctrl.win;

Hpsd = psd(h,Qout,'Fs',Fs);	% Compute PSD
mypsdpwrs = Hpsd.Data;		% extract data
deltaf = Fs/h.segmentLength;	% frequency resolution a.k.a. bin width

% Get baseband total power. Ignore the first NBW bins to avoid any
% dc component being the second dominant power in the baseband after
% the signal (or even > the signal!). This should not cause significant
% accuracy errors for any sane modulator design and PSD set-up!

sigbandtop_hz = Fs/(2*OSR); % Top of baseband for this OSR in Hz
sigband_bins = 1+round(sigbandtop_hz/deltaf); % BB top as PSD bin
bbpwr = deltaf*sum(mypsdpwrs(psdctrl.winbw:sigband_bins));  % sum powers

% Now get the signal power - assume all in +/- WINBW bins of the signal
% frequency bin. This might give poor results if WINBW is not a small
% fraction of your total number of baseband bins (but you clearly weren't
% wanting accurate results anyway in that case!), or if your signal
% is right at the top of the baseband and hence masking the most dominant
% noise bins for a high-order modulator. Bad things might also happen if
% you don't have an INTEGER number of cycles of your fsignal_hz signal
% in the PSD buffer. Like most things in life, especially those involving
% Discrete Fourier Transforms, this function is best applied in conjunction
% with a good dose of common sense...

sigbin = 1+round(fsignal_hz/deltaf); % Find closest PSD bin to fsignal

sigbinmin = max([(sigbin - psdctrl.winbw) 1]); % Don't try to look below dc!
%sigbinmax = min([sigband_bins (sigbin + psdctrl.winbw)]); % Or out-of-band!
sigbinmax = sigbin + psdctrl.winbw; % Window OOB ok for signal power calc...
sigpwr = deltaf*sum(mypsdpwrs(sigbinmin:sigbinmax));

if(sigbin > sigband_bins)
    warning('MATLAB:baseband_sqnr',...
        'Accuracy warning - signal is out of band');
elseif(sigbinmax >= sigband_bins)
    warning('MATLAB:baseband_sqnr',...
        'Accuracy warning - signal window lobe exceeds top of signal band');
end

% noise and distortion is the total power less the signal power, so
% SQNR is thus signalpower / (basebandpower - signalpower)

sqnr = sqrt(sigpwr/(bbpwr - sigpwr)); % Want amplitude ratio, so sqrt!
end
