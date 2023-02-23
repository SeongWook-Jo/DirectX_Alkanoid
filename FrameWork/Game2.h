#ifndef __Game2_H__
#define __Game2_H__

class Game2 : public Chap
{
public:
	Game2();
	~Game2();

	DWORD GameTime;
	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);
};

#endif