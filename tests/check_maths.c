#include <stdio.h>
#include "math_funcs.h"

void dump_vector(s_vector3 v)
{
  printf("( %2f, %2f, %2f )\n", v.u, v.v, v.w);
}

void check_funcs(void)
{
  s_vector3 v1 = { 0, 2, 0};
  s_vector3 v2 = { 0, 0, 2};
  s_vector3 zero = {0,0,0};
  dump_vector(add_vector(v1, v2));
  dump_vector(cross_prod(v1, v2));
  dump_vector(scale_vec(10.0, v2));
  printf("distance: %f\n", distance(v1, v2));
  dump_vector(compute_vec(v1, v2));
  printf("prod scal: %f\n", scalar_prod(v1, v2));
  dump_vector(normalise(v1));
  s_vector3 out = cross_prod(normalise(v1), normalise(v2));
  dump_vector(out);
  printf("distance: %f\n", distance(out, zero));
  printf("distance: %f\n", distance(v1, zero));
  printf("distance: %f\n", distance(normalise(v1), zero));
}

void check_intersec(void)
{
  s_vector3 p_ray = {0, 0, 0};
  s_vector3 v_ray = {1, 0, 0};
  s_vector3 p_sph = {10, 2, 0};
  s_pixel i = {0, 0, 0};
  s_sphere_object sphere = {5.0, p_sph, 0,0,0,0,0, 0, i};
  struct ray ray = {v_ray, p_ray};
  int boo;
  printf("intersection:\n");
  s_vector3 out = ray_sphere_intersec(ray, &sphere, &boo);
  dump_vector(out);
  printf("%d\n", boo);
}
