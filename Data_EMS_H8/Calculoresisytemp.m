ResistenciaInicial=0.894;
CoeficienteTemperatura=0.0039;
TemperaturaEntrada=40;
Intensidad=30;
CoeficienteTransferencia=380;
MasaBobina=1.03;
Nvueltas=226;
longitudVuelta=0.33;
Tiempo=1;
Potencia=ResistenciaInicial*2*(Intensidad)^2;
TemperaturaSalida=TemperaturaEntrada+((Potencia*Tiempo)/(MasaBobina*CoeficienteTransferencia))
ResistenciaSalida=ResistenciaInicial*(1+(CoeficienteTemperatura*(TemperaturaSalida-TemperaturaEntrada)))