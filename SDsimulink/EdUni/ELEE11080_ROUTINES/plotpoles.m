hold on;
pix = 1;
%
% Run k from 0 to 1 in 0.001 increments and find the NTF pole positions
% (roots of the NTF denominator) at each k.
% Then plot the root loci as k goes from 0 to 1.
% Make a note too of the first value of k for which any poles cross the
% |z|=1 unit circle.
%
stablek = 0;
foundk = 0;
%
% Find pole positions as k varies 0 to 1
%
for k = 1e-9:0.001:1.0001
  p = [1 3*k-3 3-3*k k-1];	% Vector of pole polynomial coeffs for this k.
  [r1] = roots(p);		% Find polynomial roots (pole locations).
  r1a(pix) = r1(1);
  r1b(pix) = r1(2);
  r1c(pix) = r1(3)+0i;		% Make this pole complex for plotting.
  if((foundk==0) && (abs(r1a(pix)) < 1))	% Inside unit circle?
     stablek = k;
     foundk = 1;
  end
pix = pix + 1;
end
%
% Plot pole loci
%
plot(r1a', '-', 'LineWidth', 2);
plot(r1b', '-', 'LineWidth', 2);
plot(r1c', '-', 'LineWidth', 2);
polemessage = sprintf('Poles inside unit circle for k < %f\n',stablek);
disp(polemessage);
%
% Plot |z|=1 unit circle in red
%
cl = [-0.01:0.01:2*pi]';
ppoints = [cos(cl) sin(cl)];
plot(ppoints(:,1), ppoints(:,2), '-r', 'LineWidth', 2);
hold off;
%
% Add some annotation
%
grid on;
axis([-1.1 1.5 -1.1 1.1]);
title('MOD3 poles versus quantiser gain (linear model)');
xlabel('z real part');
ylabel('z imaginary part');
text(-0.05,-0.025,'k = 1 \rightarrow','HorizontalAlignment','right','FontSize',15);
text(1.05,-0.025,'\leftarrow k = 0','HorizontalAlignment','left','FontSize',15);
text(0.1,0.025,'decreasing k \rightarrow','HorizontalAlignment','left','FontSize',15);
text(0.075,0.05,'\leftarrow','HorizontalAlignment','right','FontSize',15,'Rotation',-45);
text(0.075,-0.025,'\leftarrow','HorizontalAlignment','right','FontSize',15,'Rotation',45);
shg;
