#ifndef RAY_TRACING_H
# define RAY_TRACING_H

# include <float.h>
# include <stdlib.h>
# include <stdint.h>
# include "hVector.h"
# include "hIntersect.h"

void    ft_render();
int     ft_sumobjects();
_Bool   ft_trace(t_vec3 *o, t_vec3 *d, double a, uint32_t b, t_vec2 *z, void **h);
int		ft_castray();

#endif