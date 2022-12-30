%% Parametros
Amplitude_min=-55;
Amplitude_max=55;
Amplitude_inter=1;
Airgap_min=10;
Airgap_max=23;
Airgap_inter=1;
num_cases=1554;
DATOS=zeros(num_cases,2);
%% Tratamiento datos

Amplitud=(Amplitude_min:Amplitude_inter:Amplitude_max)';
Airgap=(Airgap_min:Airgap_inter:Airgap_max)';

j=1;
for i=1:num_cases
    DATOS(i,1) = Amplitud(j);
    j=j+1;
    if j>length(Amplitud)
        j=1;
    end
end

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

%% Fuerza vertical

x = DATOS(:,1); %current
y = DATOS(:,2); %airgap
z = Fuerza_vertical;

PointsCurrent = 100;
PointsAirgap = 99;

xNew = linspace(min(x),max(x),PointsCurrent);
yNew = linspace(min(y),max(y),PointsAirgap)';

[X,Y] = meshgrid(xNew,yNew);
interpolacion = scatteredInterpolant(x,y,z,'linear','linear');
A = interpolacion(X,Y);

figure
surf(X,Y,A);

xlabel('Amplitude [A]')
ylabel('Airgap [mm]')
zlabel('Force [N]')
title('Barrido Airgap-Amplitud-Fuerza')

hems.Airgap = xNew;
hems.Current = yNew;
hems.Force_Vertical = A;
hems.Flux = zeros(PointsAirgap,PointsCurrent);

%% Tratamiento datos flujo

z = Flujo_bobina1;

interpolacion = scatteredInterpolant(x,y,z,'linear','linear');
A = interpolacion(X,Y);

figure
surf(X,Y,A);

xlabel('Amplitude [A]')
ylabel('Airgap [mm]')
zlabel('Magnetic Flux')
title('Barrido Airgap-Amplitud-Flujo magnético bobinas')

hems.Flux = A;

