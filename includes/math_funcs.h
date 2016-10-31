#ifndef MATH_FUNCS_H
# define MATH_FUNCS_H

#include "scene.h"

struct ray
{
  s_vector3 vector;
  s_vector3 point;
};

#include <math.h>

s_vector3 add_vector(s_vector3 v1, s_vector3 v2);

s_vector3 scale_vec(double lambda, s_vector3 v1);

double scalar_prod(s_vector3 v1, s_vector3 v2);

s_vector3 cross_prod(s_vector3 v1, s_vector3 v2);

s_vector3 normalise(s_vector3 v1);

double distance(s_vector3 v1, s_vector3 v2);

s_vector3 compute_vec(s_vector3 v1, s_vector3 v2);

s_vector3 ray_plane_intersec(struct ray ray, s_plane_object *plane, int *boo);

s_vector3 ray_sphere_intersec(struct ray ray, s_sphere_object *sphere,
                              int *boo);

s_vector3 ray_triangle_intersec(struct ray ray, s_triangle_object *triangle,
                                int *boo);

#endif /* !MATH_FUNCS_H*/
