// Copyright 2020 Nazarov Vladislav

#include <gtest/gtest.h>

#include "include/rb_tree.h"

TEST(RBTreeTest, Default_Constructor) {
    ASSERT_NO_THROW(RBTree tree{});
}

TEST(RBTreeTest, Construct_Node) {
    Node node{ 15, nullptr, nullptr, nullptr, false };

    ASSERT_EQ(15, node.getData());
}

TEST(RBTreeTest, Can_Set_Node) {
    Node* node = new Node(15, nullptr, nullptr, nullptr, false);

    node->setLeft(new Node(25, node, nullptr, nullptr, false));

    ASSERT_EQ(25, node->getLeft()->getData());
}

// TEST(RBTreeTest, Can_Insert) {
//     RBTree tree;

//     tree.insert(new Node{15});

//     ASSERT_EQ(15, tree.getRoot()->left->data);
// }