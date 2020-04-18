// Copyright 2020 Nazarov Vladislav

#ifndef MODULES_RB_TREE_INCLUDE_RB_TREE_H_
#define MODULES_RB_TREE_INCLUDE_RB_TREE_H_

struct Node {
       int data = 0;
       Node* parent = nullptr;
       Node* left = nullptr;
       Node* right = nullptr;
       bool color = false; // false - Black, true - Red
};

class RBTree {
 public:
    RBTree();
    ~RBTree();
    Node* getRoot() { return _root; }
 private:
    Node* _root;
};

#endif  // MODULES_RB_TREE_INCLUDE_RB_TREE_H_
