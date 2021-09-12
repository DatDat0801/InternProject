#include "GSEndGame.h"


#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "../ScoreMng.h"

GSEndGame::GSEndGame()
{
}


GSEndGame::~GSEndGame()
{
}


void GSEndGame::Init()
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

	// title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("04B_30__.TTF");
	m_title = std::make_shared< Text>(shader, font, "Game Over", TextColor::RED, 2.0);
	m_title->Set2DPosition(Globals::screenWidth / 2 - 170, Globals::screenHeight / 2 - 100);

	int sc = ScoreMng::GetInstance()->m_score;
	m_score = std::make_shared< Text>(shader, font, "", TextColor::RED, 1.0);
	m_score->Set2DPosition(Globals::screenWidth / 2 , Globals::screenHeight / 2 -50);
	std::string tmps = std::to_string(sc);
	std::string ct = "Score: " + tmps;
	m_score->SetText(ct);

	int sc2 = ScoreMng::GetInstance()->GetHeighScore();
	m_maxScore = std::make_shared< Text>(shader, font, "", TextColor::RED, 1.0);
	m_maxScore->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	std::string tmps2 = std::to_string(sc2);
	std::string ct2 = "MaxScore: " + tmps2;
	m_maxScore->SetText(ct2);
	
}

void GSEndGame::Exit()
{
}


void GSEndGame::Pause()
{
}

void GSEndGame::Resume()
{
}


void GSEndGame::HandleEvents()
{
}

void GSEndGame::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSEndGame::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSEndGame::HandleMouseMoveEvents(int x, int y)
{
}

void GSEndGame::Update(float deltaTime)
{
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSEndGame::Draw()
{
	m_background->Draw();
	m_title->Draw();
	m_score->Draw();
	m_maxScore->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}