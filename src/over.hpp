#pragma once

#include "block.hpp"


namespace blk {


    class Over: public Block {
        private:
            Expr _top;
            Expr _bottom;

            int _paddingLeft;

        public:
            Over(Expr top, Expr bottom);

            std::string line(int row) const;
    };

    Expr over(Expr e1, Expr e2);


}
