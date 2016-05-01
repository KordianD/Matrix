#include <iostream>
#include "vector.h"
#include "matrix.h"
#include <stdlib.h>

int main()
{
     try 
       {
         Matrix A(2,2,1), B;
         B = A;
         std::cout << std::endl << "A = B " << std::endl << A;
         std::cout << std::endl << "A + B " << std::endl << A + B;
         std::cout << std::endl << "A - B " << std::endl << A - B;
         std::cout << std::endl << "A * 5 " << std::endl << A * 5;
         A += B;
	 std::cout << std::endl << "A += B " << std::endl << A;
	 A -= B;	
	 std::cout << std::endl << "A -= B " << std::endl << A;
         A *= 5;
	 std::cout << std::endl << "A *= 5 " << std::endl << A;
         std::cout << std::endl << "A == B " << std::endl << int (A == B);
	 std::cout << std::endl << "A != B " << std::endl << int (A != B); 
	 
	 Matrix C(A);
	 std::cout << std::endl << "C(A) "   << std::endl << C;


         
         
       }
   
      catch(const char * s)
      { 
        std::cout << s << std::endl;
        std::cout << "Koncze wykonywanie programu " << std::endl << std::endl;
        exit(EXIT_FAILURE);
      }

      catch(std::bad_alloc & c)
      {
        std::cout << c.what() << std::endl;
        std::cout << "Koncze wykonywanie programu" << std::endl << std::endl;
      }

  return 0;
}
        
 
