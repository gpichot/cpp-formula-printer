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
            inline int topPadding() const {
                return _row;
            }
            inline int bottomPadding() const {
                return _column;
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


}
