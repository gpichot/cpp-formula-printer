#pragma once

#include <string>

#include "block.hpp"


namespace blk {


    class Over: public Block {
        private:
            Expr _top;
            Expr _bottom;

        public:
            Over(Expr top, Expr bottom);

            virtual std::ostream& line(std::ostream& os, int row) const;
    };


}
