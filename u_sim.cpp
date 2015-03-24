#include<iostream>
#include<fstream>
#include "d_universe.h"

using namespace std;

int main(){
  _tuniverse univers;
  p_object _temp_object;
  char _temp_string[30];
  int i=0;
  sys_obj *_c;

  cout << "Input filename:";
  cin >> _temp_string;
  const char * _in_filename=_temp_string;
  ifstream fin(_in_filename);

  //READING FROM FILE

  int n;
  fin >> i;
  while(i>0){
    fin >>
      _temp_object.x >>
      _temp_object.y >>
      _temp_object.mass >>
      _temp_object.velocity.x >>
      _temp_object.velocity.y;

    add_object(_temp_object,&univers);i--;
  }

  cout << "Done loading file.\n";

  cout << "Output filename:";
  cin >> _temp_string;
  const char * _out_filename=_temp_string;
  ofstream fout(_out_filename);
  cout << '\n';


  float time=0,tstep=0;
  fin >> time >> tstep;
  cout << "Simulating...";

  //SIMULATION - BEGINING

  fout << univers.object_count << ' ' << time<< ' ' << tstep <<'\n';
  while(time>0){
    step(tstep, &univers);

    _c=univers.start;
    for(i=0;i<univers.object_count;i++){
      fout <<
	_c->obj.x << ' ' <<
	_c->obj.y << ' ';// <<
      //_c->obj.velocity.x << ' '<<
      //_c->obj.velocity.y << ' '<<
      //_c->obj.acceleration.x << ' '<<
      //_c->obj.acceleration.y<<
      //'\n';
      _c=_c->next;
    }
    fout << '\n';
    time=time-tstep;
  }


  //SIMULATION - END

  cout << "Done!";


  return 0;
}

