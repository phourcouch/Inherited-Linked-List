// CS311 Yoshii F23 slist.cpp
// Complete all functions with their comments
// NEVER delete my comments!!
// ====================================================
//HW#: HW3P1 slist  inheriting from llist
//Your name: **
//Complier:  g++
//File type: slist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 
// ** Make sure llist constructor and destructors have couts in them

// do not change this one
slist::slist()
{ cout << "slist constructor: " << endl;}



// positions always start at 1
//PURPOSE: search through the list to see if any node contains key
//PARAMETERS: key is being passed in order to check if it is found in list
int slist::search(el_t key){

int returnInt = 0;//used for returning
int count = 1;//used to keep track of position

Node *P = Front;//have a temp pointer point to Front of llist

while(P != NULL){//loop until end of list

if(P->Elem == key)
  returnInt = count;//if the pointer's element is equal to the key, make returning
//value the count

P = P->Next;//increment pointer 
 count++;//incerment current position/counter
}


 return returnInt;//returning the position the key was found in
}

// don't forget to throw OutOfRange for bad pos 
// You must use moveTo to go to the pos
void slist::replace(el_t element, int pos){

if(pos > Count || pos < 1)//error case - out of bounds
 throw  OutOfRange();

 Node *temp = Front;//temp node used to get Ith node
  moveTo(pos,temp);//use pos for I in moveTo and temp to get the Ith node
 
 //now temp is pointing to Ith node 
 temp->Elem = element;//replace Ith node's Elem with element 

}
bool slist::operator==(const slist& OtherOne){
  // if not the same length, return false immediately
  // if the same lengths,
 //       check each node to see if the elements are the same
if(Count != OtherOne.Count)//if not same length, return false
 return false;
else{
  Node *P = Front;//pointer for this->
  Node *Q = OtherOne.Front;//pointer for otherOne

   for(int i = 0;i < Count;i++){//loop until count/size of list
     if(P->Elem != Q->Elem)//if this-element is not the same of the other point elemenet then returm false
        return false;

   P = P->Next;//increment ptr
   Q  = Q->Next;//increment ptr
}
 return true;//return true if all of the elements are a match and the count is the same
  }
}



