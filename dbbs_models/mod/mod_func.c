#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _GRC_CA_reg();
extern void _GRC_KM_reg();
extern void _GRC_NA_reg();
extern void _GRC_NA_FHF_reg();
extern void _Kca11_reg();
extern void _Kca22_reg();
extern void _Kir23_reg();
extern void _Kv11_reg();
extern void _Kv15_reg();
extern void _Kv22_reg();
extern void _Kv34_reg();
extern void _Kv43_reg();
extern void _Leak_reg();
extern void _cdp5_CR_reg();

void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," GRC_CA.mod");
fprintf(stderr," GRC_KM.mod");
fprintf(stderr," GRC_NA.mod");
fprintf(stderr," GRC_NA_FHF.mod");
fprintf(stderr," Kca11.mod");
fprintf(stderr," Kca22.mod");
fprintf(stderr," Kir23.mod");
fprintf(stderr," Kv11.mod");
fprintf(stderr," Kv15.mod");
fprintf(stderr," Kv22.mod");
fprintf(stderr," Kv34.mod");
fprintf(stderr," Kv43.mod");
fprintf(stderr," Leak.mod");
fprintf(stderr," cdp5_CR.mod");
fprintf(stderr, "\n");
    }
_GRC_CA_reg();
_GRC_KM_reg();
_GRC_NA_reg();
_GRC_NA_FHF_reg();
_Kca11_reg();
_Kca22_reg();
_Kir23_reg();
_Kv11_reg();
_Kv15_reg();
_Kv22_reg();
_Kv34_reg();
_Kv43_reg();
_Leak_reg();
_cdp5_CR_reg();
}
