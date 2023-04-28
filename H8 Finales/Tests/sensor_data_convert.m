function [values, times] = sensor_data_convert(csvfile)
    
    values = csvfile(:,5);
    times = csvfile(:,2);
    str2num()
    %figure
    %plot(times, values)
    %title("Recorded data")
    %xlabel("Time")
    %ylabel("Value")

end