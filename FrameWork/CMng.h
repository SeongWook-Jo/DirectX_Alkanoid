class CMng
{
public:
	CMng();
	~CMng();


	Chap *chap[TOTALCHAP];	//é�ͷ� ����ų�� �ִ� �����ͷ� é�ͷ� ����(�����͸� ������)
	int n_Chap;

	HWND hWnd;
	HINSTANCE hInstance;

};

extern CMng g_Mng;