#include "utils.hpp"



void ASSERT_OUTPUT(std::string&& test, std::ostringstream& output, blk::Expr& block, int line) {
    block->line(output, line);
    ASSERT_EQ(test, output.str());
    output.clear();
    output.str("");
}
