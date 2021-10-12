// 0929.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"
#include "0929.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY0929, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    // 단축키 설정
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY0929));

    // 메시지 컨트롤
    MSG msg;

    // 기본 메시지 루프입니다:
    // 메시지 큐에서 메시지를 얻어내는 형태
    // 기본적으로 block 함수, 메시지가 없으면 return이 되지않고 block이 걸립니다.
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        // 단축키를 일반 메시지로 변환
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            // 기본 메시지 중에서 메시지의 내부적인 변화가 필요한 것
            // 2개의 키를 누르는데 키 1개로 넣어야 하는 경우 여기서 변환.
            TranslateMessage(&msg);
            // DispatchMessage 내부에서 윈도우의 프로시저 함수를 호출시켜 줌.
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    // 자기 자신의 구조체 크기, 확장성 고려한 설계
    wcex.cbSize = sizeof(WNDCLASSEX);

    // 기본적인 스타일: 가로세로 크기 변경시 새로 렌더링
    wcex.style          = CS_HREDRAW | CS_VREDRAW; 
    // 윈도우 프로시저(메시지 처리기) 등록
    wcex.lpfnWndProc    = WndProc; 

    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;

    wcex.hInstance      = hInstance;
    // 아이콘
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY0929));
    // 커서
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    // 백그라운드 컬러
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    // 메뉴 메뉴가 필요하면 메뉴 이름으로 부름(리소스에서)
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY0929);
    // 클래스 이름(아무거나 가능) 클래스 생성할때만 맞춰주면 된다.
    wcex.lpszClassName  = szWindowClass;
    // 아이콘
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
    // 클래스 등록
    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, L"HELLO WINDOWS", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 520, 520, nullptr, nullptr, hInstance, nullptr);

   // 에러 확인
   DWORD error = GetLastError();

   if (!hWnd)
   {
      return FALSE;
   }

   // 매개변수로 들어온 Windows 사이즈나, 크기에 맞춰서 한번 바꿔줌.
   ShowWindow(hWnd, nCmdShow);
   // 윈도우 한번 갱신 시켜줌.
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:

        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                // DefWindowProc-> 우리가 모든 메시지를 처리 할 수 없기 때문에,
                // 처리 할 수 없는 메시지는 그냥 패스함
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    // 윈도우를 다시 그려야 할 떄, 이 메시지가 호출 된다.
    // 윈도우 자체에서 우리에게 알려줍니다.
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            // BeginPaint 윈도우에게 Paint 한다고 알린다.
            // 원칙은 WM_PAINt 메시지 발생 됐을 때만, BeginPaint-EndPaint 호출하고
            // 윈도우에게 내가 렌더링을 한다고 알린다. 
            // 이것을 안 하면 WM_PAINT를 계속 발생시킵니다.(다 그렸다 알려 줌)
            // 만약에 WM_PAINt를 안 쓸거면, 완전히 지워버려야 합니다. 그리고  DefWindowProc로 빼버려야 합니다.
            // 그럼 이 안에서 BeginPaint, EndPaint를 해줍니다.
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...

            TextOutW(hdc, 100, 100, L"Hello Windows", wcslen(L"Hello Windows"));
            EndPaint(hWnd, &ps);
        } 

        break;
    case WM_CLOSE:
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
