#pragma once
#include "Include.h"

class Blocks
{
	Sprite Bkimg;	//이미지
	Sprite orgSize; // 01 블럭으로 사이즈 고정

public:
	Blocks();	
	~Blocks();	//소멸자

	float m_blockW;	//블럭 가로
	float m_blockH;	//블럭 세로
	float b_WSize;	//블럭이미지 가로사이즈
	float b_HSize;	//블럭이미지 세로사이즈
	float m_locationX, m_locationY; //위치값

	bool isBoom = false;	//충돌 on/off
	bool isBlock = true;	//블럭 on/off
	bool isGray = false;	//회색블럭(2번에깨지게)

	void Init(int ColorNum);
	void Update();
	void Draw();
	void Boom();
	void SetLocation(int x, int y);
};

extern Blocks blocks;
