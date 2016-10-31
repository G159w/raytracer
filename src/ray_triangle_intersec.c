#include "math_funcs.h"
#include <stdio.h>

static int is_valid(s_vector3 u, s_vector3 v, s_vector3 a, s_vector3 b)
{
  s_vector3 point1 = cross_prod(compute_vec(a, b), compute_vec(a, v));
  s_vector3 point2 = cross_prod(compute_vec(a, b), compute_vec(a, u));
  return scalar_prod(point1, point2) >= 0;
}

static int is_in_tri(s_vector3 a, s_vector3 b, s_vector3 c, s_vector3 p)
{
  return is_valid(p, b, a, c) && is_valid(p, a, b, c) && is_valid(p, c, a, b);
}

s_vector3 ray_triangle_intersec(struct ray ray, s_triangle_object *triangle,
                                int *boo)
{
  *boo = 0;
  s_vector3 ac = compute_vec(triangle->c, triangle->a);
  s_vector3 ab = compute_vec(triangle->b, triangle->a);
  s_vector3 n = normalise(cross_prod(ab, ac));
  double d = -n.u * triangle->a.u -n.v * triangle->a.v -n.w * triangle->a.w;
  s_plane_object plane =
  {
    n.u, n.v, n.w, d, 0, 0, 0, 0, 0, 0, triangle->color
  };
  n = ray_plane_intersec(ray, &plane, boo);
  if (boo)
    return n;
  if (is_in_tri(triangle->a, triangle->b, triangle->c, n))
    *boo = 0;
  *boo = 1;
  return n;
}
