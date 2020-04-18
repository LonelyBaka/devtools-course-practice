// Copyright 2020 Nazarov Vladislav

#include "include/rb_tree.h"

Node::Node(int data, Node* parent, Node* left, 
    Node* right, bool color) : _data(data), _parent(parent),
    _left(left), _right(right), _color(color) {}

RBTree::RBTree() : _root(new Node()) {
}

RBTree::~RBTree() {
    delete[] _root;
}

void insert(Node* node) {
}
