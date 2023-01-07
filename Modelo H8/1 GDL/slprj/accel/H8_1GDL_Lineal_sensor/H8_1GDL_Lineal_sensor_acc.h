#ifndef RTW_HEADER_H8_1GDL_Lineal_sensor_acc_h_
#define RTW_HEADER_H8_1GDL_Lineal_sensor_acc_h_
#ifndef H8_1GDL_Lineal_sensor_acc_COMMON_INCLUDES_
#define H8_1GDL_Lineal_sensor_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn
#define S_FUNCTION_LEVEL 2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "H8_1GDL_Lineal_sensor_acc_types.h"
#include <stddef.h>
#include <float.h>
#include "mwmathutil.h"
#include "rt_defines.h"
typedef struct { real_T B_1_0_0 ; real_T B_1_1_0 ; real_T B_1_2_0 ; real_T
B_1_4_0 ; real_T B_1_8_0 ; real_T B_1_9_0 ; real_T B_1_10_0 ; real_T B_1_11_0
; real_T B_1_12_0 ; real_T B_1_13_0 ; real_T B_1_14_0 ; real_T B_1_15_0 ;
real_T B_1_16_0 ; real_T B_1_17_0 ; real_T B_1_18_0 ; real_T B_1_19_0 ;
real_T B_1_20_0 ; real_T B_1_21_0 ; real_T B_1_22_0 ; real_T B_1_23_0 ;
real_T B_1_24_0 ; real_T B_1_25_0 ; real_T B_1_26_0 ; real_T B_1_27_0 ;
real_T B_1_28_0 ; real_T B_1_29_0 ; real_T B_1_30_0 ; real_T B_1_31_0 ;
real_T B_1_33_0 ; real_T B_1_36_0 ; real_T B_1_38_0 ; real_T B_1_40_0 ;
real_T B_1_45_0 ; real_T B_1_47_0 ; real_T B_1_49_0 ; real_T B_1_50_0 ;
real_T B_1_51_0 ; real_T B_1_52_0 ; real_T B_1_53_0 ; real_T B_1_54_0 ;
real_T B_1_0_0_m ; real_T B_1_1_0_c ; real_T B_1_2_0_k ; real_T B_1_3_0 ;
real_T B_1_6_0 ; real_T B_1_7_0 ; real_T B_1_8_0_c ; real_T B_1_9_0_b ;
real_T B_1_10_0_p ; } B_H8_1GDL_Lineal_sensor_T ; typedef struct { real_T
Memory_PreviousInput ; struct { real_T modelTStart ; } TransportDelay_RWORK ;
void * AirgapMeasures_PWORK [ 2 ] ; void * Scope1_PWORK ; void * Scope2_PWORK
; void * Scope3_PWORK ; struct { void * TUbufferPtrs [ 2 ] ; }
TransportDelay_PWORK ; void * Scope_PWORK ; void * Scope4_PWORK ; void *
Scope5_PWORK ; int32_T TmpAtomicSubsysAtSwitchInport1_sysIdxToRun ; struct {
int_T Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T
MaxNewBufSize ; } TransportDelay_IWORK ; int_T Step2_MODE ; int_T
Saturation6_MODE ; int_T Saturation1_MODE ; char_T pad_Saturation1_MODE [ 4 ]
; } DW_H8_1GDL_Lineal_sensor_T ; typedef struct { real_T LevUnit_CSTATE [ 2 ]
; real_T Integrator_CSTATE ; real_T Filter_CSTATE ; real_T RLCircuit_CSTATE ;
real_T Filter_CSTATE_i ; real_T Integrator_CSTATE_o ; real_T
Integrator_CSTATE_g ; real_T integrator_CSTATE ; } X_H8_1GDL_Lineal_sensor_T
; typedef struct { real_T LevUnit_CSTATE [ 2 ] ; real_T Integrator_CSTATE ;
real_T Filter_CSTATE ; real_T RLCircuit_CSTATE ; real_T Filter_CSTATE_i ;
real_T Integrator_CSTATE_o ; real_T Integrator_CSTATE_g ; real_T
integrator_CSTATE ; } XDot_H8_1GDL_Lineal_sensor_T ; typedef struct {
boolean_T LevUnit_CSTATE [ 2 ] ; boolean_T Integrator_CSTATE ; boolean_T
Filter_CSTATE ; boolean_T RLCircuit_CSTATE ; boolean_T Filter_CSTATE_i ;
boolean_T Integrator_CSTATE_o ; boolean_T Integrator_CSTATE_g ; boolean_T
integrator_CSTATE ; } XDis_H8_1GDL_Lineal_sensor_T ; typedef struct { real_T
LevUnit_CSTATE [ 2 ] ; real_T Integrator_CSTATE ; real_T Filter_CSTATE ;
real_T RLCircuit_CSTATE ; real_T Filter_CSTATE_i ; real_T Integrator_CSTATE_o
; real_T Integrator_CSTATE_g ; real_T integrator_CSTATE ; }
CStateAbsTol_H8_1GDL_Lineal_sensor_T ; typedef struct { real_T LevUnit_CSTATE
[ 2 ] ; real_T Integrator_CSTATE ; real_T Filter_CSTATE ; real_T
RLCircuit_CSTATE ; real_T Filter_CSTATE_i ; real_T Integrator_CSTATE_o ;
real_T Integrator_CSTATE_g ; real_T integrator_CSTATE ; }
CXPtMin_H8_1GDL_Lineal_sensor_T ; typedef struct { real_T LevUnit_CSTATE [ 2
] ; real_T Integrator_CSTATE ; real_T Filter_CSTATE ; real_T RLCircuit_CSTATE
; real_T Filter_CSTATE_i ; real_T Integrator_CSTATE_o ; real_T
Integrator_CSTATE_g ; real_T integrator_CSTATE ; }
CXPtMax_H8_1GDL_Lineal_sensor_T ; typedef struct { real_T Step2_StepTime_ZC ;
real_T Saturation6_UprLim_ZC ; real_T Saturation6_LwrLim_ZC ; real_T
Saturation1_UprLim_ZC ; real_T Saturation1_LwrLim_ZC ; }
ZCV_H8_1GDL_Lineal_sensor_T ; typedef struct { ZCSigState Step2_StepTime_ZCE
; ZCSigState Saturation6_UprLim_ZCE ; ZCSigState Saturation6_LwrLim_ZCE ;
ZCSigState Saturation1_UprLim_ZCE ; ZCSigState Saturation1_LwrLim_ZCE ; }
PrevZCX_H8_1GDL_Lineal_sensor_T ; struct P_H8_1GDL_Lineal_sensor_T_ { real_T
P_0 ; real_T P_1 [ 4 ] ; real_T P_2 [ 2 ] ; real_T P_3 [ 2 ] ; real_T P_4 ;
real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ; real_T P_9 ; real_T P_10
; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T P_14 ; real_T P_15 ;
real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ; real_T
P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T P_25 ; real_T P_26 ;
real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T P_30 ; real_T P_31 ; real_T
P_32 ; real_T P_33 ; real_T P_34 ; real_T P_35 ; real_T P_36 ; real_T P_37 ;
real_T P_38 ; real_T P_39 ; real_T P_40 ; real_T P_41 ; real_T P_42 ; } ;
extern P_H8_1GDL_Lineal_sensor_T H8_1GDL_Lineal_sensor_rtDefaultP ;
#endif
