#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

template <class T>
class LinkedListNode
{
public:
  T key;
  LinkedListNode *next_ptr;
  LinkedListNode *arbitrary_ptr;

  LinkedListNode()
  {
    next_ptr = nullptr;
    arbitrary_ptr = nullptr;
  }

  ~LinkedListNode() {}
};

template<class T>
void print_list(LinkedListNode<T>* head, string name){
  LinkedListNode<T>* it = head;
  cout << "List " << name << endl << "=======" << endl;
  while (it != nullptr)
  {
    cout << "( My adress: " << it <<"; Key: " << it->key << "; next: " << it->next_ptr << "; arb_ptr: " << it->arbitrary_ptr <<  " )" << endl;
    it = it->next_ptr;
  }
  cout << "=======" << endl;
  
}

/**
 * @brief 
 * 
 * @tparam T Generic Type T
 * @param head Pointer to the head node
 */
template<class T>
LinkedListNode<T>* deep_cpy(LinkedListNode<T>* head){
  LinkedListNode<T>* it = head;
  LinkedListNode<T>* new_head = new LinkedListNode<T>();
  
  LinkedListNode<T>* it_new = new_head;

  unordered_map< LinkedListNode<T>*, LinkedListNode<T>* > map;
  while(true){

    it_new->key = it->key;
    it_new->arbitrary_ptr = it->arbitrary_ptr;
    map[it] = it_new;
    it = it->next_ptr;

    if(it != nullptr){
      it_new->next_ptr = new LinkedListNode<T>();
      it_new = it_new->next_ptr;
    }
    else break;
    
  }
  
  it_new = new_head;
  while(it_new != nullptr){
    it_new->arbitrary_ptr = map[it_new->arbitrary_ptr];
    it_new = it_new->next_ptr;
  }
  return new_head;
}

int main(int argv, char *argc[])
{
  LinkedListNode<int> *head = new LinkedListNode<int>();

  // Create a linked list
  LinkedListNode<int> *it = head;
  vector<LinkedListNode<int> *> node_tracker;
  node_tracker.push_back(it);
  int size = 5;
  int next_key = 0;
  while (true)
  {
    it->key = next_key;
    ++next_key;
    if (next_key < size)
    {
      it->next_ptr = new LinkedListNode<int>();
      it = it->next_ptr;

      node_tracker.push_back(it);
    }
    else
      break;
  }

  srand(1);
  for(int i = 0; i < size; ++i){

    int rand_val = rand() % size;
    node_tracker[i]->arbitrary_ptr = node_tracker[rand_val];
  }

  print_list(head, "original");

  // Solve the problem.
  // Given: head
  LinkedListNode<int>* cpy = deep_cpy(head);
  print_list(cpy, "copy");
}