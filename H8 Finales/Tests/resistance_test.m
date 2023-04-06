function p = resistance_test(time, voltage_case, current, temperature, graphs)
% Process data of resistance depending on evolution of temperature 
% Coeficientes del ajuste, p(0) + x * p(1) + x^2 * p(2)
% Si graphs esta a 1 plotea los datos, si esta a 0 no

if graphs == 1

    figure
    scatter(time, temperature)
    title("Temperature Evolution")
    xlabel("Time")
    ylabel("Temperature")
    
    figure
    scatter(temperature, current)
    title("Current as function of temperature")
    xlabel("Temperature")
    ylabel("Current")

end


n = length(time);

resistance = []; %V = I * R -> R = V / I

for i = 1:1:n
    resistance(i) = voltage_case / current(i);
end

p = polyfit(temperature, resistance, 1); % aproximacion a una ecuacion de grado 1
f1 = polyval(p,temperature);

if graphs == 1

    figure
    scatter(temperature, resistance)
    hold on
    plot(temperature, f1,'r--')
    title("Resistance Evolution")
    xlabel("Time")
    ylabel("Resistance")

end

mean(resistance)

end