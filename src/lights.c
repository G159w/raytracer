#include "objects.h"
#include "matpix.h"
#include "raytracer.h"

//merges the two colors given as parameter with the decay l
s_pixel merge_colors(s_pixel c1, s_pixel c2, double l)
{
  s_pixel out =
  {
    c1.r * c2.r * l, c1.g * c2.g * l, c1.b * c2.b * l
  };
  return out;
}

static s_pixel add_colors(s_pixel c1, s_pixel c2)
{
  s_pixel out =
  {
    c1.r + c2.r, c1.g + c2.g, c1.b + c2.b
  };
  return out;
}

// basic ambient source lighting
s_pixel ambient_source(s_pixel color, s_a_light *light)
{
  return merge_colors(color, light->color, 0.1);
}

s_pixel light(s_vector3 point, s_light_list *l, s_object *obj)
{
  s_pixel color =
  {
    0, 0, 0
  };
  if (!obj)
    return color;
// LIST LIGHT THAT WILL MATCH THE VECTOR3
  for (s_light_list *tmp = l; tmp; tmp = tmp->next)
  {
    if (tmp->l->type == AMBIENT)
      color = add_colors(color, ambient_source(get_color(obj), tmp->l->light));
    else if (tmp->l->type == POINT)
      color = add_colors(color, point_source(get_color(obj), tmp->l->light, obj, point));
    else if (tmp->l->type == DIRECTIONAL)
      color = add_colors(color, directional_source(get_color(obj), tmp->l->light, obj, point));
    else if (tmp->l->type == NB_LIGHTS)
      return color;
  }
  return color;
}
