#ifndef _D_UNIVERSE_H
#define _D_UNIVERSE_H

class t_vector{
 public:
  long double x,y;

  t_vector(long double, long double);
};

class p_object{
 public:
  long double x,y;
  long double mass;
  t_vector velocity;
  t_vector acceleration;

  p_object(long double, long double, long double);
};


class sys_obj{
 public:
  p_object obj;
  sys_obj *next;
  sys_obj *prev;

  sys_obj(p_object, sys_obj*, sys_obj*);
};

class _tuniverse{
 public:
  sys_obj *start;
  sys_obj *stop;
  unsigned int object_count;

  _tuniverse(sys_obj*, sys_obj*, unsigned int);
  ~_tuniverse();

  //Object creation
  void add_object(p_object a);
  void delete_object(sys_obj *a);

  //Processing
  void step(float dt);
  
 private:
  t_vector get_accel(sys_obj *a);
  void collide_object(sys_obj *a, sys_obj *b);
};





#endif
