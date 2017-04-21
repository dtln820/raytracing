#include "hIntersect.h"

int	ft_sphintersect(t_vec3 *o, t_vec3 *d, double *tNK, uint32_t iK, t_vec2 *uv, t_sphnode *sph_sent)
{
	t_vec3 *L;
	double a;
	double b;
	double c;
	double t0;
	double t1;

	L = ft_v3diff(o, sph_sent->sphere->point);
	a = ft_dotproduct(d, d);
	b = 2 * ft_dotproduct(d, L);
	c = ft_dotproduct(L, L) - (sph_sent->sphere->radius * sph_sent->sphere->radius);
	if (ft_eqsolve(a, b, c, &t0, &t1) == 0)
		return (0);
	if (t0 < 0)
		t0 = t1;
	if (t0 < 0)
		return (0);
	*tNK = t0;
	return (1);
}

int	ft_planeintersect(t_vec3 *o, t_vec3 *d, double *tNK, uint32_t iK, t_vec2 *uv, t_planenode *plane_sent)
{
	return (0);
}

int	ft_cylintersect(t_vec3 *o, t_vec3 *d, double *tNK, uint32_t iK, t_vec2 *uv, t_cylnode *cyl_sent)
{
	return (0);
}

int	ft_coneintersect(t_vec3 *o, t_vec3 *d, double *tNK, uint32_t iK, t_vec2 *uv, t_conenode *cone_sent)
{
	return (0);
}