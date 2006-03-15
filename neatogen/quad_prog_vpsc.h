/**********************************************************
*      This software is part of the graphviz package      *
*                http://www.graphviz.org/                 *
*                                                         *
*            Copyright (c) 1994-2004 AT&T Corp.           *
*                and is licensed under the                *
*            Common Public License, Version 1.0           *
*                      by AT&T Corp.                      *
*                                                         *
*        Information and Software Systems Research        *
*              AT&T Research, Florham Park NJ             *
**********************************************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _QUAD_PROG_VPSC_H_
#define _QUAD_PROG_VPSC_H_

#ifdef DIGCOLA

typedef struct {
	float **A;
	int n; /* number of vars */
	Variable **vs;
	int m; /* total number of constraints for next iteration */
	int gm; /* number of global constraints */
	Constraint **cs;
	/* global constraints are persistant throughout optimisation process */
	Constraint **gcs;
	VPSC *vpsc;
	int *iArray1; /* utility arrays */
	int *iArray2;
	int *iArray3;
	int *iArray4;
	float *fArray1;
	float *fArray2;
	float *fArray3;
	float *fArray4;
} CMajEnvVPSC;

extern CMajEnvVPSC* initCMajVPSC(int n, float *, vtx_data*, int, float);

extern int constrained_majorization_vpsc(CMajEnvVPSC*, float*, float*, int);

extern void deleteCMajEnvVPSC(CMajEnvVPSC *e);
extern void generateNonoverlapConstraints(
        CMajEnvVPSC* e,
        float* nwidth,
        float* nheight,
	float xgap,
	float ygap,
        float nsizeScale,
        float** coords,
        int k
);

extern void removeoverlaps(int,float**,float*,float*,float,float);

#endif 

#endif /* _QUAD_PROG_VPSC_H_ */

#ifdef __cplusplus
}
#endif