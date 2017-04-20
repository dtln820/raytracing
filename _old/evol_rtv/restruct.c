#include "restruct.h"

t_vec	*ft_trace(t_vec *rayor, t_vec *raydr, t_sphere *sphere, int depth)
{
	double		tnear;
	t_sphere	*tmp_sph;
	double		t0;
	double		t1;
	t_vec		*srfcolor;
	t_vec		*phit;
	t_vec		*nhit;
	t_vec		*vectmp;
	t_vec		*vectmp2;
	double		bias;
	_Bool		inside;
	double		fratio;
	double		fresnel;
	t_vec		*refldr;
	t_vec		*reflect;
	t_vec		*refract;

	tmp_sph = NULL;
	tnear = 1e8;
	t0 = 1e8;
	t1 = 1e8;
	if (ft_sphintersect(rayor, raydr, &t0, &t1, sphere))
	{
		if (t0 < 0)
			t0 = t1;
		if (t0 < tnear)
		{
			tnear = t0;
			tmp_sph = sphere;
		}
	}
	if (!tmp_sph)
		return (ft_vecinit(2, 2, 2));
	srfcolor = ft_vecinit(0, 0, 0);
	vectmp = ft_vecmbn(raydr, tnear);
	phit = ft_vecsum(rayor, vectmp);
	free(vectmp);
	nhit = ft_vecdiff(phit, tmp_sph->center);
	ft_vecnorm(nhit);
	bias = 1e-4;
	inside = 0;
	if (ft_vecdot(raydr, nhit) > 0)
	{
		nhit = -nhit;
		inside = 1;
	}
	if ((tmp_sph->transp > 0 || sphere->reflect > 0) && depth < RAYDEPTH)
	{
		fratio = -1 * ft_vecdot(raydr, nhit);
		fresnel = ft_mix(pow(1 - fratio, 3), 1, 0.1);
		vectmp = ft_vecmbn(nhit, 2 * ft_vecdot(raydr, nhit));
		refldr = ft_vecdiff(raydr, vectmp);
		free(vectmp);
		ft_vecnorm(refldr);
		vectmp = ft_vecmbn(nhit, bias);
		vectmp2 = ft_vecsum(phit, vectmp);
		reflect = ft_trace(vectmp2, refldr, )
	}
}
