#include <cstdlib>
#include <iostream>

using namespace std;

template<class T>
class LinkedListNode {

public:
  LinkedListNode* next_ptr;
  T key;
  LinkedListNode(){
    next_ptr = nullptr;
  }

  ~LinkedListNode(){}
};


/**
 * @brief Search and delete the element of a linked list with a given key. 
 * Runtime Complexity:O(n)
 * Memory Complexity: O(1)
 * @param head the head of the linked list.
 * @param key the key we want to delete.
 * @return LinkedListNode* head, the "new" head of the linked list. 
 */
template<class T>
LinkedListNode<T>* delete_element(LinkedListNode<T>* head, T key){
  if(head == nullptr) return nullptr;

  LinkedListNode<T>* it = head;
  LinkedListNode<T>* prev = nullptr;
  do{
    if (it->key == key)
    {
      // Delete the very first element if the list contains the key at the head.
      if(prev == nullptr) return it->next_ptr;
      else{
        // Else if it is not the head element, connect the previous node with 
        // the next node and delete the current node
        prev->next_ptr = it->next_ptr;
        delete it;
        return head;
      }
    }
    prev = it;
    it = prev->next_ptr;
  }while(it->next_ptr != nullptr);

  return head;  
}

template<class T>
void print_list(LinkedListNode<T>* head){
  cout << "List keys: { ";
  LinkedListNode<T>* it = head;
  while(true){
    cout << it->key;
    if(it->next_ptr == nullptr) break;
    else cout << ", ";
    it = it->next_ptr;
  }
  cout << "}" << endl;
}

int main(int argv, char* argc[]){
  LinkedListNode<int>* head = new LinkedListNode<int>();
  LinkedListNode<int>* it = head;
  int nextkey = 0;
  while (true){
    it->key = nextkey;
    ++nextkey;
    if(nextkey < 10){ 
      it->next_ptr = new LinkedListNode<int>();
      it = it->next_ptr;
    }
    else break;
  }
  cout << "Created List" << endl;
  print_list(head);

  head = delete_element(head, 5);

  print_list(head);
}