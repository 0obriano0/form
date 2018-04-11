#include <windows.h>
#include "windows_Console.h"

// ============================================
// �禡�G ConsoleTitle
// �����G �]�w Consle �W��
// ===========================================
void windows_Console::_SetConsoleTitle(const char* title){
        SetConsoleTitle(title);
        
}

// ============================================
// �禡�G GetConsoleTitle
// �����G ���o Consle �W��
// ===========================================
void windows_Console::_GetConsoleTitle(char* title, DWORD nSize){
        GetConsoleTitle(title, nSize);
}

// ============================================
// �禡�G Clr, �M���ù�
// �����G �ѨM�ϥ� system("cls") �|���{�{���D
//        �ƹ�W�o�u�O��C���I����W�ťզӤw
// ����G CodeGurn
// ===========================================
void windows_Console::Clr(){
        COORD coordScreen = { 0, 0 }; 
        DWORD cCharsWritten; 
        CONSOLE_SCREEN_BUFFER_INFO csbi; 
        DWORD dwConSize; 
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        GetConsoleScreenBufferInfo(hConsole, &csbi); 
        dwConSize = csbi.dwSize.X * csbi.dwSize.Y; 
        FillConsoleOutputCharacter(hConsole, TEXT(' '),
                dwConSize, 
                coordScreen,
                &cCharsWritten); 
        GetConsoleScreenBufferInfo(hConsole, &csbi); 
        FillConsoleOutputAttribute(hConsole,
                csbi.wAttributes,
                dwConSize,
                coordScreen,
                &cCharsWritten); 
        SetConsoleCursorPosition(hConsole, coordScreen);

}
