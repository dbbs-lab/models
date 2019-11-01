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
 
#define nrn_init _nrn_init__cdp5_CR
#define _nrn_initial _nrn_initial__cdp5_CR
#define nrn_cur _nrn_cur__cdp5_CR
#define _nrn_current _nrn_current__cdp5_CR
#define nrn_jacob _nrn_jacob__cdp5_CR
#define nrn_state _nrn_state__cdp5_CR
#define _net_receive _net_receive__cdp5_CR 
#define factors factors__cdp5_CR 
#define state state__cdp5_CR 
 
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
#define Nannuli _p[0]
#define cainull _p[1]
#define Buffnull2 _p[2]
#define rf3 _p[3]
#define rf4 _p[4]
#define CRnull _p[5]
#define TotalPump _p[6]
#define ica_pmp _p[7]
#define vrat _p[8]
#define ca _p[9]
#define mg _p[10]
#define Buff1 _p[11]
#define Buff1_ca _p[12]
#define Buff2 _p[13]
#define Buff2_ca _p[14]
#define BTC _p[15]
#define BTC_ca _p[16]
#define DMNPE _p[17]
#define DMNPE_ca _p[18]
#define CR _p[19]
#define CR_1C_0N _p[20]
#define CR_2C_0N _p[21]
#define CR_2C_1N _p[22]
#define CR_1C_1N _p[23]
#define CR_0C_1N _p[24]
#define CR_0C_2N _p[25]
#define CR_1C_2N _p[26]
#define CR_2C_2N _p[27]
#define CR_1V _p[28]
#define pump _p[29]
#define pumpca _p[30]
#define ica _p[31]
#define parea _p[32]
#define parea2 _p[33]
#define cai _p[34]
#define mgi _p[35]
#define Dca _p[36]
#define Dmg _p[37]
#define DBuff1 _p[38]
#define DBuff1_ca _p[39]
#define DBuff2 _p[40]
#define DBuff2_ca _p[41]
#define DBTC _p[42]
#define DBTC_ca _p[43]
#define DDMNPE _p[44]
#define DDMNPE_ca _p[45]
#define DCR _p[46]
#define DCR_1C_0N _p[47]
#define DCR_2C_0N _p[48]
#define DCR_2C_1N _p[49]
#define DCR_1C_1N _p[50]
#define DCR_0C_1N _p[51]
#define DCR_0C_2N _p[52]
#define DCR_1C_2N _p[53]
#define DCR_2C_2N _p[54]
#define DCR_1V _p[55]
#define Dpump _p[56]
#define Dpumpca _p[57]
#define v _p[58]
#define _g _p[59]
#define _ion_cao	*_ppvar[0]._pval
#define _ion_cai	*_ppvar[1]._pval
#define _ion_ica	*_ppvar[2]._pval
#define _style_ca	*((int*)_ppvar[3]._pvoid)
#define diam	*_ppvar[4]._pval
 
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
 static void _hoc_factors(void);
 static void _hoc_ssDMNPEca(void);
 static void _hoc_ssDMNPE(void);
 static void _hoc_ssBTCca(void);
 static void _hoc_ssBTC(void);
 static void _hoc_ssBuff2ca(void);
 static void _hoc_ssBuff2(void);
 static void _hoc_ssBuff1ca(void);
 static void _hoc_ssBuff1(void);
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
 "setdata_cdp5_CR", _hoc_setdata,
 "factors_cdp5_CR", _hoc_factors,
 "ssDMNPEca_cdp5_CR", _hoc_ssDMNPEca,
 "ssDMNPE_cdp5_CR", _hoc_ssDMNPE,
 "ssBTCca_cdp5_CR", _hoc_ssBTCca,
 "ssBTC_cdp5_CR", _hoc_ssBTC,
 "ssBuff2ca_cdp5_CR", _hoc_ssBuff2ca,
 "ssBuff2_cdp5_CR", _hoc_ssBuff2,
 "ssBuff1ca_cdp5_CR", _hoc_ssBuff1ca,
 "ssBuff1_cdp5_CR", _hoc_ssBuff1,
 0, 0
};
#define ssDMNPEca ssDMNPEca_cdp5_CR
#define ssDMNPE ssDMNPE_cdp5_CR
#define ssBTCca ssBTCca_cdp5_CR
#define ssBTC ssBTC_cdp5_CR
#define ssBuff2ca ssBuff2ca_cdp5_CR
#define ssBuff2 ssBuff2_cdp5_CR
#define ssBuff1ca ssBuff1ca_cdp5_CR
#define ssBuff1 ssBuff1_cdp5_CR
 extern double ssDMNPEca( _threadargsproto_ );
 extern double ssDMNPE( _threadargsproto_ );
 extern double ssBTCca( _threadargsproto_ );
 extern double ssBTC( _threadargsproto_ );
 extern double ssBuff2ca( _threadargsproto_ );
 extern double ssBuff2( _threadargsproto_ );
 extern double ssBuff1ca( _threadargsproto_ );
 extern double ssBuff1( _threadargsproto_ );
 #define _zfactors_done _thread[2]._pval[0]
 #define _zdsq _thread[2]._pval[1]
 #define _zdsqvol _thread[2]._pval[2]
 /* declare global and static user variables */
#define BTCnull BTCnull_cdp5_CR
 double BTCnull = 0;
#define Buffnull1 Buffnull1_cdp5_CR
 double Buffnull1 = 0;
#define DMNPEnull DMNPEnull_cdp5_CR
 double DMNPEnull = 0;
#define b2 b2_cdp5_CR
 double b2 = 0.08;
#define b1 b1_cdp5_CR
 double b1 = 5.33;
#define c2 c2_cdp5_CR
 double c2 = 0.000107;
#define c1 c1_cdp5_CR
 double c1 = 5.63;
#define kpmp3 kpmp3_cdp5_CR
 double kpmp3 = 7.255e-005;
#define kpmp2 kpmp2_cdp5_CR
 double kpmp2 = 1.75e-005;
#define kpmp1 kpmp1_cdp5_CR
 double kpmp1 = 0.003;
#define mginull mginull_cdp5_CR
 double mginull = 0.59;
#define nV2 nV2_cdp5_CR
 double nV2 = 0.24;
#define nV1 nV1_cdp5_CR
 double nV1 = 7.3;
#define nR2 nR2_cdp5_CR
 double nR2 = 0.02;
#define nR1 nR1_cdp5_CR
 double nR1 = 310;
#define nT2 nT2_cdp5_CR
 double nT2 = 0.053;
#define nT1 nT1_cdp5_CR
 double nT1 = 1.8;
#define rf2 rf2_cdp5_CR
 double rf2 = 0.0397469;
#define rf1 rf1_cdp5_CR
 double rf1 = 0.0134329;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "mginull_cdp5_CR", "mM",
 "Buffnull1_cdp5_CR", "mM",
 "rf1_cdp5_CR", "/ms",
 "rf2_cdp5_CR", "/ms",
 "BTCnull_cdp5_CR", "mM",
 "b1_cdp5_CR", "/ms",
 "b2_cdp5_CR", "/ms",
 "DMNPEnull_cdp5_CR", "mM",
 "c1_cdp5_CR", "/ms",
 "c2_cdp5_CR", "/ms",
 "nT1_cdp5_CR", "/ms",
 "nT2_cdp5_CR", "/ms",
 "nR1_cdp5_CR", "/ms",
 "nR2_cdp5_CR", "/ms",
 "nV1_cdp5_CR", "/ms",
 "nV2_cdp5_CR", "/ms",
 "kpmp1_cdp5_CR", "/mM-ms",
 "kpmp2_cdp5_CR", "/ms",
 "kpmp3_cdp5_CR", "/ms",
 "Nannuli_cdp5_CR", "1",
 "cainull_cdp5_CR", "mM",
 "Buffnull2_cdp5_CR", "mM",
 "rf3_cdp5_CR", "/ms",
 "rf4_cdp5_CR", "/ms",
 "CRnull_cdp5_CR", "mM",
 "TotalPump_cdp5_CR", "mol/cm2",
 "ca_cdp5_CR", "mM",
 "mg_cdp5_CR", "mM",
 "Buff1_cdp5_CR", "mM",
 "Buff1_ca_cdp5_CR", "mM",
 "Buff2_cdp5_CR", "mM",
 "Buff2_ca_cdp5_CR", "mM",
 "BTC_cdp5_CR", "mM",
 "BTC_ca_cdp5_CR", "mM",
 "DMNPE_cdp5_CR", "mM",
 "DMNPE_ca_cdp5_CR", "mM",
 "CR_cdp5_CR", "mM",
 "CR_1C_0N_cdp5_CR", "mM",
 "CR_2C_0N_cdp5_CR", "mM",
 "CR_2C_1N_cdp5_CR", "mM",
 "CR_1C_1N_cdp5_CR", "mM",
 "CR_0C_1N_cdp5_CR", "mM",
 "CR_0C_2N_cdp5_CR", "mM",
 "CR_1C_2N_cdp5_CR", "mM",
 "CR_2C_2N_cdp5_CR", "mM",
 "CR_1V_cdp5_CR", "mM",
 "pump_cdp5_CR", "mol/cm2",
 "pumpca_cdp5_CR", "mol/cm2",
 "ica_pmp_cdp5_CR", "mA/cm2",
 "vrat_cdp5_CR", "1",
 0,0
};
 static double BTC_ca0 = 0;
 static double BTC0 = 0;
 static double Buff2_ca0 = 0;
 static double Buff20 = 0;
 static double Buff1_ca0 = 0;
 static double Buff10 = 0;
 static double CR_1V0 = 0;
 static double CR_2C_2N0 = 0;
 static double CR_1C_2N0 = 0;
 static double CR_0C_2N0 = 0;
 static double CR_0C_1N0 = 0;
 static double CR_1C_1N0 = 0;
 static double CR_2C_1N0 = 0;
 static double CR_2C_0N0 = 0;
 static double CR_1C_0N0 = 0;
 static double CR0 = 0;
 static double DMNPE_ca0 = 0;
 static double DMNPE0 = 0;
 static double ca0 = 0;
 static double delta_t = 0.01;
 static double mg0 = 0;
 static double pumpca0 = 0;
 static double pump0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "mginull_cdp5_CR", &mginull_cdp5_CR,
 "Buffnull1_cdp5_CR", &Buffnull1_cdp5_CR,
 "rf1_cdp5_CR", &rf1_cdp5_CR,
 "rf2_cdp5_CR", &rf2_cdp5_CR,
 "BTCnull_cdp5_CR", &BTCnull_cdp5_CR,
 "b1_cdp5_CR", &b1_cdp5_CR,
 "b2_cdp5_CR", &b2_cdp5_CR,
 "DMNPEnull_cdp5_CR", &DMNPEnull_cdp5_CR,
 "c1_cdp5_CR", &c1_cdp5_CR,
 "c2_cdp5_CR", &c2_cdp5_CR,
 "nT1_cdp5_CR", &nT1_cdp5_CR,
 "nT2_cdp5_CR", &nT2_cdp5_CR,
 "nR1_cdp5_CR", &nR1_cdp5_CR,
 "nR2_cdp5_CR", &nR2_cdp5_CR,
 "nV1_cdp5_CR", &nV1_cdp5_CR,
 "nV2_cdp5_CR", &nV2_cdp5_CR,
 "kpmp1_cdp5_CR", &kpmp1_cdp5_CR,
 "kpmp2_cdp5_CR", &kpmp2_cdp5_CR,
 "kpmp3_cdp5_CR", &kpmp3_cdp5_CR,
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
 
#define _cvode_ieq _ppvar[5]._i
 static void _ode_synonym(int, double**, Datum**);
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.5.0",
"cdp5_CR",
 "Nannuli_cdp5_CR",
 "cainull_cdp5_CR",
 "Buffnull2_cdp5_CR",
 "rf3_cdp5_CR",
 "rf4_cdp5_CR",
 "CRnull_cdp5_CR",
 "TotalPump_cdp5_CR",
 0,
 "ica_pmp_cdp5_CR",
 "vrat_cdp5_CR",
 0,
 "ca_cdp5_CR",
 "mg_cdp5_CR",
 "Buff1_cdp5_CR",
 "Buff1_ca_cdp5_CR",
 "Buff2_cdp5_CR",
 "Buff2_ca_cdp5_CR",
 "BTC_cdp5_CR",
 "BTC_ca_cdp5_CR",
 "DMNPE_cdp5_CR",
 "DMNPE_ca_cdp5_CR",
 "CR_cdp5_CR",
 "CR_1C_0N_cdp5_CR",
 "CR_2C_0N_cdp5_CR",
 "CR_2C_1N_cdp5_CR",
 "CR_1C_1N_cdp5_CR",
 "CR_0C_1N_cdp5_CR",
 "CR_0C_2N_cdp5_CR",
 "CR_1C_2N_cdp5_CR",
 "CR_2C_2N_cdp5_CR",
 "CR_1V_cdp5_CR",
 "pump_cdp5_CR",
 "pumpca_cdp5_CR",
 0,
 0};
 static Symbol* _morphology_sym;
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 60, _prop);
 	/*initialize range parameters*/
 	Nannuli = 10.9495;
 	cainull = 4.5e-005;
 	Buffnull2 = 60.9091;
 	rf3 = 0.1435;
 	rf4 = 0.0014;
 	CRnull = 0.9;
 	TotalPump = 1e-009;
 	_prop->param = _p;
 	_prop->param_size = 60;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_morphology_sym);
 	_ppvar[4]._pval = &prop_ion->param[0]; /* diam */
 prop_ion = need_memb(_ca_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[0]._pval = &prop_ion->param[2]; /* cao */
 	_ppvar[1]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[3]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for ca */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 "ca_cdp5_CR", 0.001,
 "mg_cdp5_CR", 1e-006,
 "pump_cdp5_CR", 1e-015,
 "pumpca_cdp5_CR", 1e-015,
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

 void _cdp5_CR_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("ca", -10000.);
 	_morphology_sym = hoc_lookup("morphology");
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 4);
  _extcall_thread = (Datum*)ecalloc(3, sizeof(Datum));
  _thread_mem_init(_extcall_thread);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 1, _thread_mem_init);
     _nrn_thread_reg(_mechtype, 0, _thread_cleanup);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
  hoc_register_prop_size(_mechtype, 60, 6);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "#ca_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "cvodeieq");
  hoc_register_dparam_semantics(_mechtype, 4, "diam");
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_synonym(_mechtype, _ode_synonym);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 cdp5_CR C:/Users/Elisa/Desktop/microcircuit-20191001T081556Z-001/microcircuit_example/Granule_py/mod_files/cdp5_CR.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double FARADAY = 9.64853;
 static double PI = 3.14159;
 static double cao = 2;
 /*Top LOCAL _zfactors_done */
 /*Top LOCAL _zdsq , _zdsqvol */
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int factors(_threadargsproto_);
 extern double *_nrn_thread_getelm();
 
#define _MATELM1(_row,_col) *(_nrn_thread_getelm(_so, _row + 1, _col + 1))
 
#define _RHS1(_arg) _rhs[_arg+1]
  
#define _linmat1  0
 static int _spth1 = 1;
 static int _cvspth1 = 0;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[21], _dlist1[21]; static double *_temp1;
 static int state();
 
static int  factors ( _threadargsproto_ ) {
   double _lr , _ldr2 ;
 _lr = 1.0 / 2.0 ;
   _ldr2 = _lr / ( Nannuli - 1.0 ) / 2.0 ;
   vrat = PI * ( _lr - _ldr2 / 2.0 ) * 2.0 * _ldr2 ;
   _lr = _lr - _ldr2 ;
    return 0; }
 
static void _hoc_factors(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 factors ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
static int state (void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt)
 {int _reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<21;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
}  
_RHS1(1) *= ( diam * diam * vrat) ;
_MATELM1(1, 1) *= ( diam * diam * vrat); 
_RHS1(2) *= ( diam * diam * vrat) ;
_MATELM1(2, 2) *= ( diam * diam * vrat); 
_RHS1(3) *= ( diam * diam * vrat) ;
_MATELM1(3, 3) *= ( diam * diam * vrat); 
_RHS1(4) *= ( diam * diam * vrat) ;
_MATELM1(4, 4) *= ( diam * diam * vrat); 
_RHS1(5) *= ( diam * diam * vrat) ;
_MATELM1(5, 5) *= ( diam * diam * vrat); 
_RHS1(6) *= ( diam * diam * vrat) ;
_MATELM1(6, 6) *= ( diam * diam * vrat); 
_RHS1(7) *= ( diam * diam * vrat) ;
_MATELM1(7, 7) *= ( diam * diam * vrat); 
_RHS1(8) *= ( diam * diam * vrat) ;
_MATELM1(8, 8) *= ( diam * diam * vrat); 
_RHS1(9) *= ( diam * diam * vrat) ;
_MATELM1(9, 9) *= ( diam * diam * vrat); 
_RHS1(10) *= ( diam * diam * vrat) ;
_MATELM1(10, 10) *= ( diam * diam * vrat); 
_RHS1(11) *= ( diam * diam * vrat) ;
_MATELM1(11, 11) *= ( diam * diam * vrat); 
_RHS1(12) *= ( diam * diam * vrat) ;
_MATELM1(12, 12) *= ( diam * diam * vrat); 
_RHS1(14) *= ( diam * diam * vrat) ;
_MATELM1(14, 14) *= ( diam * diam * vrat); 
_RHS1(15) *= ( diam * diam * vrat) ;
_MATELM1(15, 15) *= ( diam * diam * vrat); 
_RHS1(16) *= ( diam * diam * vrat) ;
_MATELM1(16, 16) *= ( diam * diam * vrat); 
_RHS1(17) *= ( diam * diam * vrat) ;
_MATELM1(17, 17) *= ( diam * diam * vrat); 
_RHS1(18) *= ( diam * diam * vrat) ;
_MATELM1(18, 18) *= ( diam * diam * vrat); 
_RHS1(19) *= ( diam * diam * vrat) ;
_MATELM1(19, 19) *= ( diam * diam * vrat); 
_RHS1(20) *= ( ( 1e10 ) * parea) ;
_MATELM1(20, 20) *= ( ( 1e10 ) * parea);  }
 /* COMPARTMENT diam * diam * vrat {
     ca mg Buff1 Buff1_ca Buff2 Buff2_ca BTC BTC_ca DMNPE DMNPE_ca CR CR_1C_0N CR_2C_0N CR_2C_1N CR_0C_1N CR_0C_2N CR_1C_2N CR_1C_1N CR_2C_1N CR_1C_2N CR_2C_2N }
   */
 /* COMPARTMENT ( 1e10 ) * parea {
     pump pumpca }
   */
 /* ~ ca + pump <-> pumpca ( kpmp1 * parea * ( 1e10 ) , kpmp2 * parea * ( 1e10 ) )*/
 f_flux =  kpmp1 * parea * ( 1e10 ) * pump * ca ;
 b_flux =  kpmp2 * parea * ( 1e10 ) * pumpca ;
 _RHS1( 20) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 
 _term =  kpmp1 * parea * ( 1e10 ) * ca ;
 _MATELM1( 20 ,20)  += _term;
 _MATELM1( 19 ,20)  += _term;
 _term =  kpmp1 * parea * ( 1e10 ) * pump ;
 _MATELM1( 20 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _term =  kpmp2 * parea * ( 1e10 ) ;
 _MATELM1( 20 ,0)  -= _term;
 _MATELM1( 19 ,0)  -= _term;
 /*REACTION*/
  /* ~ pumpca <-> pump ( kpmp3 * parea * ( 1e10 ) , 0.0 )*/
 f_flux =  kpmp3 * parea * ( 1e10 ) * pumpca ;
 b_flux =  0.0 * pump ;
 _RHS1( 20) += (f_flux - b_flux);
 
 _term =  kpmp3 * parea * ( 1e10 ) ;
 _MATELM1( 20 ,0)  -= _term;
 _term =  0.0 ;
 _MATELM1( 20 ,20)  += _term;
 /*REACTION*/
   /* pump + pumpca = TotalPump * parea * ( 1e10 ) */
 _RHS1(0) =  TotalPump * parea * ( 1e10 );
 _MATELM1(0, 0) = 1 * ( ( 1e10 ) * parea);
 _RHS1(0) -= pumpca * ( ( 1e10 ) * parea) ;
 _MATELM1(0, 20) = 1 * ( ( 1e10 ) * parea);
 _RHS1(0) -= pump * ( ( 1e10 ) * parea) ;
 /*CONSERVATION*/
 ica_pmp = 2.0 * FARADAY * ( f_flux - b_flux ) / parea ;
   /* ~ ca < < ( - ica * PI * diam / ( 2.0 * FARADAY ) )*/
 f_flux = b_flux = 0.;
 _RHS1( 19) += (b_flux =   ( - ica * PI * diam / ( 2.0 * FARADAY ) ) );
 /*FLUX*/
  _zdsq = diam * diam ;
   _zdsqvol = _zdsq * vrat ;
   /* ~ ca + Buff1 <-> Buff1_ca ( rf1 * _zdsqvol , rf2 * _zdsqvol )*/
 f_flux =  rf1 * _zdsqvol * Buff1 * ca ;
 b_flux =  rf2 * _zdsqvol * Buff1_ca ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  rf1 * _zdsqvol * ca ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 19 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  rf1 * _zdsqvol * Buff1 ;
 _MATELM1( 6 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 5 ,19)  -= _term;
 _term =  rf2 * _zdsqvol ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 19 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ ca + Buff2 <-> Buff2_ca ( rf3 * _zdsqvol , rf4 * _zdsqvol )*/
 f_flux =  rf3 * _zdsqvol * Buff2 * ca ;
 b_flux =  rf4 * _zdsqvol * Buff2_ca ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  rf3 * _zdsqvol * ca ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 19 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  rf3 * _zdsqvol * Buff2 ;
 _MATELM1( 4 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 3 ,19)  -= _term;
 _term =  rf4 * _zdsqvol ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 19 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ ca + BTC <-> BTC_ca ( b1 * _zdsqvol , b2 * _zdsqvol )*/
 f_flux =  b1 * _zdsqvol * BTC * ca ;
 b_flux =  b2 * _zdsqvol * BTC_ca ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  b1 * _zdsqvol * ca ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 19 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  b1 * _zdsqvol * BTC ;
 _MATELM1( 2 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 1 ,19)  -= _term;
 _term =  b2 * _zdsqvol ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 19 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ ca + DMNPE <-> DMNPE_ca ( c1 * _zdsqvol , c2 * _zdsqvol )*/
 f_flux =  c1 * _zdsqvol * DMNPE * ca ;
 b_flux =  c2 * _zdsqvol * DMNPE_ca ;
 _RHS1( 18) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 17) += (f_flux - b_flux);
 
 _term =  c1 * _zdsqvol * ca ;
 _MATELM1( 18 ,18)  += _term;
 _MATELM1( 19 ,18)  += _term;
 _MATELM1( 17 ,18)  -= _term;
 _term =  c1 * _zdsqvol * DMNPE ;
 _MATELM1( 18 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 17 ,19)  -= _term;
 _term =  c2 * _zdsqvol ;
 _MATELM1( 18 ,17)  -= _term;
 _MATELM1( 19 ,17)  -= _term;
 _MATELM1( 17 ,17)  += _term;
 /*REACTION*/
  /* ~ ca + CR <-> CR_1C_0N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_0N ;
 _RHS1( 16) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 15) += (f_flux - b_flux);
 
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 16 ,16)  += _term;
 _MATELM1( 19 ,16)  += _term;
 _MATELM1( 15 ,16)  -= _term;
 _term =  nT1 * _zdsqvol * CR ;
 _MATELM1( 16 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 15 ,19)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 16 ,15)  -= _term;
 _MATELM1( 19 ,15)  -= _term;
 _MATELM1( 15 ,15)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_0N <-> CR_2C_0N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_0N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_0N ;
 _RHS1( 15) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 12) += (f_flux - b_flux);
 
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 15 ,15)  += _term;
 _MATELM1( 19 ,15)  += _term;
 _MATELM1( 12 ,15)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_0N ;
 _MATELM1( 15 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 12 ,19)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 15 ,12)  -= _term;
 _MATELM1( 19 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ ca + CR_2C_0N <-> CR_2C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_2C_0N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_2C_1N ;
 _RHS1( 12) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 11) += (f_flux - b_flux);
 
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 19 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  nT1 * _zdsqvol * CR_2C_0N ;
 _MATELM1( 12 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 11 ,19)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 19 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ ca + CR <-> CR_0C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR * ca ;
 b_flux =  nT2 * _zdsqvol * CR_0C_1N ;
 _RHS1( 16) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 9) += (f_flux - b_flux);
 
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 16 ,16)  += _term;
 _MATELM1( 19 ,16)  += _term;
 _MATELM1( 9 ,16)  -= _term;
 _term =  nT1 * _zdsqvol * CR ;
 _MATELM1( 16 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 9 ,19)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 16 ,9)  -= _term;
 _MATELM1( 19 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ ca + CR_0C_1N <-> CR_0C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_0C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_0C_2N ;
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 8) += (f_flux - b_flux);
 
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 19 ,9)  += _term;
 _MATELM1( 8 ,9)  -= _term;
 _term =  nR1 * _zdsqvol * CR_0C_1N ;
 _MATELM1( 9 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 8 ,19)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 9 ,8)  -= _term;
 _MATELM1( 19 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ ca + CR_0C_2N <-> CR_1C_2N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_0C_2N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_2N ;
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 19 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  nT1 * _zdsqvol * CR_0C_2N ;
 _MATELM1( 8 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 7 ,19)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 19 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ ca + CR_2C_1N <-> CR_2C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_2C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_2N ;
 _RHS1( 11) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 14) += (f_flux - b_flux);
 
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 19 ,11)  += _term;
 _MATELM1( 14 ,11)  -= _term;
 _term =  nR1 * _zdsqvol * CR_2C_1N ;
 _MATELM1( 11 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 14 ,19)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 11 ,14)  -= _term;
 _MATELM1( 19 ,14)  -= _term;
 _MATELM1( 14 ,14)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_2N <-> CR_2C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_2N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_2N ;
 _RHS1( 7) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 14) += (f_flux - b_flux);
 
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 19 ,7)  += _term;
 _MATELM1( 14 ,7)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_2N ;
 _MATELM1( 7 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 14 ,19)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 7 ,14)  -= _term;
 _MATELM1( 19 ,14)  -= _term;
 _MATELM1( 14 ,14)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_0N <-> CR_1C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_1C_0N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_1N ;
 _RHS1( 15) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 15 ,15)  += _term;
 _MATELM1( 19 ,15)  += _term;
 _MATELM1( 10 ,15)  -= _term;
 _term =  nT1 * _zdsqvol * CR_1C_0N ;
 _MATELM1( 15 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 10 ,19)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 15 ,10)  -= _term;
 _MATELM1( 19 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ ca + CR_0C_1N <-> CR_1C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_0C_1N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_1N ;
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 19 ,9)  += _term;
 _MATELM1( 10 ,9)  -= _term;
 _term =  nT1 * _zdsqvol * CR_0C_1N ;
 _MATELM1( 9 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 10 ,19)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 9 ,10)  -= _term;
 _MATELM1( 19 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_1N <-> CR_2C_1N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_1N ;
 _RHS1( 10) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 11) += (f_flux - b_flux);
 
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 19 ,10)  += _term;
 _MATELM1( 11 ,10)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_1N ;
 _MATELM1( 10 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 11 ,19)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 10 ,11)  -= _term;
 _MATELM1( 19 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_1N <-> CR_1C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_1C_2N ;
 _RHS1( 10) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 19 ,10)  += _term;
 _MATELM1( 7 ,10)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_1N ;
 _MATELM1( 10 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 7 ,19)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 10 ,7)  -= _term;
 _MATELM1( 19 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ ca + CR <-> CR_1V ( nV1 * _zdsqvol , nV2 * _zdsqvol )*/
 f_flux =  nV1 * _zdsqvol * CR * ca ;
 b_flux =  nV2 * _zdsqvol * CR_1V ;
 _RHS1( 16) -= (f_flux - b_flux);
 _RHS1( 19) -= (f_flux - b_flux);
 _RHS1( 13) += (f_flux - b_flux);
 
 _term =  nV1 * _zdsqvol * ca ;
 _MATELM1( 16 ,16)  += _term;
 _MATELM1( 19 ,16)  += _term;
 _MATELM1( 13 ,16)  -= _term;
 _term =  nV1 * _zdsqvol * CR ;
 _MATELM1( 16 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 13 ,19)  -= _term;
 _term =  nV2 * _zdsqvol ;
 _MATELM1( 16 ,13)  -= _term;
 _MATELM1( 19 ,13)  -= _term;
 _MATELM1( 13 ,13)  += _term;
 /*REACTION*/
  cai = ca ;
   mgi = mg ;
     } return _reset;
 }
 
double ssBuff1 ( _threadargsproto_ ) {
   double _lssBuff1;
 _lssBuff1 = Buffnull1 / ( 1.0 + ( ( rf1 / rf2 ) * cainull ) ) ;
   
return _lssBuff1;
 }
 
static void _hoc_ssBuff1(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssBuff1 ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
double ssBuff1ca ( _threadargsproto_ ) {
   double _lssBuff1ca;
 _lssBuff1ca = Buffnull1 / ( 1.0 + ( rf2 / ( rf1 * cainull ) ) ) ;
   
return _lssBuff1ca;
 }
 
static void _hoc_ssBuff1ca(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssBuff1ca ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
double ssBuff2 ( _threadargsproto_ ) {
   double _lssBuff2;
 _lssBuff2 = Buffnull2 / ( 1.0 + ( ( rf3 / rf4 ) * cainull ) ) ;
   
return _lssBuff2;
 }
 
static void _hoc_ssBuff2(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssBuff2 ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
double ssBuff2ca ( _threadargsproto_ ) {
   double _lssBuff2ca;
 _lssBuff2ca = Buffnull2 / ( 1.0 + ( rf4 / ( rf3 * cainull ) ) ) ;
   
return _lssBuff2ca;
 }
 
static void _hoc_ssBuff2ca(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssBuff2ca ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
double ssBTC ( _threadargsproto_ ) {
   double _lssBTC;
 _lssBTC = BTCnull / ( 1.0 + ( ( b1 / b2 ) * cainull ) ) ;
   
return _lssBTC;
 }
 
static void _hoc_ssBTC(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssBTC ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
double ssBTCca ( _threadargsproto_ ) {
   double _lssBTCca;
 _lssBTCca = BTCnull / ( 1.0 + ( b2 / ( b1 * cainull ) ) ) ;
   
return _lssBTCca;
 }
 
static void _hoc_ssBTCca(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssBTCca ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
double ssDMNPE ( _threadargsproto_ ) {
   double _lssDMNPE;
 _lssDMNPE = DMNPEnull / ( 1.0 + ( ( c1 / c2 ) * cainull ) ) ;
   
return _lssDMNPE;
 }
 
static void _hoc_ssDMNPE(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssDMNPE ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
double ssDMNPEca ( _threadargsproto_ ) {
   double _lssDMNPEca;
 _lssDMNPEca = DMNPEnull / ( 1.0 + ( c2 / ( c1 * cainull ) ) ) ;
   
return _lssDMNPEca;
 }
 
static void _hoc_ssDMNPEca(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; _NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ssDMNPEca ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
/*CVODE ode begin*/
 static int _ode_spec1(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<21;_i++) _p[_dlist1[_i]] = 0.0;}
 /* COMPARTMENT diam * diam * vrat {
   ca mg Buff1 Buff1_ca Buff2 Buff2_ca BTC BTC_ca DMNPE DMNPE_ca CR CR_1C_0N CR_2C_0N CR_2C_1N CR_0C_1N CR_0C_2N CR_1C_2N CR_1C_1N CR_2C_1N CR_1C_2N CR_2C_2N }
 */
 /* COMPARTMENT ( 1e10 ) * parea {
   pump pumpca }
 */
 /* ~ ca + pump <-> pumpca ( kpmp1 * parea * ( 1e10 ) , kpmp2 * parea * ( 1e10 ) )*/
 f_flux =  kpmp1 * parea * ( 1e10 ) * pump * ca ;
 b_flux =  kpmp2 * parea * ( 1e10 ) * pumpca ;
 Dpump -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 Dpumpca += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ pumpca <-> pump ( kpmp3 * parea * ( 1e10 ) , 0.0 )*/
 f_flux =  kpmp3 * parea * ( 1e10 ) * pumpca ;
 b_flux =  0.0 * pump ;
 Dpumpca -= (f_flux - b_flux);
 Dpump += (f_flux - b_flux);
 
 /*REACTION*/
   /* pump + pumpca = TotalPump * parea * ( 1e10 ) */
 /*CONSERVATION*/
 ica_pmp = 2.0 * FARADAY * ( f_flux - b_flux ) / parea ;
 /* ~ ca < < ( - ica * PI * diam / ( 2.0 * FARADAY ) )*/
 f_flux = b_flux = 0.;
 Dca += (b_flux =   ( - ica * PI * diam / ( 2.0 * FARADAY ) ) );
 /*FLUX*/
  _zdsq = diam * diam ;
 _zdsqvol = _zdsq * vrat ;
 /* ~ ca + Buff1 <-> Buff1_ca ( rf1 * _zdsqvol , rf2 * _zdsqvol )*/
 f_flux =  rf1 * _zdsqvol * Buff1 * ca ;
 b_flux =  rf2 * _zdsqvol * Buff1_ca ;
 DBuff1 -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DBuff1_ca += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + Buff2 <-> Buff2_ca ( rf3 * _zdsqvol , rf4 * _zdsqvol )*/
 f_flux =  rf3 * _zdsqvol * Buff2 * ca ;
 b_flux =  rf4 * _zdsqvol * Buff2_ca ;
 DBuff2 -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DBuff2_ca += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + BTC <-> BTC_ca ( b1 * _zdsqvol , b2 * _zdsqvol )*/
 f_flux =  b1 * _zdsqvol * BTC * ca ;
 b_flux =  b2 * _zdsqvol * BTC_ca ;
 DBTC -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DBTC_ca += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + DMNPE <-> DMNPE_ca ( c1 * _zdsqvol , c2 * _zdsqvol )*/
 f_flux =  c1 * _zdsqvol * DMNPE * ca ;
 b_flux =  c2 * _zdsqvol * DMNPE_ca ;
 DDMNPE -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DDMNPE_ca += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR <-> CR_1C_0N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_0N ;
 DCR -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_1C_0N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_1C_0N <-> CR_2C_0N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_0N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_0N ;
 DCR_1C_0N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_2C_0N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_2C_0N <-> CR_2C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_2C_0N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_2C_1N ;
 DCR_2C_0N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_2C_1N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR <-> CR_0C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR * ca ;
 b_flux =  nT2 * _zdsqvol * CR_0C_1N ;
 DCR -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_0C_1N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_0C_1N <-> CR_0C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_0C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_0C_2N ;
 DCR_0C_1N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_0C_2N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_0C_2N <-> CR_1C_2N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_0C_2N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_2N ;
 DCR_0C_2N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_1C_2N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_2C_1N <-> CR_2C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_2C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_2N ;
 DCR_2C_1N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_2C_2N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_1C_2N <-> CR_2C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_2N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_2N ;
 DCR_1C_2N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_2C_2N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_1C_0N <-> CR_1C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_1C_0N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_1N ;
 DCR_1C_0N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_1C_1N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_0C_1N <-> CR_1C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 f_flux =  nT1 * _zdsqvol * CR_0C_1N * ca ;
 b_flux =  nT2 * _zdsqvol * CR_1C_1N ;
 DCR_0C_1N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_1C_1N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_1C_1N <-> CR_2C_1N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_2C_1N ;
 DCR_1C_1N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_2C_1N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR_1C_1N <-> CR_1C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 f_flux =  nR1 * _zdsqvol * CR_1C_1N * ca ;
 b_flux =  nR2 * _zdsqvol * CR_1C_2N ;
 DCR_1C_1N -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_1C_2N += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca + CR <-> CR_1V ( nV1 * _zdsqvol , nV2 * _zdsqvol )*/
 f_flux =  nV1 * _zdsqvol * CR * ca ;
 b_flux =  nV2 * _zdsqvol * CR_1V ;
 DCR -= (f_flux - b_flux);
 Dca -= (f_flux - b_flux);
 DCR_1V += (f_flux - b_flux);
 
 /*REACTION*/
  cai = ca ;
 mgi = mg ;
 _p[_dlist1[0]] /= ( ( 1e10 ) * parea);
 _p[_dlist1[1]] /= ( diam * diam * vrat);
 _p[_dlist1[2]] /= ( diam * diam * vrat);
 _p[_dlist1[3]] /= ( diam * diam * vrat);
 _p[_dlist1[4]] /= ( diam * diam * vrat);
 _p[_dlist1[5]] /= ( diam * diam * vrat);
 _p[_dlist1[6]] /= ( diam * diam * vrat);
 _p[_dlist1[7]] /= ( diam * diam * vrat);
 _p[_dlist1[8]] /= ( diam * diam * vrat);
 _p[_dlist1[9]] /= ( diam * diam * vrat);
 _p[_dlist1[10]] /= ( diam * diam * vrat);
 _p[_dlist1[11]] /= ( diam * diam * vrat);
 _p[_dlist1[12]] /= ( diam * diam * vrat);
 _p[_dlist1[14]] /= ( diam * diam * vrat);
 _p[_dlist1[15]] /= ( diam * diam * vrat);
 _p[_dlist1[16]] /= ( diam * diam * vrat);
 _p[_dlist1[17]] /= ( diam * diam * vrat);
 _p[_dlist1[18]] /= ( diam * diam * vrat);
 _p[_dlist1[19]] /= ( diam * diam * vrat);
 _p[_dlist1[20]] /= ( ( 1e10 ) * parea);
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1(void* _so, double* _rhs, double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {int _reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<21;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
}  
_RHS1(0) *= ( ( 1e10 ) * parea) ;
_MATELM1(0, 0) *= ( ( 1e10 ) * parea); 
_RHS1(1) *= ( diam * diam * vrat) ;
_MATELM1(1, 1) *= ( diam * diam * vrat); 
_RHS1(2) *= ( diam * diam * vrat) ;
_MATELM1(2, 2) *= ( diam * diam * vrat); 
_RHS1(3) *= ( diam * diam * vrat) ;
_MATELM1(3, 3) *= ( diam * diam * vrat); 
_RHS1(4) *= ( diam * diam * vrat) ;
_MATELM1(4, 4) *= ( diam * diam * vrat); 
_RHS1(5) *= ( diam * diam * vrat) ;
_MATELM1(5, 5) *= ( diam * diam * vrat); 
_RHS1(6) *= ( diam * diam * vrat) ;
_MATELM1(6, 6) *= ( diam * diam * vrat); 
_RHS1(7) *= ( diam * diam * vrat) ;
_MATELM1(7, 7) *= ( diam * diam * vrat); 
_RHS1(8) *= ( diam * diam * vrat) ;
_MATELM1(8, 8) *= ( diam * diam * vrat); 
_RHS1(9) *= ( diam * diam * vrat) ;
_MATELM1(9, 9) *= ( diam * diam * vrat); 
_RHS1(10) *= ( diam * diam * vrat) ;
_MATELM1(10, 10) *= ( diam * diam * vrat); 
_RHS1(11) *= ( diam * diam * vrat) ;
_MATELM1(11, 11) *= ( diam * diam * vrat); 
_RHS1(12) *= ( diam * diam * vrat) ;
_MATELM1(12, 12) *= ( diam * diam * vrat); 
_RHS1(14) *= ( diam * diam * vrat) ;
_MATELM1(14, 14) *= ( diam * diam * vrat); 
_RHS1(15) *= ( diam * diam * vrat) ;
_MATELM1(15, 15) *= ( diam * diam * vrat); 
_RHS1(16) *= ( diam * diam * vrat) ;
_MATELM1(16, 16) *= ( diam * diam * vrat); 
_RHS1(17) *= ( diam * diam * vrat) ;
_MATELM1(17, 17) *= ( diam * diam * vrat); 
_RHS1(18) *= ( diam * diam * vrat) ;
_MATELM1(18, 18) *= ( diam * diam * vrat); 
_RHS1(19) *= ( diam * diam * vrat) ;
_MATELM1(19, 19) *= ( diam * diam * vrat); 
_RHS1(20) *= ( ( 1e10 ) * parea) ;
_MATELM1(20, 20) *= ( ( 1e10 ) * parea);  }
 /* COMPARTMENT diam * diam * vrat {
 ca mg Buff1 Buff1_ca Buff2 Buff2_ca BTC BTC_ca DMNPE DMNPE_ca CR CR_1C_0N CR_2C_0N CR_2C_1N CR_0C_1N CR_0C_2N CR_1C_2N CR_1C_1N CR_2C_1N CR_1C_2N CR_2C_2N }
 */
 /* COMPARTMENT ( 1e10 ) * parea {
 pump pumpca }
 */
 /* ~ ca + pump <-> pumpca ( kpmp1 * parea * ( 1e10 ) , kpmp2 * parea * ( 1e10 ) )*/
 _term =  kpmp1 * parea * ( 1e10 ) * ca ;
 _MATELM1( 20 ,20)  += _term;
 _MATELM1( 19 ,20)  += _term;
 _MATELM1( 0 ,20)  -= _term;
 _term =  kpmp1 * parea * ( 1e10 ) * pump ;
 _MATELM1( 20 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 0 ,19)  -= _term;
 _term =  kpmp2 * parea * ( 1e10 ) ;
 _MATELM1( 20 ,0)  -= _term;
 _MATELM1( 19 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ pumpca <-> pump ( kpmp3 * parea * ( 1e10 ) , 0.0 )*/
 _term =  kpmp3 * parea * ( 1e10 ) ;
 _MATELM1( 0 ,0)  += _term;
 _MATELM1( 20 ,0)  -= _term;
 _term =  0.0 ;
 _MATELM1( 0 ,20)  -= _term;
 _MATELM1( 20 ,20)  += _term;
 /* ~ ca < < ( - ica * PI * diam / ( 2.0 * FARADAY ) )*/
 /*FLUX*/
  _zdsq = diam * diam ;
 _zdsqvol = _zdsq * vrat ;
 /* ~ ca + Buff1 <-> Buff1_ca ( rf1 * _zdsqvol , rf2 * _zdsqvol )*/
 _term =  rf1 * _zdsqvol * ca ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 19 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  rf1 * _zdsqvol * Buff1 ;
 _MATELM1( 6 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 5 ,19)  -= _term;
 _term =  rf2 * _zdsqvol ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 19 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ ca + Buff2 <-> Buff2_ca ( rf3 * _zdsqvol , rf4 * _zdsqvol )*/
 _term =  rf3 * _zdsqvol * ca ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 19 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  rf3 * _zdsqvol * Buff2 ;
 _MATELM1( 4 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 3 ,19)  -= _term;
 _term =  rf4 * _zdsqvol ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 19 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ ca + BTC <-> BTC_ca ( b1 * _zdsqvol , b2 * _zdsqvol )*/
 _term =  b1 * _zdsqvol * ca ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 19 ,2)  += _term;
 _MATELM1( 1 ,2)  -= _term;
 _term =  b1 * _zdsqvol * BTC ;
 _MATELM1( 2 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 1 ,19)  -= _term;
 _term =  b2 * _zdsqvol ;
 _MATELM1( 2 ,1)  -= _term;
 _MATELM1( 19 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ ca + DMNPE <-> DMNPE_ca ( c1 * _zdsqvol , c2 * _zdsqvol )*/
 _term =  c1 * _zdsqvol * ca ;
 _MATELM1( 18 ,18)  += _term;
 _MATELM1( 19 ,18)  += _term;
 _MATELM1( 17 ,18)  -= _term;
 _term =  c1 * _zdsqvol * DMNPE ;
 _MATELM1( 18 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 17 ,19)  -= _term;
 _term =  c2 * _zdsqvol ;
 _MATELM1( 18 ,17)  -= _term;
 _MATELM1( 19 ,17)  -= _term;
 _MATELM1( 17 ,17)  += _term;
 /*REACTION*/
  /* ~ ca + CR <-> CR_1C_0N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 16 ,16)  += _term;
 _MATELM1( 19 ,16)  += _term;
 _MATELM1( 15 ,16)  -= _term;
 _term =  nT1 * _zdsqvol * CR ;
 _MATELM1( 16 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 15 ,19)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 16 ,15)  -= _term;
 _MATELM1( 19 ,15)  -= _term;
 _MATELM1( 15 ,15)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_0N <-> CR_2C_0N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 15 ,15)  += _term;
 _MATELM1( 19 ,15)  += _term;
 _MATELM1( 12 ,15)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_0N ;
 _MATELM1( 15 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 12 ,19)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 15 ,12)  -= _term;
 _MATELM1( 19 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ ca + CR_2C_0N <-> CR_2C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 19 ,12)  += _term;
 _MATELM1( 11 ,12)  -= _term;
 _term =  nT1 * _zdsqvol * CR_2C_0N ;
 _MATELM1( 12 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 11 ,19)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 12 ,11)  -= _term;
 _MATELM1( 19 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ ca + CR <-> CR_0C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 16 ,16)  += _term;
 _MATELM1( 19 ,16)  += _term;
 _MATELM1( 9 ,16)  -= _term;
 _term =  nT1 * _zdsqvol * CR ;
 _MATELM1( 16 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 9 ,19)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 16 ,9)  -= _term;
 _MATELM1( 19 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ ca + CR_0C_1N <-> CR_0C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 19 ,9)  += _term;
 _MATELM1( 8 ,9)  -= _term;
 _term =  nR1 * _zdsqvol * CR_0C_1N ;
 _MATELM1( 9 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 8 ,19)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 9 ,8)  -= _term;
 _MATELM1( 19 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ ca + CR_0C_2N <-> CR_1C_2N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 19 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  nT1 * _zdsqvol * CR_0C_2N ;
 _MATELM1( 8 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 7 ,19)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 19 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ ca + CR_2C_1N <-> CR_2C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 19 ,11)  += _term;
 _MATELM1( 14 ,11)  -= _term;
 _term =  nR1 * _zdsqvol * CR_2C_1N ;
 _MATELM1( 11 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 14 ,19)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 11 ,14)  -= _term;
 _MATELM1( 19 ,14)  -= _term;
 _MATELM1( 14 ,14)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_2N <-> CR_2C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 19 ,7)  += _term;
 _MATELM1( 14 ,7)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_2N ;
 _MATELM1( 7 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 14 ,19)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 7 ,14)  -= _term;
 _MATELM1( 19 ,14)  -= _term;
 _MATELM1( 14 ,14)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_0N <-> CR_1C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 15 ,15)  += _term;
 _MATELM1( 19 ,15)  += _term;
 _MATELM1( 10 ,15)  -= _term;
 _term =  nT1 * _zdsqvol * CR_1C_0N ;
 _MATELM1( 15 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 10 ,19)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 15 ,10)  -= _term;
 _MATELM1( 19 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ ca + CR_0C_1N <-> CR_1C_1N ( nT1 * _zdsqvol , nT2 * _zdsqvol )*/
 _term =  nT1 * _zdsqvol * ca ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 19 ,9)  += _term;
 _MATELM1( 10 ,9)  -= _term;
 _term =  nT1 * _zdsqvol * CR_0C_1N ;
 _MATELM1( 9 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 10 ,19)  -= _term;
 _term =  nT2 * _zdsqvol ;
 _MATELM1( 9 ,10)  -= _term;
 _MATELM1( 19 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_1N <-> CR_2C_1N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 19 ,10)  += _term;
 _MATELM1( 11 ,10)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_1N ;
 _MATELM1( 10 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 11 ,19)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 10 ,11)  -= _term;
 _MATELM1( 19 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ ca + CR_1C_1N <-> CR_1C_2N ( nR1 * _zdsqvol , nR2 * _zdsqvol )*/
 _term =  nR1 * _zdsqvol * ca ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 19 ,10)  += _term;
 _MATELM1( 7 ,10)  -= _term;
 _term =  nR1 * _zdsqvol * CR_1C_1N ;
 _MATELM1( 10 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 7 ,19)  -= _term;
 _term =  nR2 * _zdsqvol ;
 _MATELM1( 10 ,7)  -= _term;
 _MATELM1( 19 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ ca + CR <-> CR_1V ( nV1 * _zdsqvol , nV2 * _zdsqvol )*/
 _term =  nV1 * _zdsqvol * ca ;
 _MATELM1( 16 ,16)  += _term;
 _MATELM1( 19 ,16)  += _term;
 _MATELM1( 13 ,16)  -= _term;
 _term =  nV1 * _zdsqvol * CR ;
 _MATELM1( 16 ,19)  += _term;
 _MATELM1( 19 ,19)  += _term;
 _MATELM1( 13 ,19)  -= _term;
 _term =  nV2 * _zdsqvol ;
 _MATELM1( 16 ,13)  -= _term;
 _MATELM1( 19 ,13)  -= _term;
 _MATELM1( 13 ,13)  += _term;
 /*REACTION*/
  cai = ca ;
 mgi = mg ;
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 21;}
 
static void _ode_spec(_NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  _ion_cai = cai;
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 21; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 static void _ode_synonym(int _cnt, double** _pp, Datum** _ppd) { 
	double* _p; Datum* _ppvar;
 	int _i; 
	for (_i=0; _i < _cnt; ++_i) {_p = _pp[_i]; _ppvar = _ppd[_i];
 _ion_cai =  ca ;
 }}
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse_thread(&_thread[_cvspth1]._pvoid, 21, _dlist1, _p, _ode_matsol1, _ppvar, _thread, _nt);
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
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
 _ode_matsol_instance1(_threadargs_);
 }}
 
static void _thread_mem_init(Datum* _thread) {
   _thread[2]._pval = (double*)ecalloc(3, sizeof(double));
 }
 
static void _thread_cleanup(Datum* _thread) {
   _nrn_destroy_sparseobj_thread(_thread[_cvspth1]._pvoid);
   _nrn_destroy_sparseobj_thread(_thread[_spth1]._pvoid);
   free((void*)(_thread[2]._pval));
 }
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 2);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 3);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt) {
  int _i; double _save;{
  BTC_ca = BTC_ca0;
  BTC = BTC0;
  Buff2_ca = Buff2_ca0;
  Buff2 = Buff20;
  Buff1_ca = Buff1_ca0;
  Buff1 = Buff10;
  CR_1C_2N = CR_1C_2N0;
  CR_0C_2N = CR_0C_2N0;
  CR_0C_1N = CR_0C_1N0;
  CR_1C_1N = CR_1C_1N0;
  CR_2C_1N = CR_2C_1N0;
  CR_2C_0N = CR_2C_0N0;
  CR_1V = CR_1V0;
  CR_2C_2N = CR_2C_2N0;
  CR_1C_0N = CR_1C_0N0;
  CR = CR0;
  DMNPE_ca = DMNPE_ca0;
  DMNPE = DMNPE0;
  ca = ca0;
  mg = mg0;
  pumpca = pumpca0;
  pump = pump0;
 {
   factors ( _threadargs_ ) ;
   ca = cainull ;
   mg = mginull ;
   Buff1 = ssBuff1 ( _threadargs_ ) ;
   Buff1_ca = ssBuff1ca ( _threadargs_ ) ;
   Buff2 = ssBuff2 ( _threadargs_ ) ;
   Buff2_ca = ssBuff2ca ( _threadargs_ ) ;
   BTC = ssBTC ( _threadargs_ ) ;
   BTC_ca = ssBTCca ( _threadargs_ ) ;
   DMNPE = ssDMNPE ( _threadargs_ ) ;
   DMNPE_ca = ssDMNPEca ( _threadargs_ ) ;
   CR = CRnull ;
   CR_1C_0N = 0.0 ;
   CR_2C_0N = 0.0 ;
   CR_2C_1N = 0.0 ;
   CR_1C_1N = 0.0 ;
   CR_0C_1N = 0.0 ;
   CR_0C_2N = 0.0 ;
   CR_1C_2N = 0.0 ;
   CR_2C_2N = 0.0 ;
   CR_1V = 0.0 ;
   parea = PI * diam ;
   parea2 = PI * ( diam - 0.2 ) ;
   ica = 0.0 ;
   ica_pmp = 0.0 ;
   pump = TotalPump ;
   pumpca = 0.0 ;
   cai = ca ;
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
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
 initmodel(_p, _ppvar, _thread, _nt);
  _ion_cai = cai;
  nrn_wrote_conc(_ca_sym, (&(_ion_cai)) - 1, _style_ca);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, _NrnThread* _nt, double _v){double _current=0.;v=_v;{
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
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
 {  sparse_thread(&_thread[_spth1]._pvoid, 21, _slist1, _dlist1, _p, &t, dt, state, _linmat1, _ppvar, _thread, _nt);
     if (secondorder) {
    int _i;
    for (_i = 0; _i < 21; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } {
   }
  _ion_cai = cai;
}}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = &(pumpca) - _p;  _dlist1[0] = &(Dpumpca) - _p;
 _slist1[1] = &(BTC_ca) - _p;  _dlist1[1] = &(DBTC_ca) - _p;
 _slist1[2] = &(BTC) - _p;  _dlist1[2] = &(DBTC) - _p;
 _slist1[3] = &(Buff2_ca) - _p;  _dlist1[3] = &(DBuff2_ca) - _p;
 _slist1[4] = &(Buff2) - _p;  _dlist1[4] = &(DBuff2) - _p;
 _slist1[5] = &(Buff1_ca) - _p;  _dlist1[5] = &(DBuff1_ca) - _p;
 _slist1[6] = &(Buff1) - _p;  _dlist1[6] = &(DBuff1) - _p;
 _slist1[7] = &(CR_1C_2N) - _p;  _dlist1[7] = &(DCR_1C_2N) - _p;
 _slist1[8] = &(CR_0C_2N) - _p;  _dlist1[8] = &(DCR_0C_2N) - _p;
 _slist1[9] = &(CR_0C_1N) - _p;  _dlist1[9] = &(DCR_0C_1N) - _p;
 _slist1[10] = &(CR_1C_1N) - _p;  _dlist1[10] = &(DCR_1C_1N) - _p;
 _slist1[11] = &(CR_2C_1N) - _p;  _dlist1[11] = &(DCR_2C_1N) - _p;
 _slist1[12] = &(CR_2C_0N) - _p;  _dlist1[12] = &(DCR_2C_0N) - _p;
 _slist1[13] = &(CR_1V) - _p;  _dlist1[13] = &(DCR_1V) - _p;
 _slist1[14] = &(CR_2C_2N) - _p;  _dlist1[14] = &(DCR_2C_2N) - _p;
 _slist1[15] = &(CR_1C_0N) - _p;  _dlist1[15] = &(DCR_1C_0N) - _p;
 _slist1[16] = &(CR) - _p;  _dlist1[16] = &(DCR) - _p;
 _slist1[17] = &(DMNPE_ca) - _p;  _dlist1[17] = &(DDMNPE_ca) - _p;
 _slist1[18] = &(DMNPE) - _p;  _dlist1[18] = &(DDMNPE) - _p;
 _slist1[19] = &(ca) - _p;  _dlist1[19] = &(Dca) - _p;
 _slist1[20] = &(pump) - _p;  _dlist1[20] = &(Dpump) - _p;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif
