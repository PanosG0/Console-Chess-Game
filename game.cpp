#include "game.h"
#include "pawn.h"
#include "pioni.cpp"
#include <iostream>
using namespace std;
void board::ektupwsh()
{
	int i,j=0;
	cout<<"   1  2  3  4  5  6  7  8"<<endl;
	cout<<"                         "<<endl;
	for (i=7; i>=0; i--)
	{
		cout<<i+1<<"  "<<N[i][j]<<"  "<<N[i][j+1]<<"  "<<N[i][j+2]<<"  "<<N[i][j+3]<<"  "<<N[i][j+4]<<"  "<<N[i][j+5]<<"  "<<N[i][j+6]<<"  "<<N[i][j+7]<<"  "<<i+1<<endl;
	}
	cout<<"                         "<<endl;
	cout<<"   1  2  3  4  5  6  7  8"<<endl;
}
void board::set()
{
	int i,j;
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			N[i][j]=' ';
			katagrafh[i][j]='0';
	    }
    } 
	for (i=0; i<8; i++)
	{
		for (j=0; j<8; j++)
		{
			if ( (i==0 && j==0) || (i==0 && j==7))
			{
				N[i][j]='R';
			}
			else if ((i==7 && j==0) || (i==7 && j==7))
			{
				N[i][j]='r';
			}
			else if ((i==0 && j==1) || (i==0 && j==6))
			{
				N[i][j]='N';
			}
			else if ((i==7 && j==1) || (i==7 && j==6))
			{
				N[i][j]='n';
			}
			else if ((i==0 && j==2) || (i==0 && j==5))
			{
				N[i][j]='B';
			}
			else if ((i==7 && j==2) || (i==7 && j==5))
			{
				N[i][j]='b';
			}
			else if (i==0 && j==3)
			{
				N[i][j]='Q';
			}
			else if (i==7 && j==3)
			{
				N[i][j]='q';
			}
			else if (i==0 && j==4)
			{
				N[i][j]='K';
			}
			else if (i==7 && j==4)
			{
				N[i][j]='k';
			}
			else if ( i==1)
			{
				N[i][j]='P';
			}
			else if (i==6)
			{
				N[i][j]='p';
			}
		}
	}
}

