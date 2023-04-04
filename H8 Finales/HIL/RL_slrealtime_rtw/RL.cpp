/*
 * RL.cpp
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

#include "RL.h"
#include "rtwtypes.h"
#include "RL_private.h"
#include <cstring>

/* Block signals (default storage) */
B_RL_T RL_B;

/* Continuous states */
X_RL_T RL_X;

/* Block states (default storage) */
DW_RL_T RL_DW;

/* Real-time model */
RT_MODEL_RL_T RL_M_ = RT_MODEL_RL_T();
RT_MODEL_RL_T *const RL_M = &RL_M_;
real_T look2_binlxpw(real_T u0, real_T u1, const real_T bp0[], const real_T bp1[],
                     const real_T table[], const uint32_T maxIndex[], uint32_T
                     stride)
{
  real_T fractions[2];
  real_T frac;
  real_T yL_0d0;
  real_T yL_0d1;
  uint32_T bpIndices[2];
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = maxIndex[0U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[0U];
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = (u0 - bp0[maxIndex[0U] - 1U]) / (bp0[maxIndex[0U]] - bp0[maxIndex[0U]
      - 1U]);
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = (u1 - bp1[0U]) / (bp1[1U] - bp1[0U]);
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = maxIndex[1U] >> 1U;
    iLeft = 0U;
    iRght = maxIndex[1U];
    while (iRght - iLeft > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u1 - bp1[iLeft]) / (bp1[iLeft + 1U] - bp1[iLeft]);
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = (u1 - bp1[maxIndex[1U] - 1U]) / (bp1[maxIndex[1U]] - bp1[maxIndex[1U]
      - 1U]);
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  bpIdx = iLeft * stride + bpIndices[0U];
  yL_0d0 = table[bpIdx];
  yL_0d0 += (table[bpIdx + 1U] - yL_0d0) * fractions[0U];
  bpIdx += stride;
  yL_0d1 = table[bpIdx];
  return (((table[bpIdx + 1U] - yL_0d1) * fractions[0U] + yL_0d1) - yL_0d0) *
    frac + yL_0d0;
}

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = static_cast<ODE4_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) std::memcpy(y, x,
                     static_cast<uint_T>(nXc)*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  RL_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  RL_step();
  RL_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  RL_step();
  RL_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  RL_step();
  RL_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void RL_step(void)
{
  real_T tmp[109];
  real_T u0;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(RL_M)) {
    /* set solver stop time */
    if (!(RL_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&RL_M->solverInfo, ((RL_M->Timing.clockTickH0 + 1) *
        RL_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&RL_M->solverInfo, ((RL_M->Timing.clockTick0 + 1) *
        RL_M->Timing.stepSize0 + RL_M->Timing.clockTickH0 *
        RL_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(RL_M)) {
    RL_M->Timing.t[0] = rtsiGetT(&RL_M->solverInfo);
  }

  /* Integrator: '<S51>/Integrator' */
  RL_B.Integrator = RL_X.Integrator_CSTATE;

  /* Sum: '<S51>/Sum' incorporates:
   *  Constant: '<S51>/Tamb'
   */
  RL_B.Sum = RL_B.Integrator + RL_P.Tamb_Value;

  /* Integrator: '<S52>/Integrator1' */
  RL_B.currentapplied = RL_X.Integrator1_CSTATE;

  /* Saturate: '<S2>/Saturation8' */
  u0 = RL_B.currentapplied;
  u1 = RL_P.Saturation8_LowerSat;
  u2 = RL_P.Saturation8_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<S2>/Saturation8' */
    RL_B.I = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S2>/Saturation8' */
    RL_B.I = u1;
  } else {
    /* Saturate: '<S2>/Saturation8' */
    RL_B.I = u0;
  }

  /* End of Saturate: '<S2>/Saturation8' */
  if (rtmIsMajorTimeStep(RL_M)) {
  }

  /* Sum: '<Root>/Add5' incorporates:
   *  Constant: '<Root>/Constant'
   */
  RL_B.Add5 = RL_P.Constant_Value - RL_B.I;

  /* Gain: '<S28>/Derivative Gain' */
  RL_B.DerivativeGain = RL_P.PIDController4_D * RL_B.Add5;

  /* Integrator: '<S29>/Filter' */
  RL_B.Filter = RL_X.Filter_CSTATE;

  /* Sum: '<S29>/SumD' */
  RL_B.SumD = RL_B.DerivativeGain - RL_B.Filter;

  /* Gain: '<S31>/Integral Gain' */
  RL_B.IntegralGain = RL_P.PIDController4_I * RL_B.Add5;

  /* Integrator: '<S34>/Integrator' */
  RL_B.Integrator_l = RL_X.Integrator_CSTATE_d;

  /* Gain: '<S37>/Filter Coefficient' */
  RL_B.FilterCoefficient = RL_P.PIDController4_N * RL_B.SumD;

  /* Gain: '<S39>/Proportional Gain' */
  RL_B.ProportionalGain = RL_P.PIDController4_P * RL_B.Add5;

  /* Sum: '<S43>/Sum' */
  RL_B.Sum_f = (RL_B.ProportionalGain + RL_B.Integrator_l) +
    RL_B.FilterCoefficient;

  /* Saturate: '<Root>/Saturation1' */
  u0 = RL_B.Sum_f;
  u1 = RL_P.Saturation1_LowerSat;
  u2 = RL_P.Saturation1_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<Root>/Saturation1' */
    RL_B.vs = u2;
  } else if (u0 < u1) {
    /* Saturate: '<Root>/Saturation1' */
    RL_B.vs = u1;
  } else {
    /* Saturate: '<Root>/Saturation1' */
    RL_B.vs = u0;
  }

  /* End of Saturate: '<Root>/Saturation1' */
  if (rtmIsMajorTimeStep(RL_M)) {
    /* Gain: '<S2>/To mm' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    RL_B.airgap = RL_P.Tomm_Gain * RL_P.lev_nom;

    /* Product: '<S51>/Product2' incorporates:
     *  Constant: '<S51>/coeficiente_transferencia'
     *  Constant: '<S51>/densidad'
     */
    RL_B.Product2 = RL_P.densidad_Value * RL_P.coeficiente_transferencia_Value;
  }

  /* Lookup_n-D: '<S2>/2-D Lookup Table' incorporates:
   *  Gain: '<S2>/To mm'
   *  Saturate: '<S2>/Saturation8'
   */
  RL_B.Fl = look2_binlxpw(RL_B.airgap, RL_B.I, RL_P.uDLookupTable_bp01Data,
    RL_P.hems.Current, RL_P.hems.Force_Vertical, RL_P.uDLookupTable_maxIndex,
    14U);

  /* Lookup_n-D: '<S2>/2-D Lookup Table1' incorporates:
   *  Gain: '<S2>/To mm'
   *  Saturate: '<S2>/Saturation8'
   */
  RL_B.Fl_m = look2_binlxpw(RL_B.airgap, RL_B.I, RL_P.uDLookupTable1_bp01Data,
    RL_P.hems.Current, RL_P.hems.Force_Horizontal, RL_P.uDLookupTable1_maxIndex,
    14U);

  /* Product: '<S51>/Divide' incorporates:
   *  Constant: '<S51>/Seccion'
   */
  RL_B.Divide = RL_B.I / RL_P.Seccion_Value;

  /* Math: '<S51>/Math Function'
   *
   * About '<S51>/Math Function':
   *  Operator: magnitude^2
   */
  u0 = RL_B.Divide;

  /* Math: '<S51>/Math Function'
   *
   * About '<S51>/Math Function':
   *  Operator: magnitude^2
   */
  RL_B.MathFunction = u0 * u0;

  /* Sum: '<S51>/Sum1' incorporates:
   *  Constant: '<S51>/Tref'
   */
  RL_B.Sum1 = RL_B.Sum - RL_P.Tref_Value;

  /* Gain: '<S51>/masa_bobina' */
  RL_B.masa_bobina = RL_P.hems.masa_bobina * RL_B.Sum1;

  /* Sum: '<S51>/Sum2' incorporates:
   *  Constant: '<S51>/Constant'
   */
  RL_B.Sum2 = RL_B.masa_bobina + RL_P.Constant_Value_f;

  /* Product: '<S51>/Product1' incorporates:
   *  Constant: '<S51>/resistividad'
   */
  RL_B.Product1 = RL_P.resistividad_Value * RL_B.Sum2;

  /* Product: '<S51>/Product' */
  RL_B.Product = RL_B.MathFunction * RL_B.Product1;

  /* Product: '<S51>/Divide1' */
  RL_B.Divide1 = RL_B.Product / RL_B.Product2;
  if (rtmIsMajorTimeStep(RL_M)) {
    /* Delay: '<S52>/Delay' */
    RL_B.Delay = RL_DW.Delay_DSTATE;

    /* Delay: '<S52>/Delay1' */
    RL_B.Delay1 = RL_DW.Delay1_DSTATE;

    /* Lookup_n-D: '<S52>/2-D Lookup Table' */
    for (int32_T i = 0; i < 109; i++) {
      tmp[i] = RL_P.hems.Current[static_cast<int32_T>
        (RL_ConstP.uDLookupTable_rtw_collapsed_sub[i]) - 1];
    }

    /* Lookup_n-D: '<S52>/2-D Lookup Table' incorporates:
     *  Delay: '<S52>/Delay'
     *  Delay: '<S52>/Delay1'
     */
    RL_B.L = look2_binlxpw(RL_B.Delay, RL_B.Delay1, RL_P.hems.Airgap, tmp,
      RL_P.hems.Inductance, RL_P.uDLookupTable_maxIndex_d, 14U);
  }

  /* Product: '<S52>/Divide1' incorporates:
   *  Constant: '<S53>/Resistance'
   */
  RL_B.current = RL_B.vs / RL_P.hems.Resistance;

  /* Sum: '<S52>/Add' */
  RL_B.Add = RL_B.current - RL_B.currentapplied;
  if (rtmIsMajorTimeStep(RL_M)) {
    /* Delay: '<S52>/Delay2' */
    RL_B.Delay2 = RL_DW.Delay2_DSTATE;

    /* Delay: '<S52>/Delay3' */
    RL_B.Delay3 = RL_DW.Delay3_DSTATE;

    /* Product: '<S52>/Divide2' incorporates:
     *  Constant: '<S53>/Resistance'
     */
    RL_B.Divide2 = RL_B.L / RL_P.hems.Resistance;
  }

  /* Product: '<S52>/Divide' */
  RL_B.Divide_f = RL_B.Add / RL_B.Divide2;
  if (rtmIsMajorTimeStep(RL_M)) {
    if (rtmIsMajorTimeStep(RL_M)) {
      /* Update for Delay: '<S52>/Delay' */
      RL_DW.Delay_DSTATE = RL_B.airgap;

      /* Update for Delay: '<S52>/Delay1' */
      RL_DW.Delay1_DSTATE = RL_B.currentapplied;

      /* Update for Delay: '<S52>/Delay2' incorporates:
       *  Constant: '<Root>/Temperature'
       */
      RL_DW.Delay2_DSTATE = RL_P.Temperature_Value;

      /* Update for Delay: '<S52>/Delay3' */
      RL_DW.Delay3_DSTATE = RL_B.currentapplied;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(RL_M)) {
    rt_ertODEUpdateContinuousStates(&RL_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++RL_M->Timing.clockTick0)) {
      ++RL_M->Timing.clockTickH0;
    }

    RL_M->Timing.t[0] = rtsiGetSolverStopTime(&RL_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.00025s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.00025, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      RL_M->Timing.clockTick1++;
      if (!RL_M->Timing.clockTick1) {
        RL_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void RL_derivatives(void)
{
  XDot_RL_T *_rtXdot;
  _rtXdot = ((XDot_RL_T *) RL_M->derivs);

  /* Derivatives for Integrator: '<S51>/Integrator' */
  _rtXdot->Integrator_CSTATE = RL_B.Divide1;

  /* Derivatives for Integrator: '<S52>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = RL_B.Divide_f;

  /* Derivatives for Integrator: '<S29>/Filter' */
  _rtXdot->Filter_CSTATE = RL_B.FilterCoefficient;

  /* Derivatives for Integrator: '<S34>/Integrator' */
  _rtXdot->Integrator_CSTATE_d = RL_B.IntegralGain;
}

/* Model initialize function */
void RL_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&RL_M->solverInfo, &RL_M->Timing.simTimeStep);
    rtsiSetTPtr(&RL_M->solverInfo, &rtmGetTPtr(RL_M));
    rtsiSetStepSizePtr(&RL_M->solverInfo, &RL_M->Timing.stepSize0);
    rtsiSetdXPtr(&RL_M->solverInfo, &RL_M->derivs);
    rtsiSetContStatesPtr(&RL_M->solverInfo, (real_T **) &RL_M->contStates);
    rtsiSetNumContStatesPtr(&RL_M->solverInfo, &RL_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&RL_M->solverInfo,
      &RL_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&RL_M->solverInfo,
      &RL_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&RL_M->solverInfo,
      &RL_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&RL_M->solverInfo, (&rtmGetErrorStatus(RL_M)));
    rtsiSetRTModelPtr(&RL_M->solverInfo, RL_M);
  }

  rtsiSetSimTimeStep(&RL_M->solverInfo, MAJOR_TIME_STEP);
  RL_M->intgData.y = RL_M->odeY;
  RL_M->intgData.f[0] = RL_M->odeF[0];
  RL_M->intgData.f[1] = RL_M->odeF[1];
  RL_M->intgData.f[2] = RL_M->odeF[2];
  RL_M->intgData.f[3] = RL_M->odeF[3];
  RL_M->contStates = ((X_RL_T *) &RL_X);
  rtsiSetSolverData(&RL_M->solverInfo, static_cast<void *>(&RL_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&RL_M->solverInfo, false);
  rtsiSetSolverName(&RL_M->solverInfo,"ode4");
  rtmSetTPtr(RL_M, &RL_M->Timing.tArray[0]);
  RL_M->Timing.stepSize0 = 0.00025;

  /* block I/O */
  (void) std::memset((static_cast<void *>(&RL_B)), 0,
                     sizeof(B_RL_T));

  /* states (continuous) */
  {
    (void) std::memset(static_cast<void *>(&RL_X), 0,
                       sizeof(X_RL_T));
  }

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&RL_DW), 0,
                     sizeof(DW_RL_T));

  /* InitializeConditions for Integrator: '<S51>/Integrator' */
  RL_X.Integrator_CSTATE = RL_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<S52>/Integrator1' */
  RL_X.Integrator1_CSTATE = RL_P.Integrator1_IC;

  /* InitializeConditions for Integrator: '<S29>/Filter' */
  RL_X.Filter_CSTATE = RL_P.PIDController4_InitialCondition;

  /* InitializeConditions for Integrator: '<S34>/Integrator' */
  RL_X.Integrator_CSTATE_d = RL_P.PIDController4_InitialConditi_d;

  /* InitializeConditions for Delay: '<S52>/Delay' */
  RL_DW.Delay_DSTATE = RL_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S52>/Delay1' */
  RL_DW.Delay1_DSTATE = RL_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S52>/Delay2' */
  RL_DW.Delay2_DSTATE = RL_P.Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S52>/Delay3' */
  RL_DW.Delay3_DSTATE = RL_P.Delay3_InitialCondition;
}

/* Model terminate function */
void RL_terminate(void)
{
  /* (no terminate code required) */
}
