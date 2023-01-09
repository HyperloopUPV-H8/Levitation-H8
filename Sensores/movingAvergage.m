function [output] = movingAvergage(input,M)
% input: valores de entrada al filtro
% output: valores de salida del filtro
% M: numero de coeficientes
% Implementación del filtro moving average

sum = 0;

for i = 1:1:M
    sum = sum + input(i);
end

output = (1/M)*sum;

end