#pragma once
#include "Include.h"

class Blocks
{
	Sprite Bkimg[5];	//�̹���

	//��������1 ������
	int bkarr1[5][13] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
		{2,2,2,2,2,2,2,2,2,2,2,2,2},
		{3,3,3,3,3,3,3,3,3,3,3,3,3},
		{4,4,4,4,4,4,4,4,4,4,4,4,4},
		{5,5,5,5,5,5,5,5,5,5,5,5,5}
	};


public:
	Blocks();
	~Blocks();	//�Ҹ���


	void Init();
	void Update();
	void Draw();

};

extern Blocks blocks;

