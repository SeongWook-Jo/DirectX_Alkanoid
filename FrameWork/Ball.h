#pragma once
#include "Include.h"
class Ball
{
	Sprite BallImg;

public:
	Ball();
	RECT m_rcCol;
	float m_W;
	float m_H;

	float m_MoveX;
	float m_MoveY;

	void Init();
	void Update();
	void Draw();

	//�׽�Ʈ �뵵�� ���
	bool bTempStart;

	//�浹ó�� ����

	void Bounce();

};

extern Ball ball;

