% Script para plotear Z

table = readtable("z.csv");
n = height(table)-1;
t = []; 
z = [];

for i = 1:1:n
    value_raw = string(table.Var5(i));
    value = str2num(extractAfter(value_raw,","));
    time = table.Var2(i);
    t = vertcat(t,time);
    z = vertcat(z,value);
end

suelo=620.5614;

z=z-suelo+22.5;

for i=1:length(z)
    if z(i)<0
        z(i)=22.5;
    end
end

ref=linspace(18,18,length(z));

for i=1:length(z)
    if z(i)==22.5
        ref(i)=22.5;
    end
end

hold off
plot(seconds(t)-seconds(t(1)),z);
hold on
plot(seconds(t)-seconds(t(1)),ref);
legend("z real","z ref");
xlabel("Time [s]");
ylabel("Air gap [mm]");

[t1, v1] = vectors("y.csv");
figure
plot(seconds(t1)-seconds(t1(1)), v1)
legend("Y position");
xlabel("Time [s]");
ylabel("Y-axis [mm]");

[t1, v1] = vectors("lcu_master_current_coil_ems_1.csv");
figure
plot(seconds(t1)-seconds(t1(1)), v1)

hold on

[t2, v2] = vectors("lcu_master_slave_current_coil_ems_2.csv");
plot(seconds(t2)-seconds(t2(1)), v2)

hold on

[t3, v3] = vectors("lcu_master_current_coil_ems_3.csv");
plot(seconds(t3)-seconds(t3(1)), v3)

hold on

[t4, v4] = vectors("lcu_master_slave_current_coil_ems_2.csv");
plot(seconds(t4)-seconds(t4(1)), v4)
%legend("Airgap 1","Airgap 2","Airgap 3","Airgap 4");
legend("I EMS 1","I EMS 2","I EMS 3","I EMS 4");
xlabel("Time [s]");
%ylabel("Distance [mm]");
ylabel("Current [A]");

[t1, v1] = vectors("lcu_master_current_coil_hems_1.csv");
figure
plot(seconds(t1)-seconds(t1(1)), v1)

hold on

[t2, v2] = vectors("lcu_master_slave_current_coil_hems_2.csv");
plot(seconds(t2)-seconds(t2(1)), v2)

hold on

[t3, v3] = vectors("lcu_master_current_coil_hems_3.csv");
plot(seconds(t3)-seconds(t3(1)), v3)

hold on

[t4, v4] = vectors("lcu_master_slave_current_coil_hems_4.csv");
plot(seconds(t4)-seconds(t4(1)), v4)
%legend("Airgap 1","Airgap 2","Airgap 3","Airgap 4");
legend("I HEMS 1","I HEMS 2","I HEMS 3","I HEMS 4");
xlabel("Time [s]");
%ylabel("Distance [mm]");
ylabel("Current [A]");

[t1, v1] = vectors("lcu_master_rot_x.csv");
v1=v1*1000;
figure
plot(seconds(t1)-seconds(t1(1)), v1)

hold on

[t2, v2] = vectors("lcu_master_rot_y.csv");
v2=v2*1000;
plot(seconds(t2)-seconds(t2(1)), v2)

hold on

[t3, v3] = vectors("lcu_master_rot_z.csv");
v3=v3*1000;
plot(seconds(t3)-seconds(t3(1)), v3)
legend("Roll","Pitch","Yaw");
xlabel("Time [s]");
ylabel("Angle [mrad]");

[t1, v1] = vectors("lcu_master_airgap_1.csv");
figure
plot(seconds(t1)-seconds(t1(1)), v1)

hold on

[t2, v2] = vectors("lcu_master_slave_airgap_2.csv");
plot(seconds(t2)-seconds(t2(1)), v2)

hold on

[t3, v3] = vectors("lcu_master_airgap_3.csv");
plot(seconds(t3)-seconds(t3(1)), v3)

hold on

[t4, v4] = vectors("lcu_master_slave_airgap_4.csv");
plot(seconds(t4)-seconds(t4(1)), v4)
%legend(csvfile1,csvfile2,csvfile3,csvfile4)
legend("Airgap 1","Airgap 2","Airgap 3","Airgap 4");
%legend("I EMS 1","I EMS 2","I EMS 3","I EMS 4");
xlabel("Time [s]");
ylabel("Distance [mm]");
%ylabel("Current [A]");