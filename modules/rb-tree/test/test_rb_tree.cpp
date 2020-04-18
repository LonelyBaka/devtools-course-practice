// Copyright 2020 Nazarov Vladislav

#include <gtest/gtest.h>

#include "include/rb_tree.h"

TEST(RBTreeTest, Default_Constructor) {
    ASSERT_NO_THROW(RBTree tree{});
}

TEST(RBTreeTest, Construct_Node) {
    Node node = { 15, nullptr, nullptr, nullptr, false };

    ASSERT_EQ(15, node.data);
}

TEST(RBTreeTest, Default_Constructor_Have_Root) {
    RBTree tree{};
    
    ASSERT_EQ(static_cast<bool>(false), 
              static_cast<bool>(tree.getRoot()->color));
}

// TEST(RBTreeTest, Can_Insert) {
//     RBTree tree;

//     tree.insert(new Node{15});

//     ASSERT_EQ(15, tree.getRoot()->left->data);
// }