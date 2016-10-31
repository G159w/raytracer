#include "math_funcs.h"
#include <math.h>

double distance(s_vector3 v1, s_vector3 v2)
{
  double out = pow(v1.u - v2.u, 2);
  out += pow(v1.v - v2.v, 2);
  out += pow(v1.w - v2.w, 2);
  out = sqrt(out);
  return out;
}

s_vector3 compute_vec(s_vector3 v1, s_vector3 v2)
{
  s_vector3 out;
  out.u = v2.u - v1.u;
  out.v = v2.v - v1.v;
  out.w = v2.w - v1.w;
  return out;
}
