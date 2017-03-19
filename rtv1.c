#include "rtv1.h"

int		intersection(t_ray *ray, double *t, t_sphere *sphere)
{
	t_vec	*temp_o;
	t_vec	*temp_d;
	t_vec	*temp_oc;
	double var[5];

	temp_oc = (t_vec*)malloc(sizeof(t_vec));
	temp_o = ft_vecinit(ray->origin->x, ray->origin->y, ray->origin->z);
	temp_d = ft_vecinit(ray->direction->x, ray->direction->y, ray->direction->z);
	ft_vecdiff(temp_o, sphere->center, temp_oc);
	var[0] = 2 * ft_vecdot(temp_oc, temp_d);
	var[1] = ft_vecdot(temp_oc, temp_oc) - sphere->radius * sphere->radius;
	var[2] = var[0] * var[0] - 4 * var[1];
	free(temp_o);
	free(temp_d);
	free(temp_oc);
	if (var[2] < 0)
		return (0);
	else
	{
		var[2] = sqrt(var[2]);
		var[3] = -var[0] - var[2];
		var[4] = -var[0] + var[2];
		*t = (var[3] < var[4]) ? var[3] : var[4];
		return (1);
	}
}

void	ft_render(t_wnd *ws)
{
	double		t;
	int			y;
	int			x;
	t_ray		*ray;
	t_sphere	*sphere;
	t_sphere	*light;

	sphere = ft_sphereinit(ws->width / 2, ws->height / 2, 50, 50);
	light = ft_sphereinit(ws->width / 2, 0, 50, 1);
	ray = ft_rayinit();
	t = 20000;
	y = 0;
	while (y < ws->height)
	{
		x = 0;
		while (x < ws->width)
		{
			ft_vecset(x, y, 0, ray->origin);
			ft_vecset(0, 0, 1, ray->direction);
			if (intersection(ray, &t, sphere) == 1)
			{
				t_vec *temp = ft_vecinit(0, 0, 0);
				t_vec *temp1 = ft_vecinit(0, 0, 0);
				t_vec *temp2 = ft_vecinit(0, 0, 0);
				t_vec *poi = ft_vecinit(0, 0, 0);
				ft_vecmbn(ray->direction, t, temp);
				ft_vecsum(ray->origin, temp, poi);
				t_vec *L = ft_vecinit(0, 0, 0);
				ft_vecdiff(light->center, poi, L);
				t_vec *N = ft_vecinit(0, 0, 0);
				ft_sphnormal(poi, sphere, N);
				ft_vecnormalize(L, temp1);
				ft_vecnormalize(N, temp2);
				double dt = ft_vecdot(temp1, temp2);
				free(temp);
				free(poi);
				free(L);
				free(N);
				free(temp1);
				free(temp2);
				int tv1 = (int)(0x0000FF * fabs(dt)) << 16;
				int tv2 = (int)(0x0000FF * fabs(dt)) << 8;
				int tv3 = (int)(0x0000FF * fabs(dt));
				mlx_pixel_put(ws->mlx, ws->win, x, y, tv1 | tv2 | tv3);
			}
			x++;
		}
		y++;
	}
	free(ray->origin);
	free(ray->direction);
	free(ray);
	free(sphere->center);
	free(sphere);
	free(light->center);
	free(light);
}

int		main(int argc, char *argv[])
{
	t_wnd *ws;
	
	ws = (t_wnd*)malloc(sizeof(t_wnd));
	ws->width = 500;
	ws->height = 500;
	ws->mlx = mlx_init();
	ws->win = mlx_new_window(ws->mlx, ws->width, ws->height, "RayTrace");
	ft_render(ws);
	mlx_loop(ws->mlx);
	return (0);
}