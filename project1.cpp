#include<stdio.h>
 
int main()
{
int BurstTime[20];
int p[20];
int WaitingTime[20];
int TurnAroundTime[20];
int TotalProcesses, i, j;
int total=0;
int pos,temp;
    float avg_WaitingTime,avg_TurnAroundTime;
    printf("Enter total number of process:");
    scanf("%d",& TotalProcesses);
    printf("\nEnter Burst Time for each process (BT < 10) :\n");
    for(i=0;i<TotalProcesses;i++)
    {
    	X:
        printf("\np-%d:",i+1);
        scanf("%d",&BurstTime[i]);
        if(BurstTime[i]>=10)
        {
        	printf("\nBurstTime should be less than 10\n");
        	goto X;
        	
		}
        p[i]=i+1;
    }
    
    for(i=0;i<TotalProcesses;i++)
    {
        pos=i;
        for(j=i+1;j<TotalProcesses;j++)
        {
            if(BurstTime[j]<BurstTime[pos])
                pos=j;
        }
 
        temp=BurstTime[i];
        BurstTime[i]=BurstTime[pos];
        BurstTime[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    WaitingTime[0]=0;
    for(i=1;i<TotalProcesses;i++)
    {
        WaitingTime[i]=0;
        for(j=0;j<i;j++)
            WaitingTime[i]+=BurstTime[j];
 
        total+=WaitingTime[i];
    }
 
    avg_WaitingTime=(float)total/TotalProcesses;
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<TotalProcesses;i++)
    {
        TurnAroundTime[i]=BurstTime[i]+WaitingTime[i];
        total+=TurnAroundTime[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],BurstTime[i],WaitingTime[i],TurnAroundTime[i]);
    }
 
    avg_TurnAroundTime=(float)total/TotalProcesses;
    printf("\n\nAverage Waiting Time   =%f",avg_WaitingTime);
    printf("\nAverage Turnaround Time=%f\n",avg_TurnAroundTime);
}

