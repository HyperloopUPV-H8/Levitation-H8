%load("hems.mat");
format long;
for i = 185:5:200

        m = i;
        m_1gdl = m/4;
        index=find(hems.Current == 0);
        p = polyfit(hems.Force_Vertical(:,index), hems.Airgap', 5);
        lev_nom = polyval(p,m_1gdl*9.81)/1000;
        sim("H8_1GDL_barridomasa.slx");

end
