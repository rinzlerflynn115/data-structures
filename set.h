#pragma once
#include <iostream>
#include <memory>

template <typename T>
class Set {
private:
    struct Node {
        Node* l;
        Node* r;
        T data;
    };
    Node* root;

    void dump(Node* cur) {
        if(cur->l) {
            dump(cur->l);
        }
        std::cout << cur->data << " ";
        if(cur->r) {
            dump(cur->r);
        }
    }
public:
    Set() : root(nullptr) {};
    Set(const Set<T>&);
    const Set<T>& operator=(const Set<T>& other);

    void insert(T val) {
        if(!root) {
            root = new Node();
            root->data = val;
            return;
        }
        
        Node* cur = root;
        
        while(cur) {
            if(cur->data == val) {
                return;
            } else if (cur->data > val) {
                if(!cur->l) {
                    cur->l = new Node();
                    cur->l->data = val;
                    return;
                }
                cur = cur->l;
            } else {
                if(!cur->r) {
                    cur->r = new Node();
                    cur->r->data = val;
                    return;
                }
                cur = cur->r;
            }
        }
    }

    void remove(T val) {
        if(!root) {
            return;
        }

        Node* prev = nullptr;
        Node* cur = root;

        if(root->data == val) {
            delete root;
        }

        if(cur->data > val) {
            prev = cur;
            cur = cur->l;
        } else if(cur->data < val) {
            prev = cur;
            cur = cur->r;
        } else {
            if(prev->l == cur) {
                //left child removal
                if(!cur->r) {
                    prev->l = cur->l;
                    return;
                }
                Node* nodeToMove = cur->r;
                Node* nodeToMoveLChild = nodeToMove->l;

                prev->l = nodeToMove;
                nodeToMove->l = cur->l;

                cur = nodeToMove->l;
                while(cur->r){
                    cur = cur->r;
                }
                cur->r = nodeToMoveLChild;
            } else if(prev->r == cur) {
                //right child removal
                if(!cur->l) {
                    prev->r = cur->r;
                    return;
                }
                Node* nodeToMove = cur->l;
                Node* nodeToMoveRChild = nodeToMove->r;
            }
        }
    }

    void dump() {
        if(root) {
            dump(root);
            std::cout << std::endl;
        }
    }
};