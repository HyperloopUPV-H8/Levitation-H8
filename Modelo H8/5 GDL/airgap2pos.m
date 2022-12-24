% CONSTANTES
x_LEV = [0.46843, 0.46843, 0.54357, 0.54357]
y_LEV = [0.24712, 0.23288, 0.24712, 0.23288]
z_LEV = [-0.7225, -0.7225, -0.7225, -0.7225]

x_LIM = %falta
y_LIM = %falta
z_LIM = %falta

% ROTACIONES
rotx_aux(1) = asin((airgaps(1) - airgaps(2))/(2 * y_LEV));
rotx_aux(2) = asin((airgaps(3) - airgaps(4))/(2 * y_LEV));

roty_aux(1) = asin((airgaps(3) - airgaps(1))/(2 * x_LEV));
roty_aux(2) = asin((airgaps(4) - airgaps(2))/(2 * x_LEV));

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

z_aux(1) = airgaps(1)  + z_LEV * cos(roty) + x_LEV * sin(roty) - y_LEV * sin(rotx);
z_aux(2) = airgaps(2)  + z_LEV * cos(roty) + x_LEV * sin(roty) + y_LEV * sin(rotx);
z_aux(3) = airgaps(3)  + z_LEV * cos(roty) - x_LEV * sin(roty) - y_LEV * sin(rotx);
z_aux(4) = airgaps(4)  + z_LEV * cos(roty) - x_LEV * sin(roty) + y_LEV * sin(rotx);

y = mean(y_aux);
z = mean(z_aux);
