/*
 * H8_1GDL.cpp
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

#include "H8_1GDL.h"
#include "rtwtypes.h"
#include "H8_1GDL_private.h"
#include <cstring>

/* Block signals (default storage) */
B_H8_1GDL_T H8_1GDL_B;

/* Continuous states */
X_H8_1GDL_T H8_1GDL_X;

/* Block states (default storage) */
DW_H8_1GDL_T H8_1GDL_DW;

/* Real-time model */
RT_MODEL_H8_1GDL_T H8_1GDL_M_ = RT_MODEL_H8_1GDL_T();
RT_MODEL_H8_1GDL_T *const H8_1GDL_M = &H8_1GDL_M_;
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
  H8_1GDL_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  H8_1GDL_step0();
  H8_1GDL_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  H8_1GDL_step0();
  H8_1GDL_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  H8_1GDL_step0();
  H8_1GDL_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function for TID0 */
void H8_1GDL_step0(void)               /* Sample time: [0.0s, 0.0s] */
{
  real_T tmp[109];
  real_T u0;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(H8_1GDL_M)) {
    /* set solver stop time */
    if (!(H8_1GDL_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&H8_1GDL_M->solverInfo,
                            ((H8_1GDL_M->Timing.clockTickH0 + 1) *
        H8_1GDL_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&H8_1GDL_M->solverInfo,
                            ((H8_1GDL_M->Timing.clockTick0 + 1) *
        H8_1GDL_M->Timing.stepSize0 + H8_1GDL_M->Timing.clockTickH0 *
        H8_1GDL_M->Timing.stepSize0 * 4294967296.0));
    }

    /* Update the flag to indicate when data transfers from
     *  Sample time: [0.00025s, 0.0s] to Sample time: [0.0005s, 0.0s]  */
    (H8_1GDL_M->Timing.RateInteraction.TID1_2)++;
    if ((H8_1GDL_M->Timing.RateInteraction.TID1_2) > 1) {
      H8_1GDL_M->Timing.RateInteraction.TID1_2 = 0;
    }

    /* Update the flag to indicate when data transfers from
     *  Sample time: [0.00025s, 0.0s] to Sample time: [0.001s, 0.0s]  */
    (H8_1GDL_M->Timing.RateInteraction.TID1_3)++;
    if ((H8_1GDL_M->Timing.RateInteraction.TID1_3) > 3) {
      H8_1GDL_M->Timing.RateInteraction.TID1_3 = 0;
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(H8_1GDL_M)) {
    H8_1GDL_M->Timing.t[0] = rtsiGetT(&H8_1GDL_M->solverInfo);
  }

  /* Integrator: '<S108>/Integrator' */
  H8_1GDL_B.Integrator = H8_1GDL_X.Integrator_CSTATE;

  /* Sum: '<S108>/Sum' incorporates:
   *  Constant: '<S108>/Tamb'
   */
  H8_1GDL_B.Sum = H8_1GDL_B.Integrator + H8_1GDL_P.Tamb_Value;

  /* Integrator: '<Root>/Integrator5' */
  H8_1GDL_B.x = H8_1GDL_X.Integrator5_CSTATE;

  /* Saturate: '<Root>/suelo-techo' */
  u0 = H8_1GDL_B.x;
  u1 = H8_1GDL_P.techo;
  u2 = H8_1GDL_P.suelo;
  if (u0 > u2) {
    /* Saturate: '<Root>/suelo-techo' */
    H8_1GDL_B.suelotecho = u2;
  } else if (u0 < u1) {
    /* Saturate: '<Root>/suelo-techo' */
    H8_1GDL_B.suelotecho = u1;
  } else {
    /* Saturate: '<Root>/suelo-techo' */
    H8_1GDL_B.suelotecho = u0;
  }

  /* End of Saturate: '<Root>/suelo-techo' */

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<Root>/dist_sensor1'
   */
  H8_1GDL_B.zaxisposition = H8_1GDL_B.suelotecho + H8_1GDL_P.dist_sensor1_Value;
  if (rtmIsMajorTimeStep(H8_1GDL_M)) {
    /* Gain: '<Root>/Gain2' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    u0 = H8_1GDL_P.m / 4.0;

    /* Gain: '<Root>/Gain2' */
    H8_1GDL_B.Fg = H8_1GDL_P.g * u0;
  }

  /* Gain: '<S4>/To mm' */
  H8_1GDL_B.airgap = H8_1GDL_P.Tomm_Gain * H8_1GDL_B.suelotecho;

  /* Integrator: '<S109>/Integrator1' */
  H8_1GDL_B.currentapplied = H8_1GDL_X.Integrator1_CSTATE;

  /* Saturate: '<S4>/Saturation8' */
  u0 = H8_1GDL_B.currentapplied;
  u1 = H8_1GDL_P.Saturation8_LowerSat;
  u2 = H8_1GDL_P.Saturation8_UpperSat;
  if (u0 > u2) {
    /* Saturate: '<S4>/Saturation8' */
    H8_1GDL_B.I = u2;
  } else if (u0 < u1) {
    /* Saturate: '<S4>/Saturation8' */
    H8_1GDL_B.I = u1;
  } else {
    /* Saturate: '<S4>/Saturation8' */
    H8_1GDL_B.I = u0;
  }

  /* End of Saturate: '<S4>/Saturation8' */

  /* Lookup_n-D: '<S4>/2-D Lookup Table' incorporates:
   *  Gain: '<S4>/To mm'
   *  Saturate: '<S4>/Saturation8'
   */
  H8_1GDL_B.Fl = look2_binlxpw(H8_1GDL_B.airgap, H8_1GDL_B.I,
    H8_1GDL_P.uDLookupTable_bp01Data, H8_1GDL_P.hems.Current,
    H8_1GDL_P.hems.Force_Vertical, H8_1GDL_P.uDLookupTable_maxIndex, 14U);

  /* Sum: '<Root>/Add4' */
  H8_1GDL_B.F = H8_1GDL_B.Fg - H8_1GDL_B.Fl;

  /* RateTransition generated from: '<Root>/Add5' */
  if (rtmIsMajorTimeStep(H8_1GDL_M)) {
    if (H8_1GDL_M->Timing.RateInteraction.TID1_2 == 1) {
      H8_1GDL_DW.TmpRTBAtAdd5Inport1_RdBufIdx = static_cast<int8_T>
        (H8_1GDL_DW.TmpRTBAtAdd5Inport1_RdBufIdx == 0);
    }

    /* RateTransition generated from: '<Root>/Add5' */
    H8_1GDL_B.TmpRTBAtAdd5Inport1 =
      H8_1GDL_DW.TmpRTBAtAdd5Inport1_Buf[H8_1GDL_DW.TmpRTBAtAdd5Inport1_RdBufIdx];
  }

  /* End of RateTransition generated from: '<Root>/Add5' */

  /* Sum: '<Root>/Add5' */
  H8_1GDL_B.Add5 = H8_1GDL_B.TmpRTBAtAdd5Inport1 - H8_1GDL_B.I;
  if (rtmIsMajorTimeStep(H8_1GDL_M)) {
    /* RateTransition generated from: '<S1>/Scope1' */
    if (H8_1GDL_M->Timing.RateInteraction.TID1_3 == 1) {
      H8_1GDL_DW.senal_discretizada_RdBufIdx = static_cast<int8_T>
        (H8_1GDL_DW.senal_discretizada_RdBufIdx == 0);
    }

    /* RateTransition generated from: '<S1>/Scope1' */
    H8_1GDL_B.airgap_sensorI =
      H8_1GDL_DW.senal_discretizada_Buf[H8_1GDL_DW.senal_discretizada_RdBufIdx];

    /* RateTransition generated from: '<S1>/Zero-Order Hold' */
    if (H8_1GDL_M->Timing.RateInteraction.TID1_3 == 1) {
      H8_1GDL_DW.TmpRTBAtZeroOrderHoldInport1_Wr = static_cast<int8_T>
        (H8_1GDL_DW.TmpRTBAtZeroOrderHoldInport1_Wr == 0);
    }

    H8_1GDL_DW.TmpRTBAtZeroOrderHoldInport1_Bu[H8_1GDL_DW.TmpRTBAtZeroOrderHoldInport1_Wr]
      = H8_1GDL_B.zaxisposition;

    /* End of RateTransition generated from: '<S1>/Zero-Order Hold' */
  }

  /* Product: '<Root>/Divide2' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  u0 = H8_1GDL_P.m / 4.0;

  /* Product: '<Root>/Divide2' */
  H8_1GDL_B.Divide2 = 1.0 / u0 * H8_1GDL_B.F;

  /* Integrator: '<Root>/Integrator4' */
  H8_1GDL_B.v = H8_1GDL_X.Integrator4_CSTATE;
  if (rtmIsMajorTimeStep(H8_1GDL_M)) {
    /* Gain: '<S83>/Derivative Gain' */
    H8_1GDL_B.DerivativeGain = H8_1GDL_P.PIDController4_D * H8_1GDL_B.Add5;

    /* DataTypeConversion: '<S84>/Passthrough for tuning' incorporates:
     *  Constant: '<S93>/N Copy'
     */
    H8_1GDL_B.Passthroughfortuning = H8_1GDL_P.PIDController4_N;

    /* SampleTimeMath: '<S86>/Tsamp'
     *
     * About '<S86>/Tsamp':
     *  y = u * K where K = ( w * Ts )
     */
    H8_1GDL_B.Tsamp = H8_1GDL_B.Passthroughfortuning * H8_1GDL_P.Tsamp_WtEt;

    /* Sum: '<S84>/SumDen' incorporates:
     *  Constant: '<S84>/Filter Den Constant'
     */
    H8_1GDL_B.SumDen = H8_1GDL_P.FilterDenConstant_Value_n + H8_1GDL_B.Tsamp;

    /* Math: '<S84>/Reciprocal'
     *
     * About '<S84>/Reciprocal':
     *  Operator: reciprocal
     */
    u0 = H8_1GDL_B.SumDen;

    /* Math: '<S84>/Reciprocal'
     *
     * About '<S84>/Reciprocal':
     *  Operator: reciprocal
     */
    H8_1GDL_B.Reciprocal = 1.0 / u0;

    /* Sum: '<S84>/SumNum' incorporates:
     *  Constant: '<S84>/Filter Den Constant'
     */
    H8_1GDL_B.SumNum = H8_1GDL_B.Tsamp - H8_1GDL_P.FilterDenConstant_Value_n;

    /* Product: '<S84>/Divide' */
    H8_1GDL_B.Divide = H8_1GDL_B.Reciprocal * H8_1GDL_B.SumNum;

    /* SignalConversion generated from: '<S84>/Filter Differentiator TF' incorporates:
     *  Constant: '<S84>/Filter Den Constant'
     */
    H8_1GDL_B.TmpSignalConversionAtFilterDiff[0] =
      H8_1GDL_P.FilterDenConstant_Value_n;
    H8_1GDL_B.TmpSignalConversionAtFilterDiff[1] = H8_1GDL_B.Divide;

    /* DiscreteTransferFcn: '<S84>/Filter Differentiator TF' */
    u0 = H8_1GDL_B.DerivativeGain;
    u0 -= H8_1GDL_B.TmpSignalConversionAtFilterDiff[1] *
      H8_1GDL_DW.FilterDifferentiatorTF_states;
    H8_1GDL_DW.FilterDifferentiatorTF_tmp = u0;
    u0 = H8_1GDL_P.FilterDifferentiatorTF_NumCoef[0] *
      H8_1GDL_DW.FilterDifferentiatorTF_tmp;
    u0 += H8_1GDL_P.FilterDifferentiatorTF_NumCoef[1] *
      H8_1GDL_DW.FilterDifferentiatorTF_states;

    /* DiscreteTransferFcn: '<S84>/Filter Differentiator TF' */
    H8_1GDL_B.FilterDifferentiatorTF = u0;

    /* Product: '<S84>/DenCoefOut' */
    H8_1GDL_B.DenCoefOut = H8_1GDL_B.FilterDifferentiatorTF *
      H8_1GDL_B.Reciprocal;

    /* Gain: '<S88>/Integral Gain' */
    H8_1GDL_B.IntegralGain = H8_1GDL_P.PIDController4_I * H8_1GDL_B.Add5;

    /* DiscreteIntegrator: '<S91>/Integrator' */
    H8_1GDL_B.Integrator_c = H8_1GDL_P.Integrator_gainval *
      H8_1GDL_B.IntegralGain + H8_1GDL_DW.Integrator_DSTATE;

    /* Gain: '<S94>/Filter Coefficient' */
    H8_1GDL_B.FilterCoefficient = H8_1GDL_P.PIDController4_N *
      H8_1GDL_B.DenCoefOut;

    /* Gain: '<S96>/Proportional Gain' */
    H8_1GDL_B.ProportionalGain = H8_1GDL_P.PIDController4_P * H8_1GDL_B.Add5;

    /* Sum: '<S100>/Sum' */
    H8_1GDL_B.Sum_f = (H8_1GDL_B.ProportionalGain + H8_1GDL_B.Integrator_c) +
      H8_1GDL_B.FilterCoefficient;

    /* Saturate: '<Root>/Saturation1' */
    u0 = H8_1GDL_B.Sum_f;
    u1 = H8_1GDL_P.Saturation1_LowerSat;
    u2 = H8_1GDL_P.Saturation1_UpperSat;
    if (u0 > u2) {
      /* Saturate: '<Root>/Saturation1' */
      H8_1GDL_B.vs = u2;
    } else if (u0 < u1) {
      /* Saturate: '<Root>/Saturation1' */
      H8_1GDL_B.vs = u1;
    } else {
      /* Saturate: '<Root>/Saturation1' */
      H8_1GDL_B.vs = u0;
    }

    /* End of Saturate: '<Root>/Saturation1' */
    /* Product: '<S108>/Product2' incorporates:
     *  Constant: '<S108>/coeficiente_transferencia'
     *  Constant: '<S108>/densidad'
     */
    H8_1GDL_B.Product2 = H8_1GDL_P.densidad_Value *
      H8_1GDL_P.coeficiente_transferencia_Value;
  }

  /* Lookup_n-D: '<S4>/2-D Lookup Table1' incorporates:
   *  Gain: '<S4>/To mm'
   *  Saturate: '<S4>/Saturation8'
   */
  H8_1GDL_B.Fl_m = look2_binlxpw(H8_1GDL_B.airgap, H8_1GDL_B.I,
    H8_1GDL_P.uDLookupTable1_bp01Data, H8_1GDL_P.hems.Current,
    H8_1GDL_P.hems.Force_Horizontal, H8_1GDL_P.uDLookupTable1_maxIndex, 14U);

  /* Product: '<S108>/Divide' incorporates:
   *  Constant: '<S108>/Seccion'
   */
  H8_1GDL_B.Divide_p = H8_1GDL_B.I / H8_1GDL_P.Seccion_Value;

  /* Math: '<S108>/Math Function'
   *
   * About '<S108>/Math Function':
   *  Operator: magnitude^2
   */
  u0 = H8_1GDL_B.Divide_p;

  /* Math: '<S108>/Math Function'
   *
   * About '<S108>/Math Function':
   *  Operator: magnitude^2
   */
  H8_1GDL_B.MathFunction = u0 * u0;

  /* Sum: '<S108>/Sum1' incorporates:
   *  Constant: '<S108>/Tref'
   */
  H8_1GDL_B.Sum1 = H8_1GDL_B.Sum - H8_1GDL_P.Tref_Value;

  /* Gain: '<S108>/masa_bobina' */
  H8_1GDL_B.masa_bobina = H8_1GDL_P.hems.masa_bobina * H8_1GDL_B.Sum1;

  /* Sum: '<S108>/Sum2' incorporates:
   *  Constant: '<S108>/Constant'
   */
  H8_1GDL_B.Sum2 = H8_1GDL_B.masa_bobina + H8_1GDL_P.Constant_Value;

  /* Product: '<S108>/Product1' incorporates:
   *  Constant: '<S108>/resistividad'
   */
  H8_1GDL_B.Product1 = H8_1GDL_P.resistividad_Value * H8_1GDL_B.Sum2;

  /* Product: '<S108>/Product' */
  H8_1GDL_B.Product = H8_1GDL_B.MathFunction * H8_1GDL_B.Product1;

  /* Product: '<S108>/Divide1' */
  H8_1GDL_B.Divide1 = H8_1GDL_B.Product / H8_1GDL_B.Product2;
  if (rtmIsMajorTimeStep(H8_1GDL_M)) {
    /* Delay: '<S109>/Delay' */
    H8_1GDL_B.Delay = H8_1GDL_DW.Delay_DSTATE;

    /* Delay: '<S109>/Delay1' */
    H8_1GDL_B.Delay1 = H8_1GDL_DW.Delay1_DSTATE;

    /* Lookup_n-D: '<S109>/2-D Lookup Table' */
    for (int32_T i = 0; i < 109; i++) {
      tmp[i] = H8_1GDL_P.hems.Current[static_cast<int32_T>
        (H8_1GDL_ConstP.uDLookupTable_rtw_collapsed_sub[i]) - 1];
    }

    /* Lookup_n-D: '<S109>/2-D Lookup Table' incorporates:
     *  Delay: '<S109>/Delay'
     *  Delay: '<S109>/Delay1'
     */
    H8_1GDL_B.L = look2_binlxpw(H8_1GDL_B.Delay, H8_1GDL_B.Delay1,
      H8_1GDL_P.hems.Airgap, tmp, H8_1GDL_P.hems.Inductance,
      H8_1GDL_P.uDLookupTable_maxIndex_d, 14U);

    /* Product: '<S109>/Divide1' incorporates:
     *  Constant: '<S110>/Resistance'
     */
    H8_1GDL_B.current = H8_1GDL_B.vs / H8_1GDL_P.hems.Resistance;

    /* Delay: '<S109>/Delay2' */
    H8_1GDL_B.Delay2 = H8_1GDL_DW.Delay2_DSTATE;

    /* Delay: '<S109>/Delay3' */
    H8_1GDL_B.Delay3 = H8_1GDL_DW.Delay3_DSTATE;

    /* Product: '<S109>/Divide2' incorporates:
     *  Constant: '<S110>/Resistance'
     */
    H8_1GDL_B.Divide2_h = H8_1GDL_B.L / H8_1GDL_P.hems.Resistance;
  }

  /* Sum: '<S109>/Add' */
  H8_1GDL_B.Add = H8_1GDL_B.current - H8_1GDL_B.currentapplied;

  /* Product: '<S109>/Divide' */
  H8_1GDL_B.Divide_f = H8_1GDL_B.Add / H8_1GDL_B.Divide2_h;
  if (rtmIsMajorTimeStep(H8_1GDL_M)) {
    if (rtmIsMajorTimeStep(H8_1GDL_M)) {
      /* Update for DiscreteTransferFcn: '<S84>/Filter Differentiator TF' */
      H8_1GDL_DW.FilterDifferentiatorTF_states =
        H8_1GDL_DW.FilterDifferentiatorTF_tmp;

      /* Update for DiscreteIntegrator: '<S91>/Integrator' */
      H8_1GDL_DW.Integrator_DSTATE = H8_1GDL_P.Integrator_gainval *
        H8_1GDL_B.IntegralGain + H8_1GDL_B.Integrator_c;

      /* Update for Delay: '<S109>/Delay' */
      H8_1GDL_DW.Delay_DSTATE = H8_1GDL_B.airgap;

      /* Update for Delay: '<S109>/Delay1' */
      H8_1GDL_DW.Delay1_DSTATE = H8_1GDL_B.currentapplied;

      /* Update for Delay: '<S109>/Delay2' incorporates:
       *  Constant: '<Root>/Temperature'
       */
      H8_1GDL_DW.Delay2_DSTATE = H8_1GDL_P.Temperature_Value;

      /* Update for Delay: '<S109>/Delay3' */
      H8_1GDL_DW.Delay3_DSTATE = H8_1GDL_B.currentapplied;
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(H8_1GDL_M)) {
    rt_ertODEUpdateContinuousStates(&H8_1GDL_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++H8_1GDL_M->Timing.clockTick0)) {
      ++H8_1GDL_M->Timing.clockTickH0;
    }

    H8_1GDL_M->Timing.t[0] = rtsiGetSolverStopTime(&H8_1GDL_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.00025, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    H8_1GDL_M->Timing.clockTick1++;
    if (!H8_1GDL_M->Timing.clockTick1) {
      H8_1GDL_M->Timing.clockTickH1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void H8_1GDL_derivatives(void)
{
  XDot_H8_1GDL_T *_rtXdot;
  _rtXdot = ((XDot_H8_1GDL_T *) H8_1GDL_M->derivs);

  /* Derivatives for Integrator: '<S108>/Integrator' */
  _rtXdot->Integrator_CSTATE = H8_1GDL_B.Divide1;

  /* Derivatives for Integrator: '<Root>/Integrator5' */
  _rtXdot->Integrator5_CSTATE = H8_1GDL_B.v;

  /* Derivatives for Integrator: '<S109>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = H8_1GDL_B.Divide_f;

  /* Derivatives for Integrator: '<Root>/Integrator4' */
  _rtXdot->Integrator4_CSTATE = H8_1GDL_B.Divide2;
}

/* Model step function for TID2 */
void H8_1GDL_step2(void)               /* Sample time: [0.0005s, 0.0s] */
{
  real_T denAccum;
  real_T u1;
  real_T u2;

  /* Update the flag to indicate when data transfers from
   *  Sample time: [0.0005s, 0.0s] to Sample time: [0.001s, 0.0s]  */
  (H8_1GDL_M->Timing.RateInteraction.TID2_3)++;
  if ((H8_1GDL_M->Timing.RateInteraction.TID2_3) > 1) {
    H8_1GDL_M->Timing.RateInteraction.TID2_3 = 0;
  }

  /* RateTransition generated from: '<Root>/Sum1' */
  if (H8_1GDL_M->Timing.RateInteraction.TID2_3 == 1) {
    H8_1GDL_DW.TmpRTBAtSum1Outport1_RdBufIdx = static_cast<int8_T>
      (H8_1GDL_DW.TmpRTBAtSum1Outport1_RdBufIdx == 0);
  }

  /* RateTransition generated from: '<Root>/Sum1' */
  H8_1GDL_B.TmpRTBAtSum1Outport1 =
    H8_1GDL_DW.TmpRTBAtSum1Outport1_Buf[H8_1GDL_DW.TmpRTBAtSum1Outport1_RdBufIdx];

  /* Gain: '<S33>/Derivative Gain' */
  H8_1GDL_B.DerivativeGain_a = H8_1GDL_P.PIDController3_D *
    H8_1GDL_B.TmpRTBAtSum1Outport1;

  /* DataTypeConversion: '<S34>/Passthrough for tuning' incorporates:
   *  Constant: '<S43>/N Copy'
   */
  H8_1GDL_B.Passthroughfortuning_f = H8_1GDL_P.PIDController3_N;

  /* SampleTimeMath: '<S36>/Tsamp'
   *
   * About '<S36>/Tsamp':
   *  y = u * K where K = ( w * Ts )
   */
  H8_1GDL_B.Tsamp_e = H8_1GDL_B.Passthroughfortuning_f * H8_1GDL_P.Tsamp_WtEt_n;

  /* Sum: '<S34>/SumDen' incorporates:
   *  Constant: '<S34>/Filter Den Constant'
   */
  H8_1GDL_B.SumDen_k = H8_1GDL_P.FilterDenConstant_Value + H8_1GDL_B.Tsamp_e;

  /* Math: '<S34>/Reciprocal'
   *
   * About '<S34>/Reciprocal':
   *  Operator: reciprocal
   */
  denAccum = H8_1GDL_B.SumDen_k;

  /* Math: '<S34>/Reciprocal'
   *
   * About '<S34>/Reciprocal':
   *  Operator: reciprocal
   */
  H8_1GDL_B.Reciprocal_n = 1.0 / denAccum;

  /* Sum: '<S34>/SumNum' incorporates:
   *  Constant: '<S34>/Filter Den Constant'
   */
  H8_1GDL_B.SumNum_h = H8_1GDL_B.Tsamp_e - H8_1GDL_P.FilterDenConstant_Value;

  /* Product: '<S34>/Divide' */
  H8_1GDL_B.Divide_g = H8_1GDL_B.Reciprocal_n * H8_1GDL_B.SumNum_h;

  /* SignalConversion generated from: '<S34>/Filter Differentiator TF' incorporates:
   *  Constant: '<S34>/Filter Den Constant'
   */
  H8_1GDL_B.TmpSignalConversionAtFilterDi_n[0] =
    H8_1GDL_P.FilterDenConstant_Value;
  H8_1GDL_B.TmpSignalConversionAtFilterDi_n[1] = H8_1GDL_B.Divide_g;

  /* DiscreteTransferFcn: '<S34>/Filter Differentiator TF' */
  denAccum = H8_1GDL_B.DerivativeGain_a;
  denAccum -= H8_1GDL_B.TmpSignalConversionAtFilterDi_n[1] *
    H8_1GDL_DW.FilterDifferentiatorTF_states_h;
  H8_1GDL_DW.FilterDifferentiatorTF_tmp_e = denAccum;
  denAccum = H8_1GDL_P.FilterDifferentiatorTF_NumCoe_d[0] *
    H8_1GDL_DW.FilterDifferentiatorTF_tmp_e;
  denAccum += H8_1GDL_P.FilterDifferentiatorTF_NumCoe_d[1] *
    H8_1GDL_DW.FilterDifferentiatorTF_states_h;

  /* DiscreteTransferFcn: '<S34>/Filter Differentiator TF' */
  H8_1GDL_B.FilterDifferentiatorTF_a = denAccum;

  /* Product: '<S34>/DenCoefOut' */
  H8_1GDL_B.DenCoefOut_a = H8_1GDL_B.FilterDifferentiatorTF_a *
    H8_1GDL_B.Reciprocal_n;

  /* Gain: '<S38>/Integral Gain' */
  H8_1GDL_B.IntegralGain_e = H8_1GDL_P.PIDController3_I *
    H8_1GDL_B.TmpRTBAtSum1Outport1;

  /* DiscreteIntegrator: '<S41>/Integrator' */
  H8_1GDL_B.Integrator_n = H8_1GDL_P.Integrator_gainval_d *
    H8_1GDL_B.IntegralGain_e + H8_1GDL_DW.Integrator_DSTATE_i;

  /* Gain: '<S44>/Filter Coefficient' */
  H8_1GDL_B.FilterCoefficient_a = H8_1GDL_P.PIDController3_N *
    H8_1GDL_B.DenCoefOut_a;

  /* Gain: '<S46>/Proportional Gain' */
  H8_1GDL_B.ProportionalGain_g = H8_1GDL_P.PIDController3_P *
    H8_1GDL_B.TmpRTBAtSum1Outport1;

  /* Sum: '<S50>/Sum' */
  H8_1GDL_B.Sum_e = (H8_1GDL_B.ProportionalGain_g + H8_1GDL_B.Integrator_n) +
    H8_1GDL_B.FilterCoefficient_a;

  /* Saturate: '<Root>/Saturation6' */
  denAccum = H8_1GDL_B.Sum_e;
  u1 = H8_1GDL_P.Saturation6_LowerSat;
  u2 = H8_1GDL_P.Saturation6_UpperSat;
  if (denAccum > u2) {
    /* Saturate: '<Root>/Saturation6' */
    H8_1GDL_B.Saturation6 = u2;
  } else if (denAccum < u1) {
    /* Saturate: '<Root>/Saturation6' */
    H8_1GDL_B.Saturation6 = u1;
  } else {
    /* Saturate: '<Root>/Saturation6' */
    H8_1GDL_B.Saturation6 = denAccum;
  }

  /* End of Saturate: '<Root>/Saturation6' */

  /* RateTransition generated from: '<Root>/Add5' */
  H8_1GDL_DW.TmpRTBAtAdd5Inport1_WrBufIdx = static_cast<int8_T>
    (H8_1GDL_DW.TmpRTBAtAdd5Inport1_WrBufIdx == 0);
  H8_1GDL_DW.TmpRTBAtAdd5Inport1_Buf[H8_1GDL_DW.TmpRTBAtAdd5Inport1_WrBufIdx] =
    H8_1GDL_B.Saturation6;

  /* Update for DiscreteTransferFcn: '<S34>/Filter Differentiator TF' */
  H8_1GDL_DW.FilterDifferentiatorTF_states_h =
    H8_1GDL_DW.FilterDifferentiatorTF_tmp_e;

  /* Update for DiscreteIntegrator: '<S41>/Integrator' */
  H8_1GDL_DW.Integrator_DSTATE_i = H8_1GDL_P.Integrator_gainval_d *
    H8_1GDL_B.IntegralGain_e + H8_1GDL_B.Integrator_n;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.0005, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  H8_1GDL_M->Timing.clockTick2++;
  if (!H8_1GDL_M->Timing.clockTick2) {
    H8_1GDL_M->Timing.clockTickH2++;
  }
}

/* Model step function for TID3 */
void H8_1GDL_step3(void)               /* Sample time: [0.001s, 0.0s] */
{
  real_T valor_escalon;

  /* RateTransition generated from: '<S1>/Zero-Order Hold' */
  H8_1GDL_DW.TmpRTBAtZeroOrderHoldInport1_Rd = static_cast<int8_T>
    (H8_1GDL_DW.TmpRTBAtZeroOrderHoldInport1_Rd == 0);

  /* RateTransition generated from: '<S1>/Zero-Order Hold' */
  H8_1GDL_B.TmpRTBAtZeroOrderHoldInport1 =
    H8_1GDL_DW.TmpRTBAtZeroOrderHoldInport1_Bu[H8_1GDL_DW.TmpRTBAtZeroOrderHoldInport1_Rd];

  /* ZeroOrderHold: '<S1>/Zero-Order Hold' */
  H8_1GDL_B.ZeroOrderHold = H8_1GDL_B.TmpRTBAtZeroOrderHoldInport1;

  /* Delay: '<S6>/Delay' */
  H8_1GDL_B.Delay_j = H8_1GDL_DW.Delay_DSTATE_f[0];

  /* Sum: '<S6>/Sum' */
  H8_1GDL_B.Sum_p = H8_1GDL_B.ZeroOrderHold - H8_1GDL_B.Delay_j;

  /* Delay: '<S6>/Delay1' */
  H8_1GDL_B.Delay1_n = H8_1GDL_DW.Delay1_DSTATE_j;

  /* Sum: '<S6>/Sum1' */
  H8_1GDL_B.Sum1_a = H8_1GDL_B.Sum_p + H8_1GDL_B.Delay1_n;

  /* Gain: '<S6>/Gain' */
  valor_escalon = 1.0 / H8_1GDL_P.MovingAverageFilter_M;

  /* Gain: '<S6>/Gain' */
  H8_1GDL_B.Gain = valor_escalon * H8_1GDL_B.Sum1_a;

  /* MATLAB Function: '<S5>/MATLAB Function1' incorporates:
   *  Constant: '<S5>/Constant'
   *  Constant: '<S5>/Constant1'
   *  Constant: '<S5>/Constant2'
   */
  if (H8_1GDL_B.Gain > H8_1GDL_P.Discr_Ampl_Max) {
    H8_1GDL_B.senal_discretizada = H8_1GDL_P.Discr_Ampl_Max;
  } else if (H8_1GDL_B.Gain < H8_1GDL_P.Discr_Ampl_Min) {
    H8_1GDL_B.senal_discretizada = H8_1GDL_P.Discr_Ampl_Min;
  } else {
    real_T i;
    valor_escalon = (H8_1GDL_P.Discr_Ampl_Max - H8_1GDL_P.Discr_Ampl_Min) /
      (H8_1GDL_P.Discr_Ampl_N - 1.0);
    i = H8_1GDL_P.Discr_Ampl_Min;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if (i < H8_1GDL_P.Discr_Ampl_Max) {
        if (valor_escalon / 2.0 + i > H8_1GDL_B.Gain) {
          H8_1GDL_B.senal_discretizada = i;
          exitg1 = 1;
        } else {
          i += valor_escalon;
        }
      } else {
        H8_1GDL_B.senal_discretizada = H8_1GDL_P.Discr_Ampl_Max;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  /* End of MATLAB Function: '<S5>/MATLAB Function1' */
  /* RateTransition generated from: '<S1>/Scope1' */
  H8_1GDL_DW.senal_discretizada_WrBufIdx = static_cast<int8_T>
    (H8_1GDL_DW.senal_discretizada_WrBufIdx == 0);
  H8_1GDL_DW.senal_discretizada_Buf[H8_1GDL_DW.senal_discretizada_WrBufIdx] =
    H8_1GDL_B.senal_discretizada;

  /* Sum: '<Root>/Sum3' incorporates:
   *  Constant: '<Root>/dist_sensor'
   */
  H8_1GDL_B.Sum3 = H8_1GDL_B.senal_discretizada - H8_1GDL_P.dist_sensor_Value;

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<Root>/Constant'
   */
  H8_1GDL_B.Sum1_e = H8_1GDL_P.lev_nom - H8_1GDL_B.Sum3;

  /* RateTransition generated from: '<Root>/Sum1' */
  H8_1GDL_DW.TmpRTBAtSum1Outport1_WrBufIdx = static_cast<int8_T>
    (H8_1GDL_DW.TmpRTBAtSum1Outport1_WrBufIdx == 0);
  H8_1GDL_DW.TmpRTBAtSum1Outport1_Buf[H8_1GDL_DW.TmpRTBAtSum1Outport1_WrBufIdx] =
    H8_1GDL_B.Sum1_e;

  /* Update for Delay: '<S6>/Delay' */
  for (int_T idxDelay = 0; idxDelay < 5; idxDelay++) {
    H8_1GDL_DW.Delay_DSTATE_f[idxDelay] = H8_1GDL_DW.Delay_DSTATE_f[idxDelay + 1];
  }

  H8_1GDL_DW.Delay_DSTATE_f[5] = H8_1GDL_B.ZeroOrderHold;

  /* End of Update for Delay: '<S6>/Delay' */

  /* Update for Delay: '<S6>/Delay1' */
  H8_1GDL_DW.Delay1_DSTATE_j = H8_1GDL_B.Sum1_a;

  /* Update absolute time */
  /* The "clockTick3" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick3" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick3 and the high bits
   * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
   */
  H8_1GDL_M->Timing.clockTick3++;
  if (!H8_1GDL_M->Timing.clockTick3) {
    H8_1GDL_M->Timing.clockTickH3++;
  }
}

/* Model initialize function */
void H8_1GDL_initialize(void)
{
  /* Registration code */

  /* Set task counter limit used by the static main program */
  (H8_1GDL_M)->Timing.TaskCounters.cLimit[0] = 1;
  (H8_1GDL_M)->Timing.TaskCounters.cLimit[1] = 1;
  (H8_1GDL_M)->Timing.TaskCounters.cLimit[2] = 2;
  (H8_1GDL_M)->Timing.TaskCounters.cLimit[3] = 4;

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&H8_1GDL_M->solverInfo, &H8_1GDL_M->Timing.simTimeStep);
    rtsiSetTPtr(&H8_1GDL_M->solverInfo, &rtmGetTPtr(H8_1GDL_M));
    rtsiSetStepSizePtr(&H8_1GDL_M->solverInfo, &H8_1GDL_M->Timing.stepSize0);
    rtsiSetdXPtr(&H8_1GDL_M->solverInfo, &H8_1GDL_M->derivs);
    rtsiSetContStatesPtr(&H8_1GDL_M->solverInfo, (real_T **)
                         &H8_1GDL_M->contStates);
    rtsiSetNumContStatesPtr(&H8_1GDL_M->solverInfo,
      &H8_1GDL_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&H8_1GDL_M->solverInfo,
      &H8_1GDL_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&H8_1GDL_M->solverInfo,
      &H8_1GDL_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&H8_1GDL_M->solverInfo,
      &H8_1GDL_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&H8_1GDL_M->solverInfo, (&rtmGetErrorStatus(H8_1GDL_M)));
    rtsiSetRTModelPtr(&H8_1GDL_M->solverInfo, H8_1GDL_M);
  }

  rtsiSetSimTimeStep(&H8_1GDL_M->solverInfo, MAJOR_TIME_STEP);
  H8_1GDL_M->intgData.y = H8_1GDL_M->odeY;
  H8_1GDL_M->intgData.f[0] = H8_1GDL_M->odeF[0];
  H8_1GDL_M->intgData.f[1] = H8_1GDL_M->odeF[1];
  H8_1GDL_M->intgData.f[2] = H8_1GDL_M->odeF[2];
  H8_1GDL_M->intgData.f[3] = H8_1GDL_M->odeF[3];
  H8_1GDL_M->contStates = ((X_H8_1GDL_T *) &H8_1GDL_X);
  rtsiSetSolverData(&H8_1GDL_M->solverInfo, static_cast<void *>
                    (&H8_1GDL_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&H8_1GDL_M->solverInfo, false);
  rtsiSetSolverName(&H8_1GDL_M->solverInfo,"ode4");
  rtmSetTPtr(H8_1GDL_M, &H8_1GDL_M->Timing.tArray[0]);
  H8_1GDL_M->Timing.stepSize0 = 0.00025;

  /* block I/O */
  (void) std::memset((static_cast<void *>(&H8_1GDL_B)), 0,
                     sizeof(B_H8_1GDL_T));

  /* states (continuous) */
  {
    (void) std::memset(static_cast<void *>(&H8_1GDL_X), 0,
                       sizeof(X_H8_1GDL_T));
  }

  /* states (dwork) */
  (void) std::memset(static_cast<void *>(&H8_1GDL_DW), 0,
                     sizeof(DW_H8_1GDL_T));

  /* Start for RateTransition generated from: '<Root>/Add5' */
  H8_1GDL_B.TmpRTBAtAdd5Inport1 = H8_1GDL_P.TmpRTBAtAdd5Inport1_InitialCond;

  /* InitializeConditions for Integrator: '<S108>/Integrator' */
  H8_1GDL_X.Integrator_CSTATE = H8_1GDL_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator5' */
  H8_1GDL_X.Integrator5_CSTATE = H8_1GDL_P.suelo;

  /* InitializeConditions for Integrator: '<S109>/Integrator1' */
  H8_1GDL_X.Integrator1_CSTATE = H8_1GDL_P.Integrator1_IC;

  /* InitializeConditions for RateTransition generated from: '<Root>/Add5' */
  H8_1GDL_DW.TmpRTBAtAdd5Inport1_Buf[0] =
    H8_1GDL_P.TmpRTBAtAdd5Inport1_InitialCond;
  H8_1GDL_DW.TmpRTBAtAdd5Inport1_WrBufIdx = 0;
  H8_1GDL_DW.TmpRTBAtAdd5Inport1_RdBufIdx = 1;

  /* InitializeConditions for RateTransition generated from: '<S1>/Scope1' */
  H8_1GDL_DW.senal_discretizada_Buf[0] =
    H8_1GDL_P.senal_discretizada_InitialCondi;
  H8_1GDL_DW.senal_discretizada_WrBufIdx = 0;
  H8_1GDL_DW.senal_discretizada_RdBufIdx = 1;

  /* InitializeConditions for RateTransition generated from: '<S1>/Zero-Order Hold' */
  H8_1GDL_DW.TmpRTBAtZeroOrderHoldInport1_Bu[0] =
    H8_1GDL_P.TmpRTBAtZeroOrderHoldInport1_In;
  H8_1GDL_DW.TmpRTBAtZeroOrderHoldInport1_Wr = 0;
  H8_1GDL_DW.TmpRTBAtZeroOrderHoldInport1_Rd = 1;

  /* InitializeConditions for Integrator: '<Root>/Integrator4' */
  H8_1GDL_X.Integrator4_CSTATE = H8_1GDL_P.Integrator4_IC;

  /* InitializeConditions for DiscreteTransferFcn: '<S84>/Filter Differentiator TF' */
  H8_1GDL_DW.FilterDifferentiatorTF_states =
    H8_1GDL_P.PIDController4_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S91>/Integrator' */
  H8_1GDL_DW.Integrator_DSTATE = H8_1GDL_P.PIDController4_InitialConditi_d;

  /* InitializeConditions for Delay: '<S109>/Delay' */
  H8_1GDL_DW.Delay_DSTATE = H8_1GDL_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S109>/Delay1' */
  H8_1GDL_DW.Delay1_DSTATE = H8_1GDL_P.Delay1_InitialCondition;

  /* InitializeConditions for Delay: '<S109>/Delay2' */
  H8_1GDL_DW.Delay2_DSTATE = H8_1GDL_P.Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S109>/Delay3' */
  H8_1GDL_DW.Delay3_DSTATE = H8_1GDL_P.Delay3_InitialCondition;

  /* InitializeConditions for RateTransition generated from: '<Root>/Sum1' */
  H8_1GDL_DW.TmpRTBAtSum1Outport1_Buf[0] =
    H8_1GDL_P.TmpRTBAtSum1Outport1_InitialCon;
  H8_1GDL_DW.TmpRTBAtSum1Outport1_WrBufIdx = 0;
  H8_1GDL_DW.TmpRTBAtSum1Outport1_RdBufIdx = 1;

  /* InitializeConditions for DiscreteTransferFcn: '<S34>/Filter Differentiator TF' */
  H8_1GDL_DW.FilterDifferentiatorTF_states_h =
    H8_1GDL_P.PIDController3_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S41>/Integrator' */
  H8_1GDL_DW.Integrator_DSTATE_i = H8_1GDL_P.suelo;

  /* InitializeConditions for Delay: '<S6>/Delay' */
  for (int32_T i = 0; i < 6; i++) {
    H8_1GDL_DW.Delay_DSTATE_f[i] = H8_1GDL_P.Delay_InitialCondition_j;
  }

  /* End of InitializeConditions for Delay: '<S6>/Delay' */

  /* InitializeConditions for Delay: '<S6>/Delay1' */
  H8_1GDL_DW.Delay1_DSTATE_j = H8_1GDL_P.Delay1_InitialCondition_l;
}

/* Model terminate function */
void H8_1GDL_terminate(void)
{
  /* (no terminate code required) */
}
