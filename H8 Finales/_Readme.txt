Nombre del documento | Descripción

airgap2pos | algoritmo que convierte el airgap de los sensores en la posición del pod.

boggieDynamics | modelo que toma como entrada las fuerzas en las unidades y el motor y computa el movimiento del pod.

H8_6GDL_nolineal | modelo completo y final para el control del pod.
Model_Ems | modelo del EMS que toma el airgap, la corriente y la temperatura para el calculo de las fuerzas y el incremento de temperatura.

Model_Hems | modelo del HEMS que toma el airgap, la corriente y la temperatura para el calculo de las fuerzas y el incremento de temperatura.

PI_ems | control PI para la bobina del EMS.

PI_hems | control PI para la bobina del HEMS.

pos2airgap | algoritmo que convierte la posición real del pod en el airgap que verían los sensores.

pos2airgapUNITS | algoritmo que convierte la posición real del pod en el airgap que verían las unidades EMS y HEMS.

RL_circuit | circuito resistencia-inductancia de las bobinas

state_space_model | modelo en función de estados para el calculo entre matrices