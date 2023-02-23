#define SCREEN_WITH 1280	// 화면 가로 픽셀크기
#define SCREEN_HEIGHT 768	// 화면 세로 픽셀크기

#define FRAME 1000
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

#define STARTWIDTH   600
#define STARTHEIGHT  700
#define BALLSPEED 3

//block 컬러
#define None 0
#define	GREY 1
#define	RED 2
#define	YELLOW 3
#define	BLUE 4
#define	GREEN 5
#define	ORANGE 6
#define	SKY 7
#define	PINK 8
#define	WHITE 9


enum gamechap
{
	LOGO = 0,
	MENU = 1,
	GAME = 2,
	GAME2 = 3,
	OVER = 4,
	TOTALCHAP //for문 돌릴땐 이만큼만 (5)만 돌리면됨
};

enum alphabet
{
	A_, B_, C_, D_, E_, F_, G_, H_, I_, J_, K_, L_
};
enum gamework
{
	INIT = 0,
	WORK = 1,
	DRAW = 2
};

template <typename T>
T Clamp(T value, T min, T max)
{
	if (value > max) value = max;
	if (value < min) value = min;
	return value;
}

