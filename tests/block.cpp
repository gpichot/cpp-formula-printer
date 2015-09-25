#include <gtest/gtest.h>

#include "block.hpp"
#include <string>


TEST(Block, Debug)
{
    blk::Expr e = blk::debug('a', 7, 4, 1, 3);
    
    ASSERT_EQ(3, e->leftPadding());

    ASSERT_EQ("aaaaaaa", e->line(0)); 
    ASSERT_EQ("aaa+aaa", e->line(1)); 
    ASSERT_EQ("aaaaaaa", e->line(2)); 
    ASSERT_EQ("aaaaaaa", e->line(3)); 
}

TEST(Over, Constructor) {
    blk::Expr e1 = blk::debug('a',7,4,3,1);
    blk::Expr e2 = blk::debug('b',4,8,2,2);
    blk::Expr o = blk::over(e1, e2);

    std::cout << e1 << std::endl;
    std::cout << e2 << std::endl;

    ASSERT_EQ(8, o->width());
    ASSERT_EQ(12, o->height());
    ASSERT_EQ(2, o->column());
    ASSERT_EQ(3, o->row());

    ASSERT_EQ(".aaaaaaa", o->line(0));
    ASSERT_EQ(".aaaaaaa", o->line(1));
    ASSERT_EQ(".a+aaaaa", o->line(2));
    ASSERT_EQ(".aaaaaaa", o->line(3));
    ASSERT_EQ(".aaaaaaa", o->line(3));

}
