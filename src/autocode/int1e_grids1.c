/*
 * Copyright (C) 2013-  Qiming Sun <osirpt.sun@gmail.com>
 * Description: code generated by  gen-code.cl
 */
#include <stdlib.h>
#include <stdio.h>
#include "cint_bas.h"
#include "cart2sph.h"
#include "g1e.h"
#include "g1e_grids.h"
#include "g2e.h"
#include "optimizer.h"
#include "cint1e.h"
#include "cint2e.h"
#include "misc.h"
#include "c2f.h"
/* <NABLA i| 1/r_{grids} |j> */
void CINTgout1e_int1e_grids_ip(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT ngrids = envs->ngrids;
FINT bgrids = MIN(ngrids - envs->grids_offset, GRID_BLKSIZE);
FINT nrys_roots = envs->nrys_roots;
FINT nf = envs->nf;
FINT ix, iy, iz, n, i, ig;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double s[GRID_BLKSIZE * 3];
G1E_GRIDS_D_I(g1, g0, envs->i_l+0, envs->j_l);
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 3; i++) {
for (ig = 0; ig < bgrids; ig++) { s[ig+i*GRID_BLKSIZE] = 0; }}
for (i = 0; i < nrys_roots; i++) {
for (ig = 0; ig < bgrids; ig++) {
s[ig+GRID_BLKSIZE*0] += g1[ix+ig+i*GRID_BLKSIZE] * g0[iy+ig+i*GRID_BLKSIZE] * g0[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*1] += g0[ix+ig+i*GRID_BLKSIZE] * g1[iy+ig+i*GRID_BLKSIZE] * g0[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*2] += g0[ix+ig+i*GRID_BLKSIZE] * g0[iy+ig+i*GRID_BLKSIZE] * g1[iz+ig+i*GRID_BLKSIZE];
}};
if (gout_empty) {
for (ig = 0; ig < bgrids; ig++) {
gout[ig+bgrids*(n*3+0)] = + s[ig+GRID_BLKSIZE*0];
gout[ig+bgrids*(n*3+1)] = + s[ig+GRID_BLKSIZE*1];
gout[ig+bgrids*(n*3+2)] = + s[ig+GRID_BLKSIZE*2];
}} else {
for (ig = 0; ig < bgrids; ig++) {
gout[ig+bgrids*(n*3+0)] += + s[ig+GRID_BLKSIZE*0];
gout[ig+bgrids*(n*3+1)] += + s[ig+GRID_BLKSIZE*1];
gout[ig+bgrids*(n*3+2)] += + s[ig+GRID_BLKSIZE*2];
}}}}
void int1e_grids_ip_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTall_1e_grids_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_grids_ip_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_grids_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_grids_ip;
return CINT1e_grids_drv(out, dims, &envs, cache, &c2s_cart_1e_grids);
} // int1e_grids_ip_cart
CACHE_SIZE_T int1e_grids_ip_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_grids_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_grids_ip;
return CINT1e_grids_drv(out, dims, &envs, cache, &c2s_sph_1e_grids);
} // int1e_grids_ip_sph
CACHE_SIZE_T int1e_grids_ip_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_grids_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_grids_ip;
return CINT1e_grids_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e_grids);
} // int1e_grids_ip_spinor
ALL_CINT1E(int1e_grids_ip)
ALL_CINT1E_FORTRAN_(int1e_grids_ip)
/* <NABLA i| 1/r_{grids} |NABLA j> */
void CINTgout1e_int1e_grids_ipvip(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT ngrids = envs->ngrids;
FINT bgrids = MIN(ngrids - envs->grids_offset, GRID_BLKSIZE);
FINT nrys_roots = envs->nrys_roots;
FINT nf = envs->nf;
FINT ix, iy, iz, n, i, ig;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double s[GRID_BLKSIZE * 9];
G1E_GRIDS_D_J(g1, g0, envs->i_l+1, envs->j_l+0);
G1E_GRIDS_D_I(g2, g0, envs->i_l+0, envs->j_l);
G1E_GRIDS_D_I(g3, g1, envs->i_l+0, envs->j_l);
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 9; i++) {
for (ig = 0; ig < bgrids; ig++) { s[ig+i*GRID_BLKSIZE] = 0; }}
for (i = 0; i < nrys_roots; i++) {
for (ig = 0; ig < bgrids; ig++) {
s[ig+GRID_BLKSIZE*0] += g3[ix+ig+i*GRID_BLKSIZE] * g0[iy+ig+i*GRID_BLKSIZE] * g0[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*1] += g2[ix+ig+i*GRID_BLKSIZE] * g1[iy+ig+i*GRID_BLKSIZE] * g0[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*2] += g2[ix+ig+i*GRID_BLKSIZE] * g0[iy+ig+i*GRID_BLKSIZE] * g1[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*3] += g1[ix+ig+i*GRID_BLKSIZE] * g2[iy+ig+i*GRID_BLKSIZE] * g0[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*4] += g0[ix+ig+i*GRID_BLKSIZE] * g3[iy+ig+i*GRID_BLKSIZE] * g0[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*5] += g0[ix+ig+i*GRID_BLKSIZE] * g2[iy+ig+i*GRID_BLKSIZE] * g1[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*6] += g1[ix+ig+i*GRID_BLKSIZE] * g0[iy+ig+i*GRID_BLKSIZE] * g2[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*7] += g0[ix+ig+i*GRID_BLKSIZE] * g1[iy+ig+i*GRID_BLKSIZE] * g2[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*8] += g0[ix+ig+i*GRID_BLKSIZE] * g0[iy+ig+i*GRID_BLKSIZE] * g3[iz+ig+i*GRID_BLKSIZE];
}};
if (gout_empty) {
for (ig = 0; ig < bgrids; ig++) {
gout[ig+bgrids*(n*9+0)] = + s[ig+GRID_BLKSIZE*0];
gout[ig+bgrids*(n*9+1)] = + s[ig+GRID_BLKSIZE*1];
gout[ig+bgrids*(n*9+2)] = + s[ig+GRID_BLKSIZE*2];
gout[ig+bgrids*(n*9+3)] = + s[ig+GRID_BLKSIZE*3];
gout[ig+bgrids*(n*9+4)] = + s[ig+GRID_BLKSIZE*4];
gout[ig+bgrids*(n*9+5)] = + s[ig+GRID_BLKSIZE*5];
gout[ig+bgrids*(n*9+6)] = + s[ig+GRID_BLKSIZE*6];
gout[ig+bgrids*(n*9+7)] = + s[ig+GRID_BLKSIZE*7];
gout[ig+bgrids*(n*9+8)] = + s[ig+GRID_BLKSIZE*8];
}} else {
for (ig = 0; ig < bgrids; ig++) {
gout[ig+bgrids*(n*9+0)] += + s[ig+GRID_BLKSIZE*0];
gout[ig+bgrids*(n*9+1)] += + s[ig+GRID_BLKSIZE*1];
gout[ig+bgrids*(n*9+2)] += + s[ig+GRID_BLKSIZE*2];
gout[ig+bgrids*(n*9+3)] += + s[ig+GRID_BLKSIZE*3];
gout[ig+bgrids*(n*9+4)] += + s[ig+GRID_BLKSIZE*4];
gout[ig+bgrids*(n*9+5)] += + s[ig+GRID_BLKSIZE*5];
gout[ig+bgrids*(n*9+6)] += + s[ig+GRID_BLKSIZE*6];
gout[ig+bgrids*(n*9+7)] += + s[ig+GRID_BLKSIZE*7];
gout[ig+bgrids*(n*9+8)] += + s[ig+GRID_BLKSIZE*8];
}}}}
void int1e_grids_ipvip_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {1, 1, 0, 0, 2, 1, 0, 9};
CINTall_1e_grids_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_grids_ipvip_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 1, 0, 0, 2, 1, 0, 9};
CINTEnvVars envs;
CINTinit_int1e_grids_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_grids_ipvip;
return CINT1e_grids_drv(out, dims, &envs, cache, &c2s_cart_1e_grids);
} // int1e_grids_ipvip_cart
CACHE_SIZE_T int1e_grids_ipvip_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 1, 0, 0, 2, 1, 0, 9};
CINTEnvVars envs;
CINTinit_int1e_grids_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_grids_ipvip;
return CINT1e_grids_drv(out, dims, &envs, cache, &c2s_sph_1e_grids);
} // int1e_grids_ipvip_sph
CACHE_SIZE_T int1e_grids_ipvip_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 1, 0, 0, 2, 1, 0, 9};
CINTEnvVars envs;
CINTinit_int1e_grids_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_grids_ipvip;
return CINT1e_grids_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e_grids);
} // int1e_grids_ipvip_spinor
ALL_CINT1E(int1e_grids_ipvip)
ALL_CINT1E_FORTRAN_(int1e_grids_ipvip)
/* <SIGMA DOT P i| 1/r_{grids} |SIGMA DOT P j> */
void CINTgout1e_int1e_grids_spvsp(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT ngrids = envs->ngrids;
FINT bgrids = MIN(ngrids - envs->grids_offset, GRID_BLKSIZE);
FINT nrys_roots = envs->nrys_roots;
FINT nf = envs->nf;
FINT ix, iy, iz, n, i, ig;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double s[GRID_BLKSIZE * 9];
G1E_GRIDS_D_J(g1, g0, envs->i_l+1, envs->j_l+0);
G1E_GRIDS_D_I(g2, g0, envs->i_l+0, envs->j_l);
G1E_GRIDS_D_I(g3, g1, envs->i_l+0, envs->j_l);
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 9; i++) {
for (ig = 0; ig < bgrids; ig++) { s[ig+i*GRID_BLKSIZE] = 0; }}
for (i = 0; i < nrys_roots; i++) {
for (ig = 0; ig < bgrids; ig++) {
s[ig+GRID_BLKSIZE*0] += g3[ix+ig+i*GRID_BLKSIZE] * g0[iy+ig+i*GRID_BLKSIZE] * g0[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*1] += g2[ix+ig+i*GRID_BLKSIZE] * g1[iy+ig+i*GRID_BLKSIZE] * g0[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*2] += g2[ix+ig+i*GRID_BLKSIZE] * g0[iy+ig+i*GRID_BLKSIZE] * g1[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*3] += g1[ix+ig+i*GRID_BLKSIZE] * g2[iy+ig+i*GRID_BLKSIZE] * g0[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*4] += g0[ix+ig+i*GRID_BLKSIZE] * g3[iy+ig+i*GRID_BLKSIZE] * g0[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*5] += g0[ix+ig+i*GRID_BLKSIZE] * g2[iy+ig+i*GRID_BLKSIZE] * g1[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*6] += g1[ix+ig+i*GRID_BLKSIZE] * g0[iy+ig+i*GRID_BLKSIZE] * g2[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*7] += g0[ix+ig+i*GRID_BLKSIZE] * g1[iy+ig+i*GRID_BLKSIZE] * g2[iz+ig+i*GRID_BLKSIZE];
s[ig+GRID_BLKSIZE*8] += g0[ix+ig+i*GRID_BLKSIZE] * g0[iy+ig+i*GRID_BLKSIZE] * g3[iz+ig+i*GRID_BLKSIZE];
}};
if (gout_empty) {
for (ig = 0; ig < bgrids; ig++) {
gout[ig+bgrids*(n*4+0)] = + s[ig+GRID_BLKSIZE*5] - s[ig+GRID_BLKSIZE*7];
gout[ig+bgrids*(n*4+1)] = + s[ig+GRID_BLKSIZE*6] - s[ig+GRID_BLKSIZE*2];
gout[ig+bgrids*(n*4+2)] = + s[ig+GRID_BLKSIZE*1] - s[ig+GRID_BLKSIZE*3];
gout[ig+bgrids*(n*4+3)] = + s[ig+GRID_BLKSIZE*0] + s[ig+GRID_BLKSIZE*4] + s[ig+GRID_BLKSIZE*8];
}} else {
for (ig = 0; ig < bgrids; ig++) {
gout[ig+bgrids*(n*4+0)] += + s[ig+GRID_BLKSIZE*5] - s[ig+GRID_BLKSIZE*7];
gout[ig+bgrids*(n*4+1)] += + s[ig+GRID_BLKSIZE*6] - s[ig+GRID_BLKSIZE*2];
gout[ig+bgrids*(n*4+2)] += + s[ig+GRID_BLKSIZE*1] - s[ig+GRID_BLKSIZE*3];
gout[ig+bgrids*(n*4+3)] += + s[ig+GRID_BLKSIZE*0] + s[ig+GRID_BLKSIZE*4] + s[ig+GRID_BLKSIZE*8];
}}}}
void int1e_grids_spvsp_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {1, 1, 0, 0, 2, 4, 0, 1};
CINTall_1e_grids_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_grids_spvsp_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 1, 0, 0, 2, 4, 0, 1};
CINTEnvVars envs;
CINTinit_int1e_grids_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_grids_spvsp;
return CINT1e_grids_drv(out, dims, &envs, cache, &c2s_cart_1e_grids);
} // int1e_grids_spvsp_cart
CACHE_SIZE_T int1e_grids_spvsp_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 1, 0, 0, 2, 4, 0, 1};
CINTEnvVars envs;
CINTinit_int1e_grids_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_grids_spvsp;
return CINT1e_grids_drv(out, dims, &envs, cache, &c2s_sph_1e_grids);
} // int1e_grids_spvsp_sph
CACHE_SIZE_T int1e_grids_spvsp_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 1, 0, 0, 2, 4, 0, 1};
CINTEnvVars envs;
CINTinit_int1e_grids_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_grids_spvsp;
return CINT1e_grids_spinor_drv(out, dims, &envs, cache, &c2s_si_1e_grids);
} // int1e_grids_spvsp_spinor
ALL_CINT1E(int1e_grids_spvsp)
ALL_CINT1E_FORTRAN_(int1e_grids_spvsp)
