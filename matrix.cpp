#include "matrix.h"
#include "vector.h"

Matrix::Matrix(int c, int r, int v)
{
      col = c;
      row = r;   

	if (col < 1 || row < 1 )
     {
       matrix = NULL;
       row = 0;
       col = 0; 
     }

  matrix = new Vector[row];
    for (int i = 0; i < row; i++)
      matrix[i] =  Vector(col, v);
}

Matrix::Matrix(const Matrix & t)
{
   matrix = new Vector[t.row];
 
   row = t.row;
   col = t.col;

   for (int i = 0; i < row; i++)
      matrix[i] = t.matrix[i];
}

Matrix::~Matrix()
{	   
	delete [] matrix;     
}

Matrix & Matrix::operator=(const Matrix & t)
{
	if (this == &t)
          return *this;

      
	 delete [] matrix;
       
        matrix = new Vector[t.row];


	row = t.row;
        col = t.col;
      
        for (int i = 0; i < row; i++)
        matrix[i] = t.matrix[i];

        return *this;
}

std::ostream & operator<<(std::ostream & os, const Matrix & t)
{
  for (int i = 0; i < t.row; i++)
    {
       std::cout << t.matrix[i]; 
       std::cout << std::endl;
    }

  return os;
}

std::istream & operator>>(std::istream & is, const Matrix & t)
{
   for (int i = 0; i < t.row; i++)
      std::cin >> t.matrix[i];

   return is;
}


Matrix  Matrix::operator+(const Matrix & t) const
{
   if (t.row != row || t.col != col)
      {
	throw "You cannot add different matrixes";
      }

   Matrix temp(col, row);
   
    for (int i = 0; i < row; i++)
       temp.matrix[i] = t.matrix[i] + matrix[i];

  return temp;

}

Matrix   Matrix::operator-(const Matrix & t) const
{
    if (t.row != row || t.col != col)
      throw "You cannot substract different matrixes";

    Matrix temp(col, row);

         for (int i = 0; i < row; i++)
       temp.matrix[i] = t.matrix[i] - matrix[i];

      return temp;
}
 

Matrix Matrix::operator*(const double multi) const
{
   Matrix temp((*this).col, (*this).row);

    for (int i = 0; i < (*this).row; i++)
        temp.matrix[i] = (*this).matrix[i] * multi;

        return temp;

}

bool   Matrix::operator==(const Matrix & t) const
{
    if (t.row == row)
      {
          for (int i = 0; i < row; i++)
            if ((matrix[i] == t.matrix[i]) == 0)
                return false;
	
	   else
		return true;
      }
  
    else if (t.row != row)
        return false;
  
}

Matrix & Matrix::operator+=(const Matrix & t)
{
      if (row == t.row && col == t.col)
           for (int i = 0; i < row; i++)
		matrix[i] += t.matrix[i];
       else
          throw "You cannot add different matrixes ";

     return *this;
}

Matrix & Matrix::operator-=(const Matrix & t)
{
      if (row == t.row && col == t.col)
           for (int i = 0; i < row; i++)
		matrix[i] -= t.matrix[i];
       else
          throw "You cannot substract different matrixes ";

	return *this;
}

Matrix & Matrix::operator*=(const double multi)
{
	for (int i = 0; i < row; i++)
           (*this).matrix[i] *= multi;
}

bool   Matrix::operator!=(const Matrix & t) const
{ 
     int x;
     x = (*this) == t;

     if (x)
      return false;
     else 
      return true;
}



   
