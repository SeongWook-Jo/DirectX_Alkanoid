#pragma once
#include "Include.h"
class Ball
{
	Sprite BallImg;

public:
	Ball();
	RECT m_Col;
	float m_W;
	float m_H;

	float m_radius;
	float m_DirX;
	float m_DirY;

	void Init();
	void Update();
	void Draw();

	//�׽�Ʈ �뵵�� ���
	bool bTempStart;

	//�浹ó�� ����

	void Bounce();

};

extern Ball ball;

