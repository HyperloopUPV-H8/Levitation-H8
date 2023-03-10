%% Variables vibrational

load('datos_vibrational.mat');

Sys_hems = ss(A3,B3,C3,D3);
Sys_ems = ss(A1,B1,C1,D1);

Ghems = tf(Sys_hems);
%bodeplot(Ghems)

Gems = tf(Sys_ems);
%bodeplot(Gems)

%% Ejemplo EDU

s = tf('s');
​
Ghems = 1e9/(s^2+2000*s+1e7);
Ghems2 = 1e9/(s^3+2000*s+1e7);
​
opts = bodeoptions;
opts.FreqScale = 'log';
opts.FreqUnits = 'Hz';
opts.MagUnits = 'dB';
opts.Title.String = 'Frequency Response';
opts.XLabel.String = 'Frequency';
%opts.YLabel.String = 'Magnitude'; %este no le gusta no se porque
opts.PhaseVisible = 'off';
opts.Grid = 'on';
opts.InputLabels.FontSize = 20;
​
hems11 = bodeplot(Ghems,'Color',[0.93 0.46 0.14]); %hems 1 a z
setoptions(hems11,opts)
hold on
hems12 = bodeplot(Ghems2,'k');
setoptions(hems12,opts)
legend({'Ghems','Ghems2'})

%% Plot options

opts = bodeoptions;
opts.FreqScale = 'log';
opts.FreqUnits = 'Hz';
opts.MagUnits = 'dB';
opts.Title.String = 'Frequency Response';
opts.XLabel.String = 'Frequency';
opts.YLabel.String = 'Magnitude';
opts.PhaseVisible = 'off';
opts.Grid = 'on';
colors = ["#EE7623", "k", "#003B4D", "#8F8FA3", "#7398AD", "#C1C5C8"];

%% HEMS Opcion 1 graficas (sale mal la leyenda)

hems11 = bodeplot(Ghems(1,1),'b'); %hems 1 a z
lineHandle = findobj(gcf,'Type','line','-and','Color','b');
set(lineHandle,'Color',colors(1));
% h_axes = findobj(gcf,'Type','Axes');
% h_lines(1) = findobj(h_axes,'Type','line')
hold on

hems21 = bodeplot(Ghems(2,1),'b'); %hems 1 a dz
lineHandle = findobj(gcf,'Type','line','-and','Color','b');
set(lineHandle,'Color',colors(2));
% h_axes = findobj(gcf,'Type','Axes');
% h_lines(2) = findobj(h_axes,'Type','line')
hold on

hems31 = bodeplot(Ghems(3,1),'b'); %hems 1 a rotX
lineHandle = findobj(gcf,'Type','line','-and','Color','b');
set(lineHandle,'Color',colors(3));
% h_axes = findobj(gcf,'Type','Axes');
% h_lines(3) = findobj(h_axes,'Type','line')
hold on

hems41 = bodeplot(Ghems(4,1),'b'); %hems 1 a drotX
lineHandle = findobj(gcf,'Type','line','-and','Color','b');
set(lineHandle,'Color',colors(4));
% h_axes = findobj(gcf,'Type','Axes');
% h_lines(4) = findobj(h_axes,'Type','line')
hold on

hems51 = bodeplot(Ghems(5,1),'b'); %hems 1 a rotY
lineHandle = findobj(gcf,'Type','line','-and','Color','b');
set(lineHandle,'Color',colors(5));
% h_axes = findobj(gcf,'Type','Axes');
% h_lines(5) = findobj(h_axes,'Type','line')
hold on

hems61 = bodeplot(Ghems(6,1),'b'); %hems 1 a drotY
lineHandle = findobj(gcf,'Type','line','-and','Color','b');
set(lineHandle,'Color',colors(6));
% h_axes = findobj(gcf,'Type','Axes');
% h_lines(6) = findobj(h_axes,'Type','line')
hold on

colororder([0.93 0.46 0.14; 0 0 0; 0 0.23 0.3; 0.56 0.56 0.64; 0.45 0.6 0.68; 0.76 0.77 0.78])

names = {'Z-position','Z-position derivative','X-rotation','X-rotation derivative','Y-rotation','Y-rotation derivative'};

setoptions(hems11,opts);
legend(names)

%% Opcion 2 graficas (no coge el colororder)

fig = figure(1);

hems11 = bodeplot(Ghems(1,1)); %hems 1 a z
hold on

hems21 = bodeplot(Ghems(2,1)); %hems 1 a dz
hold on

hems31 = bodeplot(Ghems(3,1)); %hems 1 a rotX
hold on

hems41 = bodeplot(Ghems(4,1)); %hems 1 a drotX
hold on

hems51 = bodeplot(Ghems(5,1)); %hems 1 a rotY
hold on

hems61 = bodeplot(Ghems(6,1)); %hems 1 a drotY

setoptions(hems11,opts);

legend('Z-position','Z-position derivative','X-rotation','X-rotation derivative','Y-rotation','Y-rotation derivative')

NameArray = {'Color'};
colors_Tripplets = {'[0.93, 0.46, 0.14]'; '[0, 0, 0]'; '[0, 0.23, 0.3]'; '[0.56, 0.56, 0.64]'; '[0.45, 0.6, 0.68]'; '[0.76, 0.77, 0.78]'};
set(fig,NameArray,colors_Tripplets)

%% EMS

figure
ems11 = bodeplot(Gems(1,1),'b'); %ems 1 pos y
lineHandle = findobj(gcf,'Type','line','-and','Color','b');
set(lineHandle,'Color',colors(1));
% h_axes = findobj(gcf,'Type','Axes');
% h_lines(1) = findobj(h_axes,'Type','line')
hold on

ems21 = bodeplot(Gems(2,1),'b'); %ems 1 a dposy
lineHandle = findobj(gcf,'Type','line','-and','Color','b');
set(lineHandle,'Color',colors(2));
% h_axes = findobj(gcf,'Type','Axes');
% h_lines(2) = findobj(h_axes,'Type','line')
hold on

ems31 = bodeplot(Gems(3,1),'b'); %ems 1 a rotZ
lineHandle = findobj(gcf,'Type','line','-and','Color','b');
set(lineHandle,'Color',colors(3));
% h_axes = findobj(gcf,'Type','Axes');
% h_lines(3) = findobj(h_axes,'Type','line')
hold on

ems41 = bodeplot(Gems(4,1),'b'); %hems 1 a drotZ
lineHandle = findobj(gcf,'Type','line','-and','Color','b');
set(lineHandle,'Color',colors(4));
% h_axes = findobj(gcf,'Type','Axes');
% h_lines(4) = findobj(h_axes,'Type','line')
hold on

colororder([0.93 0.46 0.14; 0 0 0; 0 0.23 0.3; 0.56 0.56 0.64; 0.45 0.6 0.68; 0.76 0.77 0.78])

names = {'Y-position','Y-position derivative','Z-rotation','Z-rotation derivative'};

setoptions(ems11,opts);
legend(names)