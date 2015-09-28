#include "over.hpp"


namespace blk {

    Over::Over(Expr top, Expr bottom)
        : _top(top), _bottom(bottom)
    {
        int maxPaddingLeft = std::max(_top->leftPadding(), _bottom->leftPadding());
        int maxPaddingRight = std::max(_top->rightPadding(), _bottom->rightPadding());

        _height = _top->height() + _bottom->height();
        _width = maxPaddingLeft + 1 + maxPaddingRight;
        _row = _top->row();
        _column = maxPaddingLeft;
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
