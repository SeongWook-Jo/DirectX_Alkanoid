#ifndef __Chap_H__
#define __Chap_H__

class Chap
{
public :
	Chap() {};
	~Chap() {};

	//virtual�� ��
	virtual void Init() = 0; //���� ���۽� ������ �ѹ��� Ž
	virtual void Update(double frame) = 0;	//������ �����Ӹ�ŭ ���
	virtual void Draw() = 0;		//���
	virtual void OnMessage(MSG* msg) = 0;	//���޵� �޽��� ó��
};

#endif