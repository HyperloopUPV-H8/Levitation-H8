% ROTACIONES
rotx_aux(1) = asin((airgaps(1) - airgaps(2))/(2 * pod.geometry.y_LEV));
rotx_aux(2) = asin((airgaps(3) - airgaps(4))/(2 * pod.geometry.y_LEV));

roty_aux(1) = asin((airgaps(1) - airgaps(3))/(2 * pod.geometry.x_LEV));
roty_aux(2) = asin((airgaps(2) - airgaps(4))/(2 * pod.geometry.x_LEV));

rotz_aux(1) = asin((airgaps(5) - airgaps(7))/(2 * pod.geometry.x_G));
rotz_aux(2) = asin((airgaps(6) - airgaps(8))/(2 * pod.geometry.x_G));

rotx = mean(rotx_aux);
roty = mean(roty_aux);
rotz = mean(rotz_aux);


% DISTANCIAS
y_aux(1) = airgaps(7)  + pod.geometry.y_G * cos(rotz) + pod.geometry.x_G * sin(rotz);
y_aux(2) = airgaps(8)  + pod.geometry.y_G * cos(rotz) - pod.geometry.x_G * sin(rotz);
y_aux(3) = - airgaps(9)  - pod.geometry.y_G * cos(rotz) - pod.geometry.x_G * sin(rotz);
y_aux(4) = - airgaps(10) - pod.geometry.y_G * cos(rotz) + pod.geometry.x_G * sin(rotz);

z_aux(1) = airgaps(1)  + pod.geometry.z_LEV * cos(roty) + pod.geometry.x_LEV * sin(roty) - pod.geometry.y_LEV * sin(rotx);
z_aux(2) = airgaps(2)  + pod.geometry.z_LEV * cos(roty) - pod.geometry.x_LEV * sin(roty) - pod.geometry.y_LEV * sin(rotx);
z_aux(3) = airgaps(3)  + pod.geometry.z_LEV * cos(roty) + pod.geometry.x_LEV * sin(roty) + pod.geometry.y_LEV * sin(rotx);
z_aux(4) = airgaps(4)  + pod.geometry.z_LEV * cos(roty) - pod.geometry.x_LEV * sin(roty) + pod.geometry.y_LEV * sin(rotx);

y = mean(y_aux);
z = mean(z_aux);
