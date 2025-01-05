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

    void clear(Node* cur) {
        if(cur->l) {
            clear(cur->l);
        }
        if(cur->r) {
            clear(cur->r);
        }
        delete cur;
    }

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

        //if the root is the node we want, handle it specially
        if(cur->data == val) {
            if(!cur->l && !cur->r) {
                root = nullptr;
            } else if(!cur->l) {
                cur = cur->r;
            } else if(!cur->r) {
                cur = cur->l;
            } else {
                //arbitrarily shift to r
                if(cur->r->l) {
                    Node* childToMove = cur->r->l;
                    Node* ptr = cur->l;
                    while(ptr->r) {
                        ptr = ptr->r;
                    }
                    ptr->r = childToMove;
                }
                cur->r->l = cur->l;
                root = cur->r;
            }
            delete cur;
            return;
        }
        
        //find the node with the target value
        while(cur) {
            if(cur->data == val) {
                //found the node
                if(prev->l == cur) {
                    //left child removal
                    if(!cur->l && !cur->r) {
                        //if no children of found node, just delete it
                        prev->l = nullptr;
                    } else if(!cur->r) {
                        //if no right child of found node, set parent left to found node's left
                        prev->l = cur->l;
                    } else if(!cur->l) {
                        //if no left child of found node, set parent left to found node's right
                        prev->l = cur->r;
                    } else {
                        //found node has children on both sides
                        if(cur->r->l) {
                            //if node to remove's right child has a left child, it needs to be
                            //moved to the furthest right descendant of the node to remove's left child
                            Node* childToMove = cur->r->l;
                            Node* ptr = cur->l;
                            while(ptr->r) {
                                ptr = ptr->r;
                            }
                            ptr->r = childToMove;
                        }
                        //node to remove's right child takes its place. Its l becomes the node to remove's l
                        //and the parent of the node to remove's l becomes the node to remove's r
                        cur->r->l = cur->l;
                        prev->l = cur->r;
                    }
                    //finally clean up the node and break
                    delete cur;
                    return;
                } else {
                    //right child removal
                    if(!cur->l && !cur->r) {
                        //node to remove has no children, just delete it
                        prev->r = nullptr;
                    } else if(!cur->l) {
                        //node to remove has no left child, just replace it with its right child
                        prev->r = cur->r;
                    } else if(!cur->r) {
                        //node to remove has no right child, just replace it with its left child
                        prev->r = cur->l;
                    } else {
                        //node to remove has both children
                        if(cur->r->l) {
                            //if node to remove's right child has a left child, it needs to be
                            //moved to the furthest right descendant of the node to remove's left child
                            Node* childToMove = cur->r->l;
                            Node* ptr = cur->l;
                            while(ptr->r) {
                                ptr = ptr->r;
                            }
                            ptr->r = childToMove;
                        }
                        //node to remove's right child takes its place. Its l becomes the node to remove's l
                        //and the parent of the node to remove's l becomes the node to remove's r
                        cur->r->l = cur->l;
                        prev->r = cur->r;
                    }
                    delete cur;
                    return;
                }
            }

            prev = cur;
            if(cur->data < val) {
                cur = cur->r;
            } else {
                cur = cur->l;
            }
        }
        //if we got here, val is not in the set
    }

    void clear() {
        if(root) {
            clear(root);
            root = nullptr;
        }
    }

    void dump() {
        if(root) {
            dump(root);
        }
        std::cout << std::endl;
    }
};