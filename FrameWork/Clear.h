#ifndef __Clear_H__
#define __Clear_H__

class Clear : public Chap
{
	Sprite clearimg[2];
public:
	Clear();
	~Clear();

	float speed;
	float alpha;
	bool clear1 = true;

	virtual void Init();
	virtual void Update(double frame);
	virtual void Draw();

	virtual void OnMessage(MSG* msg);
};
extern Clear clear;
#endif

