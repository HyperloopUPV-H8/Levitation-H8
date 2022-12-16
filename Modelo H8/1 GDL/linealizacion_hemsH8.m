x=[0.0225, 0];
argout=linmod('H8_1GDL_currentinput',x,0.019);
A=argout.a;
B=argout.b;
C=argout.c;
D=argout.d;
sys=ss(A,B,C,D);
sysr=minreal(sys)