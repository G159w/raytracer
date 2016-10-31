#ifndef RAYTRACER_H
# define RAYTRACER_H

#include "scene.h"
#include "math_funcs.h"
#include "matpix.h"

s_scene *scene;

s_pixel launch_ray(struct ray ray, s_object_list *objects,
                   s_light_list *lights);

double get_diff(s_object *obj);

s_pixel get_color(s_object *obj);

s_pixel point_source(s_pixel color, s_pt_light *light,
                     s_object *obj, s_vector3 point);

s_pixel directional_source(s_pixel color, s_dir_light *light,
                           s_object *obj, s_vector3 point);

s_vector3 calc_normal(s_object *obj, s_vector3 point);

s_pixel merge_colors(s_pixel c1, s_pixel c2, double l);


#endif /* !RAYTRACER_H */
