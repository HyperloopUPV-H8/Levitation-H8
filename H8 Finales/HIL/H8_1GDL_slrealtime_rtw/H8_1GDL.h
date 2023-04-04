/*
 * H8_1GDL.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "H8_1GDL".
 *
 * Model version              : 1.67
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C++ source code generated on : Tue Apr  4 14:32:46 2023
 *
 * Target selection: slrealtime.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_H8_1GDL_h_
#define RTW_HEADER_H8_1GDL_h_
#include <logsrv.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "verify/verifyIntrf.h"
#include "H8_1GDL_types.h"
#include <cstring>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmCounterLimit
#define rtmCounterLimit(rtm, idx)      ((rtm)->Timing.TaskCounters.cLimit[(idx)])
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
struct B_H8_1GDL_T {
  real_T Integrator;                   /* '<S108>/Integrator' */
  real_T Sum;                          /* '<S108>/Sum' */
  real_T x;                            /* '<Root>/Integrator5' */
  real_T suelotecho;                   /* '<Root>/suelo-techo' */
  real_T zaxisposition;                /* '<Root>/Sum2' */
  real_T Fg;                           /* '<Root>/Gain2' */
  real_T airgap;                       /* '<S4>/To mm' */
  real_T currentapplied;               /* '<S109>/Integrator1' */
  real_T I;                            /* '<S4>/Saturation8' */
  real_T Fl;                           /* '<S4>/2-D Lookup Table' */
  real_T F;                            /* '<Root>/Add4' */
  real_T TmpRTBAtAdd5Inport1;          /* '<Root>/Saturation6' */
  real_T Add5;                         /* '<Root>/Add5' */
  real_T airgap_sensorI;               /* '<S1>/Discr_Ampl' */
  real_T Divide2;                      /* '<Root>/Divide2' */
  real_T v;                            /* '<Root>/Integrator4' */
  real_T DerivativeGain;               /* '<S83>/Derivative Gain' */
  real_T Passthroughfortuning;         /* '<S84>/Passthrough for tuning' */
  real_T Tsamp;                        /* '<S86>/Tsamp' */
  real_T SumDen;                       /* '<S84>/SumDen' */
  real_T Reciprocal;                   /* '<S84>/Reciprocal' */
  real_T SumNum;                       /* '<S84>/SumNum' */
  real_T Divide;                       /* '<S84>/Divide' */
  real_T TmpSignalConversionAtFilterDiff[2];
  real_T FilterDifferentiatorTF;       /* '<S84>/Filter Differentiator TF' */
  real_T DenCoefOut;                   /* '<S84>/DenCoefOut' */
  real_T IntegralGain;                 /* '<S88>/Integral Gain' */
  real_T Integrator_c;                 /* '<S91>/Integrator' */
  real_T FilterCoefficient;            /* '<S94>/Filter Coefficient' */
  real_T ProportionalGain;             /* '<S96>/Proportional Gain' */
  real_T Sum_f;                        /* '<S100>/Sum' */
  real_T vs;                           /* '<Root>/Saturation1' */
  real_T Fl_m;                         /* '<S4>/2-D Lookup Table1' */
  real_T Divide_p;                     /* '<S108>/Divide' */
  real_T MathFunction;                 /* '<S108>/Math Function' */
  real_T Sum1;                         /* '<S108>/Sum1' */
  real_T masa_bobina;                  /* '<S108>/masa_bobina' */
  real_T Sum2;                         /* '<S108>/Sum2' */
  real_T Product1;                     /* '<S108>/Product1' */
  real_T Product;                      /* '<S108>/Product' */
  real_T Product2;                     /* '<S108>/Product2' */
  real_T Divide1;                      /* '<S108>/Divide1' */
  real_T Delay;                        /* '<S109>/Delay' */
  real_T Delay1;                       /* '<S109>/Delay1' */
  real_T L;                            /* '<S109>/2-D Lookup Table' */
  real_T current;                      /* '<S109>/Divide1' */
  real_T Add;                          /* '<S109>/Add' */
  real_T Delay2;                       /* '<S109>/Delay2' */
  real_T Delay3;                       /* '<S109>/Delay3' */
  real_T Divide2_h;                    /* '<S109>/Divide2' */
  real_T Divide_f;                     /* '<S109>/Divide' */
  real_T TmpRTBAtSum1Outport1;         /* '<Root>/Sum1' */
  real_T DerivativeGain_a;             /* '<S33>/Derivative Gain' */
  real_T Passthroughfortuning_f;       /* '<S34>/Passthrough for tuning' */
  real_T Tsamp_e;                      /* '<S36>/Tsamp' */
  real_T SumDen_k;                     /* '<S34>/SumDen' */
  real_T Reciprocal_n;                 /* '<S34>/Reciprocal' */
  real_T SumNum_h;                     /* '<S34>/SumNum' */
  real_T Divide_g;                     /* '<S34>/Divide' */
  real_T TmpSignalConversionAtFilterDi_n[2];
  real_T FilterDifferentiatorTF_a;     /* '<S34>/Filter Differentiator TF' */
  real_T DenCoefOut_a;                 /* '<S34>/DenCoefOut' */
  real_T IntegralGain_e;               /* '<S38>/Integral Gain' */
  real_T Integrator_n;                 /* '<S41>/Integrator' */
  real_T FilterCoefficient_a;          /* '<S44>/Filter Coefficient' */
  real_T ProportionalGain_g;           /* '<S46>/Proportional Gain' */
  real_T Sum_e;                        /* '<S50>/Sum' */
  real_T Saturation6;                  /* '<Root>/Saturation6' */
  real_T TmpRTBAtZeroOrderHoldInport1;
  real_T ZeroOrderHold;                /* '<S1>/Zero-Order Hold' */
  real_T Delay_j;                      /* '<S6>/Delay' */
  real_T Sum_p;                        /* '<S6>/Sum' */
  real_T Delay1_n;                     /* '<S6>/Delay1' */
  real_T Sum1_a;                       /* '<S6>/Sum1' */
  real_T Gain;                         /* '<S6>/Gain' */
  real_T Sum3;                         /* '<Root>/Sum3' */
  real_T Sum1_e;                       /* '<Root>/Sum1' */
  real_T senal_discretizada;           /* '<S5>/MATLAB Function1' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_H8_1GDL_T {
  real_T FilterDifferentiatorTF_states;/* '<S84>/Filter Differentiator TF' */
  real_T Integrator_DSTATE;            /* '<S91>/Integrator' */
  real_T Delay_DSTATE;                 /* '<S109>/Delay' */
  real_T Delay1_DSTATE;                /* '<S109>/Delay1' */
  real_T Delay2_DSTATE;                /* '<S109>/Delay2' */
  real_T Delay3_DSTATE;                /* '<S109>/Delay3' */
  real_T FilterDifferentiatorTF_states_h;/* '<S34>/Filter Differentiator TF' */
  real_T Integrator_DSTATE_i;          /* '<S41>/Integrator' */
  real_T Delay_DSTATE_f[6];            /* '<S6>/Delay' */
  real_T Delay1_DSTATE_j;              /* '<S6>/Delay1' */
  real_T TmpRTBAtAdd5Inport1_Buf[2];   /* synthesized block */
  real_T senal_discretizada_Buf[2];    /* synthesized block */
  real_T TmpRTBAtZeroOrderHoldInport1_Bu[2];/* synthesized block */
  real_T FilterDifferentiatorTF_tmp;   /* '<S84>/Filter Differentiator TF' */
  real_T TmpRTBAtSum1Outport1_Buf[2];  /* synthesized block */
  real_T FilterDifferentiatorTF_tmp_e; /* '<S34>/Filter Differentiator TF' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Sum2_;   /* synthesized block */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK_f;                    /* '<S1>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_n;                     /* '<S4>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<S1>/Scope2' */

  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Discr;   /* synthesized block */

  int8_T TmpRTBAtAdd5Inport1_RdBufIdx; /* synthesized block */
  int8_T TmpRTBAtAdd5Inport1_WrBufIdx; /* synthesized block */
  int8_T senal_discretizada_RdBufIdx;  /* synthesized block */
  int8_T senal_discretizada_WrBufIdx;  /* synthesized block */
  int8_T TmpRTBAtZeroOrderHoldInport1_Rd;/* synthesized block */
  int8_T TmpRTBAtZeroOrderHoldInport1_Wr;/* synthesized block */
  int8_T TmpRTBAtSum1Outport1_RdBufIdx;/* synthesized block */
  int8_T TmpRTBAtSum1Outport1_WrBufIdx;/* synthesized block */
};

/* Continuous states (default storage) */
struct X_H8_1GDL_T {
  real_T Integrator_CSTATE;            /* '<S108>/Integrator' */
  real_T Integrator5_CSTATE;           /* '<Root>/Integrator5' */
  real_T Integrator1_CSTATE;           /* '<S109>/Integrator1' */
  real_T Integrator4_CSTATE;           /* '<Root>/Integrator4' */
};

/* State derivatives (default storage) */
struct XDot_H8_1GDL_T {
  real_T Integrator_CSTATE;            /* '<S108>/Integrator' */
  real_T Integrator5_CSTATE;           /* '<Root>/Integrator5' */
  real_T Integrator1_CSTATE;           /* '<S109>/Integrator1' */
  real_T Integrator4_CSTATE;           /* '<Root>/Integrator4' */
};

/* State disabled  */
struct XDis_H8_1GDL_T {
  boolean_T Integrator_CSTATE;         /* '<S108>/Integrator' */
  boolean_T Integrator5_CSTATE;        /* '<Root>/Integrator5' */
  boolean_T Integrator1_CSTATE;        /* '<S109>/Integrator1' */
  boolean_T Integrator4_CSTATE;        /* '<Root>/Integrator4' */
};

#ifndef ODE4_INTG
#define ODE4_INTG

/* ODE4 Integration Data */
struct ODE4_IntgData {
  real_T *y;                           /* output */
  real_T *f[4];                        /* derivatives */
};

#endif

/* Constant parameters (default storage) */
struct ConstP_H8_1GDL_T {
  /* Expression: hems.Current(2:110)
   * Referenced by: '<S109>/2-D Lookup Table'
   */
  real_T uDLookupTable_rtw_collapsed_sub[109];
};

/* Parameters (default storage) */
struct P_H8_1GDL_T_ {
  struct_66wI9m9XKOeh3OoPuAXQCF hems;  /* Variable: hems
                                        * Referenced by:
                                        *   '<S4>/2-D Lookup Table'
                                        *   '<S4>/2-D Lookup Table1'
                                        *   '<S108>/masa_bobina'
                                        *   '<S109>/2-D Lookup Table'
                                        *   '<S110>/Resistance'
                                        */
  real_T g;                            /* Variable: g
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T lev_nom;                      /* Variable: lev_nom
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T m;                            /* Variable: m
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T suelo;                        /* Variable: suelo
                                        * Referenced by:
                                        *   '<Root>/Integrator5'
                                        *   '<Root>/suelo-techo'
                                        *   '<S41>/Integrator'
                                        */
  real_T techo;                        /* Variable: techo
                                        * Referenced by: '<Root>/suelo-techo'
                                        */
  real_T PIDController4_D;             /* Mask Parameter: PIDController4_D
                                        * Referenced by: '<S83>/Derivative Gain'
                                        */
  real_T PIDController3_D;             /* Mask Parameter: PIDController3_D
                                        * Referenced by: '<S33>/Derivative Gain'
                                        */
  real_T PIDController4_I;             /* Mask Parameter: PIDController4_I
                                        * Referenced by: '<S88>/Integral Gain'
                                        */
  real_T PIDController3_I;             /* Mask Parameter: PIDController3_I
                                        * Referenced by: '<S38>/Integral Gain'
                                        */
  real_T PIDController4_InitialCondition;
                              /* Mask Parameter: PIDController4_InitialCondition
                               * Referenced by: '<S84>/Filter Differentiator TF'
                               */
  real_T PIDController3_InitialCondition;
                              /* Mask Parameter: PIDController3_InitialCondition
                               * Referenced by: '<S34>/Filter Differentiator TF'
                               */
  real_T PIDController4_InitialConditi_d;
                              /* Mask Parameter: PIDController4_InitialConditi_d
                               * Referenced by: '<S91>/Integrator'
                               */
  real_T MovingAverageFilter_M;        /* Mask Parameter: MovingAverageFilter_M
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Discr_Ampl_Max;               /* Mask Parameter: Discr_Ampl_Max
                                        * Referenced by: '<S5>/Constant1'
                                        */
  real_T Discr_Ampl_Min;               /* Mask Parameter: Discr_Ampl_Min
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T PIDController4_N;             /* Mask Parameter: PIDController4_N
                                        * Referenced by:
                                        *   '<S93>/N Copy'
                                        *   '<S94>/Filter Coefficient'
                                        */
  real_T PIDController3_N;             /* Mask Parameter: PIDController3_N
                                        * Referenced by:
                                        *   '<S43>/N Copy'
                                        *   '<S44>/Filter Coefficient'
                                        */
  real_T Discr_Ampl_N;                 /* Mask Parameter: Discr_Ampl_N
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T PIDController4_P;             /* Mask Parameter: PIDController4_P
                                        * Referenced by: '<S96>/Proportional Gain'
                                        */
  real_T PIDController3_P;             /* Mask Parameter: PIDController3_P
                                        * Referenced by: '<S46>/Proportional Gain'
                                        */
  real_T FilterDenConstant_Value;      /* Expression: 1
                                        * Referenced by: '<S34>/Filter Den Constant'
                                        */
  real_T FilterDenConstant_Value_n;    /* Expression: 1
                                        * Referenced by: '<S84>/Filter Den Constant'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S108>/Integrator'
                                        */
  real_T Tamb_Value;                   /* Expression: 40
                                        * Referenced by: '<S108>/Tamb'
                                        */
  real_T dist_sensor1_Value;           /* Expression: 0.07
                                        * Referenced by: '<Root>/dist_sensor1'
                                        */
  real_T Tomm_Gain;                    /* Expression: 1000
                                        * Referenced by: '<S4>/To mm'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S109>/Integrator1'
                                        */
  real_T Saturation8_UpperSat;         /* Expression: 50
                                        * Referenced by: '<S4>/Saturation8'
                                        */
  real_T Saturation8_LowerSat;         /* Expression: -50
                                        * Referenced by: '<S4>/Saturation8'
                                        */
  real_T uDLookupTable_bp01Data[14];   /* Expression: hems.Airgap'
                                        * Referenced by: '<S4>/2-D Lookup Table'
                                        */
  real_T TmpRTBAtAdd5Inport1_InitialCond;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T senal_discretizada_InitialCondi;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtZeroOrderHoldInport1_In;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Integrator4_IC;               /* Expression: 0
                                        * Referenced by: '<Root>/Integrator4'
                                        */
  real_T Tsamp_WtEt;                   /* Computed Parameter: Tsamp_WtEt
                                        * Referenced by: '<S86>/Tsamp'
                                        */
  real_T FilterDifferentiatorTF_NumCoef[2];/* Expression: [1 -1]
                                            * Referenced by: '<S84>/Filter Differentiator TF'
                                            */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S91>/Integrator'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 200
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -200
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T uDLookupTable1_bp01Data[14];  /* Expression: hems.Airgap'
                                        * Referenced by: '<S4>/2-D Lookup Table1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S108>/Constant'
                                        */
  real_T Seccion_Value;                /* Expression: 1.55e-6
                                        * Referenced by: '<S108>/Seccion'
                                        */
  real_T resistividad_Value;           /* Expression: 1.71e-8
                                        * Referenced by: '<S108>/resistividad'
                                        */
  real_T Tref_Value;                   /* Expression: 25
                                        * Referenced by: '<S108>/Tref'
                                        */
  real_T densidad_Value;               /* Expression: 8900
                                        * Referenced by: '<S108>/densidad'
                                        */
  real_T coeficiente_transferencia_Value;/* Expression: 380
                                          * Referenced by: '<S108>/coeficiente_transferencia'
                                          */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S109>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S109>/Delay1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S109>/Delay2'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S109>/Delay3'
                                        */
  real_T Temperature_Value;            /* Expression: 40
                                        * Referenced by: '<Root>/Temperature'
                                        */
  real_T TmpRTBAtSum1Outport1_InitialCon;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Tsamp_WtEt_n;                 /* Computed Parameter: Tsamp_WtEt_n
                                        * Referenced by: '<S36>/Tsamp'
                                        */
  real_T FilterDifferentiatorTF_NumCoe_d[2];/* Expression: [1 -1]
                                             * Referenced by: '<S34>/Filter Differentiator TF'
                                             */
  real_T Integrator_gainval_d;       /* Computed Parameter: Integrator_gainval_d
                                      * Referenced by: '<S41>/Integrator'
                                      */
  real_T Saturation6_UpperSat;         /* Expression: 50
                                        * Referenced by: '<Root>/Saturation6'
                                        */
  real_T Saturation6_LowerSat;         /* Expression: -50
                                        * Referenced by: '<Root>/Saturation6'
                                        */
  real_T Delay_InitialCondition_j;     /* Expression: 0.0
                                        * Referenced by: '<S6>/Delay'
                                        */
  real_T Delay1_InitialCondition_l;    /* Expression: 0.0
                                        * Referenced by: '<S6>/Delay1'
                                        */
  real_T dist_sensor_Value;            /* Expression: 0.07
                                        * Referenced by: '<Root>/dist_sensor'
                                        */
  uint32_T uDLookupTable_maxIndex[2];
                                   /* Computed Parameter: uDLookupTable_maxIndex
                                    * Referenced by: '<S4>/2-D Lookup Table'
                                    */
  uint32_T uDLookupTable1_maxIndex[2];
                                  /* Computed Parameter: uDLookupTable1_maxIndex
                                   * Referenced by: '<S4>/2-D Lookup Table1'
                                   */
  uint32_T uDLookupTable_maxIndex_d[2];
                                 /* Computed Parameter: uDLookupTable_maxIndex_d
                                  * Referenced by: '<S109>/2-D Lookup Table'
                                  */
};

/* Real-time Model Data Structure */
struct tag_RTM_H8_1GDL_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_H8_1GDL_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_H8_1GDL_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[4];
  real_T odeF[4][4];
  ODE4_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    uint32_T clockTick3;
    uint32_T clockTickH3;
    struct {
      uint8_T TID[4];
      uint8_T cLimit[4];
    } TaskCounters;

    struct {
      uint8_T TID1_2;
      uint8_T TID1_3;
      uint8_T TID2_3;
    } RateInteraction;

    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[4];
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_H8_1GDL_T H8_1GDL_P;

#ifdef __cplusplus

}

#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_H8_1GDL_T H8_1GDL_B;

#ifdef __cplusplus

}

#endif

/* Continuous states (default storage) */
extern X_H8_1GDL_T H8_1GDL_X;

/* Block states (default storage) */
extern struct DW_H8_1GDL_T H8_1GDL_DW;

/* Constant parameters (default storage) */
extern const ConstP_H8_1GDL_T H8_1GDL_ConstP;

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void H8_1GDL_initialize(void);
  extern void H8_1GDL_step0(void);
  extern void H8_1GDL_step2(void);
  extern void H8_1GDL_step3(void);
  extern void H8_1GDL_terminate(void);

#ifdef __cplusplus

}

#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_H8_1GDL_T *const H8_1GDL_M;

#ifdef __cplusplus

}

#endif

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'H8_1GDL'
 * '<S1>'   : 'H8_1GDL/Airgap Sensor1'
 * '<S2>'   : 'H8_1GDL/PID Controller3'
 * '<S3>'   : 'H8_1GDL/PID Controller4'
 * '<S4>'   : 'H8_1GDL/Subsystem'
 * '<S5>'   : 'H8_1GDL/Airgap Sensor1/Discr_Ampl'
 * '<S6>'   : 'H8_1GDL/Airgap Sensor1/Moving Average Filter'
 * '<S7>'   : 'H8_1GDL/Airgap Sensor1/Discr_Ampl/MATLAB Function1'
 * '<S8>'   : 'H8_1GDL/PID Controller3/Anti-windup'
 * '<S9>'   : 'H8_1GDL/PID Controller3/D Gain'
 * '<S10>'  : 'H8_1GDL/PID Controller3/Filter'
 * '<S11>'  : 'H8_1GDL/PID Controller3/Filter ICs'
 * '<S12>'  : 'H8_1GDL/PID Controller3/I Gain'
 * '<S13>'  : 'H8_1GDL/PID Controller3/Ideal P Gain'
 * '<S14>'  : 'H8_1GDL/PID Controller3/Ideal P Gain Fdbk'
 * '<S15>'  : 'H8_1GDL/PID Controller3/Integrator'
 * '<S16>'  : 'H8_1GDL/PID Controller3/Integrator ICs'
 * '<S17>'  : 'H8_1GDL/PID Controller3/N Copy'
 * '<S18>'  : 'H8_1GDL/PID Controller3/N Gain'
 * '<S19>'  : 'H8_1GDL/PID Controller3/P Copy'
 * '<S20>'  : 'H8_1GDL/PID Controller3/Parallel P Gain'
 * '<S21>'  : 'H8_1GDL/PID Controller3/Reset Signal'
 * '<S22>'  : 'H8_1GDL/PID Controller3/Saturation'
 * '<S23>'  : 'H8_1GDL/PID Controller3/Saturation Fdbk'
 * '<S24>'  : 'H8_1GDL/PID Controller3/Sum'
 * '<S25>'  : 'H8_1GDL/PID Controller3/Sum Fdbk'
 * '<S26>'  : 'H8_1GDL/PID Controller3/Tracking Mode'
 * '<S27>'  : 'H8_1GDL/PID Controller3/Tracking Mode Sum'
 * '<S28>'  : 'H8_1GDL/PID Controller3/Tsamp - Integral'
 * '<S29>'  : 'H8_1GDL/PID Controller3/Tsamp - Ngain'
 * '<S30>'  : 'H8_1GDL/PID Controller3/postSat Signal'
 * '<S31>'  : 'H8_1GDL/PID Controller3/preSat Signal'
 * '<S32>'  : 'H8_1GDL/PID Controller3/Anti-windup/Passthrough'
 * '<S33>'  : 'H8_1GDL/PID Controller3/D Gain/Internal Parameters'
 * '<S34>'  : 'H8_1GDL/PID Controller3/Filter/Disc. Trapezoidal Filter'
 * '<S35>'  : 'H8_1GDL/PID Controller3/Filter/Disc. Trapezoidal Filter/Tsamp'
 * '<S36>'  : 'H8_1GDL/PID Controller3/Filter/Disc. Trapezoidal Filter/Tsamp/Internal Ts'
 * '<S37>'  : 'H8_1GDL/PID Controller3/Filter ICs/Internal IC - Filter'
 * '<S38>'  : 'H8_1GDL/PID Controller3/I Gain/Internal Parameters'
 * '<S39>'  : 'H8_1GDL/PID Controller3/Ideal P Gain/Passthrough'
 * '<S40>'  : 'H8_1GDL/PID Controller3/Ideal P Gain Fdbk/Disabled'
 * '<S41>'  : 'H8_1GDL/PID Controller3/Integrator/Discrete'
 * '<S42>'  : 'H8_1GDL/PID Controller3/Integrator ICs/Internal IC'
 * '<S43>'  : 'H8_1GDL/PID Controller3/N Copy/Internal Parameters'
 * '<S44>'  : 'H8_1GDL/PID Controller3/N Gain/Internal Parameters'
 * '<S45>'  : 'H8_1GDL/PID Controller3/P Copy/Disabled'
 * '<S46>'  : 'H8_1GDL/PID Controller3/Parallel P Gain/Internal Parameters'
 * '<S47>'  : 'H8_1GDL/PID Controller3/Reset Signal/Disabled'
 * '<S48>'  : 'H8_1GDL/PID Controller3/Saturation/Passthrough'
 * '<S49>'  : 'H8_1GDL/PID Controller3/Saturation Fdbk/Disabled'
 * '<S50>'  : 'H8_1GDL/PID Controller3/Sum/Sum_PID'
 * '<S51>'  : 'H8_1GDL/PID Controller3/Sum Fdbk/Disabled'
 * '<S52>'  : 'H8_1GDL/PID Controller3/Tracking Mode/Disabled'
 * '<S53>'  : 'H8_1GDL/PID Controller3/Tracking Mode Sum/Passthrough'
 * '<S54>'  : 'H8_1GDL/PID Controller3/Tsamp - Integral/Passthrough'
 * '<S55>'  : 'H8_1GDL/PID Controller3/Tsamp - Ngain/Passthrough'
 * '<S56>'  : 'H8_1GDL/PID Controller3/postSat Signal/Forward_Path'
 * '<S57>'  : 'H8_1GDL/PID Controller3/preSat Signal/Forward_Path'
 * '<S58>'  : 'H8_1GDL/PID Controller4/Anti-windup'
 * '<S59>'  : 'H8_1GDL/PID Controller4/D Gain'
 * '<S60>'  : 'H8_1GDL/PID Controller4/Filter'
 * '<S61>'  : 'H8_1GDL/PID Controller4/Filter ICs'
 * '<S62>'  : 'H8_1GDL/PID Controller4/I Gain'
 * '<S63>'  : 'H8_1GDL/PID Controller4/Ideal P Gain'
 * '<S64>'  : 'H8_1GDL/PID Controller4/Ideal P Gain Fdbk'
 * '<S65>'  : 'H8_1GDL/PID Controller4/Integrator'
 * '<S66>'  : 'H8_1GDL/PID Controller4/Integrator ICs'
 * '<S67>'  : 'H8_1GDL/PID Controller4/N Copy'
 * '<S68>'  : 'H8_1GDL/PID Controller4/N Gain'
 * '<S69>'  : 'H8_1GDL/PID Controller4/P Copy'
 * '<S70>'  : 'H8_1GDL/PID Controller4/Parallel P Gain'
 * '<S71>'  : 'H8_1GDL/PID Controller4/Reset Signal'
 * '<S72>'  : 'H8_1GDL/PID Controller4/Saturation'
 * '<S73>'  : 'H8_1GDL/PID Controller4/Saturation Fdbk'
 * '<S74>'  : 'H8_1GDL/PID Controller4/Sum'
 * '<S75>'  : 'H8_1GDL/PID Controller4/Sum Fdbk'
 * '<S76>'  : 'H8_1GDL/PID Controller4/Tracking Mode'
 * '<S77>'  : 'H8_1GDL/PID Controller4/Tracking Mode Sum'
 * '<S78>'  : 'H8_1GDL/PID Controller4/Tsamp - Integral'
 * '<S79>'  : 'H8_1GDL/PID Controller4/Tsamp - Ngain'
 * '<S80>'  : 'H8_1GDL/PID Controller4/postSat Signal'
 * '<S81>'  : 'H8_1GDL/PID Controller4/preSat Signal'
 * '<S82>'  : 'H8_1GDL/PID Controller4/Anti-windup/Passthrough'
 * '<S83>'  : 'H8_1GDL/PID Controller4/D Gain/Internal Parameters'
 * '<S84>'  : 'H8_1GDL/PID Controller4/Filter/Disc. Trapezoidal Filter'
 * '<S85>'  : 'H8_1GDL/PID Controller4/Filter/Disc. Trapezoidal Filter/Tsamp'
 * '<S86>'  : 'H8_1GDL/PID Controller4/Filter/Disc. Trapezoidal Filter/Tsamp/Internal Ts'
 * '<S87>'  : 'H8_1GDL/PID Controller4/Filter ICs/Internal IC - Filter'
 * '<S88>'  : 'H8_1GDL/PID Controller4/I Gain/Internal Parameters'
 * '<S89>'  : 'H8_1GDL/PID Controller4/Ideal P Gain/Passthrough'
 * '<S90>'  : 'H8_1GDL/PID Controller4/Ideal P Gain Fdbk/Disabled'
 * '<S91>'  : 'H8_1GDL/PID Controller4/Integrator/Discrete'
 * '<S92>'  : 'H8_1GDL/PID Controller4/Integrator ICs/Internal IC'
 * '<S93>'  : 'H8_1GDL/PID Controller4/N Copy/Internal Parameters'
 * '<S94>'  : 'H8_1GDL/PID Controller4/N Gain/Internal Parameters'
 * '<S95>'  : 'H8_1GDL/PID Controller4/P Copy/Disabled'
 * '<S96>'  : 'H8_1GDL/PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S97>'  : 'H8_1GDL/PID Controller4/Reset Signal/Disabled'
 * '<S98>'  : 'H8_1GDL/PID Controller4/Saturation/Passthrough'
 * '<S99>'  : 'H8_1GDL/PID Controller4/Saturation Fdbk/Disabled'
 * '<S100>' : 'H8_1GDL/PID Controller4/Sum/Sum_PID'
 * '<S101>' : 'H8_1GDL/PID Controller4/Sum Fdbk/Disabled'
 * '<S102>' : 'H8_1GDL/PID Controller4/Tracking Mode/Disabled'
 * '<S103>' : 'H8_1GDL/PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S104>' : 'H8_1GDL/PID Controller4/Tsamp - Integral/Passthrough'
 * '<S105>' : 'H8_1GDL/PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S106>' : 'H8_1GDL/PID Controller4/postSat Signal/Forward_Path'
 * '<S107>' : 'H8_1GDL/PID Controller4/preSat Signal/Forward_Path'
 * '<S108>' : 'H8_1GDL/Subsystem/Calentamiento 1 - bobina'
 * '<S109>' : 'H8_1GDL/Subsystem/RL'
 * '<S110>' : 'H8_1GDL/Subsystem/RL/Subsystem'
 */
#endif                                 /* RTW_HEADER_H8_1GDL_h_ */
