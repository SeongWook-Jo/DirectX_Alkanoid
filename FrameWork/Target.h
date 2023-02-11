#pragma once
#include "Include.h"


typedef struct Tar
{
	double dx, dy, dz, drx, dry, drz;	// ��������
};


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
	Tar m_Target;

	RECT m_rc;

	void Init();
	void Update();
	void Draw();
	void Reset();
};

extern Target target;