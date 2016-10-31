#ifndef SCENE_H_
# define SCENE_H_

# include <stdio.h>
# include "light.h"
# include "camera.h"
# include "pixel.h"
# include "objects.h"

typedef struct scene s_scene;
struct scene
{
    unsigned width;
    unsigned height;
    s_camera *cam;
    s_light_list *lights;
    s_object_list *objects;
};

s_scene *parse_file(char *filename);


#endif /* !SCENE_H_ */
