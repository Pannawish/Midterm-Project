#ifndef class_h
#define class_h

class dog
{
public:
  string species;
  int age;
  string name; //owner name
  string dname; //dog name
  int vaccine;
  string snack;
  int foodcode;
  dog();
};
dog::dog(){
  species = "unidentified";
  age = 0;
  name = "unidentified";
  dname = "unidentified";
  vaccine = 0;
  snack = "unidentified";
  foodcode = 0;
}

#endif

