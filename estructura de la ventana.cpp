#include <windows.h>
#include <string>
#include <iostream>


double GetNumberFromEdit(HWND hEdit){
    char buffer[256];
    GetWindowText(hEdit, buffer, 256);
    return atof(buffer);
}

LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
}
