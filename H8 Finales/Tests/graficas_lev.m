clc;
option=-1;
while option~=0
    fprintf("¿Qué gráficas quieres ver? \n\t1- Airgaps verticales \n\t2- Airgaps horizontales \n\t3- Rotaciones \n\t4- Posición Z \n\t5- Posición Y \n\t6- Corrientes HEMS \n\t7- Corrientes EMS \n\t8- Todos \n\t0- Salir \n");
    option=input("Elección:");
    
    switch(option)
        case 1
            plot_gui("lcu_master_airgap_1.csv", "lcu_master_slave_airgap_2.csv", "lcu_master_airgap_3.csv","lcu_master_slave_airgap_4.csv");
        case 2
            plot_gui("lcu_master_airgap_5.csv", "lcu_master_slave_airgap_6.csv", "lcu_master_airgap_7.csv","lcu_master_slave_airgap_8.csv");
        case 3
            plot_gui("lcu_master_rot_x.csv", "lcu_master_rot_y.csv", "lcu_master_rot_z.csv");
        case 4
            plot_gui("z.csv");
        case 5
            plot_gui("y.csv");
        case 6
            plot_gui("lcu_master_current_coil_hems_1.csv", "lcu_master_slave_current_coil_hems_2.csv", "lcu_master_current_coil_hems_3.csv","lcu_master_slave_current_coil_hems_4.csv");
        case 7
            plot_gui("lcu_master_current_coil_ems_1.csv", "lcu_master_slave_current_coil_ems_2.csv", "lcu_master_current_coil_ems_3.csv","lcu_master_slave_current_coil_ems_4.csv");
        case 8
            plot_gui("lcu_master_airgap_1.csv", "lcu_master_slave_airgap_2.csv", "lcu_master_airgap_3.csv","lcu_master_slave_airgap_4.csv");
            plot_gui("lcu_master_airgap_5.csv", "lcu_master_slave_airgap_6.csv", "lcu_master_airgap_7.csv","lcu_master_slave_airgap_8.csv");
            plot_gui("lcu_master_rot_x.csv", "lcu_master_rot_y.csv", "lcu_master_rot_z.csv");
            plot_gui("z.csv");
            plot_gui("y.csv");
            plot_gui("lcu_master_current_coil_hems_1.csv", "lcu_master_slave_current_coil_hems_2.csv", "lcu_master_current_coil_hems_3.csv","lcu_master_slave_current_coil_hems_4.csv");
            plot_gui("lcu_master_current_coil_ems_1.csv", "lcu_master_slave_current_coil_ems_2.csv", "lcu_master_current_coil_ems_3.csv","lcu_master_slave_current_coil_ems_4.csv");
        otherwise
            %disp("Opciones disponibles: airgaps_vertical, rotaciones, posicion_z, corrientes_hems");
end
end


function [t1, v1, v2, v3] = plot_gui(csvfile1, csvfile2, csvfile3,csvfile4)

switch nargin
    case 1
        [t1, v1] = vectors(csvfile1);
		figure
        plot(seconds(t1)-seconds(t1(1)), v1)
        legend(csvfile1)
        legend("Y position");
        xlabel("Time [s]");
        ylabel("Y-axis [mm]");
    case 2
        [t1, v1] = vectors(csvfile1);
		figure
        plot(seconds(t1)-seconds(t1(1)), v1)
        
        hold on
        
        [t2, v2] = vectors(csvfile2);
        plot(seconds(t2)-seconds(t2(1)), v2)
        legend(csvfile1,csvfile2)
    case 3
        [t1, v1] = vectors(csvfile1);
        v1=v1*1000;
		figure
        plot(seconds(t1)-seconds(t1(1)), v1)
        
        hold on
        
        [t2, v2] = vectors(csvfile2);
        v2=v2*1000;
        plot(seconds(t2)-seconds(t2(1)), v2)

        hold on

        [t3, v3] = vectors(csvfile3);
        v3=v3*1000;
        plot(seconds(t3)-seconds(t3(1)), v3)
        legend(csvfile1,csvfile2,csvfile3)
        legend("Roll","Pitch","Yaw");
        xlabel("Time [s]");
        ylabel("Angle [mrad]");
     
    case 4
        [t1, v1] = vectors(csvfile1);
		figure
        plot(seconds(t1)-seconds(t1(1)), v1)
        
        hold on
        
        [t2, v2] = vectors(csvfile2);
        plot(seconds(t2)-seconds(t2(1)), v2)

        hold on

        [t3, v3] = vectors(csvfile3);
        plot(seconds(t3)-seconds(t3(1)), v3)

        hold on

        [t4, v4] = vectors(csvfile4);
        plot(seconds(t4)-seconds(t4(1)), v4)
        legend(csvfile1,csvfile2,csvfile3,csvfile4)
        %legend("Airgap 1","Airgap 2","Airgap 3","Airgap 4");
        %legend("I EMS 1","I EMS 2","I EMS 3","I EMS 4");
        xlabel("Time [s]");
        %ylabel("Distance [mm]");
        %ylabel("Current [A]");
end

end

function [t, v] = vectors(csvfile)

    table = readtable(csvfile);
    n = height(table)-1;
    t = []; 
    v = [];

    for i = 1:1:n
        value_raw = string(table.Var5(i));
        value = str2num(extractAfter(value_raw,","));
        time = table.Var2(i);
        t = vertcat(t,time);
        v = vertcat(v,value);
    end

end