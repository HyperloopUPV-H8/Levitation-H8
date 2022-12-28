%% Calculo punto de linealizacion

load("force_airgap_current.mat");
current_v = current(1,:);
airgap_v = airgap(:,1);

lev_nom = 0.019;
g=9.81;
m=200;

%% Con LUT

x=[0.019, 0]; % estados
argout=linmod('H8_1GDL_currentinput',x,0); % entrada
A=argout.a;
B=argout.b;
C=argout.c;
D=argout.d;
sys=ss(A,B,C,D);
sysr=minreal(sys)

