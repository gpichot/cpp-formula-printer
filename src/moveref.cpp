#include "moveref.hpp"

namespace blk {

    MoveRef::MoveRef(Expr e, int column, int row)
        : _block(e), Block(e->width(), e->height(), column, row)
    {

    }

    MoveRef::~MoveRef() {

    }

    std::ostream& MoveRef::line(std::ostream& os, int row) const {

        _block->line(os, row);    

        return os;
    }

}
