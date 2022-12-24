%% Parametros
Amplitude_min=-55;
Amplitude_max=55;
Amplitude_inter=1;
Airgap_min=10;
Airgap_max=23;
Airgap_inter=1;
num_cases=1554;
DATOS=zeros(num_cases,2);
%% Generación de vectores
Amplitud=(Amplitude_min:Amplitude_inter:Amplitude_max)';
Airgap=(Airgap_min:Airgap_inter:Airgap_max)';
%% Ordenación de datos de amplitud
j=1;
for i=1:num_cases
    DATOS(i,1) = Amplitud(j);
    j=j+1;
    if j>length(Amplitud)
        j=1;
    end
end
%% Ordenación de datos de airgap
j=1;
k=1;
for i=1:num_cases
    DATOS(i,2) = Airgap(j);
    k=k+1;
    if k>length(Amplitud) && j<length(Airgap)
       j=j+1;
       k=1;
    end
end

%% Tratamiento datos

x = DATOS(:,1);
y = DATOS(:,2);
z = Fuerza_vertical;
​
nPoints = 100;
xNew = linspace(min(x),max(x),nPoints);
yNew = linspace(min(y),max(y),nPoints)';
​
​
[X,Y] = meshgrid(xNew,yNew);
​
interpolacion = scatteredInterpolant(x,y,z,'linear','linear');
A = interpolacion(X,Y);
​
figure
surf(X,Y,A);
​
xlabel('Amplitude [A]')
ylabel('Airgap [mm]')
zlabel('Force [N]')
title('Barrido Airgap-Amplitud-Fuerza')
