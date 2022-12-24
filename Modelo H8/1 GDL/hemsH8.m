load("force_airgap_current.mat")
m = 200;
g = 9.81;
nHEMS = 4;
nHEMS_W = 2;
Ixx = 12.489414;
Iyy = 52.598747;
Izz = 53.106596;
x_lev = 0.505;
y_lev = 0.2;
z_lev = 0.1;
z_max = 0.0225;
z_min = 0.01;
y_max = 0.01;
y_min = -0.01;
surf(current,airgap,force);
I2 = [-0.0117539 0.116439 12.4897 ; -0.0021666 52.5984 0.116439;  53.10658 -0.00216668 -0.0117539]
I2 = [0 0 12.4897 ; 0 52.5984 0;  53.10658 0 0]
I3 = [12.4897 0 0 ; 0 52.5984 0;   0 0 53.10658]


%% 
figure
surf(current,airgap,force);
xlabel('Amplitude [A]')
ylabel('Airgap [mm]')
zlabel('Force [N]')
title('Barrido Airgap-Amplitud-Fuerza')

%% 
resistance = force;
for i = 1:100
    for j = 1:100
        resistance(i,j) = 0.1496;
    end
end

%% 
inductance = force;
for i = 1:100
    for j = 1:100
        inductance(i,j) = 0.0016;
    end
end

%% 
temperature = linspace(0,300,100);
