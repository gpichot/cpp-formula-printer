#include <gtest/gtest.h>

#include "debug.hpp"


TEST(Block, Debug)
{
    blk::Expr e = blk::debug('a', 7, 4, 1, 3);
    
    ASSERT_EQ(3, e->leftPadding());

    ASSERT_EQ("aaaaaaa", e->line(0)); 
    ASSERT_EQ("aaa+aaa", e->line(1)); 
    ASSERT_EQ("aaaaaaa", e->line(2)); 
    ASSERT_EQ("aaaaaaa", e->line(3)); 
}
