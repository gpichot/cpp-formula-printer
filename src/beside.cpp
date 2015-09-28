#include "beside.hpp"


namespace blk {

    
    Beside::Beside(Expr left, Expr right)
        : _left(left), _right(right)
    {
        
        int maxPaddingTop = std::max(_left->topPadding(), _right->topPadding()); 
        int maxPaddingBottom = std::max(left->bottomPadding(), _right->bottomPadding());

        
        _height = maxPaddingTop + 1 + maxPaddingBottom;
        _width = _left->width() + _right->width();
        _row = maxPaddingTop;
        _column = _left->column(); 

        _paddingTopForLeft = maxPaddingTop - _left->topPadding();
        _paddingTopForRight = maxPaddingTop - _right->topPadding();
        _absPaddingBottomForLeft = _row + _left->bottomPadding();
        _absPaddingBottomForRight = _row + _right->bottomPadding();
        
    }

    std::ostream& Beside::line(std::ostream& os, int row) const {

        // Left block
        if(row < _paddingTopForLeft 
          || row >= _absPaddingBottomForLeft) {
            os << std::string(_left->width(), Block::fill);
        } else {
            _left->line(os, row - _paddingTopForLeft);
        }

        // Right block
        if(row < _paddingTopForRight
            || row >= _absPaddingBottomForRight) {
            os << std::string(_right->width(), Block::fill);
        } else {
            _right->line(os, row - _paddingTopForRight);
        }
        
        
    
        return os;    
    }

    
    Expr beside(Expr e1, Expr e2) {
        return std::make_shared<Beside>(e1, e2);
    }
}
