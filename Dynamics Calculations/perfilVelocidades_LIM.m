% Masa del pod
m = 200;
% Fuerza de tracción
Ft = 1000;
% Recorrido total
x = 20;
% Velocidad crucero
vc_ = 35;
vc = vc_/3.6;
% Fuerza de frenado
Ff = 1607;
% Aceleración máxima
acc_max_ = 0.5;
acc_max = acc_max_/9.8;
% Resolución gráfico
n = 100;
%% 
x_ = linspace(0,x,n*x);
vf = linspace(0,1,n*x);

xf = x - vc^2 * m / (2 * Ff);
xf = round(xf, 2)

for i = 1:n*x;
    if (i/n)<=xf;
        if vf(i)<vc;
            vf(i) = sqrt(2*x_(i)*Ft/m);
        end
        if vf(i)>=vc;
            
                vf(i) = vc;
        end
    end
    if (i/n)>xf;
        
        vf(i) = vc-sqrt(2*x_(i-xf*n)*Ff/m);
    end
end

plot(x_,vf)
xlabel('Distance (m)')
ylabel('Speed (m/s)')
title('Speed profile (Ft = 1000 N)')

%% 
plot(x_,vf*3.6)
xlabel('Distance (m)')
ylabel('Speed (km/h)')
title('Speed profile (Ft = 1000 N)')
