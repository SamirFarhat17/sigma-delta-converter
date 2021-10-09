% calc_quant_gain  - estimate a quantiser gain based on in/out data
%
% This script assumes that workspace variables called Qin and Qout
% exist and that these conatin samples of a quantiser's input and output.
%
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

% Check variables exist

if ~exist('Qin', 'var')
	error('No Qin data in workspace!');
end

if ~exist('Qout', 'var')
	error('No Qout data in workspace!');
end

% Reshape the data to deal with the fact that "To Workspace" sometimes
% emits funny-shaped arrays
% e.g. (1 x 1 x datapoints) instead of (datapoints x 1)

qi = reshape(Qin,[],1);
qo = reshape(Qout,[],1);

if(size(qi) ~= size(qo))
    warning('calc_quant_gain', 'Qin and Qout hold different numbers of samples!');
end

mean(qi.*qo)/mean(qi.*qi)	% Compute effective gain
