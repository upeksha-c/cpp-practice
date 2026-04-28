// An empty list:
//
//  Node*
// +------+
// | head |-->nullptr
// +------+
//
//  Node*
// +------+
// | tail |-->nullptr
// +------+
//
//
//
// A list with two elements:
//
//  Node*      Node         Node
// +------+   +-----+      +-----+
// | head |-->|value|  +-->|value|
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//                           ^
// +------+                  |
// | tail |------------------+
// +------+
#include <iostream>

using namespace std;

class Node
{
public:
  Node(int val);
  int value;
  Node* next;
};

Node::Node(int val) : value(val), next(nullptr)
{
}

class List
{
public:
  List();
  void push_front(int value);
  bool pop_front(int &value);
  void push_back(int value);
  int size();
private:
  // other members you may have used
  Node* head;
  Node* tail;
  size_t size_list;
};

List::List() : head(nullptr), tail(nullptr), size_list(0)
{
}

void List::push_front(int value)
{
  // You need to fix this part!
  // The tail pointer needs to be modified only when the first element is added
  Node* new_head = new Node(value);
  new_head->next = head;
  head=new_head;
  size_list++;
}

// All of your previously written methods may require a little fixing

// START
// +------+   +-----+      +-----+
// | head |-->|  X  |  +-->|  Y  |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//                           ^
// +------+                  |
// | tail |------------------+
// +------+
//
// STEP 1
//                                            new Node
// +------+   +-----+      +-----+             +-----+
// | head |-->|  X  |  +-->|  Y  |             |  Z  |
// +------+   +-----+  |   +-----+             +-----+
//            |next |--+   |next |-->nullptr   |next |-->nullptr
//            +-----+      +-----+             +-----+
//                           ^
// +------+                  |
// | tail |------------------+
// +------+
//
// STEP 2
//
// +------+   +-----+      +-----+       +-----+
// | head |-->|  X  |  +-->|  Y  |   +-->|  Z  |
// +------+   +-----+  |   +-----+   |   +-----+
//            |next |--+   |next |--+    |next |-->nullptr
//            +-----+      +-----+       +-----+
//                           ^
// +------+                  |
// | tail |------------------+
// +------+
//
// STEP 3
// +------+   +-----+      +-----+       +-----+
// | head |-->|  X  |  +-->|  Y  |   +-->|  Z  |
// +------+   +-----+  |   +-----+   |   +-----+
//            |next |--+   |next |--+    |next |-->nullptr
//            +-----+      +-----+       +-----+
//                                          ^
// +------+                                 |
// | tail |---------------------------------+
// +------+
void List::push_back(int value)
{
  // implement me!
  Node* new_tail = new Node(value);
  if( tail == nullptr){      
      head = tail = new_tail;
      size_list++;
  } else {
      tail->next = new_tail;
      tail = new_tail;
      size_list++;
  }
}

bool List:: pop_front(int &value){
    if(head == nullptr){
        return false;
    } else {
        Node* current_head = head;
        head = current_head->next;
        value = current_head->value;
        delete current_head;
        size_list--;

        if (head == nullptr){
            tail = nullptr;
        }
        return true;
    }
 
    

}
int main()
{
  List list;
  //
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);

  int value = 0;
  while (list.pop_front(value))
  {
    cout << value << endl;
  }
  return 0;
}