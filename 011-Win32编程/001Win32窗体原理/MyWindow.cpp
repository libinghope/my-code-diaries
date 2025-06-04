#include <windows.h>

//���ڹ��̺���
LRESULT CALLBACK WinProc(
	HWND hWnd,		//��Ϣ�����Ĵ��ھ��
	UINT uMsg,		//��Ϣ����
	WPARAM wParam,	//������Ϣ(����̰���)
	LPARAM lParam	//������Ϣ(�����������)
)
{

	switch (uMsg)
	{
	case WM_KEYDOWN: //���̰���
		MessageBox(hWnd, TEXT("���̰���"), TEXT("����"), MB_OK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		//��windowsĬ�Ϸ�ʽ����
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

//������ڵ�ַ
int WINAPI WinMain(
	HINSTANCE hInstance,	//Ӧ�ó���ʵ��
	HINSTANCE hPrevInstance,	 //��һ��Ӧ�ó���ʵ��
	LPSTR lpCmdLine,		//�����в���
	int nShowCmd)		//������ʾ����ʽ
{
	//���һ��������
	WNDCLASS wc;	//���������
	wc.cbClsExtra = 0;	//�฽���ڴ�
	wc.cbWndExtra = 0;	//���ڸ����ڴ�
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //����ɫΪ��ɫ
	wc.hCursor = LoadCursor(NULL, IDC_HELP);	//�������
	wc.hIcon = LoadIcon(NULL, IDI_WARNING);	//����ͼ��
	wc.hInstance = hInstance;	//Ӧ�ó���ʵ����ΪWinMain��1���β�
	wc.lpfnWndProc = WinProc;	//���ڹ��̺�������
	wc.lpszClassName = TEXT("MyWin");	//�������
	wc.lpszMenuName = NULL;	//û�в˵�
	wc.style = 0;	//��ķ����0��ʹ��Ĭ�Ϸ��

	//ע�ᴰ����
	RegisterClass(&wc);

	//��������
	HWND  hWnd = CreateWindow(TEXT("MyWin"), TEXT("�����õĴ���"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	//��ʾ�����´���
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	//��Ϣѭ��
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); //����
		DispatchMessage(&msg); //�ַ���Ϣ
	}

	return msg.wParam;
}
