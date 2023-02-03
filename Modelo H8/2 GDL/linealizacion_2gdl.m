lev_nom=0.01965;
suelo=0.0225;
x=[0, lev_nom, 0, 0];  %estados
argout=linmod('H8_2GDL_partelinealizada',x,[0, 0]); % entrada
A2=argout.a
B2=argout.b
C2=argout.c
D2=argout.d
sys=ss(A2,B2,C2,D2);


K = place(sys.A,sys.B,[-2+2i,-2-2i,-5,-6])

%Aa = [A2 zeros(4,4); -C2 zeros(4,4)] 
%Ba = [B2; -D2]
%Ka = place(Aa,Ba,[-1 -2 -3 -4 -5 -6 -100 -100])




