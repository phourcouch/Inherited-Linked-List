//CS311 Yoshii F23 llist.h
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW3P1 llist
// Your name: Kayla Le
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;  // int for now but can change later

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 public://used to be private
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes

  // untility function to move to a specified node position
   void moveTo(int, Node*&);
  
// public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //return true if front and rear are both pointing to null and count is 0
  bool isEmpty();
    
  //display each element of the list starting front front enxlosed in [] follwed by endl
  void displayAll();

  //adding a node at the front
  void addFront(el_t);
    
  //adding a node at the rear 
  void addRear(el_t);

  //deleting the front node
  void deleteFront(el_t&);
  
    
  //deleting the rear node
  void deleteRear(el_t&);

  //---------------------------------------


  //delete the ith node, if only one element call deletefront or deleterear, if illegal value it throws an exception, the paramters is a int for the position (ith) and
  //el_t is the element at the ith position 
  void deleteIth(int, el_t&);  // calls moveTo

  //insert an element into the list , illegel value = throw exception, special case
  //call addFront or addRear function, paramter -> int is the position and el_t is
  //the new element 
  void insertIth(int, el_t);   // calls moveTo

  //Copy Constructor to allow pass by value and return by value of a llist
  llist(const llist&);
  
  //Overloading of = (returns a reference to a llist)
  llist& operator=(const llist&); 

};
