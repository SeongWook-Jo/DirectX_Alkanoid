#pragma once
#include "Include.h"



class Target
{
	Sprite BarImg;

public :
	Target();
	~Target();

	//아이템 적용 시 변경 1로 변경
	int BarState;

	bool m_Life;

	float m_W;
	float m_H;

	float m_WSize;
	float m_HSize;

	void Init();
	void Update();
	void Draw();
	void Reset();
};

extern Target target;