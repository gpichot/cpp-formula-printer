#pragma once

#include <iostream>
#include <memory>
#include <algorithm>


namespace blk {

    class Block {

        public:
            Block() {};
            Block(int width, int height, int row, int column)
                : _width(width), _height(height), _row(row), _column(column)
            {
            };
            ~Block();

            virtual std::string line(int row) const = 0;

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

            static char fill;

        protected:
            int _height;
            int _width;

            int _row;
            int _column;

            friend std::ostream& operator<<(std::ostream& os, const Block& c) {
                // Rows
                for(int y = 0; y < c._height; y++) {
                    // Columns
                    os << c.line(y) << std::endl;
                }
                return os;
            };

    };

    char Block::fill = '.';


    typedef std::shared_ptr<Block> Expr;


    class Debug: public Block {
        public:
            Debug(char c, int width, int height, int row, int column)
                : _fill(c), Block(width, height, row, column)
            {
            }

            virtual std::string line(int row) const {
                std::string lineString = "";

                // TODO: improve with repeat char?..
                for(int x = 0; x < _width; x++) {
                    if(row != _row || x != _column) {
                        lineString += _fill;
                    } else {
                        lineString += '+';
                    }
                }

                return lineString;
            }
        protected:
            char _fill;
    };

    Expr debug(char c, int width, int height, int row, int column) {
        return std::make_shared<Debug>(c, width, height, row, column);
    }


    class Over: public Block {
        private:
            Expr _top;
            Expr _bottom;

        public:
            Over(Expr top, Expr bottom)
                : _top(top), _bottom(bottom)
            {
                int paddingLeft = std::max(_top->leftPadding(), _bottom->leftPadding());
                int paddingRight = std::max(_top->rightPadding(), _bottom->rightPadding());
                int globalPadding = _bottom->leftPadding() - _top->leftPadding();
                if(globalPadding < 0) {
                    globalPadding = _top->column();
                } else {
                    globalPadding += _top->column();
                }

                _height = _top->height() + _bottom->height();
                _width = paddingLeft + 1 + paddingRight;
                _row = _top->row();
                _column = globalPadding;

            }

            virtual std::string line(int row) const {
                std::string lineString = "";

                // TODO: improve with repeat char?..
                for(int x = 0; x < _width; x++) {
                    lineString += Block::fill;
                }

                return lineString;
            }
    };

    Expr over(Expr e1, Expr e2) {
        return std::make_shared<Over>(e1, e2);
    }

}
