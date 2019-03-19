#include<iostream>
using namespace std;
int main()
{   int number;
	cout<<"enter no. of processes\n";
	cin>>number;
	int ArrivalTime[number],ExecutionTime[number];
	cout<<"enter arrival time for processes\n";
	for(int i=0;i<=number-1;i++)
	{
			cin>>ArrivalTime[i];
	}
	cout<<"enter execution time for processes\n";
	for(int i=0;i<=number-1;i++)
	{
			cin>>ExecutionTime[i];
	}
	int CompletionTime[number],TAT[number],WT[number];// WT = Waiting Time , TAT = Turn Around Time
	for(int i=0;i<=number-1;i++)
	{   
	    if(i==0)
		CompletionTime[i]=ExecutionTime[i]-ArrivalTime[i];
		else if(CompletionTime[i-1]>ArrivalTime[i])
		CompletionTime[i]=CompletionTime[i-1]+ExecutionTime[i];
		else
		CompletionTime[i]=ArrivalTime[i]+ExecutionTime[i];
		TAT[i]=CompletionTime[i]-ArrivalTime[i];
		WT[i]=TAT[i]-ExecutionTime[i];
	}
	for(int i=0;i<=number-1;i++)
	{
		cout<<"CT["<<i<<"]="<<CompletionTime[i]<<"\n";
		cout<<"TAT["<<i<<"]="<<TAT[i]<<"\n";
		cout<<"WT["<<i<<"]="<<WT[i]<<"\n";
		
	}
}
