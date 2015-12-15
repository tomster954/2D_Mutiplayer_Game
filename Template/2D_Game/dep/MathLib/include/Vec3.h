//-----------------------------------------------------------------------------
//Author Tommas Solarino
//Description: Vector 2 .h
//-----------------------------------------------------------------------------

#ifndef VEC3_H
#define VEC3_H
#include <math.h>


class Vec3
{
public:
	
	// default constructor
	Vec3();

	// overload Constructor
	Vec3(float X, float Y, float Z);

	//length function:: Gets the hypot (A2 + b2 = c2)
	float Length();

	//MNormalise Function
	void Normalise();

	//Dot function
	float Dot(const Vec3 &rhs);

	// Gets the angle bettween two vectors
	float GetAngleBetween(const Vec3 &b);

	//Perpedicular angle of the vec
	Vec3 PerpendicularClockwise();
	
	//Perpedicular angle in the clocswise direction
	Vec3 PerpendicularAntiClockwise(); 

	//Method 2
	// Vec2 + Vec2
	Vec3 operator + (const Vec3 &rhs) const;
	// Vec2 - Vec2
	Vec3 operator - (const Vec3 &rhs) const;
	// Vec2 * Scalar
	Vec3 operator * (const float &rhs);
	// Vec2 / Scalar
	Vec3 operator / (const float &rhs);
	// Vec2 * Vec2
	Vec3 operator * (const Vec3 &rhs);
	// Vec2 / Vec2
	Vec3 operator / (const Vec3 &rhs);
	

	// Vec2 += Vec2
	Vec3& operator += (const Vec3 &rhs);
	// Vec2 -=  Vec2
	Vec3& operator -= (const Vec3 &rhs);
	// Vec2 *= Scalar
	Vec3& operator *= (const float &rhs);
	//Vec2 /= Scalar
	Vec3& operator /= (const float &rhs);
	// Vec2 *= Vec2
	Vec3& operator *= (const Vec3 &rhs);
	// Vec2 /= Vec2
	Vec3& operator /= (const Vec3 &rhs);


	float x;
	float y;
	float z;

protected:
private:


};
#endif