#include "knight.h"
#include <cmath>
void knight::makemove(board& c)
{
	int i=-1,j=-1;
	this->getk(c,i,j);
	c.N[this->x][this->y]=' ';
	if( c.turn=='w')
	{
		c.N[i-1][j-1]='N';
	}
	else
	{
		c.N[i-1][j-1]='n';                                     
	}
	this->x=i-1;
	this->y=j-1;
	system("cls");
	c.ektupwsh();
}

void knight::getk(board& c,int& i,int& j)
{
 bool flag;
 bool k=0;
 cout<<"Δώσε τις συντεταγμένες που θες να κινήσεις τον ίππο: "<<endl;
 do
 {
 	if (k)
 	{
 		cout<<"Ξαναπροσπάθησε: ";
	}
	k=1;
	cin>>i>>j;
	i--;
	j--;
	if( ( abs(abs(this->x-this->y)-abs(i+j))==-1 || abs(abs(this->x-this->y)-abs(i+j))==3 || abs(abs(this->x-this->y)-abs(i+j))==1 || abs(abs(this->x-this->y)-abs(i+j))==-3))
	{
		flag=false;
	}
	else
	{
		flag=true;
	}
	i++;
	j++;
 }
 while( flag|| this->checknight(c,i,j));
}

bool knight::checknight(board& c,int i,int j)
{
	if(c.N[i-1][j-1]==' ')
	{
		return false;
	}
	if(c.turn=='w')
	{
		if (c.N[i-1][j-1]<90)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (c.N[i-1][j-1]>90)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

knight knight::operator=(const pioni& a)
{
	knight p;
	p.x=a.x;
	p.y=a.y;
	p.type=a.type;
	return p;
}
