#include "restruct.h"

t_sphere	*ft_sphinit(t_vec *a, double r, t_vec *b, double re, double tr)
{
	t_sphere	*result;

	result = (t_sphere*)malloc(sizeof(t_sphere));
	result->center = ft_veccpy(a);
	result->radius = r;
	result->mcolor = ft_veccpy(b);
	result->reflect = re;
	result->transp = tr;
	result->lcolor = ft_vecinit(0, 0, 0);
	return (result);
}

t_sphere	*ft_lightinit(t_vec *a, double r, t_vec *c)
{
	t_sphere	*result;

	result = (t_sphere*)malloc(sizeof(t_sphere));
	result->center = ft_veccpy(a);
	result->radius = r;
	result->mcolor = ft_vecinit(0, 0, 0);
	result->reflect = 0;
	result->transp = 0;
	result->lcolor = ft_veccpy(c);
	return (result);
}

int			ft_sphintersect(t_vec *rayor, t_vec *raydr, double *t0, double *t1, t_sphere *sphere)
{
	t_vec	*line;
	double	tca;
	double	d2;
	double	thc;

	line = (t_vec*)malloc(sizeof(t_vec));
	tca = ft_dot(line, raydr);
	if (tca < 0)
		return (0);
	d2 = ft_dot(line, line) - tca * tca;
	if (d2 > sphere->radius * sphere->radius)
		return (0);
	thc = sqrt(sphere->radius * sphere->radius - d2);
	*t0 = tca - thc;
	*t1 = tca + thc;
	return (1);	
}