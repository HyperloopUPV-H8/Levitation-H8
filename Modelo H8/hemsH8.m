load("force_airgap_current.mat")
m = 200;
g = 9.81;
nHEMS = 4;
nHEMS_W = 2;
Iyy = 53.106596;
x_lev = 0.505;

%% 
current_ = current.'
surf(current_,airgap,fuerza);
%% 

