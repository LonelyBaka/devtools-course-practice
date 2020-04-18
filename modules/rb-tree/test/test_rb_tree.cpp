// Copyright 2020 Nazarov Vladislav

#include <gtest/gtest.h>

#include "include/rb_tree.h"

TEST(RBTreeTest, Default_Constructor) {
    ASSERT_NO_THROW(RBTree tree{});
}

TEST(RBTreeTest, Construct_Node) {
    Node node{15};

    ASSERT_EQ(15, node.data);
}

TEST(RBTreeTest, Default_Constructor_Have_Root) {
    RBTree tree{};
    
    ASSERT_EQ(false, tree.getRoot()->color);
}
