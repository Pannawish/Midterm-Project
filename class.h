#ifndef class_h
#define class_h
#include <string.h>

class dog
{
public:
  string species;
  int age;
  string owner_name; //owner name
  string dog_name; //dog name
  int vaccine;
  string snack;
  int foodcode;
  dog();
};
dog::dog(){
  species = "unidentified";
  age = 0;
  owner_name = "N/A";
  dog_name = "Unspecified";
  vaccine = 0;
  snack = "Unknown";
  foodcode = 0;
}

#endif

