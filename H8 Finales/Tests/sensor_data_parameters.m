function [m,v,offset] = sensor_data_parameters(values,nominalvalue)
    
    format long
    m=mean(values);
    v=var(values);
    offset=m-nominalvalue;
    
end