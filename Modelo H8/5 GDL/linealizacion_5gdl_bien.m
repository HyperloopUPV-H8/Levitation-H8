cg_nom=0.567;
lev_nom=0.01965;
%cg_suelo=0.56985;
%cg_techo=0.54735;
x=[0, 0, cg_nom, 0, 0, 0, 0, 0, 0, 0, 0]; %estados: posx,posy,posz,rotx,roty,rotz,vx,vy,vz,wx,wy,wz
argout=linmod('H8_6GDL_partelinealizada',x,[0, 0, 0, 0, 0, 0, 0, 0]); %entradas
A5=argout.a
B5=argout.b
C5=argout.c
D5=argout.d
sys=ss(A5,B5,C5,D5);
%rank(ctrb(A5,B5))
%eig(A5)
K = place(A6,B6,[-1 -1 -1 -1 -2 -2 -2 -2 -2+2j -2-2j])
%Si cambian las matrices hay que eliminar columnas 1 y 7 y filas 1 y 7

%% Añadir accion integral
%Continuo-> Aa = [A zeros(filasA,filasC); -C zeros(filasC,filasC)] Ba = [B; -D]

%C = [1 0 0 0; 0 1 0 0];
%D = zeros(2,2)

%Aa = [A5 zeros(10,10); C5 zeros(10,10)] 
%Ba = [B5; D5]
%rank(ctrb(Aa,Ba))

%Ka = place(Aa,Ba,[ -1.5 -1.5 -1.5 -1.5 -2 -2 -6 -6 -7 -7 -5 -5 -2 -2 -3 -3 -4 -4 -6+6j -6-6j])

%Ka = place(Aa,Ba,[-5 -4 -6+6j -6-6j -2+2j -2-2j])