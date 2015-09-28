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
        blk::Expr right = beside(text(" + "), e2);
        return move_ref(beside(
            e1,
            right
        ), e1->column() + 2, right->row());
    }

    Expr operator/(Expr e1, Expr e2) {
        blk::Expr bottom = over(
            text(
                std::string(std::max(e1->width(), e2->width()), '-')
            ),
            e2
        );
        return move_ref(over(
            e1,
            bottom
        ), bottom->column(), e1->height());
    }

    Expr operator==(Expr e1, Expr e2) {
        return beside(
                e1,
                beside(
                    text(" = "),
                    e2
                    )
                );
    }


}
