#ifndef _D_UNIVERSE_H
#define _D_UNIVERSE_H

struct t_vector{
long double x=0,y=0;
};

struct p_object{
long double x,y;
long double mass;
t_vector velocity;
t_vector acceleration;
};


struct sys_obj{
p_object obj;
sys_obj *next=0;
sys_obj *prev=0;
};

struct _tuniverse{
sys_obj *start=0;
sys_obj *stop=0;
unsigned int object_count=0;
};

void add_object(p_object a, _tuniverse *tu);
void delete_object(sys_obj *a, _tuniverse *tu);


void step(float dt, _tuniverse *tu);
void collide_object(sys_obj *a, sys_obj *b, _tuniverse *tu);

#endif
