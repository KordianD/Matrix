#ifndef MATRIIIX
#define MATRIIIX
#include "vector.h"
#include <iostream>

class Matrix
{
private:
   
   Vector ** matrix;   
   int col;
   int row;
public:
   
   /* Constructors and destructors*/
   explicit Matrix(int c = 2, int r = 2, int v = 0);
   Matrix(const Matrix & t);
   virtual ~Matrix();
   
   /* Overloaded operators */
   Matrix & operator=(const Matrix & t); 
   Matrix   operator+(const Matrix & t) const;
   Matrix   operator+(const int t) const;
   Matrix   operator-(const Matrix & t) const;
   Matrix   operator-(const int t) const;
   Matrix   operator*(const int multi) const;
   Matrix & operator+=(const int t);
   Matrix & operator+=(const Matrix & t);
   Matrix & operator-=(const Matrix & t);
   Matrix & operator-=(const int t);
   Matrix & operator*=(const int multi);
   bool     operator==(const Matrix & t) const;
   bool     operator!=(const Matrix & t) const;
   int      operator()(const int c, const int r);
   
   /* friend functions */
   friend std::ostream & operator<<(std::ostream & os, const Matrix & t);
   friend std::istream & operator>>(std::istream & is, const Matrix & t);
   friend Matrix operator*(const int multi, const Matrix & t);
   friend Matrix operator+(const int a, const Matrix & t);
   friend Matrix operator-(const int a, const Matrix & t);	
   

};

#endif


