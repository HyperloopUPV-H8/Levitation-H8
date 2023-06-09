t = out.hil.Time;
z_lenta = out.hil.Data;
z_rapida = out.hil.Data;

t_cortada = t(1:length(z_preHIL));
z_lenta_cortada = z_lenta(1:length(z_preHIL));
z_rapida_cortada = z_rapida(1:length(z_preHIL));

z_preHIL = out.pre.Data;

figure
plot(t_cortada,z_lenta_cortada)
hold on
plot(t_cortada,z_rapida_cortada)
hold on
plot(t_cortada, z_preHIL)

%testbench results
time = t_cortada;
prehil = z_preHIL;
posthil = z_lenta_cortada;

%% 5 DOF

time = MIL.Time;
z_MIL = MIL.Data;

z_HIL2 = HIL2.Data;
t_recortada = time(1:length(z_HIL2));
z_MIL_recortada = z_MIL(1:length(z_HIL2));

figure
plot(t_recortada,z_MIL_recortada)
hold on
plot(t_recortada, z_HIL2)

