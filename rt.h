#ifndef RT_H
# define RT_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

typedef struct	s_wnd
{
	int			width;
	int			height;
	void		*mlx;
	void		*win;
}				t_wnd;

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_ray
{
	t_vec		*orig; // origin
	t_vec		*dir; // direction
}				t_ray;

typedef struct	s_sphere
{
	t_vec		*center; // center
	double		radius; // radius 
}				t_sphere;

void			init_window(t_wnd *ws);

void			render(t_wnd *ws);

t_vec			*vec_init(double a, double b, double c);

t_ray			*ray_init(t_vec *orig, t_vec *dir);

t_sphere		*sphere_init(t_vec *center, double radius);

int				sph_intersect(t_ray *ray, double *t, t_sphere *sphere);

t_vec			vec_diff(t_vec a, t_vec *b);

double			vec_dot(t_vec a, t_vec b);

#endif