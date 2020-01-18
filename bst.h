#pragma once
#include <vector>
#include <exception>
#include <stack>

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
        

        node() {}

        node(Key k, T t) {}

        
    };

    // root of tree
    node* root; 

    public:
        bst();
        ~bst();
        void removeSubtree(node* Ptr); 
        void createLeaf(const Key &key, const T &t); 
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
}

template<typename Key, typename T>
bst<Key, T>::~bst() {
    removeSubtree(root); 
}

template<typename Key, typename T>
void bst<Key, T>::removeSubtree(node* Ptr) {
    if (Ptr!=NULL) { 
        if (Ptr->left !=NULL) { 
            removeSubtree(Ptr->left); 
        }
        if (Ptr->right !=NULL) { 
            removeSubtree(Ptr->right); 
        }
        delete Ptr; 
    }


}


template<typename Key, typename T>
void bst<Key, T>::insert(const Key &key, const T &t) {
    node* insertNode = new node;
    insertNode->k = key; 
    insertNode->value = t; 
/*
    if (root == NULL) { 
        root = insertNode; 
    }
    */
   /* if (root->k == key) { 
        root->value = t; 

    }
    else if (root->k > key) {
        root = root->left;  
        insert(key, t); 
    }
    else if (root->k < key) { 
        root = root->right; 
        insert(key, t); 
    }
*/
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
    std::stack<node* > s; 
    node* curr = root; 

    while (curr != NULL || s.empty() == false) {
        while (curr != NULL) { 
            s.push(curr);
            curr = curr->left; 
        }
        curr = s.top(); 
        s.pop(); 

        contents.push_back(std::make_pair(curr->k, curr->value)); 

        curr = curr->right; 
    }
    
    return contents;
}

template<typename Key, typename T>
std::vector<std::pair<Key, T>> bst<Key, T>::preorder_contents() {
    std::vector<std::pair<Key, T>> contents;
    std::stack<node* > s; 

    while (!s.empty()) { 

        node* curr = s.top(); 
        s.pop(); 

        contents.push_back(std::make_pair(curr->k, curr->value)); 

        if (curr-> right) {
            s.push(curr->right); 
        }

        if (curr-> left) {
            s.push(curr->left); 
        }
    }

    return contents;
}


}