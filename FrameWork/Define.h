#define SCREEN_WITH 1280	// ȭ�� ���� �ȼ�ũ��
#define SCREEN_HEIGHT 768	// ȭ�� ���� �ȼ�ũ��

#define FRAME 1000
#define LEFT 0
#define RIGHT 1
#define UP 2
#define DOWN 3

#define STARTWIDTH   600
#define STARTHEIGHT  700
#define BALLSPEED 3

// ����Ÿ ���̽�
//#define DB_HOST "127.0.0.1"
//#define DB_USER "root"
//#define DB_PASS "123456" // "Ws05290529*"
//#define DB_NAME "test"
//#define CHOP(x) x[strlen(x) - 1] = ' ' // �����ٰ� �Ⱦ�...

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
	OVER = 3,
	TOTALCHAP //for�� ������ �̸�ŭ�� (4)�� �������
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

