#include "rtv1.h"

void	ft_vecdiff(t_vec *a, t_vec *b, t_vec *result)
{
	result->x = a->x - b->x;
	result->y = a->y - b->y;
	result->z = a->z - b->z;
}

double	ft_vecdot(t_vec *a, t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}