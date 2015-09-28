#include <gtest/gtest.h>

#include <blk.hpp>


#include "utils.hpp"


TEST(Block, Debug)
{
    std::ostringstream output;
    blk::Expr e = blk::debug('a', 7, 4, 3, 1);

    ASSERT_EQ(3, e->leftPadding());

    {
        SCOPED_TRACE("Block.Debug");
        ASSERT_OUTPUT("aaaaaaa", output, e, 0); 
        ASSERT_OUTPUT("aaa+aaa", output, e, 1); 
        ASSERT_OUTPUT("aaaaaaa", output, e, 2); 
        ASSERT_OUTPUT("aaaaaaa", output, e, 3); 
    }
}
