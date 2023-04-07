function [t, v] = CubeMonitor_CSV(table, variable_name, factor_escalado)
% Entras una tabla que corresponde al csv completo
% y el nombre de la etiqueta con los datos que 
% quieres separar en el vector

n = height(table);

t = []; %  1 / f adquisicion * n = tiempo grabado
v = [];

for i = 1:1:n
    
    name = string(table.variablename(i));
    variable = table.y(i);
    time = table.x(i);

    if name == variable_name
        t = vertcat(t,time/10000);
        v = vertcat(v,variable/factor_escalado);
    end

end