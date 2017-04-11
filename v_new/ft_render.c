#include "hExtract_info.h"
#include "hPrint.h"

int		ft_sumobjects()
{
	int		result;

	result = sphere_nr + plane_nr;
	result += cyl_nr + cone_nr;
	return (result);
}

void	ft_trace()
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			
		}
	}
}

void	ft_render()
{
	int		total_objects;
	int		contor;

	total_objects = ft_sumobjects();
	contor = 0;
	while (contor < total_objects)
	{
		ft_trace(); // ? ? ?
	}
}