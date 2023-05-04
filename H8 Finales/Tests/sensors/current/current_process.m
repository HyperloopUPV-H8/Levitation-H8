table = readtable("current_coil_hems_3.csv");

[v, t] = sensor_data_convert(table, 1);
[m,var,offset] = sensor_data_parameters(v(71:632),5);

frec = t(2) - t(1);