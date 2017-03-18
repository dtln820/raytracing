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

t_vec			*ft_vecinit(double a, double b, double c);
t_ray			*ft_rayinit();
t_sphere		*ft_sphereinit(double a, double b, double c, double r);
void			ft_vecdiff(t_vec *a, t_vec *b, t_vec *result);
double			ft_vecdot(t_vec *a, t_vec *b);
void			ft_vecset(double a, double b, double c, t_vec *vector);

#endif