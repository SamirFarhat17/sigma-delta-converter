%
% Set-up a big example DAC to allow playing with somthing a
% bit more exciting than 3.
%
DACctrl.uelement = [0.983 1.017 0.967 1.003 1.028 0.956 1.037 1];
DACctrl.elecount = 8; 		% How many elements to use (can use < uelements)
DACctrl.dodem = 1;		% DEM enable control: 0 = off, 1 = on
dem_dcin = 1;
dem_select = 4;
dem_sinamp = 7;
dem_sinfreq = 4882.8125;
