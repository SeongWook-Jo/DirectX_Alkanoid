#pragma once
#include "Include.h"

class Map
{

public :
	Map();
	~Map();
	Sprite test;
	bool tests;

	Sprite m_MapImg[2];	//스테이지1 맵 스프라이트

	Sprite m_MapImg1_1[6];
	Sprite m_MapImg1_2[45];
	Sprite m_MapImg1_3[65];

	Sprite m_MapImg2_1[7];
	Sprite m_MapImg2_2[30];
	Sprite m_MapImg2_3[45];

	DWORD m_MapImg1_1_ani1;
	DWORD m_MapImg1_2_ani1;

	int m_MapImg1_1_ani1Count;
	int m_MapImg1_2_ani1Count;

	int m_MapImg2_1_ani1Count;
	int m_MapImg2_2_ani1Count;

	int m_Stage;

	void Init();
	void Update(double frame);
	void Draw();
};

extern Map map;