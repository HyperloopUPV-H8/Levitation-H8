load('hems.mat')

%% Fuerza vertical

figure
surf(hems.Current,hems.Airgap, hems.Force_Vertical);

xlabel('Amplitude [A]')
ylabel('Airgap [mm]')
zlabel('Vertical Force [N]')
title('Barrido Airgap-Amplitud-Fuerza Vertical')

%% Flujo magnetico

figure
surf(hems.Current,hems.Airgap,hems.Flux);

xlabel('Amplitude [A]')
ylabel('Airgap [mm]')
zlabel('Magnetic Flux')
title('Barrido Airgap-Amplitud-Flujo magnético bobinas')

%% Inductancia

n = length(hems.Current);

figure
surf(hems.Current(1:(n-2)), hems.Airgap, hems.Inductance);
xlabel('Amplitude [A]')
ylabel('Airgap [mm]')
zlabel('Inductance [H]')
title('Calculo Inductancias')


