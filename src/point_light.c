#include "raytracer.h"

s_pixel point_source(s_pixel color, s_pt_light *light,
                     s_object *obj, s_vector3 point)
{
  s_pixel out =
  {
    0, 0 ,0
  };
//create the vector that points to the source
  s_vector3 dir = normalise(compute_vec(light->pos, point));
//  struct ray r =
//  {
//    scale_vec(-1, dir), add_vector(point, scale_vec(0.000001, dir))
//  };
  double dist = distance(point, light->pos);
//checks if the light is blocked
//  double is_block = launch_light(r, scene->objects, obj);
//  if (is_block == -1 || is_block > dist)
//    return out;
  s_vector3 normal = normalise(calc_normal(obj, point));
  double l = scalar_prod(normal, dir);
  if (l < 0)
    return out;
  l *= get_diff(obj) / dist;
  return merge_colors(color, light->color, l);
}
