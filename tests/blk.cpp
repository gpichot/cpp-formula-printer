#include <gtest/gtest.h>

#include <blk.hpp>


#include "utils.hpp"


TEST(BLK, OperatorSum) {

    blk::Expr x = blk::text("x");
    blk::Expr y = blk::text("y");

    blk::Expr sum = x + y;

    // Output is "x.+.y"
    ASSERT_EQ(5, sum->width());
    ASSERT_EQ(1, sum->height());
    ASSERT_EQ(2, sum->column());
    ASSERT_EQ(0, sum->row());

    std::ostringstream output;

    ASSERT_OUTPUT("x.+.y", output, sum, 0); 
}

TEST(BLK, OperatorQuotient) {

    blk::Expr x = blk::text("x");
    blk::Expr y = blk::text("y");
    blk::Expr z = blk::text("z");

    blk::Expr quotient = x / y;
    blk::Expr quotient2 = quotient / z;

    ASSERT_EQ(3, quotient2->width());
    ASSERT_EQ(5, quotient2->height());
    ASSERT_EQ(1, quotient2->column());
    ASSERT_EQ(3, quotient2->row());

    std::ostringstream output;

    ASSERT_OUTPUT(".x.", output, quotient2, 0); 
    ASSERT_OUTPUT(".-.", output, quotient2, 1); 
    ASSERT_OUTPUT(".y.", output, quotient2, 2); 
    ASSERT_OUTPUT("---", output, quotient2, 3); 
    ASSERT_OUTPUT(".z.", output, quotient2, 4); 

}

TEST(BLK, EqualityOperator) {

    blk::Expr x = blk::text("x");
    blk::Expr y = blk::text("y");

    blk::Expr equality = x == y;

    // Output is "x.=.y"
    ASSERT_EQ(5, equality->width());
    ASSERT_EQ(1, equality->height());
    ASSERT_EQ(2, equality->column());
    ASSERT_EQ(0, equality->row());

    std::ostringstream output;

    ASSERT_OUTPUT("x.=.y", output, equality, 0); 

}
