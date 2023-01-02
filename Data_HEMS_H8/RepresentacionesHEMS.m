load('hems.mat')

%% Fuerza vertical

figure
surf(hems.Airgap,hems.Current,hems.Force_Vertical);

xlabel('Amplitude [A]')
ylabel('Airgap [mm]')
zlabel('Vertical Force [N]')
title('Barrido Airgap-Amplitud-Fuerza Vertical')

%% Flujo magnetico

figure
surf(hems.Airgap,hems.Current,hems.Flux);

xlabel('Amplitude [A]')
ylabel('Airgap [mm]')
zlabel('Magnetic Flux')
title('Barrido Airgap-Amplitud-Flujo magnético bobinas')
