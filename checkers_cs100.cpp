#include<iostream>
#include<windows.h>
#include <stdio.h>
#pragma comment(lib, "Winmm.lib")
#include <MMSystem.h>

using namespace std;
    void SetConsoleColour(WORD* Attributes, DWORD Colour)
{
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    *Attributes = Info.wAttributes;
    SetConsoleTextAttribute(hStdout, Colour);
}

void ResetConsoleColour(WORD Attributes)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}
void welcome();
void printboard(char checkerboard[8][8]); //to print the board
void initboardr(char checkerboard[8][8]); //initialize position of red checkers
void initboardb(char checkerboard[8][8]); //initialize position of black checkers
void initboards(char checkerboard[8][8]); //initialize the middle 2 empty rows
void initboardw(char checkerboard[8][8]); //white boxes where checkers can't go
void checkmoveb(char checkerboard[8][8]); //black player makes a move
void checkmover(char checkerboard[8][8]); //red player makes a move
bool kturn=false;

int main()
{

    //char * WAV = "C:\\Users\\zain\\Desktop\\songszz.wav";
    //sndPlaySound (WAV,SND_ASYNC);
    system("PAUSE");
     system("color 0a");
 cout<<"\n\n\n\t\t\t\t\t\t\t\t\t   Please wait while loading\n\n";
 char a=177, b=219;
 cout<<"\t\t\t\t\t\t\t\t\t      ";
 for (int i=0;i<=15;i++)
 cout<<a;
 cout<<"\r";
 cout<<"\t\t\t\t\t\t\t\t\t      ";
 for (int i=0;i<=15;i++)
 {
  cout<<b;

  for (int j=0;j<=1e8;j++); //You can also use sleep function instead of for loop
 }
 cout<<endl;

   int x=0,y=0;
   char quit='a';
   char checkerboard1[8][8];
   welcome();
   initboardw(checkerboard1);
   initboardr(checkerboard1);
   initboardb(checkerboard1);
   initboards(checkerboard1);
   printboard(checkerboard1);
   while(quit!='y' && quit!='Y')
   {
       do
       {
           cout<<"Black's Turn"<<endl;
           cout<<"Quit?(Y/N):";
           cin>>quit;
           if(quit!='y' && quit!='Y')
           {
                kturn=false;
                x=0,y=0;
                checkmoveb(checkerboard1);
                printboard(checkerboard1);
                for(int i=0;i<8;i++)
                {
                    for(int j=0;j<8;j++)
                        {
                            if(checkerboard1[i][j]=='R' || checkerboard1[i][j]=='%')
                                x++;
                        }
                }
            }
       }
       while(kturn==true);
       if(x==0)
       {
               quit='y';
               cout<<"Congratulations! Black wins!";
       }
       else
       {
            do
            {
               cout<<"Red's Turn"<<endl;
               cout<<"Quit?(Y/N):";
               cin>>quit;
               if(quit!='y' && quit!='Y')
               {
                   kturn=false;
                   checkmover(checkerboard1);
                   printboard(checkerboard1);
                   for(int i=0;i<8;i++)
                   {
                      for(int j=0;j<8;j++)
                      {
                        if(checkerboard1[i][j]=='B' || checkerboard1[i][j]=='$')
                            y++;
                      }
                   }
                   if(y==0)
                   {
                       quit='y';
                       cout<<"Congratulations! Red wins!";
                   }
               }
            }
            while(kturn==true);
        }
    }
}

void printboard(char checkerboard[8][8])
{
    int x=0,y=0,l=0,m=0;
    for(int i=0;i<8;i++)
    {
            for(int j=0;j<8;j++)
            {
                    if(checkerboard[i][j]=='R' || checkerboard[i][j]=='%')
                        x++;
            }
    }
    for(int i=0;i<8;i++)
    {
            for(int j=0;j<8;j++)
            {
                    if(checkerboard[i][j]=='B' || checkerboard[i][j]=='$')
                        y++;
            }
    }
    for(int i=0;i<8;i++)
    {
            for(int j=0;j<8;j++)
            {
                    if(checkerboard[i][j]=='%')
                        l++;
            }
    }
    for(int i=0;i<8;i++)
    {
            for(int j=0;j<8;j++)
            {
                    if(checkerboard[i][j]=='$')
                        m++;
            }
    }
    cout<<"                                  "                                                                                                                                                                                                                                             <<endl;
    cout<<"---1----2----3----4----5----6----7----8---                      -----------------------"                                                                                                                                                                                        <<endl;
    cout<<"-     #####     #####     #####     #####-                      |  BLACK   |   RED    |"                                                                                                                                                                                        <<endl;
    cout<<"1  "<<checkerboard[0][0]<<"  ##"<<checkerboard[0][1]<<"##  "<<checkerboard[0][2]<<"  ##"<<checkerboard[0][3]<<"##  "<<checkerboard[0][4]<<"  #"<<checkerboard[0][5]<<"###  "<<checkerboard[0][6]<<"  ##"<<checkerboard[0][7]<<"##1                      | CHECKERS | CHECKERS |"<<endl;
    cout<<"-     #####     #####     #####     #####-                      -----------------------"                                                                                                                                                                                        <<endl;
    cout<<"-#####     #####     #####     #####     -                           "<<y<<"         "<<x<<"     "                                                                                                                                                                              <<endl;
    cout<<"2##"<<checkerboard[1][0]<<"##  "<<checkerboard[1][1]<<"  ##"<<checkerboard[1][2]<<"##  "<<checkerboard[1][3]<<"  ##"<<checkerboard[1][4]<<"##  "<<checkerboard[1][5]<<"  ##"<<checkerboard[1][6]<<"##  "<<checkerboard[1][7]<<"  2"<<endl;
    cout<<"-#####     #####     #####     #####     -"                                                                                                                                                                                        <<endl;

    cout<<"-     #####     #####     #####     #####-"                                                                                                                                                                                        <<endl;
    cout<<"3  "<<checkerboard[2][0]<<"  ##"<<checkerboard[2][1]<<"##  "<<checkerboard[2][2]<<"  ##"<<checkerboard[2][3]<<"##  "<<checkerboard[2][4]<<"  ##"<<checkerboard[2][5]<<"##  "<<checkerboard[2][6]<<"  ##"<<checkerboard[2][7]<<"##3"<<endl;
    cout<<"-     #####     #####     #####     #####-          "                                                                                                                                                                              <<endl;
    cout<<"-#####     #####     #####     #####     -                   "                                                                                                                                                                     <<endl;
    cout<<"4##"<<checkerboard[3][0]<<"##  "<<checkerboard[3][1]<<"  ##"<<checkerboard[3][2]<<"##  "<<checkerboard[3][3]<<"  ##"<<checkerboard[3][4]<<"##  "<<checkerboard[3][5]<<"  ##"<<checkerboard[3][6]<<"##  "<<checkerboard[3][7]<<"  4"<<endl;
    cout<<"-#####     #####     #####     #####     -"                                                                                                                                                                                        <<endl;

    cout<<"-     #####     #####     #####     #####-                      -----------------------                "                                                                                                                                                                                    <<endl;
    cout<<"5  "<<checkerboard[4][0]<<"  ##"<<checkerboard[4][1]<<"##  "<<checkerboard[4][2]<<"  ##"<<checkerboard[4][3]<<"##  "<<checkerboard[4][4]<<"  ##"<<checkerboard[4][5]<<"##  "<<checkerboard[4][6]<<"  ##"<<checkerboard[4][7]<<"##5                      |  BLACK   |   RED    |            "<<endl;
    cout<<"-     #####     #####     #####     #####-                      | KINGS($) | KINGS(%) |                "                                                                                                                                                                                    <<endl;
    cout<<"-#####     #####     #####     #####     -                      -----------------------                "                                                                                                                                                                                    <<endl;
    cout<<"6##"<<checkerboard[5][0]<<"##  "<<checkerboard[5][1]<<"  ##"<<checkerboard[5][2]<<"##  "<<checkerboard[5][3]<<"  ##"<<checkerboard[5][4]<<"##  "<<checkerboard[5][5]<<"  ##"<<checkerboard[5][6]<<"##  "<<checkerboard[5][7]<<"  6                           "<<m<<"          "<<l<<"      "<<endl;
    cout<<"-#####     #####     #####     #####     -"                                                                                                                                                                                        <<endl;

    cout<<"-     #####     #####     #####     #####-"                                                                                                                                                                                        <<endl;
    cout<<"7  "<<checkerboard[6][0]<<"  ##"<<checkerboard[6][1]<<"##  "<<checkerboard[6][2]<<"  ##"<<checkerboard[6][3]<<"##  "<<checkerboard[6][4]<<"  ##"<<checkerboard[6][5]<<"##  "<<checkerboard[6][6]<<"  ##"<<checkerboard[6][7]<<"##7"<<endl;
    cout<<"-     #####     #####     #####     #####-"                                                                                                                                                                                        <<endl;
    cout<<"-#####     #####     #####     #####     -"                                                                                                                                                                                        <<endl;
    cout<<"8##"<<checkerboard[7][0]<<"##  "<<checkerboard[7][1]<<"  ##"<<checkerboard[7][2]<<"##  "<<checkerboard[7][3]<<"  ##"<<checkerboard[7][4]<<"##  "<<checkerboard[7][5]<<"  ##"<<checkerboard[7][6]<<"##  "<<checkerboard[7][7]<<"  8"<<endl;
    cout<<"-#####     #####     #####     #####     -"                                                                                                                                                                                        <<endl;
    cout<<"---1----2----3----4----5----6----7----8---"                                                                                                                                                                                        <<endl;
    cout<<"                                  "                                                                                                                                                                                                <<endl;
}
void initboardr(char checkerboard[8][8])
{
    WORD Attributes = 0;
    for(int i=0;i<3;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<8;j++)
          {
            if(j%2==0)
            {
                SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED);
                checkerboard[i][j]='R';
                ResetConsoleColour(Attributes);
            }
          }
        }                                 //alternating R checkers
        else
        {for(int j=0;j<8;j++)
          {
            if(j%2!=0)
            {
                SetConsoleColour(&Attributes, FOREGROUND_INTENSITY | FOREGROUND_RED);
                checkerboard[i][j]='R';
                ResetConsoleColour(Attributes);
            }

        }
    }
}
    }
void initboardb(char checkerboard[8][8])
{
    for(int i=5;i<8;i++)
    {
        if(i%2!=0)
        {for(int j=0;j<8;j++)
          {
            if(j%2!=0)
                checkerboard[i][j]='B';
          }
        }                                //alternating B checkers
        else
        {for(int j=0;j<8;j++)
          {
            if(j%2==0)
                checkerboard[i][j]='B';
          }
        }
    }
}
void initboards(char checkerboard[8][8])
{
    for(int i=3;i<5;i++)
    {
        if(i%2!=0)
        {
            for(int j=0;j<8;j++)
            {
                if(j%2!=0)
                checkerboard[i][j]=' ';
            }
        }                                 //alternating black boxes or spaces
        else
            for(int j=0;j<8;j++)
            {
                if(j%2==0)
                checkerboard[i][j]=' ';
            }
    }
}
void initboardw(char checkerboard[8][8])
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)              //turns entire board white or * which is later overwritten
            checkerboard[i][j]='#';
    }
}
void checkmoveb(char checkerboard[8][8]) //black takes turn
{
    int x,y,x1,y1;
    bool valid=false;
    do
    {
        do
        {
            do
            {
                cout<<"Enter checker's current x-coordinate:";
                cin>>x;
                if(x<=0 || x>8)
                    cout<<"Wrong co-ordinate entered!"<<endl;
            }
            while(x<=0 || x>8);
            do
            {
                cout<<"Enter checker's current y-coordinate:";
                cin>>y;
                if(y<=0 || y>8)
                    cout<<"Wrong co-ordinate entered!"<<endl;
            }
            while(y<=0 || y>8);
            if(checkerboard[y-1][x-1]!='B' && checkerboard[y-1][x-1]!='$')
                cout<<"Wrong co-ordinates entered!"<<endl;
        }
        while(checkerboard[y-1][x-1]!='B' && checkerboard[y-1][x-1]!='$');
        do
        {
            cout<<"Enter checker's new x-coordinate:";
            cin>>x1;
            if(x1<=0 || x1>8)
                cout<<"Wrong co-ordinate entered!"<<endl;
        }
        while(x1<=0 || x1>8);
        do
        {
            cout<<"Enter checker's new y-coordinate:";
            cin>>y1;
            if(y1<=0 || y1>8)
                cout<<"Wrong co-ordinate entered"<<endl;
        }
        while(y1<=0 || y1>8);
        if(checkerboard[y1-1][x1-1]==' ')
        {
                if(checkerboard[y-1][x-1]=='$')            //black moving his king
                {
                    if((x1==x-1 && y1==y-1) || (x1==x+1 && y1==y-1)) //checks if king is moving diagnally
                    {
                        checkerboard[y1-1][x1-1]='$';
                        checkerboard[y-1][x-1]=' ';
                        valid=true;
                    }
                    else if(x1==x+2 && y1==y-2)
                    {
                        if(checkerboard[y-2][x]=='R' || checkerboard[y-2][x]=='%')
                        {
                            checkerboard[y1-1][x1-1]='$';
                            checkerboard[y-1][x-1]=' ';              //black king kills red's checker
                            checkerboard[y-2][x]=' ';
                            valid=true;
                            kturn=true;
                        }

                    }
                    else if(x1==x-2 && y1==y-2)
                    {
                        if(checkerboard[y-2][x-2]=='R' || checkerboard[y-2][x-2]=='%')
                        {
                            checkerboard[y1-1][x1-1]='$';
                            checkerboard[y-1][x-1]=' ';              //black king kills red's checker
                            checkerboard[y-2][x-2]=' ';
                            valid=true;
                            kturn=true;
                        }
                    }
                    else if((x1==x-1 && y1==y+1) || (x1==x+1 && y1==y+1)) //checks if black king is moving diagnally
                    {
                        checkerboard[y1-1][x1-1]='$';
                        checkerboard[y-1][x-1]=' ';
                        valid=true;
                    }
                    else if(x1==x+2 && y1==y+2)
                    {
                        if(checkerboard[y][x]=='R' || checkerboard[y][x]=='%')
                        {
                            checkerboard[y1-1][x1-1]='$';
                            checkerboard[y-1][x-1]=' ';              //black king kills red's checker
                            checkerboard[y][x]=' ';
                            valid=true;
                            kturn=true;
                        }
                    }
                    else if(x1==x-2 && y1==y+2)
                    {
                        if(checkerboard[y][x-2]=='R' || checkerboard[y][x-2]=='%')
                        {
                            checkerboard[y1-1][x1-1]='$';
                            checkerboard[y-1][x-1]=' ';              //black king kills red's checker
                            checkerboard[y][x-2]=' ';
                            valid=true;
                            kturn=true;
                        }
                    }
                }
                else if((x1==x-1 && y1==y-1) || (x1==x+1 && y1==y-1)) //checks if checker is moving diagnally
                {
                    if(y1==1)
                    {
                        checkerboard[y1-1][x1-1]='$';
                        checkerboard[y-1][x-1]=' ';
                    }
                    else
                    {
                        checkerboard[y1-1][x1-1]='B';
                        checkerboard[y-1][x-1]=' ';
                    }
                    valid=true;
                }

                else if(x1==x+2 && y1==y-2)
                {
                    if(y1==1)
                    {
                        if(checkerboard[y-2][x]=='R' || checkerboard[y-2][x]=='%')
                        {
                            checkerboard[y1-1][x1-1]='$';
                            checkerboard[y-1][x-1]=' ';
                            checkerboard[y-2][x]=' ';
                            valid=true;
                            kturn=true;
                        }
                    }
                    else if(checkerboard[y-2][x]=='R' || checkerboard[y-2][x]=='%')
                    {
                            checkerboard[y1-1][x1-1]='B';
                            checkerboard[y-1][x-1]=' ';              //kills red's checker
                            checkerboard[y-2][x]=' ';
                            valid=true;
                            kturn=true;
                    }

                }
                else if(x1==x-2 && y1==y-2)
                {
                    if(y1==1)
                    {
                        if(checkerboard[y-2][x-2]=='R' || checkerboard[y-2][x-2]=='%')
                        {
                            checkerboard[y1-1][x1-1]='$';
                            checkerboard[y-1][x-1]=' ';
                            checkerboard[y-2][x-2]=' ';
                            valid=true;
                            kturn=true;
                        }
                    }
                    else if(checkerboard[y-2][x-2]=='R' || checkerboard[y-2][x-2]=='%')
                    {
                            checkerboard[y1-1][x1-1]='B';
                            checkerboard[y-1][x-1]=' ';              //kills red's checker
                            checkerboard[y-2][x-2]=' ';
                            valid=true;
                            kturn=true;
                    }
                }
                else
                {
                    valid=false;
                    cout<<"Invalid move!"<<endl;
                }
        }
        else
        {
            valid=false;
            cout<<"Invalid move! Location already occupied."<<endl;
        }
        if(valid==false)
            cout<<"Invalid move!"<<endl;
    }
    while(valid==false);
}
void checkmover(char checkerboard[8][8]) //red takes turn
{
    int x,y,x1,y1;
    bool valid=false;
    do
    {
        do
        {
            do
            {
                cout<<"Enter checker's current x-coordinate:";
                cin>>x;
                if(x<=0 || x>8)
                    cout<<"Wrong co-ordinates entered!"<<endl;
            }
            while(x<=0 || x>8);
            do
            {
                cout<<"Enter checker's current y-coordinate:";
                cin>>y;
                if(y<=0 || y>8)
                    cout<<"Wrong co-ordinates entered!"<<endl;
            }
            while(y<=0 || y>8);
            if(checkerboard[y-1][x-1]!='R' && checkerboard[y-1][x-1]!='%')
                cout<<"Wrong co-ordinates entered!"<<endl;
        }
        while(checkerboard[y-1][x-1]!='R' && checkerboard[y-1][x-1]!='%');
        do
        {
            cout<<"Enter checker's new x-coordinate:";
            cin>>x1;
            if(x1<=0 || x1>8)
                cout<<"Wrong co-ordinate entered!"<<endl;
        }
        while(x1<=0 || x1>8);
        do
        {
            cout<<"Enter checker's new y-coordinate:";
            cin>>y1;
            if(y1<=0 || y1>8)
                cout<<"Wrong co-ordinate entered!"<<endl;
        }
        while(y1<=0 || y1>8);
        if(checkerboard[y1-1][x1-1]==' ')
        {
                if(checkerboard[y1-1][x1-1]=='%')
                {
                    if((x1==x-1 && y1==y+1) || (x1==x+1 && y1==y+1)) //checks if red king is moving diagnally
                    {
                        checkerboard[y1-1][x1-1]='%';
                        checkerboard[y-1][x-1]=' ';
                        valid=true;
                    }
                    else if(x1==x+2 && y1==y+2)
                    {
                        if(checkerboard[y][x]=='B' || checkerboard[y][x]=='$')
                        {
                            checkerboard[y1-1][x1-1]='%';
                            checkerboard[y-1][x-1]=' ';              //red king kills black's checker
                            checkerboard[y][x]=' ';
                            valid=true;
                            kturn=true;
                        }
                    }
                    else if(x1==x-2 && y1==y+2)
                    {
                        if(checkerboard[y][x-2]=='B' || checkerboard[y][x-2]=='$')
                        {
                            checkerboard[y1-1][x1-1]='%';
                            checkerboard[y-1][x-1]=' ';              //red king kills black's checker
                            checkerboard[y][x-2]=' ';
                            valid=true;
                            kturn=true;
                        }
                    }
                    else if((x1==x-1 && y1==y-1) || (x1==x+1 && y1==y-1)) //checks if red king is moving diagnally
                    {
                        checkerboard[y1-1][x1-1]='%';
                        checkerboard[y-1][x-1]=' ';
                        valid=true;
                    }
                    else if(x1==x+2 && y1==y-2)
                    {
                        if(checkerboard[y-2][x]=='B' || checkerboard[y-2][x]=='$')
                        {
                            checkerboard[y1-1][x1-1]='%';
                            checkerboard[y-1][x-1]=' ';              //red king kills black's checker
                            checkerboard[y-2][x]=' ';
                            valid=true;
                            kturn=true;
                        }
                    }
                    else if(x1==x-2 && y1==y-2)
                    {
                        if(checkerboard[y-2][x-2]=='B' || checkerboard[y-2][x-2]=='$')
                        {
                            checkerboard[y1-1][x1-1]='%';
                            checkerboard[y-1][x-1]=' ';              //red king kills black's checker
                            checkerboard[y-2][x-2]=' ';
                            valid=true;
                            kturn=true;
                        }
                    }
                }
                else if((x1==x-1 && y1==y+1) || (x1==x+1 && y1==y+1)) //checks if checker is moving diagnally
                {
                    if(y1==8)
                    {
                        checkerboard[y1-1][x1-1]='%';
                        checkerboard[y-1][x-1]=' ';
                    }
                    else
                    {
                        checkerboard[y1-1][x1-1]='R';
                        checkerboard[y-1][x-1]=' ';
                    }
                    valid=true;
                }
                else if(x1==x+2 && y1==y+2)
                {
                    if(y1==8)
                    {
                        if(checkerboard[y][x]=='B' || checkerboard[y][x]=='$')
                        {
                            checkerboard[y1-1][x1-1]='%';
                            checkerboard[y-1][x-1]=' ';
                            checkerboard[y][x]=' ';
                            valid=true;
                            kturn=true;
                        }
                    }
                    else if(checkerboard[y][x]=='B' || checkerboard[y][x]=='$')
                    {
                        checkerboard[y1-1][x1-1]='R';
                        checkerboard[y-1][x-1]=' ';              //kills black's checker
                        checkerboard[y][x]=' ';
                        valid=true;
                        kturn=true;
                    }
                }
                else if(x1==x-2 && y1==y+2)
                {
                    if(y1==8)
                    {
                        if(checkerboard[y][x-2]=='B' || checkerboard[y][x-2]=='$')
                        {
                            checkerboard[y1-1][x1-1]='%';
                            checkerboard[y-1][x-1]=' ';
                            checkerboard[y][x]=' ';
                            valid=true;
                            kturn=true;
                        }
                    }
                    else if(checkerboard[y][x-2]=='B' || checkerboard[y][x-2]=='$')
                    {
                        checkerboard[y1-1][x1-1]='R';
                        checkerboard[y-1][x-1]=' ';              //kills black's checker
                        checkerboard[y][x-2]=' ';
                        valid=true;
                        kturn=true;
                    }
                }
                else
                {
                    valid=false;
                    cout<<"Invalid move!"<<endl;
                }
        }
        else
        {
            valid=false;
            cout<<"Invalid move! Location already occupied."<<endl;
        }
        if(valid==false)
            cout<<"Invalid move!"<<endl;
    }
    while(valid==false);
}
void welcome()
    {

     HANDLE  hConsole;
    int k;

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // you can loop k higher to see more color choices
  for(k = 150; k <=160; k++)
  {
    SetConsoleTextAttribute(hConsole, k);
    if (k==159)
    {
    cout<<"                                     * * * * * *   * *     * *   * * * * *   * * * * * *   * *    * *   * * * * *   * * * * * *   * * * * *                                 "<<endl;
    cout<<"                                     * * * * * *   * *     * *   * * * * *   * * * * * *   * *   * *    * * * * *   * * * * * *   * * * * *                                 "<<endl;
    cout<<"                                     * *           * *     * *   * *         * *           * *  * *     * *         * *     * *   * *                                       "<<endl;
    cout<<"                                     * *           * *     * *   * *         * *           * * * *      * *         * *     * *   * *                                       "<<endl;
    cout<<"                                     * *           * * * * * *   * * * * *   * *           * *  *       * * * * *   * * * * * *   * * * * *                                 "<<endl;
    cout<<"                                     * *           * * * * * *   * * * * *   * *           * * *        * * * * *   * * * * * *   * * * * *                                 "<<endl;
    cout<<"                                     * *           * * * * * *   * * * * *   * *           * *  *       * * * * *   * * *         * * * * *                                 "<<endl;
    cout<<"                                     * *           * *     * *   * *         * *           * * * *      * *         * * * *             * *                                 "<<endl;
    cout<<"                                     * *           * *     * *   * *         * *           * *  * *     * *         * *   * *           * *                                 "<<endl;
    cout<<"                                     * * * * * *   * *     * *   * * * * *   * * * * * *   * *   * *    * * * * *   * *     * *   * * * * *                                 "<<endl;
    cout<<"                                     * * * * * *   * *     * *   * * * * *   * * * * * *   * *    * *   * * * * *   * *       *   * * * * *                                 "<<endl;

    }
    else
    cout<<"                                                                                                                                                                            "<<endl;

  }
  system ("pause");
  system("color f0");
    }


