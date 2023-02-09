#ifndef __Chap_H__
#define __Chap_H__

class Chap
{
public :
	Chap() {};
	~Chap() {};

	//virtual로 함
	virtual void Init() = 0; //게임 시작시 무조건 한번만 탐
	virtual void Update(double frame) = 0;	//지정된 프레임만큼 계속
	virtual void Draw() = 0;		//계속
	virtual void OnMessage(MSG* msg) = 0;	//전달된 메시지 처리
};

#endif