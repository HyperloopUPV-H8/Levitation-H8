function u = pos2airgap(data)

% CONSTANTES

x_sragx = [0.8069, 0.8069, 0.8069, 0.8069]; 
y_sragx = [0.1046, 0.1046, 0.1046, 0.1046];
z_sragx = [0.09865, 0.09865, 0.09865, 0.09865]; 

x_sragz = [0.82191, 0.82191, 0.82191, 0.82191];
y_sragz = [0.2018, 0.2018, 0.2018, 0.2018];
z_sragz = [0.0396, 0.0396, 0.0396, 0.0396]; 

z_infr = 0.6328;

y = data(1);
z = data(2);
rotx = data(3);
roty = data(4);
rotz = data(5);



% DISTANCIAS
airgap5 = + y + y_sragx(1) * cos(rotz) + x_sragx(1) * sin(rotz);
airgap6 = - y + y_sragx(2) * cos(rotz) - x_sragx(2) * sin(rotz);
airgap7 = + y + y_sragx(3) * cos(rotz) - x_sragx(3) * sin(rotz);
airgap8 = - y + y_sragx(4) * cos(rotz) + x_sragx(4) * sin(rotz);


airgap1 =  +z - z_infr  + z_sragz(1) * cos(roty) + x_sragz(1) * sin(roty) - y_sragz(1) * sin(rotx);
airgap2 =  +z - z_infr  + z_sragz(2) * cos(roty) + x_sragz(2) * sin(roty) + y_sragz(2) * sin(rotx);
airgap3 =  +z - z_infr  + z_sragz(3) * cos(roty) - x_sragz(3) * sin(roty) - y_sragz(3) * sin(rotx);
airgap4 =  +z - z_infr  + z_sragz(4) * cos(roty) - x_sragz(4) * sin(roty) + y_sragz(4) * sin(rotx);


u =[airgap1, airgap2, airgap3, airgap4, airgap5, airgap6, airgap7, airgap8]';
