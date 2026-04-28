#include "rook.h"

void rook::makemove(board& c)
{
	int i,j;
	bool flag=true;
	cout<<"Δώσε τις συντεταγμένες που θες να κινήσεις τον πύργο: ";
	cin>>i>>j;
	while(flag)
	{
	  if(this->getr(c,i,j))
	  {
	  	c.N[this->x][this->y]=' ';
	    if( c.turn=='w')
	    {
		c.N[i-1][j-1]='R';
	    }
	    else
	    {
		c.N[i-1][j-1]='r';                                     
	    }
	    c.katagrafh[this->x][this->y]='1'; // kounithike
	    this->x=i-1;
	    this->y=j-1;
	    flag=false;
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
bool rook::getr(board& c,int i,int j) // einai h idia me authn pou einai sthn basilissa
{
  int k,l;
   int sum1=0;
   int sum2=0;
   if(c.turn=='w')
   {
   	 if(c.N[i-1][j-1]<90 && c.N[i-1][j-1]!=' ')
   	 {
   	 	return false;
     }
   	   for(k=this->x+1; k<i-1; k++)
       {
   	    
   		 if(c.N[k][this->y]!=' ')
   	       {
   	  	      return false;
	       }
	    }
      
   }
   else
   {
   	   if(c.N[i-1][j-1]>90)
   	   {
   		return false;
	   }
   	   for(k=this->x; k-1>i; k--)
   	   {
   	   	if(c.N[k][this->y]!=' ')
   	       {
   	  	      return false;
	       }
	   }
   }
   for(k=this->y+1; k<j-1; k++)//orizontia deksia
   {
   	if (c.N[this->x][k]!=' ')
   	   {
   	   	 return false;
	   }
   }
   for (k=this->y+1; k-1>j; k--)//orizontia aristera
   {
   	if(c.N[this->x][k]!=' ')
   	{
   		return false;
	}
   }
   return true;
}
rook rook::operator=(const pioni& a)
{
	rook p;
	p.x=a.x;
	p.y=a.y;
	p.type=a.type;
	return p;
}
