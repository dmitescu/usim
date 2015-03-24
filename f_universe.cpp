#include "d_universe.h"
#include<cstddef>
//------- T_VECTOR -------
//Constructors
t_vector::t_vector(long double nx=0, long double ny=0){
  x=nx;
  y=ny;
}


//------- P_OBJECT -------
//Constructors:
p_object::p_object(long double nx=0, long double ny=0,
		   long double nm=1){
  x=nx;
  y=ny;
  mass=nm;
}


//------- SYS_OBJ -------
//Constructors:
sys_obj::sys_obj(p_object data, sys_obj* nn=NULL, sys_obj* np=NULL){
  obj=data;
  next=nn;
  prev=np;
}


//------- _TUNIVERSE ------
//Constructors:
_tuniverse::_tuniverse(sys_obj* ns=NULL, sys_obj* ne=NULL,
		       unsigned int nc=0){
  start=ns;
  stop=ne;
  object_count=nc;
}

//Destructors:
_tuniverse::~_tuniverse(){
  while(object_count!=0)
    delete_object(start);
}

//Functions:
//Adding an object
void _tuniverse::add_object(p_object a)
{
  object_count++;
  if(start==0){
    start = new sys_obj(a, start, start);
    stop=start;
  }
  else{
    sys_obj *c;
    c=new sys_obj(a, start, stop);
    start->prev=c;
    stop->next=c;
    stop=c;
  }
}

//deleting an object
void _tuniverse::delete_object(sys_obj *a){
  object_count--;
  a->next->prev=a->prev;
  a->prev->next=a->next;
  delete a;
}
