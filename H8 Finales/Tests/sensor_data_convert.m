function [values, times] = sensor_data_convert(csvfile)
    
    values = csvfile(:,2);
    times = csvfile(:,1);
    
    figure
    plot(times, values)
    title("Recorded data")
    xlabel("Time")
    ylabel("Value")

end