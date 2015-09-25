#include "block.hpp"


namespace blk {

    Block::Block(int width, int height, int row, int column)
        : _width(width), _height(height), _row(row), _column(column)
    {

    };

    Block::~Block() {

    }

    std::ostream& operator<<(std::ostream& os, const Block& c) {
        // Rows
        for(int y = 0; y < c.height(); y++) {
            // Columns
            os << c.line(y) << std::endl;
        }
        return os;
    }


    char Block::fill = '.';


}
