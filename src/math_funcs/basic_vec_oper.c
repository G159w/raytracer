#include "math_funcs.h"
#include <math.h>

s_vector3 add_vector(s_vector3 v1, s_vector3 v2)
{
  s_vector3 out;
  out.u = v1.u + v2.u;
  out.v = v1.v + v2.v;
  out.w = v1.w + v2.w;
  return out;
}

s_vector3 scale_vec(double lambda, s_vector3 v1)
{
  s_vector3 out;
  out.u = lambda * v1.u;
  out.v = lambda * v1.v;
  out.w = lambda * v1.w;
  return out;
}

double scalar_prod(s_vector3 v1, s_vector3 v2)
{
  double out;
  out = v1.u * v2.u;
  out += v1.v * v2.v;
  out += v1.w * v2.w;
  return out;
}

s_vector3 cross_prod(s_vector3 v1, s_vector3 v2)
{
  s_vector3 out;
  out.u =  v1.v * v2.w - v1.w * v2.v;
  out.v =  v1.w * v2.u - v1.u * v2.w;
  out.w =  v1.u * v2.v - v1.v * v2.u;
  return out;
}

s_vector3 normalise(s_vector3 v1)
{
  if (!v1.u && !v1.v && !v1.w)
    return v1;
  double norm = v1.u * v1.u + v1.v * v1.v + v1.w * v1.w;
  norm = sqrt(norm);
  s_vector3 out;
  out.u = v1.u / norm;
  out.v = v1.v / norm;
  out.w = v1.w / norm;
  return out;
}
