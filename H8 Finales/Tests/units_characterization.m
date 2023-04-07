
%% Resistencias EMS

%para importar un csv darle doble click y poner los nombres de las
%variables

% voltaje 5

%load data
[time, current] = CubeMonitor_CSV(data5v, 'MONITORED_CURRENTS_V',10000);
[time, temperature] = CubeMonitor_CSV(data5v, 'MONITORED_TEMPERATURE',10000);

% compute data
[res_5, temp_5, polinomio_5]  = resistance_test(time, 5 , current, temperature, 0.894, 1);

% voltaje 10

%load data
[time, current] = CubeMonitor_CSV(data10v, 'MONITORED_CURRENTS_V',10000);
[time, temperature] = CubeMonitor_CSV(data10v, 'MONITORED_TEMPERATURE',10000);

% compute data
[res_10, temp_10, polinomio_10]  = resistance_test(time, 10 , current, temperature, 0.894, 1);

% voltaje 15

%load data
[time, current] = CubeMonitor_CSV(data15v, 'MONITORED_CURRENTS_V',10000);
[time, temperature] = CubeMonitor_CSV(data15v, 'MONITORED_TEMPERATURE',10000);

% compute data
[res_15, temp_15, polinomio_15]  = resistance_test(time, 15 , current, temperature, 0.894, 1);

% voltaje 20

%load data
[time, current] = CubeMonitor_CSV(data20v, 'MONITORED_CURRENTS_V',10000);
[time, temperature] = CubeMonitor_CSV(data20v, 'MONITORED_TEMPERATURE',10000);

% compute data
[res_20, temp_20, polinomio_20]  = resistance_test(time, 20 , current, temperature, 0.894, 1);

% voltaje 25

%load data
[time, current] = CubeMonitor_CSV(data25v, 'MONITORED_CURRENTS_V',10000);
[time, temperature] = CubeMonitor_CSV(data25v, 'MONITORED_TEMPERATURE',10000);

% compute data
[res_25, temp_25, polinomio_25]  = resistance_test(time, 25 , current, temperature, 0.894, 1);

% voltaje 30

%load data
[time, current] = CubeMonitor_CSV(data30v, 'MONITORED_CURRENTS_V',10000);
[time, temperature] = CubeMonitor_CSV(data30v, 'MONITORED_TEMPERATURE',10000);

% compute data
[res_30, temp_30, polinomio_30]  = resistance_test(time, 30 , current, temperature, 0.894, 1);

figure
% plot(temp_5, polinomio_5); SE DESCARTA POR EL ERROR DEL SENSOR
% hold on
% plot(temp_10, polinomio_10); NO SE CALIENTA
% hold on
% plot(temp_15, polinomio_15, 'r'); RESULTADO MUY DIFERENTE AL RESTO DE
% CASOS DE MAYOR CORRIENTE
% yline(res_15,'--r')
% hold on
plot(temp_20, polinomio_20, 'g');
yline(res_20,'--g')
hold on
plot(temp_25, polinomio_25, 'b');
yline(res_25,'--b')
hold on
plot(temp_30, polinomio_30, 'm');
yline(res_30, '--m')
xlabel("Temperatura")
ylabel("Resistencia")
legend('Evolucion 20 V', 'Media 20 V', 'Evolucion 25 V', ...
    'Media 25 V', 'Evolucion 30 V', 'Media 30 V')
title("Evolucion de la resistencia con la temperatura")

%% Inercia térmica del EMS

[time, current] = CubeMonitor_CSV(inercia, 'MONITORED_CURRENTS_V',10000);
[time, temperature] = CubeMonitor_CSV(inercia, 'MONITORED_TEMPERATURE',10000);

[max_temp, tiempo_subiendo] = inercia_termica_test(time, current, temperature, 1);


%% Resistencias HEMS

