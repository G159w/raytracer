#include "raytracer.h"

s_vector3 ray_plane_intersec(struct ray ray, s_plane_object *plane, int *boo)
{
  double t = 0;
  *boo = 0;
  s_vector3 n;
  n.u = plane->a;
  n.v = plane->b;
  n.w = plane->c;
  if (scalar_prod(n, ray.vector) == 0)
    *boo = 1;
  else
    t = -(scalar_prod(n, ray.point) + plane->d) / scalar_prod(n, ray.vector);
  if (t < 0)
    *boo = -1;
  else
    n = add_vector(ray.point, scale_vec(t, ray.vector));
  return n;
}
