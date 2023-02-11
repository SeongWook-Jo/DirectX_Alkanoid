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

	//테스트 용도로 사용
	bool bTempStart;

	//충돌처리 구현

	void Bounce();

};

extern Ball ball;

