#pragma once
#include "Include.h"


class Round1
{

public:

	int chap1_color[5][13] = {
		{ GREY,GREY,GREY,GREY,GREY,GREY,GREY,1,1,1,1,1,1 },
		{ 2,2,2,2,2,2,2,2,2,2,2,2,2 },
		{ 3,3,3,3,3,3,3,3,3,3,3,3,3 },
		{ 4,4,4,4,4,4,4,4,4,4,4,4,4 },
		{ 5,5,5,5,5,5,5,5,5,5,5,5,5 }
	};

	Blocks bkarr1[5][13];

	float blockSizeX;
	float blockSizeY;
	int m_BlockCount = 65;	//블럭카운트

	void Init();
	void Update();
	void Draw();
};

extern Round1 round1;

