#include "d_universe.h"
#include <cmath>

#define _K 0.667428

/*
  !!!!!!!!!!!!!!!!!!!!!!
  MASS IS MEASURED IN 		KG 10e+21
  DISTANCE IS MEASURED IN 	M  10e+9
  !!!!!!!!!!!!!!!!!!!!!!
*/

void _tuniverse::collide_object(sys_obj *a, sys_obj *b)
{
  a->obj.mass = a->obj.mass + b->obj.mass;
  delete_object(b);
}


t_vector _tuniverse::get_accel(sys_obj *p)
{
  t_vector accel(0, 0);
  long double d_square=0.0, dx, dy, F, tg;
  sys_obj* _d = p->next;

  for(int i=0; i<object_count-1; i++)
    {
      // COMPUTING DISTANCE AND TANGENT
      dx = p->obj.x - _d->obj.x;
      dy = p->obj.y - _d->obj.y;
      d_square = dx*dx + dy*dy;
			
      //COMPUTING FORCE
      F = _K * (_d->obj.mass * p->obj.mass) / (d_square * p->obj.mass); //this is actually a = F/m
      //WRITING FORCE VARIABLES
			
      if (dy != 0)
	{
	  tg = std::abs(dx / dy);

	  if (dx > 0)
	    accel.x -= F * tg / sqrt(1 + tg*tg);
	  else
	    accel.x += F * tg / sqrt(1 + tg*tg);

	  if (dy > 0)
	    accel.y -= F *  1 / sqrt(1 + tg*tg);
	  else
	    accel.y += F *  1 / sqrt(1 + tg*tg);
	}
      else
	{
	  if (dx > 0)
	    accel.x -= F;
	  else
	    accel.x += F;
	}

      _d = _d->next;
    }
  return accel;
}


void _tuniverse::step(float dt)
{
  int i=0;
  sys_obj* _c = start;
  t_vector c_accel(0, 0);

  for(i=0; i<object_count; i++)
    {
      //ACCELERATION COMPUTING
      c_accel = get_accel(_c);

      //COORDINATES UPDATE
      _c->obj.x += _c->obj.velocity.x * dt;
      _c->obj.y += _c->obj.velocity.y * dt;

      //VELOCITY UPDATE
      _c->obj.velocity.x += c_accel.x * dt;
      _c->obj.velocity.y += c_accel.y * dt;

      //ACCELERATION UPDATE
      _c->obj.acceleration = c_accel;

      //NEXT OBJECT
      _c = _c->next;
    }
}
