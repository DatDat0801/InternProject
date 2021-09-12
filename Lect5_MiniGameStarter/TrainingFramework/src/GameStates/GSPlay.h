#pragma once
#include "GameStateBase.h"
#include <vector>
class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class AnimationSprite;
class Bullet;
class Bird;
class Bee;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;

	virtual void	CheckColl();

private:
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Text>		m_score;
	std::shared_ptr<Text>		m_heart;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	int keyPressed = 0;
	std::shared_ptr<AnimationSprite>		m_player;

	std::vector<std::shared_ptr<Bullet>> m_bullets;
	std::vector<std::shared_ptr<Bird>> m_birds;
	std::vector<std::shared_ptr<Bee>> m_bees;
	bool shooted = false;

	// sau 1 khoang tgian se tang cac speed nay len
	float m_speedPlayer = 400;
	float m_speedBird = 70;
	float m_speedBee = 50;
	float m_speedBullet = 400;

	float m_coutTimeUpSpeed=0;
	float m_timeUpSpeed = 10;


	float m_countInstanceBird = 0;
	float m_timeInstanceBird =2; 

	float m_countInstanceBee = 0;
	float m_timeInstanceBee = 4;

	int score = 0;
	int m_health = 3;
	
};

