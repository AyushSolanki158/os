



#include<iostream>
using namespace std;
#define max 10
class round_robin
{
	public:
		int number,t,tq;
		int l=0,bt[max],wt[max],rmbt[max],tat[max]; float avgtat=0,avgwt=0;
		bool done;
		void get()
		{
			cout<<"Enter no. of process\n";
			cin>>number;
			
			
			cout<<"Enter time Quantum\n";
			cin>>tq;			
			
			cout<<"Enter Burst Time of Each Process\n";
			for(int i=0;i<number;i++) 
			{
				cin>>bt[i];
				rmbt[i]=bt[i];
			}
			
			
		}
		
		void calculate()
		{ while(true)
		{   done=true;
			for(int i=0;i<number;i++)
			{
				if(rmbt[i]>0)
				{  done=false;
					if(rmbt[i]>tq)
					{
						t=t+tq;
						rmbt[i]=rmbt[i]-tq;
					}
				
				else
				   {
						t=t+rmbt[i];
						rmbt[i]=0;
						wt[i]=t-bt[i];
						tat[i]=t;					
				    }
			    }
			}
			if(done==true)
			break;
		}
			
			
		}
		
		void avg()
		{
			for(int i=0;i<number;i++)
			{
				avgtat+=tat[i];
			//	cout<<"Avg tat = "<<avgtat<<endl; 
				avgwt+=wt[i];
			//	cout<<"Avg wt = "<<avgwt<<endl;
			}
			
			avgtat=avgtat/number;
			avgwt=avgwt/number;
		}
		
		
		void show()
		{
			cout<<"Wt is   tat is\n";
			for(int i=0;i<number;i++) cout<<"   "<<wt[i]<<"   "<<tat[i]<<endl;
			cout<<"\n\n";
			cout<<"Avg Turn around time is = "<<avgtat<<endl;
			cout<<"Avg Waiting time is ="<<avgwt<<endl;
			
			
		}
	
};

main()
{
	round_robin ayu;
	ayu.get();
	ayu.calculate();
	ayu.avg();
	ayu.show();
}
