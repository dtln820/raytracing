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
	t_vec		*vectmp3;
	double		bias;
	_Bool		inside;
	double		fratio;
	double		fresnel;
	t_vec		*refldr;
	t_vec		*reflect;
	t_vec		*refract;
	t_vec		*refrdr;

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
		ft_vecset(-1 * nhit->x, -1 * nhit->y, -1 * nhit->z, nhit);
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
		reflect = ft_trace(vectmp2, refldr, sphere, depth + 1);
		free(vectmp);
		free(vectmp2);
		ft_vecset(0, 0, 0, refract);
		if (sphere->transp > 0)
		{
			double ior = 1.1;
			double eta = (inside) ? ior : 1 / ior;
			vectmp = ft_vecinit(nhit->x * -1, nhit->y * -1, nhit->z * -1);
			double cosi = ft_vecdot(vectmp, raydr);
			free(vectmp);
			double k = 1 - eta * eta * (1 - cosi * cosi);
			vectmp = ft_vecmbn(raydr, eta);
			vectmp2 = ft_vecmbn(nhit, eta * cosi - sqrt(k));
			refrdr = ft_vecsum(vectmp, vectmp2);
			free(vectmp);
			free(vectmp2);
			ft_vecnorm(refrdr);
			vectmp = ft_vecmbn(nhit, bias);
			vectmp2 = ft_vecdiff(phit, nhit);
			refract = ft_trace(vectmp2, refrdr, sphere, depth + 1);
			free(vectmp);
			free(vectmp2);
		}
		vectmp = ft_vecmbn(reflect, fresnel);
		vectmp2 = ft_vecmbn(refract, (1 - fresnel) * sphere->transp);
		vectmp3 = ft_vecsum(vectmp, vectmp2);
		srfcolor = ft_vecmbv(vectmp3, sphere->mcolor);
		free(vectmp);
		free(vectmp2);
		free(vectmp3);
	}
	else
	{
		if (sphere->lcolor->x > 0)
		{
			t_vec *transmission = ft_vecinit(1, 1, 1);
			t_vec *lightDirection = ft_vecdiff(sphere->center, phit);
			ft_vecnorm(lightDirection);
			
		}
	}
}
