#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class BinaryTreeNode{
public:
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
    T data;

    BinaryTreeNode(){
        left = nullptr;
        right = nullptr;
    }
};

template<class T>  
void create_children(BinaryTreeNode<T>* node, int index, int max_nodes){
    node->data = index;
    if(2*index+1 < max_nodes)
    {
        node->left = new BinaryTreeNode<T>();
        create_children(node->left, 2*index+1, max_nodes);
    } 
    if(2*index+2 < max_nodes)
    {
        node->right = new BinaryTreeNode<T>();
        create_children(node->right, 2*index+2, max_nodes);
    }
} 

template<class T> 
void print_tree(BinaryTreeNode<T>* node){
    cout << "Node: " << node->data << ";";
    if(node->left != nullptr) cout << "Left: " << node->left->data;
    else cout << "Left: NULL";
    cout <<  " | ";
    
    if(node->right != nullptr) cout << "Right: " << node->right->data;
    else cout << "Right: NULL";

    cout << endl;

    
    if(node->left != nullptr) print_tree(node->left);
    if(node->right != nullptr) print_tree(node->right);
}

/**
 * @brief Compare two binary trees if they are identical. 
 * Runtime Complexity: O(n)
 * Memory Complexity: O(1)
 * @tparam T 
 * @param root1 root of the first tree
 * @param root2 root of the second tree
 * @return true if they are identical, else false.
 */
template<class T>
bool compare_trees(BinaryTreeNode<T>* root1, BinaryTreeNode<T>* root2){
    bool left = true;
    if(root1->left != nullptr && root2->left != nullptr) left = compare_trees(root1->left, root2->left);
    else if(root1->left == nullptr && root2->left != nullptr ||
            root1->left != nullptr && root2->left == nullptr) return false;
    bool right = true;
    if(root1->right != nullptr && root2->right != nullptr) right = compare_trees(root1->right, root2->right);    
    else if(root1->right == nullptr && root2->right != nullptr ||
            root1->right != nullptr && root2->right == nullptr) return false;
    return root1->data == root2->data && left && right;
}
int main(int argv, char* argc[]){
  BinaryTreeNode<int>* root1 = new BinaryTreeNode<int>();
  BinaryTreeNode<int>* root2 = new BinaryTreeNode<int>();

  create_children(root1, 0, 6);
  create_children(root2, 0, 6);

  bool res = compare_trees(root1, root2);
  cout << "Trees are identical: " << (res ? "True" : "False") << endl;

}