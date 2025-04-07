//Final Exam - Dynamic Link List Menu
//CIS-277-602HY
//Eishner Sibug

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string.h>
using namespace std;


struct Node{
  string fname;
  string lname;
  int birth_year;
  int number;
  Node *nxt;
};

typedef struct Node *ptr;

void display_menu(){
  cout<<"\n--SCOUTING LIST 2022--\nPlease input the corresponding number to execute: " 
      <<"\n1. Create List"
      <<"\n2. Add a Player"
      <<"\n3. Delete a Player"
      <<"\n4. Modify a Player"
      <<"\n5. Purge List"
      <<"\n6. Search Player"
      <<"\n7. Display List"
      <<"\n8. EXIT"<<endl; 
  return;
}

void menu_selection(int &selection){
  cin>>selection;
  return;
}

void menu_validation(int selection){
  while (selection < 1 || selection > 8){
    cout<<"**ERROR** Option not valid...Please Try Again"<<endl;
    cout<<"\n\nWelcome to Dynamic Link List! Please input the corresponding number to execute: "; 
    cout<<"\n1. Create Link List"
        <<"\n2. Add a Player"
        <<"\n3. Delete a Player"
        <<"\n4. Modify a Player"
        <<"\n5. Purge List"
        <<"\n6. Search Player"
        <<"\n7. Display List"
        <<"\n8.EXIT"<<endl; 
        cin>>selection;
    return;
    }
}

bool isEmpty(ptr start){
    if(start == NULL)
        return true;
    else 
        return false;    
}
 
void CreateLL(ptr &start){
    if (isEmpty(start) == true){
        start = new Node;
        start->nxt = NULL;
        cout<<"Linked List Created!"<<endl;
        return;
      }
    else{  
      cout<<"**Linked List already created, please choose another selection**"<<endl;
      return;
      }
  return;
} 
void NewPlayer(ptr &start, ptr &newPlayer){
  if (isEmpty(start) == true){
    cout<<"\n**ERROR:Create a List first**\n";
    return;
    }
  else{
    cout<<"***Adding Player Info:***"<<endl;
    cout<<"\nEnter Jersey Number:";
    cin>>newPlayer->number;
    cout<<"\nFirst Name: ";
    cin>>newPlayer->fname;
    cout<<"\nLast Name: ";
    cin>>newPlayer->lname;
    cout<<"\nBirth Year: ";
    cin>>newPlayer->birth_year;
    newPlayer->nxt = NULL;
    return;
    }
}
void AddPlayer(ptr &start, ptr &nplayer, ptr &temp1, ptr &temp2, ptr &temp3){
  if (isEmpty(start) == true){
    return;
    }
  else{
    temp1 = start;
    temp2 = start->nxt;
    if (nplayer->number < temp1->number){
      nplayer->nxt = temp1;
      temp1->nxt = temp2; 
      start = nplayer;
      cout<<"\n***Player Added to List!***\n"<<endl;
      return;
    }
    while (temp1 != NULL){
      if (nplayer->number == temp1->number){
        cout<<"\n***************************"
            <<"\n**Jersey Number already exists**\n--Please assign different number--"<<endl
            <<"******************************"<<endl;
        break;
      }
      if (temp2 == NULL && nplayer->number > temp1->number){
        temp1->nxt = nplayer;
        cout<<"\n***Player Added to List!***\n"<<endl;
        break;
      }
      if(nplayer->number > temp1->number && nplayer->number < temp2->number){
        temp3 = temp2;
        temp1->nxt=nplayer;
        nplayer->nxt=temp3;
        cout<<"\n***Player Added to List!***\n"<<endl;
        break;
      }
      temp1 = temp2; 
      temp2=temp2->nxt;
    }
  }
}

void Delete(ptr &start, ptr &temp1, ptr &temp2, ptr &temp3, int &jersey){
  if (isEmpty(start) == true){
    cout<<"\n**ERROR:Create a List first**\n";
    return;
    }
  else
    temp1 = start;
    temp2 = start->nxt;
    cout<<"\nPlease Enter the jersey # of the player you want to delete:"<<endl;
    cin>>jersey;
    if(temp1->number == jersey && temp1->nxt == NULL){
      start = temp2;
      delete temp1;
      start = new Node; 
      cout<<"***Player deleted from List!***"<<endl;
      return;
      }
    while (temp1 != NULL){
      if(temp2 == NULL && jersey != temp1->number){
        cout<<"***ERROR: Player Not Found***"<<endl;
        return;
        }
      if(temp1->number == jersey && temp2 != NULL){
        temp3 = temp2;
        delete temp1;
        cout<<"***Player deleted from List***"<<endl;
        start = temp3;
        return;
        }
      if(temp2->number == jersey){
        temp1->nxt = temp2->nxt;
        delete temp2;
        cout<<"***Player deleted from List***"<<endl;
        return;
        }
      temp1 = temp2;
      temp2 = temp2->nxt;
    }
}

void Modify(ptr &start, ptr &temp1, ptr &temp2){
  if (isEmpty(start) == true){
    cout<<"\n**ERROR:Create a List first**\n";
    return;
    }
  else{
    temp1 = start;
    temp2 = start->nxt;
    int target;
    cout<<"\nEnter the Jersey Number you want to modify:"<<endl;
    cin>>target;
    while(temp2->nxt != NULL){
      temp1 = temp2;
      temp2=temp2->nxt; 
      if(target==temp1->number){
        cout<<"\n***Jersey Found! Previous player info: "<<endl;
        cout<< "\n#"<<temp1->number
            <<"\n"<<temp1->fname<<" "<<temp1->lname
            <<"\n"<<temp1->birth_year
            <<"\n\n***Modify Number to:***"<<endl;
        cout<<"\nFirst Name: ";
        cin>>temp1->fname;
        cout<<"\nLast Name: ";
        cin>>temp1->lname;
        cout<<"\nBirth Year: ";
        cin>>temp1->birth_year;
        cout<<"\n************Info Changed to***************\n"
            << "\n#"<<temp1->number
            <<"\n"<<temp1->fname<<" "<<temp1->lname
            <<"\n"<<temp1->birth_year<<endl
            <<"********************************************\n";
        return;  
      }
    }
    cout<<"\n**Player not Found**\n"<<endl;
  }
  return;
}

void Purge(ptr &start){
  if (isEmpty(start) == true){
    cout<<"\n**ERROR:Create a List first**\n";
    return;
  }
  else{
    while (start->nxt != NULL){
      ptr temp = start;
      start = start->nxt;
      delete temp;
      }
    cout<<"\n**List has been deleted!**\n"<<endl;
    }
  
  return;
}

void Search(ptr &start, ptr &temp1, ptr &temp2){
  if (isEmpty(start) == true){
    cout<<"\n**ERROR:Create a List first**\n";
    return;
    }
  else{
    temp1 = start;
    temp2 = start->nxt;
    int target;
    cout<<"\nEnter the Jersey Number you want to Search:"<<endl;
    cin>>target;
    while(temp2->nxt != NULL){
      temp1 = temp2;
      temp2=temp2->nxt; 
      if(target==temp1->number){
        cout<<"\n***Jersey Found! Previous player info:*** "<<endl;
        cout<< "\n#"<<temp1->number
            <<"\n"<<temp1->fname<<" "<<temp1->lname
            <<"\n"<<temp1->birth_year<<endl;
        return;
      }
    }
      cout<<"\n**Player not Found***"<<endl;
  }
}
      

void Display_list(ptr &start, ptr &temp1){
 if (isEmpty(start) == true){
    cout<<"\n**ERROR:Create a List first**\n";
    return;
  }
  else{
    temp1 = start->nxt;
    while(temp1 != NULL){
      cout<<"\n-------------------------------------------------------------------------"
          <<"\n#"<<temp1->number<<endl
          <<temp1->fname<<" "<<temp1->lname<<endl
          <<temp1->birth_year<<endl<<""
          <<"-------------------------------------------------------------------------\n";
      temp1=temp1->nxt;
    } 
  }
  return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {

int select,target,birthyear;
ptr start=NULL;
ptr temp1, temp2, temp3, current, newplayer;
  
do{
  display_menu();
  menu_selection(select);
  menu_validation(select);
  switch(select){
    case 1:{          
      CreateLL(start);
      break;
      } 
    case 2:{          //Add a Node
      newplayer = new Node;
      NewPlayer(start, newplayer);
      AddPlayer(start, newplayer, temp1, temp2, temp3);
      break;
      }
    case 3:{          //Delete a Node
      Delete(start, temp1, temp2, temp3, target);
      break;
      }
    case 4:{          //Modify a Node
      Modify(start, temp1, temp2);
      break;
      }  
    case 5:{          //Purge List
      Purge(start);
      break;
      }
    case 6:{          //Search Player
      Search(start, temp1, temp2);
      break;
    }
    case 7:{          //Display List
      Display_list(start, temp1);
      break;
    }
    case 8:{
      cout<<"\n**Scouting List Terminated**";
      exit(0);
      break;
    }
  }
}while(select != 8);     

return 0;
}

