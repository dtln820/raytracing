#include "vector.h"
#include <stdio.h>

t_vec3	*vec3_create(double x, double y, double z)
{
	t_vec3	*result;

	result = (t_vec3*)malloc(sizeof(t_vec3));
	result->x = x;
	result->y = y;
	result->z = z;
	return (result);
}

double	vec3_dotpr(t_vec3 *a, t_vec3 *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

t_vec3	*vec3_crosspr(t_vec3 *a, t_vec3 *b)
{
	t_vec3	*result;

	result = (t_vec3*)malloc(sizeof(t_vec3));
	result->x = a->y * b->z - a->z * b->y;
	result->y = a->z * b->x - a->x * b->z;
	result->z = a->x * b->y - a->y * b->x;
	return (result);
}

t_vec3	*vec3_constpr(t_vec3 *a, double var)
{
	t_vec3	*result;

	result = (t_vec3*)malloc(sizeof(t_vec3));
	result->x = a->x * var;
	result->y = a->y * var;
	result->z = a->z * var;
	return (result);
}

void	vec3_print(t_vec3 *vector)
{
	printf("Cross product result:\n");
	printf("x = %.10f\n", vector->x);
	printf("y = %.10f\n", vector->y);
	printf("z = %.10f\n", vector->z);
}

int		main()
{
	t_vec3 *test;
	t_vec3 *factor;

	factor = vec3_create(2.1, 3, 0);
	test = vec3_create(1.25, 2.97, 3.01);
	vec3_print(test);
	printf("dotpr = %.10f\n", vec3_dotpr(test, factor));
	vec3_print(vec3_crosspr(test, factor));
	return (0);
}