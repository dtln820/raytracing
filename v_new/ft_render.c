#include "hExtract_info.h"
#include "hRaytracing.h"

const double INFI = DBL_MAX;

int		ft_sumobjects()
{
	int		result;

	result = sphere_nr + plane_nr;
	result += cyl_nr + cone_nr;
	return (result);
}

_Bool	ft_trace(t_vec3 *orig, t_vec3 *dir, double tNear, uint32_t index, t_vec2 *uv)
{
	int			obj_nr;
	int			i;
	int			cur_obj;
	t_sphnode	*sph_sent;
	t_planenode	*plane_sent;
	t_cylnode	*cyl_sent;
	t_conenode	*cone_sent;

	sph_sent = sph_head;
	plane_sent = plane_head;
	cyl_sent = cyl_head;
	cone_sent = cone_head;
	double tNearK = INFI;
	uint32_t indexK;
	t_vec2 *uvK;
	while (sph_sent != NULL)
	{
		if (ft_sphintersect(orig, dir, tNearK, indexK, uvK, sph_sent))
			if (tNearK < tNear)
			{
				tNear = tNearK;
				index = indexK;
				ft_vec2set(uvK->x, uvK->y, uv);
			}
		sph_sent = sph_sent->next;
	}
	while (plane_sent != NULL)
	{
		if (ft_planeintersect(orig, dir, tNearK, indexK, uvK, plane_sent))
			if (tNearK < tNear)
			{
				tNear = tNearK;
				index = indexK;
				ft_vec2set(uvK->x, uvK->y, uv);
			}
		plane_sent = plane_sent->next;
	}
	while (cyl_sent != NULL)
	{
		if (ft_cylintersect(orig, dir, tNearK, indexK, uvK, cyl_sent))
			if (tNearK < tNear)
			{
				tNear = tNearK;
				index = indexK;
				ft_vec2set(uvK->x, uvK->y, uv);
			}
		cyl_sent = cyl_sent->next;
	}
	while (cone_sent != NULL)
	{
		if (ft_coneintersect(orig, dir, tNearK, indexK, uvK, cone_sent))
			if (tNearK < tNear)
			{
				tNear = tNearK;
				index = indexK;
				ft_vec2set(uvK->x, uvK->y, uv);
			}
		cone_sent = cone_sent->next;
	}
}

int		ft_castray()
{
	if (ft_trace())
	{
		/*
		Do the math
		*/
	}
}

void	ft_render()
{
	int		color;
	int		j;
	int		i;

	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			/*
			Generate ray
			Calculate the direction vector
			*/
			color = ft_castray();
		}
	}
}