#include <cstdlib>
#include <iostream>

using namespace std;

template<class T> 
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(){
        left = nullptr;
        right = nullptr;
    }
    
    ~BinaryTreeNode(){}
};

/**
 * @brief SWAP all children nodes in the tree. 
 * Runtime Complexity: O(n)
 * Memory Complexity: O(n)
 * @tparam T 
 * @param root root of the subtree of which we want to switch the children
 */
template <class T>
void swap_all_children(BinaryTreeNode<T>* root){
    swap_children(root);
    if(root->left != nullptr) swap_all_children(root->left);
    if(root->right != nullptr) swap_all_children(root->right);
}

template<class T> 
void swap_children(BinaryTreeNode<T>* node){
    BinaryTreeNode<T>* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

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

int main(int argv, char* argc[]){
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>();
    create_children(root, 0, 10);
    print_tree(root);
    cout << "=======" << endl << endl;
    swap_all_children(root);
    print_tree(root);
}