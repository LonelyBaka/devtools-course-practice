// Copyright 2020 Nazarov Vladislav

#ifndef MODULES_RB_TREE_INCLUDE_RB_TREE_H_
#define MODULES_RB_TREE_INCLUDE_RB_TREE_H_

class Node {
 public:
    Node(int data = 0, Node* parent = nullptr, Node* left = nullptr, 
         Node* right = nullptr, bool color = false);
    int getData() { return _data; }
    Node* getParent() { return _parent; }
    Node* getLeft() { return _left; }
    Node* getRight() { return _right; }
    bool getColor() { return _color; }
    void setData(int data) { _data = data; }
    void setParent(Node* parent) { _parent = parent; }
    void setLeft(Node* left) { _left = left; }
    void setRight(Node* right) { _right = right; }
    void setColor(bool color) { _color = color; }
 private:
    int _data;
    Node* _parent;
    Node* _left;
    Node* _right;
    bool _color; // false - Black, true - Red
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
