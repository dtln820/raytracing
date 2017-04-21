#ifndef HVECTOR_H
# define HVECTOR_H

# include <math.h>

t_vec3	*ft_vec3init(double a, double b, double c);
void	ft_vec3set(double a, double b, double c, t_vec3 *vec);
t_vec3	*ft_v3numbermult(double value, t_vec3 *v);
t_vec3	*ft_v3vecmult(t_vec3 *a, t_vec3* b);
t_vec3	*ft_v3diff(t_vec3 *a, t_vec3 *b);
t_vec3	*ft_v3sum(t_vec3 *a, t_vec3 *b);
void	ft_v3invers(t_vec3 *a);
t_vec2	*ft_vec2init(double a, double b);
void	ft_vec2set(double a, double b, t_vec2 *vec);
t_vec2	*ft_v2numbermult(double value, t_vec2 *v);
t_vec2	*ft_v2sum(t_vec2 *a, t_vec2 *b);
void	ft_normalize(t_vec3 *v);
double	ft_dotproduct(t_vec3 *a, t_vec3 *b);
t_vec3	*ft_v3crossprod(t_vec3 *a, t_vec3 *b);
double	ft_clamp(double lo, double hi, double v);
double	ft_deg2rad(double grade);
t_vec3	*ft_v3mix(t_vec3 *a, t_vec3 *b, double value);

#endif