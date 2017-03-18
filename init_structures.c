#include "rtv1.h"

t_vec		*ft_vecinit(double a, double b, double c)
{
	t_vec	*vector;
	
	vector = (t_vec*)malloc(sizeof(t_vec));
	vector->x = a;
	vector->y = b;
	vector->z = c;
	return (vector);
}

t_ray		*ft_rayinit()
{
	t_ray	*result;

	result = (t_ray*)malloc(sizeof(t_ray));
	result->origin = ft_vecinit(0, 0, 0);
	result->direction = ft_vecinit(0, 0, 0);
	return (result);
}

t_sphere	*ft_sphereinit(double a, double b, double c, double r)
{
	t_sphere	*result;

	result = (t_sphere*)malloc(sizeof(t_sphere));
	result->center = ft_vecinit(a, b, c);
	result->radius = r;
	return (result);
}