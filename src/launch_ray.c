#include "scene.h"
#include "objects.h"
#include "matpix.h"
#include <stdio.h>

s_vector3 cycle(s_object *obj, struct ray ray, int *boo)
{
  s_vector3 coll =
  {
    0, 0, 0
  };
  if (obj->type == SPHERE)
    coll = ray_sphere_intersec(ray, obj->obj, boo);
  else if (obj->type == TRIANGLE)
    coll = ray_triangle_intersec(ray, obj->obj, boo);
  else if (obj->type == PLANE)
    coll = ray_plane_intersec(ray, obj->obj, boo);
  else if (obj->type == CSG)
    *boo = 1;
    //coll = ray_csg_intersec(ray, tmp->o->obj, &boo)
  return coll;
}

s_pixel launch_ray(struct ray ray, s_object_list *objects,
                   s_light_list *lights)
{
// INIT VAR
  double min = -1.;
  s_vector3 coll;
  void *obj = NULL;
  s_vector3 p_coll;
  double new = 0;
  int boo = 0;
// SEARCHING THE BEST OBJECT
  for (s_object_list *tmp = objects; tmp; tmp = tmp->next)
  {
    coll = cycle(tmp->o, ray, &boo);
    if (!boo)
    {
      new = distance(ray.point, coll);
      if (min == -1 || new < min)
      {
        min = new;
        obj = tmp->o;
        p_coll = coll;
      }
    }
    boo = 1;
  }
// LIGHT FCNT ON THE OBJS (OBJ && COLLOBJ) TO FIND HIS COLOR
  return light(p_coll, lights, obj);
}

double launch_light(struct ray ray, s_object_list *objects, s_object *object)
{
// INIT VAR
  double min = -1.;
  s_vector3 coll;
  double new = 0;
  int boo = 0;
  //struct triangle_obj *tri = NULL;
  void *comp = object;
// SEARCHING THE BEST OBJECT

  for (s_object_list *tmp = objects; tmp; tmp = tmp->next)
  {
    if (tmp->o == comp)
      continue;
    coll = cycle(tmp->o, ray, &boo);
    if (!boo)
    {
      new = distance(ray.point, coll);
      if (min == -1 || new < min)
        min = new;
    }
    boo = 1;
  }
// LIGHT FCNT ON THE OBJS (OBJ && COLLOBJ) TO FIND HIS COLOR
  return min;
}
