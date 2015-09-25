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

        _paddingLeft = globalPadding - _top->column();

        _height = _top->height() + _bottom->height();
        _width = paddingLeft + 1 + paddingRight;
        _row = _top->row();
        _column = globalPadding;
    }

    std::string Over::line(int row) const {
        std::string lineString = "";

        // TODO: improve with repeat char?..
        for(int x = 0; x < _width; x++) {
            // Top block
            if(row < _top->height()) {
                if(x < _paddingLeft) {
                    lineString += Block::fill;       
                } else {
                    lineString += _top->line(row);
                    x += _top->width() - 1;
                }
            } else {
                if(x < _paddingLeft) {
                    lineString += _bottom->line(row - _top->height());
                    x += _bottom->width() - 1;
                } else {
                    lineString += Block::fill;
                }
            }
        }

        return lineString;
    }

    Expr over(Expr e1, Expr e2) {
        return std::make_shared<Over>(e1, e2);
    }

}
