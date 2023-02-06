lev_nom=0.01965;
suelo=0.0225;
x=[0, lev_nom, 0, 0];  %estados
argout=linmod('H8_2GDL_partelinealizada',x,[0, 0]); % entrada
A2=argout.a
B2=argout.b
C2=argout.c
D2=argout.d
sys=ss(A2,B2,C2,D2);

K = place(sys.A,sys.B,[-5 -4 -2+2j -2-2j]);

%% Añadir accion integral
%Continuo-> Aa = [A zeros(filasA,filasC); -C zeros(filasC,filasC)] Ba = [B; -D]

Aa = [A2 zeros(4,2); -C2 zeros(2,2)] 
Ba = [B2; -D2]
rank(ctrb(Aa,Ba))
Ka = place(Aa,Ba,[-5 -4 -2+2j -2-2j -3+1j -3-1j])




