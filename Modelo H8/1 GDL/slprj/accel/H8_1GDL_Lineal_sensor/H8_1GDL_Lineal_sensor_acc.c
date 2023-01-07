#include "H8_1GDL_Lineal_sensor_acc.h"
#include "rtwtypes.h"
#include "H8_1GDL_Lineal_sensor_acc_private.h"
#include "multiword_types.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simtarget/slSimTgtMdlrefSfcnBridge.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T H8_1GDL_Lineal_sensor_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T *
bufSzPtr , int_T * tailPtr , int_T * headPtr , int_T * lastPtr , real_T
tMinusDelay , real_T * * uBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = *
tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf = * uBufPtr + bufSz ;
real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) {
numBuffer = 3 ; xBuf = * uBufPtr + 2 * bufSz ; } testIdx = ( tail < ( bufSz -
1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && !
isfixedbuf ) { int_T j ; real_T * tempT ; real_T * tempU ; real_T * tempX = (
NULL ) ; real_T * uBuf = * uBufPtr ; int_T newBufSz = bufSz + 1024 ; if (
newBufSz > * maxNewBufSzPtr ) { * maxNewBufSzPtr = newBufSz ; } tempU = (
real_T * ) utMalloc ( numBuffer * newBufSz * sizeof ( real_T ) ) ; if ( tempU
== ( NULL ) ) { return ( false ) ; } tempT = tempU + newBufSz ; if (
istransportdelay ) tempX = tempT + newBufSz ; for ( j = tail ; j < bufSz ; j
++ ) { tempT [ j - tail ] = tBuf [ j ] ; tempU [ j - tail ] = uBuf [ j ] ; if
( istransportdelay ) tempX [ j - tail ] = xBuf [ j ] ; } for ( j = 0 ; j <
tail ; j ++ ) { tempT [ j + bufSz - tail ] = tBuf [ j ] ; tempU [ j + bufSz -
tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j + bufSz - tail ] =
xBuf [ j ] ; } if ( * lastPtr > tail ) { * lastPtr -= tail ; } else { *
lastPtr += ( bufSz - tail ) ; } * tailPtr = 0 ; * headPtr = bufSz ; utFree (
uBuf ) ; * bufSzPtr = newBufSz ; * uBufPtr = tempU ; } else { * tailPtr =
testIdx ; } return ( true ) ; } real_T
H8_1GDL_Lineal_sensor_acc_rt_TDelayInterpolate ( real_T tMinusDelay , real_T
tStart , real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx ,
int_T newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; real_T * tBuf = uBuf + bufSz ; if ( ( newIdx == 0 ) && ( oldestIdx == 0 )
&& ( tMinusDelay > tStart ) ) return initOutput ; if ( tMinusDelay <= tStart
) return initOutput ; if ( ( tMinusDelay <= tBuf [ oldestIdx ] ) ) { if (
discrete ) { return ( uBuf [ oldestIdx ] ) ; } else { int_T tempIdx =
oldestIdx + 1 ; if ( oldestIdx == bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [
oldestIdx ] ; t2 = tBuf [ tempIdx ] ; u1 = uBuf [ oldestIdx ] ; u2 = uBuf [
tempIdx ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else {
yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } return yout ; } } if (
minorStepAndTAtLastMajorOutput ) { if ( newIdx != 0 ) { if ( * lastIdx ==
newIdx ) { ( * lastIdx ) -- ; } newIdx -- ; } else { if ( * lastIdx == newIdx
) { * lastIdx = bufSz - 1 ; } newIdx = bufSz - 1 ; } } i = * lastIdx ; if (
tBuf [ i ] < tMinusDelay ) { while ( tBuf [ i ] < tMinusDelay ) { if ( i ==
newIdx ) break ; i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } } else { while
( tBuf [ i ] >= tMinusDelay ) { i = ( i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i =
( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } * lastIdx = i ; if ( discrete ) {
double tempEps = ( DBL_EPSILON ) * 128.0 ; double localEps = tempEps *
muDoubleScalarAbs ( tBuf [ i ] ) ; if ( tempEps > localEps ) { localEps =
tempEps ; } localEps = localEps / 2.0 ; if ( tMinusDelay >= ( tBuf [ i ] -
localEps ) ) { yout = uBuf [ i ] ; } else { if ( i == 0 ) { yout = uBuf [
bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ; } } } else { if ( i == 0 ) {
t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1 ] ; } else { t1 = tBuf [ i -
1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ; u2 = uBuf [ i ] ; if ( t2 ==
t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else {
real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout
= f1 * u1 + f2 * u2 ; } } return ( yout ) ; } void rt_ssGetBlockPath (
SimStruct * S , int_T sysIdx , int_T blkIdx , char_T * * path ) {
_ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void rt_ssSet_slErrMsg (
void * S , void * diag ) { SimStruct * castedS = ( SimStruct * ) S ; if ( !
_ssIsErrorStatusAslErrMsg ( castedS ) ) { _ssSet_slErrMsg ( castedS , diag )
; } else { _ssDiscardDiagnostic ( castedS , diag ) ; } } void
rt_ssReportDiagnosticAsWarning ( void * S , void * diag ) {
_ssReportDiagnosticAsWarning ( ( SimStruct * ) S , diag ) ; } void
rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) {
_ssReportDiagnosticAsInfo ( ( SimStruct * ) S , diag ) ; } static void
mdlOutputs ( SimStruct * S , int_T tid ) { real_T B_1_34_0 ;
B_H8_1GDL_Lineal_sensor_T * _rtB ; DW_H8_1GDL_Lineal_sensor_T * _rtDW ;
P_H8_1GDL_Lineal_sensor_T * _rtP ; X_H8_1GDL_Lineal_sensor_T * _rtX ; int32_T
isHit ; boolean_T rtb_B_1_37_0 ; _rtDW = ( ( DW_H8_1GDL_Lineal_sensor_T * )
ssGetRootDWork ( S ) ) ; _rtX = ( ( X_H8_1GDL_Lineal_sensor_T * )
ssGetContStates ( S ) ) ; _rtP = ( ( P_H8_1GDL_Lineal_sensor_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_H8_1GDL_Lineal_sensor_T * )
_ssGetModelBlockIO ( S ) ) ; _rtB -> B_1_0_0 = 0.0 ; _rtB -> B_1_0_0 += _rtP
-> P_3 [ 0 ] * _rtX -> LevUnit_CSTATE [ 0 ] ; _rtB -> B_1_0_0 += _rtP -> P_3
[ 1 ] * _rtX -> LevUnit_CSTATE [ 1 ] ; _rtB -> B_1_1_0 = _rtB -> B_1_0_0 +
_rtB -> B_1_0_0_m ; _rtB -> B_1_2_0 = _rtB -> B_1_1_0 + _rtB -> B_1_1_0_c ;
ssCallAccelRunBlock ( S , 1 , 3 , SS_CALL_MDL_OUTPUTS ) ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Step2_MODE = (
ssGetTaskTime ( S , 1 ) >= _rtP -> P_5 ) ; if ( _rtDW -> Step2_MODE == 1 ) {
_rtB -> B_1_4_0 = _rtP -> P_7 ; } else { _rtB -> B_1_4_0 = _rtP -> P_6 ; }
ssCallAccelRunBlock ( S , 1 , 5 , SS_CALL_MDL_OUTPUTS ) ; }
ssCallAccelRunBlock ( S , 1 , 6 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock
( S , 1 , 7 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_1_8_0 = _rtB -> B_1_2_0 -
_rtB -> B_1_2_0_k ; _rtB -> B_1_9_0 = _rtB -> B_1_4_0 - _rtB -> B_1_8_0 ;
_rtB -> B_1_10_0 = _rtP -> P_8 * _rtB -> B_1_9_0 ; _rtB -> B_1_11_0 = _rtX ->
Integrator_CSTATE ; _rtB -> B_1_12_0 = _rtP -> P_10 * _rtB -> B_1_9_0 ; _rtB
-> B_1_13_0 = _rtX -> Filter_CSTATE ; _rtB -> B_1_14_0 = _rtB -> B_1_12_0 -
_rtB -> B_1_13_0 ; _rtB -> B_1_15_0 = _rtP -> P_12 * _rtB -> B_1_14_0 ; _rtB
-> B_1_16_0 = ( _rtB -> B_1_10_0 + _rtB -> B_1_11_0 ) + _rtB -> B_1_15_0 ; if
( ssIsModeUpdateTimeStep ( S ) ) { _rtDW -> Saturation6_MODE = _rtB ->
B_1_16_0 >= _rtP -> P_13 ? 1 : _rtB -> B_1_16_0 > _rtP -> P_14 ? 0 : - 1 ; }
_rtB -> B_1_17_0 = _rtDW -> Saturation6_MODE == 1 ? _rtP -> P_13 : _rtDW ->
Saturation6_MODE == - 1 ? _rtP -> P_14 : _rtB -> B_1_16_0 ; _rtB -> B_1_18_0
= 0.0 ; _rtB -> B_1_18_0 += _rtP -> P_16 * _rtX -> RLCircuit_CSTATE ; _rtB ->
B_1_19_0 = _rtB -> B_1_17_0 - _rtB -> B_1_18_0 ; _rtB -> B_1_20_0 = _rtP ->
P_17 * _rtB -> B_1_19_0 ; _rtB -> B_1_21_0 = _rtX -> Filter_CSTATE_i ; _rtB
-> B_1_22_0 = _rtB -> B_1_20_0 - _rtB -> B_1_21_0 ; _rtB -> B_1_23_0 = _rtP
-> P_19 * _rtB -> B_1_19_0 ; _rtB -> B_1_24_0 = _rtX -> Integrator_CSTATE_o ;
_rtB -> B_1_25_0 = _rtP -> P_21 * _rtB -> B_1_22_0 ; _rtB -> B_1_26_0 = _rtP
-> P_22 * _rtB -> B_1_19_0 ; _rtB -> B_1_27_0 = ( _rtB -> B_1_26_0 + _rtB ->
B_1_24_0 ) + _rtB -> B_1_25_0 ; _rtB -> B_1_28_0 = _rtP -> P_23 * _rtB ->
B_1_9_0 ; if ( ssIsModeUpdateTimeStep ( S ) ) { _rtDW -> Saturation1_MODE =
_rtB -> B_1_27_0 >= _rtP -> P_24 ? 1 : _rtB -> B_1_27_0 > _rtP -> P_25 ? 0 :
- 1 ; } _rtB -> B_1_29_0 = _rtDW -> Saturation1_MODE == 1 ? _rtP -> P_24 :
_rtDW -> Saturation1_MODE == - 1 ? _rtP -> P_25 : _rtB -> B_1_27_0 ; _rtB ->
B_1_30_0 = _rtX -> Integrator_CSTATE_g ; _rtB -> B_1_31_0 = _rtB -> B_1_30_0
+ _rtB -> B_1_8_0_c ; ssCallAccelRunBlock ( S , 1 , 32 , SS_CALL_MDL_OUTPUTS
) ; _rtB -> B_1_33_0 = _rtX -> integrator_CSTATE ; { real_T * * uBuffer = (
real_T * * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T
simTime = ssGetT ( S ) ; real_T tMinusDelay = simTime - _rtP -> P_28 ;
B_1_34_0 = H8_1GDL_Lineal_sensor_acc_rt_TDelayInterpolate ( tMinusDelay , 0.0
, * uBuffer , _rtDW -> TransportDelay_IWORK . CircularBufSize , & _rtDW ->
TransportDelay_IWORK . Last , _rtDW -> TransportDelay_IWORK . Tail , _rtDW ->
TransportDelay_IWORK . Head , _rtP -> P_29 , 0 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> TransportDelay_IWORK .
CircularBufSize ) [ _rtDW -> TransportDelay_IWORK . Head ] == ssGetT ( S ) )
) ) ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_1_36_0 = _rtP -> P_30 ; } rtb_B_1_37_0 = ( ssGetT ( S ) >= _rtB -> B_1_36_0
) ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtB ->
B_1_38_0 = _rtDW -> Memory_PreviousInput ; } if ( rtb_B_1_37_0 ) { _rtB ->
B_1_40_0 = ( _rtB -> B_1_33_0 - B_1_34_0 ) * _rtP -> P_0 ; } else { _rtB ->
B_1_40_0 = _rtB -> B_1_38_0 ; } ssCallAccelRunBlock ( S , 1 , 41 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 1 , 42 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 1 , 43 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 1 , 44 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_1_45_0 = _rtB -> B_1_29_0 * _rtB ->
B_1_18_0 ; ssCallAccelRunBlock ( S , 1 , 46 , SS_CALL_MDL_OUTPUTS ) ; _rtB ->
B_1_47_0 = _rtB -> B_1_18_0 / _rtB -> B_1_7_0 ; _rtB -> B_1_49_0 = _rtB ->
B_1_31_0 - _rtB -> B_1_9_0_b ; _rtB -> B_1_50_0 = _rtP -> P_32 * _rtB ->
B_1_49_0 ; _rtB -> B_1_51_0 = _rtB -> B_1_50_0 + _rtB -> B_1_3_0 ; _rtB ->
B_1_52_0 = _rtB -> B_1_10_0_p * _rtB -> B_1_51_0 ; _rtB -> B_1_53_0 = _rtB ->
B_1_47_0 * _rtB -> B_1_47_0 * _rtB -> B_1_52_0 ; _rtB -> B_1_54_0 = _rtB ->
B_1_53_0 / _rtB -> B_1_6_0 ; UNUSED_PARAMETER ( tid ) ; } static void
mdlOutputsTID2 ( SimStruct * S , int_T tid ) { B_H8_1GDL_Lineal_sensor_T *
_rtB ; P_H8_1GDL_Lineal_sensor_T * _rtP ; _rtP = ( (
P_H8_1GDL_Lineal_sensor_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_H8_1GDL_Lineal_sensor_T * ) _ssGetModelBlockIO ( S ) ) ; _rtB -> B_1_0_0_m
= _rtP -> P_33 ; _rtB -> B_1_1_0_c = _rtP -> P_34 ; _rtB -> B_1_2_0_k = _rtP
-> P_35 ; _rtB -> B_1_3_0 = _rtP -> P_36 ; _rtB -> B_1_6_0 = _rtP -> P_37 *
_rtP -> P_38 ; _rtB -> B_1_7_0 = _rtP -> P_39 ; _rtB -> B_1_8_0_c = _rtP ->
P_40 ; _rtB -> B_1_9_0_b = _rtP -> P_41 ; _rtB -> B_1_10_0_p = _rtP -> P_42 ;
UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) {
B_H8_1GDL_Lineal_sensor_T * _rtB ; DW_H8_1GDL_Lineal_sensor_T * _rtDW ;
P_H8_1GDL_Lineal_sensor_T * _rtP ; int32_T isHit ; _rtDW = ( (
DW_H8_1GDL_Lineal_sensor_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( (
P_H8_1GDL_Lineal_sensor_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_H8_1GDL_Lineal_sensor_T * ) _ssGetModelBlockIO ( S ) ) ; { real_T * *
uBuffer = ( real_T * * ) & _rtDW -> TransportDelay_PWORK . TUbufferPtrs [ 0 ]
; real_T simTime = ssGetT ( S ) ; _rtDW -> TransportDelay_IWORK . Head = ( (
_rtDW -> TransportDelay_IWORK . Head < ( _rtDW -> TransportDelay_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> TransportDelay_IWORK . Head + 1 ) : 0 )
; if ( _rtDW -> TransportDelay_IWORK . Head == _rtDW -> TransportDelay_IWORK
. Tail ) { if ( ! H8_1GDL_Lineal_sensor_acc_rt_TDelayUpdateTailOrGrowBuf ( &
_rtDW -> TransportDelay_IWORK . CircularBufSize , & _rtDW ->
TransportDelay_IWORK . Tail , & _rtDW -> TransportDelay_IWORK . Head , &
_rtDW -> TransportDelay_IWORK . Last , simTime - _rtP -> P_28 , uBuffer , (
boolean_T ) 0 , false , & _rtDW -> TransportDelay_IWORK . MaxNewBufSize ) ) {
ssSetErrorStatus ( S , "tdelay memory allocation error" ) ; return ; } } ( *
uBuffer + _rtDW -> TransportDelay_IWORK . CircularBufSize ) [ _rtDW ->
TransportDelay_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
TransportDelay_IWORK . Head ] = _rtB -> B_1_33_0 ; } isHit = ssIsSampleHit (
S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Memory_PreviousInput = _rtB ->
B_1_40_0 ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID2 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_H8_1GDL_Lineal_sensor_T *
_rtB ; P_H8_1GDL_Lineal_sensor_T * _rtP ; XDot_H8_1GDL_Lineal_sensor_T *
_rtXdot ; X_H8_1GDL_Lineal_sensor_T * _rtX ; _rtXdot = ( (
XDot_H8_1GDL_Lineal_sensor_T * ) ssGetdX ( S ) ) ; _rtX = ( (
X_H8_1GDL_Lineal_sensor_T * ) ssGetContStates ( S ) ) ; _rtP = ( (
P_H8_1GDL_Lineal_sensor_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_H8_1GDL_Lineal_sensor_T * ) _ssGetModelBlockIO ( S ) ) ; _rtXdot ->
LevUnit_CSTATE [ 0 ] = 0.0 ; _rtXdot -> LevUnit_CSTATE [ 0 ] += _rtP -> P_1 [
0 ] * _rtX -> LevUnit_CSTATE [ 0 ] ; _rtXdot -> LevUnit_CSTATE [ 0 ] += _rtX
-> LevUnit_CSTATE [ 1 ] * _rtP -> P_1 [ 2 ] ; _rtXdot -> LevUnit_CSTATE [ 0 ]
+= _rtP -> P_2 [ 0 ] * _rtB -> B_1_18_0 ; _rtXdot -> LevUnit_CSTATE [ 1 ] =
0.0 ; _rtXdot -> LevUnit_CSTATE [ 1 ] += _rtX -> LevUnit_CSTATE [ 0 ] * _rtP
-> P_1 [ 1 ] ; _rtXdot -> LevUnit_CSTATE [ 1 ] += _rtX -> LevUnit_CSTATE [ 1
] * _rtP -> P_1 [ 3 ] ; _rtXdot -> LevUnit_CSTATE [ 1 ] += _rtP -> P_2 [ 1 ]
* _rtB -> B_1_18_0 ; _rtXdot -> Integrator_CSTATE = _rtB -> B_1_28_0 ;
_rtXdot -> Filter_CSTATE = _rtB -> B_1_15_0 ; _rtXdot -> RLCircuit_CSTATE =
0.0 ; _rtXdot -> RLCircuit_CSTATE += _rtP -> P_15 * _rtX -> RLCircuit_CSTATE
; _rtXdot -> RLCircuit_CSTATE += _rtB -> B_1_29_0 ; _rtXdot ->
Filter_CSTATE_i = _rtB -> B_1_25_0 ; _rtXdot -> Integrator_CSTATE_o = _rtB ->
B_1_23_0 ; _rtXdot -> Integrator_CSTATE_g = _rtB -> B_1_54_0 ; _rtXdot ->
integrator_CSTATE = _rtB -> B_1_45_0 ; }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { B_H8_1GDL_Lineal_sensor_T *
_rtB ; P_H8_1GDL_Lineal_sensor_T * _rtP ; ZCV_H8_1GDL_Lineal_sensor_T *
_rtZCSV ; _rtZCSV = ( ( ZCV_H8_1GDL_Lineal_sensor_T * )
ssGetSolverZcSignalVector ( S ) ) ; _rtP = ( ( P_H8_1GDL_Lineal_sensor_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_H8_1GDL_Lineal_sensor_T * )
_ssGetModelBlockIO ( S ) ) ; _rtZCSV -> Step2_StepTime_ZC = ssGetT ( S ) -
_rtP -> P_5 ; _rtZCSV -> Saturation6_UprLim_ZC = _rtB -> B_1_16_0 - _rtP ->
P_13 ; _rtZCSV -> Saturation6_LwrLim_ZC = _rtB -> B_1_16_0 - _rtP -> P_14 ;
_rtZCSV -> Saturation1_UprLim_ZC = _rtB -> B_1_27_0 - _rtP -> P_24 ; _rtZCSV
-> Saturation1_LwrLim_ZC = _rtB -> B_1_27_0 - _rtP -> P_25 ; } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 3534279687U
) ; ssSetChecksumVal ( S , 1 , 1286249134U ) ; ssSetChecksumVal ( S , 2 ,
1091495090U ) ; ssSetChecksumVal ( S , 3 , 2201391960U ) ; { mxArray *
slVerStructMat = ( NULL ) ; mxArray * slStrMat = mxCreateString ( "simulink"
) ; char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat
, 1 , & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat =
mxGetField ( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == ( NULL ) ) {
status = 1 ; } else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; }
} mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "10.6" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != ( SLSize ) sizeof ( DW_H8_1GDL_Lineal_sensor_T ) ) { static char msg [
256 ] ; sprintf ( msg , "Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file (%ld vs %lu)." , ( signed long )
ssGetSizeofDWork ( S ) , ( unsigned long ) sizeof (
DW_H8_1GDL_Lineal_sensor_T ) ) ; ssSetErrorStatus ( S , msg ) ; } if (
ssGetSizeofGlobalBlockIO ( S ) != ( SLSize ) sizeof (
B_H8_1GDL_Lineal_sensor_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file (%ld vs %lu)." , ( signed long )
ssGetSizeofGlobalBlockIO ( S ) , ( unsigned long ) sizeof (
B_H8_1GDL_Lineal_sensor_T ) ) ; ssSetErrorStatus ( S , msg ) ; } { int
ssSizeofParams ; ssGetSizeofParams ( S , & ssSizeofParams ) ; if (
ssSizeofParams != sizeof ( P_H8_1GDL_Lineal_sensor_T ) ) { static char msg [
256 ] ; sprintf ( msg , "Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file (%d vs %lu)." , ssSizeofParams , (
unsigned long ) sizeof ( P_H8_1GDL_Lineal_sensor_T ) ) ; ssSetErrorStatus ( S
, msg ) ; } } _ssSetModelRtp ( S , ( real_T * ) &
H8_1GDL_Lineal_sensor_rtDefaultP ) ; } static void mdlInitializeSampleTimes (
SimStruct * S ) { slAccRegPrmChangeFcn ( S , mdlOutputsTID2 ) ; } static void
mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
