// An empty list:
//
//  Node*
// +------+
// | head |-->nullptr
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
//
#include <iostream>

using namespace std;

class Node
{
public:
  Node(int val);
  int value;
  ~Node();
  Node* next;
};

Node::Node(int val) : value(val), next(nullptr)
{
    cout << "+Node" << endl;
}

Node::~Node()
{
  cout << "-Node" << endl;
}

class List
{
public:
  List();
  void push_front(int value);
  bool pop_front(int &value);
  ~List();
private:
  Node* head;
};

List::
List::List() : head(nullptr)
{
}

void List::push_front(int value)
{
  Node* new_head = new Node(value);
  new_head->next = head;
  head=new_head;
}

// START
// +------+   +-----+      +-----+
// | head |-->|  X  |  +-->|  Y  |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//
// STEP 1
//
//            +------+
//            |popped|
//            +------+
//               |
//               V
// +------+   +-----+      +-----+
// | head |-->|  X  |  +-->|  Y  |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//
// STEP 2
// +------+
// | head |-------------------+
// +------+                   |
//                            V
// +------+   +-----+      +-----+
// |popped|-->|  X  |  +-->|  Y  |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//
// STEP 3
// returned = popped->value;
// delete popped;
// +------+   +-----+
// | head |-->|  Y  |
// +------+   +-----+
//            |next |-->nullptr
//            +-----+
List::~List(){
    while(head != nullptr){
        Node* removing = head;
        head = removing->next;
        delete removing;
    }
}
bool List::pop_front(int &value)
{
  // implement the pop
  Node* pop = head;
    if (pop == nullptr)
    {
        return false;
    } else{
        head = pop->next;
        value = pop->value;
        delete pop;
        return true;

    }
  // don't forget to delete the popped node!
  // and fix the return value
  return false;
}

int main()
{
  List list;
  //
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  return 0;
}