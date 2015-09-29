#include <gtest/gtest.h>

#include <blk.hpp>


#include "utils.hpp"


TEST(Block, Output) {
    blk::Expr e = blk::debug('a', 1, 1, 0, 0);

    std::ostringstream output;

    output << e;

    ASSERT_EQ("    0 :  +\n", output.str()); 
}


