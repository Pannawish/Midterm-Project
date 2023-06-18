#include "class.h"
inline void swap(int &a,int &b){
 int temp;
  temp=a;
  a=b;
  b=temp;
}
/*int selectionSort(dog *c, int length) 
{ 
  int list[length];
	int i, j, m, mi; 
  for (i=0;i<length;i++){
    list[i]=i;
  }
  for(j=0;j<length-1;j++)
    {
  mi=j;
      //what about mi ^^
	for (i = j+1; i < length; i++) 
	{ 
	   // find the minimum
	    if(c[mi].age>c[i].age)
      {
        mi=i;
      }
    //swap(list[j],list[mi]);
  }
      swap(list[j],list[mi]);
    //display(data,length);
  //cout<<"==========================================================="<<endl;
     
      
	}
  //display(data,length);
  for(i=0;i<length;i++){
    cout<<list[i]<<endl;
  }
  return list[length];
}*/

void lowest(dog *d, int n){
  int min=d[0].age,i;
  for(i=0;i<n;i++){
    if(d[i].age<min){
      min=i;
    }
  }
  //cout<<i;
  //return i; 
  cout<<"The youngest dog is "<<d[min].dname<<". "<<d[min].age<<" years old."<<endl;
}


void highest(dog *d, int n){
  int max=0,i;
  for(i=0;i<n;i++){
    if(d[i].age>d[max].age){
      max=i;
    }
  }
  cout<<"The oldest dog is a "<<d[max].dname<<". "<<d[max].age<<" years old."<<endl;
}

int* sort(int d[], int length) 
{ 
  int* list = new int[length]; // Dynamically allocate an integer array

  int i, j, mi;
  for (i = 0; i < length; i++) {
    list[i] = i;
  }

  for (j = 0; j < length - 1; j++) {
    mi = j;
    for (i = j + 1; i < length; i++) { 
      // find the minimum
      if (d[mi] > d[i]) 
      {
        mi = i;
      }
      //std::swap(list[j], list[mi]);
    }
    //std::swap(d[j], d[mi]);
    int temp;
  temp=d[j];
  d[j]=d[mi];
  d[mi]=temp;
    int temp2;
  temp2=list[j];
  list[j]=list[mi];
  list[mi]=temp2;
  }

  for (i = 0; i < length; i++) {
    cout << list[i] << endl;
  }

  //delete[] list; // Deallocate the dynamically allocated array

  return list;
}




