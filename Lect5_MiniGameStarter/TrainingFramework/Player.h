#pragma once
#include <iostream>
class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class AnimationSprite;

class Player
{
public:
	Player();
	void Init( );
	void Update(float deltaTime);
	void HandleInput();
	void Render();
	void Dispose();

private:
	// position
	float m_x;
	float m_y;
	float m_radius;

	// vector
	float m_dx;
	float m_dy;
	float m_speed;

	//movement
	bool m_up;
	bool m_down;

	std::shared_ptr<Sprite2D>		m_player;
};
