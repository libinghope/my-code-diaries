#include <windows.h>

//窗口过程函数
LRESULT CALLBACK WinProc(
	HWND hWnd,		//信息所属的窗口句柄
	UINT uMsg,		//消息类型
	WPARAM wParam,	//附加信息(如键盘按键)
	LPARAM lParam	//附加信息(如鼠标点击坐标)
)
{

	switch (uMsg)
	{
	case WM_KEYDOWN: //键盘按下
		MessageBox(hWnd, TEXT("键盘按下"), TEXT("键盘"), MB_OK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		//以windows默认方式处理
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

//程序入口地址
int WINAPI WinMain(
	HINSTANCE hInstance,	//应用程序实例
	HINSTANCE hPrevInstance,	 //上一个应用程序实例
	LPSTR lpCmdLine,		//命令行参数
	int nShowCmd)		//窗口显示的样式
{
	//设计一个窗口类
	WNDCLASS wc;	//窗口类变量
	wc.cbClsExtra = 0;	//类附加内存
	wc.cbWndExtra = 0;	//窗口附加内存
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //背景色为白色
	wc.hCursor = LoadCursor(NULL, IDC_HELP);	//帮助光标
	wc.hIcon = LoadIcon(NULL, IDI_WARNING);	//警告图标
	wc.hInstance = hInstance;	//应用程序实例，为WinMain第1个形参
	wc.lpfnWndProc = WinProc;	//窗口过程函数名字
	wc.lpszClassName = TEXT("MyWin");	//类的名字
	wc.lpszMenuName = NULL;	//没有菜单
	wc.style = 0;	//类的风格，填0，使用默认风格

	//注册窗口类
	RegisterClass(&wc);

	//创建窗口
	HWND  hWnd = CreateWindow(TEXT("MyWin"), TEXT("测试用的窗口"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	//显示及更新窗口
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	//消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); //翻译
		DispatchMessage(&msg); //分发信息
	}

	return msg.wParam;
}
