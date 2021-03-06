#pragma once

#include <iostream>
#include <iomanip>
#include <memory>
#include <algorithm>


namespace blk {
    class Block;

    using Expr = std::shared_ptr<Block>;

    class Block {

        public:
            Block() {};
            Block(int width, int height, int column, int row);
            ~Block();

            virtual std::ostream& line(std::ostream& os, int row) const = 0;

            inline int height() const {
                return _height;
            }
            inline int width() const {
                return _width;
            }
            inline int row() const {
                return _row;
            }
            inline int column() const {
                return _column;
            }
            inline int leftPadding() const {
                return _column;
            }
            inline int rightPadding() const {
                return _width - _column - 1;
            }
            inline int topPadding() const {
                return _row;
            }
            inline int bottomPadding() const {
                return _height - _row;
            }
            inline int minLine() const {
                return -_row;
            }
            inline int maxLine() const {
                return bottomPadding();
            }

            static char fill;

        protected:
            int _height;
            int _width;

            int _row;
            int _column;

            friend std::ostream& operator<<(std::ostream& os, const Expr& c);

    };


}
