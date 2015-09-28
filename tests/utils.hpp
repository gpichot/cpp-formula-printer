#include <gtest/gtest.h>

#include <block.hpp>

#include <sstream>


void ASSERT_OUTPUT(std::string&& test, std::ostringstream& output, blk::Expr& block, int line);
