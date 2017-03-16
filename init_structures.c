#include "rtv1.h"

void	ft_vecinit(double a, double b, double c, t_vec *vector)
{
	vector->x = a;
	vector->y = b;
	vector->z = c;
}

void	ft_rayinit(t_vec *orig, t_vec *dir, t_ray *ray)
{
	ray->origin = orig;
	ray->direction = dir;
}

void	ft_sphereinit(t_vec *center, double radius, t_sphere *sphere)
{
	sphere->center = center;
	sphere->radius = radius;
}