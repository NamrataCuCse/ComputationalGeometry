
#include<iostream>
#include<cfloat>
#include<cstdlib>
#include<cmath>
using namespace std;


/*Point Declaration */
struct Point
{
	int x,y;
};

/* sort array of points according to X-coordinate */
int compareX(const void*a,const void*b)
{
	Point*p1=(Point*)a,*p2=(Point*)b;
	if (p1->x == p2->x)
		return(p1->y-p2->y);
	else
		return(p1->x-p2->x);
}


int orientation(Point p, Point q, Point r)
{
 	int val= (q.x*r.y -r.x*q.y)-(p.x*(r.y-q.y)) + (p.y*(r.x-q.x));
    return (val <= 0) ? 0 : 1; //[0=right turn] [1=left turn]
}



void print(Point P[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"(" << P[i].x << "," <<P[i].y << ")";
		n-i-1 > 0 ? cout<<", " : cout<<" ";
	}
	cout<< endl;
}





float GRAHAM_SCAN(Point Px[],int n)
{
	//cout<<n;
	Point Pupper[n],Plower[n],aux[n];
	int uindex,lindex;
	int i,top=0,k=0;
	Pupper[top++]=Px[0];
	Pupper[top]=Px[1];
//	cout<<"\n\n=> Initial points on Upper hull are:: ";
//	print(Pupper,top+1);
	
	for(i=2;i<n;i++)
	 {  
	 	while(top>=1 &&  (orientation(Px[i],Pupper[top], Pupper[top-1])==0))
	 	{          
          top=top-1;
	 	}
	 	Pupper[++top]=Px[i];
     }
     
     cout<<"\n\n=>Points on Upper hull are:: ";
	 print(Pupper,top+1);
	 uindex=top+1;
	 top=0;
	 Plower[top++]=Px[n-1];
	 Plower[top]=Px[n-2];
	 
//	 cout<<"\n\n=> Initial points on Upper hull are:: ";
	print(Plower,top+1);
	 
	 for(i=2;i<n;i++)
	 { 	
			while(top>=1 &&  (orientation(Px[n-i-1],Plower[top], Plower[top-1])==0))
	 	{          
          top=top-1;
	 	}
	 	Plower[++top]=Px[n-i-1];
     }
     
     cout<<"\n\n=>Points on Lower hull are:: ";
	 print(Plower,top+1);
	 lindex=top+1;
	 	 
	 for(i=0;i<uindex;i++)
	 {
	 	aux[k++]=Pupper[i];
	 }

	 for(i=1;i<lindex-1;i++)
	 {
	 	aux[k++]=Plower[i];
	 }	 
	 
	 cout<<"\n\n=> Given points on Convex hull are:: ";
	 print(aux,k);

}


void SORT_X_AXIS(Point P[],int n)
{
	Point Px[n];
	Point Py[n];
	for(int i=0;i<n;i++)
		{
			Px[i]=P[i];
			Py[i]=P[i];
		}
		qsort(Px,n,sizeof(Point),compareX); //inbuilt function qsort, return sorted value of Px 
		cout<<"\n\n=> Given points sorted by X-axis are :: "<<endl;
		print(Px,n);
		GRAHAM_SCAN(Px,n);
}



/* Main */
int main()
{
	int n;
	Point P[100];
 	cout<<"Enter the number of points :: ";
 	cin>>n;
 	
 	cout<<"\n\nEnter the points ::"<<endl;
	for(int i=0;i<n;i++)
	{	cout<<"Enter X and Y-coordinate of Point("<<i+1<<") ::";
		cin>>P[i].x;
		cin>>P[i].y;
	}
	
	cout<<"\n\n=> Given points are :: ";
	print(P,n);
	SORT_X_AXIS(P,n);
	return 0;
}
