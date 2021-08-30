#include "GSPlay.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "../AnimationSprite.h"
#include "../Bullet.h"

#include <mmsystem.h>
#include<mciapi.h>
#pragma comment(lib,"Winmm.lib")
#define MaxY 100
#define MinY 700
class AnimationSprite;
class Bullet;
GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_main_menu.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// button clode
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close2.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(70, 50);
	button->SetOnClick([]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	texture = ResourceManagers::GetInstance()->GetTexture("bullet.tga");
	for (int i = 0; i < 7; i++)
	{
		std::shared_ptr<Bullet> _bullet = std::make_shared<Bullet>(model, shader, texture, 400); 
		_bullet->Set2DPosition((float)Globals::screenWidth / 2-400, (float)Globals::screenHeight / 2);
		_bullet->SetSize(30, 30);
		m_bullets.push_back(_bullet);
	}

	// character
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close2.tga");
	//shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	//m_player = std::make_shared<AnimationSprite>(model, shader, texture, 3, 0.5f);
	m_player = std::make_shared<Sprite2D>(model, shader, texture);
	m_player->Set2DPosition(60, 700);//(float)Globals::screenWidth / 2 , (float)Globals::screenHeight / 2. y->700-100
	m_player->SetSize(130, 80);



	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_score = std::make_shared< Text>(shader, font, "score: 10", TextColor::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	mciSendString("open \"D:/GL Project/InternProject/Lect5_MiniGameStarter/Data/Sounds/Shoot.mp3\" type mpegvideo alias mp3", NULL, 0, NULL);
}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed)
	{
		switch (key)
		{
		case 'J':
			keyPressed |= KEY_MOVE_SHOOT;
			break;
		case 'W':
			keyPressed |= KEY_MOVE_FORWORD;
			break;
		case 'S':
			keyPressed |= KEY_MOVE_BACKWORD;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case 'J':
			keyPressed ^= KEY_MOVE_SHOOT;
			break;
		case 'W':
			keyPressed ^= KEY_MOVE_FORWORD;
			break;
		case 'S':
			keyPressed ^= KEY_MOVE_BACKWORD;
			break;
		default:
			break;
		}
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}

int countTime = 0;
void GSPlay::Update(float deltaTime)
{
	if (keyPressed & KEY_MOVE_SHOOT)
	{
		/*auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");*/
		//auto texture = ResourceManagers::GetInstance()->GetTexture("btn_close2.tga");
		//auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
		//m_bullet = std::make_shared<Bullet>(model, shader, texture, 400); //, 20
		//m_bullet->Set2DPosition(m_player->GetPosition().x, m_player->GetPosition().y);//(float)Globals::screenWidth / 2 , (float)Globals::screenHeight / 2. y->700-100
		//m_bullet->SetSize(130, 90);

		std::shared_ptr<Bullet> _bullet;
		for (int i = 0; i < m_bullets.size(); i++)
		{
			if (m_bullets.at(i)->m_isStop==true && countTime<=0)
			{
				_bullet = m_bullets.at(i);
				_bullet->Set2DPosition(m_player->GetPosition().x+100, m_player->GetPosition().y);//(float)Globals::screenWidth / 2 , (float)Globals::screenHeight / 2. y->700-100
				_bullet->m_isStop = false;
				shooted = true;
				countTime = 10;
				
				//mciSendString("play mp3", NULL, 0, NULL);
				break;
			}
		}
	}
	if (countTime > 0)
	{
		countTime -= deltaTime;
	}

	if (keyPressed & KEY_MOVE_FORWORD)
	{
		if (m_player->GetPosition().y > MaxY)
		{
			m_player->Set2DPosition(m_player->GetPosition().x, m_player->GetPosition().y - deltaTime * 200);
		}

	}
	if (keyPressed & KEY_MOVE_BACKWORD)
	{
		if (m_player->GetPosition().y < MinY)
		{
			m_player->Set2DPosition(m_player->GetPosition().x, m_player->GetPosition().y + deltaTime * 200);
		}
	}

	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	m_player->Update(deltaTime);
	if (shooted)
	{
		for (int i = 0; i < m_bullets.size(); i++)
		{
			if (m_bullets.at(i)->m_isStop == false)
			{
				m_bullets.at(i)->Update(deltaTime);
			}
		}
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	m_player->Draw();
	m_score->Draw();
	for (int i = 0; i < m_bullets.size(); i++)
	{
		m_bullets.at(i)->Draw();
	}
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}
