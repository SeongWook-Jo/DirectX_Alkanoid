class CMng
{
public:
	CMng();
	~CMng();


	///////////////////////// ��������Ʈ ��ü! ///////////////////
//	Sprite loadimg;  // �ΰ��̹���

	//////////////////////////////////////////////////////////////


	Chap *chap[TOTALCHAP];	//é�ͷ� ����ų�� �ִ� �����ͷ� é�ͷ� ����(�����͸� ������)
	int n_Chap;

	HWND hWnd;
	HINSTANCE hInstance;

};

extern CMng g_Mng;