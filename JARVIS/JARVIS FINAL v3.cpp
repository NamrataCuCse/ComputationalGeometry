#include<iostream>
#include<cfloat>
#include<cstdlib>
#include<cmath>

using namespace std;

struct Point
{
	int x,y;
};



void print(Point P[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"(" << P[i].x << "," <<P[i].y << ")";
		n-i-1 > 0 ? cout<<", " : cout<<" ";
	}
	cout<< endl;
}
void print1(Point P[],int n)
{
	for(int i=1;i<=n;i++)
	{
		cout<<"(" << P[i].x << "," <<P[i].y << ")";
		n-i-1 > 0 ? cout<<", " : cout<<" ";
	}
	cout<< endl;
}


double degree(Point p0, Point p1, Point p2){

 double a,b,c,deg;
 
	  a = pow(p1.x-p0.x,2) + pow(p1.y-p0.y,2),
      b = pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2),
      c = pow(p2.x-p0.x,2) + pow(p2.y-p0.y,2);
   	  deg=(acos( (a+b-c)/sqrt(4*a*b) ))*180/3.14;
	  return deg;
}


void jarvis_march(Point P[],int n)
{
	Point stack[n],spl,q;
	int top=0;
	stack[top].x =-99;
	stack[top].y =0;
	top=top+1;
	int flag=1;
	
	// There must be at least 3 points 
	if (n < 3) return; 
	
	int ymin = P[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = P[i].y;
     if ((y < ymin) || (ymin == y && P[i].x < P[min].x))
        ymin = P[i].y, min = i;
   } 
	
	
	int p=min,MAX;
	
	stack[top]=spl=P[p];
	cout<<"Initial hull point  -->  ("<<stack[top].x<<","<<stack[top].y<<")"<<endl;
	

	 
	do
	{
	MAX=0;
	cout<<"\n--------------- ITERATION "<<top<<"--------------"<<endl;
	top=top+1;
	
	
	for(int i=0;i<n;i++)
	 {  
	 	cout<<"Point ("<<P[i].x<<","<<P[i].y<<")  -> Angle = "<<degree(stack[top-2],stack[top-1],P[i])<<endl;
		 	
	 	if(degree(stack[top-2],stack[top-1],P[i]) > MAX)
	 	{
	 		MAX = degree(stack[top-2],stack[top-1],P[i]);
	 	    stack[top]=P[i];
		} 
		
	}
	
	
	if(stack[top].x==spl.x && stack[top].y==spl.y)
	{
		flag=0;
	}


	cout<<"\n \nNext point on hull ("<<stack[top].x<<","<<stack[top].y<<") "<<endl;

	}while(flag);
	
	cout<<"\n\n=> CONVEX HULL :: ";
	print1(stack,top-1);
}




int main()
{
int n;
	Point points[100];
 	cout<<"Enter the number of points :: ";
 	cin>>n;
 	
 	cout<<"\n\nEnter the points ::"<<endl;
	for(int i=0;i<n;i++)
	{	cout<<"Enter X and Y-coordinate of Point("<<i+1<<") ::";
		cin>>points[i].x;
		cin>>points[i].y;
	}
	
	cout<<"\n\n=> Given points are :: ";
	print(points,n);
	
	jarvis_march(points,n);
   	
	return 0;
}
