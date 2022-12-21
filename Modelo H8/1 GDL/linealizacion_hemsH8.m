%% Con LUT

x=[0.019, 0]; % estados
argout=linmod('H8_1GDL_currentinput',x,0); % entrada
A=argout.a;
B=argout.b;
C=argout.c;
D=argout.d;
sys=ss(A,B,C,D);
sysr=minreal(sys)

%% Con ecuaciones

x=[0.019, 0]; % estados
argout=linmod('H8_1GDL_currentinput_ecuaciones',x,0); % entrada
A=argout.a;
B=argout.b;
C=argout.c;
D=argout.d;
sys=ss(A,B,C,D);
sysr=minreal(sys)