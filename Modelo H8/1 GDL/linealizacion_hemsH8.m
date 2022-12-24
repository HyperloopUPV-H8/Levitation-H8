%% Calculo punto de linealizacion

current_v = current(1,:);
airgap_v = airgap(:,1);

lev_nom = 0.018;

%% Con LUT

x=[0.018, 0]; % estados
argout=linmod('H8_1GDL_currentinput',x,0); % entrada
A=argout.a;
B=argout.b;
C=argout.c;
D=argout.d;
sys=ss(A,B,C,D);
sysr=minreal(sys)

