#pragma once
#include "Include.h"

class Bird
{
	Sprite Bdimg[2];	//�̹���


public :
	Bird();		//������
	~Bird();	//�Ҹ���

	DWORD m_BirdAniTime;	//�ִϸ��̼ǽð�
	int m_BirdCount;

	void Init();
	void Update();
	void Draw();

};

extern Bird bird;