
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


%% Caracterizacion EMS

% airgap 19 -> 1:9
% airgap 16 -> 10:16
% airgap 13 -> 17:21

f19 = fit(ems_caracterizacion.CorrienteTeorica(1:9), ems_caracterizacion.Fuerza2(1:9), 'exp1');
f16 = fit(ems_caracterizacion.CorrienteTeorica(10:16), ems_caracterizacion.Fuerza2(10:16), 'exp1');
f13 = fit(ems_caracterizacion.CorrienteTeorica(17:22), ems_caracterizacion.Fuerza2(17:21), 'exp1');

figure
scatter(ems_caracterizacion.CorrienteTeorica(1:9), ems_caracterizacion.Fuerza2(1:9),'blue')
hold on
scatter(ems_caracterizacion.CorrienteTeorica(10:16), ems_caracterizacion.Fuerza2(10:16),'green')
hold on
scatter(ems_caracterizacion.CorrienteTeorica(17:21), ems_caracterizacion.Fuerza2(17:21),'red')

legend('19 mm', '16 mm', '13 mm')
xlabel("Corriente")
ylabel("Fuerza")
title("Caracterizacion EMS")

figure

subplot(1,3,1)
scatter(ems_caracterizacion.CorrienteTeorica(1:9), ems_caracterizacion.Fuerza2(1:9),'blue')
hold on
plot(f19,'blue')
hold on
scatter(ems_caracterizacion.CorrienteTeorica(1:9), ems_caracterizacion.ForceReal(1:9),'blue','filled')

xlabel("Corriente")
ylabel("Fuerza")
title("19 mm")

subplot(1,3,2)
scatter(ems_caracterizacion.CorrienteTeorica(10:16), ems_caracterizacion.Fuerza2(10:16),'green')
hold on
plot(f16,'green')
hold on
scatter(ems_caracterizacion.CorrienteTeorica(10:16), ems_caracterizacion.ForceReal(10:16),'green','filled')

xlabel("Corriente")
ylabel("Fuerza")
title("16 mm")

subplot(1,3,3)
scatter(ems_caracterizacion.CorrienteTeorica(17:21), ems_caracterizacion.Fuerza2(17:21),'red')
hold on
plot(f13,'red')
hold on
scatter(ems_caracterizacion.CorrienteTeorica(17:21), ems_caracterizacion.ForceReal(17:21),'red','filled')

xlabel("Corriente")
ylabel("Fuerza")
title("13 mm")


%% Caracterizacion HEMS

% Airgap 22 -> 1:9
% Airgap 19 -> 10:21
% Airgap 16 -> 22:28
% Airgap 13 -> 29:37

% Sin corriente -> 38:41

figure

subplot(2,3,1)
scatter(hems_caracterizazcion.CorrienteTeoricaA(1:9), hems_caracterizazcion.FuerzaRealBobinas(1:9),'blue')
hold on
scatter(hems_caracterizazcion.CorrienteTeoricaA(1:9), hems_caracterizazcion.FuerzaTeoBobinas(1:9),'blue','filled')

xlabel("Corriente")
ylabel("Fuerza")
title("22 mm")

subplot(2,3,2)
scatter(hems_caracterizazcion.CorrienteTeoricaA(10:21), hems_caracterizazcion.FuerzaRealBobinas(10:21),'green')
hold on
scatter(hems_caracterizazcion.CorrienteTeoricaA(10:21), hems_caracterizazcion.FuerzaTeoBobinas(10:21),'green','filled')

xlabel("Corriente")
ylabel("Fuerza")
title("19 mm")

subplot(2,3,3)
scatter(hems_caracterizazcion.CorrienteTeoricaA(22:28), hems_caracterizazcion.FuerzaRealBobinas(22:28),'red')
hold on
scatter(hems_caracterizazcion.CorrienteTeoricaA(22:28), hems_caracterizazcion.FuerzaTeoBobinas(22:28),'red','filled')

xlabel("Corriente")
ylabel("Fuerza")
title("16 mm")

subplot(2,3,4)
scatter(hems_caracterizazcion.CorrienteTeoricaA(29:37), hems_caracterizazcion.FuerzaRealBobinas(29:37),'magenta')
hold on
scatter(hems_caracterizazcion.CorrienteTeoricaA(29:37), hems_caracterizazcion.FuerzaTeoBobinas(29:37),'magenta','filled')

xlabel("Corriente")
ylabel("Fuerza")
title("13 mm")

subplot(2,3,5)
scatter(hems_caracterizazcion.AirgapRealmm(38:41), hems_caracterizazcion.FuerzaRealBobinas(38:41),'black')
hold on
scatter(hems_caracterizazcion.AirgapRealmm(38:41), hems_caracterizazcion.FuerzaTericaN(38:41),'black','filled')

xlabel("Airgap")
ylabel("Fuerza")
title("0 A")

legend("Filled Teórica", "Void Measured")


