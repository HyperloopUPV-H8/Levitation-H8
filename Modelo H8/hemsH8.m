load("force_airgap_current.mat")
m = 200;
g = 9.81;
nHEMS = 4;

%% 
current_ = current.'
surf(current_,airgap,fuerza);
%% 

