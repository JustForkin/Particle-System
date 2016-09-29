#include "Vector.h"
#include <math.h>

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
Vector::Vector() {

	this->x = 0;
	this->y = 0;
	this->z = 0;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
Vector::Vector(const Vector& v) {

	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
Vector::Vector(const double x, const double y, const double z) {

	this->x = x;
	this->y = y;
	this->z = z;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
void Vector::set(const double x, const double y, const double z) {

	this->x = x;
	this->y = y;
	this->z = z;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
void Vector::set(const Vector& v) {

	this->set(v.x, v.y, v.z);
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
double Vector::getX() const {

	return x;
}

double Vector::getY() const {

	return y;
}

double Vector::getZ() const {

	return z;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
double Vector::magnitude() const {

	return sqrt(x * x + y * y + z * z);
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
 Vector Vector::asUnitVector () const {

    double m = this->magnitude();

    Vector v(x/m, y/m, z/m);

	return v;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
Vector Vector::scaled(const double scaleFactor) const {

	double m = this->magnitude();

     Vector v(
		 x * scaleFactor / m,
		 y * scaleFactor / m,
		 z * scaleFactor / m);

	 return v;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
Vector Vector::multiply(const double scaleFactor) const {

    Vector res(
    	x * scaleFactor,
    	y * scaleFactor,
    	z * scaleFactor);

 	return res;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
Vector Vector::add(const Vector& v) const {

    Vector res(x + v.x, y + v.y, z + v.z);

    return res;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
Vector Vector::vectorTo(const Vector& v) const {

	 Vector res(v.x - x, v.y - y, v.z - z);

	 return res;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
bool Vector::withinSphere (
	const Vector* center, const double radius) const {

	double magnitudeSqr =
      (x - center->x) * (x - center->x) +
      (y - center->y) * (y - center->y) +
      (z - center->z) * (z - center->z);

    return magnitudeSqr < radius * radius;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
Vector Vector::copy() const {

	Vector v(x, y, z);

	return v;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
Vector Vector::fromArray(const double* data) {

	Vector v(data[0], data[1], data[2]);

	return v;
}
