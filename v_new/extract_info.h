#ifndef EXTRACT_INFO_H
# define EXTRACT_INFO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line.h"

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef struct			s_plane
{
	char				*name;
	double				point_x;
	double				point_y;
	double				point_z;
	struct s_vector		*normal_vec;
	double				r_x;
	double				r_y;
	double				r_z;
}						t_plane;

typedef struct			s_camera
{
	char				*name;
	double				p_x;
	double				p_y;
	double				p_z;
	double				r_x;
	double				r_y;
	double				r_z;
}						t_camera;

typedef struct			s_sphere
{
	char				*name;
	double				p_x;
	double				p_y;
	double				p_z;
	double				r_x;
	double				r_y;
	double				r_z;
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

#endif