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
 
#define nrn_init _nrn_init__GRC_NA
#define _nrn_initial _nrn_initial__GRC_NA
#define nrn_cur _nrn_cur__GRC_NA
#define _nrn_current _nrn_current__GRC_NA
#define nrn_jacob _nrn_jacob__GRC_NA
#define nrn_state _nrn_state__GRC_NA
#define _net_receive _net_receive__GRC_NA 
#define kstates kstates__GRC_NA 
 
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
#define gnabar _p[0]
#define Aalfa _p[1]
#define Valfa _p[2]
#define Abeta _p[3]
#define Vbeta _p[4]
#define Agamma _p[5]
#define Adelta _p[6]
#define Aepsilon _p[7]
#define Ateta _p[8]
#define Vteta _p[9]
#define ACon _p[10]
#define ACoff _p[11]
#define AOon _p[12]
#define AOoff _p[13]
#define n1 _p[14]
#define n2 _p[15]
#define n3 _p[16]
#define n4 _p[17]
#define ina _p[18]
#define g _p[19]
#define gamma _p[20]
#define delta _p[21]
#define epsilon _p[22]
#define Con _p[23]
#define Coff _p[24]
#define Oon _p[25]
#define Ooff _p[26]
#define C1 _p[27]
#define C2 _p[28]
#define C3 _p[29]
#define C4 _p[30]
#define C5 _p[31]
#define O _p[32]
#define OB _p[33]
#define I1 _p[34]
#define I2 _p[35]
#define I3 _p[36]
#define I4 _p[37]
#define I5 _p[38]
#define I6 _p[39]
#define ena _p[40]
#define a _p[41]
#define b _p[42]
#define Q10 _p[43]
#define DC1 _p[44]
#define DC2 _p[45]
#define DC3 _p[46]
#define DC4 _p[47]
#define DC5 _p[48]
#define DO _p[49]
#define DOB _p[50]
#define DI1 _p[51]
#define DI2 _p[52]
#define DI3 _p[53]
#define DI4 _p[54]
#define DI5 _p[55]
#define DI6 _p[56]
#define v _p[57]
#define _g _p[58]
#define _ion_ena	*_ppvar[0]._pval
#define _ion_ina	*_ppvar[1]._pval
#define _ion_dinadv	*_ppvar[2]._pval
 
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
 static void _hoc_alfa(void);
 static void _hoc_beta(void);
 static void _hoc_teta(void);
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
 "setdata_GRC_NA", _hoc_setdata,
 "alfa_GRC_NA", _hoc_alfa,
 "beta_GRC_NA", _hoc_beta,
 "teta_GRC_NA", _hoc_teta,
 0, 0
};
#define alfa alfa_GRC_NA
#define beta beta_GRC_NA
#define teta teta_GRC_NA
 extern double alfa( _threadargsprotocomma_ double );
 extern double beta( _threadargsprotocomma_ double );
 extern double teta( _threadargsprotocomma_ double );
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gnabar_GRC_NA", "mho/cm2",
 "Aalfa_GRC_NA", "/ms",
 "Valfa_GRC_NA", "/mV",
 "Abeta_GRC_NA", "/ms",
 "Vbeta_GRC_NA", "/mV",
 "Agamma_GRC_NA", "/ms",
 "Adelta_GRC_NA", "/ms",
 "Aepsilon_GRC_NA", "/ms",
 "Ateta_GRC_NA", "/ms",
 "ACon_GRC_NA", "/ms",
 "ACoff_GRC_NA", "/ms",
 "AOon_GRC_NA", "/ms",
 "AOoff_GRC_NA", "/ms",
 "ina_GRC_NA", "mA/cm2",
 "g_GRC_NA", "mho/cm2",
 0,0
};
 static double C50 = 0;
 static double C40 = 0;
 static double C30 = 0;
 static double C20 = 0;
 static double C10 = 0;
 static double I60 = 0;
 static double I50 = 0;
 static double I40 = 0;
 static double I30 = 0;
 static double I20 = 0;
 static double I10 = 0;
 static double OB0 = 0;
 static double O0 = 0;
 static double delta_t = 0.01;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
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
"GRC_NA",
 "gnabar_GRC_NA",
 "Aalfa_GRC_NA",
 "Valfa_GRC_NA",
 "Abeta_GRC_NA",
 "Vbeta_GRC_NA",
 "Agamma_GRC_NA",
 "Adelta_GRC_NA",
 "Aepsilon_GRC_NA",
 "Ateta_GRC_NA",
 "Vteta_GRC_NA",
 "ACon_GRC_NA",
 "ACoff_GRC_NA",
 "AOon_GRC_NA",
 "AOoff_GRC_NA",
 "n1_GRC_NA",
 "n2_GRC_NA",
 "n3_GRC_NA",
 "n4_GRC_NA",
 0,
 "ina_GRC_NA",
 "g_GRC_NA",
 "gamma_GRC_NA",
 "delta_GRC_NA",
 "epsilon_GRC_NA",
 "Con_GRC_NA",
 "Coff_GRC_NA",
 "Oon_GRC_NA",
 "Ooff_GRC_NA",
 0,
 "C1_GRC_NA",
 "C2_GRC_NA",
 "C3_GRC_NA",
 "C4_GRC_NA",
 "C5_GRC_NA",
 "O_GRC_NA",
 "OB_GRC_NA",
 "I1_GRC_NA",
 "I2_GRC_NA",
 "I3_GRC_NA",
 "I4_GRC_NA",
 "I5_GRC_NA",
 "I6_GRC_NA",
 0,
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 59, _prop);
 	/*initialize range parameters*/
 	gnabar = 0.013;
 	Aalfa = 353.91;
 	Valfa = 13.99;
 	Abeta = 1.272;
 	Vbeta = 13.99;
 	Agamma = 150;
 	Adelta = 40;
 	Aepsilon = 1.75;
 	Ateta = 0.0201;
 	Vteta = 25;
 	ACon = 0.005;
 	ACoff = 0.5;
 	AOon = 0.75;
 	AOoff = 0.005;
 	n1 = 5.422;
 	n2 = 3.279;
 	n3 = 1.83;
 	n4 = 0.738;
 	_prop->param = _p;
 	_prop->param_size = 59;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ena */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _thread_cleanup(Datum*);
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, _NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _GRC_NA_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("na", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 3);
  _extcall_thread = (Datum*)ecalloc(2, sizeof(Datum));
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 59, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 GRC_NA C:/Users/Elisa/Desktop/microcircuit-20191001T081556Z-001/microcircuit_example/Granule_py/mod_files/GRC_NA.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "Cerebellum Granule Cell Model";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
 extern double *_nrn_thread_getelm();
 
#define _MATELM1(_row,_col) *(_nrn_thread_getelm(_so, _row + 1, _col + 1))
 
#define _RHS1(_arg) _rhs[_arg+1]
  
#define _linmat1  1
 static int _spth1 = 1;
 static int _cvspth1 = 0;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[13], _dlist1[13]; static double *_temp1;
 static int kstates();
 
double alfa ( _threadargsprotocomma_ double _lv ) {
   double _lalfa;
 _lalfa = Q10 * Aalfa * exp ( _lv / Valfa ) ;
   
return _lalfa;
 }
 
static void _hoc_alfa(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alfa ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double beta ( _threadargsprotocomma_ double _lv ) {
   double _lbeta;
 _lbeta = Q10 * Abeta * exp ( - _lv / Vbeta ) ;
   
return _lbeta;
 }
 
static void _hoc_beta(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  beta ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double teta ( _threadargsprotocomma_ double _lv ) {
   double _lteta;
 _lteta = Q10 * Ateta * exp ( - _lv / Vteta ) ;
   
return _lteta;
 }
 
static void _hoc_teta(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  teta ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
static int kstates (void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt)
 {int _reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<13;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 /* ~ C1 <-> C2 ( n1 * alfa ( _threadargscomma_ v ) , n4 * beta ( _threadargscomma_ v ) )*/
 f_flux =  n1 * alfa ( _threadargscomma_ v ) * C1 ;
 b_flux =  n4 * beta ( _threadargscomma_ v ) * C2 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  n1 * alfa ( _threadargscomma_ v ) ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  n4 * beta ( _threadargscomma_ v ) ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ C2 <-> C3 ( n2 * alfa ( _threadargscomma_ v ) , n3 * beta ( _threadargscomma_ v ) )*/
 f_flux =  n2 * alfa ( _threadargscomma_ v ) * C2 ;
 b_flux =  n3 * beta ( _threadargscomma_ v ) * C3 ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  n2 * alfa ( _threadargscomma_ v ) ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  n3 * beta ( _threadargscomma_ v ) ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ C3 <-> C4 ( n3 * alfa ( _threadargscomma_ v ) , n2 * beta ( _threadargscomma_ v ) )*/
 f_flux =  n3 * alfa ( _threadargscomma_ v ) * C3 ;
 b_flux =  n2 * beta ( _threadargscomma_ v ) * C4 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  n3 * alfa ( _threadargscomma_ v ) ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  n2 * beta ( _threadargscomma_ v ) ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ C4 <-> C5 ( n4 * alfa ( _threadargscomma_ v ) , n1 * beta ( _threadargscomma_ v ) )*/
 f_flux =  n4 * alfa ( _threadargscomma_ v ) * C4 ;
 b_flux =  n1 * beta ( _threadargscomma_ v ) * C5 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  n4 * alfa ( _threadargscomma_ v ) ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  n1 * beta ( _threadargscomma_ v ) ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ C5 <-> O ( gamma , delta )*/
 f_flux =  gamma * C5 ;
 b_flux =  delta * O ;
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 12) += (f_flux - b_flux);
 
 _term =  gamma ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 12 ,1)  -= _term;
 _term =  delta ;
 _MATELM1( 1 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ O <-> OB ( epsilon , teta ( _threadargscomma_ v ) )*/
 f_flux =  epsilon * O ;
 b_flux =  teta ( _threadargscomma_ v ) * OB ;
 _RHS1( 12) -= (f_flux - b_flux);
 _RHS1( 11) += (f_flux - b_flux);
 
 _term =  epsilon ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  teta ( _threadargscomma_ v ) ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ I1 <-> I2 ( n1 * alfa ( _threadargscomma_ v ) * a , n4 * beta ( _threadargscomma_ v ) * b )*/
 f_flux =  n1 * alfa ( _threadargscomma_ v ) * a * I1 ;
 b_flux =  n4 * beta ( _threadargscomma_ v ) * b * I2 ;
 _RHS1( 10) -= (f_flux - b_flux);
 _RHS1( 9) += (f_flux - b_flux);
 
 _term =  n1 * alfa ( _threadargscomma_ v ) * a ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 9 ,10)  -= _term;
 _term =  n4 * beta ( _threadargscomma_ v ) * b ;
 _MATELM1( 10 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ I2 <-> I3 ( n2 * alfa ( _threadargscomma_ v ) * a , n3 * beta ( _threadargscomma_ v ) * b )*/
 f_flux =  n2 * alfa ( _threadargscomma_ v ) * a * I2 ;
 b_flux =  n3 * beta ( _threadargscomma_ v ) * b * I3 ;
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 8) += (f_flux - b_flux);
 
 _term =  n2 * alfa ( _threadargscomma_ v ) * a ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 8 ,9)  -= _term;
 _term =  n3 * beta ( _threadargscomma_ v ) * b ;
 _MATELM1( 9 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ I3 <-> I4 ( n3 * alfa ( _threadargscomma_ v ) * a , n2 * beta ( _threadargscomma_ v ) * b )*/
 f_flux =  n3 * alfa ( _threadargscomma_ v ) * a * I3 ;
 b_flux =  n2 * beta ( _threadargscomma_ v ) * b * I4 ;
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  n3 * alfa ( _threadargscomma_ v ) * a ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  n2 * beta ( _threadargscomma_ v ) * b ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ I4 <-> I5 ( n4 * alfa ( _threadargscomma_ v ) * a , n1 * beta ( _threadargscomma_ v ) * b )*/
 f_flux =  n4 * alfa ( _threadargscomma_ v ) * a * I4 ;
 b_flux =  n1 * beta ( _threadargscomma_ v ) * b * I5 ;
 _RHS1( 7) -= (f_flux - b_flux);
 _RHS1( 6) += (f_flux - b_flux);
 
 _term =  n4 * alfa ( _threadargscomma_ v ) * a ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 6 ,7)  -= _term;
 _term =  n1 * beta ( _threadargscomma_ v ) * b ;
 _MATELM1( 7 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ I5 <-> I6 ( gamma , delta )*/
 f_flux =  gamma * I5 ;
 b_flux =  delta * I6 ;
 _RHS1( 6) -= (f_flux - b_flux);
 
 _term =  gamma ;
 _MATELM1( 6 ,6)  += _term;
 _term =  delta ;
 _MATELM1( 6 ,0)  -= _term;
 /*REACTION*/
  /* ~ C1 <-> I1 ( Con , Coff )*/
 f_flux =  Con * C1 ;
 b_flux =  Coff * I1 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  Con ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 10 ,5)  -= _term;
 _term =  Coff ;
 _MATELM1( 5 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ C2 <-> I2 ( Con * a , Coff * b )*/
 f_flux =  Con * a * C2 ;
 b_flux =  Coff * b * I2 ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 9) += (f_flux - b_flux);
 
 _term =  Con * a ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 9 ,4)  -= _term;
 _term =  Coff * b ;
 _MATELM1( 4 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ C3 <-> I3 ( Con * pow( a , 2.0 ) , Coff * pow( b , 2.0 ) )*/
 f_flux =  Con * pow( a , 2.0 ) * C3 ;
 b_flux =  Coff * pow( b , 2.0 ) * I3 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 8) += (f_flux - b_flux);
 
 _term =  Con * pow( a , 2.0 ) ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 8 ,3)  -= _term;
 _term =  Coff * pow( b , 2.0 ) ;
 _MATELM1( 3 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ C4 <-> I4 ( Con * pow( a , 3.0 ) , Coff * pow( b , 3.0 ) )*/
 f_flux =  Con * pow( a , 3.0 ) * C4 ;
 b_flux =  Coff * pow( b , 3.0 ) * I4 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  Con * pow( a , 3.0 ) ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 7 ,2)  -= _term;
 _term =  Coff * pow( b , 3.0 ) ;
 _MATELM1( 2 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ C5 <-> I5 ( Con * pow( a , 4.0 ) , Coff * pow( b , 4.0 ) )*/
 f_flux =  Con * pow( a , 4.0 ) * C5 ;
 b_flux =  Coff * pow( b , 4.0 ) * I5 ;
 _RHS1( 1) -= (f_flux - b_flux);
 _RHS1( 6) += (f_flux - b_flux);
 
 _term =  Con * pow( a , 4.0 ) ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 6 ,1)  -= _term;
 _term =  Coff * pow( b , 4.0 ) ;
 _MATELM1( 1 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ O <-> I6 ( Oon , Ooff )*/
 f_flux =  Oon * O ;
 b_flux =  Ooff * I6 ;
 _RHS1( 12) -= (f_flux - b_flux);
 
 _term =  Oon ;
 _MATELM1( 12 ,12)  += _term;
 _term =  Ooff ;
 _MATELM1( 12 ,0)  -= _term;
 /*REACTION*/
   /* C1 + C2 + C3 + C4 + C5 + O + OB + I1 + I2 + I3 + I4 + I5 + I6 = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= I6 ;
 _MATELM1(0, 6) = 1;
 _RHS1(0) -= I5 ;
 _MATELM1(0, 7) = 1;
 _RHS1(0) -= I4 ;
 _MATELM1(0, 8) = 1;
 _RHS1(0) -= I3 ;
 _MATELM1(0, 9) = 1;
 _RHS1(0) -= I2 ;
 _MATELM1(0, 10) = 1;
 _RHS1(0) -= I1 ;
 _MATELM1(0, 11) = 1;
 _RHS1(0) -= OB ;
 _MATELM1(0, 12) = 1;
 _RHS1(0) -= O ;
 _MATELM1(0, 1) = 1;
 _RHS1(0) -= C5 ;
 _MATELM1(0, 2) = 1;
 _RHS1(0) -= C4 ;
 _MATELM1(0, 3) = 1;
 _RHS1(0) -= C3 ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= C2 ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= C1 ;
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE ode begin*/
 static int _ode_spec1(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<13;_i++) _p[_dlist1[_i]] = 0.0;}
 /* ~ C1 <-> C2 ( n1 * alfa ( _threadargscomma_ v ) , n4 * beta ( _threadargscomma_ v ) )*/
 f_flux =  n1 * alfa ( _threadargscomma_ v ) * C1 ;
 b_flux =  n4 * beta ( _threadargscomma_ v ) * C2 ;
 DC1 -= (f_flux - b_flux);
 DC2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> C3 ( n2 * alfa ( _threadargscomma_ v ) , n3 * beta ( _threadargscomma_ v ) )*/
 f_flux =  n2 * alfa ( _threadargscomma_ v ) * C2 ;
 b_flux =  n3 * beta ( _threadargscomma_ v ) * C3 ;
 DC2 -= (f_flux - b_flux);
 DC3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C3 <-> C4 ( n3 * alfa ( _threadargscomma_ v ) , n2 * beta ( _threadargscomma_ v ) )*/
 f_flux =  n3 * alfa ( _threadargscomma_ v ) * C3 ;
 b_flux =  n2 * beta ( _threadargscomma_ v ) * C4 ;
 DC3 -= (f_flux - b_flux);
 DC4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C4 <-> C5 ( n4 * alfa ( _threadargscomma_ v ) , n1 * beta ( _threadargscomma_ v ) )*/
 f_flux =  n4 * alfa ( _threadargscomma_ v ) * C4 ;
 b_flux =  n1 * beta ( _threadargscomma_ v ) * C5 ;
 DC4 -= (f_flux - b_flux);
 DC5 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C5 <-> O ( gamma , delta )*/
 f_flux =  gamma * C5 ;
 b_flux =  delta * O ;
 DC5 -= (f_flux - b_flux);
 DO += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ O <-> OB ( epsilon , teta ( _threadargscomma_ v ) )*/
 f_flux =  epsilon * O ;
 b_flux =  teta ( _threadargscomma_ v ) * OB ;
 DO -= (f_flux - b_flux);
 DOB += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ I1 <-> I2 ( n1 * alfa ( _threadargscomma_ v ) * a , n4 * beta ( _threadargscomma_ v ) * b )*/
 f_flux =  n1 * alfa ( _threadargscomma_ v ) * a * I1 ;
 b_flux =  n4 * beta ( _threadargscomma_ v ) * b * I2 ;
 DI1 -= (f_flux - b_flux);
 DI2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ I2 <-> I3 ( n2 * alfa ( _threadargscomma_ v ) * a , n3 * beta ( _threadargscomma_ v ) * b )*/
 f_flux =  n2 * alfa ( _threadargscomma_ v ) * a * I2 ;
 b_flux =  n3 * beta ( _threadargscomma_ v ) * b * I3 ;
 DI2 -= (f_flux - b_flux);
 DI3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ I3 <-> I4 ( n3 * alfa ( _threadargscomma_ v ) * a , n2 * beta ( _threadargscomma_ v ) * b )*/
 f_flux =  n3 * alfa ( _threadargscomma_ v ) * a * I3 ;
 b_flux =  n2 * beta ( _threadargscomma_ v ) * b * I4 ;
 DI3 -= (f_flux - b_flux);
 DI4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ I4 <-> I5 ( n4 * alfa ( _threadargscomma_ v ) * a , n1 * beta ( _threadargscomma_ v ) * b )*/
 f_flux =  n4 * alfa ( _threadargscomma_ v ) * a * I4 ;
 b_flux =  n1 * beta ( _threadargscomma_ v ) * b * I5 ;
 DI4 -= (f_flux - b_flux);
 DI5 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ I5 <-> I6 ( gamma , delta )*/
 f_flux =  gamma * I5 ;
 b_flux =  delta * I6 ;
 DI5 -= (f_flux - b_flux);
 DI6 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C1 <-> I1 ( Con , Coff )*/
 f_flux =  Con * C1 ;
 b_flux =  Coff * I1 ;
 DC1 -= (f_flux - b_flux);
 DI1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> I2 ( Con * a , Coff * b )*/
 f_flux =  Con * a * C2 ;
 b_flux =  Coff * b * I2 ;
 DC2 -= (f_flux - b_flux);
 DI2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C3 <-> I3 ( Con * pow( a , 2.0 ) , Coff * pow( b , 2.0 ) )*/
 f_flux =  Con * pow( a , 2.0 ) * C3 ;
 b_flux =  Coff * pow( b , 2.0 ) * I3 ;
 DC3 -= (f_flux - b_flux);
 DI3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C4 <-> I4 ( Con * pow( a , 3.0 ) , Coff * pow( b , 3.0 ) )*/
 f_flux =  Con * pow( a , 3.0 ) * C4 ;
 b_flux =  Coff * pow( b , 3.0 ) * I4 ;
 DC4 -= (f_flux - b_flux);
 DI4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C5 <-> I5 ( Con * pow( a , 4.0 ) , Coff * pow( b , 4.0 ) )*/
 f_flux =  Con * pow( a , 4.0 ) * C5 ;
 b_flux =  Coff * pow( b , 4.0 ) * I5 ;
 DC5 -= (f_flux - b_flux);
 DI5 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ O <-> I6 ( Oon , Ooff )*/
 f_flux =  Oon * O ;
 b_flux =  Ooff * I6 ;
 DO -= (f_flux - b_flux);
 DI6 += (f_flux - b_flux);
 
 /*REACTION*/
   /* C1 + C2 + C3 + C4 + C5 + O + OB + I1 + I2 + I3 + I4 + I5 + I6 = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1(void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<13;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 /* ~ C1 <-> C2 ( n1 * alfa ( _threadargscomma_ v ) , n4 * beta ( _threadargscomma_ v ) )*/
 _term =  n1 * alfa ( _threadargscomma_ v ) ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  n4 * beta ( _threadargscomma_ v ) ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ C2 <-> C3 ( n2 * alfa ( _threadargscomma_ v ) , n3 * beta ( _threadargscomma_ v ) )*/
 _term =  n2 * alfa ( _threadargscomma_ v ) ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  n3 * beta ( _threadargscomma_ v ) ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ C3 <-> C4 ( n3 * alfa ( _threadargscomma_ v ) , n2 * beta ( _threadargscomma_ v ) )*/
 _term =  n3 * alfa ( _threadargscomma_ v ) ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  n2 * beta ( _threadargscomma_ v ) ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ C4 <-> C5 ( n4 * alfa ( _threadargscomma_ v ) , n1 * beta ( _threadargscomma_ v ) )*/
 _term =  n4 * alfa ( _threadargscomma_ v ) ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  n1 * beta ( _threadargscomma_ v ) ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ C5 <-> O ( gamma , delta )*/
 _term =  gamma ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 12 ,1)  -= _term;
 _term =  delta ;
 _MATELM1( 1 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ O <-> OB ( epsilon , teta ( _threadargscomma_ v ) )*/
 _term =  epsilon ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  teta ( _threadargscomma_ v ) ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ I1 <-> I2 ( n1 * alfa ( _threadargscomma_ v ) * a , n4 * beta ( _threadargscomma_ v ) * b )*/
 _term =  n1 * alfa ( _threadargscomma_ v ) * a ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 9 ,10)  -= _term;
 _term =  n4 * beta ( _threadargscomma_ v ) * b ;
 _MATELM1( 10 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ I2 <-> I3 ( n2 * alfa ( _threadargscomma_ v ) * a , n3 * beta ( _threadargscomma_ v ) * b )*/
 _term =  n2 * alfa ( _threadargscomma_ v ) * a ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 8 ,9)  -= _term;
 _term =  n3 * beta ( _threadargscomma_ v ) * b ;
 _MATELM1( 9 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ I3 <-> I4 ( n3 * alfa ( _threadargscomma_ v ) * a , n2 * beta ( _threadargscomma_ v ) * b )*/
 _term =  n3 * alfa ( _threadargscomma_ v ) * a ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  n2 * beta ( _threadargscomma_ v ) * b ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ I4 <-> I5 ( n4 * alfa ( _threadargscomma_ v ) * a , n1 * beta ( _threadargscomma_ v ) * b )*/
 _term =  n4 * alfa ( _threadargscomma_ v ) * a ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 6 ,7)  -= _term;
 _term =  n1 * beta ( _threadargscomma_ v ) * b ;
 _MATELM1( 7 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ I5 <-> I6 ( gamma , delta )*/
 _term =  gamma ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 0 ,6)  -= _term;
 _term =  delta ;
 _MATELM1( 6 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ C1 <-> I1 ( Con , Coff )*/
 _term =  Con ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 10 ,5)  -= _term;
 _term =  Coff ;
 _MATELM1( 5 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ C2 <-> I2 ( Con * a , Coff * b )*/
 _term =  Con * a ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 9 ,4)  -= _term;
 _term =  Coff * b ;
 _MATELM1( 4 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ C3 <-> I3 ( Con * pow( a , 2.0 ) , Coff * pow( b , 2.0 ) )*/
 _term =  Con * pow( a , 2.0 ) ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 8 ,3)  -= _term;
 _term =  Coff * pow( b , 2.0 ) ;
 _MATELM1( 3 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ C4 <-> I4 ( Con * pow( a , 3.0 ) , Coff * pow( b , 3.0 ) )*/
 _term =  Con * pow( a , 3.0 ) ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 7 ,2)  -= _term;
 _term =  Coff * pow( b , 3.0 ) ;
 _MATELM1( 2 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ C5 <-> I5 ( Con * pow( a , 4.0 ) , Coff * pow( b , 4.0 ) )*/
 _term =  Con * pow( a , 4.0 ) ;
 _MATELM1( 1 ,1)  += _term;
 _MATELM1( 6 ,1)  -= _term;
 _term =  Coff * pow( b , 4.0 ) ;
 _MATELM1( 1 ,6)  -= _term;
 _MATELM1( 6 ,6)  += _term;
 /*REACTION*/
  /* ~ O <-> I6 ( Oon , Ooff )*/
 _term =  Oon ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 0 ,12)  -= _term;
 _term =  Ooff ;
 _MATELM1( 12 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
   /* C1 + C2 + C3 + C4 + C5 + O + OB + I1 + I2 + I3 + I4 + I5 + I6 = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 13;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 13; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse_thread(&_thread[_cvspth1]._pvoid, 13, _dlist1, _p, _ode_matsol1, _ppvar, _thread, _nt);
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
  ena = _ion_ena;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_cleanup(Datum* _thread) {
   _nrn_destroy_sparseobj_thread(_thread[_cvspth1]._pvoid);
   _nrn_destroy_sparseobj_thread(_thread[_spth1]._pvoid);
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  C5 = C50;
  C4 = C40;
  C3 = C30;
  C2 = C20;
  C1 = C10;
  I6 = I60;
  I5 = I50;
  I4 = I40;
  I3 = I30;
  I2 = I20;
  I1 = I10;
  OB = OB0;
  O = O0;
 {
   C1 = 1.0 ;
   C2 = 0.0 ;
   C3 = 0.0 ;
   C4 = 0.0 ;
   C5 = 0.0 ;
   O = 0.0 ;
   OB = 0.0 ;
   I1 = 0.0 ;
   I2 = 0.0 ;
   I3 = 0.0 ;
   I4 = 0.0 ;
   I5 = 0.0 ;
   I6 = 0.0 ;
   Q10 = pow( 3.0 , ( ( celsius - 20.0 ) / 10.0 ) ) ;
   gamma = Q10 * Agamma ;
   delta = Q10 * Adelta ;
   epsilon = Q10 * Aepsilon ;
   Con = Q10 * ACon ;
   Coff = Q10 * ACoff ;
   Oon = Q10 * AOon ;
   Ooff = Q10 * AOoff ;
   a = pow( ( Oon / Con ) , 0.25 ) ;
   b = pow( ( Ooff / Coff ) , 0.25 ) ;
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
  ena = _ion_ena;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   g = gnabar * O ;
   ina = g * ( v - ena ) ;
   }
 _current += ina;

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
  ena = _ion_ena;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
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
  ena = _ion_ena;
 {  sparse_thread(&_thread[_spth1]._pvoid, 13, _slist1, _dlist1, _p, &t, dt, kstates, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 13; ++_i) {
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
 _slist1[0] = &(I6) - _p;  _dlist1[0] = &(DI6) - _p;
 _slist1[1] = &(C5) - _p;  _dlist1[1] = &(DC5) - _p;
 _slist1[2] = &(C4) - _p;  _dlist1[2] = &(DC4) - _p;
 _slist1[3] = &(C3) - _p;  _dlist1[3] = &(DC3) - _p;
 _slist1[4] = &(C2) - _p;  _dlist1[4] = &(DC2) - _p;
 _slist1[5] = &(C1) - _p;  _dlist1[5] = &(DC1) - _p;
 _slist1[6] = &(I5) - _p;  _dlist1[6] = &(DI5) - _p;
 _slist1[7] = &(I4) - _p;  _dlist1[7] = &(DI4) - _p;
 _slist1[8] = &(I3) - _p;  _dlist1[8] = &(DI3) - _p;
 _slist1[9] = &(I2) - _p;  _dlist1[9] = &(DI2) - _p;
 _slist1[10] = &(I1) - _p;  _dlist1[10] = &(DI1) - _p;
 _slist1[11] = &(OB) - _p;  _dlist1[11] = &(DOB) - _p;
 _slist1[12] = &(O) - _p;  _dlist1[12] = &(DO) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
