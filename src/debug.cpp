#include "debug.hpp"


namespace blk {

    Debug::Debug(char c, int width, int height, int row, int column)
        : _fill(c), Block(width, height, row, column)
    {
    }

    std::ostream& Debug::line(std::ostream& os, int row) const {

        if(row != _row) {
            os << std::string(_width, _fill);
        } else {
            os << std::string(_column, _fill);
            os << '+';
            os << std::string(rightPadding(), _fill);
        }

        return os;

    }

    Expr debug(char c, int width, int height, int row, int column) {
        return std::make_shared<Debug>(c, width, height, row, column);
    }


}
