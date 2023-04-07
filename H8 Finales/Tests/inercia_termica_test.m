function [max_temp, tiempo_subiendo] = inercia_termica_test(time, current, temperature, graphs)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

current_f = movmean(current, 200);
temperature_f = movmean(temperature, 200);

n = length(time);

time_r = [];
current_r = [];
temp_r = [];

for i = 900:1:n
    if current_f(i) < 2 % Si no se esta aplicando corriente
        time_r = vertcat(time_r, time(i));
        current_r = vertcat(current_r, current_f(i));
        temp_r = vertcat(temp_r, temperature_f(i));
    end
end

r = length(time_r);

x = (1:r)';
f = fit(x, temp_r, 'exp2');
eq = f(x(1:r));

[max_temp, tiempo_subiendo] = max(eq);
tiempo_subiendo = tiempo_subiendo * 1/100;
tiempo = x * 1/100;
diff = max_temp - f(0);

if graphs == 1
    figure
    plot(tiempo, eq)
    xlim([0 250])
    title('Evolucion temperatura al acabar de aplicar corriente')
    xlabel("Tiempo [s]")
    ylabel("Temperatura")
end

display("La maxima temperatura se alcanza en el segundo:")
tiempo_subiendo
display("La maxima temperatura es:")
max_temp
display("La diferencia de temepraturas es de:")
diff

end