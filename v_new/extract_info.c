#include "extract_info.h"

int			cam_nr;
int			sphere_nr;
int			light_nr;
t_camnode	*cam_head;
t_camnode	*cam_sent;

void	ft_fillcamprop(int *enters, t_camera *cam, char *str)
{
	if (*enters == 2)
	{
		cam->name = (char*)malloc(sizeof(char) * strlen(str));
		strcpy(cam->name, str);
	}
	else if (*enters == 3)
		cam->p_x = strtod(str, NULL);
	else if (*enters == 4)
		cam->p_y = strtod(str, NULL);
	else if (*enters == 5)
		cam->p_z = strtod(str, NULL);
	else if (*enters == 6)
		cam->r_x = strtod(str, NULL);
	else if (*enters == 7)
		cam->r_y = strtod(str, NULL);
	else if (*enters == 8)
	{
		cam->r_z = strtod(str, NULL);
		*enters = 0;
	}
}

void	ft_camcreatefirst()
{
	cam_head = (t_camnode*)malloc(sizeof(t_camnode));
	cam_head->cam = (t_camera*)malloc(sizeof(t_camera));
	cam_head->next = NULL;
	cam_sent = cam_head;
	cam_nr++;
}

void	ft_camcreatenode()
{
	cam_sent = cam_head;
	while (cam_sent->next != NULL)
		cam_sent = cam_sent->next;
	cam_sent->next = (t_camnode*)malloc(sizeof(t_camnode));
	cam_sent->next->cam = (t_camera*)malloc(sizeof(t_camera));
	cam_sent->next->next = NULL;
	cam_sent = cam_sent->next;
	cam_nr++;
}

void	ft_fillcamera(char *str)
{
	static int	enters;

	enters++;
	if (enters == 1 && cam_nr > 0)
		ft_camcreatenode();
	else if (enters > 1)
		ft_fillcamprop(&enters, cam_sent->cam, str);
	if (cam_nr == 0 && enters == 1)
	{
		ft_camcreatefirst();
		cam_nr++;
	}
}

void	ft_fillstructs(char *str)
{
	static int		objtofill[3];
	/*
	0 - Camera
	1 - Sphere
	2 - Light
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
	// else if (strcmp(str, "Sphere") == 0 || objtofill[1] == 1)
	// {
	// 	objtofill[1] = 1;
	// 	if (strcmp(str, "#END") == 0)
	// 	{
	// 		objtofill[1] = 0;
	// 		return ;
	// 	}
	// 	ft_fillsphere(str);
	// }
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
	printf("Object name: %s\n", cam_sent->cam->name);
	printf("\nPosition X: %f\n", cam_sent->cam->p_x);
	printf("Position X: %f\n", cam_sent->cam->p_y);
	printf("Position X: %f\n", cam_sent->cam->p_z);
	printf("\nRotation X: %f\n", cam_sent->cam->r_x);
	printf("Rotation Y: %f\n", cam_sent->cam->r_y);
	printf("Rotation Z: %f\n", cam_sent->cam->r_z);
	return (0);
}