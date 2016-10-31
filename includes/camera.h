#ifndef CAMERA_H_
# define CAMERA_H_

# include "vector3.h"

typedef struct camera s_camera;
struct camera
{
    s_vector3 pos;
    s_vector3 u;
    s_vector3 v;
};


#endif /* !CAMERA_H_ */
