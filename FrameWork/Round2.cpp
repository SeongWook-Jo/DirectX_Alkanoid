#include "Include.h"

Round2 round2;

void Round2::Init()
{
	//��� �̹���
	Blocks tempBlo;
	tempBlo.Init(1);	//blocks�� init�� colornum 1 ����
	blockSizeX = tempBlo.b_WSize;	//���̹����� ���� ������
	blockSizeY = tempBlo.b_HSize;	//���̹����� ���� ������

	//ó�� ��� ��ġ��
	float x = 420;
	float y = 220;

	//blocks�� ��ġ�� �� ���� ����
	for (int i = 0; i < 13; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			bkarr2[i][j].isBoom = false;
			bkarr2[i][j].Init(chap1_color[i][j]);	//�� ���ڳ���
			bkarr2[i][j].SetLocation(x, y);			//��ġ�� ����
			x += blockSizeX;						//13�� ���̹��� ���λ����ŭ ����
		}
		y += blockSizeY;							//5�� ���̹��� ���λ����ŭ ����
		x = 420;									//x�� 420���� �ʱ�ȭ
	}
}

void Round2::Update()
{
	if (Gmanager.m_GameStart)
	{
		//����浹
		for (int i = 0; i < 13; ++i)
		{
			for (int j = 0; j < 13; ++j)
			{
				bkarr2[i][j].Update();	//�� �浹 �ҷ���
			}
		}
	}
}

void Round2::Draw()
{
	if (Gmanager.m_GameStart)
	{
		//��
		for (int i = 0; i < 13; ++i)
		{
			for (int j = 0; j < 13; ++j)
			{
				bkarr2[i][j].Draw();	//�� �׸��� �ҷ���
			}
		}
	}
}
