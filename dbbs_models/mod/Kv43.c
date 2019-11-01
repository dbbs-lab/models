/* Created by Language version: 7.5.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "scoplib_ansi.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__Kv4_3
#define _nrn_initial _nrn_initial__Kv4_3
#define nrn_cur _nrn_cur__Kv4_3
#define _nrn_current _nrn_current__Kv4_3
#define nrn_jacob _nrn_jacob__Kv4_3
#define nrn_state _nrn_state__Kv4_3
#define _net_receive _net_receive__Kv4_3 
#define _f_rate _f_rate__Kv4_3 
#define rate rate__Kv4_3 
#define states states__Kv4_3 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define Aalpha_a _p[0]
#define Kalpha_a _p[1]
#define V0alpha_a _p[2]
#define Abeta_a _p[3]
#define Kbeta_a _p[4]
#define V0beta_a _p[5]
#define Aalpha_b _p[6]
#define Kalpha_b _p[7]
#define V0alpha_b _p[8]
#define Abeta_b _p[9]
#define Kbeta_b _p[10]
#define V0beta_b _p[11]
#define V0_ainf _p[12]
#define K_ainf _p[13]
#define V0_binf _p[14]
#define K_binf _p[15]
#define gkbar _p[16]
#define ik _p[17]
#define a_inf _p[18]
#define b_inf _p[19]
#define tau_a _p[20]
#define tau_b _p[21]
#define g _p[22]
#define alpha_a _p[23]
#define beta_a _p[24]
#define alpha_b _p[25]
#define beta_b _p[26]
#define a _p[27]
#define b _p[28]
#define Da _p[29]
#define Db _p[30]
#define ek _p[31]
#define v _p[32]
#define _g _p[33]
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_alp_b(void);
 static void _hoc_alp_a(void);
 static void _hoc_bet_b(void);
 static void _hoc_bet_a(void);
 static void _hoc_linoid(void);
 static void _hoc_rate(void);
 static void _hoc_sigm(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_Kv4_3", _hoc_setdata,
 "alp_b_Kv4_3", _hoc_alp_b,
 "alp_a_Kv4_3", _hoc_alp_a,
 "bet_b_Kv4_3", _hoc_bet_b,
 "bet_a_Kv4_3", _hoc_bet_a,
 "linoid_Kv4_3", _hoc_linoid,
 "rate_Kv4_3", _hoc_rate,
 "sigm_Kv4_3", _hoc_sigm,
 0, 0
};
#define alp_b alp_b_Kv4_3
#define alp_a alp_a_Kv4_3
#define bet_b bet_b_Kv4_3
#define bet_a bet_a_Kv4_3
#define linoid linoid_Kv4_3
#define sigm sigm_Kv4_3
 extern double alp_b( _threadargsprotocomma_ double );
 extern double alp_a( _threadargsprotocomma_ double );
 extern double bet_b( _threadargsprotocomma_ double );
 extern double bet_a( _threadargsprotocomma_ double );
 extern double linoid( _threadargsprotocomma_ double , double );
 extern double sigm( _threadargsprotocomma_ double , double );
 
static void _check_rate(double*, Datum*, Datum*, _NrnThread*); 
static void _check_table_thread(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, int _type) {
   _check_rate(_p, _ppvar, _thread, _nt);
 }
 /* declare global and static user variables */
#define usetable usetable_Kv4_3
 double usetable = 1;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "usetable_Kv4_3", 0, 1,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Aalpha_a_Kv4_3", "/ms",
 "Kalpha_a_Kv4_3", "mV",
 "V0alpha_a_Kv4_3", "mV",
 "Abeta_a_Kv4_3", "/ms",
 "Kbeta_a_Kv4_3", "mV",
 "V0beta_a_Kv4_3", "mV",
 "Aalpha_b_Kv4_3", "/ms",
 "Kalpha_b_Kv4_3", "mV",
 "V0alpha_b_Kv4_3", "mV",
 "Abeta_b_Kv4_3", "/ms",
 "Kbeta_b_Kv4_3", "mV",
 "V0beta_b_Kv4_3", "mV",
 "V0_ainf_Kv4_3", "mV",
 "K_ainf_Kv4_3", "mV",
 "V0_binf_Kv4_3", "mV",
 "K_binf_Kv4_3", "mV",
 "gkbar_Kv4_3", "mho/cm2",
 "ik_Kv4_3", "mA/cm2",
 "tau_a_Kv4_3", "ms",
 "tau_b_Kv4_3", "ms",
 "g_Kv4_3", "mho/cm2",
 "alpha_a_Kv4_3", "/ms",
 "beta_a_Kv4_3", "/ms",
 "alpha_b_Kv4_3", "/ms",
 "beta_b_Kv4_3", "/ms",
 0,0
};
 static double a0 = 0;
 static double b0 = 0;
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "usetable_Kv4_3", &usetable_Kv4_3,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(_NrnThread*, _Memb_list*, int);
static void nrn_state(_NrnThread*, _Memb_list*, int);
 static void nrn_cur(_NrnThread*, _Memb_list*, int);
static void  nrn_jacob(_NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(_NrnThread*, _Memb_list*, int);
static void _ode_matsol(_NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.5.0",
"Kv4_3",
 "Aalpha_a_Kv4_3",
 "Kalpha_a_Kv4_3",
 "V0alpha_a_Kv4_3",
 "Abeta_a_Kv4_3",
 "Kbeta_a_Kv4_3",
 "V0beta_a_Kv4_3",
 "Aalpha_b_Kv4_3",
 "Kalpha_b_Kv4_3",
 "V0alpha_b_Kv4_3",
 "Abeta_b_Kv4_3",
 "Kbeta_b_Kv4_3",
 "V0beta_b_Kv4_3",
 "V0_ainf_Kv4_3",
 "K_ainf_Kv4_3",
 "V0_binf_Kv4_3",
 "K_binf_Kv4_3",
 "gkbar_Kv4_3",
 0,
 "ik_Kv4_3",
 "a_inf_Kv4_3",
 "b_inf_Kv4_3",
 "tau_a_Kv4_3",
 "tau_b_Kv4_3",
 "g_Kv4_3",
 "alpha_a_Kv4_3",
 "beta_a_Kv4_3",
 "alpha_b_Kv4_3",
 "beta_b_Kv4_3",
 0,
 "a_Kv4_3",
 "b_Kv4_3",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 34, _prop);
 	/*initialize range parameters*/
 	Aalpha_a = 0.8147;
 	Kalpha_a = -23.3271;
 	V0alpha_a = -9.17203;
 	Abeta_a = 0.1655;
 	Kbeta_a = 19.4718;
 	V0beta_a = -18.2791;
 	Aalpha_b = 0.0368;
 	Kalpha_b = 12.8433;
 	V0alpha_b = -111.332;
 	Abeta_b = 0.0345;
 	Kbeta_b = -8.90123;
 	V0beta_b = -49.9537;
 	V0_ainf = -38;
 	K_ainf = -17;
 	V0_binf = -78.8;
 	K_binf = 8.4;
 	gkbar = 0.0032;
 	_prop->param = _p;
 	_prop->param_size = 34;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _thread_mem_init(Datum*);
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _Kv43_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 5);
  _extcall_thread = (Datum*)ecalloc(4, sizeof(Datum));
  _thread_mem_init(_extcall_thread);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 1, _thread_mem_init);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
     _nrn_thread_table_reg(_mechtype, _check_table_thread);
  hoc_register_prop_size(_mechtype, 34, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Kv4_3 C:/Users/Elisa/Desktop/microcircuit-20191001T081556Z-001/microcircuit_example/Granule_py/mod_files/Kv43.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double *_t_a_inf;
 static double *_t_tau_a;
 static double *_t_b_inf;
 static double *_t_tau_b;
static int _reset;
static char *modelname = "Cerebellum Granule Cell Model";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int _f_rate(_threadargsprotocomma_ double);
static int rate(_threadargsprotocomma_ double);
 
#define _deriv1_advance _thread[0]._i
#define _dith1 1
#define _recurse _thread[2]._i
#define _newtonspace1 _thread[3]._pvoid
extern void* nrn_cons_newtonspace(int);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static void _n_rate(_threadargsprotocomma_ double _lv);
 static int _slist2[2];
  static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset = 0; {
   rate ( _threadargscomma_ v ) ;
   Da = ( a_inf - a ) / tau_a ;
   Db = ( b_inf - b ) / tau_b ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
 rate ( _threadargscomma_ v ) ;
 Da = Da  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_a )) ;
 Db = Db  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tau_b )) ;
  return 0;
}
 /*END CVODE*/
 
static int states (double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0; int error = 0;
 { double* _savstate1 = _thread[_dith1]._pval;
 double* _dlist2 = _thread[_dith1]._pval + 2;
 int _counte = -1;
 if (!_recurse) {
 _recurse = 1;
 {int _id; for(_id=0; _id < 2; _id++) { _savstate1[_id] = _p[_slist1[_id]];}}
 error = nrn_newton_thread(_newtonspace1, 2,_slist2, _p, states, _dlist2, _ppvar, _thread, _nt);
 _recurse = 0; if(error) {abort_run(error);}}
 {
   rate ( _threadargscomma_ v ) ;
   Da = ( a_inf - a ) / tau_a ;
   Db = ( b_inf - b ) / tau_b ;
   {int _id; for(_id=0; _id < 2; _id++) {
if (_deriv1_advance) {
 _dlist2[++_counte] = _p[_dlist1[_id]] - (_p[_slist1[_id]] - _savstate1[_id])/dt;
 }else{
_dlist2[++_counte] = _p[_slist1[_id]] - _savstate1[_id];}}}
 } }
 return _reset;}
 
double alp_a ( _threadargsprotocomma_ double _lv ) {
   double _lalp_a;
 double _lQ10 ;
 _lQ10 = pow( 3.0 , ( ( celsius - 25.5 ) / 10.0 ) ) ;
   _lalp_a = _lQ10 * Aalpha_a * sigm ( _threadargscomma_ _lv - V0alpha_a , Kalpha_a ) ;
   
return _lalp_a;
 }
 
static void _hoc_alp_a(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alp_a ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double bet_a ( _threadargsprotocomma_ double _lv ) {
   double _lbet_a;
 double _lQ10 ;
 _lQ10 = pow( 3.0 , ( ( celsius - 25.5 ) / 10.0 ) ) ;
   _lbet_a = _lQ10 * Abeta_a / ( exp ( ( _lv - V0beta_a ) / Kbeta_a ) ) ;
   
return _lbet_a;
 }
 
static void _hoc_bet_a(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  bet_a ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double alp_b ( _threadargsprotocomma_ double _lv ) {
   double _lalp_b;
 double _lQ10 ;
 _lQ10 = pow( 3.0 , ( ( celsius - 25.5 ) / 10.0 ) ) ;
   _lalp_b = _lQ10 * Aalpha_b * sigm ( _threadargscomma_ _lv - V0alpha_b , Kalpha_b ) ;
   
return _lalp_b;
 }
 
static void _hoc_alp_b(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alp_b ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double bet_b ( _threadargsprotocomma_ double _lv ) {
   double _lbet_b;
 double _lQ10 ;
 _lQ10 = pow( 3.0 , ( ( celsius - 25.5 ) / 10.0 ) ) ;
   _lbet_b = _lQ10 * Abeta_b * sigm ( _threadargscomma_ _lv - V0beta_b , Kbeta_b ) ;
   
return _lbet_b;
 }
 
static void _hoc_bet_b(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  bet_b ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 static double _mfac_rate, _tmin_rate;
  static void _check_rate(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  static int _maktable=1; int _i, _j, _ix = 0;
  double _xi, _tmax;
  static double _sav_Aalpha_a;
  static double _sav_Kalpha_a;
  static double _sav_V0alpha_a;
  static double _sav_Abeta_a;
  static double _sav_Kbeta_a;
  static double _sav_V0beta_a;
  static double _sav_Aalpha_b;
  static double _sav_Kalpha_b;
  static double _sav_V0alpha_b;
  static double _sav_Abeta_b;
  static double _sav_Kbeta_b;
  static double _sav_V0beta_b;
  static double _sav_celsius;
  if (!usetable) {return;}
  if (_sav_Aalpha_a != Aalpha_a) { _maktable = 1;}
  if (_sav_Kalpha_a != Kalpha_a) { _maktable = 1;}
  if (_sav_V0alpha_a != V0alpha_a) { _maktable = 1;}
  if (_sav_Abeta_a != Abeta_a) { _maktable = 1;}
  if (_sav_Kbeta_a != Kbeta_a) { _maktable = 1;}
  if (_sav_V0beta_a != V0beta_a) { _maktable = 1;}
  if (_sav_Aalpha_b != Aalpha_b) { _maktable = 1;}
  if (_sav_Kalpha_b != Kalpha_b) { _maktable = 1;}
  if (_sav_V0alpha_b != V0alpha_b) { _maktable = 1;}
  if (_sav_Abeta_b != Abeta_b) { _maktable = 1;}
  if (_sav_Kbeta_b != Kbeta_b) { _maktable = 1;}
  if (_sav_V0beta_b != V0beta_b) { _maktable = 1;}
  if (_sav_celsius != celsius) { _maktable = 1;}
  if (_maktable) { double _x, _dx; _maktable=0;
   _tmin_rate =  - 100.0 ;
   _tmax =  30.0 ;
   _dx = (_tmax - _tmin_rate)/13000.; _mfac_rate = 1./_dx;
   for (_i=0, _x=_tmin_rate; _i < 13001; _x += _dx, _i++) {
    _f_rate(_p, _ppvar, _thread, _nt, _x);
    _t_a_inf[_i] = a_inf;
    _t_tau_a[_i] = tau_a;
    _t_b_inf[_i] = b_inf;
    _t_tau_b[_i] = tau_b;
   }
   _sav_Aalpha_a = Aalpha_a;
   _sav_Kalpha_a = Kalpha_a;
   _sav_V0alpha_a = V0alpha_a;
   _sav_Abeta_a = Abeta_a;
   _sav_Kbeta_a = Kbeta_a;
   _sav_V0beta_a = V0beta_a;
   _sav_Aalpha_b = Aalpha_b;
   _sav_Kalpha_b = Kalpha_b;
   _sav_V0alpha_b = V0alpha_b;
   _sav_Abeta_b = Abeta_b;
   _sav_Kbeta_b = Kbeta_b;
   _sav_V0beta_b = V0beta_b;
   _sav_celsius = celsius;
  }
 }

 static int rate(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _lv) { 
#if 0
_check_rate(_p, _ppvar, _thread, _nt);
#endif
 _n_rate(_p, _ppvar, _thread, _nt, _lv);
 return 0;
 }

 static void _n_rate(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _lv){ int _i, _j;
 double _xi, _theta;
 if (!usetable) {
 _f_rate(_p, _ppvar, _thread, _nt, _lv); return; 
}
 _xi = _mfac_rate * (_lv - _tmin_rate);
 if (isnan(_xi)) {
  a_inf = _xi;
  tau_a = _xi;
  b_inf = _xi;
  tau_b = _xi;
  return;
 }
 if (_xi <= 0.) {
 a_inf = _t_a_inf[0];
 tau_a = _t_tau_a[0];
 b_inf = _t_b_inf[0];
 tau_b = _t_tau_b[0];
 return; }
 if (_xi >= 13000.) {
 a_inf = _t_a_inf[13000];
 tau_a = _t_tau_a[13000];
 b_inf = _t_b_inf[13000];
 tau_b = _t_tau_b[13000];
 return; }
 _i = (int) _xi;
 _theta = _xi - (double)_i;
 a_inf = _t_a_inf[_i] + _theta*(_t_a_inf[_i+1] - _t_a_inf[_i]);
 tau_a = _t_tau_a[_i] + _theta*(_t_tau_a[_i+1] - _t_tau_a[_i]);
 b_inf = _t_b_inf[_i] + _theta*(_t_b_inf[_i+1] - _t_b_inf[_i]);
 tau_b = _t_tau_b[_i] + _theta*(_t_tau_b[_i+1] - _t_tau_b[_i]);
 }

 
static int  _f_rate ( _threadargsprotocomma_ double _lv ) {
   double _la_a , _lb_a , _la_b , _lb_b ;
 _la_a = alp_a ( _threadargscomma_ _lv ) ;
   _lb_a = bet_a ( _threadargscomma_ _lv ) ;
   _la_b = alp_b ( _threadargscomma_ _lv ) ;
   _lb_b = bet_b ( _threadargscomma_ _lv ) ;
   a_inf = 1.0 / ( 1.0 + exp ( ( _lv - V0_ainf ) / K_ainf ) ) ;
   tau_a = 1.0 / ( _la_a + _lb_a ) ;
   b_inf = 1.0 / ( 1.0 + exp ( ( _lv - V0_binf ) / K_binf ) ) ;
   tau_b = 1.0 / ( _la_b + _lb_b ) ;
    return 0; }
 
static void _hoc_rate(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 
#if 1
 _check_rate(_p, _ppvar, _thread, _nt);
#endif
 _r = 1.;
 rate ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double linoid ( _threadargsprotocomma_ double _lx , double _ly ) {
   double _llinoid;
 if ( fabs ( _lx / _ly ) < 1e-6 ) {
     _llinoid = _ly * ( 1.0 - _lx / _ly / 2.0 ) ;
     }
   else {
     _llinoid = _lx / ( exp ( _lx / _ly ) - 1.0 ) ;
     }
   
return _llinoid;
 }
 
static void _hoc_linoid(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  linoid ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
double sigm ( _threadargsprotocomma_ double _lx , double _ly ) {
   double _lsigm;
 _lsigm = 1.0 / ( exp ( _lx / _ly ) + 1.0 ) ;
   
return _lsigm;
 }
 
static void _hoc_sigm(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  sigm ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_mem_init(Datum* _thread) {
   _thread[_dith1]._pval = (double*)ecalloc(4, sizeof(double));
   _newtonspace1 = nrn_cons_newtonspace(2);
 }
 
static void _thread_cleanup(Datum* _thread) {
   free((void*)(_thread[_dith1]._pval));
   nrn_destroy_newtonspace(_newtonspace1);
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  a = a0;
  b = b0;
 {
   rate ( _threadargscomma_ v ) ;
   a = a_inf ;
   b = b_inf ;
   }
 
}
}

static void nrn_init(_NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];

#if 0
 _check_rate(_p, _ppvar, _thread, _nt);
#endif
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ek = _ion_ek;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   g = gkbar * a * a * a * b ;
   ik = g * ( v - ek ) ;
   alpha_a = alp_a ( _threadargscomma_ v ) ;
   beta_a = bet_a ( _threadargscomma_ v ) ;
   alpha_b = alp_b ( _threadargscomma_ v ) ;
   beta_b = bet_b ( _threadargscomma_ v ) ;
   }
 _current += ik;

} return _current;
}

static void nrn_cur(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  ek = _ion_ek;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}
 
}

static void nrn_state(_NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  ek = _ion_ek;
 {  _deriv1_advance = 1;
 derivimplicit_thread(2, _slist1, _dlist1, _p, states, _ppvar, _thread, _nt);
_deriv1_advance = 0;
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 2; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(a) - _p;  _dlist1[0] = &(Da) - _p;
 _slist1[1] = &(b) - _p;  _dlist1[1] = &(Db) - _p;
 _slist2[0] = &(a) - _p;
 _slist2[1] = &(b) - _p;
   _t_a_inf = makevector(13001*sizeof(double));
   _t_tau_a = makevector(13001*sizeof(double));
   _t_b_inf = makevector(13001*sizeof(double));
   _t_tau_b = makevector(13001*sizeof(double));
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
