#ifndef HINTERSECT_H
# define HINTERSECT_H

# include "hVector.h"

int	ft_sphintersect(t_vec3 *o, t_vec3 *d, double tNK, uint32_t iK, t_vec2 *uv, t_sphnode *sph_sent);
int	ft_planeintersect(t_vec3 *o, t_vec3 *d, double tNK, uint32_t iK, t_vec2 *uv, t_planenode *plane_sent);
int	ft_cylintersect(t_vec3 *o, t_vec3 *d, double tNK, uint32_t iK, t_vec2 *uv, t_cylnode *cyl_sent);
int	ft_coneintersect(t_vec3 *o, t_vec3 *d, double tNK, uint32_t iK, t_vec2 *uv, t_conenode *cone_sent);

#endif