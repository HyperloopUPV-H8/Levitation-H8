x=[0,0.01965, 0, 0];  %estados
argout=linmod('H8_2GDL_partelinealizada',x,[0,0]); % entrada
A2=argout.a;
B2=argout.b;
C2=argout.c;
D2=argout.d;
sys=ss(A2,B2,C2,D2);
%sysr=minreal(sys)
%C esta OK con [1 0 0 0; 0 1 0 0]
%D esta OK con 0