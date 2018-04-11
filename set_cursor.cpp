#include "set_cursor.h"
#include <conio.h>
#include <stdio.h>

// =============================================
// �禡�G gotoxy
// �����G ���ʴ�Цܫ��w��m
// ============================================
void set_cursor::gotoxy(int x, int  y)
{
        COORD point;
        point.X = x, point.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

// =============================================
// �禡�G getxy
// �����G ���o�ثe��Ц�m
// ============================================
void set_cursor::getxy(int &x, int &y)
{
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        x = csbi.dwCursorPosition.X;
        y = csbi.dwCursorPosition.Y;
}

// ============================================
// �禡�G SetCursorVisible, �]�w�����ܤ��
// �����G ���N�O�]�w��Цh�Τj,�ʤ��� 1~100
// ===========================================
void set_cursor::SetCursorVisible(BOOL Visible, DWORD Size)
{
        CONSOLE_CURSOR_INFO cci;
        cci.bVisible = Visible; // �O�_�i��
        cci.dwSize = Size; // �]�w�j�p,1~100
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}
