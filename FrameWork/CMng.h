class CMng
{
public:
	CMng();
	~CMng();


	Chap *chap[TOTALCHAP];	//챕터로 가리킬수 있는 포인터로 챕터로 관리(포인터만 가져옴)
	int n_Chap;

	HWND hWnd;
	HINSTANCE hInstance;

};

extern CMng g_Mng;