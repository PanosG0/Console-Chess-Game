#include "pioni.h"
#include "pawn.cpp"
#include "knight.cpp"
#include "bishop.cpp"
#include "queen.cpp"
#include "rook.cpp"
#include "king.cpp"
#include <cstring>
#include <fstream>
#include <string>
void pioni::play(board& c)
{
	c.turn='w'; //white
	int x1=-1;
	int y1=-1;
	char p=' ';
	char x2,y2;
	int i,j;
	bool flag=true;
	string str;
	fstream f;
	f.open("moves.dat",ios::binary | ios::out | ios::in | ios::trunc);
	if (f.is_open())
	{
	 while(flag)
	 {
		for (i=0; i<8; i++)
		{
			for (j=0; j<8; j++)
			{
				if(c.N[i][j]!=' ')
				{
					x2=(char)i+1;
					y2=(char)j+1;
					p=c.N[i][j];
					f<<x2<<y2<<p<<"0"<<endl;
				}
			}
		}
		flag=false;
	 }
   } 
	p=' ';
	flag=true;
	while(flag)
	{
		f.clear();
	    f.seekg(0,ios::beg);
		check1(c,x1,y1,p);
	    setc();
	    if(move(c) && checkking(c))                                        
	    {
	    	changeturn(c);
	    	x2=(char)(this->x+1);
	    	y2=(char)(this->y+1);
	    	while(getline(f,str))
	    	{
	    		if(str[0]==(char)x1 && str[1]==(char)y1 && str[2]==type)
	    		{
	    			f<<x2<<y2<<p<<"1";
				}
			}
		}
		else
		{
			flag=false;
		}
    }
    char s;
	cout<<"Θέλετε να επαναλάβετε όλες τις κινήσεις που πραγματοποιήθηκαν απο την αρχή; Y/N"<<endl;
	cin>>s;
	if(s=='Y' || s=='y')
	{
		c.set();
		c.ektupwsh();
		f.clear();
		f.seekg(0,ios::beg);
		while(getline(f,str) && !f.eof())
		{
			this->x=(int)str[0];
			this->y=(int)str[1];
			this->type=str[2];
			system("pause");
			system("cls");
			for (i=0; i<8; i++)
			{
				for(j=0; j<8; j++)
				{
					if (c.N[i][j]==type)
					{
						c.N[i][j]=' ';
					}
				}
			}
			c.N[this->x-1][this->y-1]=this->type;
			c.ektupwsh();
		}
	}
	f.close();
}

void pioni::changeturn(board& c)
{
	if (c.turn=='w')
	{
		c.turn='b';
	}
	else
	{
		c.turn='w';
	}
}

void pioni::setc()
{
	if (type<90) // to 90 einai to Z
	{
		colour="white";
	}
	else
	{
		colour="black";
	}
}

void pioni::check1(board& c,int& x1,int& y1,char& p)
{
	if(c.turn=='w')
	{
		cout<<"Είναι η σειρά του παίκτη με τα λευκά πιόνια!";
	}
	else
	{
		cout<<"Είναι η σειρά του παίκτη με τα μαύρα πιόνια!";
	}
	cout<<"                     "<<endl;
	cout<<"Δώσε συντεταγμένες του πιονιού που θες να παίξεις :";
	cin>>x1>>y1;
	while ((x1<1 || x1>8) || (y1<1 || y1>8) || search(x1-1,y1-1,p,c))
	{
	   cout<<"Ξαναπροσπάθησε :";
	   cin>>x1>>y1;
	}
	type=p;
	x=x1-1;
	y=y1-1;
}
bool pioni::search(int x,int y,char& p,board& c)
{
	if (c.turn=='w')
	{
		if(c.N[x][y]!=' ' && c.N[x][y]<90) // to deutero einai elegxos gia to an ontws pairnei leuko pioni kai oxi mauro
	    {
		p=c.N[x][y];
		return false;
	    }
	    else
	    {
		return true; //gia na stamathsei to loop
	    }
	}
	else if (c.turn=='b')
	{
		if(c.N[x][y]!=' ' && c.N[x][y]>90)
		{
		p=c.N[x][y];
		return false;
	    }
	    else
	    {
		return true; 
	    }
	}
	
}
bool pioni::checkking(board& c) // edw na to prospathisw gia checkmate estw
{
	int i,j;
	int wx,wy,bx,by;
	bool flag1=false,flag2=false,flag3=false,flag4=false,flag5=false,flag6=false,flag7=false,flag8=false;
	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			if(c.N[i][j]=='K')
			{
				wx=i;
				wy=j;
			}
			if(c.N[i][j]=='k')
			{
				bx=i;
				by=j;
			}
		}
	}
    if (c.N[wx+1][wy+1]=='q'    ||     c.N[wx+2][wy+2]=='q'    ||      c.N[wx+3][wy+3]=='q'   ||    c.N[wx+4][wy+4]=='q'  || c.N[wx+1][wy+1]=='b'    ||       c.N[wx+2][wy+2]=='b'    ||      c.N[wx+3][wy+3]=='b'   ||    c.N[wx+4][wy+4]=='b'  || c.N[wx+1][wy+1]=='p')
    {
    	flag1=true;
	}
    if (c.N[wx+1][wy]=='q' || c.N[wx+2][wy]=='q' || c.N[wx+3][wy]=='q' || c.N[wx+4][wy]=='q' || c.N[wx+5][wy]=='q' || c.N[wx+6][wy]=='q' ||  c.N[wx+7][wy]=='q' ||  c.N[wx+1][wy]=='r' || c.N[wx+2][wy]=='r' || c.N[wx+3][wy]=='r' || c.N[wx+4][wy]=='r' || c.N[wx+5][wy]=='r' || c.N[wx+6][wy]=='r' ||  c.N[wx+7][wy]=='r')
    {
    	flag2=true;
	}
    if (c.N[wx+1][wy-1]=='q'    ||     c.N[wx+2][wy-2]=='q'    ||      c.N[wx+3][wy-3]=='q'   ||    c.N[wx+4][wy-4]=='q'  || c.N[wx+1][wy-1]=='b'    ||       c.N[wx+2][wy-2]=='b'    ||      c.N[wx+3][wy-3]=='b'   ||    c.N[wx+4][wy-4]=='b'  ||  c.N[wx+1][wy-1]=='p')
    {
    	flag3=true;
	}
    if (c.N[wx][wy+1]=='q' || c.N[wx][wy+2]=='q' || c.N[wx][wy+3]=='q' || c.N[wx][wy+4]=='q' || c.N[wx][wy+5]=='q' || c.N[wx][wy+6]=='q' ||  c.N[wx][wy+7]=='q' ||  c.N[wx][wy+1]=='r' || c.N[wx][wy+2]=='r' || c.N[wx][wy+3]=='r' || c.N[wx][wy+4]=='r' || c.N[wx][wy+5]=='r' || c.N[wx][wy+6]=='r' ||  c.N[wx][wy+7]=='r')
    {
    	flag4=true;
	}
    if (c.N[wx][wy-1]=='q' || c.N[wx][wy-2]=='q' || c.N[wx][wy-3]=='q' || c.N[wx][wy-4]=='q' || c.N[wx][wy-5]=='q' || c.N[wx][wy-6]=='q' ||  c.N[wx][wy-7]=='q' ||  c.N[wx][wy-1]=='r' || c.N[wx][wy-2]=='r' || c.N[wx][wy-3]=='r' || c.N[wx][wy-4]=='r' || c.N[wx][wy-5]=='r' || c.N[wx][wy-6]=='r' ||  c.N[wx][wy-7]=='r')
    {
    	flag5=true;
	}
    if(c.N[wx-1][wy+1]=='q'    ||     c.N[wx-2][wy+2]=='q'    ||      c.N[wx-3][wy+3]=='q'   ||    c.N[wx-4][wy+4]=='q'  || c.N[wx-1][wy+1]=='b'    ||       c.N[wx-2][wy+2]=='b'    ||      c.N[wx-3][wy+3]=='b'   ||    c.N[wx-4][wy+4]=='b' )
    {
    	flag6=true;
	}
    if (c.N[wx-1][wy]=='q' || c.N[wx-2][wy]=='q' || c.N[wx-3][wy]=='q' || c.N[wx-4][wy]=='q' || c.N[wx-5][wy]=='q' || c.N[wx-6][wy]=='q' ||  c.N[wx-7][wy]=='q' ||  c.N[wx-1][wy]=='r' || c.N[wx-2][wy]=='r' || c.N[wx-3][wy]=='r' || c.N[wx-4][wy]=='r' || c.N[wx-5][wy]=='r' || c.N[wx-6][wy]=='r' ||  c.N[wx-7][wy]=='r')
    {
    	flag7=true;
	}
    if (c.N[wx-1][wy-1]=='q'    ||     c.N[wx-2][wy-2]=='q'    ||      c.N[wx-3][wy-3]=='q'   ||    c.N[wx-4][wy-4]=='q'  || c.N[wx-1][wy-1]=='b'    ||       c.N[wx-2][wy-2]=='b'    ||      c.N[wx-3][wy-3]=='b'   ||    c.N[wx-4][wy-4]=='b')
    {
    	flag8=true;
	}
	if (flag1 && flag2 && flag3 && flag4 && flag5 &&flag6 &&flag7 && flag8)
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα μαύρα πιόνια!"<<endl;
		return false;
	}
	if (flag1 && c.N[wx+1][wy]!=' '  && c.N[wx][wy+1]!=' ' && c.N[wx][wy-1]!=' '  && c.N[wx-1][wy+1]!=' '  && c.N[wx-1][wy]!=' ' && c.N[wx-1][wy-1]!=' ' && c.N[wx+1][wy-1]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα μαύρα πιόνια!"<<endl;
		return false;
	}
	if (flag2 && c.N[wx+1][wy+1]!=' ' && c.N[wx][wy+1]!=' ' && c.N[wx][wy-1]!=' '  && c.N[wx-1][wy+1]!=' '  && c.N[wx-1][wy]!=' ' && c.N[wx-1][wy-1]!=' ' && c.N[wx+1][wy-1]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα μαύρα πιόνια!"<<endl;
		return false;
	}
	if (flag3 && c.N[wx+1][wy+1]!=' ' && c.N[wx][wy+1]!=' ' && c.N[wx][wy-1]!=' '  && c.N[wx-1][wy+1]!=' '  && c.N[wx-1][wy]!=' ' && c.N[wx-1][wy-1]!=' ' && c.N[wx+1][wy]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα μαύρα πιόνια!"<<endl;
		return false;
	}
	if (flag4 && c.N[wx+1][wy+1]!=' ' && c.N[wx+1][wy-1]!=' '  && c.N[wx][wy-1]!=' '  && c.N[wx-1][wy+1]!=' '  && c.N[wx-1][wy]!=' ' && c.N[wx-1][wy-1]!=' ' && c.N[wx+1][wy]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα μαύρα πιόνια!"<<endl;
		return false;
	}
	if (flag5 && c.N[wx+1][wy+1]!=' ' && c.N[wx+1][wy-1]!=' '  && c.N[wx][wy-1]!=' '  && c.N[wx-1][wy+1]!=' '  && c.N[wx][wy+1]!=' ' && c.N[wx-1][wy-1]!=' ' && c.N[wx+1][wy]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα μαύρα πιόνια!"<<endl;
		return false;
	}
	if (flag6 && c.N[wx+1][wy+1]!=' ' && c.N[wx+1][wy-1]!=' '  && c.N[wx][wy-1]!=' '  && c.N[wx-1][wy]!=' '  && c.N[wx][wy+1]!=' ' && c.N[wx-1][wy-1]!=' ' && c.N[wx+1][wy]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα μαύρα πιόνια!"<<endl;
		return false;
	}
	if (flag7 && c.N[wx+1][wy+1]!=' ' && c.N[wx+1][wy-1]!=' '  && c.N[wx-1][wy+1]!=' '  && c.N[wx-1][wy]!=' '  && c.N[wx][wy+1]!=' ' && c.N[wx-1][wy-1]!=' ' && c.N[wx+1][wy]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα μαύρα πιόνια!"<<endl;
		return false;
	}
	if (flag8 && c.N[wx+1][wy+1]!=' ' && c.N[wx+1][wy-1]!=' '  && c.N[wx-1][wy+1]!=' '  && c.N[wx-1][wy]!=' '  && c.N[wx][wy+1]!=' ' && c.N[wx][wy-1]!=' ' && c.N[wx+1][wy]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα μαύρα πιόνια!"<<endl;
		return false;
	}
flag1=false;
flag2=false;
flag3=false;
flag4=false;
flag5=false;
flag6=false;
flag7=false;
flag8=false;
	if (c.N[bx+1][by+1]=='Q'    ||     c.N[bx+2][by+2]=='Q'    ||      c.N[bx+3][by+3]=='Q'   ||    c.N[bx+4][by+4]=='Q'  || c.N[bx+1][by+1]=='B'    ||       c.N[bx+2][by+2]=='B'    ||      c.N[bx+3][by+3]=='B'   ||    c.N[bx+4][by+4]=='B')
    {
    	flag1=true;
	}
    if (c.N[bx+1][by]=='Q' || c.N[bx+2][by]=='Q' || c.N[bx+3][by]=='Q' || c.N[bx+4][by]=='Q' || c.N[bx+5][by]=='Q' || c.N[bx+6][by]=='Q' ||  c.N[bx+7][by]=='Q' ||  c.N[bx+1][by]=='R' || c.N[bx+2][by]=='R' || c.N[bx+3][by]=='R' || c.N[bx+4][by]=='R' || c.N[bx+5][by]=='R' || c.N[bx+6][by]=='R' ||  c.N[bx+7][by]=='R')
    {
    	flag2=true;
	}
    if (c.N[bx+1][by-1]=='Q'    ||     c.N[bx+2][by-2]=='Q'    ||      c.N[bx+3][by-3]=='Q'   ||    c.N[bx+4][by-4]=='Q'  || c.N[bx+1][by-1]=='B'    ||       c.N[bx+2][by-2]=='B'    ||      c.N[bx+3][by-3]=='B'   ||    c.N[bx+4][by-4]=='B')
    {
    	flag3=true;
	}
    if (c.N[bx][by+1]=='Q' || c.N[bx][by+2]=='Q' || c.N[bx][by+3]=='Q' || c.N[bx][by+4]=='Q' || c.N[bx][by+5]=='Q' || c.N[bx][by+6]=='Q' ||  c.N[bx][by+7]=='Q' ||  c.N[bx][by+1]=='R' || c.N[bx][by+2]=='R' || c.N[bx][by+3]=='R' || c.N[bx][by+4]=='R' || c.N[bx][by+5]=='R' || c.N[bx][by+6]=='R' ||  c.N[bx][by+7]=='R')
    {
    	flag4=true;
	}
    if (c.N[bx][by-1]=='Q' || c.N[bx][by-2]=='Q' || c.N[bx][by-3]=='Q' || c.N[bx][by-4]=='Q' || c.N[bx][by-5]=='Q' || c.N[bx][by-6]=='Q' ||  c.N[bx][by-7]=='Q' ||  c.N[bx][by-1]=='R' || c.N[bx][by-2]=='R' || c.N[bx][by-3]=='R' || c.N[bx][by-4]=='R' || c.N[bx][by-5]=='R' || c.N[bx][by-6]=='R' ||  c.N[bx][by-7]=='R')
    {
    	flag5=true;
	}
    if(c.N[bx-1][by+1]=='Q'    ||     c.N[bx-2][by+2]=='Q'    ||      c.N[bx-3][by+3]=='Q'   ||    c.N[bx-4][by+4]=='Q'  || c.N[bx-1][by+1]=='B'    ||       c.N[bx-2][by+2]=='B'    ||      c.N[bx-3][by+3]=='B'   ||    c.N[bx-4][by+4]=='B'  || c.N[bx-1][by+1]=='P')
    {
    	flag6=true;
	}
    if (c.N[bx-1][by]=='Q' || c.N[bx-2][by]=='Q' || c.N[bx-3][by]=='Q' || c.N[bx-4][by]=='Q' || c.N[bx-5][by]=='Q' || c.N[bx-6][by]=='Q' ||  c.N[bx-7][by]=='Q' ||  c.N[bx-1][by]=='R' || c.N[bx-2][by]=='R' || c.N[bx-3][by]=='R' || c.N[bx-4][by]=='R' || c.N[bx-5][by]=='R' || c.N[bx-6][by]=='R' ||  c.N[bx-7][by]=='R')
    {
    	flag7=true;
	}
    if (c.N[bx-1][by-1]=='Q'    ||     c.N[bx-2][by-2]=='Q'    ||      c.N[bx-3][by-3]=='Q'   ||    c.N[bx-4][by-4]=='Q'  || c.N[bx-1][by-1]=='B'    ||       c.N[bx-2][by-2]=='B'    ||      c.N[bx-3][by-3]=='B'   ||    c.N[bx-4][by-4]=='B' || c.N[bx-1][by-1]=='P')
    {
    	flag8=true;
	}	
	if(flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8)
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα λευκά πιόνια!"<<endl;
    	return false;
	}
	if (flag1 && c.N[bx+1][by]!=' '  && c.N[bx][by+1]!=' ' && c.N[bx][by-1]!=' '  && c.N[bx-1][by+1]!=' '  && c.N[bx-1][by]!=' ' && c.N[bx-1][by-1]!=' ' && c.N[bx+1][by-1]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα λευκά πιόνια!"<<endl;
		return false;
	}
	if (flag2 && c.N[bx+1][by+1]!=' ' && c.N[bx][by+1]!=' ' && c.N[bx][by-1]!=' '  && c.N[bx-1][by+1]!=' '  && c.N[bx-1][by]!=' ' && c.N[bx-1][by-1]!=' ' && c.N[bx+1][by-1]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα λευκά πιόνια!"<<endl;
		return false;
	}
	if (flag3 && c.N[bx+1][by+1]!=' ' && c.N[bx][by+1]!=' ' && c.N[bx][by-1]!=' '  && c.N[bx-1][by+1]!=' '  && c.N[bx-1][by]!=' ' && c.N[bx-1][by-1]!=' ' && c.N[bx+1][by]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα λευκά πιόνια!"<<endl;
		return false;
	}
	if (flag4 && c.N[bx+1][by+1]!=' ' && c.N[bx+1][by-1]!=' '  && c.N[bx][by-1]!=' '  && c.N[bx-1][by+1]!=' '  && c.N[bx-1][by]!=' ' && c.N[bx-1][by-1]!=' ' && c.N[bx+1][by]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα λευκά πιόνια!"<<endl;
		return false;
	}
	if (flag5 && c.N[bx+1][by+1]!=' ' && c.N[bx+1][by-1]!=' '  && c.N[bx][by-1]!=' '  && c.N[bx-1][by+1]!=' '  && c.N[bx][by+1]!=' ' && c.N[bx-1][by-1]!=' ' && c.N[bx+1][by]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα λευκά πιόνια!"<<endl;
		return false;
	}
	if (flag6 && c.N[bx+1][by+1]!=' ' && c.N[bx+1][by-1]!=' '  && c.N[bx][by-1]!=' '  && c.N[bx-1][by]!=' '  && c.N[bx][by+1]!=' ' && c.N[bx-1][by-1]!=' ' && c.N[bx+1][by]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα λευκά πιόνια!"<<endl;
		return false;
	}
	if (flag7 && c.N[bx+1][by+1]!=' ' && c.N[bx+1][by-1]!=' '  && c.N[bx-1][by+1]!=' '  && c.N[bx-1][by]!=' '  && c.N[bx][by+1]!=' ' && c.N[bx-1][by-1]!=' ' && c.N[bx+1][by]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα λευκά πιόνια!"<<endl;
		return false;
	}
	if (flag8 && c.N[bx+1][by+1]!=' ' && c.N[bx+1][by-1]!=' '  && c.N[bx-1][by+1]!=' '  && c.N[bx-1][by]!=' '  && c.N[bx][by+1]!=' ' && c.N[bx][by-1]!=' ' && c.N[bx+1][by]!=' ')
	{
		cout<<"Ματ: Νίκησε ο παίκτης με τα λευκά πιόνια!"<<endl;
		return false;
	}
 return true;
}
bool pioni::move(board& c)
{
	if (type=='P' || type=='p')
	{
		pawn ap;
		ap=ap=*this;
		ap.makemove(c);
		this->x=ap.x;
		this->y=ap.y;
		return true;
	}
	else if (type=='N' || type=='n')
	{
		knight ak;
		ak=ak=*this;
		ak.makemove(c);
		this->x=ak.x;
		this->y=ak.y;
		return true;
	}
	else if(type=='B' || type=='b')
	{
		bishop ab;
		ab=ab=*this;
		ab.makemove(c);
		this->x=ab.x;
		this->y=ab.y;
		return true;
	}
	else if(type=='Q' || type=='q')
	{
		queen aq;
		aq=aq=*this;
		aq.makemove(c);
		this->x=aq.x;
		this->y=aq.y;
		return true;
	}
	else if(type=='R' || type=='r')
	{
		rook rr;
		rr=rr=*this;
		rr.makemove(c);
		this->x=rr.x;
		this->y=rr.y;
		return true;
	}
	else if(type=='K' || type=='k')
	{
		king kk;
		kk=kk=*this;
		kk.makemove(c);
		this->x=kk.x;
		this->y=kk.y;
		return true;
	}
}
