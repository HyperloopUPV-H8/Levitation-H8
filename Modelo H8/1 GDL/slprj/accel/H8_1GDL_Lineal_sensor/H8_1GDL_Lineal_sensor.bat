@echo off
set MATLAB=C:\Program Files\MATLAB\R2022b
"%MATLAB%\bin\win64\gmake" -f H8_1GDL_Lineal_sensor.mk  OPTS="-DTID01EQ=0"
