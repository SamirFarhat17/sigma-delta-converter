/* Include files */

#include <stddef.h>
#include "blas.h"
#include "mod2_randac_sfun.h"
#include "c2_mod2_randac.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "mod2_randac_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c2_debug_family_names[8] = { "nargin", "nargout", "dacin",
  "rotflag", "numele", "elems", "dacout", "rinx" };

/* Function Declarations */
static void initialize_c2_mod2_randac(SFc2_mod2_randacInstanceStruct
  *chartInstance);
static void initialize_params_c2_mod2_randac(SFc2_mod2_randacInstanceStruct
  *chartInstance);
static void enable_c2_mod2_randac(SFc2_mod2_randacInstanceStruct *chartInstance);
static void disable_c2_mod2_randac(SFc2_mod2_randacInstanceStruct *chartInstance);
static void c2_update_debugger_state_c2_mod2_randac
  (SFc2_mod2_randacInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_mod2_randac
  (SFc2_mod2_randacInstanceStruct *chartInstance);
static void set_sim_state_c2_mod2_randac(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_mod2_randac(SFc2_mod2_randacInstanceStruct
  *chartInstance);
static void sf_c2_mod2_randac(SFc2_mod2_randacInstanceStruct *chartInstance);
static void c2_chartstep_c2_mod2_randac(SFc2_mod2_randacInstanceStruct
  *chartInstance);
static void initSimStructsc2_mod2_randac(SFc2_mod2_randacInstanceStruct
  *chartInstance);
static void registerMessagesc2_mod2_randac(SFc2_mod2_randacInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct *chartInstance,
  const mxArray *c2_b_rinx, const char_T *c2_identifier, real_T c2_y[3]);
static void c2_b_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_c_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_dacout, const char_T *c2_identifier);
static real_T c2_d_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[47]);
static real_T c2_sum(SFc2_mod2_randacInstanceStruct *chartInstance, real_T
                     c2_x_data[3], int32_T c2_x_sizes[1]);
static void c2_rand(SFc2_mod2_randacInstanceStruct *chartInstance, real_T c2_r[3]);
static void c2_eml_rand_mt19937ar(SFc2_mod2_randacInstanceStruct *chartInstance,
  uint32_T c2_d_state[625]);
static void c2_twister_state_vector(SFc2_mod2_randacInstanceStruct
  *chartInstance, uint32_T c2_mt[625], real_T c2_seed, uint32_T c2_b_mt[625]);
static void c2_b_eml_rand_mt19937ar(SFc2_mod2_randacInstanceStruct
  *chartInstance, uint32_T c2_d_state[625], uint32_T c2_e_state[625], real_T
  *c2_r);
static void c2_eml_error(SFc2_mod2_randacInstanceStruct *chartInstance);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint32_T c2_f_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_b_method, const char_T *c2_identifier);
static uint32_T c2_g_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static uint32_T c2_h_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_d_state, const char_T *c2_identifier);
static uint32_T c2_i_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_j_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct *chartInstance,
  const mxArray *c2_d_state, const char_T *c2_identifier, uint32_T c2_y[625]);
static void c2_k_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, uint32_T c2_y[625]);
static void c2_l_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct *chartInstance,
  const mxArray *c2_d_state, const char_T *c2_identifier, uint32_T c2_y[2]);
static void c2_m_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, uint32_T c2_y[2]);
static uint8_T c2_n_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_mod2_randac, const char_T
  *c2_identifier);
static uint8_T c2_o_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_twister_state_vector(SFc2_mod2_randacInstanceStruct
  *chartInstance, uint32_T c2_mt[625], real_T c2_seed);
static real_T c2_c_eml_rand_mt19937ar(SFc2_mod2_randacInstanceStruct
  *chartInstance, uint32_T c2_d_state[625]);
static void init_dsm_address_info(SFc2_mod2_randacInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_mod2_randac(SFc2_mod2_randacInstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_rinx_not_empty = FALSE;
  chartInstance->c2_method_not_empty = FALSE;
  chartInstance->c2_state_not_empty = FALSE;
  chartInstance->c2_b_state_not_empty = FALSE;
  chartInstance->c2_c_state_not_empty = FALSE;
  chartInstance->c2_is_active_c2_mod2_randac = 0U;
}

static void initialize_params_c2_mod2_randac(SFc2_mod2_randacInstanceStruct
  *chartInstance)
{
}

static void enable_c2_mod2_randac(SFc2_mod2_randacInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_mod2_randac(SFc2_mod2_randacInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c2_update_debugger_state_c2_mod2_randac
  (SFc2_mod2_randacInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c2_mod2_randac
  (SFc2_mod2_randacInstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  real_T c2_hoistedGlobal;
  real_T c2_u;
  const mxArray *c2_b_y = NULL;
  uint32_T c2_b_hoistedGlobal;
  uint32_T c2_b_u;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i0;
  real_T c2_c_u[3];
  const mxArray *c2_d_y = NULL;
  uint32_T c2_c_hoistedGlobal;
  uint32_T c2_d_u;
  const mxArray *c2_e_y = NULL;
  int32_T c2_i1;
  uint32_T c2_e_u[625];
  const mxArray *c2_f_y = NULL;
  int32_T c2_i2;
  uint32_T c2_f_u[2];
  const mxArray *c2_g_y = NULL;
  uint8_T c2_d_hoistedGlobal;
  uint8_T c2_g_u;
  const mxArray *c2_h_y = NULL;
  real_T *c2_dacout;
  c2_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(7), FALSE);
  c2_hoistedGlobal = *c2_dacout;
  c2_u = c2_hoistedGlobal;
  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_hoistedGlobal = chartInstance->c2_method;
  c2_b_u = c2_b_hoistedGlobal;
  c2_c_y = NULL;
  if (!chartInstance->c2_method_not_empty) {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_b_u, 7, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 1, c2_c_y);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    c2_c_u[c2_i0] = chartInstance->c2_rinx[c2_i0];
  }

  c2_d_y = NULL;
  if (!chartInstance->c2_rinx_not_empty) {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_d_y, sf_mex_create("y", c2_c_u, 0, 0U, 1U, 0U, 2, 1, 3),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 2, c2_d_y);
  c2_c_hoistedGlobal = chartInstance->c2_state;
  c2_d_u = c2_c_hoistedGlobal;
  c2_e_y = NULL;
  if (!chartInstance->c2_state_not_empty) {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_d_u, 7, 0U, 0U, 0U, 0), FALSE);
  }

  sf_mex_setcell(c2_y, 3, c2_e_y);
  for (c2_i1 = 0; c2_i1 < 625; c2_i1++) {
    c2_e_u[c2_i1] = chartInstance->c2_c_state[c2_i1];
  }

  c2_f_y = NULL;
  if (!chartInstance->c2_c_state_not_empty) {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_f_y, sf_mex_create("y", c2_e_u, 7, 0U, 1U, 0U, 1, 625),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 4, c2_f_y);
  for (c2_i2 = 0; c2_i2 < 2; c2_i2++) {
    c2_f_u[c2_i2] = chartInstance->c2_b_state[c2_i2];
  }

  c2_g_y = NULL;
  if (!chartInstance->c2_b_state_not_empty) {
    sf_mex_assign(&c2_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  FALSE);
  } else {
    sf_mex_assign(&c2_g_y, sf_mex_create("y", c2_f_u, 7, 0U, 1U, 0U, 1, 2),
                  FALSE);
  }

  sf_mex_setcell(c2_y, 5, c2_g_y);
  c2_d_hoistedGlobal = chartInstance->c2_is_active_c2_mod2_randac;
  c2_g_u = c2_d_hoistedGlobal;
  c2_h_y = NULL;
  sf_mex_assign(&c2_h_y, sf_mex_create("y", &c2_g_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 6, c2_h_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_mod2_randac(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  real_T c2_dv0[3];
  int32_T c2_i3;
  uint32_T c2_uv0[625];
  int32_T c2_i4;
  uint32_T c2_uv1[2];
  int32_T c2_i5;
  real_T *c2_dacout;
  c2_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c2_doneDoubleBufferReInit = TRUE;
  c2_u = sf_mex_dup(c2_st);
  *c2_dacout = c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c2_u, 0)), "dacout");
  chartInstance->c2_method = c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 1)), "method");
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 2)), "rinx",
                      c2_dv0);
  for (c2_i3 = 0; c2_i3 < 3; c2_i3++) {
    chartInstance->c2_rinx[c2_i3] = c2_dv0[c2_i3];
  }

  chartInstance->c2_state = c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c2_u, 3)), "state");
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 4)),
                        "state", c2_uv0);
  for (c2_i4 = 0; c2_i4 < 625; c2_i4++) {
    chartInstance->c2_c_state[c2_i4] = c2_uv0[c2_i4];
  }

  c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 5)),
                        "state", c2_uv1);
  for (c2_i5 = 0; c2_i5 < 2; c2_i5++) {
    chartInstance->c2_b_state[c2_i5] = c2_uv1[c2_i5];
  }

  chartInstance->c2_is_active_c2_mod2_randac = c2_n_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 6)),
     "is_active_c2_mod2_randac");
  sf_mex_destroy(&c2_u);
  c2_update_debugger_state_c2_mod2_randac(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_mod2_randac(SFc2_mod2_randacInstanceStruct
  *chartInstance)
{
}

static void sf_c2_mod2_randac(SFc2_mod2_randacInstanceStruct *chartInstance)
{
  int32_T c2_i6;
  uint8_T *c2_dacin;
  real_T *c2_dacout;
  real_T *c2_rotflag;
  real_T *c2_numele;
  real_T (*c2_elems)[3];
  c2_elems = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c2_numele = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_rotflag = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_dacin = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*c2_dacin, 0U);
  _SFD_DATA_RANGE_CHECK(*c2_dacout, 1U);
  _SFD_DATA_RANGE_CHECK(*c2_rotflag, 2U);
  _SFD_DATA_RANGE_CHECK(*c2_numele, 3U);
  for (c2_i6 = 0; c2_i6 < 3; c2_i6++) {
    _SFD_DATA_RANGE_CHECK((*c2_elems)[c2_i6], 4U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_mod2_randac(chartInstance);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_mod2_randacMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c2_chartstep_c2_mod2_randac(SFc2_mod2_randacInstanceStruct
  *chartInstance)
{
  uint8_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  uint8_T c2_dacin;
  real_T c2_rotflag;
  real_T c2_numele;
  int32_T c2_i7;
  real_T c2_elems[3];
  uint32_T c2_debug_family_var_map[8];
  real_T c2_nargin = 4.0;
  real_T c2_nargout = 1.0;
  real_T c2_dacout;
  int32_T c2_i8;
  boolean_T c2_b0;
  boolean_T c2_b1;
  boolean_T c2_b2;
  int32_T c2_i9;
  int32_T c2_elems_sizes;
  int32_T c2_loop_ub;
  int32_T c2_i10;
  real_T c2_elems_data[3];
  real_T c2_p[3];
  real_T c2_a;
  real_T c2_b;
  real_T c2_b_a;
  real_T c2_b_b;
  boolean_T c2_b_p;
  boolean_T c2_b3;
  boolean_T c2_c_p;
  real_T c2_c_a;
  real_T c2_c_b;
  real_T c2_d_a;
  real_T c2_d_b;
  boolean_T c2_d_p;
  boolean_T c2_b4;
  boolean_T c2_e_p;
  int32_T c2_idx[3];
  real_T c2_e_a;
  real_T c2_e_b;
  real_T c2_f_a;
  real_T c2_f_b;
  boolean_T c2_f_p;
  boolean_T c2_b5;
  boolean_T c2_g_p;
  real_T c2_g_a;
  real_T c2_g_b;
  real_T c2_h_a;
  real_T c2_h_b;
  boolean_T c2_h_p;
  boolean_T c2_b6;
  boolean_T c2_i_p;
  real_T c2_i_a;
  real_T c2_i_b;
  real_T c2_j_a;
  real_T c2_j_b;
  boolean_T c2_j_p;
  boolean_T c2_b7;
  boolean_T c2_k_p;
  int32_T c2_i11;
  int32_T c2_i12;
  boolean_T c2_b8;
  boolean_T c2_b9;
  boolean_T c2_b10;
  int32_T c2_i13;
  int32_T c2_tmp_sizes;
  int32_T c2_b_loop_ub;
  int32_T c2_i14;
  int32_T c2_tmp_data[3];
  int32_T c2_b_tmp_sizes[2];
  int32_T c2_iv0[2];
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_c_loop_ub;
  int32_T c2_i17;
  int32_T c2_b_tmp_data[3];
  int32_T c2_b_elems_sizes;
  int32_T c2_d_loop_ub;
  int32_T c2_i18;
  real_T c2_b_elems_data[3];
  real_T *c2_b_dacout;
  uint8_T *c2_b_dacin;
  real_T *c2_b_rotflag;
  real_T *c2_b_numele;
  real_T (*c2_b_elems)[3];
  c2_b_elems = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
  c2_b_numele = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c2_b_rotflag = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c2_b_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_b_dacin = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = *c2_b_dacin;
  c2_b_hoistedGlobal = *c2_b_rotflag;
  c2_c_hoistedGlobal = *c2_b_numele;
  c2_dacin = c2_hoistedGlobal;
  c2_rotflag = c2_b_hoistedGlobal;
  c2_numele = c2_c_hoistedGlobal;
  for (c2_i7 = 0; c2_i7 < 3; c2_i7++) {
    c2_elems[c2_i7] = (*c2_b_elems)[c2_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 0U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_dacin, 2U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_rotflag, 3U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_numele, 4U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_elems, 5U, c2_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dacout, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_rinx, 7U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 51);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c2_rinx_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
    for (c2_i8 = 0; c2_i8 < 3; c2_i8++) {
      chartInstance->c2_rinx[c2_i8] = 1.0;
    }

    chartInstance->c2_rinx_not_empty = TRUE;
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 57);
  if (CV_EML_IF(0, 1, 1, c2_rotflag == 0.0)) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 58);
    c2_b0 = (1 > c2_dacin);
    c2_b1 = c2_b0;
    c2_b2 = c2_b1;
    if (c2_b2) {
      c2_i9 = 0;
    } else {
      c2_i9 = (uint8_T)_SFD_EML_ARRAY_BOUNDS_CHECK("elems", (int32_T)c2_dacin, 1,
        3, 0, 0);
    }

    c2_elems_sizes = c2_i9;
    c2_loop_ub = c2_i9 - 1;
    for (c2_i10 = 0; c2_i10 <= c2_loop_ub; c2_i10++) {
      c2_elems_data[c2_i10] = c2_elems[c2_i10];
    }

    c2_dacout = c2_sum(chartInstance, c2_elems_data, *(int32_T (*)[1])&
                       c2_elems_sizes);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 60);
    c2_rand(chartInstance, c2_p);
    c2_a = c2_p[0];
    c2_b = c2_p[1];
    c2_b_a = c2_a;
    c2_b_b = c2_b;
    c2_b_p = (c2_b_a <= c2_b_b);
    c2_b3 = c2_b_p;
    c2_c_p = c2_b3;
    if (c2_c_p) {
      c2_c_a = c2_p[1];
      c2_c_b = c2_p[2];
      c2_d_a = c2_c_a;
      c2_d_b = c2_c_b;
      c2_d_p = (c2_d_a <= c2_d_b);
      c2_b4 = c2_d_p;
      c2_e_p = c2_b4;
      if (c2_e_p) {
        c2_idx[0] = 1;
        c2_idx[1] = 2;
        c2_idx[2] = 3;
      } else {
        c2_e_a = c2_p[0];
        c2_e_b = c2_p[2];
        c2_f_a = c2_e_a;
        c2_f_b = c2_e_b;
        c2_f_p = (c2_f_a <= c2_f_b);
        c2_b5 = c2_f_p;
        c2_g_p = c2_b5;
        if (c2_g_p) {
          c2_idx[0] = 1;
          c2_idx[1] = 3;
          c2_idx[2] = 2;
        } else {
          c2_idx[0] = 3;
          c2_idx[1] = 1;
          c2_idx[2] = 2;
        }
      }
    } else {
      c2_g_a = c2_p[0];
      c2_g_b = c2_p[2];
      c2_h_a = c2_g_a;
      c2_h_b = c2_g_b;
      c2_h_p = (c2_h_a <= c2_h_b);
      c2_b6 = c2_h_p;
      c2_i_p = c2_b6;
      if (c2_i_p) {
        c2_idx[0] = 2;
        c2_idx[1] = 1;
        c2_idx[2] = 3;
      } else {
        c2_i_a = c2_p[1];
        c2_i_b = c2_p[2];
        c2_j_a = c2_i_a;
        c2_j_b = c2_i_b;
        c2_j_p = (c2_j_a <= c2_j_b);
        c2_b7 = c2_j_p;
        c2_k_p = c2_b7;
        if (c2_k_p) {
          c2_idx[0] = 2;
          c2_idx[1] = 3;
          c2_idx[2] = 1;
        } else {
          c2_idx[0] = 3;
          c2_idx[1] = 2;
          c2_idx[2] = 1;
        }
      }
    }

    for (c2_i11 = 0; c2_i11 < 3; c2_i11++) {
      c2_p[c2_i11] = (real_T)c2_idx[c2_i11];
    }

    for (c2_i12 = 0; c2_i12 < 3; c2_i12++) {
      chartInstance->c2_rinx[c2_i12] = c2_p[c2_i12];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 61);
    c2_b8 = (1 > c2_dacin);
    c2_b9 = c2_b8;
    c2_b10 = c2_b9;
    if (c2_b10) {
      c2_i13 = 0;
    } else {
      c2_i13 = (uint8_T)_SFD_EML_ARRAY_BOUNDS_CHECK("rinx", (int32_T)c2_dacin, 1,
        3, 0, 0);
    }

    c2_tmp_sizes = c2_i13;
    c2_b_loop_ub = c2_i13 - 1;
    for (c2_i14 = 0; c2_i14 <= c2_b_loop_ub; c2_i14++) {
      c2_tmp_data[c2_i14] = 1 + c2_i14;
    }

    c2_b_tmp_sizes[0] = 1;
    c2_iv0[0] = 1;
    c2_iv0[1] = c2_tmp_sizes;
    c2_b_tmp_sizes[1] = c2_iv0[1];
    c2_i15 = c2_b_tmp_sizes[0];
    c2_i16 = c2_b_tmp_sizes[1];
    c2_c_loop_ub = c2_tmp_sizes - 1;
    for (c2_i17 = 0; c2_i17 <= c2_c_loop_ub; c2_i17++) {
      c2_b_tmp_data[c2_i17] = (int32_T)chartInstance->c2_rinx[c2_tmp_data[c2_i17]
        - 1];
    }

    c2_b_elems_sizes = c2_b_tmp_sizes[1];
    c2_d_loop_ub = c2_b_tmp_sizes[1] - 1;
    for (c2_i18 = 0; c2_i18 <= c2_d_loop_ub; c2_i18++) {
      c2_b_elems_data[c2_i18] = c2_elems[c2_b_tmp_data[c2_i18] - 1];
    }

    c2_dacout = c2_sum(chartInstance, c2_b_elems_data, *(int32_T (*)[1])&
                       c2_b_elems_sizes);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -61);
  _SFD_SYMBOL_SCOPE_POP();
  *c2_b_dacout = c2_dacout;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_mod2_randac(SFc2_mod2_randacInstanceStruct
  *chartInstance)
{
}

static void registerMessagesc2_mod2_randac(SFc2_mod2_randacInstanceStruct
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
  int32_T c2_i19;
  real_T c2_b_inData[3];
  int32_T c2_i20;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_mod2_randacInstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randacInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i19 = 0; c2_i19 < 3; c2_i19++) {
    c2_b_inData[c2_i19] = (*(real_T (*)[3])c2_inData)[c2_i19];
  }

  for (c2_i20 = 0; c2_i20 < 3; c2_i20++) {
    c2_u[c2_i20] = c2_b_inData[c2_i20];
  }

  c2_y = NULL;
  if (!chartInstance->c2_rinx_not_empty) {
    sf_mex_assign(&c2_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), FALSE);
  } else {
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 2, 1, 3), FALSE);
  }

  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct *chartInstance,
  const mxArray *c2_b_rinx, const char_T *c2_identifier, real_T c2_y[3])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_rinx), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_rinx);
}

static void c2_b_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, real_T c2_y[3])
{
  real_T c2_dv1[3];
  int32_T c2_i21;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_rinx_not_empty = FALSE;
  } else {
    chartInstance->c2_rinx_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_dv1, 1, 0, 0U, 1, 0U, 2, 1,
                  3);
    for (c2_i21 = 0; c2_i21 < 3; c2_i21++) {
      c2_y[c2_i21] = c2_dv1[c2_i21];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_rinx;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i22;
  SFc2_mod2_randacInstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randacInstanceStruct *)chartInstanceVoid;
  c2_b_rinx = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_rinx), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_rinx);
  for (c2_i22 = 0; c2_i22 < 3; c2_i22++) {
    (*(real_T (*)[3])c2_outData)[c2_i22] = c2_y[c2_i22];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_mod2_randacInstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randacInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static real_T c2_c_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_dacout, const char_T *c2_identifier)
{
  real_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_dacout), &c2_thisId);
  sf_mex_destroy(&c2_dacout);
  return c2_y;
}

static real_T c2_d_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_dacout;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_mod2_randacInstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randacInstanceStruct *)chartInstanceVoid;
  c2_dacout = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_dacout), &c2_thisId);
  sf_mex_destroy(&c2_dacout);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i23;
  real_T c2_b_inData[3];
  int32_T c2_i24;
  real_T c2_u[3];
  const mxArray *c2_y = NULL;
  SFc2_mod2_randacInstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randacInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i23 = 0; c2_i23 < 3; c2_i23++) {
    c2_b_inData[c2_i23] = (*(real_T (*)[3])c2_inData)[c2_i23];
  }

  for (c2_i24 = 0; c2_i24 < 3; c2_i24++) {
    c2_u[c2_i24] = c2_b_inData[c2_i24];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 0, 0U, 1U, 0U, 1, 3), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  uint8_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_mod2_randacInstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randacInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(uint8_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_mod2_randac_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[47];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i25;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  c2_info_helper(c2_info);
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 47), FALSE);
  for (c2_i25 = 0; c2_i25 < 47; c2_i25++) {
    c2_r0 = &c2_info[c2_i25];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i25);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i25);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(c2_ResolvedFunctionInfo c2_info[47])
{
  c2_info[0].context = "";
  c2_info[0].name = "sum";
  c2_info[0].dominantType = "double";
  c2_info[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c2_info[0].fileTimeLo = 1442401494U;
  c2_info[0].fileTimeHi = 0U;
  c2_info[0].mFileTimeLo = 0U;
  c2_info[0].mFileTimeHi = 0U;
  c2_info[1].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c2_info[1].name = "isequal";
  c2_info[1].dominantType = "double";
  c2_info[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[1].fileTimeLo = 1442401495U;
  c2_info[1].fileTimeHi = 0U;
  c2_info[1].mFileTimeLo = 0U;
  c2_info[1].mFileTimeHi = 0U;
  c2_info[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[2].name = "eml_isequal_core";
  c2_info[2].dominantType = "double";
  c2_info[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m";
  c2_info[2].fileTimeLo = 1442401497U;
  c2_info[2].fileTimeHi = 0U;
  c2_info[2].mFileTimeLo = 0U;
  c2_info[2].mFileTimeHi = 0U;
  c2_info[3].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c2_info[3].name = "eml_const_nonsingleton_dim";
  c2_info[3].dominantType = "double";
  c2_info[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m";
  c2_info[3].fileTimeLo = 1442401497U;
  c2_info[3].fileTimeHi = 0U;
  c2_info[3].mFileTimeLo = 0U;
  c2_info[3].mFileTimeHi = 0U;
  c2_info[4].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c2_info[4].name = "eml_scalar_eg";
  c2_info[4].dominantType = "double";
  c2_info[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m";
  c2_info[4].fileTimeLo = 1442401497U;
  c2_info[4].fileTimeHi = 0U;
  c2_info[4].mFileTimeLo = 0U;
  c2_info[4].mFileTimeHi = 0U;
  c2_info[5].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c2_info[5].name = "eml_index_class";
  c2_info[5].dominantType = "";
  c2_info[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[5].fileTimeLo = 1442401497U;
  c2_info[5].fileTimeHi = 0U;
  c2_info[5].mFileTimeLo = 0U;
  c2_info[5].mFileTimeHi = 0U;
  c2_info[6].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m";
  c2_info[6].name = "eml_int_forloop_overflow_check";
  c2_info[6].dominantType = "";
  c2_info[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m";
  c2_info[6].fileTimeLo = 1442401497U;
  c2_info[6].fileTimeHi = 0U;
  c2_info[6].mFileTimeLo = 0U;
  c2_info[6].mFileTimeHi = 0U;
  c2_info[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper";
  c2_info[7].name = "intmax";
  c2_info[7].dominantType = "char";
  c2_info[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m";
  c2_info[7].fileTimeLo = 1442401495U;
  c2_info[7].fileTimeHi = 0U;
  c2_info[7].mFileTimeLo = 0U;
  c2_info[7].mFileTimeHi = 0U;
  c2_info[8].context = "";
  c2_info[8].name = "randperm";
  c2_info[8].dominantType = "double";
  c2_info[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randperm.m";
  c2_info[8].fileTimeLo = 1442401499U;
  c2_info[8].fileTimeHi = 0U;
  c2_info[8].mFileTimeLo = 0U;
  c2_info[8].mFileTimeHi = 0U;
  c2_info[9].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randperm.m";
  c2_info[9].name = "flintmax";
  c2_info[9].dominantType = "char";
  c2_info[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m";
  c2_info[9].fileTimeLo = 1442401495U;
  c2_info[9].fileTimeHi = 0U;
  c2_info[9].mFileTimeLo = 0U;
  c2_info[9].mFileTimeHi = 0U;
  c2_info[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m";
  c2_info[10].name = "eml_float_model";
  c2_info[10].dominantType = "char";
  c2_info[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[10].fileTimeLo = 1442401497U;
  c2_info[10].fileTimeHi = 0U;
  c2_info[10].mFileTimeLo = 0U;
  c2_info[10].mFileTimeHi = 0U;
  c2_info[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randperm.m";
  c2_info[11].name = "floor";
  c2_info[11].dominantType = "double";
  c2_info[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[11].fileTimeLo = 1442401495U;
  c2_info[11].fileTimeHi = 0U;
  c2_info[11].mFileTimeLo = 0U;
  c2_info[11].mFileTimeHi = 0U;
  c2_info[12].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m";
  c2_info[12].name = "eml_scalar_floor";
  c2_info[12].dominantType = "double";
  c2_info[12].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m";
  c2_info[12].fileTimeLo = 1442401495U;
  c2_info[12].fileTimeHi = 0U;
  c2_info[12].mFileTimeLo = 0U;
  c2_info[12].mFileTimeHi = 0U;
  c2_info[13].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randperm.m";
  c2_info[13].name = "rand";
  c2_info[13].dominantType = "double";
  c2_info[13].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m";
  c2_info[13].fileTimeLo = 1442401499U;
  c2_info[13].fileTimeHi = 0U;
  c2_info[13].mFileTimeLo = 0U;
  c2_info[13].mFileTimeHi = 0U;
  c2_info[14].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m";
  c2_info[14].name = "eml_is_rand_extrinsic";
  c2_info[14].dominantType = "";
  c2_info[14].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_is_rand_extrinsic.m";
  c2_info[14].fileTimeLo = 1442401499U;
  c2_info[14].fileTimeHi = 0U;
  c2_info[14].mFileTimeLo = 0U;
  c2_info[14].mFileTimeHi = 0U;
  c2_info[15].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/rand.m";
  c2_info[15].name = "eml_rand";
  c2_info[15].dominantType = "char";
  c2_info[15].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c2_info[15].fileTimeLo = 1442401499U;
  c2_info[15].fileTimeHi = 0U;
  c2_info[15].mFileTimeLo = 0U;
  c2_info[15].mFileTimeHi = 0U;
  c2_info[16].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c2_info[16].name = "eml_rand_str2id";
  c2_info[16].dominantType = "char";
  c2_info[16].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_str2id.m";
  c2_info[16].fileTimeLo = 1442401499U;
  c2_info[16].fileTimeHi = 0U;
  c2_info[16].mFileTimeLo = 0U;
  c2_info[16].mFileTimeHi = 0U;
  c2_info[17].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c2_info[17].name = "eml_rand_mcg16807_stateful";
  c2_info[17].dominantType = "char";
  c2_info[17].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c2_info[17].fileTimeLo = 1442401499U;
  c2_info[17].fileTimeHi = 0U;
  c2_info[17].mFileTimeLo = 0U;
  c2_info[17].mFileTimeHi = 0U;
  c2_info[18].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c2_info[18].name = "eml_rand_mcg16807";
  c2_info[18].dominantType = "char";
  c2_info[18].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m";
  c2_info[18].fileTimeLo = 1442401499U;
  c2_info[18].fileTimeHi = 0U;
  c2_info[18].mFileTimeLo = 0U;
  c2_info[18].mFileTimeHi = 0U;
  c2_info[19].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m";
  c2_info[19].name = "eml_rand_mcg16807";
  c2_info[19].dominantType = "uint32";
  c2_info[19].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m";
  c2_info[19].fileTimeLo = 1442401499U;
  c2_info[19].fileTimeHi = 0U;
  c2_info[19].mFileTimeLo = 0U;
  c2_info[19].mFileTimeHi = 0U;
  c2_info[20].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807.m!genrandu";
  c2_info[20].name = "mtimes";
  c2_info[20].dominantType = "double";
  c2_info[20].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[20].fileTimeLo = 1442401499U;
  c2_info[20].fileTimeHi = 0U;
  c2_info[20].mFileTimeLo = 0U;
  c2_info[20].mFileTimeHi = 0U;
  c2_info[21].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c2_info[21].name = "eml_rand_shr3cong_stateful";
  c2_info[21].dominantType = "char";
  c2_info[21].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c2_info[21].fileTimeLo = 1442401499U;
  c2_info[21].fileTimeHi = 0U;
  c2_info[21].mFileTimeLo = 0U;
  c2_info[21].mFileTimeHi = 0U;
  c2_info[22].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c2_info[22].name = "eml_rand_shr3cong";
  c2_info[22].dominantType = "char";
  c2_info[22].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m";
  c2_info[22].fileTimeLo = 1442401499U;
  c2_info[22].fileTimeHi = 0U;
  c2_info[22].mFileTimeLo = 0U;
  c2_info[22].mFileTimeHi = 0U;
  c2_info[23].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m";
  c2_info[23].name = "eml_rand_shr3cong";
  c2_info[23].dominantType = "uint32";
  c2_info[23].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m";
  c2_info[23].fileTimeLo = 1442401499U;
  c2_info[23].fileTimeHi = 0U;
  c2_info[23].mFileTimeLo = 0U;
  c2_info[23].mFileTimeHi = 0U;
  c2_info[24].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong.m!genrandu";
  c2_info[24].name = "mtimes";
  c2_info[24].dominantType = "double";
  c2_info[24].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[24].fileTimeLo = 1442401499U;
  c2_info[24].fileTimeHi = 0U;
  c2_info[24].mFileTimeLo = 0U;
  c2_info[24].mFileTimeHi = 0U;
  c2_info[25].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand.m";
  c2_info[25].name = "eml_rand_mt19937ar_stateful";
  c2_info[25].dominantType = "char";
  c2_info[25].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c2_info[25].fileTimeLo = 1442401499U;
  c2_info[25].fileTimeHi = 0U;
  c2_info[25].mFileTimeLo = 0U;
  c2_info[25].mFileTimeHi = 0U;
  c2_info[26].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c2_info[26].name = "eml_rand_mt19937ar";
  c2_info[26].dominantType = "char";
  c2_info[26].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m";
  c2_info[26].fileTimeLo = 1442401499U;
  c2_info[26].fileTimeHi = 0U;
  c2_info[26].mFileTimeLo = 0U;
  c2_info[26].mFileTimeHi = 0U;
  c2_info[27].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m";
  c2_info[27].name = "eml_rand_mt19937ar";
  c2_info[27].dominantType = "uint32";
  c2_info[27].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m";
  c2_info[27].fileTimeLo = 1442401499U;
  c2_info[27].fileTimeHi = 0U;
  c2_info[27].mFileTimeLo = 0U;
  c2_info[27].mFileTimeHi = 0U;
  c2_info[28].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c2_info[28].name = "eps";
  c2_info[28].dominantType = "";
  c2_info[28].resolved = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[28].fileTimeLo = 1442401495U;
  c2_info[28].fileTimeHi = 0U;
  c2_info[28].mFileTimeLo = 0U;
  c2_info[28].mFileTimeHi = 0U;
  c2_info[29].context = "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m";
  c2_info[29].name = "eml_eps";
  c2_info[29].dominantType = "char";
  c2_info[29].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c2_info[29].fileTimeLo = 1442401497U;
  c2_info[29].fileTimeHi = 0U;
  c2_info[29].mFileTimeLo = 0U;
  c2_info[29].mFileTimeHi = 0U;
  c2_info[30].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m";
  c2_info[30].name = "eml_float_model";
  c2_info[30].dominantType = "char";
  c2_info[30].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m";
  c2_info[30].fileTimeLo = 1442401497U;
  c2_info[30].fileTimeHi = 0U;
  c2_info[30].mFileTimeLo = 0U;
  c2_info[30].mFileTimeHi = 0U;
  c2_info[31].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c2_info[31].name = "isequal";
  c2_info[31].dominantType = "double";
  c2_info[31].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m";
  c2_info[31].fileTimeLo = 1442401495U;
  c2_info[31].fileTimeHi = 0U;
  c2_info[31].mFileTimeLo = 0U;
  c2_info[31].mFileTimeHi = 0U;
  c2_info[32].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar";
  c2_info[32].name = "isnan";
  c2_info[32].dominantType = "double";
  c2_info[32].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[32].fileTimeLo = 1442401495U;
  c2_info[32].fileTimeHi = 0U;
  c2_info[32].mFileTimeLo = 0U;
  c2_info[32].mFileTimeHi = 0U;
  c2_info[33].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c2_info[33].name = "mtimes";
  c2_info[33].dominantType = "double";
  c2_info[33].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  c2_info[33].fileTimeLo = 1442401499U;
  c2_info[33].fileTimeHi = 0U;
  c2_info[33].mFileTimeLo = 0U;
  c2_info[33].mFileTimeHi = 0U;
  c2_info[34].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c2_info[34].name = "eml_index_class";
  c2_info[34].dominantType = "";
  c2_info[34].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[34].fileTimeLo = 1442401497U;
  c2_info[34].fileTimeHi = 0U;
  c2_info[34].mFileTimeLo = 0U;
  c2_info[34].mFileTimeHi = 0U;
  c2_info[35].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!is_valid_state";
  c2_info[35].name = "eml_index_plus";
  c2_info[35].dominantType = "double";
  c2_info[35].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[35].fileTimeLo = 1442401497U;
  c2_info[35].fileTimeHi = 0U;
  c2_info[35].mFileTimeLo = 0U;
  c2_info[35].mFileTimeHi = 0U;
  c2_info[36].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[36].name = "eml_index_class";
  c2_info[36].dominantType = "";
  c2_info[36].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[36].fileTimeLo = 1442401497U;
  c2_info[36].fileTimeHi = 0U;
  c2_info[36].mFileTimeLo = 0U;
  c2_info[36].mFileTimeHi = 0U;
  c2_info[37].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar.m!genrandu";
  c2_info[37].name = "eml_error";
  c2_info[37].dominantType = "char";
  c2_info[37].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  c2_info[37].fileTimeLo = 1442401497U;
  c2_info[37].fileTimeHi = 0U;
  c2_info[37].mFileTimeLo = 0U;
  c2_info[37].mFileTimeHi = 0U;
  c2_info[38].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/randfun/randperm.m";
  c2_info[38].name = "eml_sort_idx";
  c2_info[38].dominantType = "double";
  c2_info[38].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  c2_info[38].fileTimeLo = 1442401498U;
  c2_info[38].fileTimeHi = 0U;
  c2_info[38].mFileTimeLo = 0U;
  c2_info[38].mFileTimeHi = 0U;
  c2_info[39].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  c2_info[39].name = "eml_index_class";
  c2_info[39].dominantType = "";
  c2_info[39].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[39].fileTimeLo = 1442401497U;
  c2_info[39].fileTimeHi = 0U;
  c2_info[39].mFileTimeLo = 0U;
  c2_info[39].mFileTimeHi = 0U;
  c2_info[40].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  c2_info[40].name = "eml_size_ispow2";
  c2_info[40].dominantType = "coder.internal.indexInt";
  c2_info[40].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m";
  c2_info[40].fileTimeLo = 1442401497U;
  c2_info[40].fileTimeHi = 0U;
  c2_info[40].mFileTimeLo = 0U;
  c2_info[40].mFileTimeHi = 0U;
  c2_info[41].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m";
  c2_info[41].name = "eml_unsigned_class";
  c2_info[41].dominantType = "char";
  c2_info[41].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c2_info[41].fileTimeLo = 1442401498U;
  c2_info[41].fileTimeHi = 0U;
  c2_info[41].mFileTimeLo = 0U;
  c2_info[41].mFileTimeHi = 0U;
  c2_info[42].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m";
  c2_info[42].name = "eml_index_class";
  c2_info[42].dominantType = "";
  c2_info[42].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m";
  c2_info[42].fileTimeLo = 1442401497U;
  c2_info[42].fileTimeHi = 0U;
  c2_info[42].mFileTimeLo = 0U;
  c2_info[42].mFileTimeHi = 0U;
  c2_info[43].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  c2_info[43].name = "eml_index_plus";
  c2_info[43].dominantType = "coder.internal.indexInt";
  c2_info[43].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m";
  c2_info[43].fileTimeLo = 1442401497U;
  c2_info[43].fileTimeHi = 0U;
  c2_info[43].mFileTimeLo = 0U;
  c2_info[43].mFileTimeHi = 0U;
  c2_info[44].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m";
  c2_info[44].name = "eml_sort_le";
  c2_info[44].dominantType = "double";
  c2_info[44].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m";
  c2_info[44].fileTimeLo = 1442401498U;
  c2_info[44].fileTimeHi = 0U;
  c2_info[44].mFileTimeLo = 0U;
  c2_info[44].mFileTimeHi = 0U;
  c2_info[45].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m!eml_sort_ascending_le";
  c2_info[45].name = "eml_relop";
  c2_info[45].dominantType = "function_handle";
  c2_info[45].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m";
  c2_info[45].fileTimeLo = 1442401497U;
  c2_info[45].fileTimeHi = 0U;
  c2_info[45].mFileTimeLo = 0U;
  c2_info[45].mFileTimeHi = 0U;
  c2_info[46].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m!eml_sort_ascending_le";
  c2_info[46].name = "isnan";
  c2_info[46].dominantType = "double";
  c2_info[46].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m";
  c2_info[46].fileTimeLo = 1442401495U;
  c2_info[46].fileTimeHi = 0U;
  c2_info[46].mFileTimeLo = 0U;
  c2_info[46].mFileTimeHi = 0U;
}

static real_T c2_sum(SFc2_mod2_randacInstanceStruct *chartInstance, real_T
                     c2_x_data[3], int32_T c2_x_sizes[1])
{
  real_T c2_y;
  boolean_T c2_p;
  boolean_T c2_b_p;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_d1;
  real_T c2_d2;
  boolean_T c2_b11;
  boolean_T c2_c_p;
  boolean_T c2_b12;
  int32_T c2_i26;
  static char_T c2_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 's', 'u', 'm', '_', 's', 'p', 'e', 'c', 'i', 'a', 'l',
    'E', 'm', 'p', 't', 'y' };

  char_T c2_u[30];
  const mxArray *c2_b_y = NULL;
  boolean_T c2_b13;
  int32_T c2_i27;
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

  c2_b11 = c2_b_p;
  c2_c_p = c2_b11;
  if (!c2_c_p) {
  } else {
    c2_p = TRUE;
  }

  c2_b12 = !c2_p;
  if (c2_b12) {
  } else {
    for (c2_i26 = 0; c2_i26 < 30; c2_i26++) {
      c2_u[c2_i26] = c2_cv0[c2_i26];
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
    c2_b13 = FALSE;
  }

  if (guard1 == TRUE) {
    c2_b13 = TRUE;
  }

  if (c2_b13) {
  } else {
    for (c2_i27 = 0; c2_i27 < 36; c2_i27++) {
      c2_b_u[c2_i27] = c2_cv1[c2_i27];
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

static void c2_rand(SFc2_mod2_randacInstanceStruct *chartInstance, real_T c2_r[3])
{
  uint32_T c2_uv2[625];
  int32_T c2_i28;
  int32_T c2_k;
  real_T c2_b_k;
  real_T c2_d3;
  if (!chartInstance->c2_method_not_empty) {
    chartInstance->c2_method = 7U;
    chartInstance->c2_method_not_empty = TRUE;
  }

  if (!chartInstance->c2_c_state_not_empty) {
    c2_eml_rand_mt19937ar(chartInstance, c2_uv2);
    for (c2_i28 = 0; c2_i28 < 625; c2_i28++) {
      chartInstance->c2_c_state[c2_i28] = c2_uv2[c2_i28];
    }

    chartInstance->c2_c_state_not_empty = TRUE;
  }

  for (c2_k = 0; c2_k < 3; c2_k++) {
    c2_b_k = 1.0 + (real_T)c2_k;
    c2_d3 = c2_c_eml_rand_mt19937ar(chartInstance, chartInstance->c2_c_state);
    c2_r[(int32_T)c2_b_k - 1] = c2_d3;
  }
}

static void c2_eml_rand_mt19937ar(SFc2_mod2_randacInstanceStruct *chartInstance,
  uint32_T c2_d_state[625])
{
  real_T c2_d4;
  int32_T c2_i29;
  c2_d4 = 5489.0;
  for (c2_i29 = 0; c2_i29 < 625; c2_i29++) {
    c2_d_state[c2_i29] = 0U;
  }

  c2_b_twister_state_vector(chartInstance, c2_d_state, c2_d4);
}

static void c2_twister_state_vector(SFc2_mod2_randacInstanceStruct
  *chartInstance, uint32_T c2_mt[625], real_T c2_seed, uint32_T c2_b_mt[625])
{
  int32_T c2_i30;
  for (c2_i30 = 0; c2_i30 < 625; c2_i30++) {
    c2_b_mt[c2_i30] = c2_mt[c2_i30];
  }

  c2_b_twister_state_vector(chartInstance, c2_b_mt, c2_seed);
}

static void c2_b_eml_rand_mt19937ar(SFc2_mod2_randacInstanceStruct
  *chartInstance, uint32_T c2_d_state[625], uint32_T c2_e_state[625], real_T
  *c2_r)
{
  int32_T c2_i31;
  for (c2_i31 = 0; c2_i31 < 625; c2_i31++) {
    c2_e_state[c2_i31] = c2_d_state[c2_i31];
  }

  *c2_r = c2_c_eml_rand_mt19937ar(chartInstance, c2_e_state);
}

static void c2_eml_error(SFc2_mod2_randacInstanceStruct *chartInstance)
{
  int32_T c2_i32;
  static char_T c2_cv2[37] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'r', 'a', 'n', 'd', '_', 'i', 'n', 'v', 'a', 'l', 'i', 'd',
    'T', 'w', 'i', 's', 't', 'e', 'r', 'S', 't', 'a', 't', 'e' };

  char_T c2_u[37];
  const mxArray *c2_y = NULL;
  for (c2_i32 = 0; c2_i32 < 37; c2_i32++) {
    c2_u[c2_i32] = c2_cv2[c2_i32];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_u, 10, 0U, 1U, 0U, 2, 1, 37), FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 1U, 14,
    c2_y));
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_u;
  const mxArray *c2_y = NULL;
  SFc2_mod2_randacInstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randacInstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, FALSE);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i33;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_i33, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i33;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_mod2_randacInstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randacInstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint32_T c2_f_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_b_method, const char_T *c2_identifier)
{
  uint32_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_method),
    &c2_thisId);
  sf_mex_destroy(&c2_b_method);
  return c2_y;
}

static uint32_T c2_g_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint32_T c2_y;
  uint32_T c2_u0;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_method_not_empty = FALSE;
  } else {
    chartInstance->c2_method_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 7, 0U, 0, 0U, 0);
    c2_y = c2_u0;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static uint32_T c2_h_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_d_state, const char_T *c2_identifier)
{
  uint32_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_d_state), &c2_thisId);
  sf_mex_destroy(&c2_d_state);
  return c2_y;
}

static uint32_T c2_i_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint32_T c2_y;
  uint32_T c2_u1;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_state_not_empty = FALSE;
  } else {
    chartInstance->c2_state_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u1, 1, 7, 0U, 0, 0U, 0);
    c2_y = c2_u1;
  }

  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_j_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct *chartInstance,
  const mxArray *c2_d_state, const char_T *c2_identifier, uint32_T c2_y[625])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_d_state), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_d_state);
}

static void c2_k_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, uint32_T c2_y[625])
{
  uint32_T c2_uv3[625];
  int32_T c2_i34;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_c_state_not_empty = FALSE;
  } else {
    chartInstance->c2_c_state_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_uv3, 1, 7, 0U, 1, 0U, 1, 625);
    for (c2_i34 = 0; c2_i34 < 625; c2_i34++) {
      c2_y[c2_i34] = c2_uv3[c2_i34];
    }
  }

  sf_mex_destroy(&c2_u);
}

static void c2_l_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct *chartInstance,
  const mxArray *c2_d_state, const char_T *c2_identifier, uint32_T c2_y[2])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_d_state), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_d_state);
}

static void c2_m_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct *chartInstance,
  const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId, uint32_T c2_y[2])
{
  uint32_T c2_uv4[2];
  int32_T c2_i35;
  if (mxIsEmpty(c2_u)) {
    chartInstance->c2_b_state_not_empty = FALSE;
  } else {
    chartInstance->c2_b_state_not_empty = TRUE;
    sf_mex_import(c2_parentId, sf_mex_dup(c2_u), c2_uv4, 1, 7, 0U, 1, 0U, 1, 2);
    for (c2_i35 = 0; c2_i35 < 2; c2_i35++) {
      c2_y[c2_i35] = c2_uv4[c2_i35];
    }
  }

  sf_mex_destroy(&c2_u);
}

static uint8_T c2_n_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_mod2_randac, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_mod2_randac), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_mod2_randac);
  return c2_y;
}

static uint8_T c2_o_emlrt_marshallIn(SFc2_mod2_randacInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u2;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u2, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u2;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void c2_b_twister_state_vector(SFc2_mod2_randacInstanceStruct
  *chartInstance, uint32_T c2_mt[625], real_T c2_seed)
{
  uint32_T c2_r;
  int32_T c2_mti;
  real_T c2_b_mti;
  real_T c2_d5;
  uint32_T c2_u3;
  c2_r = 5489U;
  c2_mt[0] = 5489U;
  for (c2_mti = 0; c2_mti < 623; c2_mti++) {
    c2_b_mti = 2.0 + (real_T)c2_mti;
    c2_d5 = muDoubleScalarRound(c2_b_mti - 1.0);
    if (c2_d5 < 4.294967296E+9) {
      if (c2_d5 >= 0.0) {
        c2_u3 = (uint32_T)c2_d5;
      } else {
        c2_u3 = 0U;
      }
    } else if (c2_d5 >= 4.294967296E+9) {
      c2_u3 = MAX_uint32_T;
    } else {
      c2_u3 = 0U;
    }

    c2_r = (c2_r ^ c2_r >> 30U) * 1812433253U + c2_u3;
    c2_mt[(int32_T)c2_b_mti - 1] = c2_r;
  }

  c2_mt[624] = 624U;
}

static real_T c2_c_eml_rand_mt19937ar(SFc2_mod2_randacInstanceStruct
  *chartInstance, uint32_T c2_d_state[625])
{
  int32_T c2_i36;
  uint32_T c2_u[2];
  int32_T c2_j;
  real_T c2_b_j;
  uint32_T c2_mti;
  int32_T c2_kk;
  real_T c2_b_kk;
  uint32_T c2_y;
  uint32_T c2_b_y;
  uint32_T c2_c_y;
  int32_T c2_c_kk;
  uint32_T c2_d_y;
  uint32_T c2_e_y;
  uint32_T c2_f_y;
  uint32_T c2_g_y;
  real_T c2_a;
  real_T c2_h_y;
  real_T c2_b;
  real_T c2_b_r;
  boolean_T c2_b14;
  boolean_T c2_isvalid;
  int32_T c2_k;
  int32_T c2_b_a;
  real_T c2_d6;
  boolean_T guard1 = FALSE;
  int32_T exitg1;
  boolean_T exitg2;

  /* <LEGAL>   This is a uniform (0,1) pseudorandom number generator based on: */
  /* <LEGAL> */
  /* <LEGAL>    A C-program for MT19937, with initialization improved 2002/1/26. */
  /* <LEGAL>    Coded by Takuji Nishimura and Makoto Matsumoto. */
  /* <LEGAL> */
  /* <LEGAL>    Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura, */
  /* <LEGAL>    All rights reserved. */
  /* <LEGAL> */
  /* <LEGAL>    Redistribution and use in source and binary forms, with or without */
  /* <LEGAL>    modification, are permitted provided that the following conditions */
  /* <LEGAL>    are met: */
  /* <LEGAL> */
  /* <LEGAL>      1. Redistributions of source code must retain the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer. */
  /* <LEGAL> */
  /* <LEGAL>      2. Redistributions in binary form must reproduce the above copyright */
  /* <LEGAL>         notice, this list of conditions and the following disclaimer in the */
  /* <LEGAL>         documentation and/or other materials provided with the distribution. */
  /* <LEGAL> */
  /* <LEGAL>      3. The names of its contributors may not be used to endorse or promote */
  /* <LEGAL>         products derived from this software without specific prior written */
  /* <LEGAL>         permission. */
  /* <LEGAL> */
  /* <LEGAL>    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS */
  /* <LEGAL>    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT */
  /* <LEGAL>    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR */
  /* <LEGAL>    A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR */
  /* <LEGAL>    CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, */
  /* <LEGAL>    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, */
  /* <LEGAL>    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR */
  /* <LEGAL>    PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF */
  /* <LEGAL>    LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING */
  /* <LEGAL>    NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS */
  /* <LEGAL>    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
  do {
    exitg1 = 0;
    for (c2_i36 = 0; c2_i36 < 2; c2_i36++) {
      c2_u[c2_i36] = 0U;
    }

    for (c2_j = 0; c2_j < 2; c2_j++) {
      c2_b_j = 1.0 + (real_T)c2_j;
      c2_mti = c2_d_state[624] + 1U;
      if ((real_T)c2_mti >= 625.0) {
        for (c2_kk = 0; c2_kk < 227; c2_kk++) {
          c2_b_kk = 1.0 + (real_T)c2_kk;
          c2_y = (c2_d_state[(int32_T)c2_b_kk - 1] & 2147483648U) | (c2_d_state
            [(int32_T)(c2_b_kk + 1.0) - 1] & 2147483647U);
          c2_b_y = c2_y;
          c2_c_y = c2_b_y;
          if ((real_T)(c2_c_y & 1U) == 0.0) {
            c2_c_y >>= 1U;
          } else {
            c2_c_y = c2_c_y >> 1U ^ 2567483615U;
          }

          c2_d_state[(int32_T)c2_b_kk - 1] = c2_d_state[(int32_T)(c2_b_kk +
            397.0) - 1] ^ c2_c_y;
        }

        for (c2_c_kk = 0; c2_c_kk < 396; c2_c_kk++) {
          c2_b_kk = 228.0 + (real_T)c2_c_kk;
          c2_y = (c2_d_state[(int32_T)c2_b_kk - 1] & 2147483648U) | (c2_d_state
            [(int32_T)(c2_b_kk + 1.0) - 1] & 2147483647U);
          c2_d_y = c2_y;
          c2_e_y = c2_d_y;
          if ((real_T)(c2_e_y & 1U) == 0.0) {
            c2_e_y >>= 1U;
          } else {
            c2_e_y = c2_e_y >> 1U ^ 2567483615U;
          }

          c2_d_state[(int32_T)c2_b_kk - 1] = c2_d_state[(int32_T)((c2_b_kk + 1.0)
            - 228.0) - 1] ^ c2_e_y;
        }

        c2_y = (c2_d_state[623] & 2147483648U) | (c2_d_state[0] & 2147483647U);
        c2_f_y = c2_y;
        c2_g_y = c2_f_y;
        if ((real_T)(c2_g_y & 1U) == 0.0) {
          c2_g_y >>= 1U;
        } else {
          c2_g_y = c2_g_y >> 1U ^ 2567483615U;
        }

        c2_d_state[623] = c2_d_state[396] ^ c2_g_y;
        c2_mti = 1U;
      }

      c2_y = c2_d_state[(int32_T)(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)c2_mti, 1, 625, 1, 0) - 1];
      c2_d_state[624] = c2_mti;
      c2_y ^= c2_y >> 11U;
      c2_y ^= c2_y << 7U & 2636928640U;
      c2_y ^= c2_y << 15U & 4022730752U;
      c2_y ^= c2_y >> 18U;
      c2_u[(int32_T)c2_b_j - 1] = c2_y;
    }

    c2_u[0] >>= 5U;
    c2_u[1] >>= 6U;
    c2_a = (real_T)c2_u[0];
    c2_h_y = c2_a * 6.7108864E+7;
    c2_b = c2_h_y + (real_T)c2_u[1];
    c2_b_r = 1.1102230246251565E-16 * c2_b;
    if (c2_b_r == 0.0) {
      guard1 = FALSE;
      if ((real_T)c2_d_state[624] >= 1.0) {
        if ((real_T)c2_d_state[624] < 625.0) {
          c2_b14 = TRUE;
        } else {
          guard1 = TRUE;
        }
      } else {
        guard1 = TRUE;
      }

      if (guard1 == TRUE) {
        c2_b14 = FALSE;
      }

      c2_isvalid = c2_b14;
      if (c2_isvalid) {
        c2_isvalid = FALSE;
        c2_k = 0;
        exitg2 = FALSE;
        while ((exitg2 == FALSE) && (c2_k + 1 < 625)) {
          if ((real_T)c2_d_state[c2_k] == 0.0) {
            c2_b_a = c2_k + 1;
            c2_k = c2_b_a;
          } else {
            c2_isvalid = TRUE;
            exitg2 = TRUE;
          }
        }
      }

      if (!c2_isvalid) {
        c2_eml_error(chartInstance);
        c2_d6 = 5489.0;
        c2_b_twister_state_vector(chartInstance, c2_d_state, c2_d6);
      }
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return c2_b_r;
}

static void init_dsm_address_info(SFc2_mod2_randacInstanceStruct *chartInstance)
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

void sf_c2_mod2_randac_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2865634299U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(255881522U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1487163901U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3247395696U);
}

mxArray *sf_c2_mod2_randac_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("huB2sdW336SGWjvVU2KLIG");
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

mxArray *sf_c2_mod2_randac_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c2_mod2_randac(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[5],T\"dacout\",},{M[4],M[0],T\"method\",S'l','i','p'{{M1x2[512 518],M[1],T\"/cad/eda/matlab/R2013a/toolbox/eml/lib/matlab/randfun/eml_rand.m\"}}},{M[4],M[0],T\"rinx\",S'l','i','p'{{M1x2[1861 1865],M[0],}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"/cad/eda/matlab/R2013a/toolbox/eml/lib/matlab/randfun/eml_rand_mcg16807_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[166 171],M[1],T\"/cad/eda/matlab/R2013a/toolbox/eml/lib/matlab/randfun/eml_rand_mt19937ar_stateful.m\"}}},{M[4],M[0],T\"state\",S'l','i','p'{{M1x2[165 170],M[1],T\"/cad/eda/matlab/R2013a/toolbox/eml/lib/matlab/randfun/eml_rand_shr3cong_stateful.m\"}}},{M[8],M[0],T\"is_active_c2_mod2_randac\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_mod2_randac_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_mod2_randacInstanceStruct *chartInstance;
    chartInstance = (SFc2_mod2_randacInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _mod2_randacMachineNumber_,
           2,
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
          init_script_number_translation(_mod2_randacMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_mod2_randacMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _mod2_randacMachineNumber_,
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2107);
        _SFD_CV_INIT_EML_IF(0,1,0,1868,1885,-1,1945);
        _SFD_CV_INIT_EML_IF(0,1,1,1947,1964,1999,2102);
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
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          uint8_T *c2_dacin;
          real_T *c2_dacout;
          real_T *c2_rotflag;
          real_T *c2_numele;
          real_T (*c2_elems)[3];
          c2_elems = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 3);
          c2_numele = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c2_rotflag = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c2_dacout = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c2_dacin = (uint8_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c2_dacin);
          _SFD_SET_DATA_VALUE_PTR(1U, c2_dacout);
          _SFD_SET_DATA_VALUE_PTR(2U, c2_rotflag);
          _SFD_SET_DATA_VALUE_PTR(3U, c2_numele);
          _SFD_SET_DATA_VALUE_PTR(4U, *c2_elems);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _mod2_randacMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "qqweZ1f11xI8UKWR2X6TdH";
}

static void sf_opaque_initialize_c2_mod2_randac(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_mod2_randacInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c2_mod2_randac((SFc2_mod2_randacInstanceStruct*)
    chartInstanceVar);
  initialize_c2_mod2_randac((SFc2_mod2_randacInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_mod2_randac(void *chartInstanceVar)
{
  enable_c2_mod2_randac((SFc2_mod2_randacInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_mod2_randac(void *chartInstanceVar)
{
  disable_c2_mod2_randac((SFc2_mod2_randacInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_mod2_randac(void *chartInstanceVar)
{
  sf_c2_mod2_randac((SFc2_mod2_randacInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_mod2_randac(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_mod2_randac
    ((SFc2_mod2_randacInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_mod2_randac();/* state var info */
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

extern void sf_internal_set_sim_state_c2_mod2_randac(SimStruct* S, const mxArray
  *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_mod2_randac();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_mod2_randac((SFc2_mod2_randacInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_mod2_randac(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_mod2_randac(S);
}

static void sf_opaque_set_sim_state_c2_mod2_randac(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_mod2_randac(S, st);
}

static void sf_opaque_terminate_c2_mod2_randac(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_mod2_randacInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_mod2_randac_optimization_info();
    }

    finalize_c2_mod2_randac((SFc2_mod2_randacInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_mod2_randac((SFc2_mod2_randacInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_mod2_randac(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_mod2_randac((SFc2_mod2_randacInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_mod2_randac(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_mod2_randac_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,4);
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
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3565187946U));
  ssSetChecksum1(S,(3086053922U));
  ssSetChecksum2(S,(1643815960U));
  ssSetChecksum3(S,(3220111275U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_mod2_randac(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_mod2_randac(SimStruct *S)
{
  SFc2_mod2_randacInstanceStruct *chartInstance;
  chartInstance = (SFc2_mod2_randacInstanceStruct *)utMalloc(sizeof
    (SFc2_mod2_randacInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_mod2_randacInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_mod2_randac;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_mod2_randac;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_mod2_randac;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_mod2_randac;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_mod2_randac;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_mod2_randac;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_mod2_randac;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_mod2_randac;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_mod2_randac;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_mod2_randac;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_mod2_randac;
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

void c2_mod2_randac_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_mod2_randac(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_mod2_randac(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_mod2_randac(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_mod2_randac_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
