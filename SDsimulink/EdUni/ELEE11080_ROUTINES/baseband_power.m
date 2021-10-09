function [bbpwr dcpwr] = baseband_power(Qout, Fs, OSR, psdctrl)
%
% baseband_power - function to compute total baseband power for a given OSR.
%
% Inputs:
%
% Qout	Array of modulator quantised outputs (in decimal)
% Fs	Sampling frequency
% OSR	Oversampling ratio (used to determine signalband / baseband top frequency).
% psdctrl PSD control structure
%
% Returns:
%
% bbpwr	Estimate of the TOTAL baseband power (signals + noises) in Watts
% dcpwr	Power in the dc bins
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

Hpsd = psd(h,Qout,'Fs',Fs);
mypsdpwrs = Hpsd.Data;          % Extract PSD bins.
deltaf = Fs/h.segmentLength;	% frequency resolution a.k.a. bin width

% Compute the top of the baseband as a frequecy in Hertz and a
% corresponding PSD (nearest) bin location.

sigbandtop_hz = Fs/(2*OSR);
sigband_bins = 1+round(sigbandtop_hz/deltaf); % BB top as PSD bin

% Sum the bins and mutliply by the effective noise bandwidth to get
% the total power in the baseband.
%
% Ignores the first WINBW bins to avoid getting a big parabola in a b'band
% power versus dcinput sweep plot due to some (dcin^2) power bins
% leaking into the noise calculation! Remember that dc energy is almost
% certainly not just in the first bin if you are windowing!
%
% This may obviously give a large error if WINBW bins is a significant part
% of the baseband - but if that's true then you probably weren't looking
% for accurate results anyway!

bbpwr = deltaf*sum(mypsdpwrs(psdctrl.winbw:sigband_bins)); 
dcpwr = deltaf*sum(mypsdpwrs(1:psdctrl.winbw)); 
end
