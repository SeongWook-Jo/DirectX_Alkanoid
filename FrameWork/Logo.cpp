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
	alpha = 0;	//안보임

	loadimg.Create("./resource/Img/Load/logo.png", false, D3DCOLOR_XRGB(0, 0, 0));
}

// Chap, 재정의 함수 호출
void Logo::Update(double frame)
{
	alpha += speed * frame / 400;	//처음에 안보였다가 255되면 로고 보임
	if( alpha >= 255 )
	{
		alpha = 255;
		speed = -speed;		
	}
	if(alpha <= 0) {	//알파값이 다시 0이 되면(로고안보이면)메뉴로 넘어가게
		 g_Mng.n_Chap = MENU;
	}
	
}

void Logo::Draw()
{
	loadimg.SetColor(255,255,255, alpha);  // 색상 변경
	loadimg.Draw( 430 , 100 ) ;  //이미지출력
}

void Logo::OnMessage( MSG* msg )
{

}