#include "rt.h"

t_vec       vec_diff(t_vec a, t_vec b)
{
    t_vec   result;

    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;

    return (result);
}

double      vec_dot(t_vec a, t_vec b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}