#include "Particle.h"

///////////////////////////////////////////////////////////////////
// constructor
//
///////////////////////////////////////////////////////////////////
Particle::Particle() {

	this->_radius = 0.03;
	this->reset();
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
Vector* Particle::getAcceleration() {

	return &_acceleration;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
Vector* Particle::getPosition() {

	return &_position;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
Vector* Particle::getVelocity() {

	return &_velocity;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
Vector* Particle::getDof() {

	return &_dof;
}

void Particle::setDof(Vector* dof) {

	_dof.set(*dof);
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
void Particle::setCharge(double charge) {

	_charge = charge;
}

double Particle::getCharge() {

	return _charge;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
void Particle::setRecycled(bool recycled) {

	_recycled = recycled;
}

bool Particle::getRecycled() {

	return _recycled;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
double Particle::getLifeTime () {

	return _lifeTime;
}

void Particle::setLifeTime (double lifeTime) {

	_lifeTime = lifeTime;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
double Particle::getRadius () {

	return _radius;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
void Particle::step(double dt) {

	_lifeTime -= dt;

    _velocity.x += _acceleration.x * dt;
    _position.x += _velocity.x * _dof.x * dt;
				    
    _velocity.y += _acceleration.y * dt;
    _position.y += _velocity.y * _dof.y * dt;
				    
    _velocity.z += _acceleration.z * dt;
    _position.z += _velocity.z * _dof.z * dt;
}

///////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////////////////////////////
void Particle::reset() {

	_recycled = false;
 	_lifeTime = 30.0;
}