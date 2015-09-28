#include <gtest/gtest.h>

#include <blk.hpp>

#include "utils.hpp"


TEST(Beside, PaddingOnDiagNE_SW) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 1, 2, 0, 1);
    blk::Expr e2 = blk::debug('b', 1, 2, 0, 0);
    blk::Expr o = blk::beside(e1, e2);

    ASSERT_EQ(3, o->height());

    {
        SCOPED_TRACE("Beside.PaddingOnDiagNE_SW");
        ASSERT_OUTPUT("a.", output, o, 0);
        ASSERT_OUTPUT("++", output, o, 1);
        ASSERT_OUTPUT(".b", output, o, 2);
    }

}

TEST(Beside, PaddingOnDiagNW_SE) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 1, 2, 0, 1);
    blk::Expr e2 = blk::debug('b', 1, 2, 0, 0);
    blk::Expr o = blk::beside(e2, e1);


    {
        SCOPED_TRACE("Beside.PaddingOnDiagNW_SE");
        ASSERT_OUTPUT(".a", output, o, 0);
        ASSERT_OUTPUT("++", output, o, 1);
        ASSERT_OUTPUT("b.", output, o, 2);
    }

}

TEST(Beside, PaddingLeftBoth) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 1, 3, 0, 1);
    blk::Expr e2 = blk::debug('b', 1, 1, 0, 0);
    blk::Expr o = blk::beside(e1, e2);

    {
        SCOPED_TRACE("Beside.PaddingLeftBoth");
        ASSERT_OUTPUT("a.", output, o, 0);
        ASSERT_OUTPUT("++", output, o, 1);
        ASSERT_OUTPUT("a.", output, o, 2);
    }

}

TEST(Beside, PaddingRightBoth) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 1, 3, 0, 1);
    blk::Expr e2 = blk::debug('b', 1, 1, 0, 0);
    blk::Expr o = blk::beside(e2, e1);

    {
        SCOPED_TRACE("Beside.PaddingRightBoth");
        ASSERT_OUTPUT(".a", output, o, 0);
        ASSERT_OUTPUT("++", output, o, 1);
        ASSERT_OUTPUT(".a", output, o, 2);
    }

}
