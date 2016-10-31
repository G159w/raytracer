#include "scene.h"
#include <stdio.h>
#include "math.h"
#include "raytracer.h"

//2.5 BASIC CAMERA
s_vector3 **init_cm(s_scene *s)
{
  s_vector3 u = normalise(s->cam->u);
  s_vector3 v = normalise(s->cam->v);
  s_vector3 w = cross_prod(u, v);
  double fo = tan(0.78539816339744830962 / 2);
  double dist = (s->width / 2) / fo;
  s_vector3 p_center = add_vector(scale_vec(dist, w), s->cam->pos);
  return init_tab(s, p_center);
}
