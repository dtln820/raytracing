#ifndef VECTOR_H
# define VECTOR_H

# include <string.h>
# include <stdlib.h>

typedef struct	s_vec3
{
	double	x;
	double	y;
	double	z;
}				t_vec3;

t_vec3			*vec3_create(double x, double y, double z);

double			vec3_dotpr(t_vec3 *a, t_vec3 *b);

t_vec3			*vec3_crosspr(t_vec3 *a, t_vec3 *b);

t_vec3			*vec3_constpr(t_vec3 *a, double var);

#endif