#ifndef EXTRACT_INFO_H
# define EXTRACT_INFO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "get_next_line.h"

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

typedef struct			s_camnode
{
	struct s_camera		*cam;
	struct s_camnode	*next;
}						t_camnode;

#endif