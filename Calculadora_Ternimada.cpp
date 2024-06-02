#incluir <ventanas.h>
#incluir <cadena>
#incluir <iostream>


doble GetNumberFromEdit(HWND hEdit){
    búfer de caracteres [256];
    GetWindowText(hEdit, búfer, 256);
    devolver atof(buffer);
}

Procedimiento de ventana de devolución de llamada de resultado (HWND hwnd, mensaje UINT, WPARAM wParam, LPARAM lParam) {
}

// VENTANA GRÁFICA
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int nCmdShow){
    const char CLASS_NAME[] = "Calculadora Proyecto";
    WNDCLASS baño = {};
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
        Mensaje de envío(&msg);
    }
    devolver 0;
}
