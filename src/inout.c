#include <stdio.h>
#include <stdlib.h>
#include "raytracer.h"

//TAB CREATION 
s_vector3 **init_tab(s_scene *s, s_vector3 p_center)
{
  long int y_screen = s->width / 2;
  long int x_screen = s->height / 2;
  s_vector3 **output = malloc(sizeof (s_vector3 *) * s->height);
  for (unsigned j = 0; j < s->height; j++)
    output[j] = malloc(sizeof (s_vector3) * s->width);
  for (long int i = -x_screen; i < x_screen; i++)
    for (long int j = -y_screen; j < y_screen; j++)
    {
      s_vector3 position = add_vector(scale_vec(i, s->cam->v),
                                      scale_vec(j, s->cam->u));
      output[i + x_screen][j + y_screen] = add_vector(p_center, position);
    }
  return output;
}

//PIXEL FILLING
s_pixel **init_pix(s_scene *s, s_vector3 **points)
{
  s_pixel **output = malloc(sizeof (s_pixel *) * s->height);
  for (unsigned j = 0; j < s->height; j++)
    output[j] = malloc(sizeof (s_pixel) * s->width);
  for (unsigned i = 0; i < s->height; i++)
    for (unsigned j = 0; j < s->width; j++)
    {
      struct ray ray =
      {
        normalise(compute_vec(s->cam->pos, points[i][j])), s->cam->pos
      };
      output[i][j] = launch_ray(ray, s->objects, s->lights);
    }
  return output;
}

//WRITE IN THE FILE
void makeppm(s_pixel **output, s_scene *s, char *name)
{
  FILE *fd = fopen(name, "w+");
  fprintf(fd,"P3\n");
  fprintf(fd,"%u %u\n", s->width, s->height);
  fprintf(fd,"255\n");
  for (unsigned i = 0; i < s->height; i++)
  {
    for (unsigned j = 0; j < s->width; j++)
    {
      fprintf(fd,"%3.0f %3.0f %3.0f  ",  255 * output[i][j].r,
              255 * output[i][j].g, 255 * output[i][j].b);
    }
    fprintf(fd,"\n");
  }
  for (unsigned i = 0; i < s->height; i++)
    free(output[i]);
  free(output);
  fclose(fd);
}
