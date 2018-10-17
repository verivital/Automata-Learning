#ifndef __c3_ESTbouncing_h__
#define __c3_ESTbouncing_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_ESTbouncingInstanceStruct
#define typedef_SFc3_ESTbouncingInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  uint8_T c3_tp_S1;
  uint8_T c3_tp_S2;
  uint8_T c3_is_active_c3_ESTbouncing;
  uint8_T c3_is_c3_ESTbouncing;
  real_T c3_A1[4];
  real_T c3_Bc[2];
  real_T c3_x[2];
  boolean_T c3_dataWrittenToVector[4];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_fEmlrtCtx;
  real_T (*c3_out)[2];
} SFc3_ESTbouncingInstanceStruct;

#endif                                 /*typedef_SFc3_ESTbouncingInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_ESTbouncing_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_ESTbouncing_get_check_sum(mxArray *plhs[]);
extern void c3_ESTbouncing_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
