#include <gtest/gtest.h>

#include <blk.hpp>

#include "utils.hpp"


TEST(Over, PaddingOnDiagNE_SW) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 2, 1, 1, 0);
    blk::Expr e2 = blk::debug('b', 2, 1, 0, 0);
    blk::Expr o = blk::over(e1, e2);

    ASSERT_EQ(3, o->width());

    ASSERT_OUTPUT(std::string("a+."), output, o, 0);
    ASSERT_OUTPUT(std::string(".+b"), output, o, 1);

}

TEST(Over, PaddingOnDiagNW_SE) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 2, 1, 0, 0);
    blk::Expr e2 = blk::debug('b', 2, 1, 1, 0);
    blk::Expr o = blk::over(e1, e2);

    ASSERT_OUTPUT(std::string(".+a"), output, o, 0);
    ASSERT_OUTPUT(std::string("b+."), output, o, 1);

}

TEST(Over, PaddingBottomBoth) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 3, 1, 1, 0);
    blk::Expr e2 = blk::debug('b', 1, 1, 0, 0);
    blk::Expr o = blk::over(e1, e2);

    ASSERT_OUTPUT(std::string("a+a"), output, o, 0);
    ASSERT_OUTPUT(std::string(".+."), output, o, 1);

}

TEST(Over, PaddingTopBoth) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 3, 1, 1, 0);
    blk::Expr e2 = blk::debug('b', 1, 1, 0, 0);
    blk::Expr o = blk::over(e2, e1);

    ASSERT_OUTPUT(std::string(".+."), output, o, 0);
    ASSERT_OUTPUT(std::string("a+a"), output, o, 1);

}
