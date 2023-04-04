/*
 * RL_types.h
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

#ifndef RTW_HEADER_RL_types_h_
#define RTW_HEADER_RL_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_66wI9m9XKOeh3OoPuAXQCF_
#define DEFINED_TYPEDEF_FOR_struct_66wI9m9XKOeh3OoPuAXQCF_

struct struct_66wI9m9XKOeh3OoPuAXQCF
{
  real_T Airgap[14];
  real_T Current[111];
  real_T Force_Vertical[1554];
  real_T Flux[1554];
  real_T Force_Horizontal[1554];
  real_T Inductance[1526];
  real_T masa_bobina;
  real_T Resistance;
};

#endif

/* Parameters (default storage) */
typedef struct P_RL_T_ P_RL_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_RL_T RT_MODEL_RL_T;

#endif                                 /* RTW_HEADER_RL_types_h_ */
