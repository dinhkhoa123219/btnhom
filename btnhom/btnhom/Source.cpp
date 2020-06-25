#include"Quiz.h"
#include<Windows.h>
#include<conio.h>
#include<stdio.h>
#include<string>
using namespace std;
const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;
const int ENTER = 13;
const int ESC = 27;
const int BACKSPACE = 8;
const int TAB = 9;
const int INS = 82;
const int DEL = 83;
#define color_text1 42 //mau chu 1
#define color_text2 169 //mau chu 2
#define color_fill1 34 // mau nen 1
#define color_fill2 170 // mau nen 2
//void Raw_Button_TAB(int color_text, int color_fill)
//{
//	gotoxy(74, 36); textcolor(color_text); cout << "         ";
//	gotoxy(74, 37); textcolor(color_text); cout << "   TAB   ";
//	gotoxy(74, 38); textcolor(color_text); cout << "         ";
//	gotoxy(70, 39); textcolor(07); cout << "CHON TIEP HANG VAO GIO";
//}
//void Raw_Button_ESC1(int color_text, int color_fill)
//{
//	gotoxy(15, 36); textcolor(color_text); cout << "         ";
//	gotoxy(15, 37); textcolor(color_text); cout << "   ESC   ";
//	gotoxy(15, 38); textcolor(color_text); cout << "         ";
//	gotoxy(11, 39); textcolor(07); cout << "TRO VE MENU CHINH";
//}
//void Raw_Button_OK(int color_text, int color_fill)
//{
//	gotoxy(74, 31); textcolor(color_fill); cout << "         ";
//	gotoxy(74, 32); textcolor(color_text); cout << "  ENTER  ";
//	gotoxy(74, 33); textcolor(color_fill); cout << "         ";
//	gotoxy(74, 34); textcolor(07); cout << "    OK   ";
//}

void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r; 
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void Menu()
{
	
	int x = 50, y = 23;
	system("cls");
	char a = 92;
	resizeConsole(1200,800);
	SetConsoleTitleA("QUIZ");
	textcolor(10);
	string name1;
	string filename;
	int get_ans;
	gotoxy(25, 9);  cout <<" .----------------.  .----------------.  .----------------.  .----------------.  .----------------. ";
	gotoxy(25, 10); cout <<"| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |";
	gotoxy(25, 11); cout <<"| |    ___       | || |  ___    ___  | || |     _____    | || |   ________   | || |   ________   | |";
	gotoxy(25, 12); cout <<"| |  .'   '.     | || |  | |    | |  | || |    |_   _|   | || |  |  __   _|  | || |  |  __   _|  | |";
	gotoxy(25, 13); cout <<"| | /  .-.  " << a << "    | || |  | |    | |  | || |      | |     | || |  |_/  / /    | || |  |_/  / /    | |";
	gotoxy(25, 14); cout <<"| | | |   | |    | || |  | |    | |  | || |      | |     | || |     .'.' _   | || |     .'.' _   | |";
	gotoxy(25, 15); cout <<"| | " << a << "  `-'  _    | || |  | |____| |  | || |     _| |_    | || |   _/ /__/ |  | || |   _/ /__/ |  | |";
	gotoxy(25, 16); cout <<"| |  `.___." << a << "__|  | || |  |_|____|_|  | || |    |_____|   | || |  |________|  | || |  |________|  | |";
	gotoxy(25, 17); cout <<"| |              | || |              | || |              | || |              | || |              | |";
	gotoxy(25, 18); cout <<"| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |";
	gotoxy(25, 19); cout <<" '----------------'  '----------------'  '----------------'  '----------------'  '----------------' ";
	gotoxy(25, 22); cout << endl << endl;
	cout << "Enter your full name and start the test: ";
	getline(cin, name1);
Enter_filename:
	cout << "Nhap ten file cau hoi : ";
	cin >> filename;
	ifstream fileInput(filename);
	if (fileInput.fail())
	{
		std::cout << "Failed to open this file, please retpye the filename !!" << endl;
		goto Enter_filename;
	}
	Quiz Q = Quiz("Bai test so 1", 30);
	Q.importFromFile(filename);
	int score_quizz = 0;
	cout << endl << endl;
	for (int i = 0; i < Q.list_Question.size(); i++)
	{
		cout << Q.list_Question[i] << endl;
		Enter_the_answer :
		cout << " Please tpye 1 or 2 or 3 or 4 to answer the question : ";
		cin >> get_ans;
		//if (get_ans != 1 || get_ans != 2 || get_ans != 3 || get_ans != 4)
		//	goto Enter_the_answer;
		cout << "Cau tra loi dung la : " << Q.list_Question[i].CorrectAnswer() << endl;
		if (get_ans == Q.list_Question[i].CorrectAnswer())
			score_quizz = score_quizz + Q.list_Question[i].choice[Q.list_Question[i].CorrectAnswer()-1].getScore();
	}
	cout << " Point : "<<score_quizz << endl;
}
int main()
{
	Menu();
	
}