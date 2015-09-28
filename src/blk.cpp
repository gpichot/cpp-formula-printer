#include "blk.hpp"


namespace blk {


    Expr move_ref(Expr e, int column, int row) {
        return std::make_shared<MoveRef>(e, column, row);
    }


}
