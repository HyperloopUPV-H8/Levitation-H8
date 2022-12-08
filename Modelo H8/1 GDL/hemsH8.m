load("force_airgap_current.mat")
m = 200;
g = 9.81;
nHEMS = 4;
nHEMS_W = 2;
Iyy = 53.106596;
x_lev = 0.505;

%% 
current_ = current.';
surf(current_,airgap,fuerza);

%% 
resistance = fuerza;
for i = 1:100
    for j = 1:100
        resistance(i,j) = 0.1496;
    end
end

%% 
inductance = fuerza;
for i = 1:100
    for j = 1:100
        inductance(i,j) = 0.0016;
    end
end

%% 
temperature = linspace(0,300,100);
