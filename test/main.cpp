#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "set_cursor.h"
#include "windows_Console.h"
#include "UI.h"
#include "game_system.h"

using namespace std;

void reset_gamemenu(int *num){
	windows_Console win_c;
	win_c.Clr();
	UI UI;
	UI.base();
	UI.GameMenu();
	*num = 1;
}

int main(int argc, char** argv) {
	
	set_cursor sc;
	windows_Console win_c;
	
	sc.SetCursorVisible(false,1); 
	win_c._SetConsoleTitle(" ( •ω•`)");
	
	UI UI;
	for(int loopnum_start = 0; loopnum_start < 2; loopnum_start++){
		win_c.Clr();
		UI.base();
		UI.GameMenu();
	}
	
	game_system gs;
	gs.game_system_seting(UI.form_width-2,UI.form_height-1,UI.form_top,UI.form_left);
	
	int gamemode = 1;
	
	int key1,key2;
	while(1){
		if (!kbhit())
			key1= getch();
			
		if (key1 == 0 || key1==224){
			key2 = getch();
			switch(key2){
				case 72:
					if(!gs.getgame_start() && !gs.getgame_test()){
						sc.gotoxy(UI.mode1_left-3,UI.mode1_height);
						std::cout << ">> ";
						sc.gotoxy(UI.mode2_left-3,UI.mode2_height);
						std::cout << "   ";
						gamemode = 1;
					}
					break;
				case 80:
					if(!gs.getgame_start() && !gs.getgame_test()){
						sc.gotoxy(UI.mode1_left-3,UI.mode1_height);
						std::cout << "   ";
						sc.gotoxy(UI.mode2_left-3,UI.mode2_height);
						std::cout << ">> ";
						gamemode = 2;	
					}
					break;
			}
		}else{
			switch(key1){
				case 13:
					if(!gs.getgame_start() && !gs.getgame_test()){
						if(gamemode == 2){
							gs.test();
						}
					}
					break;
				case 27:
					if(gs.getgame_test()){
						reset_gamemenu(&gamemode);
						gs.setgame_test(false);
					}else if(!gs.getgame_start()){
						bool error_fortype = false;
						do{
							sc.SetCursorVisible(true,10);
							win_c.Clr();
							UI.base();
							
							if(error_fortype){
								char str1[] = "資料輸入錯誤請重新輸入!!!";
								int L1 = strlen(str1);
								sc.gotoxy(UI.form_left+(UI.form_width-2-L1)/2,UI.form_top+(UI.form_height-1-2)/2-1);
								std::cout << str1;
								error_fortype = false;
							}
							
							char str2[] = "###你是否要關閉遊戲???###";
							char str3[] = "(請輸入Y or N):";
							int L2 = strlen(str2);
							int L3 = strlen(str3);
							sc.gotoxy(UI.form_left+(UI.form_width-2-L2)/2,UI.form_top+(UI.form_height-1-2)/2);
							std::cout << str2;
							sc.gotoxy(UI.form_left+(UI.form_width-2-L3)/2,UI.form_top+(UI.form_height-1-2)/2+1);
							std::cout << str3;
							
							char ans;
							std::cin >> &ans;
							if(ans == 'y' || ans == 'Y')
								exit(0);
							else if (ans == 'n' || ans == 'N')
								reset_gamemenu(&gamemode);
							else
								error_fortype = true; 	
						}while(error_fortype);
						sc.SetCursorVisible(false,10);
					}
					break;
			}
			
			
		}
	}
	return 0;
}
