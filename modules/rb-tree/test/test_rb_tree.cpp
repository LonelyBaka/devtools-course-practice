// Copyright 2020 Nazarov Vladislav

#include <gtest/gtest.h>

#include "include/rb_tree.h"

TEST(RBTreeTest, Default_Constructor) {
    ASSERT_NO_THROW(RBTree tree {});
}
