# C++ Formula Printer

A C++ library that formats a mathematical expression as a string.

## Examples

For instance:

        blk::Expr x = blk::text("x");
        blk::Expr y = blk::text("y");
        blk::Expr z = blk::text("z");
                    
        blk::Block::fill = ' ';

        std::cout << (( y / ( z + x )) == ( z + x / y ) / ( x + y + z ) / ( x + z / y ) == x ) << std::endl;

will outputs:
    
       -5 :                  x        
       -4 :              z + -        
       -3 :                  y        
       -2 :           -----------     
       -1 :    y       x + y + z      
        0 :  ----- = ------------- = x
        1 :  z + x           z        
        2 :              x + -        
        3 :                  y        
