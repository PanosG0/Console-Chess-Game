#include "queen.h"
#include <cmath>
void queen::makemove(board& c)
{
	int i,j;
	bool flag=true;
	cout<<"Δώσε τις συντεταγμένες που θες να κινήσεις την βασίλισσα: ";
	cin>>i>>j;
	while(flag)
	{
	  if(this->getq(c,i,j) || this->getq2(c,i,j))
	  {
	  	c.N[this->x][this->y]=' ';
	    if( c.turn=='w')
	    {
		c.N[i-1][j-1]='Q';
	    }
	    else
	    {
		c.N[i-1][j-1]='q';                                     
	    }
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

bool queen::getq(board& c,int i,int j) // apomenoun ta orizontia(ta katheta sxetika komple)
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

bool queen::getq2(board&c,int i,int j)// douleuei gia diagwnious
{
  if(abs(this->x-this->y)==abs(i-j))
  {
	if (c.N[i-1][j-1]==' ' && c.N[this->x+1][this->y+1]==' ' && (j>this->y+1) )
	{
		return false;
	}
	if  (c.N[i-1][j-1]==' ' &&  c.N[this->x+1][this->y-1]==' ' && (j<this->y+1))
	{
		return false;
	}
	if (c.N[i-1][j-1]==' ' &&   c.N[this->x-1][this->y-1]==' '  && (j<this->y+1))
	{
		return false;
	}
	if(c.N[i-1][j-1]==' ' &&   c.N[this->x-1][this->y+1]==' '  && (j>this->y+1))
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
			
			if (c.N[this->x+1][this->y+1]==' ' && (j>this->y+1))
	            {
		           return false;
	            }
	        if  (c.N[this->x+1][this->y-1]==' ' && (j<this->y+1))
	            {
		           return false;
	            }
	        if (c.N[this->x-1][this->y-1]==' '  && (j<this->y+1))
	           {
	           	 return false;
			   }
			if (c.N[this->x-1][this->y+1]==' '  && (j>this->y+1))
			  {
			  	return false;
			  }
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
			if (c.N[this->x+1][this->y+1]==' ' && (j>this->y+1))
	            {
		           return false;
	            }
	        if  (c.N[this->x+1][this->y-1]==' ' && (j<this->y+1))
	            {
		           return false;
	            }
			if (c.N[this->x-1][this->y-1]==' '  && (j<this->y+1))
	           {
	           	 return false;
			   }
			if (c.N[this->x-1][this->y+1]==' '  && (j>this->y+1))
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

queen queen::operator=(const pioni& a)
{
	queen p;
	p.x=a.x;
	p.y=a.y;
	p.type=a.type;
	return p;
}
