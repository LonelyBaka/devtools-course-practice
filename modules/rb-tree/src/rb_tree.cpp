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

void RBTree::insert(Node *node) {
    if (find(node->getData()) != nullptr)
        throw "Node with same data already in tree";

    Node *first = nullptr;
    Node *second = _root;

    while (second != nullptr) {
        first = second;
        if (node->getData() < second->getData())
            second = second->getLeft();
        else
            second = second->getRight();
    }

    node->setParent(first);

    if (first == nullptr)
        _root = node;
    else if (node->getData() < first->getData())
        first->setLeft(node);
    else
        first->setRight(node);

    node->setLeft(nullptr);
    node->setRight(nullptr);
    node->setColor(true);

    insertBalancing(node);
}

void RBTree::insertBalancing(Node *node) {
    while (node->getParent() != nullptr && node->getParent()->getColor() == true) {
        if (node->getParent() == node->getParent()->getParent()->getLeft()) {
            Node *y = node->getParent()->getParent()->getRight();
            if (y->getColor() == true) {
                node->getParent()->setColor(false);
                y->setColor(false);
                node->getParent()->getParent()->setColor(true);
                node = node->getParent()->getParent();
            } else {
                if (node == node->getParent()->getRight()) {
                    node = node->getParent();
                    leftRotate(node);
                }
                node->getParent()->setColor(false);
                node->getParent()->getParent()->setColor(true);
                rightRotate(node->getParent()->getParent());
            }
        } else {
            Node *y = node->getParent()->getParent()->getLeft();
            if (y->getColor() == true) {
                node->getParent()->setColor(false);
                y->setColor(false);
                node->getParent()->getParent()->setColor(true);
                node = node->getParent()->getParent();
            } else {
                if (node == node->getParent()->getLeft()) {
                    node = node->getParent();
                    rightRotate(node);
                }
                node->getParent()->setColor(false);
                node->getParent()->getParent()->setColor(true);
                leftRotate(node->getParent()->getParent());
            }
        }
    }
    if (_root->getColor() == true) {
        repaint(_root);
    }
}

void RBTree::leftRotate(Node *node) {
    Node *tmp = node->getRight();
    node->setRight(tmp->getLeft());
    if (tmp->getLeft() != nullptr)
        tmp->getLeft()->setParent(node);
    tmp->setParent(node->getParent());
    if (node->getParent() == nullptr)
        _root = tmp;
    else if (node == node->getParent()->getLeft())
        node->getParent()->setLeft(tmp);
    else
        node->getParent()->setRight(tmp);
    tmp->setLeft(node);
    node->setParent(tmp);
}

void RBTree::rightRotate(Node *node) {
    Node *tmp = node->getLeft();
    node->setLeft(tmp->getRight());
    if (tmp->getRight() != nullptr)
        tmp->getRight()->setParent(node);
    tmp->setParent(node->getParent());
    if (node->getParent() == nullptr)
        _root = tmp;
    else if (node == node->getParent()->getRight())
        node->getParent()->setRight(tmp);
    else
        node->getParent()->setLeft(tmp);
    tmp->setRight(node);
    node->setParent(tmp);
}

Node* RBTree::find(const int& data) {
    Node* cur = _root;
    while (cur != nullptr) {
        if (data == cur->getData())
            return cur;
        else if (data < cur->getData())
            cur = cur->getLeft();
        else
            cur = cur->getRight();
    }
    return nullptr;
}

void RBTree::repaint(Node* node) {
    node->setColor(!node->getColor());
    if (node->getLeft() != nullptr)
        repaint(node->getLeft());
    if (node->getRight() != nullptr)
        repaint(node->getRight());
}
