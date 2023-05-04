% 
% cargar la tabla como table=readtable(csvfile)
%
function [v, t] = sensor_data_convert(table, scale_factor)
    
    n = height(table)-1;

t = []; 
v = [];

for i = 1:1:n
    
    value_raw = string(table.Var5(i));
    value = str2num(extractAfter(value_raw,","));
    time = table.Var2(i);
    t = vertcat(t,time);
    v = vertcat(v,value/scale_factor);


end

figure
set(groot,'defaultAxesTickLabelInterpreter','latex');

colors = ["#EE7623", "k", "#003B4D", "#8F8FA3", "#7398AD", "#C1C5C8"];
plot(t, v,'Color',colors(1))
    %title("Recorded data")
    xlabel("Time",'Interpreter','latex')
    ylabel("Air gap [m]",'Interpreter','latex')

end