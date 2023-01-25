#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
void clean_down();
void clean_return();
void set_cursor(bool hide) { 
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo); 
	CursorInfo.bVisible = hide;				   
	SetConsoleCursorInfo(handle, &CursorInfo); 
}
void gotoxy(int x, int y) { 
	COORD c = {(SHORT)x, (SHORT)y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setmode() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin, &mode);
	mode &= ~ENABLE_QUICK_EDIT_MODE; 
	SetConsoleMode(hStdin, mode);
}
struct Click {
	int x, y;
	int delay;
	int button_down, button_up;
	std::string msg;
};
void clean_test(int m){
	CONSOLE_FONT_INFOEX cfi;
cfi.cbSize = sizeof(cfi);
cfi.nFont = 0;
cfi.dwFontSize.X = 0;                   
cfi.dwFontSize.Y = m;                  
cfi.FontFamily = FF_DONTCARE;
cfi.FontWeight = FW_NORMAL;
std::wcscpy(cfi.FaceName, L"Consolas"); 
SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}
void clean_welcome(){
	clean_test(50);
cout<<"\n\n\n\n\n\n\n\n\t\t   一键清理正在启动\n";
}
void clean_mode(){
	set_cursor(1);
	int x,y;
	gotoxy(x,y);
	setmode();
}
void clean_welcome2(){
	Sleep(2000);
	system("cls");
	clean_test(24);
 
}
void clean_main(int u){
	cout <<"正在清除系统垃圾文件，请稍等......\n";
	system("clean.bat");
	cout<<"\n一键清理系统垃圾完成！";
	if(u==1){
		clean_down();
	}else if(u==2){
		clean_return();
	} else if(u==3){
		system("pause");
	}
}
void clean_down(){
	system("shutdown -s -t 1");
}
void clean_return(){
	system("shutdown -r -t 0");
}
void clean_set(){
_2_:	cout<<"欢迎使用一键清理\n";
	cout<<"它可以清除系统垃圾文件\n";
	cout<<"你可以用经典设置和自定义,\n1.经典\t2.自定义\n请输入：";
	int set;
	cin>>set;
	if(set==1){
		clean_main(3);
	}else if(set==2){
_1_:		cout<<"在完成后，你想让电脑做什么？\n1.关机\t2.重启\t3.不做反应\n请输入：";
		 cin>>set;
		 if(set==1){
		 	clean_main(1);
		 }else if(set==2){
		 	clean_main(2);
		 }else if(set==3){	
		 	clean_main(3);
		 }else{
		 	cout<<"请重新输入";
		 	system("cls");
		 	goto _1_;
		 }
	}else{
		cout<<"请重新输入";
		 	system("cls");
		 	goto _2_;
	} 
}

void clean_h(){
	system("nircmd standby");
}
int main( ){
	system("title 一键清理"); 
	clean_mode();
	clean_welcome();
	clean_welcome2();
    clean_set();
	return 0;
	}
