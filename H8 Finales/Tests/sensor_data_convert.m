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

plot(t, v)
    title("Recorded data")
    xlabel("Time")
    ylabel("Value")

end