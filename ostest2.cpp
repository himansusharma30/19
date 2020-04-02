#include<iostream>
using namespace std;
int main()
{
	int student[10],gifts[10],temp;
	for(int i=0;i<10;i++)
	{
		cout<<i+1<<":"<<endl;
		cout<<"no.of gifts:";
		cin>>gifts[i];
		student[i]=i+1;
	}
    //sorting according to gifts 
     for(int i=0;i<10;i++)
    {
        for(int j=0;j<10-i-1;j++)
        {
            	if(gifts[j]<gifts[j+1])
            	{
				    temp=gifts[j];
                    gifts[j]=gifts[j+1];
                    gifts[j+1]=temp;
                    
                    temp=student[j];
                    student[j]=student[j+1];
                    student[j+1]=temp;
				}
		}
    }
    cout<<"student "<<"     gifts "<<endl;
    for(int i=0;i<10;i++)
    {
    	cout<<student[i]<<"\t\t"<<gifts[i]<<endl;
	}
	cout<<"The order of billing of student is:\t";
	for(int k=0;k<10;k++)
	{
	cout<<student[k]<<"\t";
	}
}
