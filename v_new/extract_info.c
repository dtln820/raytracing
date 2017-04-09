#include "extract_info.h"

int					cam_nr;
int					sphere_nr;
int					light_nr;
int					plane_nr;
int					cyl_nr;
int					cone_nr;
t_camnode			*cam_head;
t_sphnode			*sph_head;
t_planenode			*plane_head;
t_cylnode			*cyl_head;
t_conenode			*cone_head;

void	ft_fillstructs(char *str)
{
	static int		objtofill[6];
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
	else if (strcmp(str, "Plane") == 0 || objtofill[2] == 1)
	{
		objtofill[2] = 1;
		if (strcmp(str, "#END") == 0)
		{
			objtofill[2] = 0;
			return ;
		}
		ft_fillplane(str);
	}
	else if (strcmp(str, "Cylinder") == 0 || objtofill[3] == 1)
	{
		objtofill[3] = 1;
		if (strcmp(str, "#END") == 0)
		{
			objtofill[3] = 0;
			return ;
		}
		ft_fillcylinder(str);
	}
	else if (strcmp(str, "Cone") == 0 || objtofill[4] == 1)
	{
		objtofill[4] = 1;
		if (strcmp(str, "#END") == 0)
		{
			objtofill[4] = 0;
			return ;
		}
		ft_fillcone(str);
	}
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
	printf("##Object name: [ %s ]\n", cam_sent->cam->name);
	printf("Position: { %.2f, %.2f, %.2f }\n", cam_sent->cam->origin.x,
	cam_sent->cam->origin.y, cam_sent->cam->origin.z);
	printf("Rotation: { %.2f, %.2f, %.2f }\n", cam_sent->cam->rotation.x,
	cam_sent->cam->rotation.y, cam_sent->cam->rotation.z);

	t_sphnode *sph_sent = sph_head;
	printf("\n\n##Object name: [ %s ]\n", sph_sent->sphere->name);
	printf("Position: { %.2f, %.2f, %.2f }\n", sph_sent->sphere->center.x,
	sph_sent->sphere->center.y, sph_sent->sphere->center.z);
	printf("Rotation: { %.2f, %.2f, %.2f }\n", sph_sent->sphere->rotation.x,
	sph_sent->sphere->rotation.y, sph_sent->sphere->rotation.z);
	printf("Radius: { %.2f }\n", sph_sent->sphere->radius);

	t_planenode *plane_sent = plane_head;
	printf("\n\n##Object name: [ %s ]\n", plane_sent->plane->name);
	printf("Position: { %.2f, %.2f, %.2f }\n", plane_sent->plane->point.x,
	plane_sent->plane->point.y, plane_sent->plane->point.z);
	printf("Normal vector: { %.2f, %.2f, %.2f }\n", plane_sent->plane->normal_vec.x,
	plane_sent->plane->normal_vec.y, plane_sent->plane->normal_vec.z);
	printf("Rotation: { %.2f, %.2f, %.2f }\n", plane_sent->plane->rotation.x,
	plane_sent->plane->rotation.y, plane_sent->plane->rotation.z);

	t_cylnode *cyl_sent = cyl_head;
	printf("\n\n##Object name: [ %s ]\n", cyl_sent->cylinder->name);
	printf("Start Cap: { %.2f, %.2f, %.2f }\n", cyl_sent->cylinder->start_cap.x,
	cyl_sent->cylinder->start_cap.y, cyl_sent->cylinder->start_cap.z);
	printf("End Cap: { %.2f, %.2f, %.2f }\n", cyl_sent->cylinder->end_cap.x,
	cyl_sent->cylinder->end_cap.y, cyl_sent->cylinder->end_cap.z);
	printf("Radius: { %.2f }\n", cyl_sent->cylinder->radius);

	t_conenode *cone_sent = cone_head;
	printf("\n\n##Object name: [ %s ]\n", cone_sent->cone->name);
	printf("Start Cap: { %.2f, %.2f, %.2f }\n", cone_sent->cone->start_cap.x,
	cone_sent->cone->start_cap.y, cone_sent->cone->start_cap.z);
	printf("End Cap: { %.2f, %.2f, %.2f }\n", cone_sent->cone->end_cap.x,
	cone_sent->cone->end_cap.y, cone_sent->cone->end_cap.z);
	printf("Start Radius: { %.2f }\n", cone_sent->cone->sc_radius);
	printf("End Radius: { %.2f }\n", cone_sent->cone->ec_radius);
	return (0);
}