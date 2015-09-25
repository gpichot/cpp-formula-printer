#pragma once

#include <memory>

#include "block.hpp"


namespace blk {


    class Debug: public Block {
        public:
            Debug(char c, int width, int height, int row, int column);

            virtual std::string line(int row) const;
        protected:
            char _fill;
    };


    Expr debug(char c, int width, int height, int row, int column);


}
