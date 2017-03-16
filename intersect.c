#include "rt.h"

int		sph_intersect(t_ray *ray, double *t, t_sphere *sphere)
{
	t_vec	orig;
	t_vec	dir;
	t_vec	oc;
	double	b;
	double	c;
	double	disc;

	orig.x = ray->orig->x;
	orig.y = ray->orig->y;
	orig.z = ray->orig->z;
	dir.x = ray->dir->x;
	dir.y = ray->dir->y;
	dir.z = ray->dir->z;
	oc = vec_diff(orig, sphere->center); // center of sphere
	b = 2 * vec_dot(oc, dir);
	c = vec_dot(oc, oc) - sphere->radius * sphere->radius; // radius of sphere
	disc = b * b - 4 * c;
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