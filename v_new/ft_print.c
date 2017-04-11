#include "hPrint.h"

void	ft_print_cameras()
{
	t_camnode *cam_sent;

	cam_sent = cam_head;
	while (cam_sent != NULL)
	{
		printf("##Object name: [ %s ]\n", cam_sent->cam->name);
		printf("Position: { %.2f, %.2f, %.2f }\n", cam_sent->cam->origin.x,
		cam_sent->cam->origin.y, cam_sent->cam->origin.z);
		printf("Rotation: { %.2f, %.2f, %.2f }\n", cam_sent->cam->rotation.x,
		cam_sent->cam->rotation.y, cam_sent->cam->rotation.z);
		cam_sent = cam_sent->next;
	}
}

void	ft_print_spheres()
{
	t_sphnode *sph_sent;

	sph_sent = sph_head;
	while (sph_sent != NULL)
	{
		printf("\n\n##Object name: [ %s ]\n", sph_sent->sphere->name);
		printf("Position: { %.2f, %.2f, %.2f }\n", sph_sent->sphere->center.x,
		sph_sent->sphere->center.y, sph_sent->sphere->center.z);
		printf("Rotation: { %.2f, %.2f, %.2f }\n", sph_sent->sphere->rotation.x,
		sph_sent->sphere->rotation.y, sph_sent->sphere->rotation.z);
		printf("Radius: { %.2f }\n", sph_sent->sphere->radius);
		printf("Color: #%X\n", sph_sent->sphere->color);
		sph_sent = sph_sent->next;
	}
}

void	ft_print_planes()
{
	t_planenode *plane_sent;

	plane_sent = plane_head;
	while (plane_sent != NULL)
	{
		printf("\n\n##Object name: [ %s ]\n", plane_sent->plane->name);
		printf("Position: { %.2f, %.2f, %.2f }\n", plane_sent->plane->point.x,
		plane_sent->plane->point.y, plane_sent->plane->point.z);
		printf("Normal vector: { %.2f, %.2f, %.2f }\n", plane_sent->plane->normal_vec.x,
		plane_sent->plane->normal_vec.y, plane_sent->plane->normal_vec.z);
		printf("Rotation: { %.2f, %.2f, %.2f }\n", plane_sent->plane->rotation.x,
		plane_sent->plane->rotation.y, plane_sent->plane->rotation.z);
		printf("Color: #%X\n", plane_sent->plane->color);
		plane_sent = plane_sent->next;
	}
}

void	ft_print_cylinders()
{
	t_cylnode *cyl_sent;

	cyl_sent = cyl_head;
	while (cyl_sent != NULL)
	{
		printf("\n\n##Object name: [ %s ]\n", cyl_sent->cylinder->name);
		printf("Start Cap: { %.2f, %.2f, %.2f }\n", cyl_sent->cylinder->start_cap.x,
		cyl_sent->cylinder->start_cap.y, cyl_sent->cylinder->start_cap.z);
		printf("End Cap: { %.2f, %.2f, %.2f }\n", cyl_sent->cylinder->end_cap.x,
		cyl_sent->cylinder->end_cap.y, cyl_sent->cylinder->end_cap.z);
		printf("Radius: { %.2f }\n", cyl_sent->cylinder->radius);
		printf("Color: #%X\n", cyl_sent->cylinder->color);
		cyl_sent = cyl_sent->next;
	}
}

void	ft_print_cones()
{
	t_conenode *cone_sent;

	cone_sent = cone_head;
	while (cone_sent != NULL)
	{
		printf("\n\n##Object name: [ %s ]\n", cone_sent->cone->name);
		printf("Start Cap: { %.2f, %.2f, %.2f }\n", cone_sent->cone->start_cap.x,
		cone_sent->cone->start_cap.y, cone_sent->cone->start_cap.z);
		printf("End Cap: { %.2f, %.2f, %.2f }\n", cone_sent->cone->end_cap.x,
		cone_sent->cone->end_cap.y, cone_sent->cone->end_cap.z);
		printf("Start Radius: { %.2f }\n", cone_sent->cone->sc_radius);
		printf("End Radius: { %.2f }\n", cone_sent->cone->ec_radius);
		printf("Color: #%X\n", cone_sent->cone->color);
		cone_sent = cone_sent->next;
	}
}

void	ft_print_lights()
{
	t_lightnode *light_sent;

	light_sent = light_head;
	while (light_sent != NULL)
	{
		printf("\n\n##Object name: [ %s ]\n", light_sent->light->name);
		printf("Position: { %.2f, %.2f, %.2f }\n", light_sent->light->center.x,
		light_sent->light->center.y, light_sent->light->center.z);
		printf("Rotation: { %.2f, %.2f, %.2f }\n", light_sent->light->rotation.x,
		light_sent->light->rotation.y, light_sent->light->rotation.z);
		printf("Radius: { %.2f }\n", light_sent->light->radius);
		printf("Color: #%X\n", light_sent->light->color);
		light_sent = light_sent->next;
	}
}

void	ft_print_numbers()
{
	printf("\nNumber of cameras: %d\n", cam_nr);
	printf("Number of lights: %d\n", light_nr);
	printf("Number of planes: %d\n", plane_nr);
	printf("Number of spheres: %d\n", sphere_nr);
	printf("Number of cylinders: %d\n", cyl_nr);
	printf("Number of cones: %d\n", cone_nr);
}

void	ft_print_structs()
{
	ft_print_cameras();
	ft_print_lights();
	ft_print_planes();
	ft_print_spheres();
	ft_print_cylinders();
	ft_print_cones();
	ft_print_numbers();
}