%% Con LUT

x=[0.023, 0]; % estados
argout=linmod('H8_1GDL_currentinput',x,0); % entrada
A=argout.a;
B=argout.b;
C=argout.c;
D=argout.d;
sys=ss(A,B,C,D);
sysr=minreal(sys)

%% Con ecuaciones

x=[0.023, 0]; % estados
argout=linmod('H8_1GDL_currentinput_ecuaciones',x,0); % entrada
Ap=argout.a;
Bp=argout.b;
Cp=argout.c;
Dp=argout.d;
sysp=ss(Ap,Bp,Cp,Dp);
sysrp=minreal(sysp)