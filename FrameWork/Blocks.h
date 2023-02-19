#pragma once
#include "Include.h"

class Blocks
{
	typedef struct BK	//�� ����ü
	{
		int point;				//�浹������ �Դ� ����
		bool life;
		bool death;
		float dx, dy, dz, drx, dry, drz;	// ��������
	};

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

	int m_BlockCount;	//��ī��Ʈ
	int score;	//�� ����

	float m_blockW;	//�� ����
	float m_blockH;	//�� ����
	float b_WSize;	//���̹��� ���λ�����
	float b_HSize;	//���̹��� ���λ�����

	BK m_block[5][13];	//�� ����ü
	RECT m_bkrc;	//�� ����

	void Init();
	void Update();
	void Draw();
	void Boom();

};

extern Blocks blocks;

