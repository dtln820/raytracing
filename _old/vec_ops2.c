#include "rtv1.h"

void	ft_sphnormal(t_vec *poi, t_sphere *sphere, t_vec *result)
{
	t_vec	*temp1;

	temp1 = (t_vec*)malloc(sizeof(t_vec));
	ft_vecdiff(sphere->center, poi, temp1);
	ft_vecdivbn(temp1, sphere->radius, result);
	free(temp1);
}

void	ft_vecdivbn(t_vec *a, double b, t_vec *result)
{
	result->x = a->x / b;
	result->y = a->y / b;
	result->z = a->z / b;
}

void	ft_vecnormalize(t_vec *a, t_vec *result)
{
	double	mg;

	mg = sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
	result->x = a->x / mg;
	result->y = a->y / mg;
	result->z = a->z / mg;
}