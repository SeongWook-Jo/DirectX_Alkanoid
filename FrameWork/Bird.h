#pragma once
#include "Include.h"

class Bird
{
	Sprite Bdimg[2];	//이미지


public :
	Bird();		//생성자
	~Bird();	//소멸자

	DWORD m_BirdAniTime;	//애니메이션시간
	int m_BirdCount;

	void Init();
	void Update();
	void Draw();

};

extern Bird bird;