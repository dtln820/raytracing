#include "rtv1.h"

int		intersection(t_ray *ray, double *t, t_sphere *sphere)
{
	t_vec	*temp_o;
	t_vec	*temp_d;
	t_vec	*temp_oc;

	temp_o = (t_vec*)malloc(sizeof(t_vec));
	temp_d = (t_vec*)malloc(sizeof(t_vec));
	temp_oc = (t_vec*)malloc(sizeof(t_vec));
	ft_vecinit(ray->origin->x, ray->origin->y, ray->origin->z, temp_o);
	ft_vecinit(ray->direction->x, ray->direction->y, ray->direction->z, temp_d);
	ft_vecdiff(temp_o, sphere->center, temp_oc);

	double b = 2 * ft_vecdot(temp_oc, temp_d);
	double c = ft_vecdot(temp_oc, temp_oc) - sphere->radius * sphere->radius;
	double disc = b * b - 4 * c;

	free(temp_o);
	free(temp_d);
	free(temp_oc);
	if (disc < 0)
		return (0);
	else
	{
		disc = sqrt(disc);
		double t0 = -b - disc;
		double t1 = -b + disc;
		*t = (t0 < t1) ? t0 : t1;
		return (1);
	}
}

void	ft_render(t_wnd *ws)
{
	double		t;
	int			y;
	int			x;
	t_ray		*ray;
	t_vec		*orig = (t_vec*)malloc(sizeof(t_vec));
	t_vec		*dir = (t_vec*)malloc(sizeof(t_vec));
	t_sphere	*sphere = (t_sphere*)malloc(sizeof(t_vec));
	t_vec		*center = (t_vec*)malloc(sizeof(t_vec));

	ft_vecinit(ws->width / 2, ws->height / 2, 50, center);
	ft_sphereinit(center, 50, sphere);
	t = 20000;
	ray = (t_ray*)malloc(sizeof(t_ray));
	y = 0;
	while (y < ws->height)
	{
		x = 0;
		while (x < ws->width)
		{
			// init vectors and trace ray
			ft_vecinit(x, y, 0, orig);
			ft_vecinit(0, 0, 1, dir);
			ft_rayinit(orig, dir, ray);

			// check intersection
			if (intersection(ray, &t, sphere) == 1)
			{
				// put_pixel
				mlx_pixel_put(ws->mlx, ws->win, x, y, 0xFFFFFF);
			}
			x++;
		}
		y++;
	}
	free(orig);
	free(dir);
	free(ray);
	free(center);
	free(sphere);
}

int		main(int argc, char *argv[])
{
	t_wnd *ws;
	
	ws = (t_wnd*)malloc(sizeof(t_wnd));
	ws->width = 500;
	ws->height = 500;
	ws->mlx = mlx_init();
	ws->win = mlx_new_window(ws->mlx, ws->width, ws->height, "Test");
	ft_render(ws);
	mlx_loop(ws->mlx);
	return (0);
}