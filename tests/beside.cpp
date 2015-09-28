#include <gtest/gtest.h>

#include <debug.hpp>
#include <beside.hpp>

#include "utils.hpp"


TEST(Beside, PaddingOnDiagNE_SW) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 1, 2, 0, 1);
    blk::Expr e2 = blk::debug('b', 1, 2, 0, 0);
    blk::Expr o = blk::beside(e1, e2);

    ASSERT_EQ(3, o->height());

    ASSERT_OUTPUT(std::string("a."), output, o, 0);
    ASSERT_OUTPUT(std::string("++"), output, o, 1);
    ASSERT_OUTPUT(std::string(".b"), output, o, 2);

}

TEST(Beside, PaddingOnDiagNW_SE) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 1, 2, 0, 1);
    blk::Expr e2 = blk::debug('b', 1, 2, 0, 0);
    blk::Expr o = blk::beside(e2, e1);

    ASSERT_OUTPUT(std::string(".a"), output, o, 0);
    ASSERT_OUTPUT(std::string("++"), output, o, 1);
    ASSERT_OUTPUT(std::string("b."), output, o, 2);

}

TEST(Beside, PaddingLeftBoth) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 1, 3, 0, 1);
    blk::Expr e2 = blk::debug('b', 1, 1, 0, 0);
    blk::Expr o = blk::beside(e1, e2);

    ASSERT_OUTPUT(std::string("a."), output, o, 0);
    ASSERT_OUTPUT(std::string("++"), output, o, 1);
    ASSERT_OUTPUT(std::string("a."), output, o, 2);

}

TEST(Beside, PaddingRightBoth) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 1, 3, 0, 1);
    blk::Expr e2 = blk::debug('b', 1, 1, 0, 0);
    blk::Expr o = blk::beside(e2, e1);

    ASSERT_OUTPUT(std::string(".a"), output, o, 0);
    ASSERT_OUTPUT(std::string("++"), output, o, 1);
    ASSERT_OUTPUT(std::string(".a"), output, o, 2);

}
