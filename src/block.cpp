#include "block.hpp"


namespace blk {


    Block::Block(int width, int height, int column, int row)
        : _width(width), _height(height), _row(row), _column(column)
    {

    };

    Block::~Block() {

    }

    std::ostream& operator<<(std::ostream& os, const Block& c) {
        // Columns
        for(int y = 0; y < c.height(); y++) {
            os << std::setw(5) << (y - c.row()) << " :  ";
            c.line(os, y) << std::endl;
        }
        return os;
    }


    char Block::fill = '.';


}
