#ifndef VECTOR123
#define VECTOR123

#include <iostream>

class Vector
{
private:
  int * vector;
  int size;
public:
  
/* konstruktory i destruktory */
  explicit Vector(int size_c = 2, int value = 0);
  Vector(const Vector & t);  // kontruktor kopiujacy

  /* przeciazone operatory */
  Vector operator+(const Vector & t) const;
  Vector operator-(const Vector & t) const;
  Vector operator*(const double multi) const;
  void operator+=(const Vector & t);
  void operator-=(const Vector & t);
  void operator*=(const double multi);
  bool   operator==(const Vector & t) const;
  bool   operator!=(const Vector & t) const;
  int    operator[](int i) const;
  Vector & operator=(const Vector & t); /* operator przypisania  */
  ~Vector();



  /* funkcje zaprzyjaznione */
  friend Vector operator*(const double multi, const Vector & t);
  friend std::ostream & operator<<(std::ostream & os, const Vector & t);
  friend std::istream & operator>>(std::istream & os, const Vector & t);



};

#endif
