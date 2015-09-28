#include <gtest/gtest.h>

#include <blk.hpp>


TEST(Block, Debug)
{
    std::ostringstream output;
    blk::Expr e = blk::debug('a', 7, 4, 3, 1);
    
    ASSERT_EQ(3, e->leftPadding());

    e->line(output, 0);
    ASSERT_EQ("aaaaaaa", output.str()); 
    output.clear();
    output.str("");
    e->line(output, 1);
    ASSERT_EQ("aaa+aaa", output.str()); 
    output.clear();
    output.str("");
    e->line(output, 2);
    ASSERT_EQ("aaaaaaa", output.str()); 
    output.clear();
    output.str("");
    e->line(output, 3);
    ASSERT_EQ("aaaaaaa", output.str()); 
}
