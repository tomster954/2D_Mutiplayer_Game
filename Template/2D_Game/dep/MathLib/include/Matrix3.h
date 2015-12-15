//-----------------------------------------------------------------------------
//Author Tommas Solarino
//Description: Vector 2 .h
//-----------------------------------------------------------------------------

#ifndef MATRIX3_H
#define MATRIX3_H
#include <math.h>
#include "Vec2.h"

class Mat3
{
public:
	/// \brief Default Constructor
	/// \param N/A
	/// \return	N/A
	Mat3();

	/// \brief Constructor for the matrix (Set floats in params)
	/// \param float m1, m2, m3, m4, m5, m6, m7, m8, m9 
	/// \return N/A
	Mat3(float M1, float M2, float M3, 
		 float M4, float M5, float M6,
		 float M7, float M8, float M9);

	/// \brief Default Destructor
	/// \param N/A
	/// \return	N/A
	~Mat3();

	/// \brief Creates an identity Matrix3
	/// \param N/A
	/// \return	void
	void Mat3::CreateIdentity();				

	/// \brief Creates Translation Matrix3
	/// \param float x, y
	/// \return void
	void CreateTranslation(float x, float y);	

	/// \brief Translates the Matrix3 by a Vector2
	/// \param Vector2
	/// \return void
	void TranslateMat3(const Vec2& translate);

	/// \brief Translates the Matrix3 by two floats
	/// \param float x, y
	/// \return void
	void TranslateMat3(float x, float y);

	/// \brief Creates a Scale Matrix3
	/// \param float sx, sy
	/// \return void
	void CreateScale(float sx, float sy);		

	/// \brief Scales the Matrix3
	/// \param float sx, sy
	/// \return void
	void ScaleMat3(float sx, float sy);

	/// \brief Creates a Rotated Matrix3
	/// \param float rot
	/// \return void
	void CreateRotation(float rot);

	/// \brief Rotates the Matrix3
	/// \param float rot
	/// \return void 
	void Rotate(float rot);

	/// \brief Displays the Matrix3 
	/// \param N/A
	/// \return void 
	void DisplayMat3();				

	/// \brief Gets the up rotation
	/// \param N/A
	/// \return float 
	float GetUpRot();

	/// \brief Sets the up rotation
	/// \param float uRot
	/// \return void 
	void SetUpRot(float uRot);

	/// \brief Gets the up direction
	/// \param float uRot
	/// \return Vector2 
	Vec2 GetUpDirection();

	/// \brief Gets the right rotation
	/// \param N/A
	/// \return float
	float GetRightRot();
	
	/// \brief Sets the right rotation
	/// \param float rRot
	/// \return void
	void SetRightRot(float rRot);

	/// \brief Gets the translation
	/// \param N/A
	/// \return Vector2
	Vec2 GetTranslation();

	/// \brief Gets the scale
	/// \param N/A
	/// \return Vector2
	Vec2 GetScale();

	/// \brief Multiplys a Matrix3 by a Matrix3
	/// \param const Matrix3 &rhs
	/// \return Matrix3
	Mat3 operator * (const Mat3 &rhs) const;

	/// \brief Multiply equal a Matrix3 by a Matrix3
	/// \param const Matrix3 &rhs
	/// \return Matrix3
	Mat3& operator *= (const Mat3 &rhs);


	float	m1,	m2,	m3,
			m4,	m5,	m6,
			m7,	m8,	m9;
			


private:

};


#endif
