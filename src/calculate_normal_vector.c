#include "raytracer.h"

s_vector3 calc_normal(s_object *obj, s_vector3 point)
{
  if (obj->type == SPHERE)
  {
    s_sphere_object *sph = obj->obj;
    return normalise(compute_vec(point, sph->pos));
  }
  else if (obj->type == PLANE)
  {
    s_plane_object *pln = obj->obj;
    s_vector3 res =
    {
      pln->a, pln->b, pln->c
    };
    return normalise(res);
  }
  else if (obj->type == CSG)
  {
    //s_csg *csg = obj->obj;
    // NEED TO ADD FUNCTION FOR CSG NORMALS
    return point;
  }
  else
  {
    s_triangle_object *tri = obj->obj;
    s_vector3 ab = compute_vec(tri->a, tri->b);
    s_vector3 ac = compute_vec(tri->a, tri->c);
    return normalise(cross_prod(ab, ac));
  }
}
