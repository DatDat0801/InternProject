#include "Bee.h"

#include "Shader.h"
#include "Model.h"
#include "Camera.h"
#include "Texture.h"
#include "Application.h"
#include "AnimationSprite.h"
#include "Sprite2D.h"
class AnimationSprite;
class Sprite2D;
Bee::Bee()
{

}
Bee::Bee(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader, std::shared_ptr<Texture> texture, int numFrames, float frameTime, float speed) : AnimationSprite(model, shader, texture, numFrames, frameTime), m_speed(speed), m_isStop(true)
{}


void Bee::Init()
{
	AnimationSprite::Init();
}

void Bee::Draw()
{
	AnimationSprite::Draw();
}


void Bee::Update(GLfloat deltatime)
{
	m_currentFrameTime += deltatime;
	if (m_currentFrameTime >= m_frameTime)
	{
		m_currentFrame++;
		if (m_currentFrame >= m_numFrames)
		{
			m_currentFrame = 0;
		}
		m_currentFrameTime -= m_frameTime;
	}

	if (this->GetPosition().y > -80 && m_isStop == false)
	{
		this->Set2DPosition(this->GetPosition().x, this->GetPosition().y - deltatime * m_speed);
	}
}
