#include "rt.h"

void	init_window(t_wnd *ws)
{
	ws = (t_wnd*)malloc(sizeof(t_wnd));
	ws->height = 480;
	ws->width = 640;
	ws->mlx = mlx_init();
	ws->win = mlx_new_window(ws->mlx, ws->width, ws->height, "RayTrace");
}

void	render(t_wnd *ws)
{
	t_ray	*ray;
	int		x;
	int		y;

	y = 0;
	while (y < ws->height)
	{
		x = 0;
		while (x < ws->width)
		{
			// sending rays
			ray = ray_init(vec_init(x, y, 0), vec_init(0, 0, 1));

			// check if ray intersects objects
		}
	}
}

int		main(int argc, char *argv[])
{
	t_wnd	*ws;

	init_window(ws);
	render(ws);
	mlx_loop(ws->mlx);
	return (0);
}