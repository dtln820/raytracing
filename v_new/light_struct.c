#include "extract_info.h"

static t_lightnode	*light_sent;

void	ft_filllightprop(int *enters, t_light *light, char *str)
{
	if (*enters == 2)
	{
		light->name = (char*)malloc(sizeof(char) * strlen(str));
		strcpy(light->name, str);
	}
	else if (*enters == 3)
		light->center.x = strtod(str, NULL);
	else if (*enters == 4)
		light->center.y = strtod(str, NULL);
	else if (*enters == 5)
		light->center.z = strtod(str, NULL);
	else if (*enters == 6)
		light->rotation.x = strtod(str, NULL);
	else if (*enters == 7)
		light->rotation.y = strtod(str, NULL);
	else if (*enters == 8)
		light->rotation.z = strtod(str, NULL);
	else if (*enters == 9)
		light->radius = strtod(str, NULL);
	else if (*enters == 10)
	{
		light->color = strtol(str, NULL, 16);
		*enters = 0;
	}
}

void	ft_lightcreatefirst()
{
	light_head = (t_lightnode*)malloc(sizeof(t_lightnode));
	light_head->light = (t_light*)malloc(sizeof(t_light));
	light_head->next = NULL;
	light_sent = light_head;
	light_nr++;
}

void	ft_lightcreatenode()
{
	light_sent = light_head;
	while (light_sent->next != NULL)
		light_sent = light_sent->next;
	light_sent->next = (t_lightnode*)malloc(sizeof(t_lightnode));
	light_sent->next->light = (t_light*)malloc(sizeof(t_light));
	light_sent->next->next = NULL;
	light_sent = light_sent->next;
	light_nr++;
}

void	ft_filllight(char *str)
{
	static int	enters;

	enters++;
	if (enters == 1 && light_nr > 0)
		ft_lightcreatenode();
	else if (enters > 1)
		ft_filllightprop(&enters, light_sent->light, str);
	if (light_nr == 0 && enters == 1)
		ft_lightcreatefirst();
}