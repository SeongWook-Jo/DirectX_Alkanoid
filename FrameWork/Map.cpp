#include "Include.h"

Map map;


Map::Map()
{
	m_Stage = 1;
}

Map::~Map()
{
}

void Map::Init()	//로드할 이미지 넣어놓고
{
	int i,j;
	char FileName[256];
	
	//나뉘어져 있는 레이어이미지들 출력
	for(i = 0; i<6; i++ )
	{
		sprintf_s(FileName, "./resource/Img/map1/BG_Hades_1/BG_Hades_%04d.tga", i + 1);
		m_MapImg1_1[i].Create( FileName ,false,D3DCOLOR_XRGB(0,0,0));
		
	}

	j = 1;
	for(i = 0; i<45; i++ )
	{
		sprintf_s(FileName, "./resource/Img/map1/BG_Hades_2/BG_Hades_0002_%06d.tga", j);
		m_MapImg1_2[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));
		j+=2;
		
	}

	for (int i = 0; i<65; i++)
	{
		sprintf_s(FileName, "./resource/Img/map1/BG_Medusa_3/BG_Medusa_fire_01_%04d.tga", i + 1);
		m_MapImg1_3[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	}

	for (int i = 0; i<7; i++)
	{
		sprintf_s(FileName, "./resource/Img/map1/BG_Poseidon_1/BG_Poseidon_%04d.tga", i + 1);
		m_MapImg2_1[i].Create(FileName, false, D3DCOLOR_XRGB(0, 0, 0));

	}

	for(int i = 0; i<30; i++ )
	{
		sprintf_s(FileName, "./resource/Img/map1/BG_Poseidon_2/1%04d.png", i);
		m_MapImg2_2[i].Create(FileName,false,D3DCOLOR_XRGB(0,0,0));
		
	} 

	for(int i = 0; i<45; i++ )
	{
		sprintf_s(FileName, "./resource/Img/map1/BG_Poseidon_3/1%04d.png", i );
		m_MapImg2_3[i].Create(FileName,false,D3DCOLOR_XRGB(0,0,0));
		
	} 
}

void Map::Update(double frame)
{
	//무작정 아니고 프레임 걸고 있음 
	if(GetTickCount64() - m_MapImg1_1_ani1 > frame)	//계속흘러가는 시간
	{
		if(m_Stage==1)
		{
			m_MapImg1_1_ani1Count++;
			m_MapImg1_2_ani1Count++;
			if(m_MapImg1_1_ani1Count > 44) m_MapImg1_1_ani1Count = 0;
			if(m_MapImg1_2_ani1Count > 64) m_MapImg1_2_ani1Count = 0;
		}
		else if (m_Stage == 2)
		{
			m_MapImg2_1_ani1Count++;
			m_MapImg2_2_ani1Count++;
			if (m_MapImg2_1_ani1Count > 29) m_MapImg2_1_ani1Count = 0;
			if (m_MapImg2_2_ani1Count > 44) m_MapImg2_2_ani1Count = 0;

		}
		m_MapImg1_1_ani1 = GetTickCount64();
	}

}

void Map::Draw()	//스테이지별로 레이어 나눠놓기(이미지 위치)
{	
	if(m_Stage==1)
	{
		m_MapImg1_1[0].Render(0, 0, 0, 1, 1);	//맨뒤에 숫자 2개는 크기 1,1 은 원본크기
		m_MapImg1_1[1].Render(0, 0, 0, 1, 1);
		m_MapImg1_1[3].Render(270, 70, 0, 1, 1);
		m_MapImg1_2[m_MapImg1_1_ani1Count].Render(0, 0, 0, 1.5, 1.5);	//인덱스 번호는 업데이트에서 바꾸는게 좋음
		m_MapImg1_1[2].Render(190, 0, 0, 1, 1);
		m_MapImg1_1[4].Render(900, 0, 0, 1, 1);
		m_MapImg1_1[5].Render(0, 0, 0, 1, 1);
		m_MapImg1_3[m_MapImg1_2_ani1Count].Render(0, 260, 0, 1, 1);
		m_MapImg1_3[m_MapImg1_2_ani1Count].Render(800, 260, 0, 1, 1);
	}

	else if(m_Stage==2)
	{
		m_MapImg2_1[0].Render(0, 0, 0, 1, 1);
		m_MapImg2_2[m_MapImg2_1_ani1Count].Render(165, 0, 0, 4, 1);
		m_MapImg2_1[1].Render(0, 0, 0, 1, 1);
		m_MapImg2_2[m_MapImg2_1_ani1Count].Render(300, 710, 0, 2.3, 1);
		m_MapImg2_1[2].Render(0, 0, 0, 1, 1);
		m_MapImg2_3[m_MapImg2_2_ani1Count].Render(0, -40, 0, 4, 2);
		m_MapImg2_1[3].Render(0, 0, 0, 1, 1);
		m_MapImg2_1[4].Render(0, 0, 0, 1, 1);
		m_MapImg2_1[5].Render(0, 0, 0, 1, 1);
		m_MapImg2_1[6].Render(0, 0, 0, 1, 1);

	}

}
