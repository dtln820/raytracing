#ifndef VECTOR_H
# define VECTOR_H

# include <string.h>

typedef struct	s_vector
{
	double	*data;
	size_t	limit;
	size_t	size;
}				t_vector;



#endif