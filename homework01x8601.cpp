#include <iostream>
#include<windows.h>
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
    LARGE_INTEGER startTime;
    LARGE_INTEGER endTime;
    LARGE_INTEGER frequency;
    QueryPerformanceFrequency(&frequency);
    double quadpart = (double)frequency.QuadPart;
    while(counter<20)
    {
    QueryPerformanceCounter(&startTime);
    for(int i=0;i<n;i++)
    {
        sum[i] = 0.0;
        for(int j=0;j<n;j++)
            sum[i] += b[j][i] * a[j];
    }
    QueryPerformanceCounter(&endTime);
    totaltime += (endTime.QuadPart - startTime.QuadPart)/quadpart;
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
