#include "d_universe.h"
#include<cmath>
#define k 0.667428

/*
!!!!!!!!!!!!!!!!!!!!!!
MASS IS MEASURED IN 		KG 10e+21
DISTANCE IS MEASURED IN 	M  10e+9
!!!!!!!!!!!!!!!!!!!!!!
*/

void collide_object(sys_obj *a, sys_obj *b, _tuniverse *tu){
    a->obj.mass=a->obj.mass+b->obj.mass;
    delete_object(b, tu);
}



t_vector get_accel(sys_obj *p, _tuniverse *t)
{
    t_vector accel; long double tmp=0.0,dx,dy,F,tgsqrd;
    accel.x=0;accel.y=0;
    sys_obj *_d=p->next;
    for(int i=0;i<t->object_count-1;i++)
    {
        // COMPUTING DISTANCE AND TANGENT
        dx=p->obj.x-_d->obj.x;
        dy=p->obj.y-_d->obj.y;
        tmp=dx*dx+dy*dy;
        tgsqrd=(dy*dy)/(dx*dx);
        //COMPUTING FORCE
        F=k*(p->obj.mass*_d->obj.mass)/(tmp*p->obj.mass);

        //WRITING FORCE VARIABLES
        if(dx>0)    accel.x-=F*sqrt(tgsqrd/(1+tgsqrd));
        else        accel.x+=F*sqrt(tgsqrd/(1+tgsqrd));
        if(dy>0)    accel.y-=F*sqrt(1/(1+tgsqrd));
        else        accel.y+=F*sqrt(1/(1+tgsqrd));
        _d=_d->next;
    }
    return accel;
}

void step(float dt, _tuniverse *tu){
    int i=0;
    sys_obj *_c=tu->start; t_vector c_accel, m_accel;
    
    for(i=0;i<tu->object_count;i++){
	
	//ACCELERATION COMPUTING

        c_accel = get_accel(_c,tu);
	c_accel.x=c_accel.x/2+_c->obj.acceleration.x;c_accel.y=c_accel.y/2+_c->obj.acceleration.y;
        //COORDINATES UPDATE

        _c->obj.x+=_c->obj.velocity.x*dt+(c_accel.x*dt*dt)/2;
        _c->obj.y+=_c->obj.velocity.y*dt+(c_accel.y*dt*dt)/2;

        //VELOCITY UPDATE
        _c->obj.velocity.x+=c_accel.x*dt;
        _c->obj.velocity.y+=c_accel.y*dt;


        //ACCELERATION UPDATE

        _c->obj.acceleration=c_accel;

        //NEXT OBJECT
        _c=_c->next;


	/*
	!!!!! TRADITIONAL CODE (NO INTEGRATION) !!!!!
	

        c_accel = get_accel(_c,tu);

        _c->obj.x+=_c->obj.velocity.x*dt+(c_accel.x*dt*dt)/2;
        _c->obj.y+=_c->obj.velocity.y*dt+(c_accel.y*dt*dt)/2;



        _c->obj.acceleration=c_accel;

        _c->obj.velocity.x+=_c->obj.acceleration.x*dt;
        _c->obj.velocity.y+=_c->obj.acceleration.y*dt;



        _c=_c->next;


	*/
    }
}
