#include "matpix.h"
#include "pixel.h"
#include "scene.h"
#include <stdio.h>
#include <stdlib.h>
#include "vector3.h"
#include "matpix.h"

s_scene *scene = NULL;

int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    fprintf(stderr, "Usage: ./rt input.in output.ppm\n");
    return 1;
  }
  scene = parse_file(argv[1]);
  s_vector3 **tab = init_cm(scene);
  s_pixel **pix = init_pix(scene, tab);
  makeppm(pix, scene, argv[2]);
  for (unsigned i = 0; i < scene->height; i++)
    free(tab[i]);
  free(tab);
  return 0;
}
