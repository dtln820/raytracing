#include "hExtract_info.h"

static t_conenode	*cone_sent;

void	ft_fillconeprop(int *enters, t_cone *cone, char *str)
{
	if (*enters == 2)
	{
		cone->name = (char*)malloc(sizeof(char) * strlen(str));
		strcpy(cone->name, str);
	}
	else if (*enters == 3)
		cone->start_cap.x = strtod(str, NULL);
	else if (*enters == 4)
		cone->start_cap.y = strtod(str, NULL);
	else if (*enters == 5)
		cone->start_cap.z = strtod(str, NULL);
	else if (*enters == 6)
		cone->end_cap.x = strtod(str, NULL);
	else if (*enters == 7)
		cone->end_cap.y = strtod(str, NULL);
	else if (*enters == 8)
		cone->end_cap.z = strtod(str, NULL);
	else if (*enters == 9)
		cone->sc_radius = strtod(str, NULL);
	else if (*enters == 10)
		cone->ec_radius = strtod(str, NULL);
	else if (*enters == 11)
	{
		cone->color = strtol(str, NULL, 16);
		*enters = 0;
	}
}

void	ft_conecreatefirst()
{
	cone_head = (t_conenode*)malloc(sizeof(t_conenode));
	cone_head->cone = (t_cone*)malloc(sizeof(t_cone));
	cone_head->next = NULL;
	cone_sent = cone_head;
	cone_nr++;
}

void	ft_conecreatenode()
{
	cone_sent = cone_head;
	while (cone_sent->next != NULL)
		cone_sent = cone_sent->next;
	cone_sent->next = (t_conenode*)malloc(sizeof(t_conenode));
	cone_sent->next->cone = (t_cone*)malloc(sizeof(t_cone));
	cone_sent->next->next = NULL;
	cone_sent = cone_sent->next;
	cone_nr++;
}

void	ft_fillcone(char *str)
{
	static int	enters;

	enters++;
	if (enters == 1 && cone_nr > 0)
		ft_conecreatenode();
	else if (enters > 1)
		ft_fillconeprop(&enters, cone_sent->cone, str);
	if (cone_nr == 0 && enters == 1)
		ft_conecreatefirst();
}