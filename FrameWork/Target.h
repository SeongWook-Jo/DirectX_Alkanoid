#pragma once
#include "Include.h"


typedef struct Tar
{
	double dx, dy, dz, drx, dry, drz;	// 데미지존
};


class Target
{
	Sprite BarImg;

public :
	Target();
	~Target();

	//아이템 적용 시 변경 1로 변경
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