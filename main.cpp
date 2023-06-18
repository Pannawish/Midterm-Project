#include <iostream>
using namespace std;
#include "class.h"
#include "sorting.h"

int main() {
  cout << "Welcome to Pet Store." << endl;
  int n;
  cout << "Number of costumers? ";
  cin >> n;
  cout << "Please fill in the information below." << endl;
  int no = 1;
  dog *d=new dog[n];

  while ((no - 1) != n) {
    cout << "#" << no << endl;
    cout << "Owner: ";
    cin >> (*(d + no - 1)).name;
    cout << "Name:";
    cin >> (*(d + no - 1)).dname;
    cout << "Species/Breed? ";
    cin >> (*(d + no - 1)).species;
    
    cout << "Age: ";
    cin >> (*(d + no - 1)).age;
      
    cout << "Hisotry of vaccination?\n (Yes(1) or No(0)):";
    int ans;
    cin >> ans;
    if (ans == 1) {
      (*(d + no - 1)).vaccine = 1;
    } 
    else (*(d + no - 1)).vaccine = 0;
    cout << "Which brand of dog food you whould like to purchase? (input the "
            "number!) "
         << endl;
    int k;
    while(1){
    cout << "1. Purina Pro Plan" << endl
         << "2. Pedigree" << endl
         << "3. Royal chain" << endl
         << "4. Bil-Jac"
         << "Your order: " << endl;
    
    cin >> k;
      if (k<=4&&k>=1) break;
    }
    /*switch (k)
    {
      case 1: (*(d+no-1)).snack="Purina Pro Plan\n"; break; // prints "1",
      case 2: (*(d+no-1)).snack="Pedigree\n"; break; // then prints "2"
      case 3: (*(d+no-1)).snack="Royal chain\n"; break;
      case 4: (*(d+no-1)).snack="Bil-Jac\n"; break;
      default:std::cout << "default\n"; break;
    }*/
    if (k == 1){
      (*(d + no - 1)).snack = "Purina Pro Plan";
      (*(d + no - 1)).foodcode = 1;
    }
    else if (k == 2){
      (*(d + no - 1)).snack = "Pedigree";
      (*(d + no - 1)).foodcode = 2;
    }
    else if (k == 3){
      (*(d + no - 1)).snack = "Royal chain";
      (*(d + no - 1)).foodcode = 3;
    }
    else if (k == 4){
      (*(d + no - 1)).snack = "Bil-Jac";
      (*(d + no - 1)).foodcode = 4;
    }
    no += 1;
    cout << endl;
  }
  cout << "Choose what you want to do with the data. " << endl;
  cout << "1. List each dog's name from youngest to oldest" << endl
       << "2. Tell the most popular dog's food" << endl
       << "3. Tell whose dog is the youngest" << endl
       << "4. Tell me whose dog is the oldest" << endl
       << "5. Tell me which dog is vaccinated or not vaccinated." << endl
       << "6. Summarize all data briefly." << endl;
  int a;
  int i;
  cin >> a;

    int q,w,e,r;
    for (i=0;i<n;i++){
      if(d[i].foodcode==1) q++;
      if(d[i].foodcode==2) w++;
      if(d[i].foodcode==3) e++;
      if(d[i].foodcode==4) r++;
    }
    int max=q;
    if (max<w) max=w;
    if (max<e) max=e;
    if (max<r) max=r;
    string dogfood;
    if (max==q) dogfood="Purina Pro Plan";
    if (max==w) dogfood="Pedigree";
    if (max==e) dogfood="Royal chain";
    if (max==r) dogfood="Bil-Jac";
  
  dog *c=new dog[n];
  
  for(i=0;i<n;i++){
    c[i]=d[i];
  }
  int order[n];
  for(i=0;i<n;i++){
    order[i]=d[i].age;
  }
  
  if(a==1){
    int *list1=sort(order,n);
    
    for(i=0;i<n;i++){
    cout<<d[list1[i]].dname;
  }
  }
  if(a==2)
    cout<<"The most poplular dog's food is "<<dogfood<<endl;
    
  
  if (a==3){
    lowest(d,n);
  }
  if (a==4){
    highest(d,n);
  }
  /*dog *c=new dog[n];
  
  for(i=0;i<n;i++){
    c[i]=d[i];
  }
  int order[n];
  for(i=0;i<n;i++){
    order[i]=d[i].age;
  }
  if(a==1){
    int *list1=sort(order,n);
    
    for(i=0;i<n;i++){
    cout<<d[list1[i]].dname;
  }
  }*/
  if (a==5){
    cout<<"List of vaccinated dog."<<endl;
    int m=1,p=1;
    for(i=0;i<n;i++){
      if (d[i].vaccine==1){
        cout<<m<<". "<<d[i].dname<<endl;
        m++;
      }
    }
    cout<<"List of unvaccinated dog."<<endl;
    for(i=0;i<n;i++){
      if (d[i].vaccine==0){
        cout<<p<<". "<<d[i].dname<<endl;
        p++;
      }
    }
  }
  if (a==6){
    cout<<"Number of costumer = "<<n<<endl;
    lowest(d,n);
    highest(d,n);
    int m=0,p=0;
    for(i=0;i<n;i++){
      if (d[i].vaccine==1) m++;
    }
    for(i=0;i<n;i++){
      if (d[i].vaccine==0) p++;
    }
    cout<<"Number of Vaccinated dogs = "<<m<<endl;
    cout<<"Number of Unvaccinated dogs = "<<p<<endl;
    cout<<"The most popular dog's food is "<<dogfood<<endl;
  }
  
  
}







//Tell me which dog is vaccinated or not vaccinated.
/*switch (a)
{
  case 1: break;
  case 2: break;
  case 3: lowest(d,n); break;
  case 4: break;
  case 5: break;
  default:std::cout << "default\n"; break;
}*/