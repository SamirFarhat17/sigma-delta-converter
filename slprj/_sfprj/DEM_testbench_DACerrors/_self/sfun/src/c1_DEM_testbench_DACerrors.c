/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DEM_testbench_DACerrors_sfun.h"
#include "c1_DEM_testbench_DACerrors.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DEM_testbench_DACerrors_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c1_debug_family_names[11] = { "dacplus1", "ipt", "indx",
  "nargin", "nargout", "dacin", "rotflag", "numele", "elems", "dacout",
  "ila_pointer" };

/* Function Declarations */
static void initialize_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance);
static void initialize_params_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance);
static void enable_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance);
static void disable_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance);
static void set_sim_state_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance, const mxArray
   *c1_st);
static void finalize_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance);
static void sf_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance);
static void initSimStructsc1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance);
static void registerMessagesc1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static void c1_emlrt_marshallIn(SFc1_DEM_testbench_DACerrorsInstanceStruct
  *chartInstance, const mxArray *c1_b_ila_pointer, const char_T *c1_identifier,
  real_T c1_y[100]);
static void c1_b_emlrt_marshallIn(SFc1_DEM_testbench_DACerrorsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[100]);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static real_T c1_c_emlrt_marshallIn(SFc1_DEM_testbench_DACerrorsInstanceStruct
  *chartInstance, const mxArray *c1_dacout, const char_T *c1_identifier);
static real_T c1_d_emlrt_marshallIn(SFc1_DEM_testbench_DACerrorsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_e_emlrt_marshallIn(SFc1_DEM_testbench_DACerrorsInstanceStruct *
  chartInstance, const mxArray *c1_indx, const char_T *c1_identifier);
static uint8_T c1_f_emlrt_marshallIn(SFc1_DEM_testbench_DACerrorsInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[14]);
static void c1_check_forloop_overflow_error
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance, boolean_T
   c1_overflow);
static void c1_eml_scalar_eg(SFc1_DEM_testbench_DACerrorsInstanceStruct
  *chartInstance);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_g_emlrt_marshallIn(SFc1_DEM_testbench_DACerrorsInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void init_dsm_address_info(SFc1_DEM_testbench_DACerrorsInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance)
{
  chartInstance->c1_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c1_ila_pointer_not_empty = FALSE;
  chartInstance->c1_is_active_c1_DEM_testbench_DACerrors = 0U;
}

static void initialize_params_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance)
{
}

static void enable_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c1_update_debugger_state_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  int32_T c1_i0;
  real_T c1_b_u[100];
  const mxArray *c1_c_y = NULL;
  uint8_T c1_b_hoistedGlobal;
  uint8_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T *c1_dacout;
  c1_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellarray(3), FALSE);
  c1_hoistedGlobal = *c1_dacout;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  for (c1_i0 = 0; c1_i0 < 100; c1_i0++) {
    c1_b_u[c1_i0] = chartInstance->c1_ila_pointer[c1_i0];
  }

  c1_c_y = NULL;
  if (!chartInstance->c1_ila_pointer_not_empty) {
    sf_mex_assign(&c1_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c1_c_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  FALSE);
  }

  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_b_hoistedGlobal = chartInstance->c1_is_active_c1_DEM_testbench_DACerrors;
  c1_c_u = c1_b_hoistedGlobal;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c1_y, 2, c1_d_y);
  sf_mex_assign(&c1_st, c1_y, FALSE);
  return c1_st;
}

static void set_sim_state_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance, const mxArray
   *c1_st)
{
  const mxArray *c1_u;
  real_T c1_dv0[100];
  int32_T c1_i1;
  real_T *c1_dacout;
  c1_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c1_doneDoubleBufferReInit = TRUE;
  c1_u = sf_mex_dup(c1_st);
  *c1_dacout = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 0)), "dacout");
  c1_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
                      "ila_pointer", c1_dv0);
  for (c1_i1 = 0; c1_i1 < 100; c1_i1++) {
    chartInstance->c1_ila_pointer[c1_i1] = c1_dv0[c1_i1];
  }

  chartInstance->c1_is_active_c1_DEM_testbench_DACerrors = c1_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 2)),
     "is_active_c1_DEM_testbench_DACerrors");
  sf_mex_destroy(&c1_u);
  c1_update_debugger_state_c1_DEM_testbench_DACerrors(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void finalize_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance)
{
}

static void sf_c1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance)
{
  int32_T c1_i2;
  uint8_T c1_hoistedGlobal;
  real_T c1_b_hoistedGlobal;
  real_T c1_c_hoistedGlobal;
  uint8_T c1_dacin;
  real_T c1_rotflag;
  real_T c1_numele;
  int32_T c1_i3;
  real_T c1_elems[3];
  uint32_T c1_debug_family_var_map[11];
  uint8_T c1_dacplus1;
  real_T c1_ipt;
  uint8_T c1_indx;
  real_T c1_nargin = 4.0;
  real_T c1_nargout = 1.0;
  real_T c1_dacout;
  uint32_T c1_u0;
  int32_T c1_i4;
  uint8_T c1_b_dacin;
  uint8_T c1_b;
  uint8_T c1_b_b;
  boolean_T c1_overflow;
  uint8_T c1_b_indx;
  real_T c1_x;
  real_T c1_y;
  real_T c1_xk;
  real_T c1_yk;
  real_T c1_b_x;
  real_T c1_b_y;
  real_T c1_r;
  real_T c1_c_x;
  real_T c1_d_x;
  real_T c1_e_x;
  real_T c1_f_x;
  real_T c1_g_x;
  real_T c1_h_x;
  real_T c1_i_x;
  real_T c1_c_y;
  real_T c1_j_x;
  real_T c1_d_y;
  real_T c1_c_b;
  real_T c1_e_y;
  real_T c1_k_x;
  real_T c1_l_x;
  uint8_T *c1_c_dacin;
  real_T *c1_b_dacout;
  real_T *c1_b_rotflag;
  real_T *c1_b_numele;
  real_T (*c1_b_elems)[3];
  c1_b_elems = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c1_b_numele = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c1_b_rotflag = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c1_b_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c1_c_dacin = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c1_c_dacin, 0U);
  _SFD_DATA_RANGE_CHECK(*c1_b_dacout, 1U);
  _SFD_DATA_RANGE_CHECK(*c1_b_rotflag, 2U);
  _SFD_DATA_RANGE_CHECK(*c1_b_numele, 3U);
  for (c1_i2 = 0; c1_i2 < 3; c1_i2++) {
    _SFD_DATA_RANGE_CHECK((*c1_b_elems)[c1_i2], 4U);
  }

  chartInstance->c1_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_hoistedGlobal = *c1_c_dacin;
  c1_b_hoistedGlobal = *c1_b_rotflag;
  c1_c_hoistedGlobal = *c1_b_numele;
  c1_dacin = c1_hoistedGlobal;
  c1_rotflag = c1_b_hoistedGlobal;
  c1_numele = c1_c_hoistedGlobal;
  for (c1_i3 = 0; c1_i3 < 3; c1_i3++) {
    c1_elems[c1_i3] = (*c1_b_elems)[c1_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c1_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_dacplus1, 0U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_ipt, 1U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_indx, 2U, c1_d_sf_marshallOut,
    c1_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 3U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 4U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_dacin, 5U, c1_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_rotflag, 6U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c1_numele, 7U, c1_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c1_elems, 8U, c1_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_dacout, 9U, c1_b_sf_marshallOut,
    c1_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c1_ila_pointer, 10U,
    c1_sf_marshallOut, c1_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 39);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 41);
  c1_u0 = (uint32_T)c1_dacin + 1U;
  if (CV_SATURATION_EVAL(4, 0, 0, 0, c1_u0 > 255U)) {
    c1_u0 = 255U;
  }

  c1_dacplus1 = (uint8_T)c1_u0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 47);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c1_ila_pointer_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 48);
    for (c1_i4 = 0; c1_i4 < 100; c1_i4++) {
      chartInstance->c1_ila_pointer[c1_i4] = 1.0;
    }

    chartInstance->c1_ila_pointer_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 51);
  if (CV_EML_IF(0, 1, 1, c1_rotflag == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 52);
    chartInstance->c1_ila_pointer[(uint8_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
      "ila_pointer", (int32_T)(uint8_T)_SFD_INTEGER_CHECK("dacplus1", (real_T)
      c1_dacplus1), 1, 100, 2, 0) - 1] = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 55);
  c1_dacout = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 56);
  c1_ipt = chartInstance->c1_ila_pointer[(uint8_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
    "ila_pointer", (int32_T)(uint8_T)_SFD_INTEGER_CHECK("dacplus1", (real_T)
    c1_dacplus1), 1, 100, 2, 0) - 1];
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 57);
  c1_b_dacin = c1_dacin;
  c1_b = c1_b_dacin;
  c1_b_b = c1_b;
  if (1 > c1_b_b) {
    c1_overflow = FALSE;
  } else {
    c1_overflow = (c1_b_b > 254);
  }

  if (c1_overflow) {
    c1_check_forloop_overflow_error(chartInstance, c1_overflow);
  }

  c1_indx = 1U;
  c1_b_indx = 1U;
  while (c1_b_indx <= c1_b_dacin) {
    c1_indx = c1_b_indx;
    CV_EML_FOR(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 58);
    c1_dacout += c1_elems[(int32_T)(real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("elems",
      (int32_T)_SFD_INTEGER_CHECK("ipt", c1_ipt), 1, 3, 1, 0) - 1];
    _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 59);
    c1_x = c1_ipt;
    c1_y = c1_numele;
    c1_eml_scalar_eg(chartInstance);
    c1_xk = c1_x;
    c1_yk = c1_y;
    c1_b_x = c1_xk;
    c1_b_y = c1_yk;
    c1_eml_scalar_eg(chartInstance);
    if (c1_b_y == 0.0) {
      c1_r = c1_b_x;
    } else {
      c1_c_x = c1_b_y;
      c1_d_x = c1_c_x;
      c1_d_x = muDoubleScalarFloor(c1_d_x);
      if (c1_b_y == c1_d_x) {
        c1_e_x = c1_b_x / c1_b_y;
        c1_f_x = c1_e_x;
        c1_f_x = muDoubleScalarFloor(c1_f_x);
        c1_r = c1_b_x - c1_f_x * c1_b_y;
      } else {
        c1_r = c1_b_x / c1_b_y;
        c1_g_x = c1_r;
        c1_h_x = c1_g_x;
        c1_h_x = muDoubleScalarRound(c1_h_x);
        c1_i_x = c1_r - c1_h_x;
        c1_c_y = muDoubleScalarAbs(c1_i_x);
        c1_j_x = c1_r;
        c1_d_y = muDoubleScalarAbs(c1_j_x);
        c1_c_b = c1_d_y;
        c1_e_y = 2.2204460492503131E-16 * c1_c_b;
        if (c1_c_y <= c1_e_y) {
          c1_r = 0.0;
        } else {
          c1_k_x = c1_r;
          c1_l_x = c1_k_x;
          c1_l_x = muDoubleScalarFloor(c1_l_x);
          c1_r = (c1_r - c1_l_x) * c1_b_y;
        }
      }
    }

    c1_ipt = c1_r + 1.0;
    c1_b_indx = (uint8_T)((uint32_T)c1_b_indx + 1U);
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_EML_FOR(0, 1, 0, 0);
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, 66);
  chartInstance->c1_ila_pointer[(uint8_T)_SFD_EML_ARRAY_BOUNDS_CHECK(
    "ila_pointer", (int32_T)(uint8_T)_SFD_INTEGER_CHECK("dacplus1", (real_T)
    c1_dacplus1), 1, 100, 2, 0) - 1] = c1_ipt;
  _SFD_EML_CALL(0U, chartInstance->c1_sfEvent, -66);
  _SFD_SYMBOL_SCOPE_POP();
  *c1_b_dacout = c1_dacout;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DEM_testbench_DACerrorsMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance)
{
}

static void registerMessagesc1_DEM_testbench_DACerrors
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber)
{
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i5;
  real_T c1_b_inData[100];
  int32_T c1_i6;
  real_T c1_u[100];
  const mxArray *c1_y = NULL;
  SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance;
  chartInstance = (SFc1_DEM_testbench_DACerrorsInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i5 = 0; c1_i5 < 100; c1_i5++) {
    c1_b_inData[c1_i5] = (*(real_T (*)[100])c1_inData)[c1_i5];
  }

  for (c1_i6 = 0; c1_i6 < 100; c1_i6++) {
    c1_u[c1_i6] = c1_b_inData[c1_i6];
  }

  c1_y = NULL;
  if (!chartInstance->c1_ila_pointer_not_empty) {
    sf_mex_assign(&c1_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 2, 1, 100),
                  FALSE);
  }

  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static void c1_emlrt_marshallIn(SFc1_DEM_testbench_DACerrorsInstanceStruct
  *chartInstance, const mxArray *c1_b_ila_pointer, const char_T *c1_identifier,
  real_T c1_y[100])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_ila_pointer), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_b_ila_pointer);
}

static void c1_b_emlrt_marshallIn(SFc1_DEM_testbench_DACerrorsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId,
  real_T c1_y[100])
{
  real_T c1_dv1[100];
  int32_T c1_i7;
  if (mxIsEmpty(c1_u)) {
    chartInstance->c1_ila_pointer_not_empty = FALSE;
  } else {
    chartInstance->c1_ila_pointer_not_empty = TRUE;
    sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv1, 1, 0, 0U, 1, 0U, 2, 1,
                  100);
    for (c1_i7 = 0; c1_i7 < 100; c1_i7++) {
      c1_y[c1_i7] = c1_dv1[c1_i7];
    }
  }

  sf_mex_destroy(&c1_u);
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_ila_pointer;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y[100];
  int32_T c1_i8;
  SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance;
  chartInstance = (SFc1_DEM_testbench_DACerrorsInstanceStruct *)
    chartInstanceVoid;
  c1_b_ila_pointer = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_ila_pointer), &c1_thisId,
                        c1_y);
  sf_mex_destroy(&c1_b_ila_pointer);
  for (c1_i8 = 0; c1_i8 < 100; c1_i8++) {
    (*(real_T (*)[100])c1_outData)[c1_i8] = c1_y[c1_i8];
  }

  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance;
  chartInstance = (SFc1_DEM_testbench_DACerrorsInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static real_T c1_c_emlrt_marshallIn(SFc1_DEM_testbench_DACerrorsInstanceStruct
  *chartInstance, const mxArray *c1_dacout, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_dacout), &c1_thisId);
  sf_mex_destroy(&c1_dacout);
  return c1_y;
}

static real_T c1_d_emlrt_marshallIn(SFc1_DEM_testbench_DACerrorsInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d0;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d0, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_dacout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance;
  chartInstance = (SFc1_DEM_testbench_DACerrorsInstanceStruct *)
    chartInstanceVoid;
  c1_dacout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_dacout), &c1_thisId);
  sf_mex_destroy(&c1_dacout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_i9;
  real_T c1_b_inData[3];
  int32_T c1_i10;
  real_T c1_u[3];
  const mxArray *c1_y = NULL;
  SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance;
  chartInstance = (SFc1_DEM_testbench_DACerrorsInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  for (c1_i9 = 0; c1_i9 < 3; c1_i9++) {
    c1_b_inData[c1_i9] = (*(real_T (*)[3])c1_inData)[c1_i9];
  }

  for (c1_i10 = 0; c1_i10 < 3; c1_i10++) {
    c1_u[c1_i10] = c1_b_inData[c1_i10];
  }

  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance;
  chartInstance = (SFc1_DEM_testbench_DACerrorsInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static uint8_T c1_e_emlrt_marshallIn(SFc1_DEM_testbench_DACerrorsInstanceStruct *
  chartInstance, const mxArray *c1_indx, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_indx), &c1_thisId);
  sf_mex_destroy(&c1_indx);
  return c1_y;
}

static uint8_T c1_f_emlrt_marshallIn(SFc1_DEM_testbench_DACerrorsInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u1;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u1, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_indx;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance;
  chartInstance = (SFc1_DEM_testbench_DACerrorsInstanceStruct *)
    chartInstanceVoid;
  c1_indx = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_indx), &c1_thisId);
  sf_mex_destroy(&c1_indx);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_DEM_testbench_DACerrors_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c1_nameCaptureInfo;
  c1_ResolvedFunctionInfo c1_info[14];
  const mxArray *c1_m0 = NULL;
  int32_T c1_i11;
  c1_ResolvedFunctionInfo *c1_r0;
  c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  c1_info_helper(c1_info);
  sf_mex_assign(&c1_m0, sf_mex_createstruct("nameCaptureInfo", 1, 14), FALSE);
  for (c1_i11 = 0; c1_i11 < 14; c1_i11++) {
    c1_r0 = &c1_info[c1_i11];
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->context)), "context", "nameCaptureInfo",
                    c1_i11);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c1_r0->name)), "name", "nameCaptureInfo", c1_i11);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c1_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c1_i11);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", c1_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c1_r0->resolved)), "resolved", "nameCaptureInfo",
                    c1_i11);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c1_i11);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c1_i11);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c1_i11);
    sf_mex_addfield(c1_m0, sf_mex_create("nameCaptureInfo", &c1_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c1_i11);
  }

  sf_mex_assign(&c1_nameCaptureInfo, c1_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(c1_ResolvedFunctionInfo c1_info[14])
{
  c1_info[0].context = "";
  c1_info[0].name = "eml_int_forloop_overflow_check";
  c1_info[0].dominantType = "";
  c1_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c1_info[0].fileTimeLo = 1442401497U;
  c1_info[0].fileTimeHi = 0U;
  c1_info[0].mFileTimeLo = 0U;
  c1_info[0].mFileTimeHi = 0U;
  c1_info[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c1_info[1].name = "intmax";
  c1_info[1].dominantType = "char";
  c1_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c1_info[1].fileTimeLo = 1442401495U;
  c1_info[1].fileTimeHi = 0U;
  c1_info[1].mFileTimeLo = 0U;
  c1_info[1].mFileTimeHi = 0U;
  c1_info[2].context = "";
  c1_info[2].name = "mod";
  c1_info[2].dominantType = "double";
  c1_info[2].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c1_info[2].fileTimeLo = 1442401495U;
  c1_info[2].fileTimeHi = 0U;
  c1_info[2].mFileTimeLo = 0U;
  c1_info[2].mFileTimeHi = 0U;
  c1_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c1_info[3].name = "eml_scalar_eg";
  c1_info[3].dominantType = "double";
  c1_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[3].fileTimeLo = 1442401497U;
  c1_info[3].fileTimeHi = 0U;
  c1_info[3].mFileTimeLo = 0U;
  c1_info[3].mFileTimeHi = 0U;
  c1_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m";
  c1_info[4].name = "eml_scalexp_alloc";
  c1_info[4].dominantType = "double";
  c1_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m";
  c1_info[4].fileTimeLo = 1442401497U;
  c1_info[4].fileTimeHi = 0U;
  c1_info[4].mFileTimeLo = 0U;
  c1_info[4].mFileTimeHi = 0U;
  c1_info[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c1_info[5].name = "eml_scalar_eg";
  c1_info[5].dominantType = "double";
  c1_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c1_info[5].fileTimeLo = 1442401497U;
  c1_info[5].fileTimeHi = 0U;
  c1_info[5].mFileTimeLo = 0U;
  c1_info[5].mFileTimeHi = 0U;
  c1_info[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c1_info[6].name = "eml_scalar_floor";
  c1_info[6].dominantType = "double";
  c1_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c1_info[6].fileTimeLo = 1442401495U;
  c1_info[6].fileTimeHi = 0U;
  c1_info[6].mFileTimeLo = 0U;
  c1_info[6].mFileTimeHi = 0U;
  c1_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c1_info[7].name = "eml_scalar_round";
  c1_info[7].dominantType = "double";
  c1_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m";
  c1_info[7].fileTimeLo = 1442401495U;
  c1_info[7].fileTimeHi = 0U;
  c1_info[7].mFileTimeLo = 0U;
  c1_info[7].mFileTimeHi = 0U;
  c1_info[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c1_info[8].name = "eml_scalar_abs";
  c1_info[8].dominantType = "double";
  c1_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m";
  c1_info[8].fileTimeLo = 1442401495U;
  c1_info[8].fileTimeHi = 0U;
  c1_info[8].mFileTimeLo = 0U;
  c1_info[8].mFileTimeHi = 0U;
  c1_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c1_info[9].name = "eps";
  c1_info[9].dominantType = "char";
  c1_info[9].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[9].fileTimeLo = 1442401495U;
  c1_info[9].fileTimeHi = 0U;
  c1_info[9].mFileTimeLo = 0U;
  c1_info[9].mFileTimeHi = 0U;
  c1_info[10].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[10].name = "eml_is_float_class";
  c1_info[10].dominantType = "char";
  c1_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m";
  c1_info[10].fileTimeLo = 1442401497U;
  c1_info[10].fileTimeHi = 0U;
  c1_info[10].mFileTimeLo = 0U;
  c1_info[10].mFileTimeHi = 0U;
  c1_info[11].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c1_info[11].name = "eml_eps";
  c1_info[11].dominantType = "char";
  c1_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[11].fileTimeLo = 1442401497U;
  c1_info[11].fileTimeHi = 0U;
  c1_info[11].mFileTimeLo = 0U;
  c1_info[11].mFileTimeHi = 0U;
  c1_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c1_info[12].name = "eml_float_model";
  c1_info[12].dominantType = "char";
  c1_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c1_info[12].fileTimeLo = 1442401497U;
  c1_info[12].fileTimeHi = 0U;
  c1_info[12].mFileTimeLo = 0U;
  c1_info[12].mFileTimeHi = 0U;
  c1_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod";
  c1_info[13].name = "mtimes";
  c1_info[13].dominantType = "double";
  c1_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c1_info[13].fileTimeLo = 1442401499U;
  c1_info[13].fileTimeHi = 0U;
  c1_info[13].mFileTimeLo = 0U;
  c1_info[13].mFileTimeHi = 0U;
}

static void c1_check_forloop_overflow_error
  (SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance, boolean_T
   c1_overflow)
{
  int32_T c1_i12;
  static char_T c1_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c1_u[34];
  const mxArray *c1_y = NULL;
  int32_T c1_i13;
  static char_T c1_cv1[5] = { 'u', 'i', 'n', 't', '8' };

  char_T c1_b_u[5];
  const mxArray *c1_b_y = NULL;
  if (!c1_overflow) {
  } else {
    for (c1_i12 = 0; c1_i12 < 34; c1_i12++) {
      c1_u[c1_i12] = c1_cv0[c1_i12];
    }

    c1_y = NULL;
    sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  FALSE);
    for (c1_i13 = 0; c1_i13 < 5; c1_i13++) {
      c1_b_u[c1_i13] = c1_cv1[c1_i13];
    }

    c1_b_y = NULL;
    sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  FALSE);
    sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U,
      14, c1_y, 14, c1_b_y));
  }
}

static void c1_eml_scalar_eg(SFc1_DEM_testbench_DACerrorsInstanceStruct
  *chartInstance)
{
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance;
  chartInstance = (SFc1_DEM_testbench_DACerrorsInstanceStruct *)
    chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, FALSE);
  return c1_mxArrayOutData;
}

static int32_T c1_g_emlrt_marshallIn(SFc1_DEM_testbench_DACerrorsInstanceStruct *
  chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i14;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i14, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i14;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance;
  chartInstance = (SFc1_DEM_testbench_DACerrorsInstanceStruct *)
    chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static void init_dsm_address_info(SFc1_DEM_testbench_DACerrorsInstanceStruct
  *chartInstance)
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

void sf_c1_DEM_testbench_DACerrors_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(830694537U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1474662649U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(752916230U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2763279481U);
}

mxArray *sf_c1_DEM_testbench_DACerrors_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("wxt9VuvhphBS0cnCb1IvhE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
      pr[0] = (double)(3);
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

mxArray *sf_c1_DEM_testbench_DACerrors_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c1_DEM_testbench_DACerrors(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"dacout\",},{M[4],M[0],T\"ila_pointer\",S'l','i','p'{{M1x2[1409 1420],M[0],}}},{M[8],M[0],T\"is_active_c1_DEM_testbench_DACerrors\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_DEM_testbench_DACerrors_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance;
    chartInstance = (SFc1_DEM_testbench_DACerrorsInstanceStruct *)
      ((ChartInfoStruct *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DEM_testbench_DACerrorsMachineNumber_,
           1,
           1,
           1,
           5,
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
          init_script_number_translation(_DEM_testbench_DACerrorsMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DEM_testbench_DACerrorsMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DEM_testbench_DACerrorsMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"dacin");
          _SFD_SET_DATA_PROPS(1,2,0,1,"dacout");
          _SFD_SET_DATA_PROPS(2,1,1,0,"rotflag");
          _SFD_SET_DATA_PROPS(3,1,1,0,"numele");
          _SFD_SET_DATA_PROPS(4,1,1,0,"elems");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,1,0,1,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2223);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,1468,-1,1475);
        _SFD_CV_INIT_EML_IF(0,1,0,1689,1712,-1,1780);
        _SFD_CV_INIT_EML_IF(0,1,1,1782,1799,-1,1863);
        _SFD_CV_INIT_EML_FOR(0,1,0,1910,1931,2187);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_d_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)c1_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c1_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          uint8_T *c1_dacin;
          real_T *c1_dacout;
          real_T *c1_rotflag;
          real_T *c1_numele;
          real_T (*c1_elems)[3];
          c1_elems = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c1_numele = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c1_rotflag = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c1_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c1_dacin = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c1_dacin);
          _SFD_SET_DATA_VALUE_PTR(1U, c1_dacout);
          _SFD_SET_DATA_VALUE_PTR(2U, c1_rotflag);
          _SFD_SET_DATA_VALUE_PTR(3U, c1_numele);
          _SFD_SET_DATA_VALUE_PTR(4U, *c1_elems);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DEM_testbench_DACerrorsMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "HRiHdNX77UVvCen1dYarkG";
}

static void sf_opaque_initialize_c1_DEM_testbench_DACerrors(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_DEM_testbench_DACerrorsInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c1_DEM_testbench_DACerrors
    ((SFc1_DEM_testbench_DACerrorsInstanceStruct*) chartInstanceVar);
  initialize_c1_DEM_testbench_DACerrors
    ((SFc1_DEM_testbench_DACerrorsInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_DEM_testbench_DACerrors(void *chartInstanceVar)
{
  enable_c1_DEM_testbench_DACerrors((SFc1_DEM_testbench_DACerrorsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c1_DEM_testbench_DACerrors(void *chartInstanceVar)
{
  disable_c1_DEM_testbench_DACerrors((SFc1_DEM_testbench_DACerrorsInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c1_DEM_testbench_DACerrors(void *chartInstanceVar)
{
  sf_c1_DEM_testbench_DACerrors((SFc1_DEM_testbench_DACerrorsInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c1_DEM_testbench_DACerrors
  (SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c1_DEM_testbench_DACerrors
    ((SFc1_DEM_testbench_DACerrorsInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_DEM_testbench_DACerrors();/* state var info */
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

extern void sf_internal_set_sim_state_c1_DEM_testbench_DACerrors(SimStruct* S,
  const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c1_DEM_testbench_DACerrors();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c1_DEM_testbench_DACerrors
    ((SFc1_DEM_testbench_DACerrorsInstanceStruct*)chartInfo->chartInstance,
     mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c1_DEM_testbench_DACerrors
  (SimStruct* S)
{
  return sf_internal_get_sim_state_c1_DEM_testbench_DACerrors(S);
}

static void sf_opaque_set_sim_state_c1_DEM_testbench_DACerrors(SimStruct* S,
  const mxArray *st)
{
  sf_internal_set_sim_state_c1_DEM_testbench_DACerrors(S, st);
}

static void sf_opaque_terminate_c1_DEM_testbench_DACerrors(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_DEM_testbench_DACerrorsInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DEM_testbench_DACerrors_optimization_info();
    }

    finalize_c1_DEM_testbench_DACerrors
      ((SFc1_DEM_testbench_DACerrorsInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_DEM_testbench_DACerrors
    ((SFc1_DEM_testbench_DACerrorsInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_DEM_testbench_DACerrors(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c1_DEM_testbench_DACerrors
      ((SFc1_DEM_testbench_DACerrorsInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_DEM_testbench_DACerrors(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DEM_testbench_DACerrors_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,1,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4283939613U));
  ssSetChecksum1(S,(2713850296U));
  ssSetChecksum2(S,(1419649867U));
  ssSetChecksum3(S,(566175864U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_DEM_testbench_DACerrors(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c1_DEM_testbench_DACerrors(SimStruct *S)
{
  SFc1_DEM_testbench_DACerrorsInstanceStruct *chartInstance;
  chartInstance = (SFc1_DEM_testbench_DACerrorsInstanceStruct *)utMalloc(sizeof
    (SFc1_DEM_testbench_DACerrorsInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_DEM_testbench_DACerrorsInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c1_DEM_testbench_DACerrors;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c1_DEM_testbench_DACerrors;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c1_DEM_testbench_DACerrors;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c1_DEM_testbench_DACerrors;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c1_DEM_testbench_DACerrors;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c1_DEM_testbench_DACerrors;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c1_DEM_testbench_DACerrors;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c1_DEM_testbench_DACerrors;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_DEM_testbench_DACerrors;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_DEM_testbench_DACerrors;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c1_DEM_testbench_DACerrors;
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

void c1_DEM_testbench_DACerrors_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_DEM_testbench_DACerrors(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_DEM_testbench_DACerrors(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_DEM_testbench_DACerrors(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_DEM_testbench_DACerrors_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
