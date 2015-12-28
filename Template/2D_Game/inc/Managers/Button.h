//-----------------------------------------------------------------------------
//Author: Tom Solarino
//Description: This is a button class that will create buttons
//-----------------------------------------------------------------------------

#ifndef MY_BUTTON
#define MY_BUTTON
#include "SpriteLoad\Texture.h"
#include "Vec3.h"

class SpriteBatch_Imidiate;
class Application;

class Button
{
public:
	Button();
	Button(Vec2 a_pos, Texture *a_texture, Application *a_app);
	~Button();

	void Update();
	void Draw(SpriteBatch_Imidiate *a_SBI);

	void SetPosition(float a_x, float a_y);

	bool m_pressed;

private:
	Vec3 m_colour;
	Vec2 m_size;
	Vec2 m_pos;
	Texture *m_texture;
	Application *m_app;

};

#endif