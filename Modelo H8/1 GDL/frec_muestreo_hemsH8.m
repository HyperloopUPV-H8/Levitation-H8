%Teorema de Nyquist
%T oscilac controlador sistema 1gdl lineal con ruido - 0.1925 s
%f=1/T
Tc=0.1925;
fc=1/Tc;
fs_c=2*fc; %fs>2f, añadimos factor de seguridad de 1.075
fss_c=1.075*fs_c
wss_c=2*pi*fss_c;

%T max respuesta sensor - 0.001 s
Tsen=0.001;
fsen=1/Tsen;
fs_sen=2*fsen;
fss_sen=1.075*fs_sen
wss_sen=2*pi*fss_sen;
