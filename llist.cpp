//CS311 Yoshii F23 Linked List class

//INSTRUCTION:
//Must use the provided HW3P1_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//  You can copy from a Word document to emacs (contrl-right click)
//  Highly recommended to copy HW3P1-help as PURPOSE of each function.
//
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//  NEVER delete my comments!!!!
//EMACS HINT:
//  cntr-K cuts and cntr-Y pastes. 
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: Kayla Le
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{ Front = Rear = NULL;//point Front and Rear to null when a list is made
  Count = 0;//set Count to 0 since list is empty when made

 cout << "... in llist constructor..." << endl; }

llist::~llist()
{ 
while(Front != NULL){//loop while Front is not null
 deleteFront(Front->Elem);//delete Front and pass the elem field of it
}

 cout << ".... in llist destructor..." << endl; }

//PURPOSE: returns true if front and rear are both pointing to NULL and count is 0
//PARAMETER: no paramters
bool llist::isEmpty() {
 if(Rear == NULL && Front == NULL && Count == 0){//if front and rear are null and count is 0, the list is empty - return true
	return true;
  }
 return false;//otherwise return false

 } // be sure to check all 3 data members

//PURPOSE: display each element of the list starting from front enclosed in []
//followed bu ends
//PARAMETER: no parameters
void llist::displayAll() {

Node *P= this->Front;//temp pointer at starting at the front
cout << "[";

if(!isEmpty()){//if list is not empty then loop through list to display elements of current pointer 
  while(P != NULL){//loop while the temp pointer is not null
     cout << " " <<  P->Elem;//print out element of current node
     P = P->Next;//increment the node to the next one
   }
}
else{
  cout << " empty ";//if list is empty print out empty enclosed in []
}
cout << "]" << endl;
 }  // be sure to display horizontally in [  ] with
// blanks between elements e.g. [ 1 2 3 4]
// You MUST use while (P != NULL) loop or you will not get the credit!
  
//PURPOSE:add a new node at the rear and puts newNum in the elem field of new node
//code is updated
//PARAMETER: the new element that is being added to the elem field of the new  Rear node
void llist::addRear(el_t NewNum) {

if(isEmpty()){//special case -> it is going to be first node
  Node *P = new Node;//new node
  Front = P;//make front point to it
  Rear = P;//make rear point to it
  P->Elem = NewNum;//put newnum in the elem field of new node
  Count++;//count updated
  Rear->Next = NULL;//making sure Rear->Next is NULL
}
else {//regular case - not going to be first node
 Rear->Next = new Node;//add new node at the rear
 Rear = Rear->Next;//move rear since you added a node at the next of rear
 Rear->Elem = NewNum;//put newnum in the elem field of the new rear
 Rear->Next = NULL;//make sure rear->next is null
 Count++;//update count
}

 } // speical case: if its the first node, 
//create new node and make front and rear point to it. put newNum in elem field of this new node
//regular case: add new node at rear and put newNum in elem field of this new node

//PURPOSE: add a new node at the front
//PARAMETER: el_t NewNum is the value of the new node  being passed
void llist::addFront(el_t NewNum) {

     if(isEmpty()){//special case 
	Node *P = new Node;//new node 
        Front = P;//point front to new node
	Rear = P;//point rear to new node
	P->Elem = NewNum;//put newnum in elem field of new node
	Count++;//update count
	Rear->Next = NULL;//make sure new Rear next is null
	
   }
else {//regular case
  Node *P = new Node;//new node
  P->Next = Front;//add the new  node at the front
  Front = P;//move front to new front
  P->Elem = NewNum;;//put newnum in the elem field of new node
  Count++;//update count
}


 } //special case: if it is the only node in list
//regular case: not the only node

//PURPOSE:delete front node
//PARAMETER:passing by refernce the element of the old node
void llist::deleteFront(el_t& OldNum) {
  
  

 if(isEmpty()){//error case
    throw Underflow();//error case -> if list is empty throw an exeption
}
  if(Count == 1 ){//speical case -> removing only element in list
    OldNum = Front->Elem;//give back front element through OldNum
    delete Front;//delete cell
    Rear = NULL;//make sure rear is null
    Front = NULL;//make sure Front is NULL
    Count--;//update count  

  } else {//regualr case
    OldNum = Front->Elem;//give back front node through OldNUm
     Node *Second;//pointer that  points to new front after delete (front->Next)
     Second = Front->Next;//make second point to new front
     delete Front;//delete cell at front
     Front = Second;//point front to second- new front
     Count--;//update count
}                       
     


 } // error case : if list is empty 
//special case if count is 1
//regular case -> there is more than one element in list

//PURPOSE:delete rear node
//PARAMETER:give back rear node element through OldNum (pass by ref)
void llist::deleteRear(el_t& OldNum){
  if(isEmpty())//error case
  throw Underflow();

if(Count == 1){//special case
  OldNum = Rear->Elem;//give back the element of Rear
  delete Rear;//delete cell
  Front = NULL;//make sure front is null
  Rear = NULL;//make sure rear is null
  Count--;//update count
}
else{//egualr case
   OldNum = Rear->Elem;//give back rear node element 
   Node *P = Front;//pointer to get node before rear
 
 while(P->Next != Rear){//stop when P  is pointing  to ndoe before rear
     P = P->Next;//if not node before rear point to next node
  }
//now P  is pointing to node before rear (new rear) 
delete Rear;//remove rear cell
Rear = P;//make rear point to ndoe before it(new rear)
Rear->Next = NULL;//make sure rear-> next is null
Count--;//update count
}


} //error case -> if empty throw exception
//special case -> if there is only one node in lsit
//regualr case -> more than 1 node in list



/* --- harder ones for case 2 and 3 follow -- */

// Utility Function to move a local pointer to the Jth node
void llist::moveTo(int J, Node*& temp)
{ // moves temp J-1 times to go to the Jth node  
  // for ( int K = ... ) temp = temp->Next; 
 for(int K = 0; K < J -1;K++){
  temp = temp->Next;//increment local  pointer 

}
}

//PURPOSE:delete the node at hthe ith place
//PARAMETER:int I for position and Odnum is pass back the element deleted 
void llist::deleteIth(int I, el_t& OldNum) {

 if(I > Count || I < 1)//error case - out of bounds
  throw OutOfRange();

if(I == 1){//special case - deleting at Front 
  OldNum = Front->Elem;//store front elemenet into OldNum
  deleteFront(OldNum);//delete Front and pass the element of it
}else if(I == Count){//speical case - delete Rear
 OldNum = Rear->Elem;//store rear element into oldNUm
  deleteRear(OldNum);//delete rear passing it slemeent 
}
else{//regular case

Node *temp = Front; //node to get Ith node

moveTo(I,temp);//bring back Ith node

Node *afterNode = temp->Next;//afterNOde point to node after Ith node ( I + 1);
OldNum = temp->Elem;//give back Ith node element to  OldNUm

Node *beforeNode = Front;//node used to get the ndoe beofre the Ith node

for(int i = 0;i < I - 2;i++)
 beforeNode = beforeNode->Next;//have pointer point to Ith -1 node
 
 //now beforeNode pointing to Ith - 1 node
beforeNode->Next = afterNode;//make Ith -1 node pointer to the ith + 1 node

delete temp;//delete cell at Ith node
Count--;//count is updated
}

 } // must use moveTo to move local pointers. Be sure to comment to which node you are moving them. Do not forget to set OldNum.  

//PURPOSE:
//PARAMETER:
void llist::insertIth(int I, el_t newNum) {


if(I > Count+1 || I < 1)//error case - out of bounds
  throw OutOfRange();

if(I == 1){//special case - deleting at Front
  addFront(newNum);//add front and pass newNum
}else if(I == Count+1){//speical case - delete Rear
  addRear(newNum);//add rear and pass newNum
}
else{//regular case

Node *temp = Front;//pointer that holds the node at the Ith position
 moveTo(I,temp);//move pointer to ith node

Node *beforeNode = Front;//pointer used to point to the ith -1 node

for(int i = 0;i < I - 2;i++)
 beforeNode = beforeNode->Next;//have pointer point to Ith -1 node

beforeNode->Next = new Node;//I - 1 node next is pointing to a new Node
beforeNode->Next->Elem = newNum;//put newNum into the new node's elem field
beforeNode->Next->Next = temp;//the new node's next points to the node at the ith position before inserting new node


Count++;//update count
}



 } // must use moveTo to move local pointers. Be sure to comment to which node you are moving them.

//PURPOSE: make the this->list as a copy of Original list
//PARAMETER:original list being passed by refernce 
llist::llist(const llist& Original) {

 Front = NULL; Rear = NULL; Count = 0;//this data members need to be initialized first

el_t x;//used for to pass a value for delete Rear

 if(&Original != this)//if not the same
{

   while(!this->isEmpty())//emptying this->object
     this->deleteRear(x);//deleting rear and passing a int

Node *P;//local pointer for Original

P = Original.Front;//make pointer point to front of original one

while(P != NULL)//loop through original list
{
 this->addRear(P->Elem);//add the  node P is pointing to's elem  to this->rear
 P = P->Next;//incerment pointer to next node
}

}//end of if
 

 } // use my code

//PURPOSE: make a list equal to other list via operator =
//PARAMETER:passing the otherlist 
llist& llist::operator=(const llist& OtherOne) {
 el_t x;//used for to pass a value for delete Rear
 
 if(&OtherOne != this)//if not the same
{

   while(!this->isEmpty())//emptying this->object
     this->deleteRear(x);

Node *P;//local pointer for OtherOne

P = OtherOne.Front;//make pointer point to front of other one

while(P != NULL)
{ 
 this->addRear(P->Elem);//add current otherOne node to this->rear
 P = P->Next;//incerment pointer to next node
}

}//end of if

return *this;
 } // use my code

