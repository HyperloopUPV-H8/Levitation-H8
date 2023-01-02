
load('caracterizacionEMSfinal.mat')

ems.Airgap = VAirgap;
ems.Current = VAmplitud;
ems.Force_Vertical = MFuerzaVertical;
ems.Force_Horizontal = MFuerzaHorizontal;
ems.Flux = MFlujomagnetico;
ems.Inductance = zeros(length(VAmplitud)-2,length(VAirgap))
ems.Resistance = 0.447*2; %resistencia en el instante incial

%% Fuerza horizontal

figure
surf(ems.Airgap,ems.Current,ems.Force_Horizontal);

xlabel('Airgap [mm]')
ylabel('Amplitude [A]')
zlabel('Horizontal Force [N]')
title('Barrido Airgap-Amplitud-Fuerza Horizontal')

%% Fuerza vertical

figure
surf(ems.Airgap,ems.Current,ems.Force_Vertical);

xlabel('Airgap [mm]')
ylabel('Amplitude [A]')
zlabel('Vertical Force [N]')
title('Barrido Airgap-Amplitud-Fuerza Vertical')

%% Flujo magnetico

figure
surf(ems.Airgap,ems.Current,ems.Flux);

xlabel('Airgap [mm]')
ylabel('Amplitude [A]')
zlabel('Magnetic Flux')
title('Barrido Airgap-Amplitud-Flujo magnético bobinas')
