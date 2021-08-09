#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include<stdlib.h>

#define CLRSCR system("cls")

using namespace std;
int CurrBatsmen = 0;
int Currbol = 0;
int scoreA;
int scoreB;
class Team
{
private:
    char teamName[8];
    char teamPlayer1[10];
    char teamPlayer2[10];
    char teamPlayer3[10];
    string randomteam[3];

public:
    void group()
    {
        randomteam[0] = this->teamPlayer1;
        randomteam[1] = this->teamPlayer2;
        randomteam[2] = this->teamPlayer3;
    }

    void ining()
    {
        int randomvalue;
        srand(time(NULL));
        randomvalue = (rand() % 3);
        CurrBatsmen = randomvalue;
        Currbol = randomvalue;
    }
    void randomSelectionbatsmen()
    {
        cout <<endl<< this->randomteam[CurrBatsmen] << " is the Batsmen from " << this->teamName << endl;
    }
    void randomSelectionboller()
    {
        cout <<endl<< this->randomteam[Currbol] << " is the Boller from " << this->teamName << endl;
    }
    void Aplaygame()
    {
        CLRSCR ;
        int ball;
        scoreA = 0;
        char bat;

        srand(time(NULL));

        for (int i = 1; i < 7; i++)
        {
            cout << this->randomteam[CurrBatsmen] 
                 << " Hit space to play the ball   " << endl;
            bat = getch();
            if (bat == ' ')
            {
                ball = (rand() % 7);
                cout << endl<<this->randomteam[CurrBatsmen] << " you scored:   " << ball<<" on  "<<i <<"  ball" << endl;
                scoreA = scoreA + ball;
            }
            else
            {
                cout << "wrong input";
                break;
            }
        }

        cout << "total score :" << scoreA;
    }
    void Bplaygame()
    {
        CLRSCR ;
        int ball;
        int sum = 0;
        char bat;

        srand(time(NULL));

        for (int i = 1; i < 7; i++)
        {
            cout << this->randomteam[CurrBatsmen] 
                 << " Hit space to play the ball   " << endl;
            bat = getch();
            if (bat == ' ')
            {
                ball = (rand() % 7);
                cout <<endl<< this->randomteam[CurrBatsmen] << " you scored:   " << ball<<" on  "<<i<<"  ball" << endl;
                sum = sum + ball;
                scoreB = sum;
                if (scoreB <= (scoreA + 1))
                {

                    continue;
                }
                else
                {
                    
                    break;
                }
            }
            else
            {
                cout << "wrong input";
                break;
            }
        }

        cout << "total score :" << scoreB;
    }

    void showteam()
    {
        cout << " Player of the  " << this->teamName << " Are " << endl
             << this->teamPlayer1 << endl
             << this->teamPlayer2 << endl
             << this->teamPlayer3 << endl;
    }

    Team(char *a, char *b, char *c, char *d)
    {
        strcpy(this->teamName, a);
        strcpy(this->teamPlayer1, b);
        strcpy(this->teamPlayer2, c);
        strcpy(this->teamPlayer3, d);
        this->group();
    }
    void compare()
    {
        CLRSCR ;
        if (scoreA > scoreB)
        {
            cout << endl
                 << " Team A win the Match by " << scoreA - scoreB << " run" << endl;
        }
        else if (scoreA == scoreB)
        {
            cout << endl
                 << " Match draw" << endl;
        }
        else if (scoreB > scoreA)
        {
            cout << endl
                 << " Team B win the Match by " << scoreB - scoreA << " run" << endl;
        }
    }
};

int main()
{
    char teamA[8] = "TEAM A";
    char Player1A[8] = "RAHUL";
    char Player2A[8] = "AMIT";
    char Player3A[8] = "PANKAJ";

    Team A(teamA, Player1A, Player2A, Player3A);

    char teamB[8] = "TEAM B";
    char player1B[8] = "KRISHNA";
    char player2B[8] = "ADITYA";
    char player3B[8] = "RAJ";

    Team B(teamB, player1B, player2B, player3B);

    cout << "Welcome To the Mini cricket " << endl;
    int point;
    cout << "Enter 1 to continue the game" << endl;
    cin >> point;
    if (point = 1)
    {
        A.ining();
        A.showteam();
        B.showteam();
        A.randomSelectionbatsmen();
        B.randomSelectionboller();
        cout<<endl<<" Press Any key to cont.....";
        getch();
        A.Aplaygame();
        cout<<endl<<" Press Any key to cont.....";
        getch();
        B.ining();
        B.randomSelectionbatsmen();
        A.randomSelectionboller();
        cout<<endl<<" Press Any key to cont.....";
        getch();
        B.Bplaygame();
        cout<<endl<<" Press Any key to cont.....";
        getch();
        A.compare();
    }
    else
    {
        cout << " Enter only 1 to start the Game ";
    }
     getch();
    return 0;
}
