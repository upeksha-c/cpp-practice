#include <iostream>

using namespace std;

class Node
{
public:
  Node(int val);
  int value;
  Node* next;
};

class List
{
public:
  List();
  void push_front(int value);
  bool pop_front(int &value);
  void push_back(int value);
  bool pop_back(int &value);
  int  at(int index);
  void insert_at(int index, int value);
  void remove_at(int index);
  int size();
private:
  // other members you may have used
  Node* head;
  Node* tail;
};

// ...
void printList(List &list)
{
  for (int i = 0; i < list.size(); i++)
  {
    cout << "list[" << i << "] == " << list.at(i) << endl;
  }
}

int main()
{
  List list;
  //
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  printList(list);
  cout << endl;

  list.remove_at(2);
  printList(list);
  cout << endl;

  list.insert_at(1, 6);
  printList(list);

  return 0;
}