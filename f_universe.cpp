#include "d_universe.h"

void add_object(p_object a,_tuniverse *tu)
{
tu->object_count++;
if(tu->start==0){
    tu->start = new sys_obj;
    tu->start->obj=a;
    tu->start->next=tu->stop;
    tu->start->prev=tu->stop;
    tu->stop=tu->start;
}
else{
    sys_obj *c;
    c=new sys_obj;
    tu->start->prev=c;
    c->obj=a;
    c->next=tu->start;
    c->prev=tu->stop;
    tu->stop->next=c;
    tu->stop=c;
}
}

void delete_object(sys_obj *a, _tuniverse *tu){
 //   sys_obj *c=a;
    tu->object_count--;
    a->next->prev=a->prev;
    a->prev->next=a->next;
    delete a;

}
