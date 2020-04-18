// Copyright 2020 Nazarov Vladislav

#include "include/rb_tree.h"

RBTree::RBTree() : _root(new Node{}) {
}

RBTree::~RBTree() {
    delete[] _root;
}
