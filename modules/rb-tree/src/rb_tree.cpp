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

void RBTree::insert(Node* node) {
    if (find(node->getData()) != nullptr)
        throw "Node with same data already in tree";

    Node* first = nullptr;
    Node* second = _root;

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

void RBTree::insertBalancing(Node* node) {
    while (node->getParent() != nullptr &&
           node->getParent()->getColor() == true) {
        if (node->getParent() == node->getParent()->getParent()->getLeft()) {
            Node* tmp = node->getParent()->getParent()->getRight();
            if (tmp != nullptr && tmp->getColor() == true) {
                node->getParent()->setColor(false);
                tmp->setColor(false);
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
            Node* tmp = node->getParent()->getParent()->getLeft();
            if (tmp != nullptr && tmp->getColor() == true) {
                node->getParent()->setColor(false);
                tmp->setColor(false);
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

void RBTree::leftRotate(Node* node) {
    Node* tmp = node->getRight();
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

void RBTree::rightRotate(Node* node) {
    Node* tmp = node->getLeft();
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

void RBTree::remove(const int data) {
    Node* find_res = find(data);
    if (find_res == nullptr)
        throw "No node with this data in tree";
    Node* node = find_res;
    Node* tmp1 = node;
    Node* tmp2;
    bool tmp1_original_color = tmp1->getColor();
    if (node->getLeft() == nullptr && node->getRight() == nullptr) {
        if (node->getParent()->getLeft()->getData() == node->getData())
            node->getParent()->setLeft(nullptr);
        else
            node->getParent()->setRight(nullptr);
        delete[] node;
    } else if (node->getLeft() == nullptr) {
        tmp2 = node->getRight();
        swapNodes(node, node->getRight());
    } else if (node->getRight() == nullptr) {
        tmp2 = node->getLeft();
        swapNodes(node, node->getLeft());
    } else {
        tmp1 = node->getRight();
        while (tmp1->getLeft() != nullptr)
            tmp1 = tmp1->getLeft();
        tmp1_original_color = tmp1->getColor();
        tmp2 = tmp1->getRight();
        if (tmp1->getParent() == node) {
            tmp2->setParent(tmp1);
        } else {
            swapNodes(tmp1, tmp1->getRight());
            tmp1->setRight(node->getRight());
            tmp1->getRight()->setParent(tmp1);
        }
        swapNodes(node, tmp1);
        tmp1->setLeft(node->getLeft());
        tmp1->getLeft()->setParent(tmp1);
        tmp1->setColor(node->getColor());
    }

    if (tmp1_original_color == false)
        removeBalancing(tmp2);
}

void RBTree::swapNodes(Node* node1, Node* node2) {
    if (node1->getParent() == nullptr)
        _root = node2;
    else if (node1 == node1->getParent()->getLeft())
        node1->getParent()->setLeft(node2);
    else
        node1->getParent()->setRight(node2);

    node2->setParent(node1->getParent());
}

void RBTree::removeBalancing(Node* node) {
    while (node != _root && node->getColor() == false) {
        if (node == node->getParent()->getLeft()) {
            Node* tmp = node->getParent()->getRight();

            if (tmp->getColor() == true) {
                tmp->setColor(false);
                node->getParent()->setColor(true);
                leftRotate(node->getParent());
                tmp = node->getParent()->getRight();
            }

            if (tmp->getLeft()->getColor() == false &&
                tmp->getRight()->getColor() == false) {
                tmp->setColor(true);
                node = node->getParent();
            } else {
                if (tmp->getRight()->getColor() == false) {
                    tmp->getLeft()->setColor(false);
                    tmp->setColor(true);
                    rightRotate(tmp);
                    tmp = node->getParent()->getRight();
                }
                tmp->setColor(node->getParent()->getColor());
                node->getParent()->setColor(false);
                tmp->getRight()->setColor(false);
                leftRotate(node->getParent());
                node = _root;
            }
        } else {
            Node* tmp = node->getParent()->getLeft();

            if (tmp->getColor() == true) {
                tmp->setColor(false);
                node->getParent()->setColor(true);
                rightRotate(node->getParent());
                tmp = node->getParent()->getLeft();
            }

            if (tmp->getRight()->getColor() == false &&
                tmp->getLeft()->getColor() == false) {
                tmp->setColor(true);
                node = node->getParent();
            } else {
                if (tmp->getLeft()->getColor() == false) {
                    tmp->getRight()->setColor(false);
                    tmp->setColor(true);
                    leftRotate(tmp);
                    tmp = node->getParent()->getLeft();
                }
                tmp->setColor(node->getParent()->getColor());
                node->getParent()->setColor(false);
                tmp->getLeft()->setColor(false);
                rightRotate(node->getParent());
                node = _root;
            }
        }
    }

    node->setColor(false);
}
