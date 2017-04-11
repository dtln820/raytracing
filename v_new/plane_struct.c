#include "extract_info.h"

static t_planenode	*plane_sent;

void	ft_fillplaneprop(int *enters, t_plane *plane, char *str)
{
	if (*enters == 2)
	{
		plane->name = (char*)malloc(sizeof(char) * strlen(str));
		strcpy(plane->name, str);
	}
	else if (*enters == 3)
		plane->point.x = strtod(str, NULL);
	else if (*enters == 4)
		plane->point.y = strtod(str, NULL);
	else if (*enters == 5)
		plane->point.z = strtod(str, NULL);
	else if (*enters == 6)
		plane->normal_vec.x = strtod(str, NULL);
	else if (*enters == 7)
		plane->normal_vec.y = strtod(str, NULL);
	else if (*enters == 8)
		plane->normal_vec.z = strtod(str, NULL);
	else if (*enters == 9)
		plane->rotation.x = strtod(str, NULL);
	else if (*enters == 10)
		plane->rotation.y = strtod(str, NULL);
	else if (*enters == 11)
		plane->rotation.z = strtod(str, NULL);
	else if (*enters == 12)
	{
		plane->color = strtol(str, NULL, 16);
		*enters = 0;
	}
}

void	ft_planecreatefirst()
{
	plane_head = (t_planenode*)malloc(sizeof(t_planenode));
	plane_head->plane = (t_plane*)malloc(sizeof(t_plane));
	plane_head->next = NULL;
	plane_sent = plane_head;
	plane_nr++;
}

void	ft_planecreatenode()
{
	plane_sent = plane_head;
	while (plane_sent->next != NULL)
		plane_sent = plane_sent->next;
	plane_sent->next = (t_planenode*)malloc(sizeof(t_planenode));
	plane_sent->next->plane = (t_plane*)malloc(sizeof(t_plane));
	plane_sent->next->next = NULL;
	plane_sent = plane_sent->next;
	plane_nr++;
}

void	ft_fillplane(char *str)
{
	static int	enters;

	enters++;
	if (enters == 1 && plane_nr > 0)
		ft_planecreatenode();
	else if (enters > 1)
		ft_fillplaneprop(&enters, plane_sent->plane, str);
	if (plane_nr == 0 && enters == 1)
		ft_planecreatefirst();
}