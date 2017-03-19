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

