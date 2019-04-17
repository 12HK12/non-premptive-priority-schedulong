#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int findSmallestElement(float arr[], int n){ 
   float temp = arr[0];
   int index=0;
   for(int i=0; i<n; i++) {
      if(temp>arr[i]) {
         temp=arr[i];
         index=i;
      }
   }
   return index;
}
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
	cout<<"The process table is : ";
	cout<<"\n";
			cout<<"Processes"<<"\t\t\t"<<"Arrival Time"<<"\t\t\t"<<"BurstTime";
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		cout<<process[i]<<"\t\t\t\t"<<arrivaltime[i]<<"s"<<"\t\t\t\t"<<bursttime[i]<<"s";
		
	}
	float *wt;
	wt=new float[n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(priority[j]>priority[j+1])
			{
				swap(process[j],process[j+1]);
				swap(arrivaltime[j],arrivaltime[j+1]);
				swap(bursttime[j],bursttime[j+1]);
				swap(priority[j],priority[j+1]);
			}
		}
	}
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"The processes according to their priority ";
		cout<<"\n";
		cout<<"\n";
     cout<<"Processes"<<"\t\t\t"<<"Arrival Time"<<"\t\t\t"<<"BurstTime"<<"\t\t\t"<<"priority";
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		cout<<process[i]<<"\t\t\t\t"<<arrivaltime[i]<<"s"<<"\t\t\t\t"<<bursttime[i]<<"s"<<"\t\t\t\t"<<priority[i];
		
	}
	cout<<"\n";
   
     	cout<<"\n";
     	
     		for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(priority[j]<priority[j+1] && arrivaltime[j]>arrivaltime[j+1])
			{
				swap(process[j],process[j+1]);
				swap(arrivaltime[j],arrivaltime[j+1]);
				swap(bursttime[j],bursttime[j+1]);
				swap(priority[j],priority[j+1]);
			   
			}
		}
	}
		cout<<"\n";
		cout<<"\n";
		cout<<"The process table according to their priority and arrival time : ";
		cout<<"\n";
		cout<<"\n";
     cout<<"Processes"<<"\t\t\t"<<"Arrival Time"<<"\t\t\t"<<"BurstTime"<<"\t\t\t"<<"priority";
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		cout<<process[i]<<"\t\t\t\t"<<arrivaltime[i]<<"s"<<"\t\t\t\t"<<bursttime[i]<<"s"<<"\t\t\t\t"<<priority[i];
		
	}
	   		for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(priority[j]<priority[j+1] && arrivaltime[j]==arrivaltime[j+1])
			{
				swap(process[j],process[j+1]);
				swap(arrivaltime[j],arrivaltime[j+1]);
				swap(bursttime[j],bursttime[j+1]);
				swap(priority[j],priority[j+1]);
			   
			}
		}
	}
			cout<<"\n";
		cout<<"\n";
		cout<<"The final table of the processes to execute : ";
		cout<<"\n";
		cout<<"\n";
     cout<<"Processes"<<"\t\t\t"<<"Arrival Time"<<"\t\t\t"<<"BurstTime"<<"\t\t\t"<<"priority";
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		cout<<process[i]<<"\t\t\t\t"<<arrivaltime[i]<<"s"<<"\t\t\t\t"<<bursttime[i]<<"s"<<"\t\t\t\t"<<priority[i];
		
	}
    float *ct;
    ct=new float[n];
    ct[0]=arrivaltime[0]+bursttime[0];
    for(int i=1;i<n;i++)
	{
		ct[i]=ct[i-1]+bursttime[i];
    	
	}
    float *turnaroundtime;
    turnaroundtime=new float[n];
    for(int i=0;i<n;i++)
    {
    	turnaroundtime[i]=ct[i]-arrivaltime[i];
	}
	
		float averageturnaroundtime;
		float sum1=0.0f;
		for(int i=0;i<n;i++)
		{
		sum1=sum1+turnaroundtime[i];	
		}
		
		averageturnaroundtime=(float)sum1/n;
		cout<<"\n";
		
	    float *waitingtime;
	    waitingtime=new float[5];
	    for(int i=0;i<n;i++)
	    {
	    	waitingtime[i]=turnaroundtime[i]-bursttime[i];
		}
		
			float averagewaitingtime;
		float sum2=0.0f;
		for(int i=0;i<n;i++)
		{
		sum2=sum2+waitingtime[i];	
		}
		
		averagewaitingtime=(float)sum2/n;
		cout<<"\n";

		cout<<"\n";
		cout<<"waitingtime"<<"\t\t\t\t"<<"turnaroundtime";
		cout<<"\n";
	for(int i=0;i<n;i++)
	{
	cout<<waitingtime[i]<<"s"<<"\t\t\t\t\t"<<turnaroundtime[i]<<"s";
	cout<<"\n";	
	}
		cout<<"\n";
			cout<<"\n";
			
    cout<<"Average waiting time and Average turn Around time are : ";
    cout<<"\n";
	cout<<"Average waiting time : "<<averagewaitingtime<<"s";
	cout<<"\n";
	cout<<"Average Turn around time : "<<averageturnaroundtime<<"s"; 
	    
    
}
