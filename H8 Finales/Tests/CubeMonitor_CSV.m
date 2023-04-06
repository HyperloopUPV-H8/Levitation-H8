function [t, v] = CubeMonitor_CSV(table, variable_name)
% Entras una tabla que corresponde al csv completo
% y el nombre de la etiqueta con los datos que 
% quieres separar en el vector

n = height(table);

t = [];
v = [];

for i = 1:1:n
    
    name = string(table.variablename(i));
    variable = table.v(i);
    time = table.t(i);

    if name == variable_name
        t = vertcat(t,time);
        v = vertcat(v,variable);
    end

end