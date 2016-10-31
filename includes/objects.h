#ifndef OBJECTS_H_
# define OBJECTS_H_

# include "camera.h"
# include "pixel.h"

/* enums */

enum type_object
{
  SPHERE,
  TRIANGLE,
  PLANE,
  CSG,
};

enum csg_type
{
  UNION,
  INTERSECTION,
  DIFFERENCE
};

typedef enum type_object e_type_object;
typedef enum csg_type e_csg_type;

/* structs */

typedef struct object s_object;
struct object
{
    e_type_object type;
    void *obj;
};

typedef struct obj_csg s_csg;
struct obj_csg
{
  e_csg_type type;
  double diff;
  double refl;
  double spec;
  double shin;
  double refr;
  double opac;
  s_pixel color;
  s_object *first;
  s_object *second;
};

typedef struct object_list s_object_list;
struct object_list
{
    s_object *o;
    s_object_list *next;
};

typedef struct sphere_object s_sphere_object;
struct sphere_object
{
    double rad;
    s_vector3 pos;
    double diff;
    double refl;
    double spec;
    double shin;
    double refr;
    double opac;
    s_pixel color;
};

typedef struct triangle_object s_triangle_object;
struct triangle_object
{
    s_vector3 a;
    s_vector3 b;
    s_vector3 c;
    double diff;
    double refl;
    double spec;
    double shin;
    double refr;
    double opac;
    s_pixel color;
};

typedef struct plane_object s_plane_object;
struct plane_object
{
    double a;
    double b;
    double c;
    double d;
    double diff;
    double refl;
    double spec;
    double shin;
    double refr;
    double opac;
    s_pixel color;
};


#endif /* !OBJECTS_H_ */
