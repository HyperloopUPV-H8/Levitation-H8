
%% Resistencias EMS

%para importar un csv darle doble click y poner los nombres de las
%variables

voltage = [5, 10, 15, 20, 25, 30];
n = length(voltage);

ems1_coef = zeros(n, 2);

[time, current] = CubeMonitor_CSV(voltios, 'MONITORED_CURRENTS_V');
[time, temp] = CubeMonitor_CSV(voltios, 'MONITORED_TEMPERATURE');

resistance_test(time, 30 , current, temp, 0);



%% Resistencias HEMS

