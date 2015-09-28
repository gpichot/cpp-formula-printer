#pragma once

#include <iostream>


#include "block.hpp"


namespace blk {

    class MoveRef: public Block {

        public:
            MoveRef(Expr e, int column, int row);
            ~MoveRef(); 

            virtual std::ostream& line(std::ostream& os, int row) const;

        private:
            Expr _block;

    };

}
