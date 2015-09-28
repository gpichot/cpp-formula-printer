#include <gtest/gtest.h>

#include "debug.hpp"
#include "over.hpp"


void ASSERT_OUTPUT(std::string&& test, std::ostringstream& output, blk::Expr& block, int line) {
    block->line(output, line);
    ASSERT_EQ(test, output.str());
    output.clear();
    output.str("");
}

TEST(Over, PaddingOnDiagNE_SW) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 2, 1, 0, 1);
    blk::Expr e2 = blk::debug('b', 2, 1, 0, 0);
    blk::Expr o = blk::over(e1, e2);

    ASSERT_OUTPUT(std::string("a+."), output, o, 0);
    ASSERT_OUTPUT(std::string(".+b"), output, o, 1);

}

TEST(Over, PaddingOnDiagNW_SE) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 2, 1, 0, 0);
    blk::Expr e2 = blk::debug('b', 2, 1, 0, 1);
    blk::Expr o = blk::over(e1, e2);

    ASSERT_OUTPUT(std::string(".+a"), output, o, 0);
    ASSERT_OUTPUT(std::string("b+."), output, o, 1);

}

TEST(Over, PaddingBottomBoth) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 3, 1, 0, 1);
    blk::Expr e2 = blk::debug('b', 1, 1, 0, 0);
    blk::Expr o = blk::over(e1, e2);

    ASSERT_OUTPUT(std::string("a+a"), output, o, 0);
    ASSERT_OUTPUT(std::string(".+."), output, o, 1);

}

TEST(Over, PaddingTopBoth) {

    std::ostringstream output;

    blk::Expr e1 = blk::debug('a', 3, 1, 0, 1);
    blk::Expr e2 = blk::debug('b', 1, 1, 0, 0);
    blk::Expr o = blk::over(e2, e1);

    ASSERT_OUTPUT(std::string(".+."), output, o, 0);
    ASSERT_OUTPUT(std::string("a+a"), output, o, 1);

}
