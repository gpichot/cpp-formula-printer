#include <gtest/gtest.h>

#include "debug.hpp"
#include "over.hpp"


TEST(Over, Constructor) {

    blk::Expr e1 = blk::debug('a',7,4,3,1);
    blk::Expr e2 = blk::debug('b',4,8,2,2);
    blk::Expr o = blk::over(e1, e2);

    ASSERT_EQ(8, o->width());
    ASSERT_EQ(12, o->height());
    ASSERT_EQ(2, o->column());
    ASSERT_EQ(3, o->row());

    ASSERT_EQ(".aaaaaaa", o->line(0));
    ASSERT_EQ(".aaaaaaa", o->line(1));
    ASSERT_EQ(".aaaaaaa", o->line(2));
    ASSERT_EQ(".a+aaaaa", o->line(3));
    ASSERT_EQ("bbbb....", o->line(4));
    ASSERT_EQ("bbbb....", o->line(5));
    ASSERT_EQ("bb+b....", o->line(6));
    ASSERT_EQ("bbbb....", o->line(7));
    ASSERT_EQ("bbbb....", o->line(8));
    ASSERT_EQ("bbbb....", o->line(9));
    ASSERT_EQ("bbbb....", o->line(10));
    ASSERT_EQ("bbbb....", o->line(11));

}

TEST(Over, ConstructorBottomLeftPadding) {

    blk::Expr e1 = blk::debug('a', 2, 2, 1, 1);
    blk::Expr e2 = blk::debug('b', 2, 2, 0, 0);
    blk::Expr o = blk::over(e1, e2);

    ASSERT_EQ("aa.", o->line(0));
    ASSERT_EQ("a+.", o->line(1));
    ASSERT_EQ(".+b", o->line(2));
    ASSERT_EQ(".bb", o->line(3));

}
