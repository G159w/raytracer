#ifndef LIGHT_H_
# define LIGHT_H_

#include "pixel.h"
#include "vector3.h"

enum type_light
{
    DIRECTIONAL,
    POINT,
    AMBIENT,
    NB_LIGHTS
};

typedef enum type_light e_type_light;

typedef struct light s_light;
struct light
{
    e_type_light type;
    void *light;
};

typedef struct light_list s_light_list;
struct light_list
{
    s_light *l;
    s_light_list *next;
};

typedef struct dir_light s_dir_light;
struct dir_light
{
    s_vector3 dir;
    s_pixel color;
};

typedef struct pt_light s_pt_light;
struct pt_light
{
    s_vector3 pos;
    s_pixel color;
};

typedef struct a_light s_a_light;
struct a_light
{
    s_pixel color;
};


#endif /* !LIGHT_H_ */
