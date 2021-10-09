#ifndef __c1_DEM_testbench_DACerrors_9lev_h__
#define __c1_DEM_testbench_DACerrors_9lev_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c1_ResolvedFunctionInfo
#define typedef_c1_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c1_ResolvedFunctionInfo;

#endif                                 /*typedef_c1_ResolvedFunctionInfo*/

#ifndef typedef_SFc1_DEM_testbench_DACerrors_9levInstanceStruct
#define typedef_SFc1_DEM_testbench_DACerrors_9levInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_DEM_testbench_DACerrors_9lev;
  real_T c1_ila_pointer[100];
  boolean_T c1_ila_pointer_not_empty;
} SFc1_DEM_testbench_DACerrors_9levInstanceStruct;

#endif                                 /*typedef_SFc1_DEM_testbench_DACerrors_9levInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c1_DEM_testbench_DACerrors_9lev_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_DEM_testbench_DACerrors_9lev_get_check_sum(mxArray *plhs[]);
extern void c1_DEM_testbench_DACerrors_9lev_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
