#incluir <ventanas.h>
#incluir <cadena>
#incluir <iostream>

double GetNumberFromEdit(HWND hEdit){
    char buffer[256];
    GetWindowText(hEdit, buffer, 256);
    return atof(buffer);
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
	
	
}



// VENTANA GRAFICA
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow){
    const char CLASS_NAME[] = "Calculadora Proyecto";
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProcedure;
    wc.hInstance = hInst;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);
    HWND hwnd = CreateWindow(CLASS_NAME, "Calculadora Proyecto", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 150, NULL, NULL, hInst, NULL);
    if (hwnd == NULL){
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}
