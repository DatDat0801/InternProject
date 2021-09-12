#pragma once
#include "AnimationSprite.h"
#include "Sprite2D.h"
class AnimationSprite;
class Sprite2D;

class Bird : public AnimationSprite
{
public:
	Bird();
	Bird(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, int numFrames, float frameTime, float speed);
	void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;

	bool m_isStop=true;
	float m_speed;
	float m_x;
	float m_y;
	float m_radius = 27;
};

