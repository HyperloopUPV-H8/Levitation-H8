% CONSTANTES
x_LEV = [0.46843, 0.46843, 0.54357, 0.54357]
y_LEV = [0.24712, 0.23288, 0.24712, 0.23288]
z_LEV = [-0.7225, -0.7225, -0.7225, -0.7225]

x_LIM = %falta
y_LIM = %falta
z_LIM = %falta

% ROTACIONES
rotx_aux(1) = asin((airgaps(1) - airgaps(2))/(y_LEV(1) + y_LEV(2)));
rotx_aux(2) = asin((airgaps(3) - airgaps(4))/(y_LEV(3) + y_LEV(4)));

roty_aux(1) = asin((airgaps(3) - airgaps(1))/(x_LEV(3) + x_LEV(1)));
roty_aux(2) = asin((airgaps(4) - airgaps(2))/(x_LEV(4) + x_LEV(2)));

rotz_aux(1) = asin((airgaps(5) - airgaps(7))/(2 * x_LIM));
rotz_aux(2) = asin((airgaps(6) - airgaps(8))/(2 * x_LIM));

rotx = mean(rotx_aux);
roty = mean(roty_aux);
rotz = mean(rotz_aux);


% DISTANCIAS
y_aux(1) = + airgaps(5) - y_LIM * cos(rotz) - x_LIM * sin(rotz);
y_aux(2) = - airgaps(6) + y_LIM * cos(rotz) - x_LIM * sin(rotz);
y_aux(3) = + airgaps(7) - y_LIM * cos(rotz) + x_LIM * sin(rotz);
y_aux(4) = - airgaps(8) + y_LIM * cos(rotz) + x_LIM * sin(rotz);

z_aux(1) = airgaps(1)  + z_LEV(1) * cos(roty) + x_LEV(1) * sin(roty) - y_LEV(1) * sin(rotx);
z_aux(2) = airgaps(2)  + z_LEV(2) * cos(roty) + x_LEV(2) * sin(roty) + y_LEV(2) * sin(rotx);
z_aux(3) = airgaps(3)  + z_LEV(3) * cos(roty) - x_LEV(3) * sin(roty) - y_LEV(3) * sin(rotx);
z_aux(4) = airgaps(4)  + z_LEV(4) * cos(roty) - x_LEV(4) * sin(roty) + y_LEV(4) * sin(rotx);

y = mean(y_aux);
z = mean(z_aux);
