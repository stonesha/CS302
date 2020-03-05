#pragma once
#include <cstdio>
#include <cstddef>
#include <cstdlib>
#include <cmath>

#define NRANSI
#define NR_END 1
#define FREE_ARG char*

#ifndef MAX
#  define MAX(a,b)  ((a) < (b) ? (b) : (a))
#endif
#define SQR(a) ((a)*(a))
#define SIGN(a,b) ((b) >= 0.0 ? fabs(a) : -fabs(a))
#define IMIN(a,b) ((a) < (b) ? (a) : (b))

//svdcmp.c

/* Numerical Recipes standard error handler */
void nrerror(std::string error_text)
//char error_text[];
{
	fprintf(stderr, "Numerical Recipes run-time error...\n");
	fprintf(stderr, "%s\n", error_text.c_str());
	fprintf(stderr, "...now exiting to system...\n");
	exit(1);
}

/* allocate a float vector with subscript range v[nl..nh] */
float* Vector(long nl, long nh)
//long nl,nh;
{
	float* v;

	v = (float*)malloc((size_t)((nh - nl + 1 + NR_END) * sizeof(float)));
	if (!v) nrerror("allocation failure in vector()");
	return v - nl + NR_END;
}

/* free a float vector allocated with vector() */
void free_vector(float* v, long nl, long nh)
//float *v;
//long nl,nh;
{
	free((FREE_ARG)(v + nl - NR_END));
}

float pythag(float a, float b)
//float a,b;
{
	float absa, absb;

	absa = fabs(a);
	absb = fabs(b);
	if (absa > absb) return absa * sqrt(1.0 + SQR(absb / absa));
	else return (absb == 0.0 ? 0.0 : absb * sqrt(1.0 + SQR(absa / absb)));
}

void svdcmp(float** a, int m, int n, float* w, float** v)
//int m,n;
//float **a, *w, **v;
{
	//float pythag();
	//float* vector();
	int flag, i, its, j, jj, k, l, nm;
	float anorm, c, f, g, h, s, scale, x, y, z, *rv1;
	//void free_vector();

	rv1 = Vector(1, n);
	g = scale = anorm = 0.0;
	for (i = 1; i <= n; i++) {
		l = i + 1;
		rv1[i] = scale * g;
		g = s = scale = 0.0;
		if (i <= m) {
			for (k = i; k <= m; k++) scale += fabs(a[k][i]);
			if (scale) {
				for (k = i; k <= m; k++) {
					a[k][i] /= scale;
					s += a[k][i] * a[k][i];
				}
				f = a[i][i];
				g = -SIGN(sqrt(s), f);
				h = f * g - s;
				a[i][i] = f - g;
				for (j = l; j <= n; j++) {
					for (s = 0.0, k = i; k <= m; k++) s += a[k][i] * a[k][j];
					f = s / h;
					for (k = i; k <= m; k++) a[k][j] += f * a[k][i];
				}
				for (k = i; k <= m; k++) a[k][i] *= scale;
			}
		}
		w[i] = scale * g;
		g = s = scale = 0.0;
		if (i <= m && i != n) {
			for (k = l; k <= n; k++) scale += fabs(a[i][k]);
			if (scale) {
				for (k = l; k <= n; k++) {
					a[i][k] /= scale;
					s += a[i][k] * a[i][k];
				}
				f = a[i][l];
				g = -SIGN(sqrt(s), f);
				h = f * g - s;
				a[i][l] = f - g;
				for (k = l; k <= n; k++) rv1[k] = a[i][k] / h;
				for (j = l; j <= m; j++) {
					for (s = 0.0, k = l; k <= n; k++) s += a[j][k] * a[i][k];
					for (k = l; k <= n; k++) a[j][k] += s * rv1[k];
				}
				for (k = l; k <= n; k++) a[i][k] *= scale;
			}
		}
		anorm = MAX(anorm, (fabs(w[i]) + fabs(rv1[i])));
	}
	for (i = n; i >= 1; i--) {
		if (i < n) {
			if (g) {
				for (j = l; j <= n; j++)
					v[j][i] = (a[i][j] / a[i][l]) / g;
				for (j = l; j <= n; j++) {
					for (s = 0.0, k = l; k <= n; k++) s += a[i][k] * v[k][j];
					for (k = l; k <= n; k++) v[k][j] += s * v[k][i];
				}
			}
			for (j = l; j <= n; j++) v[i][j] = v[j][i] = 0.0;
		}
		v[i][i] = 1.0;
		g = rv1[i];
		l = i;
	}
	for (i = IMIN(m, n); i >= 1; i--) {
		l = i + 1;
		g = w[i];
		for (j = l; j <= n; j++) a[i][j] = 0.0;
		if (g) {
			g = 1.0 / g;
			for (j = l; j <= n; j++) {
				for (s = 0.0, k = l; k <= m; k++) s += a[k][i] * a[k][j];
				f = (s / a[i][i]) * g;
				for (k = i; k <= m; k++) a[k][j] += f * a[k][i];
			}
			for (j = i; j <= m; j++) a[j][i] *= g;
		}
		else for (j = i; j <= m; j++) a[j][i] = 0.0;
		++a[i][i];
	}
	for (k = n; k >= 1; k--) {
		for (its = 1; its <= 30; its++) {
			flag = 1;
			for (l = k; l >= 1; l--) {
				nm = l - 1;
				if ((float)(fabs(rv1[l]) + anorm) == anorm) {
					flag = 0;
					break;
				}
				if ((float)(fabs(w[nm]) + anorm) == anorm) break;
			}
			if (flag) {
				c = 0.0;
				s = 1.0;
				for (i = l; i <= k; i++) {
					f = s * rv1[i];
					rv1[i] = c * rv1[i];
					if ((float)(fabs(f) + anorm) == anorm) break;
					g = w[i];
					h = pythag(f, g);
					w[i] = h;
					h = 1.0 / h;
					c = g * h;
					s = -f * h;
					for (j = 1; j <= m; j++) {
						y = a[j][nm];
						z = a[j][i];
						a[j][nm] = y * c + z * s;
						a[j][i] = z * c - y * s;
					}
				}
			}
			z = w[k];
			if (l == k) {
				if (z < 0.0) {
					w[k] = -z;
					for (j = 1; j <= n; j++) v[j][k] = -v[j][k];
				}
				break;
			}
			if (its == 30) nrerror((char *)"no convergence in 30 svdcmp iterations");
			x = w[l];
			nm = k - 1;
			y = w[nm];
			g = rv1[nm];
			h = rv1[k];
			f = ((y - z) * (y + z) + (g - h) * (g + h)) / (2.0 * h * y);
			g = pythag(f, 1.0);
			f = ((x - z) * (x + z) + h * ((y / (f + SIGN(g, f))) - h)) / x;
			c = s = 1.0;
			for (j = l; j <= nm; j++) {
				i = j + 1;
				g = rv1[i];
				y = w[i];
				h = s * g;
				g = c * g;
				z = pythag(f, h);
				rv1[j] = z;
				c = f / z;
				s = h / z;
				f = x * c + g * s;
				g = g * c - x * s;
				h = y * s;
				y *= c;
				for (jj = 1; jj <= n; jj++) {
					x = v[jj][j];
					z = v[jj][i];
					v[jj][j] = x * c + z * s;
					v[jj][i] = z * c - x * s;
				}
				z = pythag(f, h);
				w[j] = z;
				if (z) {
					z = 1.0 / z;
					c = f * z;
					s = h * z;
				}
				f = c * g + s * y;
				x = c * y - s * g;
				for (jj = 1; jj <= m; jj++) {
					y = a[jj][j];
					z = a[jj][i];
					a[jj][j] = y * c + z * s;
					a[jj][i] = z * c - y * s;
				}
			}
			rv1[l] = 0.0;
			rv1[k] = f;
			w[k] = x;
		}
	}
	free_vector(rv1, 1, n);
}
#undef NRANSI

//svbksb.c

#define NRANSI

void svbksb(float** u, float* w, float** v, int m, int n, float* b, float* x)
//float **u, *w, **v, *b, *x;
//int m,n;
{
	int jj, j, i;
	float s, * tmp;

	tmp = Vector(1, n);
	for (j = 1; j <= n; j++) {
		s = 0.0;
		if (w[j]) {
			for (i = 1; i <= m; i++) s += u[i][j] * b[i];
			s /= w[j];
		}
		tmp[j] = s;
	}
	for (j = 1; j <= n; j++) {
		s = 0.0;
		for (jj = 1; jj <= n; jj++) s += v[j][jj] * tmp[jj];
		x[j] = s;
	}
	free_vector(tmp, 1, n);
}
#undef NRANSI

//solve_system.c

/* this routine solves a m x n linear system of equations using SVD */

void solve_system(int m, int n, float** a, float* x, float* b)
//int m,n;
//float **a, *x, *b;
{
	int i, j;
	float w_min, w_max, ** a_temp, * w, ** v;

	w = (float*)malloc((n + 1) * sizeof(float));

	v = (float**)malloc((n + 1) * sizeof(float*));
	for (i = 0; i < n + 1; i++)
		v[i] = (float*)malloc((n + 1) * sizeof(float));

	a_temp = (float**)malloc((m + 1) * sizeof(float*));
	for (i = 0; i < m + 1; i++)
		a_temp[i] = (float*)malloc((n + 1) * sizeof(float));

	/* copy a to a_temp because svdcmp changes a */

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			a_temp[i + 1][j + 1] = a[i + 1][j + 1];

	svdcmp(a_temp, m, n, w, v);

	w_min = w_max = w[1];
	for (j = 2; j <= n; j++) {
		if (w_min > w[j]) w_min = w[j];
		if (w_max < w[j]) w_max = w[j];
	}

	w_min = w_max * 1.0e-6;
	for (j = 1; j <= n; j++)
		if (w[j] < w_min) w[j] = 0.0;

	svbksb(a_temp, w, v, m, n, b, x);

	for (i = 0; i < m + 1; i++)
		free(a_temp[i]);
	free(a_temp);

	free(w);

	for (i = 0; i < n + 1; i++)
		free(v[i]);
	free(v);
}