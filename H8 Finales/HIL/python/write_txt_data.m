
fB=sprintf(['u_send.txt']);

packB=fopen(fB,'w');


for i=1:1:length(accion_control_d)
   fprintf(packB, '%5d\n', accion_control_d(i));
end

fclose(packB);

