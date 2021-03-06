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

	 Matrix E(2,2,3);
	 E += 2;
	 std::cout << std::endl << "E += 2" << std::endl << E;

	 Matrix F(3,3,4);
	 F -= 5;
	 std::cout << std::endl << "F -= 2" << std::endl << F;
	 

         Matrix G;
	 Matrix H(2,2,3);
	 G = 2 + H;

         std::cout << std::endl << "G = 2 + H " << std::endl << G;

	 Matrix I(2,2,6);
	 Matrix J; 
	 J = 3 - I;

	 std::cout << std::endl << "J = 3 - I " << std::endl << J;


         std::cout << std::endl << " J(1,1) " << std::endl << J(1,1);
	 std::cout << std::endl;
         
         
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
        
 
