#include <gtest/gtest.h>

#include <blk.hpp>


#include "utils.hpp"


TEST(Text, Test)
{

    blk::Expr t1 = blk::text("hello", blk::Text::Alignment::Left);
    blk::Expr t2 = blk::text("hello", blk::Text::Alignment::Center);
    blk::Expr t3 = blk::text("coucou", blk::Text::Alignment::Center);
    blk::Expr t4 = blk::text("hello", blk::Text::Alignment::Right);

    ASSERT_EQ(0, t1->column());
    ASSERT_EQ(2, t2->column());
    ASSERT_EQ(2, t3->column());
    ASSERT_EQ(4, t4->column());

    std::ostringstream output;

    {
        SCOPED_TRACE("Text.Test");
        ASSERT_OUTPUT("hello", output, t1, 0);
    }

}
