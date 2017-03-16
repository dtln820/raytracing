#include "rt.h"

t_vec		*vec_init(double a, double b, double c)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = a;
	result->y = b;
	result->z = c;

	return (result);
}

t_ray		*ray_init(t_vec *orig, t_vec *dir)
{
	t_ray	*result;

	result = (t_ray*)malloc(sizeof(t_ray));
	result->orig->x = orig->x;
	result->orig->y = orig->y;
	result->orig->z = orig->z;
	result->dir->x = dir->x;
	result->dir->y = dir->y;
	result->dir->z = dir->z;

	return (result);
}

t_sphere		*sphere_init(t_vec *center, double radius)
{
	t_sphere	*result;

	result = (t_sphere*)malloc(sizeof(t_sphere));
	result->center->x = center->x;
	result->center->y = center->y;
	result->center->z = center->z;
	result->radius = radius;

	return (result);
}