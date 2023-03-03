#define _CRT_NONSTDC_NO_DEPRECATE

#include "Include.h"

Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::Init()
{
	speed = 400;
	alpha = 0;	//�Ⱥ���

	loadimg.Create("./resource/Img/Load/logo.png", false, D3DCOLOR_XRGB(0, 0, 0));
}

// Chap, ������ �Լ� ȣ��
void Logo::Update(double frame)
{
	alpha += speed * frame / 400;	//ó���� �Ⱥ����ٰ� 255�Ǹ� �ΰ� ����
	if( alpha >= 255 )
	{
		alpha = 255;
		speed = -speed;		
	}
	if(alpha <= 0) {	//���İ��� �ٽ� 0�� �Ǹ�(�ΰ�Ⱥ��̸�)�޴��� �Ѿ��
		 g_Mng.n_Chap = MENU;
	}
	
}

void Logo::Draw()
{
	loadimg.SetColor(255,255,255, alpha);  // ���� ����
	loadimg.Draw( 430 , 100 ) ;  //�̹������
}

void Logo::OnMessage( MSG* msg )
{

}