//-----------------------------------------------------------------------------
//Author Tommas Solarino
//Description: Vector 2 .h
//-----------------------------------------------------------------------------

#ifndef VEC2_H
#define VEC2_H
#include <math.h>

class Mat3;

class Vec2
{
public:
	
	/// \brief  default constructor
	/// \param N/A
	/// \return N/A
	Vec2();

	/// \brief  Overload Constructor
	/// \param float x, y 
	/// \return Vector2
	Vec2(float X, float Y);

	/// \brief  Gets the length from one point to another (A2 + b2 = c2)
	/// \param N/A
	/// \return float
	float Length();

	/// \brief  Normalises
	/// \param N/A
	/// \return void
	void Normalise();

	/// \brief  Dot operator
	/// \param const Vector2 &rhs
	/// \return float
	float Dot(const Vec2 &rhs);

	
	
	/// \brief Gets the angle bettween two vectors
	/// \param const Vector2 &b
	/// \return float
	float GetAngleBetween(const Vec2 &b);

	
	/// \brief Perpedicular angle of the Vector2
	/// \param N/A
	/// \return Vector2
	Vec2 PerpendicularClockwise();
	
	
	/// \brief Perpedicular angle in the clocswise direction
	/// \param N/A
	/// \return Vector2
	Vec2 PerpendicularAntiClockwise(); 

	/// \brief Vector2 + Vector2
	/// \param const Vec2 &rhs
	/// \return Vector2
	Vec2 operator + (const Vec2 &rhs) const;
	
	/// \brief Vector2 - Vector2
	/// \param const Vec2 &rhs
	/// \return Vector2
	Vec2 operator - (const Vec2 &rhs) const;
	
	/// \brief Vector2 * Scalar
	/// \param const float &rhs
	/// \return Vector2
	Vec2 operator * (const float &rhs);
	
	/// \brief Vector2 / Scalar
	/// \param const float &rhs
	/// \return Vector2
	Vec2 operator / (const float &rhs);
	
	/// \brief Vector2 * Vector2
	/// \param const Vec2 &rhs
	/// \return Vector2
	Vec2 operator * (const Vec2 &rhs);

	/// \brief Vector2 / Vector2
	/// \param const Vec2 &rhs
	/// \return Vector2
	Vec2 operator / (const Vec2 &rhs);

	/// \brief Vector2 * Matrix3
	/// \param const Mat3 &rhs
	/// \return Vector2
	Vec2 operator * (const Mat3 &rhs);

	/// \brief Vector2 += Vector2
	/// \param const Vec2 &rhs
	/// \return Vector2
	Vec2& operator += (const Vec2 &rhs);
	
	/// \brief Vector2 -= Vector2
	/// \param const Vec2 &rhs
	/// \return Vector2
	Vec2& operator -= (const Vec2 &rhs);
	
	/// \brief Vector2 *= Scalar
	/// \param const float &rhs
	/// \return Vector2
	Vec2& operator *= (const float &rhs);
	
	/// \brief Vector2 /= Scalar
	/// \param const float &rhs
	/// \return Vector2
	Vec2& operator /= (const float &rhs);
	
	/// \brief Vector2 *= Vector2
	/// \param const Vec2 &rhs
	/// \return Vector2
	Vec2& operator *= (const Vec2 &rhs);
	
	/// \brief Vector2 /= Vector2
	/// \param const Vec2 &rhs
	/// \return Vector2
	Vec2& operator /= (const Vec2 &rhs);


	float x;
	float y;

protected:
private:


};

#endif