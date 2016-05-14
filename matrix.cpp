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

  matrix = new Vector * [row];
  
  for (int i = 0; i < row; i++)
     *(matrix + i) = new Vector(col, v);
     
   
}

Matrix::Matrix(const Matrix & t)
{
   matrix = new Vector * [t.row];
 
   row = t.row;
   col = t.col;

   for (int i = 0; i < row; i++)
     { matrix[i] = new Vector(col);
	*(*(matrix + i)) = *(*(t.matrix + i));
     }

       	
}

Matrix::~Matrix()
{	   
	for (int i = 0; i < row; i++)
           delete  *(matrix + i);

        delete [] matrix;
              
         
}

Matrix & Matrix::operator=(const Matrix & t)
{
	if (this == &t)
          return *this;

         for (int i = 0; i < row; i++)
           delete   *(matrix + i);

           delete [] matrix;
       
        matrix = new Vector * [t.row];


	row = t.row;
        col = t.col;
      
        for (int i = 0; i < row; i++)
	   *(matrix + i) = new Vector(t.col); 

        for (int j = 0; j < row; j++)
	    *(*(matrix + j)) = *(*(t.matrix + j)); 


        return *this;
}

std::ostream & operator<<(std::ostream & os, const Matrix & t)
{
  for (int i = 0; i < t.row; i++)
    {
       std::cout << (*(*(t.matrix + i)))[i];      // (*t.matrix)[i];
       std::cout << std::endl;
    }

  return os;
}

std::istream & operator>>(std::istream & is, const Matrix & t)
{
   for (int i = 0; i < t.row; i++)
      std::cin >>   *(*(t.matrix + i));

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
	*(*(temp.matrix + i)) =   *(*(t.matrix + i)) + *(*(matrix + i));  

// (*temp.matrix)[i] = (*t.matrix)[i] + (*matrix)[i];

  return temp;

}

Matrix  Matrix::operator+(const int t) const
{
	Matrix temp(col, row, t);
        temp = temp + (*this);
	return temp;
}

Matrix    operator+(const int a, const Matrix & t)
{ 
        return t + a;
}        

Matrix   Matrix::operator-(const Matrix & t) const
{
    if (t.row != row || t.col != col)
      throw "You cannot substract different matrixes";

    Matrix temp(col, row);

         for (int i = 0; i < row; i++)
            *(*(temp.matrix + i)) =   *(*(matrix + i)) - *(*(t.matrix + i)); 



      return temp;
}

Matrix  Matrix::operator-(const int t) const
{
	Matrix temp(col, row, t);
	temp = (*this) - temp;
	return temp;
}


Matrix operator-(const int a, const Matrix & t)
{
 	return (t - a) * (-1);
}

Matrix Matrix::operator*(const int multi) const
{
   Matrix temp((*this).col, (*this).row);

    for (int i = 0; i < (*this).row; i++)
       *(*(temp.matrix + i)) = *(*(matrix + i)) * multi;

  

        return temp;

}

bool   Matrix::operator==(const Matrix & t) const
{
    if (t.row == row)
      {
          for (int i = 0; i < row; i++)
            if (  *(*(matrix + i)) == *(*(t.matrix + i)) == 0)
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
	    *(*(matrix + i)) += *(*(t.matrix + i));		
	
       else
          throw "You cannot add different matrixes ";

     return *this;
}

Matrix &  Matrix::operator+=(const int t)
{
	Matrix temp(col, row, t);
	(*this) += temp;
	return (*this);
}


Matrix & Matrix::operator-=(const Matrix & t)
{
      if (row == t.row && col == t.col)
           for (int i = 0; i < row; i++)
		*(*(matrix + i)) -= *(*(t.matrix + i));
       else
          throw "You cannot substract different matrixes ";

	return *this;
}

Matrix & Matrix::operator-=(const int t)
{
	Matrix temp(col, row, t);
        (*this) -= temp;
}
        


Matrix & Matrix::operator*=(const int multi)
{
	for (int i = 0; i < row; i++)
            *(*(matrix + i)) *= multi;
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

int      Matrix::operator()(const int c, const int r)
{
	if ( c < 0 || r < 0 || c > col || r > row)
	   throw "You are out of range! ";

	return (*(*(matrix + r)))[c];
}



   
