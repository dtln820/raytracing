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

typedef struct			s_light
{
	char				*name;
	char				*type;
	t_point				center;
	t_point				rotation;
	double				radius;
	int					color;
}						t_light;

typedef struct			s_cone
{
	char				*name;
	char				*type;
	t_point				start_cap;
	t_point				end_cap;
	double				sc_radius;
	double				ec_radius;
	int					color;
}						t_cone;

typedef struct			s_cylinder
{
	char				*name;
	char				*type;
	t_point				start_cap;
	t_point				end_cap;
	double				radius;
	int					color;
}						t_cylinder;

typedef struct			s_plane
{
	char				*name;
	char				*type;
	t_point				point;
	t_vector			normal_vec;
	t_point				rotation;
	int					color;
}						t_plane;

typedef struct			s_sphere
{
	char				*name;
	char				*type;
	t_point				center;
	t_point				rotation;
	double				radius;
	int					color;
}						t_sphere;

typedef struct			s_camera
{
	char				*name;
	t_point				origin;
	t_point				rotation;
}						t_camera;

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

typedef struct			s_conenode
{
	struct s_cone		*cone;
	struct s_conenode	*next;
}						t_conenode;

typedef struct			s_lightnode
{
	struct s_light		*light;
	struct s_lightnode	*next;
}						t_lightnode;

typedef struct			s_object
{
	void				*obj;
	struct s_object		*next;
}

int						cam_nr;
int						sphere_nr;
int						light_nr;
int						plane_nr;
int						cyl_nr;
int						cone_nr;
t_camnode				*cam_head;
t_sphnode				*sph_head;
t_planenode				*plane_head;
t_cylnode				*cyl_head;
t_conenode				*cone_head;
t_lightnode				*light_head;

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
void	ft_fillconeprop(int *enters, t_cone *cone, char *str);
void	ft_conecreatefirst();
void	ft_conecreatenode();
void	ft_fillcone(char *str);
void	ft_filllightprop(int *enters, t_light *light, char *str);
void	ft_lightcreatefirst();
void	ft_lightcreatenode();
void	ft_filllight(char *str);
int		ft_checkextract(int argc, char *argv[]);

#endif