#pragma once
#include "Include.h"

class Blocks
{
	Sprite Bkimg;	//�̹���
	Sprite orgSize; // 01 ������ ������ ����

public:
	Blocks();	
	~Blocks();	//�Ҹ���

	float m_blockW;	//�� ����
	float m_blockH;	//�� ����
	float b_WSize;	//���̹��� ���λ�����
	float b_HSize;	//���̹��� ���λ�����
	float m_locationX, m_locationY; //��ġ��

	bool isBoom = false;	//�浹 on/off
	bool isBlock = true;	//�� on/off
	bool isGray = false;	//ȸ����(2����������)

	void Init(int ColorNum);
	void Update();
	void Draw();
	void Boom();
	void SetLocation(int x, int y);
};

extern Blocks blocks;
