#include "text.hpp"


namespace blk {

    Text::Text(std::string str, Alignment alignment)
        : _str(str), _alignment(alignment)
    {
        if(_alignment == Alignment::Left) {
            _column = 0;
        } else if (_alignment == Alignment::Center) {
            _column = str.size() / 2 + str.size() % 2 - 1;
        } else {
            _column = str.size() - 1;
        }
        
        _width = str.size();
        _height = 1;
        _row = 0;
    }

    Text::~Text() {

    }   

    std::ostream& Text::line(std::ostream& os, int row) const {
        
        return os;
    }

}
