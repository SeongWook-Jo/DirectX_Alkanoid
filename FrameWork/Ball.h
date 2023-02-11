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

	//테스트 용도로 사용
	bool bTempStart;

	//충돌처리 구현

	void Bounce();

};

extern Ball ball;

