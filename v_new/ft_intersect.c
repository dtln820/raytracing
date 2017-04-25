#include "hIntersect.h"
#include "hOther.h"

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
	double	denom;
	t_vec3	*p0l0;
	double	t;

	denom = ft_dotproduct(plane_sent->normal_vec, d);
	if (denom > 1e-6)
	{
		p0l0 = ft_v3diff(plane_sent->point, o);
		t = ft_dotproduct(p0l0, plane_sent->normal_vec) / denom;
		if (t >= 0)
		{
			*tNK = t;
			return (1);
		}
	}
	return (0);
}

int	ft_cylintersect(t_vec3 *o, t_vec3 *d, double *tNK, uint32_t iK, t_vec2 *uv, t_cylnode *cyl_sent)
{
	// do the infinite for now
	double	a;
	double	b;
	double	c;
	double	t0;
	double	t1;

	a = d->x * d->x + d->z * d->z;
	b = 2 * o->x * o->x + 2 * o->z * o->z;
	c = o->x * o->x + o->z * o->z - (cyl_sent->radius * cyl_sent->radius);
	if (ft_eqsolve(a, b, c, &t0, &t1) == 0)
		return (0);
	if (t0 < 0)
		t0 = t1;
	if (t0 < 0)
		return (0);
	*tNK = t0;
	return (1);
}

int	ft_coneintersect(t_vec3 *o, t_vec3 *d, double *tNK, uint32_t iK, t_vec2 *uv, t_conenode *cone_sent)
{
	// do the infinite for now
	double	a;
	double	b;
	double	c;
	double	t0;
	double	t1;

	a = d->x * d->x + d->z * d->z - d->y * d->y;
	b = 2 * o->x * d->x + 2 * o->z * d->z - 2 * o->y * d->y;
	c = o->x * o->x + o->z * o->z - o->y * o->y;
	if (ft_eqsolve(a, b, c, &t0, &t1) == 0)
		return (0);
	if (t0 < 0)
		t0 = t1;
	if (t0 < 0)
		return (0);
	*tNK = t0;
	return (1);
}