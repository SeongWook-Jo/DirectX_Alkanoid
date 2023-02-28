#ifndef __Logo_H__
#define __Logo_H__

class Logo : public Chap
{
public:
	Logo();
	~Logo();

	HWND hWnd;	//윈도우 핸들 받고
	//CSound* Sound1;
	Sprite loadimg;	//스프라이트

	float speed;
	float alpha;

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);

	
};

#endif