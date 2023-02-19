#pragma once
#include "Include.h"

class Blocks
{
	typedef struct BK	//블럭 구조체
	{
		int point;				//충돌했을때 먹는 점수
		bool life;
		bool death;
		float dx, dy, dz, drx, dry, drz;	// 데미지존
	};

	Sprite Bkimg[5];	//이미지

	//스테이지1 블럭셋팅
	int bkarr1[5][13] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
		{2,2,2,2,2,2,2,2,2,2,2,2,2},
		{3,3,3,3,3,3,3,3,3,3,3,3,3},
		{4,4,4,4,4,4,4,4,4,4,4,4,4},
		{5,5,5,5,5,5,5,5,5,5,5,5,5}
	};


public:
	Blocks();
	~Blocks();	//소멸자

	int m_BlockCount;	//블럭카운트
	int score;	//총 점수

	float m_blockW;	//블럭 가로
	float m_blockH;	//블럭 세로
	float b_WSize;	//블럭이미지 가로사이즈
	float b_HSize;	//블럭이미지 세로사이즈

	BK m_block[5][13];	//블럭 구조체
	RECT m_bkrc;	//블럭 범위

	void Init();
	void Update();
	void Draw();
	void Boom();

};

extern Blocks blocks;

