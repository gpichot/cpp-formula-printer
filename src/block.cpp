#include "block.hpp"


namespace blk {


    Block::Block(int width, int height, int column, int row)
        : _width(width), _height(height), _row(row), _column(column)
    {

    };

    Block::~Block() {

    }

    std::ostream& operator<<(std::ostream& os, const Expr& e) {
        // Columns
        for(int y = 0; y < e->height(); y++) {
            os << std::setw(5) << (y - e->row()) << " :  ";
            e->line(os, y) << std::endl;
        }
        return os;
    }


    char Block::fill = '.';


}
