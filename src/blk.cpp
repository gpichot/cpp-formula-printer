#include "blk.hpp"


namespace blk {


    Expr debug(char c, int width, int height, int column, int row) {
        return std::make_shared<Debug>(c, width, height, column, row);
    }

    Expr over(Expr e1, Expr e2) {
        return std::make_shared<Over>(e1, e2);
    }

    Expr beside(Expr e1, Expr e2) {
        return std::make_shared<Beside>(e1, e2);
    }

    Expr move_ref(Expr e, int column, int row) {
        return std::make_shared<MoveRef>(e, column, row);
    }
    Expr text(std::string&& str, Text::Alignment alignment) {
        return std::make_shared<Text>(str, alignment);
    }

    Expr operator+(Expr e1, Expr e2) {
        std::string sep(1, blk::Block::fill);
        blk::Expr right = beside(
            text(sep + "+" + sep),
            e2
        );
        return move_ref(beside(
            e1,
            right
        ), e1->column() + 2, right->row());
    }

    Expr operator/(Expr e1, Expr e2) {
        int size = std::max(e1->width(), e2->width());
        if(e1->height() > 1 || e2->height() > 1) {
            size += 2;
        }

        blk::Expr bottom = over(
            text(std::string(size, '-')),
            e2
        );
        return move_ref(over(
            e1,
            bottom
        ), bottom->column(), e1->height());
    }

    Expr operator==(Expr e1, Expr e2) {
        std::string sep(1, blk::Block::fill);
        blk::Expr right = beside(
            text(sep + "=" + sep),
            e2
        );
        return move_ref(beside(
            e1,
            right
        ), e1->column() + 2, std::max(e1->row(), e2->row()));
    }


}
