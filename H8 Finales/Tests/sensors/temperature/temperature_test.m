%% Temperaturas EMS

format long;

[time, temp]=CubeMonitor_CSV(inercia2, 'MONITORED_TEMPERATURE', 1e4);

f_T=time(2)-time(1)
variance_T = variance(temp)

filtered_T = movmedian(temp,30);

figure
set(groot,'defaultAxesTickLabelInterpreter','latex');  

colors = ["#EE7623", "k", "#003B4D", "#8F8FA3", "#7398AD", "#C1C5C8"];
plot(time,temp,'Color',colors(1))
ylabel('Temperature [ºC]','Interpreter','latex')
xlabel('Time [s]','Interpreter','latex')
hold on
plot(time, filtered_T, 'Color',colors(3))
legend('Temperature raw values','Temperature filtered values','Interpreter','latex')

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