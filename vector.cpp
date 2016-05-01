#include "vector.h"
#include <iostream>


Vector::Vector(int size_c, int value)
{
  if (size_c < 1)
  {
      vector = NULL;
      size = 0;
      return;
  }

  size = size_c;
  vector = new int[size_c];
  int i;
  for (i = 0; i < size_c; i++)
    vector[i] = value;
}


Vector Vector::operator+(const Vector & t) const
{
  if (t.size == (*this).size)
   {
     Vector temp(t.size);
     for (int i = 0; i < t.size; i++)
       temp.vector[i] = (*this).vector[i] + t.vector[i];
     return temp;
   }

   else
   {
      throw "Niedozwolone dodawanie wektorow ";
   }
}

Vector Vector::operator-(const Vector & t) const
{
  if (t.size == (*this).size)
   {
     Vector temp(t.size);
     for (int i = 0; i < t.size; i++)
       temp.vector[i] = (*this).vector[i] - t.vector[i];
     return temp;
   }

   else
   {
      throw "Niedozwolone odejmowanie wektorow ";
   }
}

Vector Vector::operator*(const double multi) const
{
    Vector temp((*this).size);

    for (int i = 0; i < (*this).size; i++)
        temp.vector[i] = (*this).vector[i] * multi;

        return temp;

}

Vector operator*(const double multi, const Vector & t)
{
    Vector temp(t.size);

    for (int i = 0; i < t.size; i++)
        temp.vector[i] = t.vector[i] * multi;

    return temp;
}

std::ostream & operator<<(std::ostream & os, const Vector & t)
{
    for (int i = 0; i < t.size; i++)
    os << t.vector[i] << " ";

    return os;
}

std::istream & operator>>(std::istream & os, const Vector & t)
{
    int * pointer;
    pointer = new int[t.size];


     for (int i = 0; i < t.size; i++)
       std::cin >> pointer[i];

     for (int i = 0; i < t.size; i++)
        *(t.vector + i) = pointer[i];

     delete [] pointer;
     return os;
}

bool  Vector::operator==(const Vector & t) const
{
    int counter = 0;

    if (t.size == (*this).size)
    {
        for (int i = 0; i < t.size; i++)
            if (t.vector[i] == (*this).vector[i])
               counter++;
    }

   if (counter == t.size)
      return false;
   else
      return true;
}

bool  Vector::operator!=(const Vector & t) const
{
   int x;
   x = *this == t;

   if (x == 1)
    return false;
   else
    return true;
}

int    Vector::operator[](int i) const
{
    if (i >= (*this).size || i < 0)
        throw "Proba odczytu poza tablica";

    return (*this).vector[i];
}

void Vector::operator+=(const Vector & t)
{
    *this = *this + t;
}

void Vector::operator-=(const Vector & t)
{
    *this = *this - t;
}

void Vector::operator*=(const double multi)
{
   (*this) = (*this) * multi;

}

Vector & Vector::operator=(const Vector & t)    /* operator przypisania */
{
    if (this == &t)
        return *this;

    else if (size == t.size)
        {
            delete [] vector;
            vector = new int[size];
            for (int i = 0; i < size; i++)
                vector[i] = t.vector[i];
            return *this;
        }

		else
		{
			delete [] vector;
			vector = new int[t.size];
			size = t.size;
				for (int i = 0; i < size; i++) vector[i] = t.vector[i];
				return *this;
		}
}


Vector::Vector(const Vector & t)
{
    size = t.size;
    vector = new int[t.size];
     for (int i = 0; i < size; i++)
      vector[i] = t.vector[i];

}

Vector::~Vector()
{
    delete [] vector;
    size = 0;
}
