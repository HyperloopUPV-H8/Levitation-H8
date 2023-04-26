%% Temperaturas EMS

temp_nom=40;
[time, temp]=CubeMonitor_CSV(inercia2, 'MONITORED_TEMPERATURE', 1e4);


p = polyfit(time, temp, 2); 
f1 = polyval(p, time);

figure
scatter(time,temp)
hold on
plot(time, f1, 'g')

[mean_T,variance_T,offset_T] = sensor_data_parameters(temp,temp_nom)