#pragma once

#include <memory>
#include <iostream>
#include <string>

#include "block.hpp"


namespace blk {


    class Debug: public Block {
        public:
            Debug(char c, int width, int height, int column, int row);

            virtual std::ostream& line(std::ostream& os, int row) const;
        protected:
            char _fill;
    };


    Expr debug(char c, int width, int height, int column, int row);


}
