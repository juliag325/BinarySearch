#pragma once
#include <vector>
#include <exception>

namespace cop3530 {

template<typename Key, typename T>
class bst {
    struct node {
        // key
        // value
        // left child
        // right child
        Key k; 
        T value; 
        node* left; 
        node* right; 
        

        node() {
        }

        node(Key k, T t) {
        }

        
    };

    // root of tree
    private node* root; 

    public:
        bst();
        ~bst();
        void insert(const Key &key, const T &t);
        void erase(const Key &key);
        T& at(const Key &key);
        bool contains(const Key &key) const;
        bool empty() const;
        size_t size() const;
        std::vector<std::pair<Key, T>> inorder_contents();
        std::vector<std::pair<Key, T>> preorder_contents();

};

template<typename Key, typename T>
bst<Key, T>::bst() {
    root = NULL;  
}

template<typename Key, typename T>
bst<Key, T>::~bst() {
    if (node) { 
        bst(node->left); 
        bst(node->right); 
        delete node; 
    }
}

template<typename Key, typename T>
void bst<Key, T>::insert(const Key &key, const T &t) {

}

template<typename Key, typename T>
void bst<Key, T>::erase(const Key &key) {
    
}

template<typename Key, typename T>
T& bst<Key, T>::at(const Key &key) {
    
}

template<typename Key, typename T>
bool bst<Key, T>::contains(const Key &key) const {
    return false;
}

template<typename Key, typename T>
bool bst<Key, T>::empty() const {
    return true;
}

template<typename Key, typename T>
size_t bst<Key, T>::size() const {
    return 0;
}

template<typename Key, typename T>
std::vector<std::pair<Key, T>> bst<Key, T>::inorder_contents() {
    std::vector<std::pair<Key, T>> contents;
    return contents;
}

template<typename Key, typename T>
std::vector<std::pair<Key, T>> bst<Key, T>::preorder_contents() {
    std::vector<std::pair<Key, T>> contents;
    return contents;
}

}