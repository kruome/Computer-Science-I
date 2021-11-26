#include <bits/stdc++.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node
{
  int score;
  string name;
  string country;
  Node *prev, *next;

  static Node *getnode (int score, string name,
			string country)
  {
    Node *newNode = (Node *) malloc (sizeof (Node));
      newNode->score = score;
      newNode->name = name;
      newNode->country = country;
      newNode->prev = newNode->next = NULL;
      return newNode;
  }
};

class Deque
{
  Node *front;
  Node *rear;
  int Size;

public:
    Deque ()
  {
    front = rear = NULL;
    Size = 0;
  }

  void insertFront (int, string, string);
  void insertRear (int, string, string);
  void deleteFront ();
  void deleteRear ();
  int getFrontscore ();
  int getRearscore ();
  string getFrontcountry ();
  string getFrontname ();
  string getRearschool ();
  string getRearcountry ();
  string getRearname ();
  int size ();
  bool isEmpty ();
  void erase ();
  int printindex(int);

};
int Deque:: printindex(int x){
    int val = -1;
    Node* temp = new Node;
    temp = front;
    for(int i = 0; i < x; i ++){
        temp=temp->next;
    }
    val = temp->score;
    return val;
}

bool
Deque::isEmpty ()
{
  return (front == NULL);
}

int
Deque::size ()
{
  return Size;
}

void
Deque::insertFront (int score, string name, string country)
{
  Node *newNode = Node::getnode (score, name, country);
  if (newNode == NULL)
    cout << "OverFlow\n";
  else
    {
      if (front == NULL)
	rear = front = newNode;

      else
	{
	  newNode->next = front;
	  front->prev = newNode;
	  front = newNode;
	}

      Size++;
    }
}

void
Deque::insertRear (int score, string name, string country)
{
  Node *newNode = Node::getnode (score, name,country);
  if (newNode == NULL)
    cout << "OverFlow\n";
  else
    {
      if (rear == NULL)
	front = rear = newNode;

      else
	{
	  newNode->prev = rear;
	  rear->next = newNode;
	  rear = newNode;
	}

      Size++;
    }
}

void
Deque::deleteFront ()
{
  if (isEmpty ())
    cout << "UnderFlow\n";

  else
    {
      Node *temp = front;
      front = front->next;

      if (front == NULL)
	rear = NULL;
      else
	front->prev = NULL;
      free (temp);

      Size--;
    }
}

void
Deque::deleteRear ()
{
  if (isEmpty ())
    cout << "UnderFlow\n";

  else
    {
      Node *temp = rear;
      rear = rear->prev;

      if (rear == NULL)
	front = NULL;
      else
	rear->next = NULL;
      free(temp);

      Size--;
    }
}

int
Deque::getFrontscore ()
{
  if (isEmpty ())
    {
      return -1;
    }
  else
    {
      return front->score;
    }
}

string
Deque::getFrontname ()
{
  if (isEmpty ())
    {
      return "Empty.";
    }
  else
    {
      return front->name;
    }
}

string
Deque::getFrontcountry ()
{
  if (isEmpty ())
    {
      return "Empty.";
    }
  else
    {
      return front->country;
    }
}

int
Deque::getRearscore ()
{
  if (isEmpty ())
    {
      return -1;
    }
  else
    {
      return rear->score;
    }
}

string
Deque::getRearname ()
{
  if (isEmpty ())
    {
      return "Empty.";
    }
  else
    {
      return rear->name;
    }
}

string
Deque::getRearcountry ()
{
  if (isEmpty ())
    {
      return "Empty.";
    }
  else
    {
      return rear->country;
    }
}
void
Deque::erase ()
{
  rear = NULL;
  while (front != NULL)
    {
      Node *temp = front;
      front = front->next;
      free (temp);
    }
  Size = 0;
}
int interpolation_search (Deque p, int value, int size)
{
  int low = 0;
  int high = size-1;
  int mid = -1;
  
  int l = p.getFrontscore();
  int h = p.getRearscore();
 while (low <= high && value >= p.printindex(low) && value <= p.printindex(high))
  {
     if (low == high)
     {
         if(p.printindex(low)==value)
         {
             return low;
         }else
         {
            return -1;
         }
    }else{
    mid = low +  (((high - low) / (p.printindex(high) - p.printindex(low))) * (value - p.printindex(low)));
    if (p.printindex(mid) < value)
    {
      low = mid+1;
    }
    else if (p.printindex(mid)> value)
    {
      high = mid-1;
    }
    else if(p.printindex(mid)==value)
    {
      return mid;
    }
   }
  }
}

int
main ()
{
  Deque scollection;
  
  scollection.insertRear (100, "A", "USA");
  scollection.insertRear (200, "B", "USA");
  scollection.insertRear (300, "C", "USA");
  scollection.insertRear (400, "D", "USA");
  scollection.insertRear (500, "D", "USA");
  scollection.insertRear (600, "D", "USA");
  scollection.insertRear (700, "D", "USA");
  scollection.insertRear (800, "D", "USA");


cout<<"The index of the requested value is at " << interpolation_search(scollection,100,8) << endl;
cout<<"The index of the requested value is at " << interpolation_search(scollection,200,8) << endl;
cout<<"The index of the requested value is at " << interpolation_search(scollection,300,8) << endl;
cout<<"The index of the requested value is at " << interpolation_search(scollection,400,8) << endl;
cout<<"The index of the requested value is at " << interpolation_search(scollection,500,8) << endl;
cout<<"The index of the requested value is at " << interpolation_search(scollection,600,8) << endl;


}