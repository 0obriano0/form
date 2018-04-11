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

// ============================================
// �禡�G SetConsoleSize
// �����G �]�w Console �����j�p
//        // x ���n��.
// ===========================================
BOOL windows_Console::SetConsoleSize(int W, int H)
{
        BOOL ret;
        SMALL_RECT SR;
        SR.Top = 0;
        SR.Left = 0;
        SR.Bottom = H-1;
        SR.Right = W-1;
        	ret = SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE),TRUE, &SR);
        if(!ret) return ret;

        COORD Sz;
        Sz.X = W;
        Sz.Y = H;
        
        return SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),Sz);
}

// ============================================
// �禡�G ConsoleFullScreen
// �����G Console�]�����ù�
//        VK_MENU -> ALT, VK_RETURN -> Enter
//        ���N�O alt + Enter 
// ����G CodeGurn
// ===========================================

void windows_Console::ConsoleFullScreen()
{
        keybd_event(VK_MENU,0x38,0,0); 
        keybd_event(VK_RETURN,0x1c,0,0); 
        keybd_event(VK_MENU,0xb8,KEYEVENTF_KEYUP,0);
        keybd_event(VK_RETURN,0x9c,KEYEVENTF_KEYUP,0);

        /* �쪩�O�g�U���o��,���ھ� scan code �e�X���T��, �����n
        keybd_event(VK_MENU,0x38,0,0); 
        keybd_event(VK_RETURN,0x1c,0,0); 
        keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0); 
        keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
        */

}

// ============================================
// �禡�G IsConsoleFullScreen()
// �����G �P�_�O�_�����ù�
// ===========================================
BOOL windows_Console::IsConsoleFullScreen()
{
        // CONSOLE_FULLSCREEN(1), CONSOLE_FULLSCREEN_HARDWARE(2)
        DWORD mode;
        GetConsoleDisplayMode(&mode);
        if( (mode&CONSOLE_FULLSCREEN) == CONSOLE_FULLSCREEN) return TRUE;
        return FALSE;
}


// ============================================
// �禡�G GetConsoleWindowSize
// �����G ���o�ثe�����j�p
// ===========================================


void windows_Console::GetConsoleWindowSize(DWORD &W, DWORD &H)
{
        CONSOLE_FONT_INFO cfi;
        GetCurrentConsoleFont(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
        W = cfi.dwFontSize.X;
        H = cfi.dwFontSize.Y;
}

// ============================================
// �禡�G _GetLargestConsoleWindowSize
// �����G ���o�̤j�����j�p
// ===========================================

void windows_Console::_GetLargestConsoleWindowSize(DWORD &W, DWORD &H)
{
        COORD c = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));
        W = c.X;
        H = c.Y;
}
