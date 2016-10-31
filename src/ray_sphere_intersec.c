#include "math_funcs.h"
#include <math.h>

#include <stdio.h>

/*
** Returns the 1st point that is meet that cuts trought the sphere
** the boolean boo is used to know ifthe ray intersects or not the object
** 0 is an intersection 1 is no intersection and 2 is a intersection before the
** start of our ray.
*/
s_vector3 ray_sphere_intersec(struct ray ray, s_sphere_object *sphere,
                              int *boo)
{
  *boo = 0;
  s_vector3 out =
  {
    0, 0, 0
  };
  s_vector3 interm = add_vector(ray.point, scale_vec(-1, sphere->pos));
  double a = scalar_prod(ray.vector, ray.vector);
  double b = 2 * scalar_prod(ray.vector, interm);
  double c = scalar_prod(interm, interm) - pow(sphere->rad, 2);
  double det = b * b - 4 * a * c; 
  if (det < 0)
    *boo = 1;
  else
  {
    double x1 = (-b - sqrt(det)) / (2 * a);
    double x2 = (-b + sqrt(det)) / (2 * a);
    if (x2 < 0)
      *boo = -1;
    else if (x1 < 0)
      out = add_vector(ray.point, scale_vec(x2, ray.vector));
    else
      out = add_vector(ray.point, scale_vec(x1, ray.vector));
  }
  return out;
}
