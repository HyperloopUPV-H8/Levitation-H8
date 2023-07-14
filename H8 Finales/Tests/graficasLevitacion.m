function  [] = graficasLevitacion()
    % Script para plotear las graficas de Levitacion
    %Frecuencias:
        freq_z=60;
        freq_y=60;
        freq_rotaciones=60;
        freq_airgaps=60;
        freq_corrientes=60;


    % Plotear pos Z

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
        
        t_z=linspace(0,length(z)/freq_z,length(z));

        suelo=619.512;
        techo=608;

        v_suelo=linspace(suelo,suelo,length(z));
        v_techo=linspace(techo,techo,length(z));
        
        for i=1:length(z)
            if z(i)>600
                j=i;
                break;
            end
        end

        for k=1:j
            z(k)=z(j);
        end
        
        ref=linspace(616,616,length(z));
        
%         for i=1:length(z)
%             if z(i)==22.5
%                 %ref(i)=0;
%                 ref(i)=22.5;
%             end
%         end
        
        figure
        plot(t_z,z);
        hold on
        plot(t_z,ref);
        plot(t_z,v_techo);
        plot(t_z,v_suelo);
        legend("z real","z ref");
        xlabel("Time [s]");
        ylabel("Air gap [mm]");
        
    % Plotear pos Y
        [t1, y] = vectors("y.csv");
        figure
        t_y=linspace(0,length(y)/freq_y,length(y));
        plot(t_y, y)
        legend("Y position");
        xlabel("Time [s]");
        ylabel("Y-axis [mm]");

    % Plotear rotaciones
        

        [t1, rotx] = vectors("lcu_master_rot_x.csv");
        t_rot=linspace(0,length(rotx)/freq_rotaciones,length(rotx));
        rotx=rotx*1000;
        figure
        plot(t_rot, rotx)
        
        hold on
        
        [t2, roty] = vectors("lcu_master_rot_y.csv");
        roty=roty*1000;
        plot(t_rot, roty)
        
        [t3, rotz] = vectors("lcu_master_rot_z.csv");
        rotz=rotz*1000;
        plot(t_rot, rotz)
        legend("Roll","Pitch","Yaw");
        xlabel("Time [s]");
        ylabel("Angle [mrad]");

    % Plotear airgaps HEMS

        [t1, airgap1] = vectors("lcu_master_airgap_1.csv");
        t_Zhems=linspace(0,length(y)/freq_airgaps,length(airgap1));
        figure
        airgap1=-abs(airgap1-airgap1(1))+22.5;
        plot(t_Zhems, airgap1)
        hold on
                
        [t2, airgap2] = vectors("lcu_master_slave_airgap_2.csv");
        airgap2=-abs(airgap2-airgap2(1))+22.5;
        plot(t_Zhems, airgap2)
                
        [t3, airgap3] = vectors("lcu_master_airgap_3.csv");
        airgap3=-abs(airgap3-airgap3(1))+22.5;
        plot(t_Zhems, airgap3)
                
        [t4, airgap4] = vectors("lcu_master_slave_airgap_4.csv");
        airgap4=-abs(airgap4-airgap4(1))+22.5;
        plot(t_Zhems, airgap4)
        legend("Airgap HEMS 1","Airgap HEMS 2","Airgap HEMS 3","Airgap HEMS 4");
        xlabel("Time [s]");
        ylabel("Distance [mm]");

    % Plotear airgaps EMS

        [t1, airgap5] = vectors("lcu_master_airgap_5.csv");
        t_Yems=linspace(0,length(airgap5)/freq_airgaps,length(airgap5));
        figure
        airgap5=100-airgap5;
        plot(t_Yems, airgap5)
        hold on
                
        [t2, airgap6] = vectors("lcu_master_slave_airgap_6.csv");
        airgap6=100-airgap6;
        plot(t_Yems, airgap6)
                
        [t3, airgap7] = vectors("lcu_master_airgap_7.csv");
        airgap7=100-airgap7;
        plot(t_Yems, airgap7)
                
        [t4, airgap8] = vectors("lcu_master_slave_airgap_8.csv");
        airgap8=100-airgap8;
        plot(t_Yems, airgap8)
        legend("Airgap EMS 1","Airgap EMS 2","Airgap EMS 3","Airgap EMS 4");
        xlabel("Time [s]");
        ylabel("Distance [mm]");

    % Plotear corrientes HEMS

        [t1, Ihems1] = vectors("lcu_master_current_coil_hems_1.csv");
        t_Ihems=linspace(0,length(Ihems1)/freq_corrientes,length(Ihems1));
        figure
        plot(t_Ihems, Ihems1)
        
        hold on
        
        [t2, Ihems2] = vectors("lcu_master_slave_current_coil_hems_2.csv");
        plot(t_Ihems, Ihems2)
        
        hold on
        
        [t3, Ihems3] = vectors("lcu_master_current_coil_hems_3.csv");
        plot(t_Ihems, Ihems3)
        
        hold on
        
        [t4, Ihems4] = vectors("lcu_master_slave_current_coil_hems_4.csv");
        plot(t_Ihems, Ihems4)
        legend("I HEMS 1","I HEMS 2","I HEMS 3","I HEMS 4");
        xlabel("Time [s]");
        ylabel("Current [A]");

    % Plotear corrientes EMS      

        [t1, Iems1] = vectors("lcu_master_current_coil_ems_1.csv");
        t_Iems=linspace(0,length(Iems1)/freq_corrientes,length(Iems1));
        figure
        plot(t_Iems, Iems1)
        
        hold on
        
        [t2, Iems2] = vectors("lcu_master_slave_current_coil_ems_2.csv");
        plot(t_Iems, Iems2)
        
        hold on
        
        [t3, Iems3] = vectors("lcu_master_current_coil_ems_3.csv");
        plot(t_Iems, Iems3)
        
        hold on
        
        [t4, Iems4] = vectors("lcu_master_slave_current_coil_ems_4.csv");
        plot(t_Iems, Iems4)
        legend("I EMS 1","I EMS 2","I EMS 3","I EMS 4");
        xlabel("Time [s]");
        ylabel("Current [A]");
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