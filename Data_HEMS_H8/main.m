% ╔═══════════════════════════════════════════════════════════════════════╗
% ║───────────────╔╗─╔╗───────────╔╗──────────╔╗─╔╦═══╦╗──╔╗──────────────║
% ║───────────────║║─║║───────────║║──────────║║─║║╔═╗║╚╗╔╝║──────────────║
% ║───────────────║╚═╝╠╗─╔╦══╦══╦═╣║╔══╦══╦══╗║║─║║╚═╝╠╗║║╔╝──────────────║
% ║───────────────║╔═╗║║─║║╔╗║║═╣╔╣║║╔╗║╔╗║╔╗║║║─║║╔══╝║╚╝║───────────────║
% ║───────────────║║─║║╚═╝║╚╝║║═╣║║╚╣╚╝║╚╝║╚╝║║╚═╝║║───╚╗╔╝───────────────║
% ║───────────────╚╝─╚╩═╗╔╣╔═╩══╩╝╚═╩══╩══╣╔═╝╚═══╩╝────╚╝────────────────║
% ║───────────────────╔═╝║║║──────────────║║──────────────────────────────║
% ║───────────────────╚══╝╚╝──────────────╚╝──────────────────────────────║
% ╚═══════════════════════════════════════════════════════════════════════╝
%% Script initialization
clear
clc
close all

%cd C:\FERRAN\2_Hyperloop_2022\1_dynamics_H7\3_Estudio_Inductancia
addpath('plots')
addpath('lib')

% % H7
% load("data.mat")
% 
% air_gap         = r.air_gap;
% current         = r.current;
% force           = r.force;
% magnetic_flux   = r.magnetic_flux;
% 
% [AG_map, I_map] = meshgrid(air_gap, current);
% 
% plotMF(AG_map, I_map, magnetic_flux)

% H8
load("hems.mat")

air_gap         = hems.Airgap;
current         = hems.Current';
force           = hems.Force_Vertical;
magnetic_flux   = hems.Flux';

[I_map, AG_map] = meshgrid(current, air_gap);

%plotMF(AG_map, I_map, magnetic_flux)
surf(I_map, AG_map, magnetic_flux)

%% Discretization 

% H7
L = zeros((length(current)-2), length(air_gap));        % Inductance [H]

for AG_i = 1:length(air_gap)
    L(:, AG_i) = FDM(magnetic_flux(AG_i, :), current);  
end

[AG_reduced_map, I_reduced_map] = meshgrid(air_gap, current(2:(end-1)));

% plotL(AG_reduced_map, I_reduced_map, L)
surf(AG_reduced_map, I_reduced_map, L)

% % H8
% L = zeros((length(current)-2), length(air_gap));        % Inductance [H]
% 
% for AG_i = 1:(length(air_gap))
%     L(:,AG_i) = FDM(magnetic_flux(AG_i, :), current); 
% end
% 
% [I_reduced_map, AG_reduced_map] = meshgrid(current(2:(end-1)),air_gap);
% 
% % plotL(AG_reduced_map, I_reduced_map, L)
% surf(I_reduced_map, AG_reduced_map, L)

%% Data collection - Lookup table

hems.inductance              = L;
save("hems.mat", "hems")
