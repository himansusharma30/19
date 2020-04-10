#include<iostream>
#include<math.h>
#include<stdio.h> 
using namespace std;
class roundrobin
{
public:
	
void queue(int arr[], int n)
{
	for( int i=0; i<n; i++)
	{arr[i]=-1;}

}
bool check(int r_burst[], int n)
{
	bool robin1 = true;
	int i;
	for( i=0; i<n; i++)
	{
		if(r_burst[i]>0)
		{
			robin1 = false;
		}
	}
	return robin1;
}	
void t(int arr[], int n)
{
	int i;
	for( i=0; i<n; i++)
	{arr[i]=0;}
}
};
int main()
{
	roundrobin r;
	int t_quantum=10,n=6;
	int thread[]={1,2,3,4,5,6};
	int priority[]={40,30,30,35,5,10};
	int arrival[]={0,25,30,60,100,105};
	int burst[]={20,25,25,15,10,10};
	int r_burst[]={20,25,25,15,10,10};
	int tat[n],wt[n],ct[n],temp_ct[n];
	bool robin=false;
    int time=0, j,selected_process=0;
	int temp_ct_count=0;
	int temp[6];
	int max=temp[0];
	r.t(wt,n);
	r.t(tat,n);
	r.t(ct,n);
	r.t(temp_ct,20);
	while(robin != true){
		recheck:
		if(r.check(r_burst, 6))
		{
			robin=true;
			break;
		}
		for(int i=0; i<n; i++)
		{ 
			if(r_burst[i]==0)
			{
			   continue;   
			}
			if(arrival[i] > time)
			{
			    time +=(arrival[i]-time); 
			    break;
			}
			else if(r_burst[i] > t_quantum )
			{
				time += t_quantum;
			    r_burst[i] -= t_quantum;
			
				goto recheck;
			}

			else {
				r_burst[i] = 0;
				time += t_quantum;
				ct[i] = time;
				temp_ct[temp_ct_count] = thread[i];
				temp_ct_count++;
			}
		}
	}

	for(int i=0; i<n; i++){
		tat[i] = ct[i]-arrival[i];
		wt[i] = tat[i]-burst[i];
	}
		cout<<"Process "<<"TAT  "<< "   WT  "<< "    CT\n";
	int sum_wt=0;
	for( int i=0; i<n; i++){
		cout<<thread[i]<<"\t"<< tat[i]<<"\t"<< wt[i]<<"\t"<< ct[i]<<endl;
		sum_wt += wt[i];
	}
    cout<<"\n\n";
	for( int i=0; i<n; i++){
		cout<<"P["<<i+1<<"]: "<<ct[i]<<"--"<<ct[i+1]<<endl;
	}

	for( int i=0; i<6; i++){
		cout<<ct[i]<<endl;
	}
    cout<<"\n\n";
	double CPU_RATE;
	double avg_wt;
	avg_wt = (sum_wt/(double)n);
	CPU_RATE =pow(avg_wt,(double)n) ;
    printf("CPU utilization rate: %.2f\n",CPU_RATE);

}
