#include "rt.h"

// void	init_window(t_wnd *ws)
// {
// 	ws = (t_wnd*)malloc(sizeof(t_wnd));
// 	ws->height = 480;
// 	ws->width = 640;
// 	ws->mlx = mlx_init();
// 	ws->win = mlx_new_window(ws->mlx, ws->width, ws->height, "RayTrace");
// }

void	render(t_wnd *ws)
{
	t_ray	*ray;
	int		x;
	int		y;
	double	t;
	t_sphere *sphere;

	sphere = sphere_init(vec_init(ws->width / 2, ws->height / 2, 50), 20);

	t = 20000;
	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			// sending rays
			ray = ray_init(vec_init(x, y, 0), vec_init(0, 0, 1));

			// check if ray intersects objects
			if (sph_intersect(ray, &t, sphere) == 1)
			{
				mlx_pixel_put(ws->mlx, ws->win, x, y, 0xFFFFFF);
			}
			// if (ray)
			// {
			// free(ray->orig);
			// free(ray->dir);
			// free(ray);
			// }
		}
	}
	// if (sphere)
	// {
	// free(sphere->center);
	// free(sphere);
	// }
}

int		main(int argc, char *argv[])
{
	t_wnd	*ws;

	ws = (t_wnd*)malloc(sizeof(t_wnd));
	ws->height = 480;
	ws->width = 640;
	ws->mlx = mlx_init();
	ws->win = mlx_new_window(ws->mlx, ws->width, ws->height, "RayTrace");
	render(ws);
	mlx_loop(ws->mlx);
	return (0);
}