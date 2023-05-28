#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
char board[9]={'-','-','-','-','-','-','-','-','-'};
char current_player='X';
string player_1,player_2;
bool gameplay=true;
bool winner =true;
void is_board()
{
	system("Color A");
	cout<<setw(34)<<"\n\t****************| TIC TAC TOE GAME |********************\n\n";
	cout<<endl<<"\t***GAME***"<<setw(51)<<"***MANUAL***"<<endl;
	cout<<"\n\t"<<board[0]<<" | "<<board[1]<<" | "<<board[2]<<setw(50)<<"1 | 2 | 3"<<"\t "<<player_1<<"= X"<<endl;
	cout<<"\t"<<"----------"<<setw(50)<<"----------"<<"\t "<<player_2<<"= O"<<endl;
	cout<<"\t"<<board[3]<<" | "<<board[4]<<" | "<<board[5]<<setw(50)<<"4 | 5 | 6"<<endl;
	cout<<"\t"<<"----------"<<setw(50)<<"----------"<<endl;
	cout<<"\t"<<board[6]<<" | "<<board[7]<<" | "<<board[8]<<setw(50)<<"7 | 8 | 9"<<endl;
	cout<<"\t"<<"----------"<<setw(51)<<"----------\n"<<endl;
	Beep(800,50);
}
void entering_data()
{
	bool run=true;
	do{
	int number=0;
	if (current_player=='X')
	{
		cout<<setw(10)<<"Its "<<player_1<<"'s turn plz enter the number between 1 to 9 = ";
		cin>>number;
	}
	else
	{
		cout<<setw(10)<<"Its "<<player_2<<"'s turn plz enter the number between 1 to 9 = ";
		cin>>number;
	}
	if (number>=1&&number<=9&&board[number-1]=='-')
	{
		board[number-1]=current_player;
		run=false;
	}
	else
	cout<<"\t number entered is invalid "<<endl;}while(run);
	system("cls");
	is_board();
}
bool horizontal()
{
	if (board[0]==board[1]&&board[1]==board[2]&&board[0]!='-')
	{
		return true;
	}
	else if (board[3]==board[4]&&board[3]==board[5]&&board[3]!='-')
	{
		return true;
	}
	else if (board[6]==board[7]&&board[7]==board[8]&&board[6]!='-')
	{
		return true;
	}
	else 
	return false;
}
bool vertical()
{
	if (board[0]==board[3]&&board[3]==board[6]&&board[0]!='-')
	{
		return true;
	}
	else if (board[1]==board[4]&&board[1]==board[7]&&board[1]!='-')
	{
		return true;
	}
	else if (board[2]==board[5]&&board[5]==board[8]&&board[2]!='-')
	{
		return true;
	}
	else
	return false;
}
bool diagnal()
{
	if (board[0]==board[4]&&board[4]==board[8]&&board[0]!='-')
	{
		return true;
	}
	else if (board[2]==board[4]&&board[4]==board[6]&&board[2]!='-')
	{
		return true;
	}
	else
	return false;
}
void tie()
{
	if (winner){
	
	int counter=0;
	for (int i=0;i<9;i++)
	{
		if (board[i]=='-')
		{
			counter++;
		}
	}
	if (counter==0)
	{
		cout<<"\tMatch is DRAW ";
		Beep(670,1000);
		gameplay=false;
	}
}
}
void win()
{
	if (horizontal() || vertical() || diagnal() )
	{
	
		if (current_player=='O')
		{
			cout<<"\tCongratulations Winner is : "<<player_2<<endl;
			cout<<"\tBetter Luck Next Time For "<<player_1;
		}
		else
		{
			cout<<"\tCongratulations Winner is : "<<player_1<<endl;
			cout<<"\tBetter Luck Next Time For "<<player_2;
	    }
		Beep(670,1000);
		gameplay=false;
		winner=false;
	}
}
void switch_player()
{
	if (current_player=='X')
	{
		current_player='O';
	}
	else
	current_player='X';
}
int main()
{
	char yes_or_no;
	do{
	system("cls");
	system("Color A");
	cout<<"\n\t******************| MAIN MENU |*****************"<<endl;
	cout<<"\n\t\t Enter first player name = ";
	cin>>player_1;
	cout<<"\n\t\t Enter second player name = ";
	cin>>player_2;
	system("cls");
	is_board();
	while (gameplay)
	{
    entering_data();
    win();
    tie();
    switch_player();
}
	cout<<"\n\n\t\tIf you want to play again press y :";
	cin>>yes_or_no;
	for (int x=0;x<9;x++)
	{board[x]='-';}
	gameplay=true;
	winner=true;
	}while(yes_or_no=='y');
	cout<<"\n\t\tThank You For Playing ";
	getch();
}
