#ifndef EXTRACT_INFO_H
# define EXTRACT_INFO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line.h"

typedef	struct			s_point
{
	double				x;
	double				y;
	double				z;
}						t_point;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_cylinder
{
	char				*name;
	t_point				start_cap;
	t_vector			cyl_axis;
	double				radius;
	t_point				end_cap;
}						t_cylinder;

typedef struct			s_plane
{
	char				*name;
	t_point				point;
	t_vector			normal_vec;
	t_point				rotation;
}						t_plane;

typedef struct			s_camera
{
	char				*name;
	t_point				origin;
	t_point				rotation;
}						t_camera;

typedef struct			s_sphere
{
	char				*name;
	t_point				center;
	t_point				rotation;
	double				radius;
}						t_sphere;

typedef struct			s_camnode
{
	struct s_camera		*cam;
	struct s_camnode	*next;
}						t_camnode;

typedef struct			s_sphnode
{
	struct s_sphere		*sphere;
	struct s_sphnode	*next;
}						t_sphnode;

typedef struct			s_lightnode
{
	struct s_sphere		*light;
	struct s_lightnode	*next;
}						t_lightnode;

typedef struct			s_planenode
{
	struct s_plane		*plane;
	struct s_planenode	*next;
}						t_planenode;

typedef struct			s_cylnode
{
	struct s_cylinder	*cylinder;
	struct s_cylnode	*next;
}						t_cylnode;

int		ft_extract(int fd, char *path);
void	ft_fillstructs(char *str);
void	ft_fillcamprop(int *enters, t_camera *cam, char *str);
void	ft_camcreatefirst();
void	ft_camcreatenode();
void	ft_fillcamera(char *str);
void	ft_fillsphprop(int *enters, t_sphere *sphere, char *str);
void	ft_sphcreatefirst();
void	ft_sphcreatenode();
void	ft_fillsphere(char *str);
void	ft_fillplaneprop(int *enters, t_plane *plane, char *str);
void	ft_planecreatefirst();
void	ft_planecreatenode();
void	ft_fillplane(char *str);
void	ft_fillcylinderprop(int *enters, t_cylinder *cylinder, char *str);
void	ft_cylcreatefirst();
void	ft_cylcreatenode();
void	ft_fillcylinder(char *str);

#endif