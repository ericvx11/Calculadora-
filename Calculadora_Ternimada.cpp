#incluir <ventanas.h>
#incluir <cadena>
#incluir <iostream>


doble GetNumberFromEdit(HWND hEdit){
    b�fer de caracteres [256];
    GetWindowText(hEdit, b�fer, 256);
    devolver atof(buffer);
}

Procedimiento de ventana de devoluci�n de llamada de resultado (HWND hwnd, mensaje UINT, WPARAM wParam, LPARAM lParam) {
}

// VENTANA GR�FICA
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow){
    const char CLASS_NAME[] = "Calculadora Proyecto";
    WNDCLASS ba�o = {};
    wc.lpfnWndProc = Procedimiento de ventana;
    wc.hInstancia = hInst;
    wc.lpszClassName = CLASE_NOMBRE;

    RegistrarClase(&wc);
    HWND hwnd = CreateWindow(CLASS_NAME, "Calculadora Proyecto", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 150, NULL, NULL, hInst, NULL);
    si (hwnd == NULL){
        devolver 0;
    }

    MostrarVentana(hwnd, nCmdShow);
    Mensaje MSG = {};
    mientras (GetMessage(&msg, NULL, 0, 0)){
        Traducir mensaje(&msg);
        Mensaje de env�o(&msg);
    }
    devolver 0;
}
