% CONSTANTES
x_LEV = [0.46843, 0.46843, 0.54357, 0.54357] % pendiente de revisar
y_LEV = [0.24712, 0.23288, 0.24712, 0.23288] % pendiente de revisar
z_LEV = [0.7225, 0.7225, 0.7225, 0.7225] % pendiente de revisar

x_LIM = %falta
y_LIM = %falta
z_LIM = %falta

z_cm = %falta


% DISTANCIAS
airgaps(5) =  y + y_LIM * cos(rotz) + x_LIM * sin(rotz);
airgaps(6)  = - y + y_LIM * cos(rotz) - x_LIM * sin(rotz);
airgaps(7) = + y + y_LIM * cos(rotz) - x_LIM * sin(rotz);
airgaps(8) = - y + y_LIM * cos(rotz) + x_LIM * sin(rotz);


airgaps(1) = - z + z_cm  + z_LEV(1) * cos(roty) + x_LEV(1) * sin(roty) - y_LEV(1) * sin(rotx);
airgaps(2) = - z + z_cm  + z_LEV(1) * cos(roty) + x_LEV(1) * sin(roty) + y_LEV(1) * sin(rotx);
airgaps(3) = - z + z_cm  + z_LEV(1) * cos(roty) - x_LEV(1) * sin(roty) - y_LEV(1) * sin(rotx);
airgaps(4) = - z + z_cm  + z_LEV(1) * cos(roty) - x_LEV(1) * sin(roty) + y_LEV(1) * sin(rotx);


y = mean(y_aux);
z = mean(z_aux);
