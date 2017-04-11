#include "extract_info.h"

int                 cyl_nr;
t_cylnode			*cyl_head;
static t_cylnode	*cyl_sent;

void	ft_fillcylinderprop(int *enters, t_cylinder *cylinder, char *str)
{
	if (*enters == 2)
	{
		cylinder->name = (char*)malloc(sizeof(char) * strlen(str));
		strcpy(cylinder->name, str);
	}
	else if (*enters == 3)
		cylinder->start_cap.x = strtod(str, NULL);
	else if (*enters == 4)
		cylinder->start_cap.y = strtod(str, NULL);
	else if (*enters == 5)
		cylinder->start_cap.z = strtod(str, NULL);
	else if (*enters == 6)
		cylinder->radius = strtod(str, NULL);
	else if (*enters == 7)
		cylinder->end_cap.x = strtod(str, NULL);
	else if (*enters == 8)
		cylinder->end_cap.y = strtod(str, NULL);
	else if (*enters == 9)
		cylinder->end_cap.z = strtod(str, NULL);
	else if (*enters == 10)
	{
		cylinder->color = strtol(str, NULL, 16);
		*enters = 0;
	}
}

void	ft_cylcreatefirst()
{
	cyl_head = (t_cylnode*)malloc(sizeof(t_cylnode));
	cyl_head->cylinder = (t_cylinder*)malloc(sizeof(t_cylinder));
	cyl_head->next = NULL;
	cyl_sent = cyl_head;
	cyl_nr++;
}

void	ft_cylcreatenode()
{
	cyl_sent = cyl_head;
	while (cyl_sent->next != NULL)
		cyl_sent = cyl_sent->next;
	cyl_sent->next = (t_cylnode*)malloc(sizeof(t_cylnode));
	cyl_sent->next->cylinder = (t_cylinder*)malloc(sizeof(t_cylinder));
	cyl_sent->next->next = NULL;
	cyl_sent = cyl_sent->next;
	cyl_nr++;
}

void	ft_fillcylinder(char *str)
{
	static int	enters;

	enters++;
	if (enters == 1 && cyl_nr > 0)
		ft_cylcreatenode();
	else if (enters > 1)
		ft_fillcylinderprop(&enters, cyl_sent->cylinder, str);
	if (cyl_nr == 0 && enters == 1)
		ft_cylcreatefirst();
}