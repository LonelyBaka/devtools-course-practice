// Copyright 2020 Nazarov Vladislav

#include "include/rb_tree.h"

RBTree::RBTree() : _root(new Node{ 0, nullptr, nullptr, nullptr, false }) {
}

RBTree::~RBTree() {
    delete[] _root;
}

void insert(Node* node) {
}
