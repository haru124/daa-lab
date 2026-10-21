#include<iostream>
#include<algorithm>
using namespace std;

struct jobs{
char id;
int profit;
int deadline;
};

bool compare(jobs a,jobs b)
{    return a.profit>b.profit;
}

int main(){
int n=6; // number of jobs
jobs job[] = { {'A', 200, 5}, {'B', 180, 3}, {'C', 190, 3}, {'D', 300, 2}, {'E', 120, 4}, {'F', 100, 2} };

sort(job,job+n,compare);

int maxd = 0;
for(int i=0;i<n;i++)
{
    if(maxd < job[i].deadline)
        maxd = job[i].deadline;

}

char schedule[maxd] = {'\0'};
int total = 0;

for(int i = 0;i<n;i++){
    for(int j=min(maxd-1,job[i].deadline-1);j>=0;j--)
    {
        if(schedule[j]==0)
           {
               schedule[j] = job[i].id;
               total += job[i].profit;
               break;
           }
    }
}


//display
cout<<"Optimal Job schedule ";
for(int i = 0;i<maxd;i++)
{
    if(schedule[i]!='\0')
        cout<<schedule[i]<<" ";
}
cout<<endl;

//display the max profit
cout<<"Max profit:"<<total<<endl;
return 0;
}


