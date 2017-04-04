#include "extract_info.h"

int					sphere_nr;
t_sphnode			*sph_head;
static t_sphnode	*sph_sent;

void	ft_fillsphprop(int *enters, t_sphere *sphere, char *str)
{
	if (*enters == 2)
	{
		sphere->name = (char*)malloc(sizeof(char) * strlen(str));
		strcpy(sphere->name, str);
	}
	else if (*enters == 3)
		sphere->p_x = strtod(str, NULL);
	else if (*enters == 4)
		sphere->p_y = strtod(str, NULL);
	else if (*enters == 5)
		sphere->p_z = strtod(str, NULL);
	else if (*enters == 6)
		sphere->r_x = strtod(str, NULL);
	else if (*enters == 7)
		sphere->r_y = strtod(str, NULL);
	else if (*enters == 8)
		sphere->r_z = strtod(str, NULL);
	else if (*enters == 9)
	{
		sphere->radius = strtod(str, NULL);
		*enters = 0;
	}
}

void	ft_sphcreatefirst()
{
	sph_head = (t_sphnode*)malloc(sizeof(t_sphnode));
	sph_head->sphere = (t_sphere*)malloc(sizeof(t_sphere));
	sph_head->next = NULL;
	sph_sent = sph_head;
	sphere_nr++;
}

void	ft_sphcreatenode()
{
	sph_sent = sph_head;
	while (sph_sent->next != NULL)
		sph_sent = sph_sent->next;
	sph_sent->next = (t_sphnode*)malloc(sizeof(t_sphnode));
	sph_sent->next->sphere = (t_sphere*)malloc(sizeof(t_sphere));
	sph_sent->next->next = NULL;
	sph_sent = sph_sent->next;
	sphere_nr++;
}

void	ft_fillsphere(char *str)
{
	static int	enters;

	enters++;
	if (enters == 1 && sphere_nr > 0)
		ft_sphcreatenode();
	else if (enters > 1)
		ft_fillsphprop(&enters, sph_sent->sphere, str);
	if (sphere_nr == 0 && enters == 1)
		ft_sphcreatefirst();
}