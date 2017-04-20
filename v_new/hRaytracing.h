#ifndef RAY_TRACING_H
# define RAY_TRACING_H

# include <float.h>
# include <stdlib.h>
# include <stdint.h>
# include "hVector.h"
# include "hIntersect.h"

void    ft_render();
int     ft_sumobjects();
void    ft_trace();
int		ft_castray();

#endif