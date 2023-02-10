%y_nom=0.012;
%z_nom=0.01965;
%x=[0 y_nom z_nom 0 0 0 0 0 0 0 0 0]; %estados: posx,posy,posz,rotx,roty,rotz,vx,vy,vz,ax,ay,az
%argout=linmod('H8_6GDL_partelinealizada',x,[0 0 0 0 0 0 0 0]); %entradas
%A5=argout.a
%B5=argout.b
%C5=argout.c
%D5=argout.d
%sys=ss(A5,B5,C5,D5);
%rank(ctrb(A5,B5))
%eig(A5)
K = place(A5,B5,[-5 -5 -2 -2 -3 -3 -4 -4 -6+6j -6-6j])
%Si cambian las matrices hay que eliminar columnas 1 y 7 y filas 1 y 7

%% Añadir accion integral
%Continuo-> Aa = [A zeros(filasA,filasC); -C zeros(filasC,filasC)] Ba = [B; -D]

%C = [1 0 0 0; 0 1 0 0];
%D = zeros(2,2)

%Aa = [A2 zeros(4,2); C zeros(2,2)] 
%Ba = [B2; D]
%rank(ctrb(Aa,Ba))

%Ka = place(Aa,Ba,[-5 -6+6j -6-6j -2+2j -2-2j])

%Ka = place(Aa,Ba,[-5 -4 -6+6j -6-6j -2+2j -2-2j])
