#include "vector.h"
#include <stdio.h>

t_vector	*v_create(double array[], size_t size)
{
	t_vector *result;

	result = (t_vector*)malloc(sizeof(t_vector));
	result->size = size;
	result->data = (double*)malloc(sizeof(double) * size);
	while (size > 0)
	{
		result->data[result->size - size] = array[result->size - size];
		size--;
	}
	return (result);
}

int		main()
{
	t_vector *test;

	double v[4] = {7, 5, 16, 8};
	test = v_create(v, 4);
	for (int i = 0; i < test->size; i++)
	{
		printf("test[%d] = %f\n", i, test->data[i]);
	}
	return (0);
}