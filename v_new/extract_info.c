#include "extract_info.h"

int					cam_nr;
int					sphere_nr;
int					light_nr;
t_camnode			*cam_head;
t_sphnode			*sph_head;

void	ft_fillplaneprop(int *enters, t_plane *plane, char *str)
{
	if (*enters == 2)
	{
		plane->name = (char*)malloc(sizeof(char) * strlen(str));
		strcpy(plane->name, str);
	} 
}

void	ft_fillstructs(char *str)
{
	static int		objtofill[3];
	/*
	0 - Camera
	1 - Sphere
	2 - Plane
	3 - Cylinder
	4 - Cone
	5 - Light
	*/

	if (strcmp(str, "Camera") == 0 || objtofill[0] == 1)
	{
		objtofill[0] = 1;
		if (strcmp(str, "#END") == 0)
		{
			objtofill[0] = 0;
			return ;
		}
		ft_fillcamera(str);
	}
	else if (strcmp(str, "Sphere") == 0 || objtofill[1] == 1)
	{
		objtofill[1] = 1;
		if (strcmp(str, "#END") == 0)
		{
			objtofill[1] = 0;
			return ;
		}
		ft_fillsphere(str);
	}
	// else if (strcmp(str, "Light") == 0 || objtofill[2] == 1)
	// {
	// 	objtofill[2] = 1;
	// 	if (strcmp(str, "#END") == 0)
	// 	{
	// 		objtofill[2] = 1;
	// 		return ;
	// 	}
	// 	ft_filllight(str);
	// }
}

int		ft_extract(int fd, char *path)
{
	char	*buffer;

	while (get_next_line(fd, &buffer) > 0)
	{
		ft_fillstructs(buffer);
		free(buffer);
	}
	return (0);
}

int		main(int argc, char *argv[])
{
	int		fd;

	if (argc < 2)
	{
		printf("Give a file to extract!\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	cam_head = NULL;
	ft_extract(fd, argv[1]);
	t_camnode *cam_sent = cam_head;
	printf("Object name: %s\n", cam_sent->cam->name);
	printf("\nPosition X: %f\n", cam_sent->cam->p_x);
	printf("Position X: %f\n", cam_sent->cam->p_y);
	printf("Position X: %f\n", cam_sent->cam->p_z);
	printf("\nRotation X: %f\n", cam_sent->cam->r_x);
	printf("Rotation Y: %f\n", cam_sent->cam->r_y);
	printf("Rotation Z: %f\n", cam_sent->cam->r_z);

	t_sphnode *sph_sent = sph_head;
	printf("\nObject name: %s\n", sph_sent->sphere->name);
	printf("\nPosition X: %f\n", sph_sent->sphere->p_x);
	printf("Position X: %f\n", sph_sent->sphere->p_y);
	printf("Position X: %f\n", sph_sent->sphere->p_z);
	printf("\nRotation X: %f\n", sph_sent->sphere->r_x);
	printf("Rotation Y: %f\n", sph_sent->sphere->r_y);
	printf("Rotation Z: %f\n", sph_sent->sphere->r_z);
	printf("\nRadius: %f\n", sph_sent->sphere->radius);
	return (0);
}