#pragma once
#include "Include.h"



class Target
{
	Sprite BarImg;

public :
	Target();
	~Target();

	//������ ���� �� ���� 1�� ����
	int BarState;
	//Ball ball;

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