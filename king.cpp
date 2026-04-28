#include "king.h"
#include <cmath>

void king::makemove(board& c)
{
	int i,j;
	bool flag=true;
	cout<<"Δώσε τις συντεταγμένες που θες να κινήσεις τον βασιλιά: ";
	cin>>i>>j;
	while(flag)
	{
	  if(this->getkk(c,i,j))
	  {
	  	c.N[this->x][this->y]=' ';
	    if( c.turn=='w')
	    {
		c.N[i-1][j-1]='K';
	    }
	    else
	    {
		c.N[i-1][j-1]='k';                                     
	    }
	    c.katagrafh[this->x][this->y]='1'; // kounithike o basilias
	    this->x=i-1;
	    this->y=j-1;
	    flag=false;
	  }
	  else if(this->roke(c,i,j))
	  {
	  	if(c.turn=='w')
	  	{
	  		if (this->y<(j-1))
	  		{
	  			c.N[this->x][this->y]=' ';
	  			c.N[0][6]='K';
	  			c.N[0][5]='R';
	  			c.N[0][7]=' ';
			}
			else
			{
				c.N[this->x][this->y]=' ';
	  			c.N[0][2]='K';
	  			c.N[0][3]='R';
	  			c.N[0][0]=' ';
			}
		}
		else
		{
			if (this->y<(j-1))
			{
				c.N[this->x][this->y]=' ';
	  			c.N[7][6]='K';
	  			c.N[7][5]='R';
	  			c.N[7][7]=' ';
			}
			else
			{
				c.N[this->x][this->y]=' ';
	  			c.N[7][2]='K';
	  			c.N[7][3]='R';
	  			c.N[7][0]=' ';
			}
		}
	  }
	  else
	  {
	  	cout<<"Ξαναπροσπάθησε:";
	  	cin>>i>>j;
	  }
	}
	system("cls");
	c.ektupwsh();
}


bool king::roke(board& c,int i,int j)//roke
{
	if (this->x==(i-1) && abs(this->y-(j-1))>1 ) // roke
	{
		if (c.turn=='w')  
		{
			if (this->y<(j-1))//deksia kinhsh
			{
				if (c.N[0][5]==' ' && c.N[0][6]==' ' && c.katagrafh[0][7]=='0' && c.katagrafh[this->x][this->y]=='0')
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else // aristerh kinhsh
			{
				if (c.N[0][1]==' ' && c.N[0][2]==' ' && c.N[0][3]==' ' && c.katagrafh[0][0]=='0' && c.katagrafh[this->x][this->y]=='0')
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			 
		}
		else if(c.turn=='b' ) // (c.N[7][0]=='r' || c.N[7][7]=='r')
		{
				if (this->y<(j-1))
				{
					if (c.N[7][6]==' ' && c.N[7][6]==' ' && c.katagrafh[7][7]=='0'&& c.katagrafh[this->x][this->y]=='0')
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
					if (c.N[7][1]==' ' && c.N[7][2]==' ' && c.N[7][3]==' ' && c.katagrafh[7][0]=='0'&& c.katagrafh[this->x][this->y]=='0')
					{
						return true;
					}
					else
					{
						return false;
					}
				}
		}
	}
	else
	{
		return false;
	}
}

bool king::getkk(board& c,int i,int j)
{
	if (abs(this->x-(i-1))==1 && abs(this->y-(j-1))==1 && (  (c.turn=='w' && (c.N[i-1][j-1]>90 || c.N[i-1][j-1]==' ') ) || (c.turn=='b' && (c.N[i-1][j-1]<90 || c.N[i-1][j-1]==' ') )   )   )
	{
		return true;
	}
	else if(this->y==(j-1) && abs(this->x-(i-1))==1 && (  (c.turn=='w' && (c.N[i-1][j-1]>90 || c.N[i-1][j-1]==' ') ) || (c.turn=='b' && (c.N[i-1][j-1]<90 || c.N[i-1][j-1]==' ') )   ))
	{
		return true;
	}
	else if(this->x==(i-1) && abs(this->y-(j-1))==1 && (  (c.turn=='w' && (c.N[i-1][j-1]>90 || c.N[i-1][j-1]==' ') ) || (c.turn=='b' && (c.N[i-1][j-1]<90 || c.N[i-1][j-1]==' ') )   ))
	{
		return true;
	}
	else
	{
		return false;
	}
}


king king::operator=(const pioni& a)
{
	king kk;
	kk.x=a.x;
	kk.y=a.y;
	kk.type=a.type;
	return kk;
}
