#include "over.hpp"


namespace blk {

    Over::Over(Expr top, Expr bottom)
        : _top(top), _bottom(bottom)
    {
        int paddingLeft = std::max(_top->leftPadding(), _bottom->leftPadding());
        int paddingRight = std::max(_top->rightPadding(), _bottom->rightPadding());
        int globalPadding = _bottom->leftPadding() - _top->leftPadding();
        if(globalPadding < 0) {
            globalPadding = _top->column();
        } else {
            globalPadding += _top->column();
        }

        // int _paddingLeft = globalPadding - _top->column();

        _height = _top->height() + _bottom->height();
        _width = paddingLeft + 1 + paddingRight;
        _row = _top->row();
        _column = globalPadding;
    }

    std::ostream& Over::line(std::ostream& os, int row) const {

        if(row < _top->height()) {
            // Print top block
            os << std::string(leftPadding() - _top->leftPadding(), Block::fill);
            _top->line(os, row);
            os << std::string(rightPadding() - _top->rightPadding(), Block::fill);
        } else {
            // Print bottom block
            os << std::string(leftPadding() - _bottom->leftPadding(), Block::fill);
            _bottom->line(os, row - _top->height());
            os << std::string(rightPadding() - _bottom->rightPadding(), Block::fill);
        }

        return os;
    }

    Expr over(Expr e1, Expr e2) {
        return std::make_shared<Over>(e1, e2);
    }

}
