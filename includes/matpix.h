#ifndef MATPIX_H_
# define MATPIX_H_

#include "pixel.h"
#include "scene.h"
#include "vector3.h"
#include "math_funcs.h"

s_scene *scene;

s_pixel **init_pix(s_scene *s, s_vector3 **points);

s_vector3 **init_tab(s_scene *s, s_vector3  p_center);

s_pixel launch_ray(struct ray, s_object_list *, s_light_list *);

double launch_light(struct ray, s_object_list *, s_object *obj);

s_vector3 **init_cm(s_scene *s);

s_pixel light(s_vector3 point, s_light_list *l, s_object *obj);

void makeppm(s_pixel **out, s_scene *s, char *name);

#endif /* !MATPIX_H_ */
