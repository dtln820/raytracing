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

void	ft_vecset(double a, double b, double c, t_vec *vector)
{
	vector->x = a;
	vector->y = b;
	vector->z = c;
}

void	ft_vecmbn(t_vec *vector, double a, t_vec *result)
{
	result->x = vector->x * a;
	result->y = vector->y * a;
	result->z = vector->z * a;
}

void	ft_vecsum(t_vec *a, t_vec *b, t_vec *result)
{
	result->x = a->x + b->x;
	result->y = a->y + b->y;
	result->z = a->z + b->z;
}