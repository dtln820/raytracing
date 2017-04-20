#include "hVector.h"

t_vec3	*ft_vec3init(double a, double b, double c)
{
	t_vec3	*result;

	result = (t_vec3*)malloc(sizeof(t_vec3));
	result->x = a;
	result->y = b;
	result->z = c;
	return (result);
}

void	ft_vec3set(double a, double b, double c, t_vec3 *vec)
{
	vec->x = a;
	vec->y = b;
	vec->z = c;
}

t_vec3	*ft_v3numbermult(double value, t_vec3 *v)
{
	return (ft_vec3init(v->x * value, v->y * value, v->z * value));
}

t_vec3	*ft_v3vecmult(t_vec3 *a, t_vec3 *b)
{
	return (ft_vec3init(a->x * b->x, a->y * b->y, a->z * b->z));
}

t_vec3	*ft_v3diff(t_vec3 *a, t_vec3 *b)
{
	return (ft_vec3init(a->x - b->x, a->y - b->y, a->z - b->z));
}

t_vec3	*ft_v3sum(t_vec3 *a, t_vec3 *b)
{
	return (ft_vec3init(a->x + b->x, a->y + b->y, a->z + b->z));
}

void	ft_v3invers(t_vec3 *a)
{
	a->x = a->x * -1;
	a->y = a->y * -1;
	a->z = a->z * -1;
}

t_vec2	*ft_vec2init(double a, double b)
{
	t_vec2	*result;

	result = (t_vec2*)malloc(sizeof(t_vec2));
	result->x = a;
	result->y = b;
	return (result);
}

void	ft_vec2set(double a, double b, t_vec2 *vec)
{
	vec->x = a;
	vec->y = b;
}

t_vec2	*ft_v2numbermult(double value, t_vec2 *v)
{
	return (ft_vec2init(v->a * value, v->b * value));
}

t_vec2	*ft_v2sum(t_vec2 *a, t_vec2 *b)
{
	return (ft_vec2init(a->x + b->x, a->y + b->y));
}

void	ft_normalize(t_vec3 *v)
{
	double magsq;
	double invmag;

	magsq = v->x *v->x + v->y * v->y + v->z * v->z;
	if (magsq > 0)
	{
		invmag = 1 / sqrtf(magsq);
		ft_vec3set(v->x * invmag, v->y * invmag, v->z * invmag, v);
	}
}

double	ft_dotproduct(t_vec3 *a, t_vec3 *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vec3	*ft_v3crossprod(t_vec3 *a, t_vec3 *b)
{
	t_vec3	*result;

	result = (t_vec3*)malloc(sizeof(t_vec3));
	result->x = a->y * b->z - a->z * b->y;
	result->y = a->z * b->x - a->x * b->z;
	result->z = a->x * b->y - a->y * b->x;
	return (result);
}

double	ft_clamp(double lo, double hi, double v)
{
	double temp;

	if (hi > v)
		temp = v;
	else
		temp = hi;
	if (lo > temp)
		return (lo);
	else
		return (temp);
}

double	ft_deg2rad(double grade)
{
	return (grade * M_PI / 180);
}

t_vec3	*ft_v3mix(t_vec3 *a, t_vec3 *b, double value)
{
	t_vec3	*temp1;
	t_vec3	*temp2;
	t_vec3	*result;

	temp1 = ft_v3numbermult(value - 1, a);
	temp2 = ft_v3numbermult(value, b);
	result = ft_v3sum(temp1, temp2);
	free(temp1);
	free(temp2);
	return (result);
}