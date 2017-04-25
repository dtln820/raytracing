#include "hExtract_info.h"
#include "hRaytracing.h"

#define DEPTH 5

const double INFI = DBL_MAX;

int		ft_sumobjects()
{
	int		result;

	result = sphere_nr + plane_nr;
	result += cyl_nr + cone_nr;
	return (result);
}

_Bool	ft_trace(t_vec3 *orig, t_vec3 *dir, double tNear, uint32_t index, t_vec2 *uv, void **hitObject)
{
	char		intersected;
	int			obj_nr;
	int			i;
	int			cur_obj;
	t_sphnode	*sph_sent;
	t_planenode	*plane_sent;
	t_cylnode	*cyl_sent;
	t_conenode	*cone_sent;

	intersected = 0;
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
				intersected = 1;
				*hitObject = sph_sent;
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
				intersected = 1;
				*hitObject = plane_sent;
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
				intersected = 1;
				*hitObject = cyl_sent;
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
				intersected = 1;
				*hitObject = cone_sent;
			}
		cone_sent = cone_sent->next;
	}
	if (intersected == 0)
		return (0);
	return (1);
}

int		ft_castray(t_vec3 *o, t_vec3 *d, int current_depth)
{
	if (current_depth > DEPTH)
		return (0x000000);
	int			hitColor;
	double		tnear = INFI;
	t_vec2		*uv;
	uint32_t	index = 0;
	void		*hitObject;
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