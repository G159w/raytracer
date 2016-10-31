#include "raytracer.h"

s_pixel directional_source(s_pixel color, s_dir_light *light,
                           s_object *obj, s_vector3 point)
{
  s_pixel out =
  {
    0, 0 ,0
  };
  struct ray r =
  {
    scale_vec(-1, light->dir), add_vector(scale_vec(-0.000001, light->dir),
                                          point)
  };
  //check if the light isn't blocked
  double comp = launch_light(r, scene->objects, obj);
  if (comp != -1)
    return out;
  // compute the coefficient 
  s_vector3 normal = calc_normal(obj, point);
  double l = scalar_prod(normal, normalise(light->dir));
  if (l < 0)
    return out;
  l *= get_diff(obj);
  return merge_colors(color, light->color, l);
}
