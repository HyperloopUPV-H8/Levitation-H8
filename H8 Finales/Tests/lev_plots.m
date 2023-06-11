function lev_plots(selection)
% plots tipicos y repetitivos utiles para testing

switch(selection)
    case "airgaps_vertical"
        plot_gui("lcu_master_airgap_1.csv", "lcu_master_slave_airgap_2.csv", "lcu_master_airgap_3.csv","lcu_master_slave_airgap_4.csv");
    case "rotaciones"
        plot_gui("lcu_master_rot_x.csv", "lcu_master_rot_y.csv", "lcu_master_rot_z.csv");
    case "posicion_z"
        plot_gui("z.csv","z_reference.csv");
    case "corrientes_hems"
         plot_gui("lcu_master_current_coil_hems_1.csv", "lcu_master_slave_current_coil_hems_2.csv", "lcu_master_current_coil_hems_3.csv","lcu_master_slave_current_coil_hems_4.csv");
    otherwise
        disp("Opciones disponibles: airgaps_vertical, rotaciones, posicion_z, corrientes_hems");
end

end

function [t1, v1, v2, v3] = plot_gui(csvfile1, csvfile2, csvfile3,csvfile4)

switch nargin
    case 1
        [t1, v1] = vectors(csvfile1);
		figure
        plot(t1, v1)
        legend(csvfile1)
    case 2
        [t1, v1] = vectors(csvfile1);
		figure
        plot(t1, v1)
        
        hold on
        
        [t2, v2] = vectors(csvfile2);
        plot(t2, v2)
        legend(csvfile1,csvfile2)
    case 3
        [t1, v1] = vectors(csvfile1);
		figure
        plot(t1, v1)
        
        hold on
        
        [t2, v2] = vectors(csvfile2);
        plot(t2, v2)

        hold on

        [t3, v3] = vectors(csvfile3);
        plot(t3, v3)
        legend(csvfile1,csvfile2,csvfile3)
     
    case 4
        [t1, v1] = vectors(csvfile1);
		figure
        plot(t1, v1)
        
        hold on
        
        [t2, v2] = vectors(csvfile2);
        plot(t2, v2)

        hold on

        [t3, v3] = vectors(csvfile3);
        plot(t3, v3)

        hold on

        [t4, v4] = vectors(csvfile4);
        plot(t4, v4)
        legend(csvfile1,csvfile2,csvfile3,csvfile4)
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
