#include <gtest/gtest.h>

#include <blk.hpp>


TEST(MoveRef, Test)
{

    blk::Expr e = blk::debug('a', 2, 2, 0, 0);
    
    blk::Expr m = blk::move_ref(e, 1, 1);
    
    ASSERT_EQ(1, m->row());
    ASSERT_EQ(1, m->column());
      
}
