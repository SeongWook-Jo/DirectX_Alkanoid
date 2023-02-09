class g_DeviceFont
{
public:
	IDirect3D9* Direct3D;		//다이렉트
	IDirect3DDevice9* Device9;	//디바이스
	D3DPRESENT_PARAMETERS d3dpp ;	//설계도면

	ID3DXSprite* Sprite;       
	ID3DXFont* Fonts;    
	D3DXFONT_DESC fdesc ;

public:
	g_DeviceFont(void);
	~g_DeviceFont(void);

	bool Create(HWND g_hWnd);
	//글씨 쓸수 있음 메세지 전달
	bool DrawString( const char* msg , int x , int y , D3DCOLOR color = D3DCOLOR_ARGB( 255,255,255,255) );

};

//외부참조 extern선언
extern g_DeviceFont dv_font;