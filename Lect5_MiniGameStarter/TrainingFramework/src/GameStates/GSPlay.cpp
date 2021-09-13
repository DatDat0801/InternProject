#include "GSPlay.h"
#include <stdlib.h>
#include<iostream>
#include<string>

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
#include "../Bird.h"
#include "../Bee.h"
#include "../ScoreMng.h"
#include "../ClassSound.h"

//#include <mmsystem.h>
//#include<mciapi.h>
#pragma comment(lib,"Winmm.lib")

#include<Windows.h>

#define MaxY 100
#define MinY 700

const int MaxBirdSpeed= 300;
const int MaxBeeSpeed= 300;
const int MaxPlayerSpeed=400;
const int MaxBulletSpeed=500;
class AnimationSprite;
class Bullet;
class Bird;
class Bee;

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
		std::shared_ptr<Bullet> _bullet = std::make_shared<Bullet>(model, shader, texture, m_speedBullet); 
		_bullet->Set2DPosition((float)Globals::screenWidth / 2-400, (float)Globals::screenHeight / 2);
		_bullet->SetSize(30, 30);
		m_bullets.push_back(_bullet);
	}

	// bird
	texture = ResourceManagers::GetInstance()->GetTexture("Bird.tga");
	shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	for (int i = 0; i < 15; i++)
	{
		std::shared_ptr<Bird> _bird = std::make_shared<Bird>(model, shader, texture, 8, 0.07f, 200);
		_bird->Set2DPosition((float)Globals::screenWidth / 2, 900);
		_bird->SetSize(60, 60);
		m_birds.push_back(_bird);
	}

	//bee
	texture = ResourceManagers::GetInstance()->GetTexture("Bee.tga");
	//shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	for (int i = 0; i < 20; i++)
	{
		std::shared_ptr<Bee> _bee = std::make_shared<Bee>(model, shader, texture, 6, 0.07f, 200);
		_bee->Set2DPosition((float)Globals::screenWidth / 2, 900);
		_bee->SetSize(60, 60);
		m_bees.push_back(_bee);
	}

	// character
	texture = ResourceManagers::GetInstance()->GetTexture("vehicle3.tga");
	shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	m_player = std::make_shared<AnimationSprite>(model, shader, texture, 3, 0.1f);
	//m_player = std::make_shared<Sprite2D>(model, shader, texture);
	m_player->Set2DPosition(60, 300);//(float)Globals::screenWidth / 2 , (float)Globals::screenHeight / 2. y->700-100
	m_player->SetSize(130, 80);


	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("04B_30__.TTF");
	m_score = std::make_shared< Text>(shader, font, "score: 0", TextColor::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	// heart
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	m_heart = std::make_shared< Text>(shader, font, "Health: 3", TextColor::RED, 1.0);
	m_heart->Set2DPosition(Vector2(200, 25));
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
	m_coutTimeUpSpeed += deltaTime;
	if (m_coutTimeUpSpeed >= m_timeUpSpeed)
	{
		m_speedPlayer += 10;
		m_speedBird += 5;
		//m_speedBee += 5;
		m_speedBullet += 10;
		if (m_speedPlayer > MaxPlayerSpeed)
		{
			m_speedPlayer = MaxPlayerSpeed;
		}
		if (m_speedBird > MaxBirdSpeed)
		{
			m_speedBird = MaxBirdSpeed;
		}
		/*if (m_speedBee > MaxBeeSpeed)
		{
			m_speedBee = MaxBeeSpeed;
		}*/
		if (m_speedBullet > MaxBulletSpeed)
		{
			m_speedBullet = MaxBulletSpeed;
		}
		/*if (m_timeInstanceBee <= 3)
		{
			m_timeInstanceBee -= 0.25;
		}*/
		m_coutTimeUpSpeed = 0;
	}
	if (keyPressed & KEY_MOVE_SHOOT)
	{
		std::shared_ptr<Bullet> _bullet;
		for (int i = 0; i < m_bullets.size(); i++)
		{
			if (m_bullets.at(i)->m_isStop==true && countTime<=0)
			{
				_bullet = m_bullets.at(i);
				_bullet->m_speed = m_speedBullet;
				_bullet->Set2DPosition(m_player->GetPosition().x+55, m_player->GetPosition().y-10);//(float)Globals::screenWidth / 2 , (float)Globals::screenHeight / 2. y->700-100
				_bullet->m_isStop = false;
				shooted = true;
				countTime = 10;
				
				/*mciSendString("play mp3", NULL, 0, NULL);
				PlaySound(TEXT("Shoot.wav"), NULL, SND_SYNC);*/
				s_shoot->PlaySound();
				//s_shoot->s
				break;
			}
		}
	}
	if (countTime > 0)
	{
		countTime -= deltaTime;
	}

	srand(time(NULL));
	double randPos = ((double)rand()) / ((double)RAND_MAX);
	float birdRan = (float)(rand() % (510 - 200) + 200);
	// handle bird
	m_countInstanceBird += deltaTime;
	if (m_countInstanceBird >= m_timeInstanceBird)
	{
		std::shared_ptr<Bird> _bird;
		for (int i = 0; i < m_birds.size(); i++)
		{
			if (m_birds.at(i)->m_isStop == true)
			{
				//random X

				_bird = m_birds.at(i);
				_bird->Set2DPosition(birdRan, 800);//(float)Globals::screenWidth / 2 , (float)Globals::screenHeight / 2. y->700-100
				_bird->m_speed = m_speedBird;
				_bird->m_isStop = false;
				m_birds.at(i)->m_isStop = false;
				m_countInstanceBird = 0;
				break;
			}
		}
	}

	// handle bee
	m_countInstanceBee += deltaTime;
	if (m_countInstanceBee >= m_timeInstanceBee)
	{
		std::shared_ptr<Bee> _bee;
		for (int i = 0; i < m_bees.size(); i++)
		{
			if (m_bees.at(i)->m_isStop == true)
			{
				//random X
				srand(time(NULL));
				double tmp = ((double)rand()) / ((double)RAND_MAX);
				float tmp2 = (float)(rand() % (50 - 40) + 40);

				_bee= m_bees.at(i);
				_bee->Set2DPosition(birdRan+tmp2, 800);//(float)Globals::screenWidth / 2 , (float)Globals::screenHeight / 2. y->700-100
				_bee->m_speed = m_speedBee;
				_bee->m_isStop = false;
				m_bees.at(i)->m_isStop = false;
				m_countInstanceBee = 0;
				break;
			}
		}
	}

	if (keyPressed & KEY_MOVE_FORWORD)
	{
		if (m_player->GetPosition().y > MaxY)
		{
			m_player->Set2DPosition(m_player->GetPosition().x, m_player->GetPosition().y - deltaTime * m_speedPlayer);
		}

	}
	if (keyPressed & KEY_MOVE_BACKWORD)
	{
		if (m_player->GetPosition().y < MinY)
		{
			m_player->Set2DPosition(m_player->GetPosition().x, m_player->GetPosition().y + deltaTime * m_speedPlayer);
		}
	}

	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	m_player->Update(deltaTime);
	
	// bird update
	for (int i = 0; i < m_birds.size(); i++)
	{
		if (m_birds.at(i)->m_isStop == false)
		{
			m_birds.at(i)->Update(deltaTime);
		}
	}

	// bee update
	for (int i = 0; i < m_bees.size(); i++)
	{
		if (m_bees.at(i)->m_isStop == false)
		{
			m_bees.at(i)->Update(deltaTime);
		}
	}

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
	CheckColl();

	if(m_health<=0)
	{
		ScoreMng::GetInstance()->m_score = score;
		//ScoreMng::GetInstance()->SaveScoreMax();
		GameStateMachine::GetInstance()->PopState();
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_ENDGAME);
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	m_player->Draw();
	m_score->Draw();
	m_heart->Draw();
	for (int i = 0; i < m_bullets.size(); i++)
	{
		m_bullets.at(i)->Draw();
	}
	for (int i = 0; i < m_birds.size(); i++)
	{
		m_birds.at(i)->Draw();
	}
	for (int i = 0; i < m_bees.size(); i++)
	{
		m_bees.at(i)->Draw();
	}
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}

void GSPlay::CheckColl()
{
	for (int i = 0; i < m_bullets.size(); i++)
	{
		for (int j = 0; j < m_birds.size(); j++)
		{
			if (m_bullets.at(i)->m_isStop==false && m_birds.at(j)->m_isStop==false)
			{
				Vector3 obj1 = m_bullets.at(i)->GetPosition();
				Vector3 obj2 = m_birds.at(j)->GetPosition();
				float dis = sqrt(pow(obj1.x - obj2.x, 2) + pow(obj1.y - obj2.y, 2));

				float min = m_birds.at(j)->m_radius - m_bullets.at(i)->m_radius;
				float max = m_birds.at(j)->m_radius + m_bullets.at(i)->m_radius;

				if (dis > min && dis < max)
				{
					m_bullets.at(i)->Set2DPosition(700, 300);
					m_bullets.at(i)->m_isStop = true;
					s_birdDie->PlaySound();
					srand(time(NULL));
					double tmp = ((double)rand()) / ((double)RAND_MAX);
					float tmp2 = (float)(rand() % (500 - 200) + 100);
					m_birds.at(j)->Set2DPosition(tmp2, 900);
					m_birds.at(j)->m_isStop = true;

					score += 1;
					std::string tmps = std::to_string(score);
					std::string sc = "score: " + tmps;
					m_score->SetText(sc);
					break;
				}
			}
			if (m_birds.at(j)->m_isStop == false && m_birds.at(j)->GetPosition().y <= -50)
			{
				if (m_health >= 1)
				{
					m_health -= 1;
				}
				
				std::string tmps = std::to_string(m_health);
				std::string sc = "Health: " + tmps;
				m_heart->SetText(sc);
				m_birds.at(j)->m_isStop = true;
				break;
			}
		}

		for (int j = 0; j < m_bees.size(); j++)
		{
			if (m_bullets.at(i)->m_isStop == false && m_bees.at(j)->m_isStop == false)
			{
				Vector3 obj1 = m_bullets.at(i)->GetPosition();
				Vector3 obj2 = m_bees.at(j)->GetPosition();
				float dis = sqrt(pow(obj1.x - obj2.x, 2) + pow(obj1.y - obj2.y, 2));

				float min = m_bees.at(j)->m_radius - m_bullets.at(i)->m_radius;
				float max = m_bees.at(j)->m_radius + m_bullets.at(i)->m_radius;

				if (dis > min && dis < max)
				{
					m_bullets.at(i)->Set2DPosition(700, 300);
					m_bullets.at(i)->m_isStop = true;
					s_beeDie->PlaySound();

					srand(time(NULL));
					double tmp = ((double)rand()) / ((double)RAND_MAX);
					float tmp2 = (float)(rand() % (500 - 200) + 100);
					m_bees.at(j)->Set2DPosition(tmp2, 900);
					m_bees.at(j)->m_isStop = true;

					if (m_health >= 1)
					{
						m_health -= 1;
					}
					std::string tmps = std::to_string(m_health);
					std::string sc = "Health: " + tmps;
					m_heart->SetText(sc);
					break;
				}
			}
		}
	}


}
