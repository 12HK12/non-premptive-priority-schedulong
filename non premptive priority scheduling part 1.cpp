#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
	string *process;
	int n;
	cout<<"Enter the no of process : ";
	cin>>n;
	process=new string[n];
	cout<<"Enter the processes : ";
	for(int i=0;i<n;i++)
	{
	cin>>process[i];	
	} 
	float *arrivaltime;
	arrivaltime=new float[n];
	cout<<"Enter their arrival time :";
    for(int i=0;i<n;i++)
    {
    	cin>>arrivaltime[i];
	}
    float *bursttime;
    bursttime=new float[n];
    cout<<"Enter their burst time : ";
    for(int i=0;i<n;i++)
    {
    	cin>>bursttime[i];
	}

	float *priority;
	priority=new float[n];
    for(int i=0;i<n;i++)
    {
    	priority[i]=1+(float)(arrivaltime[i]/bursttime[i]);
	}
			cout<<"Processes"<<"\t\t\t"<<"Arrival Time"<<"\t\t\t"<<"BurstTime";
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		cout<<process[i]<<"\t\t\t\t"<<arrivaltime[i]<<"s"<<"\t\t\t\t"<<bursttime[i]<<"s";
		
	}
}
