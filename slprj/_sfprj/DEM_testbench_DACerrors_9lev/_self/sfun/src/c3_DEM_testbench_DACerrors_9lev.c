/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DEM_testbench_DACerrors_9lev_sfun.h"
#include "c3_DEM_testbench_DACerrors_9lev.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DEM_testbench_DACerrors_9lev_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c3_debug_family_names[8] = { "nargin", "nargout", "dacin",
  "rotflag", "numele", "elems", "scramcode", "dacout" };

/* Function Declarations */
static void initialize_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance);
static void initialize_params_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance);
static void enable_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance);
static void disable_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance);
static void set_sim_state_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance, const mxArray
   *c3_st);
static void finalize_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance);
static void sf_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance);
static void initSimStructsc3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance);
static void registerMessagesc3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance, const mxArray
   *c3_dacout, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_sum(SFc3_DEM_testbench_DACerrors_9levInstanceStruct
                     *chartInstance, real_T c3_x_data[8], int32_T c3_x_sizes[1]);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_c_emlrt_marshallIn
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_d_emlrt_marshallIn
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance, const mxArray
   *c3_b_is_active_c3_DEM_testbench_DACerrors_9lev, const char_T *c3_identifier);
static uint8_T c3_e_emlrt_marshallIn
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c3_is_active_c3_DEM_testbench_DACerrors_9lev = 0U;
}

static void initialize_params_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance)
{
}

static void enable_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c3_update_debugger_state_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  uint8_T c3_b_hoistedGlobal;
  uint8_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T *c3_dacout;
  c3_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellarray(2), FALSE);
  c3_hoistedGlobal = *c3_dacout;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal =
    chartInstance->c3_is_active_c3_DEM_testbench_DACerrors_9lev;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  sf_mex_assign(&c3_st, c3_y, FALSE);
  return c3_st;
}

static void set_sim_state_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance, const mxArray
   *c3_st)
{
  const mxArray *c3_u;
  real_T *c3_dacout;
  c3_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c3_doneDoubleBufferReInit = TRUE;
  c3_u = sf_mex_dup(c3_st);
  *c3_dacout = c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u,
    0)), "dacout");
  chartInstance->c3_is_active_c3_DEM_testbench_DACerrors_9lev =
    c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)),
    "is_active_c3_DEM_testbench_DACerrors_9lev");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_DEM_testbench_DACerrors_9lev(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance)
{
}

static void sf_c3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance)
{
  int32_T c3_i0;
  int32_T c3_i1;
  uint8_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  uint8_T c3_dacin;
  real_T c3_rotflag;
  real_T c3_numele;
  int32_T c3_i2;
  real_T c3_elems[8];
  int32_T c3_i3;
  real_T c3_scramcode[8];
  uint32_T c3_debug_family_var_map[8];
  real_T c3_nargin = 5.0;
  real_T c3_nargout = 1.0;
  real_T c3_dacout;
  boolean_T c3_b0;
  boolean_T c3_b1;
  boolean_T c3_b2;
  int32_T c3_i4;
  int32_T c3_elems_sizes;
  int32_T c3_loop_ub;
  int32_T c3_i5;
  real_T c3_elems_data[8];
  boolean_T c3_b3;
  boolean_T c3_b4;
  boolean_T c3_b5;
  int32_T c3_i6;
  int32_T c3_b_elems_sizes;
  int32_T c3_b_loop_ub;
  int32_T c3_i7;
  real_T c3_b_elems_data[8];
  uint8_T *c3_b_dacin;
  real_T *c3_b_dacout;
  real_T *c3_b_rotflag;
  real_T *c3_b_numele;
  real_T (*c3_b_scramcode)[8];
  real_T (*c3_b_elems)[8];
  c3_b_scramcode = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 4);
  c3_b_elems = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 3);
  c3_b_numele = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c3_b_rotflag = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c3_b_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c3_b_dacin = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c3_b_dacin, 0U);
  _SFD_DATA_RANGE_CHECK(*c3_b_dacout, 1U);
  _SFD_DATA_RANGE_CHECK(*c3_b_rotflag, 2U);
  _SFD_DATA_RANGE_CHECK(*c3_b_numele, 3U);
  for (c3_i0 = 0; c3_i0 < 8; c3_i0++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_elems)[c3_i0], 4U);
  }

  for (c3_i1 = 0; c3_i1 < 8; c3_i1++) {
    _SFD_DATA_RANGE_CHECK((*c3_b_scramcode)[c3_i1], 5U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *c3_b_dacin;
  c3_b_hoistedGlobal = *c3_b_rotflag;
  c3_c_hoistedGlobal = *c3_b_numele;
  c3_dacin = c3_hoistedGlobal;
  c3_rotflag = c3_b_hoistedGlobal;
  c3_numele = c3_c_hoistedGlobal;
  for (c3_i2 = 0; c3_i2 < 8; c3_i2++) {
    c3_elems[c3_i2] = (*c3_b_elems)[c3_i2];
  }

  for (c3_i3 = 0; c3_i3 < 8; c3_i3++) {
    c3_scramcode[c3_i3] = (*c3_b_scramcode)[c3_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_dacin, 2U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_rotflag, 3U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_numele, 4U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_elems, 5U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_scramcode, 6U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_dacout, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 45);
  if (CV_EML_IF(0, 1, 0, c3_rotflag == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 46);
    c3_b0 = (1 > c3_dacin);
    c3_b1 = c3_b0;
    c3_b2 = c3_b1;
    if (c3_b2) {
      c3_i4 = 0;
    } else {
      c3_i4 = (uint8_T)_SFD_EML_ARRAY_BOUNDS_CHECK("elems", (int32_T)c3_dacin, 1,
        8, 0, 0);
    }

    c3_elems_sizes = c3_i4;
    c3_loop_ub = c3_i4 - 1;
    for (c3_i5 = 0; c3_i5 <= c3_loop_ub; c3_i5++) {
      c3_elems_data[c3_i5] = c3_elems[c3_i5];
    }

    c3_dacout = c3_sum(chartInstance, c3_elems_data, *(int32_T (*)[1])&
                       c3_elems_sizes);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 48);
    c3_b3 = (1 > c3_dacin);
    c3_b4 = c3_b3;
    c3_b5 = c3_b4;
    if (c3_b5) {
      c3_i6 = 0;
    } else {
      c3_i6 = (uint8_T)_SFD_EML_ARRAY_BOUNDS_CHECK("scramcode", (int32_T)
        c3_dacin, 1, 8, 0, 0);
    }

    c3_b_elems_sizes = c3_i6;
    c3_b_loop_ub = c3_i6 - 1;
    for (c3_i7 = 0; c3_i7 <= c3_b_loop_ub; c3_i7++) {
      c3_b_elems_data[c3_i7] = c3_elems[(int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("elems", (int32_T)_SFD_INTEGER_CHECK(
        "scramcode(1:dacin)", c3_scramcode[c3_i7]), 1, 8, 0, 0) - 1];
    }

    c3_dacout = c3_sum(chartInstance, c3_b_elems_data, *(int32_T (*)[1])&
                       c3_b_elems_sizes);
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -48);
  _SFD_SYMBOL_SCOPE_POP();
  *c3_b_dacout = c3_dacout;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DEM_testbench_DACerrors_9levMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance)
{
}

static void registerMessagesc3_DEM_testbench_DACerrors_9lev
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber)
{
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance;
  chartInstance = (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance, const mxArray
   *c3_dacout, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_dacout), &c3_thisId);
  sf_mex_destroy(&c3_dacout);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_dacout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance;
  chartInstance = (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *)
    chartInstanceVoid;
  c3_dacout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_dacout), &c3_thisId);
  sf_mex_destroy(&c3_dacout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i8;
  real_T c3_b_inData[8];
  int32_T c3_i9;
  real_T c3_u[8];
  const mxArray *c3_y = NULL;
  SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance;
  chartInstance = (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i8 = 0; c3_i8 < 8; c3_i8++) {
    c3_b_inData[c3_i8] = (*(real_T (*)[8])c3_inData)[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 8; c3_i9++) {
    c3_u[c3_i9] = c3_b_inData[c3_i9];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 8), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  uint8_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance;
  chartInstance = (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(uint8_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

const mxArray
  *sf_c3_DEM_testbench_DACerrors_9lev_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo;
  c3_ResolvedFunctionInfo c3_info[8];
  c3_ResolvedFunctionInfo (*c3_b_info)[8];
  const mxArray *c3_m0 = NULL;
  int32_T c3_i10;
  c3_ResolvedFunctionInfo *c3_r0;
  c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  c3_b_info = (c3_ResolvedFunctionInfo (*)[8])c3_info;
  (*c3_b_info)[0].context = "";
  (*c3_b_info)[0].name = "sum";
  (*c3_b_info)[0].dominantType = "double";
  (*c3_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c3_b_info)[0].fileTimeLo = 1442401494U;
  (*c3_b_info)[0].fileTimeHi = 0U;
  (*c3_b_info)[0].mFileTimeLo = 0U;
  (*c3_b_info)[0].mFileTimeHi = 0U;
  (*c3_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c3_b_info)[1].name = "isequal";
  (*c3_b_info)[1].dominantType = "double";
  (*c3_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  (*c3_b_info)[1].fileTimeLo = 1442401495U;
  (*c3_b_info)[1].fileTimeHi = 0U;
  (*c3_b_info)[1].mFileTimeLo = 0U;
  (*c3_b_info)[1].mFileTimeHi = 0U;
  (*c3_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  (*c3_b_info)[2].name = "eml_isequal_core";
  (*c3_b_info)[2].dominantType = "double";
  (*c3_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  (*c3_b_info)[2].fileTimeLo = 1442401497U;
  (*c3_b_info)[2].fileTimeHi = 0U;
  (*c3_b_info)[2].mFileTimeLo = 0U;
  (*c3_b_info)[2].mFileTimeHi = 0U;
  (*c3_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c3_b_info)[3].name = "eml_const_nonsingleton_dim";
  (*c3_b_info)[3].dominantType = "double";
  (*c3_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  (*c3_b_info)[3].fileTimeLo = 1442401497U;
  (*c3_b_info)[3].fileTimeHi = 0U;
  (*c3_b_info)[3].mFileTimeLo = 0U;
  (*c3_b_info)[3].mFileTimeHi = 0U;
  (*c3_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c3_b_info)[4].name = "eml_scalar_eg";
  (*c3_b_info)[4].dominantType = "double";
  (*c3_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c3_b_info)[4].fileTimeLo = 1442401497U;
  (*c3_b_info)[4].fileTimeHi = 0U;
  (*c3_b_info)[4].mFileTimeLo = 0U;
  (*c3_b_info)[4].mFileTimeHi = 0U;
  (*c3_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c3_b_info)[5].name = "eml_index_class";
  (*c3_b_info)[5].dominantType = "";
  (*c3_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c3_b_info)[5].fileTimeLo = 1442401497U;
  (*c3_b_info)[5].fileTimeHi = 0U;
  (*c3_b_info)[5].mFileTimeLo = 0U;
  (*c3_b_info)[5].mFileTimeHi = 0U;
  (*c3_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c3_b_info)[6].name = "eml_int_forloop_overflow_check";
  (*c3_b_info)[6].dominantType = "";
  (*c3_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  (*c3_b_info)[6].fileTimeLo = 1442401497U;
  (*c3_b_info)[6].fileTimeHi = 0U;
  (*c3_b_info)[6].mFileTimeLo = 0U;
  (*c3_b_info)[6].mFileTimeHi = 0U;
  (*c3_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  (*c3_b_info)[7].name = "intmax";
  (*c3_b_info)[7].dominantType = "char";
  (*c3_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  (*c3_b_info)[7].fileTimeLo = 1442401495U;
  (*c3_b_info)[7].fileTimeHi = 0U;
  (*c3_b_info)[7].mFileTimeLo = 0U;
  (*c3_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c3_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c3_i10 = 0; c3_i10 < 8; c3_i10++) {
    c3_r0 = &c3_info[c3_i10];
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->context)), "context", "nameCaptureInfo",
                    c3_i10);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c3_r0->name)), "name", "nameCaptureInfo", c3_i10);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c3_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c3_i10);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", c3_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c3_r0->resolved)), "resolved", "nameCaptureInfo",
                    c3_i10);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c3_i10);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c3_i10);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c3_i10);
    sf_mex_addfield(c3_m0, sf_mex_create("nameCaptureInfo", &c3_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c3_i10);
  }

  sf_mex_assign(&c3_nameCaptureInfo, c3_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static real_T c3_sum(SFc3_DEM_testbench_DACerrors_9levInstanceStruct
                     *chartInstance, real_T c3_x_data[8], int32_T c3_x_sizes[1])
{
  real_T c3_y;
  boolean_T c3_p;
  boolean_T c3_b_p;
  int32_T c3_k;
  real_T c3_b_k;
  real_T c3_d1;
  real_T c3_d2;
  boolean_T c3_b6;
  boolean_T c3_c_p;
  boolean_T c3_b7;
  int32_T c3_i11;
  static char_T c3_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 's', 'u', 'm', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l',
    'E', 'm', 'p', 't', 'y' };

  char_T c3_u[30];
  const mxArray *c3_b_y = NULL;
  boolean_T c3_b8;
  int32_T c3_i12;
  static char_T c3_cv1[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  char_T c3_b_u[36];
  const mxArray *c3_c_y = NULL;
  int32_T c3_vlen;
  int32_T c3_b_vlen;
  int32_T c3_c_k;
  int32_T c3_d_k;
  boolean_T guard1 = FALSE;
  int32_T exitg1;
  c3_p = FALSE;
  c3_b_p = FALSE;
  c3_k = 0;
  do {
    exitg1 = 0;
    if (c3_k < 2) {
      c3_b_k = 1.0 + (real_T)c3_k;
      c3_d1 = c3_b_k;
      if (c3_d1 <= 1.0) {
        c3_d2 = (real_T)c3_x_sizes[0];
      } else {
        c3_d2 = 1.0;
      }

      if (c3_d2 != 0.0) {
        exitg1 = 1;
      } else {
        c3_k++;
      }
    } else {
      c3_b_p = TRUE;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  c3_b6 = c3_b_p;
  c3_c_p = c3_b6;
  if (!c3_c_p) {
  } else {
    c3_p = TRUE;
  }

  c3_b7 = !c3_p;
  if (c3_b7) {
  } else {
    for (c3_i11 = 0; c3_i11 < 30; c3_i11++) {
      c3_u[c3_i11] = c3_cv0[c3_i11];
    }

    c3_b_y = NULL;
    sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
      14, c3_b_y));
  }

  guard1 = FALSE;
  if (c3_x_sizes[0] == 1) {
    guard1 = TRUE;
  } else if ((real_T)c3_x_sizes[0] != 1.0) {
    guard1 = TRUE;
  } else {
    c3_b8 = FALSE;
  }

  if (guard1 == TRUE) {
    c3_b8 = TRUE;
  }

  if (c3_b8) {
  } else {
    for (c3_i12 = 0; c3_i12 < 36; c3_i12++) {
      c3_b_u[c3_i12] = c3_cv1[c3_i12];
    }

    c3_c_y = NULL;
    sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 36),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
      14, c3_c_y));
  }

  if (c3_x_sizes[0] == 0) {
    c3_y = 0.0;
  } else {
    c3_vlen = (int32_T)(real_T)c3_x_sizes[0];
    c3_y = c3_x_data[0];
    c3_b_vlen = c3_vlen;
    for (c3_c_k = 2; c3_c_k <= c3_b_vlen; c3_c_k++) {
      c3_d_k = c3_c_k;
      c3_y += c3_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c3_d_k, 1, c3_x_sizes[0],
        1, 0) - 1];
    }
  }

  return c3_y;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance;
  chartInstance = (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, FALSE);
  return c3_mxArrayOutData;
}

static int32_T c3_c_emlrt_marshallIn
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i13;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i13, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i13;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance;
  chartInstance = (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *)
    chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_d_emlrt_marshallIn
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance, const mxArray
   *c3_b_is_active_c3_DEM_testbench_DACerrors_9lev, const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_DEM_testbench_DACerrors_9lev), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_DEM_testbench_DACerrors_9lev);
  return c3_y;
}

static uint8_T c3_e_emlrt_marshallIn
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance, const mxArray
   *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info
  (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_DEM_testbench_DACerrors_9lev_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3807072763U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1152407297U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(14922667U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1140845976U);
}

mxArray *sf_c3_DEM_testbench_DACerrors_9lev_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ZtHOCIPGQGiB7cS7GCYQyB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(8);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(8);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_DEM_testbench_DACerrors_9lev_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c3_DEM_testbench_DACerrors_9lev(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"dacout\",},{M[8],M[0],T\"is_active_c3_DEM_testbench_DACerrors_9lev\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_DEM_testbench_DACerrors_9lev_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance;
    chartInstance = (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DEM_testbench_DACerrors_9levMachineNumber_,
           3,
           1,
           1,
           6,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation
            (_DEM_testbench_DACerrors_9levMachineNumber_,
             chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _DEM_testbench_DACerrors_9levMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DEM_testbench_DACerrors_9levMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"dacin");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dacout");
          _SFD_SET_DATA_PROPS(2,1,1,0,"rotflag");
          _SFD_SET_DATA_PROPS(3,1,1,0,"numele");
          _SFD_SET_DATA_PROPS(4,1,1,0,"elems");
          _SFD_SET_DATA_PROPS(5,1,1,0,"scramcode");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1711);
        _SFD_CV_INIT_EML_IF(0,1,0,1601,1618,1653,1706);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 8;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          uint8_T *c3_dacin;
          real_T *c3_dacout;
          real_T *c3_rotflag;
          real_T *c3_numele;
          real_T (*c3_elems)[8];
          real_T (*c3_scramcode)[8];
          c3_scramcode = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 4);
          c3_elems = (real_T (*)[8])ssGetInputPortSignal(chartInstance->S, 3);
          c3_numele = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c3_rotflag = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c3_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c3_dacin = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c3_dacin);
          _SFD_SET_DATA_VALUE_PTR(1U, c3_dacout);
          _SFD_SET_DATA_VALUE_PTR(2U, c3_rotflag);
          _SFD_SET_DATA_VALUE_PTR(3U, c3_numele);
          _SFD_SET_DATA_VALUE_PTR(4U, *c3_elems);
          _SFD_SET_DATA_VALUE_PTR(5U, *c3_scramcode);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DEM_testbench_DACerrors_9levMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "tTMry2oiTvU7hw0hZxZiU";
}

static void sf_opaque_initialize_c3_DEM_testbench_DACerrors_9lev(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_DEM_testbench_DACerrors_9levInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_DEM_testbench_DACerrors_9lev
    ((SFc3_DEM_testbench_DACerrors_9levInstanceStruct*) chartInstanceVar);
  initialize_c3_DEM_testbench_DACerrors_9lev
    ((SFc3_DEM_testbench_DACerrors_9levInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_DEM_testbench_DACerrors_9lev(void
  *chartInstanceVar)
{
  enable_c3_DEM_testbench_DACerrors_9lev
    ((SFc3_DEM_testbench_DACerrors_9levInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_DEM_testbench_DACerrors_9lev(void
  *chartInstanceVar)
{
  disable_c3_DEM_testbench_DACerrors_9lev
    ((SFc3_DEM_testbench_DACerrors_9levInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_DEM_testbench_DACerrors_9lev(void
  *chartInstanceVar)
{
  sf_c3_DEM_testbench_DACerrors_9lev
    ((SFc3_DEM_testbench_DACerrors_9levInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c3_DEM_testbench_DACerrors_9lev
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c3_DEM_testbench_DACerrors_9lev
    ((SFc3_DEM_testbench_DACerrors_9levInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_DEM_testbench_DACerrors_9lev();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c3_DEM_testbench_DACerrors_9lev(SimStruct*
  S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c3_DEM_testbench_DACerrors_9lev();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c3_DEM_testbench_DACerrors_9lev
    ((SFc3_DEM_testbench_DACerrors_9levInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c3_DEM_testbench_DACerrors_9lev
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c3_DEM_testbench_DACerrors_9lev(S);
}

static void sf_opaque_set_sim_state_c3_DEM_testbench_DACerrors_9lev(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c3_DEM_testbench_DACerrors_9lev(S, st);
}

static void sf_opaque_terminate_c3_DEM_testbench_DACerrors_9lev(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_DEM_testbench_DACerrors_9levInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DEM_testbench_DACerrors_9lev_optimization_info();
    }

    finalize_c3_DEM_testbench_DACerrors_9lev
      ((SFc3_DEM_testbench_DACerrors_9levInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_DEM_testbench_DACerrors_9lev
    ((SFc3_DEM_testbench_DACerrors_9levInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_DEM_testbench_DACerrors_9lev(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c3_DEM_testbench_DACerrors_9lev
      ((SFc3_DEM_testbench_DACerrors_9levInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_DEM_testbench_DACerrors_9lev(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DEM_testbench_DACerrors_9lev_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,3,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1903371760U));
  ssSetChecksum1(S,(314083631U));
  ssSetChecksum2(S,(398332164U));
  ssSetChecksum3(S,(1763715890U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_DEM_testbench_DACerrors_9lev(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_DEM_testbench_DACerrors_9lev(SimStruct *S)
{
  SFc3_DEM_testbench_DACerrors_9levInstanceStruct *chartInstance;
  chartInstance = (SFc3_DEM_testbench_DACerrors_9levInstanceStruct *)utMalloc
    (sizeof(SFc3_DEM_testbench_DACerrors_9levInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc3_DEM_testbench_DACerrors_9levInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_DEM_testbench_DACerrors_9lev;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_DEM_testbench_DACerrors_9lev;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_DEM_testbench_DACerrors_9lev;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_DEM_testbench_DACerrors_9lev;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_DEM_testbench_DACerrors_9lev;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_DEM_testbench_DACerrors_9lev;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_DEM_testbench_DACerrors_9lev;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_DEM_testbench_DACerrors_9lev;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_DEM_testbench_DACerrors_9lev;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_DEM_testbench_DACerrors_9lev;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_DEM_testbench_DACerrors_9lev;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c3_DEM_testbench_DACerrors_9lev_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_DEM_testbench_DACerrors_9lev(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_DEM_testbench_DACerrors_9lev(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_DEM_testbench_DACerrors_9lev(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_DEM_testbench_DACerrors_9lev_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
