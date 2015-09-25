#pragma once

#include "block.hpp"


namespace blk {


    class Debug: public Block {
        public:
            Debug(char c, int width, int height, int row, int column)
                : _fill(c), Block(width, height, row, column)
            {
            }

            virtual std::string line(int row) const {
                std::string lineString = "";

                // TODO: improve with repeat char?..
                for(int x = 0; x < _width; x++) {
                    if(row != _row || x != _column) {
                        lineString += _fill;
                    } else {
                        lineString += '+';
                    }
                }

                return lineString;
            }
        protected:
            char _fill;
    };

    Expr debug(char c, int width, int height, int row, int column) {
        return std::make_shared<Debug>(c, width, height, row, column);
    }


}
