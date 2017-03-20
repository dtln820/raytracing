#ifndef RESTRUCT_H
# define RESTRUCT_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>

# define RAYDEPTH 5

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_sphere
{
	t_vec		*center;
	double		radius;
	t_vec		*mcolor; // material color (de suprafata)
	double		reflect;
	double		transp;
	t_vec		*lcolor; // light color (de emitere)
}				t_sphere;

t_vec			*ft_vecinit(double a, double b, double c);
void			ft_vecset(double a, double b, double c, t_vec *vec);
void			ft_vecnorm(t_vec *vec);
double			ft_vecsqlng(t_vec *vec);
double			ft_veclng(t_vec *vec);
t_vec			*ft_vecmbn(t_vec *vec, double n);
t_vec			*ft_vecmbv(t_vec *vec, t_vec *ovec);
double			ft_vecdot(t_vec *a, t_vec *b);
t_vec			*ft_vecdiff(t_vec *a, t_vec *b);
t_vec			*ft_vecsum(t_vec *a, t_vec *b);
void			ft_vecsumto(t_vec *a, t_vec *vec);
void			ft_vecmbvto(t_vec *a, t_vec *vec);
t_vec			*ft_vecopus(t_vec *a);
t_sphere		*ft_sphinit(t_vec *a, double r, t_vec *b, double re, double tr);
t_sphere		*ft_lightinit(t_vec *a, double r, t_vec *c);
int				ft_sphintersect(t_vec *rayor, t_vec *raydr, double *t0, double *t1, t_sphere *sphere);

#endif