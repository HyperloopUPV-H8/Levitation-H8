/*
 * RL.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RL".
 *
 * Model version              : 1.67
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C++ source code generated on : Tue Apr  4 14:16:31 2023
 *
 * Target selection: slrealtime.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Linux 64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_RL_h_
#define RTW_HEADER_RL_h_
#include <logsrv.h>
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "RL_types.h"
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

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
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

/* Block signals (default storage) */
struct B_RL_T {
  real_T Integrator;                   /* '<S51>/Integrator' */
  real_T Sum;                          /* '<S51>/Sum' */
  real_T currentapplied;               /* '<S52>/Integrator1' */
  real_T I;                            /* '<S2>/Saturation8' */
  real_T Add5;                         /* '<Root>/Add5' */
  real_T DerivativeGain;               /* '<S28>/Derivative Gain' */
  real_T Filter;                       /* '<S29>/Filter' */
  real_T SumD;                         /* '<S29>/SumD' */
  real_T IntegralGain;                 /* '<S31>/Integral Gain' */
  real_T Integrator_l;                 /* '<S34>/Integrator' */
  real_T FilterCoefficient;            /* '<S37>/Filter Coefficient' */
  real_T ProportionalGain;             /* '<S39>/Proportional Gain' */
  real_T Sum_f;                        /* '<S43>/Sum' */
  real_T vs;                           /* '<Root>/Saturation1' */
  real_T airgap;                       /* '<S2>/To mm' */
  real_T Fl;                           /* '<S2>/2-D Lookup Table' */
  real_T Fl_m;                         /* '<S2>/2-D Lookup Table1' */
  real_T Divide;                       /* '<S51>/Divide' */
  real_T MathFunction;                 /* '<S51>/Math Function' */
  real_T Sum1;                         /* '<S51>/Sum1' */
  real_T masa_bobina;                  /* '<S51>/masa_bobina' */
  real_T Sum2;                         /* '<S51>/Sum2' */
  real_T Product1;                     /* '<S51>/Product1' */
  real_T Product;                      /* '<S51>/Product' */
  real_T Product2;                     /* '<S51>/Product2' */
  real_T Divide1;                      /* '<S51>/Divide1' */
  real_T Delay;                        /* '<S52>/Delay' */
  real_T Delay1;                       /* '<S52>/Delay1' */
  real_T L;                            /* '<S52>/2-D Lookup Table' */
  real_T current;                      /* '<S52>/Divide1' */
  real_T Add;                          /* '<S52>/Add' */
  real_T Delay2;                       /* '<S52>/Delay2' */
  real_T Delay3;                       /* '<S52>/Delay3' */
  real_T Divide2;                      /* '<S52>/Divide2' */
  real_T Divide_f;                     /* '<S52>/Divide' */
};

/* Block states (default storage) for system '<Root>' */
struct DW_RL_T {
  real_T Delay_DSTATE;                 /* '<S52>/Delay' */
  real_T Delay1_DSTATE;                /* '<S52>/Delay1' */
  real_T Delay2_DSTATE;                /* '<S52>/Delay2' */
  real_T Delay3_DSTATE;                /* '<S52>/Delay3' */
  struct {
    void *AQHandles;
  } TAQSigLogging_InsertedFor_Subsy;   /* synthesized block */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<S2>/Scope' */
};

/* Continuous states (default storage) */
struct X_RL_T {
  real_T Integrator_CSTATE;            /* '<S51>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S52>/Integrator1' */
  real_T Filter_CSTATE;                /* '<S29>/Filter' */
  real_T Integrator_CSTATE_d;          /* '<S34>/Integrator' */
};

/* State derivatives (default storage) */
struct XDot_RL_T {
  real_T Integrator_CSTATE;            /* '<S51>/Integrator' */
  real_T Integrator1_CSTATE;           /* '<S52>/Integrator1' */
  real_T Filter_CSTATE;                /* '<S29>/Filter' */
  real_T Integrator_CSTATE_d;          /* '<S34>/Integrator' */
};

/* State disabled  */
struct XDis_RL_T {
  boolean_T Integrator_CSTATE;         /* '<S51>/Integrator' */
  boolean_T Integrator1_CSTATE;        /* '<S52>/Integrator1' */
  boolean_T Filter_CSTATE;             /* '<S29>/Filter' */
  boolean_T Integrator_CSTATE_d;       /* '<S34>/Integrator' */
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
struct ConstP_RL_T {
  /* Expression: hems.Current(2:110)
   * Referenced by: '<S52>/2-D Lookup Table'
   */
  real_T uDLookupTable_rtw_collapsed_sub[109];
};

/* Parameters (default storage) */
struct P_RL_T_ {
  struct_66wI9m9XKOeh3OoPuAXQCF hems;  /* Variable: hems
                                        * Referenced by:
                                        *   '<S2>/2-D Lookup Table'
                                        *   '<S2>/2-D Lookup Table1'
                                        *   '<S51>/masa_bobina'
                                        *   '<S52>/2-D Lookup Table'
                                        *   '<S53>/Resistance'
                                        */
  real_T lev_nom;                      /* Variable: lev_nom
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T PIDController4_D;             /* Mask Parameter: PIDController4_D
                                        * Referenced by: '<S28>/Derivative Gain'
                                        */
  real_T PIDController4_I;             /* Mask Parameter: PIDController4_I
                                        * Referenced by: '<S31>/Integral Gain'
                                        */
  real_T PIDController4_InitialCondition;
                              /* Mask Parameter: PIDController4_InitialCondition
                               * Referenced by: '<S29>/Filter'
                               */
  real_T PIDController4_InitialConditi_d;
                              /* Mask Parameter: PIDController4_InitialConditi_d
                               * Referenced by: '<S34>/Integrator'
                               */
  real_T PIDController4_N;             /* Mask Parameter: PIDController4_N
                                        * Referenced by: '<S37>/Filter Coefficient'
                                        */
  real_T PIDController4_P;             /* Mask Parameter: PIDController4_P
                                        * Referenced by: '<S39>/Proportional Gain'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S51>/Integrator'
                                        */
  real_T Tamb_Value;                   /* Expression: 40
                                        * Referenced by: '<S51>/Tamb'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S52>/Integrator1'
                                        */
  real_T Saturation8_UpperSat;         /* Expression: 50
                                        * Referenced by: '<S2>/Saturation8'
                                        */
  real_T Saturation8_LowerSat;         /* Expression: -50
                                        * Referenced by: '<S2>/Saturation8'
                                        */
  real_T Constant_Value;               /* Expression: 10
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 200
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -200
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Tomm_Gain;                    /* Expression: 1000
                                        * Referenced by: '<S2>/To mm'
                                        */
  real_T uDLookupTable_bp01Data[14];   /* Expression: hems.Airgap'
                                        * Referenced by: '<S2>/2-D Lookup Table'
                                        */
  real_T uDLookupTable1_bp01Data[14];  /* Expression: hems.Airgap'
                                        * Referenced by: '<S2>/2-D Lookup Table1'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S51>/Constant'
                                        */
  real_T Seccion_Value;                /* Expression: 1.55e-6
                                        * Referenced by: '<S51>/Seccion'
                                        */
  real_T resistividad_Value;           /* Expression: 1.71e-8
                                        * Referenced by: '<S51>/resistividad'
                                        */
  real_T Tref_Value;                   /* Expression: 25
                                        * Referenced by: '<S51>/Tref'
                                        */
  real_T densidad_Value;               /* Expression: 8900
                                        * Referenced by: '<S51>/densidad'
                                        */
  real_T coeficiente_transferencia_Value;/* Expression: 380
                                          * Referenced by: '<S51>/coeficiente_transferencia'
                                          */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S52>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S52>/Delay1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S52>/Delay2'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S52>/Delay3'
                                        */
  real_T Temperature_Value;            /* Expression: 40
                                        * Referenced by: '<Root>/Temperature'
                                        */
  uint32_T uDLookupTable_maxIndex[2];
                                   /* Computed Parameter: uDLookupTable_maxIndex
                                    * Referenced by: '<S2>/2-D Lookup Table'
                                    */
  uint32_T uDLookupTable1_maxIndex[2];
                                  /* Computed Parameter: uDLookupTable1_maxIndex
                                   * Referenced by: '<S2>/2-D Lookup Table1'
                                   */
  uint32_T uDLookupTable_maxIndex_d[2];
                                 /* Computed Parameter: uDLookupTable_maxIndex_d
                                  * Referenced by: '<S52>/2-D Lookup Table'
                                  */
};

/* Real-time Model Data Structure */
struct tag_RTM_RL_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_RL_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_RL_T *contStateDisabled;
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
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_RL_T RL_P;

#ifdef __cplusplus

}

#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_RL_T RL_B;

#ifdef __cplusplus

}

#endif

/* Continuous states (default storage) */
extern X_RL_T RL_X;

/* Block states (default storage) */
extern struct DW_RL_T RL_DW;

/* Constant parameters (default storage) */
extern const ConstP_RL_T RL_ConstP;

#ifdef __cplusplus

extern "C"
{

#endif

  /* Model entry point functions */
  extern void RL_initialize(void);
  extern void RL_step(void);
  extern void RL_terminate(void);

#ifdef __cplusplus

}

#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_RL_T *const RL_M;

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
 * '<Root>' : 'RL'
 * '<S1>'   : 'RL/PID Controller4'
 * '<S2>'   : 'RL/Subsystem'
 * '<S3>'   : 'RL/PID Controller4/Anti-windup'
 * '<S4>'   : 'RL/PID Controller4/D Gain'
 * '<S5>'   : 'RL/PID Controller4/Filter'
 * '<S6>'   : 'RL/PID Controller4/Filter ICs'
 * '<S7>'   : 'RL/PID Controller4/I Gain'
 * '<S8>'   : 'RL/PID Controller4/Ideal P Gain'
 * '<S9>'   : 'RL/PID Controller4/Ideal P Gain Fdbk'
 * '<S10>'  : 'RL/PID Controller4/Integrator'
 * '<S11>'  : 'RL/PID Controller4/Integrator ICs'
 * '<S12>'  : 'RL/PID Controller4/N Copy'
 * '<S13>'  : 'RL/PID Controller4/N Gain'
 * '<S14>'  : 'RL/PID Controller4/P Copy'
 * '<S15>'  : 'RL/PID Controller4/Parallel P Gain'
 * '<S16>'  : 'RL/PID Controller4/Reset Signal'
 * '<S17>'  : 'RL/PID Controller4/Saturation'
 * '<S18>'  : 'RL/PID Controller4/Saturation Fdbk'
 * '<S19>'  : 'RL/PID Controller4/Sum'
 * '<S20>'  : 'RL/PID Controller4/Sum Fdbk'
 * '<S21>'  : 'RL/PID Controller4/Tracking Mode'
 * '<S22>'  : 'RL/PID Controller4/Tracking Mode Sum'
 * '<S23>'  : 'RL/PID Controller4/Tsamp - Integral'
 * '<S24>'  : 'RL/PID Controller4/Tsamp - Ngain'
 * '<S25>'  : 'RL/PID Controller4/postSat Signal'
 * '<S26>'  : 'RL/PID Controller4/preSat Signal'
 * '<S27>'  : 'RL/PID Controller4/Anti-windup/Passthrough'
 * '<S28>'  : 'RL/PID Controller4/D Gain/Internal Parameters'
 * '<S29>'  : 'RL/PID Controller4/Filter/Cont. Filter'
 * '<S30>'  : 'RL/PID Controller4/Filter ICs/Internal IC - Filter'
 * '<S31>'  : 'RL/PID Controller4/I Gain/Internal Parameters'
 * '<S32>'  : 'RL/PID Controller4/Ideal P Gain/Passthrough'
 * '<S33>'  : 'RL/PID Controller4/Ideal P Gain Fdbk/Disabled'
 * '<S34>'  : 'RL/PID Controller4/Integrator/Continuous'
 * '<S35>'  : 'RL/PID Controller4/Integrator ICs/Internal IC'
 * '<S36>'  : 'RL/PID Controller4/N Copy/Disabled'
 * '<S37>'  : 'RL/PID Controller4/N Gain/Internal Parameters'
 * '<S38>'  : 'RL/PID Controller4/P Copy/Disabled'
 * '<S39>'  : 'RL/PID Controller4/Parallel P Gain/Internal Parameters'
 * '<S40>'  : 'RL/PID Controller4/Reset Signal/Disabled'
 * '<S41>'  : 'RL/PID Controller4/Saturation/Passthrough'
 * '<S42>'  : 'RL/PID Controller4/Saturation Fdbk/Disabled'
 * '<S43>'  : 'RL/PID Controller4/Sum/Sum_PID'
 * '<S44>'  : 'RL/PID Controller4/Sum Fdbk/Disabled'
 * '<S45>'  : 'RL/PID Controller4/Tracking Mode/Disabled'
 * '<S46>'  : 'RL/PID Controller4/Tracking Mode Sum/Passthrough'
 * '<S47>'  : 'RL/PID Controller4/Tsamp - Integral/Passthrough'
 * '<S48>'  : 'RL/PID Controller4/Tsamp - Ngain/Passthrough'
 * '<S49>'  : 'RL/PID Controller4/postSat Signal/Forward_Path'
 * '<S50>'  : 'RL/PID Controller4/preSat Signal/Forward_Path'
 * '<S51>'  : 'RL/Subsystem/Calentamiento 1 - bobina'
 * '<S52>'  : 'RL/Subsystem/RL'
 * '<S53>'  : 'RL/Subsystem/RL/Subsystem'
 */
#endif                                 /* RTW_HEADER_RL_h_ */
