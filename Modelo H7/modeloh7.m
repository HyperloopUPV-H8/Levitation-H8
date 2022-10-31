m = 200;
ref = 0.0175;
x = 2;


%% 
p00 =       926.8; 
p10 =       10.82;
p01 =   -6.23e+04;  
p20 =    -0.06986; 
p11 =      -480.6;  
p02 =   1.203e+06;  
p30 =   -0.001275;  
p21 =       2.722;  
p12 =        7783;  
%% 

c = linspace(-40,40,33);
a = linspace(0.011,0.023,49);
f = zeros(33,49);

for i1 = 1:49
    for i2 = 1:33
        f(i2,i1) = p00 + p10*c(i2) + p01*a(i1) + p20*c(i2)^2 + p11*c(i2)*a(i1) + p02*a(i1)^2 + p30*c(i2)^3 + p21*c(i2)^2*a(i1) + p12*c(i2)*a(i1)^2;
    end
end

mesh(a, c, f)
xlabel('Airgap')
ylabel('Current')
zlabel('Force')
hold on
f_ = force';
surf(airgap, current,f_)
hold off


