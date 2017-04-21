#include "hOther.h"

int		ft_qesolve(double a, double b, double c, double *x0, double *x1)
{
	double	discr;
	double	q;
	double	temp;

	discr = b * b - 4 * a * c;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = -0.5 * b / a;
		*x1 = *x0;
	}
	else
	{
		q = (b > 0) ? -0.5 * (b + sqrt(discr)) : -0.5 * (b - sqrt(discr));
		*x0 = q / a;
		*x1 = c / q;
	}
	if (*x0 > *x1)
	{
		temp = *x0;
		*x0 = *x1;
		*x1 = temp;
	}
	return (1);
}