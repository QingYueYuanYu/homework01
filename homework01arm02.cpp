#include <iostream>
#include<time.h>
using namespace std;

int main()
{
    int step = 10;
    for(int n=10;n<=1000;n+=step)
    {
    int *sum,*a,**b;
    sum = new int[n];
    a = new int[n];
    b = new int*[n];
    for(int i=0;i<n;i++)
        b[i] = new int[n];
    for(int i=0;i<n;i++)
    {
        a[i] = i;
        for(int j=0;j<n;j++)
            b[i][j] = i+j;
    }
    double totaltime = 0;
    int counter = 0;
    timespec startTime;
    timespec endTime;
    while(counter<=20)
    {
    clock_gettime(CLOCK_MONOTONIC,&startTime);
    for(int i=0;i<n;i++)
        sum[i] = 0.0;
    for(int j=0;j<n;j++)
    {
        for(int i=0;i<n;i++)
        sum[i] += b[j][i] * a[j];
    }
    clock_gettime(CLOCK_MONOTONIC,&endTime);
    totaltime += ((endTime.tv_sec - startTime.tv_sec) * 10^9 + endTime.tv_nsec - startTime.tv_nsec)/1000000000.0;
    counter ++;
    }
    cout<<"n:"<<n<<" "<<"avgtime:"<<totaltime/counter<<"s"<<endl;
    if(n==100)
        step = 100;
    delete[]sum;
    delete[]a;
    for(int i=0;i<n;i++)
        delete[]b[i];
    delete[]b;
    }
    return 0;
}
