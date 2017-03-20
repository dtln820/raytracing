#include "restruct.h"

t_vec	*ft_vecinit(double a, double b, double c)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = a;
	result->y = b;
	result->z = c;
	return (result);
}

void	ft_vecset(double a, double b, double c, t_vec *vec)
{
	vec->x = a;
	vec->y = b;
	vec->z = c;
}

void	ft_vecnorm(t_vec *vec)
{
	double	var;
	double	inv;

	var = ft_vecsqlng(vec);
	if (var > 0)
	{
		inv = 1 / sqrt(var);
		vec->x *= inv;
		vec->y *= inv;
		vec->z *= inv;
	}
}

double	ft_vecsqlng(t_vec *vec)
{
	double	temp1;
	double	temp2;
	double	temp3;

	temp1 = vec->x * vec->x;
	temp2 = vec->y * vec->y;
	temp3 = vec->z * vec->z;
	return (temp1 + temp2 + temp3);
}

double	ft_veclng(t_vec *vec)
{
	return (sqrt(ft_vecsqlng(vec)));
}

t_vec	*ft_vecmbn(t_vec *vec, double n) // multiply by number
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(result));
	result->x = vec->x * n;
	result->y = vec->y * n;
	result->z = vec->z * n;
	return (result);
}

t_vec	*ft_vecmbv(t_vec *vec, t_vec *ovec) // multiply by vector
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(result));
	result->x = vec->x * ovec->x;
	result->y = vec->y * ovec->y;
	result->z = vec->z * ovec->z;
	return (result);
}

double	ft_vecdot(t_vec *a, t_vec *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vec	*ft_vecdiff(t_vec *a, t_vec *b)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = a->x - b->x;
	result->y = a->y - b->y;
	result->z = a->z - b->z;
	return (result);
}

t_vec	*ft_vecsum(t_vec *a, t_vec *b)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = a->x + b->x;
	result->y = a->y + b->y;
	result->z = a->z + b->z;
	return (result);
}

void	ft_vecsumto(t_vec *a, t_vec *vec)
{
	vec->x += a->x;
	vec->y += a->y;
	vec->z += a->z;
}

void	ft_vecmbvto(t_vec *a, t_vec *vec)
{
	vec->x *= a->x;
	vec->y *= a->y;
	vec->z *= a->z;
}

t_vec	*ft_vecopus(t_vec *a)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = -1 * a->x;
	result->y = -1 * a->y;
	result->z = -1 * a->z;
	return (result);
}

t_vec	*ft_veccpy(t_vec *a)
{
	t_vec	*result;

	result = (t_vec*)malloc(sizeof(t_vec));
	result->x = a->x;
	result->y = a->y;
	result->z = a->z;
	return (result);
}