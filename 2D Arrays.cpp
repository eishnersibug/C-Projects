//Name: Eishner Sibug
//CIS-265 C++ Adv Programming Conc. 
//Last Update: February 11, 2022
//Description: 


#include <cmath.h>
#include <iostream.h>
#include <iomanip.h>
using namespace std;

const int R = 3;
const int C = 4;

void populate(int Ar[][4]){
  for (int i=0; i<R;i++){
    for (int j = 0; j < C ; j++){
      cout<<"Please enter an integer"<<endl;
      cin>>Ar[i][j];
    }
  }
}

void populate_valid (int Ar[][4]){
  for (int i=0; i<R;i++){
   for (int j = 0; j < C ; j++){
     while (Ar[i][j]<-100 || Ar[i][j]>100){
      cout<<"**ERROR** Range allowed: -20 to 100..Please restart the program "<<endl;
      exit(0);
      }
    }
  }
}

int input_selection(int &selection){
  cin>>selection;
  return selection;
}

void list(string){
  cout<<"\n**********************"<<endl
        <<"\n***Select what you like done to the Array***\n"
        <<"\n1. Display the SUM of all POSITIVE numbers in the Array"
        <<"\n2. Display the SUM of all NEGATIVE numbers in the Array"
        <<"\n3. Display all of the POSITIVE numbers in the Array"
        <<"\n4. Display all of the NEGATIVE numbers in the Array"
        <<"\n5. How many POSITIVE numbers are there in the Array?"
        <<"\n6. How many NEGATIVE numbers are there in the Array?"
        <<"\n7. SUM of each ROW"
        <<"\n8. SUM of each COLUMN"
        <<"\n9. EXIT\n";
}
void valid_selection(int &selection){
  while (selection < 1 || selection > 10){
    cout<<"/n**ERROR** Option not valid\n"
        <<"\n***Select what you like done to the Array***\n"
        <<"\n1. Display the SUM of all POSITIVE numbers in the Array"
        <<"\n2. Display the SUM of all NEGATIVE numbers in the Array"
        <<"\n3. Display all of the POSITIVE numbers in the Array"
        <<"\n4. Display all of the NEGATIVE numbers in the Array"
        <<"\n5. How many POSITIVE numbers are there in the Array?"
        <<"\n6. How many NEGATIVE numbers are there in the Array?"
        <<"\n7. SUM of each ROW"
        <<"\n8. SUM of each COLUMN"
        <<"\n9. EXIT\n";
        cin>>selection;
  }
}


int SumP(int Ar[][4], int SUM){ 
  for (int i = 0; i < R;i++){
   for (int j = 0; j < C ; j++){
     while (Ar[i][j]< 100 || Ar[i][j] > 0){
      SUM += Ar[i][j];
      }
    }
  }
return SUM;
}

int SumN(int Ar[][4], int SUM){
  for (int i=0; i<R;i++){
   for (int j = 0; j < C ; j++){
     if (Ar[i][j]< 0|| Ar[i][j]>-100){
      SUM += Ar[i][j];
      }
    }
  }
  return SUM;
  }

  
int main() {
int total, select,large,small, nums[R][C];
string menu;
  
populate(nums);
populate_valid(nums);
list(menu);
input_selection(select);
valid_selection(select);

switch(select){
  case 1:{
  total = 0;
  SumP(nums, total); 
  cout<<"The SUM of All POSITIVE Elements = "<<total<<endl;
  break;
  }
  case 2:{
  total = 0;
  SumN(nums, total);
  cout<<"The SUM of All NEGATIVE Elements = "<<total<<endl;
  break;
  }
  case 3:{
    
  }
  
    
}


}