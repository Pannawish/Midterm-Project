#include <iostream>
using namespace std;
#include "class.h"
#include "sorting.h"

int main() {
  cout << "Data collector and filtering for Pet Store." << endl;
  int n;
  cout << "Number of customers? ";
  cin >> n;
  cout << "Please fill in the information below." << endl;
  int no = 1;
  dog *d=new dog[n];

  while ((no - 1) != n) {
    cout << "#" << no << endl;
    cout << "Owner: ";
    cin >> (*(d + no - 1)).owner_name;
    cout << "Dog's Name: ";
    cin >> (*(d + no - 1)).dog_name;
    cout << "Species/Breed? ";
    cin >> (*(d + no - 1)).species;
    
    cout << "Age: ";
    cin >> (*(d + no - 1)).age;
      
    cout << "History of vaccination?\n (Yes(1) or No(0)):";
    int ans;
    cin >> ans;
    if (ans == 1) {
      (*(d + no - 1)).vaccine = 1;
    } 
    else (*(d + no - 1)).vaccine = 0;
    cout << "Which brand of dog food did the customer buy: "<< endl;
    int k;
    cout << "1. Purina Pro Plan" << endl
         << "2. Pedigree" << endl
         << "3. Royal chain" << endl
         << "4. Bil-Jac"<<endl
         << "Order: ";
    cin >> k;

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
    no++;
    cout << endl;
  }
  int i;
    int q=0,w=0,e=0,r=0;
    for (i=0;i<n;i++){ //this code will check the most popular dog's food
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
  
  for(i=0;i<n;i++){    //this loop will duplicate the pointer data
    c[i]=d[i];
  }
  int order[n];
  for(i=0;i<n;i++){
    order[i]=d[i].age;
  }
  int a;
  while(1){
  cout << "Choose what you want to do with the data " << endl;
  cout << "1. List each dog's name from youngest to oldest" << endl
       << "2. Tell the most popular dog's food" << endl
       << "3. Tell me whose dog is the youngest" << endl
       << "4. Tell me whose dog is the oldest" << endl
       << "5. List me the vaccinated dogs and unvaccinated dog" << endl
       <<"6. Tell me the average age of dog in the data list"<<endl
       << "7. Summarize all data briefly" << endl<<"8. Cancel the selection"<<endl;
  cin >> a;
  if (a==8){
    cout<<"Program terminated"<<endl;
    break;
  }
    cout<<"======================================================"<<endl;
  if(a==1){
    int *list1=sort(order,n);
    cout<<"List of dog sorted from youngest to oldest"<<endl;
    int count=1;
    for(i=0;i<n;i++){
    cout<<"#"<<count<<". "<<d[list1[i]].dog_name<<" "<<d[list1[i]].age<<" years old."<<" Owner: "<<d[list1[i]].owner_name<<endl;
      count++;
  }
  }
  if(a==2)
    cout<<"The most poplular dog food is "<<dogfood<<endl;
    
  if (a==3){
    lowest(d,n);
  }
    
  if (a==4){
    highest(d,n);
  }

  if (a==5){
    cout<<"List of vaccinated dogs."<<endl;
    int m=1,p=1;
    for(i=0;i<n;i++){
      if (d[i].vaccine==1){
        cout<<m<<". "<<d[i].dog_name<<". Owner: "<<d[i].owner_name<<endl;
        m++;
      }
    }
    cout<<"List of unvaccinated dogs."<<endl;
    for(i=0;i<n;i++){
      if (d[i].vaccine==0){
        cout<<p<<". "<<d[i].dog_name<<". Owner: "<<d[i].owner_name<<endl;
        p++;
      }
    }
  }
    int y=0; 
    float mean=0;
  if(a==6){
    for (i=0;i<n;i++){
      mean+=d[i].age;
      y++;
      }
    mean=mean/y;
    cout<<"The average age of the dogs in the data list is: "<<mean<<endl;
  }
  if (a==7){
    cout<<"Number of customers = "<<n<<endl;
    lowest(d,n);
    highest(d,n);
    for (i=0;i<n;i++){
      mean+=d[i].age;
      y++;
      }
    mean=mean/y;
    cout<<"The average age of dog in the data list is: "<<mean<<endl;
    int m=0,p=0;
    for(i=0;i<n;i++){
      if (d[i].vaccine==1) m++;
    }
    for(i=0;i<n;i++){
      if (d[i].vaccine==0) p++;
    }
    cout<<"Number of Vaccinated dogs = "<<m<<endl;
    cout<<"Number of Unvaccinated dogs = "<<p<<endl;
    cout<<"The most popular dog food is: "<<dogfood<<endl;
  }
  cout<<"======================================================"<<endl;
  cout<<endl;
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
    cout<<d[list1[i]].dog_name;
  }
  }*/

/*switch (k)
    {
      case 1: (*(d+no-1)).snack="Purina Pro Plan\n"; break; // prints "1",
      case 2: (*(d+no-1)).snack="Pedigree\n"; break; // then prints "2"
      case 3: (*(d+no-1)).snack="Royal chain\n"; break;
      case 4: (*(d+no-1)).snack="Bil-Jac\n"; break;
      default: std::cout << "unknown"; break;
    }*/