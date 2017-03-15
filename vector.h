#ifndef VECTOR_H
# define VECTOR_H

# include <string.h>
# include <stdlib.h>

typedef struct	s_vector
{
	double	*data;
	size_t	size;
}				t_vector;

#endif