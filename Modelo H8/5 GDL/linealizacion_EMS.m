   cg_nom=0.567;
   lev_nom=0.01965;
   cg_suelo=0.56985;
   cg_techo=0.55735;
%     x=[0, 0, cg_nom, 0, 0, 0, 0, 0, 0, 0, 0, 0]; %estados: posy,rotz,vy,wz
%     argout=linmod('H8_EMS_partelinealizada',x,[0, 0, 0, 0]); %entradas
%     A1=argout.a
%     B1=argout.b
%     C1=argout.c
%     D1=argout.d
%sys=ss(A5,B5,C5,D5);
%rank(ctrb(A5,B5))
%eig(A5)
K2 = place(A1,B1,[-1 -1  -2+2j -2-2j])
%Si cambian las matrices hay que eliminar columnas 1 y 7 y filas 1 y 7

%% Añadir accion integral
%Continuo-> Aa = [A zeros(filasA,filasC); -C zeros(filasC,filasC)] Ba = [B; -D]

%C = [1 0 0 0; 0 1 0 0];
%D = zeros(2,2)

Aa1 = [A1 zeros(4,4); C1 zeros(4,4)] 
Ba1 = [B1; D1]
rank(ctrb(Aa1,Ba1))

Ka2 = place(Aa1,Ba1,[ -1 -1 -1 -1 -2 -2 -2+2j -2-2j])

%Ka = place(Aa,Ba,[-5 -4 -6+6j -6-6j -2+2j -2-2j])
