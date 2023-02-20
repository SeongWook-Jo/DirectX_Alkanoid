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

	float m_WSize;
	float m_HSize;

	float m_DirX;
	float m_DirY;
	float m_Speed;

	void Init();
	void Update();
	void Draw();

	//�׽�Ʈ �뵵�� ���
	bool bTempStart;

	//�浹ó�� ����

	void BarBounce(float x, float y);
	void Bounce(float x, float y);

};

extern Ball ball;

