#include <gtest/gtest.h>

#include <blk.hpp>

#include "utils.hpp"


TEST(Over, PaddingOnDiagNE_SW) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 2, 1, 1, 0);
    blk::Expr e2 = blk::debug('b', 2, 1, 0, 0);
    blk::Expr o = blk::over(e1, e2);

    ASSERT_EQ(3, o->width());

    {
        SCOPED_TRACE("Over.PaddingOnDiagNE_SW");
        ASSERT_OUTPUT("a+.", output, o, 0);
        ASSERT_OUTPUT(".+b", output, o, 1);
    }

}

TEST(Over, PaddingOnDiagNW_SE) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 2, 1, 0, 0);
    blk::Expr e2 = blk::debug('b', 2, 1, 1, 0);
    blk::Expr o = blk::over(e1, e2);

    {
        SCOPED_TRACE("Over.PaddingOnDiagNW_SE");
        ASSERT_OUTPUT(".+a", output, o, 0);
        ASSERT_OUTPUT("b+.", output, o, 1);
    }

}

TEST(Over, PaddingBottomBoth) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 3, 1, 1, 0);
    blk::Expr e2 = blk::debug('b', 1, 1, 0, 0);
    blk::Expr o = blk::over(e1, e2);

    {
        SCOPED_TRACE("Over.PaddingBottomBoth");
        ASSERT_OUTPUT("a+a", output, o, 0);
        ASSERT_OUTPUT(".+.", output, o, 1);
    }

}

TEST(Over, PaddingTopBoth) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 3, 1, 1, 0);
    blk::Expr e2 = blk::debug('b', 1, 1, 0, 0);
    blk::Expr o = blk::over(e2, e1);

    {
        SCOPED_TRACE("Over.PaddingTopBoth");
        ASSERT_OUTPUT(".+.", output, o, 0);
        ASSERT_OUTPUT("a+a", output, o, 1);
    }

}
