#include "debug.hpp"


namespace blk {

    Debug::Debug(char c, int width, int height, int row, int column)
        : _fill(c), Block(width, height, row, column)
    {
    }

    std::string Debug::line(int row) const {

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

    Expr debug(char c, int width, int height, int row, int column) {
        return std::make_shared<Debug>(c, width, height, row, column);
    }
}
