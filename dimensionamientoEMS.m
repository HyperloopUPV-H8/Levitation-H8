% Fuerza de tracción (N)
Ft = 1000;
% Numero de EMS por lado
nEMS = 2;
% Desviación máxima (mm)
d = 5;
% Ratio (Fl/Ft) para desviación de 5mm
r0 = 5.715517241;
r = r0/5;
% Posición actual
x = -5;
% Masa (kg)
m = 200;
% Factor de tolerancia
T = 2;
%% 
F0 = r * d * (Ft/2) / nEMS;
F0 = F0 * T
%% 
Ft_ = linspace(100,9000,1000);
F = r * d * Ft_ / nEMS;
F = F * T;
plot(Ft_,F)
xlabel('Fuerza de tracción (N)')
ylabel('Fuerza EMS (N)')
title('Dimensionamiento EMS')