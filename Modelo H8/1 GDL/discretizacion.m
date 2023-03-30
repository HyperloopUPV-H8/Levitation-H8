%Discretizacion de bucle de distancia

P = -64900;
I = -155000;
D = -1900;
N = 1900;
Ts = 1/(2e3);

Kp = P;
Ki = I;
Tf = N;
Kd = D/N;


Ccon = pid(Kp,Ki,Kd,Tf)  % continuous-time controller in parallel form
Cdis1 = c2d(Ccon,Ts,'zoh') % discrete-time controller in parallel form

Kpd = Kp;
Kid = Ki;
Kdd = Kd;
Tfd = 1/Tf;
