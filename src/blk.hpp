#pragma once

#include "block.hpp"
#include "debug.hpp"
#include "over.hpp"
#include "beside.hpp"
#include "moveref.hpp"
#include "text.hpp"


namespace blk {


    Expr debug(char c, int width, int height, int column, int row);
    Expr over(Expr e1, Expr e2);
    Expr beside(Expr e1, Expr e2);
    Expr move_ref(Expr e, int column, int row);
    Expr text(std::string&& str, Text::Alignment alignment);


}
