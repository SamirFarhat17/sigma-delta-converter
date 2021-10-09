%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Modulator synthesize settings (For toolbox)

    %Modulator specification
    order = 3; % Order of the Modulator
    OSR = 64; % Oversampling ratio of the modulator (Used for toolbox  functions only)
    form = 'CIFB'; %Modulator architecture. %At present, simulink simulations support only this structure. Other structures can be incorporated if needed 
    nLev = 2; % Number of levels in the quantiser 
    OBG = NaN; % Out of band gain of NTF (max 2 for binary quantiser), Use NaN for default by toolbox(OBG = 1.5, Lee criterion)
    opt = 1; %Optimisation of NTF zeroes (0 = no opt, 1 = opt)
    

%Quantiser selection
if nLev == 2
    bin_quant = 1;
    multi_quant = 0;
elseif nLev > 2
    bin_quant = 0;
    multi_quant = 1;
else
    uiwait(msgbox('Invalid quantiser levels','Sigma Delta Simulator'));
    return;
end

%Parameter Verification
if order < 0
    uiwait(msgbox('Invalid modulator order','Sigma Delta Simulator'));
    return;
end

if OSR~= ceil(OSR)
    uiwait(msgbox('OSR should be an integer','Sigma Delta Simulator'));
    return;
end

if ~(strcmp(form,'CIFB') ||strcmp(form,'CRFB') ||strcmp(form, 'CIFF') ||strcmp(form,'CRFF')) 
    uiwait(msgbox('Unknown modulator form','Sigma Delta Simulator'));
    return;
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Code for Nth order Sig Delta Modulator

%Step 1, synthesize the NTF


%Step 1: Synthesize NTF
    %See order and OSR defentions at variables section on Top
    H = synthesizeNTF(order,OSR,opt,OBG);  % Synthesize the NTF for the modulator with order, OSR define
    
    
%Step 2: Realize NTF    
    %Realise the NTF with a particular
    %Modulator structure. Examples are CIFB, CIFF, CRFB, CRFF. 
    %We will be using a CIFB structure to establish the whole design path and
    %change if required later.
    [a,g,b,c] = realizeNTF(H,form); %This function converts the NTF synthesized earlier into coeffiecients for circuit implementation.
    
%Step 3: Generate loop filter description in ABCD format    
    %realizeNTF returns coefficients for an unscaled modulator whose internal
    %stages occupy an unspecified range. So dynamic range scaling must be
    %performed (Page 268 for a diagram)
    b(2:end) = 0; % Set all feed in terms to 0 for a maximally flat STF 
    ABCD = stuffABCD(a,g,b,c,form);  % ABCD matrix (generic loop filter description) (unscaled)
    
%Step 4: Dynamic range scaling of ABCD matrix    
    %Use scaleABCD to determine scaling factors for each state of
    %modulator. Modulator is simulated with inputs of different amplitudes
    %to determine maximum stable input amplitude (umax). Then dynamic range
    %scaling is peformed to maximum value of each state equals specified
    %limit (xlim)
    xLim = 0.9;
    f0 = 0; %Normalised frequency of the test sinusoid
    %ABCDs is the scaled state space matrix description
    %umax is the maximum possible amplitude of the signal that can be
    %applied to the modulator.
    
    %Use either of one
    %[ABCDs umax] = scaleABCD(ABCD,nLev,f0,xLim);
    [ABCDs umax] = scaleABCD(ABCD);
    
%Step 5: Convert scaled ABCD matrix back to coeffcients for circuit implementation     
    %Scaled ABCD matrix is translated back into co-efficients by mapABCD
    %for the modulator structure defined.
    [a g b c] = mapABCD(ABCDs,form);
    %This data goes into simulink models
    
% Additional toolbox functions used below for plotting and analysis    
    
    fig0 = figure('NumberTitle','off','Name','Plots from toolbox');
    scrn = get(0,'ScreenSize');
    set(fig0,'Position',[scrn(3)/4 scrn(4)/4 0.5*scrn(3) 0.5*scrn(4)]);    
    clf;

    subplot(1,2,1);
    plotPZ(H);  %Plots the poles and Zeroes of NTF synthesized above
    title('Poles and Zeroes of NTF');


    %To plot STF and NTF
    [Ha Ga] = calculateTF(ABCD); % Calculates STF from ABCD matrix. Ha = NTF eq, Ga = STF eq
    f = linspace(0,0.5,100);
    z = exp(2i*pi*f);
    magHa = dbv(evalTF(Ha,z)); 
    magGa = dbv(evalTF(Ga,z));
    
    subplot(1,2,2);
    plot(f,magHa,'b',f,magGa,'m','Linewidth',1);
    grid on;
    title('STF and NTF')
    leg3 = legend('NTF','STF');
    set(leg3,'Location', 'SouthEast');
   
   
    
    