#include "raytracer.h"

double get_diff(s_object *obj)
{
  struct sphere_object *sph = NULL;
  struct triangle_object *tri = NULL;
  struct plane_object *pln = NULL;
  if (obj->type == SPHERE)
  {
    sph = obj->obj;
    return sph->diff;
  }
  else if (obj->type == TRIANGLE)
  {
    tri = obj->obj;
    return tri->diff;
  }
  else if (obj->type == PLANE)
  {
    pln = obj->obj;
    return pln->diff;
  }
  else if (obj->type == CSG)
  {
    sph = obj->obj;
    return sph->diff;
  }
  return pln->diff;
}

s_pixel get_color(s_object *obj)
{
  s_pixel s =
  {
    0, 0, 0
  };
  struct sphere_object *sph = NULL;
  struct triangle_object *tri = NULL;
  struct plane_object *pln = NULL;
  if (obj->type == SPHERE)
  {
    sph = obj->obj;
    return sph->color;
  }
  else if (obj->type == TRIANGLE)
  {
    tri = obj->obj;
    return tri->color;
  }
  else if (obj->type == PLANE)
  {
    pln = obj->obj;
    return pln->color;
  }
  else if (obj->type == CSG)
  {
    sph = obj->obj;
    return sph->color;
  }
  return s;
}
