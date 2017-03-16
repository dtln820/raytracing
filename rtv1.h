#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_wnd
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
}				t_wnd;

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_ray
{
	t_vec		*origin;
	t_vec		*direction;
}				t_ray;

typedef struct	s_sphere
{
	t_vec		*center;
	double		radius;
}				t_sphere;

void			ft_vecinit(double a, double b, double c, t_vec *vector);
void			ft_rayinit(t_vec *orig, t_vec *dir, t_ray *ray);
void			ft_sphereinit(t_vec *center, double radius, t_sphere *sphere);
void			ft_vecdiff(t_vec *a, t_vec *b, t_vec *result);
double			ft_vecdot(t_vec *a, t_vec *b);

#endif