#pragma once

#include <string>
#include <algorithm>
#include <memory>
#include <cstdlib>

#include "block.hpp"


namespace blk {


    class Beside: public Block {
        private:
            Expr _left;
            Expr _right;

            int _paddingTopForLeft;
            int _paddingTopForRight;
            int _absPaddingBottomForLeft;
            int _absPaddingBottomForRight;

        public:
            Beside(Expr left, Expr right);

            virtual std::ostream& line(std::ostream& os, int row) const;
    };

    Expr beside(Expr e1, Expr e2);


}
