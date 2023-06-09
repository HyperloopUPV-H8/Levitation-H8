
format long;
load('hems.mat')
alturas = [];
dist_nom = 0.595163669779659;
masa = 150:1:200;
for i = 150:1:200

        m_1gdl = i/4;
        index=find(hems.Current == 0);
        p = polyfit(hems.Force_Vertical(:,index), hems.Airgap', 5);
        lev_nom = polyval(p,m_1gdl*9.81)/1000;
        alturas = horzcat(alturas,lev_nom+dist_nom);
        %sim("H8_1GDL_barridomasa.slx");

end
