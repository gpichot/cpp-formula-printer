#pragma once

#include <string>

#include "block.hpp"


namespace blk {

    class Text: public Block {

        public:
        enum Alignment {
            Left,
            Center,
            Right,
        };

        Text(std::string str, Alignment alignment);
        ~Text();

        virtual std::ostream& line(std::ostream& os, int row) const;

        private:
        std::string _str;
        Alignment _alignment;

    };


}
