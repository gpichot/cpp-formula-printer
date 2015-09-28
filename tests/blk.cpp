#include <gtest/gtest.h>

#include <blk.hpp>


#include "utils.hpp"


TEST(BLK, OperatorSum) {

    blk::Expr x = blk::text("x");
    blk::Expr y = blk::text("y");

    blk::Expr sum = x + y;

    std::cout << *sum << std::endl;
    std::cout << *y << std::endl;
    std::cout << *x << std::endl;

}

TEST(BLK, OperatorQuotient) {

    blk::Expr x = blk::text("x");
    blk::Expr y = blk::text("y");

    blk::Expr quotient = x / y;

    std::cout << *quotient << std::endl;
    std::cout << *y << std::endl;
    std::cout << *x << std::endl;

}
