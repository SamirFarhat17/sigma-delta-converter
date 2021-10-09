#ifndef __c2_DEM_testbench_DACerrors_h__
#define __c2_DEM_testbench_DACerrors_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c2_ResolvedFunctionInfo
#define typedef_c2_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c2_ResolvedFunctionInfo;

#endif                                 /*typedef_c2_ResolvedFunctionInfo*/

#ifndef typedef_SFc2_DEM_testbench_DACerrorsInstanceStruct
#define typedef_SFc2_DEM_testbench_DACerrorsInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_DEM_testbench_DACerrors;
  real_T c2_dwa_pointer;
  boolean_T c2_dwa_pointer_not_empty;
} SFc2_DEM_testbench_DACerrorsInstanceStruct;

#endif                                 /*typedef_SFc2_DEM_testbench_DACerrorsInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_DEM_testbench_DACerrors_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_DEM_testbench_DACerrors_get_check_sum(mxArray *plhs[]);
extern void c2_DEM_testbench_DACerrors_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
