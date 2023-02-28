#pragma once
#include "Include.h"

class Map
{

public :
	Map();
	~Map();
	Sprite test;
	bool tests;

	Sprite m_MapImg[3];	//스테이지1 맵 스프라이트
	
	int m_Stage;

	void Init();
	void Update(double frame);
	void Draw();
};

extern Map map;