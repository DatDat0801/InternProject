#pragma once
#include "Sprite2D.h"

class Bullet: public Sprite2D
{
public:
	Bullet();
	Bullet(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, float speed);
	void		Init() override;
	void		Draw() override;
	void		Update(GLfloat deltatime) override;
	bool m_isStop;

	float m_speed;
	float m_x;
	float m_y;
	float m_radius=10;
};

