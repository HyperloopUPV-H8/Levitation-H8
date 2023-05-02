% 1 gdl real ajustes

% load("hems.mat");
% load("barrido_levnom.mat");

peso = 47.942;
m = peso*4;
suelo = 24.14/1000;
mech = 56.6/1000;

vbat = 200; 
v_max = 0.4*vbat; %minimo deberia ser 70V para 50A
v_min = -0.4*vbat;

fs_current = 20000;
fl_current = 10000;
var_current = 0.052125100064495;
offset_current = 0.001065378087271;

fs_airgap = 20000;
fl_airgap = 10000;
var_airgap = 1.112140361208638e-08/1000;
offset_airgap = 0;
airgap_min = 80/1000;
airgap_max = 115/1000;

current_filter_order = 20;

airgap_filter_order = 6;

kp_current = 20;
ki_current = 200;
kd_current = 0;
f_current_control = 2000; 

kp_airgap = -59000;
ki_airgap = -155000;
kd_airgap = -1900;
f_airgap_control = 2000;

N = 16;
diferent_values = (2^N)-1;
