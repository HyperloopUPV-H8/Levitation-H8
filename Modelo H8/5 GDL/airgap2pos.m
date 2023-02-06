function u = ag2pos(airgaps)

% CONSTANTES

x_sragx = [0.8069, 0.8069, 0.8069, 0.8069]; 
y_sragx = [0.1046, 0.1046, 0.1046, 0.1046];
z_sragx = [0.09865, 0.09865, 0.09865, 0.09865]; 

x_sragz = [0.82191, 0.82191, 0.82191, 0.82191];
y_sragz = [0.2018, 0.2018, 0.2018, 0.2018];
z_sragz = [0.0396, 0.0396, 0.0396, 0.0396]; 

z_infr = 0.6328;

coder.varsize('rotx_aux');
coder.varsize('roty_aux');
coder.varsize('rotz_aux');
coder.varsize('y_aux');
coder.varsize('z_aux');

rotx_aux=zeros(2,1);
roty_aux=zeros(2,1);
rotz_aux=zeros(2,1);
y_aux=zeros(4,1);
z_aux=zeros(4,1);

% ROTACIONES
rotx_aux(1) = asin((airgaps(1) - airgaps(2))/(y_sragz(1) + y_sragz(2)));
rotx_aux(2) = asin((airgaps(3) - airgaps(4))/(y_sragz(3) + y_sragz(4)));

roty_aux(1) = asin((airgaps(3) - airgaps(1))/(x_sragz(3) + x_sragz(1)));
roty_aux(2) = asin((airgaps(4) - airgaps(2))/(x_sragz(4) + x_sragz(2)));

rotz_aux(1) = asin((airgaps(5) - airgaps(7))/(x_sragx(1) + x_sragx(3)));
rotz_aux(2) = asin((airgaps(8) - airgaps(6))/(x_sragx(2) + x_sragx(4)));

rotx = mean(rotx_aux);
roty = mean(roty_aux);
rotz = mean(rotz_aux);

% DISTANCIAS
y_aux(1) = + airgaps(5) - y_sragx(1) * cos(rotz) - x_sragx(1) * sin(rotz);
y_aux(2) = - airgaps(6) + y_sragx(2) * cos(rotz) - x_sragx(2) * sin(rotz);
y_aux(3) = + airgaps(7) - y_sragx(3) * cos(rotz) + x_sragx(3) * sin(rotz);
y_aux(4) = - airgaps(8) + y_sragx(4) * cos(rotz) + x_sragx(4) * sin(rotz);

z_aux(1) = z_infr + airgaps(1) - z_sragz(1) * cos(roty) - x_sragz(1) * sin(roty) + y_sragz(1) * sin(rotx);
z_aux(2) = z_infr + airgaps(2) - z_sragz(1) * cos(roty) - x_sragz(2) * sin(roty) - y_sragz(2) * sin(rotx);
z_aux(3) = z_infr + airgaps(3) - z_sragz(1) * cos(roty) + x_sragz(3) * sin(roty) + y_sragz(3) * sin(rotx);
z_aux(4) = z_infr + airgaps(4) - z_sragz(1) * cos(roty) + x_sragz(4) * sin(roty) - y_sragz(4) * sin(rotx);


y = mean(y_aux);
z = mean(z_aux);

u =[y, z, rotx, roty, rotz]';