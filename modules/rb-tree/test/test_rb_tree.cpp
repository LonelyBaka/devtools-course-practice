// Copyright 2020 Nazarov Vladislav

#include <gtest/gtest.h>

#include "include/rb_tree.h"

TEST(RBTreeTest, Default_Constructor) {
    ASSERT_NO_THROW(RBTree tree{});
}

TEST(RBTreeTest, Construct_Node) {
    Node node(15);

    ASSERT_EQ(15, node.getData());
}

TEST(RBTreeTest, Can_Set_Node) {
    Node* node = new Node(15);

    node->setLeft(new Node(25, node));

    ASSERT_EQ(25, node->getLeft()->getData());
}

TEST(RBTreeTest, Can_Insert) {
    RBTree tree;

    tree.insert(new Node(15));

    ASSERT_EQ(15, tree.getRoot()->getRight()->getData());
}

TEST(RBTreeTest, Can_Insert_A_Lot) {
    RBTree tree;

    tree.insert(new Node(-5));
    tree.insert(new Node(10));
    tree.insert(new Node(5));
    tree.insert(new Node(15));

    ASSERT_EQ(5, tree.getRoot()->getRight()->getLeft()->getData());
}

TEST(RBTreeTest, Can_Find_Element) {
    RBTree tree;

    tree.insert(new Node(-5));
    tree.insert(new Node(10));
    tree.insert(new Node(5));
    tree.insert(new Node(15));

    ASSERT_TRUE(tree.find(-5)->getColor());
}

TEST(RBTreeTest, Can_Remove_Element) {
    RBTree tree;

    tree.insert(new Node(-5));
    tree.insert(new Node(10));
    tree.insert(new Node(5));
    tree.insert(new Node(15));
    tree.remove(-5);

    ASSERT_EQ(tree.find(-5), nullptr);
}

TEST(RBTreeTest, Cant_Insert_Exist_Element) {
    RBTree tree;

    tree.insert(new Node(-5));

    ASSERT_ANY_THROW(tree.insert(new Node(-5)));
}

TEST(RBTreeTest, Cant_Remove_No_Exist_Element) {
    RBTree tree;

    tree.insert(new Node(-5));

    ASSERT_ANY_THROW(tree.remove(10));
}

TEST(RBTreeTest, Can_Make_Large_Tree) {
    RBTree tree;

    for (int i = 1; i < 50; ++i)
        tree.insert(new Node(i));

    ASSERT_EQ(22, tree.find(22)->getData());
}

TEST(RBTreeTest, Can_Remove_In_Large_Tree) {
    RBTree tree;

    for (int i = 1; i < 50; ++i)
        tree.insert(new Node(i));
    for (int i = 2; i < 20; i+=2)
        tree.remove(i);

    ASSERT_EQ(nullptr, tree.find(10));
}

TEST(RBTreeTest, Insert_And_Remove_Different_Numbers) {
    RBTree tree;

    tree.insert(new Node(-5));
    tree.insert(new Node(15));
    tree.insert(new Node(4));
    tree.insert(new Node(25));
    tree.insert(new Node(-3));
    tree.insert(new Node(-15));
    tree.remove(-15);
    tree.remove(-3);
    tree.insert(new Node(-17));
    tree.remove(4);
    tree.remove(25);
    tree.insert(new Node(14));
    tree.insert(new Node(13));
    tree.insert(new Node(-2));
}