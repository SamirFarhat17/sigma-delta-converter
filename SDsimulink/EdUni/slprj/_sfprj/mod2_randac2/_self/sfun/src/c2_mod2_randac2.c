/* Include files */

#include <stddef.h>
#include "blas.h"
#include "mod2_randac2_sfun.h"
#include "c2_mod2_randac2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "mod2_randac2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[8] = { "nargin", "nargout", "dacin",
  "rotflag", "numele", "elems", "scramcode", "dacout" };

/* Function Declarations */
static void initialize_c2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance);
static void initialize_params_c2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance);
static void enable_c2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance);
static void disable_c2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_mod2_randac2
  (SFc2_mod2_randac2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_mod2_randac2
  (SFc2_mod2_randac2InstanceStruct *chartInstance);
static void set_sim_state_c2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance);
static void sf_c2_mod2_randac2(SFc2_mod2_randac2InstanceStruct *chartInstance);
static void initSimStructsc2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance);
static void registerMessagesc2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static real_T c2_emlrt_marshallIn(SFc2_mod2_randac2InstanceStruct *chartInstance,
  const mxArray *c2_dacout, const char_T *c2_identifier);
static real_T c2_b_emlrt_marshallIn(SFc2_mod2_randac2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_sum(SFc2_mod2_randac2InstanceStruct *chartInstance, real_T
                     c2_x_data[4], int32_T c2_x_sizes[1]);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_c_emlrt_marshallIn(SFc2_mod2_randac2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_d_emlrt_marshallIn(SFc2_mod2_randac2InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_mod2_randac2, const char_T
  *c2_identifier);
static uint8_T c2_e_emlrt_marshallIn(SFc2_mod2_randac2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_mod2_randac2InstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_mod2_randac2 = 0U;
}

static void initialize_params_c2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance)
{
}

static void enable_c2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_mod2_randac2
  (SFc2_mod2_randac2InstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_mod2_randac2
  (SFc2_mod2_randac2InstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint8_T c2_b_hoistedGlobal;
  uint8_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  real_T *c2_dacout;
  c2_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  c2_hoistedGlobal = *c2_dacout;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_is_active_c2_mod2_randac2;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T *c2_dacout;
  c2_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_dacout = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u,
    0)), "dacout");
  chartInstance->c2_is_active_c2_mod2_randac2 = c2_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_mod2_randac2");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_mod2_randac2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance)
{
}

static void sf_c2_mod2_randac2(SFc2_mod2_randac2InstanceStruct *chartInstance)
{
  int32_T c2_i0;
  int32_T c2_i1;
  uint8_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  uint8_T c2_dacin;
  real_T c2_rotflag;
  real_T c2_numele;
  int32_T c2_i2;
  real_T c2_elems[4];
  int32_T c2_i3;
  real_T c2_scramcode[3];
  uint32_T c2_debug_family_var_map[8];
  real_T c2_nargin = 5.0;
  real_T c2_nargout = 1.0;
  real_T c2_dacout;
  boolean_T c2_b0;
  boolean_T c2_b1;
  boolean_T c2_b2;
  int32_T c2_i4;
  int32_T c2_elems_sizes;
  int32_T c2_loop_ub;
  int32_T c2_i5;
  real_T c2_elems_data[4];
  boolean_T c2_b3;
  boolean_T c2_b4;
  boolean_T c2_b5;
  int32_T c2_i6;
  int32_T c2_b_elems_sizes;
  int32_T c2_b_loop_ub;
  int32_T c2_i7;
  real_T c2_b_elems_data[3];
  uint8_T *c2_b_dacin;
  real_T *c2_b_dacout;
  real_T *c2_b_rotflag;
  real_T *c2_b_numele;
  real_T (*c2_b_scramcode)[3];
  real_T (*c2_b_elems)[4];
  c2_b_scramcode = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
  c2_b_elems = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_numele = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_rotflag = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_dacin = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_b_dacin, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_b_dacout, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_b_rotflag, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_b_numele, 3U);
  for (c2_i0 = 0; c2_i0 < 4; c2_i0++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_elems)[c2_i0], 4U);
  }

  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    _SFD_DATA_RANGE_CHECK((*c2_b_scramcode)[c2_i1], 5U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_dacin;
  c2_b_hoistedGlobal = *c2_b_rotflag;
  c2_c_hoistedGlobal = *c2_b_numele;
  c2_dacin = c2_hoistedGlobal;
  c2_rotflag = c2_b_hoistedGlobal;
  c2_numele = c2_c_hoistedGlobal;
  for (c2_i2 = 0; c2_i2 < 4; c2_i2++) {
    c2_elems[c2_i2] = (*c2_b_elems)[c2_i2];
  }

  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    c2_scramcode[c2_i3] = (*c2_b_scramcode)[c2_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_dacin, 2U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_rotflag, 3U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_numele, 4U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_elems, 5U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_scramcode, 6U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dacout, 7U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
  if (CV_EML_IF(0, 1, 0, c2_rotflag == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
    c2_b0 = (1 > c2_dacin);
    c2_b1 = c2_b0;
    c2_b2 = c2_b1;
    if (c2_b2) {
      c2_i4 = 0;
    } else {
      c2_i4 = (uint8_T)_SFD_EML_ARRAY_BOUNDS_CHECK("elems", (int32_T)c2_dacin, 1,
        4, 0, 0);
    }

    c2_elems_sizes = c2_i4;
    c2_loop_ub = c2_i4 - 1;
    for (c2_i5 = 0; c2_i5 <= c2_loop_ub; c2_i5++) {
      c2_elems_data[c2_i5] = c2_elems[c2_i5];
    }

    c2_dacout = c2_sum(chartInstance, c2_elems_data, *(int32_T (*)[1])&
                       c2_elems_sizes);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 48);
    c2_b3 = (1 > c2_dacin);
    c2_b4 = c2_b3;
    c2_b5 = c2_b4;
    if (c2_b5) {
      c2_i6 = 0;
    } else {
      c2_i6 = (uint8_T)_SFD_EML_ARRAY_BOUNDS_CHECK("scramcode", (int32_T)
        c2_dacin, 1, 3, 0, 0);
    }

    c2_b_elems_sizes = c2_i6;
    c2_b_loop_ub = c2_i6 - 1;
    for (c2_i7 = 0; c2_i7 <= c2_b_loop_ub; c2_i7++) {
      c2_b_elems_data[c2_i7] = c2_elems[(int32_T)(real_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("elems", (int32_T)_SFD_INTEGER_CHECK(
        "scramcode(1:dacin)", c2_scramcode[c2_i7]), 1, 4, 0, 0) - 1];
    }

    c2_dacout = c2_sum(chartInstance, c2_b_elems_data, *(int32_T (*)[1])&
                       c2_b_elems_sizes);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -48);
  _SFD_SYMBOL_SCOPE_POP();
  *c2_b_dacout = c2_dacout;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_mod2_randac2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance)
{
}

static void registerMessagesc2_mod2_randac2(SFc2_mod2_randac2InstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_mod2_randac2InstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randac2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_emlrt_marshallIn(SFc2_mod2_randac2InstanceStruct *chartInstance,
  const mxArray *c2_dacout, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_dacout), &c2_thisId);
  sf_mex_destroy(&c2_dacout);
  return c2_y;
}

static real_T c2_b_emlrt_marshallIn(SFc2_mod2_randac2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_dacout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_mod2_randac2InstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randac2InstanceStruct *)chartInstanceVoid;
  c2_dacout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_dacout), &c2_thisId);
  sf_mex_destroy(&c2_dacout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i8;
  real_T c2_b_inData[3];
  int32_T c2_i9;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_mod2_randac2InstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randac2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
    c2_b_inData[c2_i8] = (*(real_T (*)[3])c2_inData)[c2_i8];
  }

  for (c2_i9 = 0; c2_i9 < 3; c2_i9++) {
    c2_u[c2_i9] = c2_b_inData[c2_i9];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i10;
  real_T c2_b_inData[4];
  int32_T c2_i11;
  real_T c2_u[4];
  const mxArray *c2_y = NULL;
  SFc2_mod2_randac2InstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randac2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i10 = 0; c2_i10 < 4; c2_i10++) {
    c2_b_inData[c2_i10] = (*(real_T (*)[4])c2_inData)[c2_i10];
  }

  for (c2_i11 = 0; c2_i11 < 4; c2_i11++) {
    c2_u[c2_i11] = c2_b_inData[c2_i11];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 4), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_mod2_randac2InstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randac2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_mod2_randac2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[8];
  c2_ResolvedFunctionInfo (*c2_b_info)[8];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i12;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[8])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "sum";
  (*c2_b_info)[0].dominantType = "double";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c2_b_info)[0].fileTimeLo = 1442401494U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 0U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c2_b_info)[1].name = "isequal";
  (*c2_b_info)[1].dominantType = "double";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  (*c2_b_info)[1].fileTimeLo = 1442401495U;
  (*c2_b_info)[1].fileTimeHi = 0U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  (*c2_b_info)[2].name = "eml_isequal_core";
  (*c2_b_info)[2].dominantType = "double";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  (*c2_b_info)[2].fileTimeLo = 1442401497U;
  (*c2_b_info)[2].fileTimeHi = 0U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c2_b_info)[3].name = "eml_const_nonsingleton_dim";
  (*c2_b_info)[3].dominantType = "double";
  (*c2_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  (*c2_b_info)[3].fileTimeLo = 1442401497U;
  (*c2_b_info)[3].fileTimeHi = 0U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  (*c2_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c2_b_info)[4].name = "eml_scalar_eg";
  (*c2_b_info)[4].dominantType = "double";
  (*c2_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  (*c2_b_info)[4].fileTimeLo = 1442401497U;
  (*c2_b_info)[4].fileTimeHi = 0U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  (*c2_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c2_b_info)[5].name = "eml_index_class";
  (*c2_b_info)[5].dominantType = "";
  (*c2_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  (*c2_b_info)[5].fileTimeLo = 1442401497U;
  (*c2_b_info)[5].fileTimeHi = 0U;
  (*c2_b_info)[5].mFileTimeLo = 0U;
  (*c2_b_info)[5].mFileTimeHi = 0U;
  (*c2_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  (*c2_b_info)[6].name = "eml_int_forloop_overflow_check";
  (*c2_b_info)[6].dominantType = "";
  (*c2_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  (*c2_b_info)[6].fileTimeLo = 1442401497U;
  (*c2_b_info)[6].fileTimeHi = 0U;
  (*c2_b_info)[6].mFileTimeLo = 0U;
  (*c2_b_info)[6].mFileTimeHi = 0U;
  (*c2_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  (*c2_b_info)[7].name = "intmax";
  (*c2_b_info)[7].dominantType = "char";
  (*c2_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  (*c2_b_info)[7].fileTimeLo = 1442401495U;
  (*c2_b_info)[7].fileTimeHi = 0U;
  (*c2_b_info)[7].mFileTimeLo = 0U;
  (*c2_b_info)[7].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 8), FALSE);
  for (c2_i12 = 0; c2_i12 < 8; c2_i12++) {
    c2_r0 = &c2_info[c2_i12];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i12);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i12);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static real_T c2_sum(SFc2_mod2_randac2InstanceStruct *chartInstance, real_T
                     c2_x_data[4], int32_T c2_x_sizes[1])
{
  real_T c2_y;
  boolean_T c2_p;
  boolean_T c2_b_p;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_d1;
  real_T c2_d2;
  boolean_T c2_b6;
  boolean_T c2_c_p;
  boolean_T c2_b7;
  int32_T c2_i13;
  static char_T c2_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 's', 'u', 'm', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l',
    'E', 'm', 'p', 't', 'y' };

  char_T c2_u[30];
  const mxArray *c2_b_y = NULL;
  boolean_T c2_b8;
  int32_T c2_i14;
  static char_T c2_cv1[36] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'a', 'u', 't', 'o', 'D', 'i', 'm', 'I', 'n', 'c', 'o',
    'm', 'p', 'a', 't', 'i', 'b', 'i', 'l', 'i', 't', 'y' };

  char_T c2_b_u[36];
  const mxArray *c2_c_y = NULL;
  int32_T c2_vlen;
  int32_T c2_b_vlen;
  int32_T c2_c_k;
  int32_T c2_d_k;
  boolean_T guard1 = FALSE;
  int32_T exitg1;
  c2_p = FALSE;
  c2_b_p = FALSE;
  c2_k = 0;
  do {
    exitg1 = 0;
    if (c2_k < 2) {
      c2_b_k = 1.0 + (real_T)c2_k;
      c2_d1 = c2_b_k;
      if (c2_d1 <= 1.0) {
        c2_d2 = (real_T)c2_x_sizes[0];
      } else {
        c2_d2 = 1.0;
      }

      if (c2_d2 != 0.0) {
        exitg1 = 1;
      } else {
        c2_k++;
      }
    } else {
      c2_b_p = TRUE;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  c2_b6 = c2_b_p;
  c2_c_p = c2_b6;
  if (!c2_c_p) {
  } else {
    c2_p = TRUE;
  }

  c2_b7 = !c2_p;
  if (c2_b7) {
  } else {
    for (c2_i13 = 0; c2_i13 < 30; c2_i13++) {
      c2_u[c2_i13] = c2_cv0[c2_i13];
    }

    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 30),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
      14, c2_b_y));
  }

  guard1 = FALSE;
  if (c2_x_sizes[0] == 1) {
    guard1 = TRUE;
  } else if ((real_T)c2_x_sizes[0] != 1.0) {
    guard1 = TRUE;
  } else {
    c2_b8 = FALSE;
  }

  if (guard1 == TRUE) {
    c2_b8 = TRUE;
  }

  if (c2_b8) {
  } else {
    for (c2_i14 = 0; c2_i14 < 36; c2_i14++) {
      c2_b_u[c2_i14] = c2_cv1[c2_i14];
    }

    c2_c_y = NULL;
    sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 36),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U,
      14, c2_c_y));
  }

  if (c2_x_sizes[0] == 0) {
    c2_y = 0.0;
  } else {
    c2_vlen = (int32_T)(real_T)c2_x_sizes[0];
    c2_y = c2_x_data[0];
    c2_b_vlen = c2_vlen;
    for (c2_c_k = 2; c2_c_k <= c2_b_vlen; c2_c_k++) {
      c2_d_k = c2_c_k;
      c2_y += c2_x_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c2_d_k, 1, c2_x_sizes[0],
        1, 0) - 1];
    }
  }

  return c2_y;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_mod2_randac2InstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randac2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_c_emlrt_marshallIn(SFc2_mod2_randac2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i15;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i15, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i15;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_mod2_randac2InstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randac2InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_mod2_randac2InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_mod2_randac2, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_mod2_randac2), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_mod2_randac2);
  return c2_y;
}

static uint8_T c2_e_emlrt_marshallIn(SFc2_mod2_randac2InstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_mod2_randac2InstanceStruct *chartInstance)
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

void sf_c2_mod2_randac2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(676238120U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1937980887U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(860661599U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1750670804U);
}

mxArray *sf_c2_mod2_randac2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("DoHdpw3jS77tn5HKSYYCMG");
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
      pr[0] = (double)(4);
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
      pr[0] = (double)(3);
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

mxArray *sf_c2_mod2_randac2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_mod2_randac2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"dacout\",},{M[8],M[0],T\"is_active_c2_mod2_randac2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_mod2_randac2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_mod2_randac2InstanceStruct *chartInstance;
    chartInstance = (SFc2_mod2_randac2InstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _mod2_randac2MachineNumber_,
           2,
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
          init_script_number_translation(_mod2_randac2MachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_mod2_randac2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _mod2_randac2MachineNumber_,
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
          (MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)c2_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          uint8_T *c2_dacin;
          real_T *c2_dacout;
          real_T *c2_rotflag;
          real_T *c2_numele;
          real_T (*c2_elems)[4];
          real_T (*c2_scramcode)[3];
          c2_scramcode = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 4);
          c2_elems = (real_T (*)[4])ssGetInputPortSignal(chartInstance->S, 3);
          c2_numele = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_rotflag = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_dacin = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_dacin);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_dacout);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_rotflag);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_numele);
          _SFD_SET_DATA_VALUE_PTR(4U, *c2_elems);
          _SFD_SET_DATA_VALUE_PTR(5U, *c2_scramcode);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _mod2_randac2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "85HVntakBU3U83gW7nGtVD";
}

static void sf_opaque_initialize_c2_mod2_randac2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_mod2_randac2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_mod2_randac2((SFc2_mod2_randac2InstanceStruct*)
    chartInstanceVar);
  initialize_c2_mod2_randac2((SFc2_mod2_randac2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_mod2_randac2(void *chartInstanceVar)
{
  enable_c2_mod2_randac2((SFc2_mod2_randac2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_mod2_randac2(void *chartInstanceVar)
{
  disable_c2_mod2_randac2((SFc2_mod2_randac2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_mod2_randac2(void *chartInstanceVar)
{
  sf_c2_mod2_randac2((SFc2_mod2_randac2InstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_mod2_randac2(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_mod2_randac2
    ((SFc2_mod2_randac2InstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_mod2_randac2();/* state var info */
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

extern void sf_internal_set_sim_state_c2_mod2_randac2(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_mod2_randac2();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_mod2_randac2((SFc2_mod2_randac2InstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_mod2_randac2(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_mod2_randac2(S);
}

static void sf_opaque_set_sim_state_c2_mod2_randac2(SimStruct* S, const mxArray *
  st)
{
  sf_internal_set_sim_state_c2_mod2_randac2(S, st);
}

static void sf_opaque_terminate_c2_mod2_randac2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_mod2_randac2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_mod2_randac2_optimization_info();
    }

    finalize_c2_mod2_randac2((SFc2_mod2_randac2InstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_mod2_randac2((SFc2_mod2_randac2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_mod2_randac2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_mod2_randac2((SFc2_mod2_randac2InstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_mod2_randac2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_mod2_randac2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1051197280U));
  ssSetChecksum1(S,(2789057376U));
  ssSetChecksum2(S,(530263846U));
  ssSetChecksum3(S,(1826130668U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_mod2_randac2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_mod2_randac2(SimStruct *S)
{
  SFc2_mod2_randac2InstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randac2InstanceStruct *)utMalloc(sizeof
    (SFc2_mod2_randac2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_mod2_randac2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_mod2_randac2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_mod2_randac2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_mod2_randac2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_mod2_randac2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_mod2_randac2;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_mod2_randac2;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_mod2_randac2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_mod2_randac2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_mod2_randac2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_mod2_randac2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_mod2_randac2;
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

void c2_mod2_randac2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_mod2_randac2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_mod2_randac2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_mod2_randac2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_mod2_randac2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
