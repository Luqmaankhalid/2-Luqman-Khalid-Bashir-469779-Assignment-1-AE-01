#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

char turn[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
char player_1='X';
char player_2='O'; 
string name1,name2;
void displayboard()
{
    cout<<" "<<turn[0][0]<<" | "<<turn[0][1]<<" | "<<turn[0][2]<<" "<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<turn[1][0]<<" | "<<turn[1][1]<<" | "<<turn[1][2]<<" "<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<turn[2][0]<<" | "<<turn[2][1]<<" | "<<turn[2][2]<<" "<<endl;
}
void resetboard()
{
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(turn[i][j]!=' ')
            turn[i][j]=' ';
        }
    }
}
int checkspace()
{
    int freeSpace = 9;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (turn[i][j] != ' ')
                freeSpace--;
    return freeSpace;
}

void player_1move()
{
    if(checkspace()){
        int row,column;
        do {
            cout<<name1<<" Enter row number(from 1 to 3): ";
            cin>>row;
            cout<<"Enter column number(from 1 to 3): ";
            cin>>column;
            if(turn[row-1][column-1]!=' ')
                cout<<"Invalid Move. Try again."<<endl;
            else 
            {
                turn[row-1][column-1]=player_1;
                break;
            }
           
        }
        while(turn[row-1][column-1]!=' ');
        displayboard();
    }
}

void player_2move()
{
    if(checkspace())
    {
        int row,column;
        do {
            cout<<name2<<" Enter row number(from 1 to 3): ";
            cin>>row;
            cout<<"Enter column number(from 1 to 3): ";
            cin>>column;
        
            if(turn[row-1][column-1]!=' ')
                cout<<"Invalid Move. Try again."<<endl;
            else {
                turn[row-1][column-1]=player_2;
                break;
            }
        
        } while(turn[row-1][column-1]!=' ');
        displayboard();
    }
}
void computer_move()
{
    srand(time(0));
    while (1)
    {
        int row = rand() % 3;
        int column = rand() % 3;
        if (turn[row][column] != ' ')
            continue;
        else
        {
            turn[row][column] = player_2;
            break;
        }
    }
    cout << "Computer's move:" << endl;
    displayboard();
}
char checkwinner()
{
    for(int i=0;i<3;i++)
        if(turn[i][0]==turn[i][1]&&turn[i][0]==turn[i][2])
            return turn[i][0];
    for(int j=0;j<3;j++)
        if(turn[0][j]==turn[1][j]&&turn[2][j]==turn[0][j])
            return turn[0][j];
    if(turn[0][0]==turn[1][1]&&turn[2][2]==turn[0][0] || turn[0][2]==turn[1][1]&&turn[2][0]==turn[0][2]) // Fixed this line
        return turn[1][1];
    else
        return ' ';
}

int main()
{
   char again;
   
do{
cout<<"Welcome to tic tac toe!"<<endl;
cout<<"Do you want to play with dumb Alexa or another player: "<<endl;
cout<<"Press 1 for Alexa and press 2 for other player: ";
int choice;
cin>>choice;
switch(choice)
{case 1:
   { resetboard();
   displayboard();
   cout<<"Enter you name: ";
   cin>>name1;
    while(checkwinner()==' '&&checkspace()!=0)
    {
        player_1move();
        if(checkwinner()!=' ')break;
        computer_move();
        if(checkwinner()!=' ')break;
    }break;}
case 2:
    {
    resetboard();
    cout<<"Enter player_1 name: ";
    cin>>name1;
    cout<<"Enter player_2 name: ";
    cin>>name2;
    displayboard();
    while(checkwinner()==' '&&checkspace()!=0){
        player_1move();
        if(checkwinner()!=' ' ) 
            break;
        player_2move();
        if(checkwinner()!=' ' ) 
            break;}
        break;
    }
    default:
    cout<<"Invalid input!";break;
    }
    if(checkwinner()=='X')
        cout<<"Congrats!"<<name1<<" ,you won the game"<<endl;
    else if(checkwinner()=='O') 
    if(choice==1)
          cout<<"Alexa wins!";
    else
            cout<<"Congrats!"<<name2<<" ,you won the game"<<endl;
    else
        cout<<"It's a tie"<<endl;
    cout<<"Do you want to play again?(If yes press y and for No press N)"<<endl;
    cin>>again;}
    while(again=='Y'|| again=='y');
    cout<<"Thanks for playing!";
    return 0;
}
