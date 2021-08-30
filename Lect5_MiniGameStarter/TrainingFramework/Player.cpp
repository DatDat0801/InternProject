#include "Player.h"

#include <GameConfig.h>
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "GameManager/ResourceManagers.h"
Player::Player(){}

void Player::Init(){
	m_x = 30;
	m_y = Globals::screenHeight / 2;
	m_dx = 5;
	m_dy = 5;

	m_up = m_down = false;

	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	//auto texture = ResourceManagers::GetInstance()->GetTexture("bg_main_menu.tga");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture("btn_close2.tga");
	//shader = ResourceManagers::GetInstance()->GetShader("AnimationShader");
	//m_player = std::make_shared<AnimationSprite>(model, shader, texture, 3, 0.5f);
	m_player = std::make_shared<Sprite2D>(model, shader, texture);
	m_player->Set2DPosition(60, 700);//(float)Globals::screenWidth / 2 , (float)Globals::screenHeight / 2. y->700-100
	m_player->SetSize(130, 80);
}

void Player::Update(float deltaTime) {

}

void Player :: HandleInput(){}

void Player::Render(){
	std::shared_ptr<Sprite2D>		m_player;
}

void Player::Dispose(){}