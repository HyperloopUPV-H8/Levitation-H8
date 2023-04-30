%% Temperaturas EMS

format long;

[time, temp]=CubeMonitor_CSV(inercia2, 'MONITORED_TEMPERATURE', 1e4);

f_T=time(2)-time(1)
variance_T = variance(temp)

f1 = movmedian(temp,30);
figure
plot(time,temp)
hold on
plot(time, f1, 'g')

function variance_T = variance(value)
    
    n = length(value);
    difference = [];

    for i=1:n

        if i~=1

           d = value(i) - value(i-1);
           difference = vertcat(difference,d);

        end

    end

    variance_T=max(difference);

end