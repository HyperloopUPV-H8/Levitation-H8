%% Vectores simulación 1 GDL Comparacion Lineal y no Lineal 

load("Simulacion_1gdl_comparacionLinealNoLineal.mat");

time = out.comparacion_z_lineal.Time;
lineal = out.comparacion_z_lineal.Data;
noLineal = out.comparacion_z_nolineal.Data;

% plot(time, lineal)
% hold on
% plot(time, noLineal)

%% Vectores simulacion 1 GDL Sin sensor

load("Simulacion_1gdl_SinSensor.mat");

aux = 0.01965;

time = out.z_sinSensor_1gld.Time;
z = out.z_sinSensor_1gld.Data;
corriente = out.I_sinSensor_1gld1.Data;
temperatura = out.T_sinSensor_1gld1.Data;

z_ref = [];
for i = 1:1:7524
    recta = 0*i+aux;
    z_ref = [z_ref recta];
end
z_ref = z_ref';

% figure
% plot(time, z);
% hold on
% plot(time,z_ref);
% 
% figure
% plot(time, corriente);
% 
% figure
% plot(time, temperatura);

%% Vectores simulacion 1 GDL discretizado y con sensor 

load("Simulacion_1gdl_ConSensor.mat");

aux = 0.01965;

time = out.z_conSensor_1gld.Time;
z = out.z_conSensor_1gld.Data;
corriente = out.I_conSensor_1gld1.Data;
temperatura = out.T_conSensor_1gld1.Data;

z_ref = [];
for i = 1:1:3424
    recta = 0*i+aux;
    z_ref = [z_ref recta];
end
z_ref = z_ref';

% figure
% plot(time,z);
% hold on
% plot(time,z_ref);
% 
% figure
% plot(time, corriente);
% 
% figure
% plot(time, temperatura);
% 
 airgap_Filtrado_Time = out.airgapFiltrado_conSensor_1gld1.Time;
 airgap_sinFiltrar = out.airgapSinFiltrar_conSensor_1gld.Data;
 airgap_Filtrado = out.airgapFiltrado_conSensor_1gld1.Data;
% 
figure
plot(time, airgap_sinFiltrar, 'Color',colors(1), 'LineWidth', 1);
hold on
plot(airgap_Filtrado_Time, airgap_Filtrado,'Color', colors(2), 'LineWidth', 1);
xlabel("Time [s]")
ylabel("Distance sensor measure [mm]")
legend('Non-filtered','Filtered')

