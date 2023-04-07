function [res, temp_ev, polinomio]  = resistance_test(time, voltage_case, current, temperature, res_teorica, graphs)
% Process data of resistance depending on evolution of temperature 
% Coeficientes del ajuste, p(0) + x * p(1) + x^2 * p(2)
% Pasarle la resistencia teorica para poder eliminar casos indeseados
% Si graphs esta a 1 plotea los datos, si esta a 0 no

% Eliminar los casos de 0 A
theorical = voltage_case / res_teorica;

n = length(time);

temperature_sh = [];
current_sh = [];
time_sh = [];

% Quitar casos antes y despues de empezar
for i = 1:1:n
    if (current(i) > (theorical - 1) && (current(i) < (theorical + 1)))
        current_sh = vertcat(current_sh, current(i));
        temperature_sh = vertcat(temperature_sh, temperature(i));
        time_sh = vertcat(time_sh, time(i));
    end
end

resistance = [];
m = length(current_sh);

for i = 1:1:m
    calculated = voltage_case / current_sh(i);
    resistance = vertcat(resistance, calculated);
end

p = polyfit(temperature_sh, resistance, 1); % aproximacion a una ecuacion de grado 1
f1 = polyval(p,temperature_sh);

if graphs == 1
    
    % Evolucion de la resistencia en funcion de la temperatura
    title_r = strcat('Resistance Evolution ', string(voltage_case), ' V');
    figure
    scatter(temperature_sh, resistance)
    hold on
    plot(temperature_sh, f1,'r--')
    title(title_r)
    xlabel("Temperature")
    ylabel("Resistance")
    hold off

end

res = mean(resistance);
temp_ev = temperature_sh;
polinomio = f1;

end