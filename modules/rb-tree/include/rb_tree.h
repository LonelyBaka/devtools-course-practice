// Copyright 2020 Nazarov Vladislav

#ifndef MODULES_RB_TREE_INCLUDE_RB_TREE_H_
#define MODULES_RB_TREE_INCLUDE_RB_TREE_H_

struct Node {
       int data;
       Node* parent;
       Node* left;
       Node* right;
       bool color; // false - Black, true - Red
};

class RBTree {
 public:
    RBTree();
    ~RBTree();
    Node* getRoot() { return _root; }
    void insert(Node* node);
 private:
    Node* _root;
};

#endif  // MODULES_RB_TREE_INCLUDE_RB_TREE_H_
