#include <blk.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    blk::Expr x = blk::text("x");
    blk::Expr y = blk::text("y");
    blk::Expr z = blk::text("z");
    
    blk::Block::fill = ' ';


    std::cout << (  (y/(z+x)) == (z+x/y)/(x+y+z)/(x+z/y) == x  )
        << std::endl;
    return 0;
}

