#include "extract_info.h"

static t_camnode	*cam_sent;

void	ft_fillcamprop(int *enters, t_camera *cam, char *str)
{
	if (*enters == 2)
	{
		cam->name = (char*)malloc(sizeof(char) * strlen(str));
		strcpy(cam->name, str);
	}
	else if (*enters == 3)
		cam->origin.x = strtod(str, NULL);
	else if (*enters == 4)
		cam->origin.y = strtod(str, NULL);
	else if (*enters == 5)
		cam->origin.z = strtod(str, NULL);
	else if (*enters == 6)
		cam->rotation.x = strtod(str, NULL);
	else if (*enters == 7)
		cam->rotation.y = strtod(str, NULL);
	else if (*enters == 8)
	{
		cam->rotation.z = strtod(str, NULL);
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
		ft_camcreatefirst();
}