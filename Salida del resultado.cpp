#include <windows.h>
#include <string>
#include <iostream>

#define ID_BUTTON_SUM 1
#define ID_BUTTON_RES 2
#define ID_BUTTON_MUL 3
#define ID_BUTTON_DIV 4
#define ID_BUTTON_NOC 5

HWND hAdd, hSub, hMul, hDiv, hClr;
HWND hEdit1, hEdit2, hEditRes;

double GetNumberFromEdit(HWND hEdit){
    char buffer[256];
    GetWindowText(hEdit, buffer, 256);
    return atof(buffer);
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch (msg)
    {
    case WM_CREATE:
        hEdit1 = CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 20, 20, 100, 20, hwnd, NULL, NULL, NULL);
        hEdit2 = CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER, 130, 20, 100, 20, hwnd, NULL, NULL, NULL);
        hEditRes = CreateWindow("Edit", "", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY, 240, 20, 100, 20, hwnd, NULL, NULL, NULL);

        hAdd = CreateWindow("Button", " + ", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 20, 60, 60, 20, hwnd, (HMENU)ID_BUTTON_SUM, NULL, NULL);
        hSub = CreateWindow("Button", " - ", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 110, 60, 60, 20, hwnd, (HMENU)ID_BUTTON_RES, NULL, NULL);
        hMul = CreateWindow("Button", " X ", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 200, 60, 60, 20, hwnd, (HMENU)ID_BUTTON_MUL, NULL, NULL);
        hDiv = CreateWindow("Button", " / ", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 290, 60, 60, 20, hwnd, (HMENU)ID_BUTTON_DIV, NULL, NULL);
        hClr = CreateWindow("Button", "OtraVez", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 380, 60, 60, 20, hwnd, (HMENU)ID_BUTTON_NOC, NULL, NULL);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == ID_BUTTON_SUM || LOWORD(wParam) == ID_BUTTON_RES || LOWORD(wParam) == ID_BUTTON_MUL || LOWORD(wParam) == ID_BUTTON_DIV)
        {
            double num1 = GetNumberFromEdit(hEdit1);
            double num2 = GetNumberFromEdit(hEdit2);
            double result = 0.0;
            switch (LOWORD(wParam)){
             	case ID_BUTTON_SUM:
             		result = num1 + num2;
             		break;
                case ID_BUTTON_RES:
             		result = num1 - num2;
             		break;
             	case ID_BUTTON_MUL:
             		result = num1 * num2;
             		break;
             	case ID_BUTTON_DIV:
			if (num2 != 0.0){
			 	  result = num1 / num2;
			 }else{
			 	MessageBox(hwnd, "UPS: Trataste de dividir por cero ", "Error", MB_OK | MB_ICONERROR);
			 	result = 0.0;
			 }
			 
			}
			
			 char buffer[256];
            snprintf(buffer, sizeof(buffer), "%f", result);
            SetWindowText(hEditRes, buffer);
            std::cout << "Resultado: " << result << std::endl;
		}
		
		 if (LOWORD(wParam) == ID_BUTTON_NOC)
        {
            SetWindowText(hEdit1, "");
            SetWindowText(hEdit2, "");
            SetWindowText(hEditRes, "");
        }
        break;

    case WM_DESTROY:
        PostQuitMessage(0);


    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}
