#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;
void bubble(int a[10000]){
    int swap = 0;
    int start,finish;
    start=(int) clock();
    for(int i=0;i<10000;i++)
    {
        for(int j=i+1;j<10000;j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                swap++;
            }
        }
    }
    finish=(int)clock();
    int time=finish-start;
    cout<<"冒泡排序所用时间："<<time<<endl;
    cout<<"冒泡排序交换次数："<<swap<<endl;
}
void select(int a[10000]){
    int swap =0;
    int start,finish;
    start=(int) clock();
    for(int i=0; i<10000; i++)
    {
        int k=i;
        for(int j=i+1; j<10000; j++)
        {
            if(a[j]<a[k])
                k=j;
        }
        if(k!=i)
        {
            int temp=a[k];
            a[k]=a[i];
            a[i]=temp;
            swap++;
        }
    }
    finish=(int)clock();
    int time=finish-start;
    cout<<"选择排序所用时间："<<time<<endl;
    cout<<"选择排序交换次数："<<swap<<endl;
}
void insert(int a[10000]){
    int swap =0;
    int start,finish;
    start=(int) clock();
    for(int i= 1; i<10000; i++){
        if(a[i] < a[i-1]){
            int j= i-1;
            int x = a[i];
            a[i] = a[i-1];
            while(x < a[j]){
                a[j+1] = a[j];
                j--;
                swap++;
                if (j<=0)
                    break;
            }
            a[j+1] = x;
            swap++;
        }
    }
    finish=(int)clock();
    int time=finish-start;
    cout<<"直接插入排序所用时间："<<time<<endl;
    cout<<"直接插入排序交换次数："<<swap<<endl;
}
void shell(int a[10000]){
    int swap =0;
    int start,finish;
    start=(int) clock();
    for(int gap = 3; gap >0; gap--)
    {
        for(int i=0; i<gap; i++)
        {
            for(int j = i+gap; j<10000; j=j+gap)
            {
                if(a[j]<a[j-gap])
                {
                    int temp = a[j];
                    int k = j-gap;
                    while(k>=0&&a[k]>temp)
                    {
                        a[k+gap] = a[k];
                        k = k-gap;
                        swap++;
                    }
                    a[k+gap] = temp;
                    swap++;
                }
            }
        }
    }
    finish=(int)clock();
    int time=finish-start;
    cout<<"希尔排序所用时间："<<time<<endl;
    cout<<"希尔排序交换次数："<<swap<<endl;
}
void quickSort(int a[], int l, int r, int &s)
{
    if (l< r)
    {
        int i = l, j = r, x = a[l];
        while (i < j)
        {
            while(i < j && a[j]>= x)
                j--;
            if(i < j){
                a[i++] = a[j];
                s++;
            }
            while(i < j && a[i]< x)
                i++;
            if(i < j){
                a[j--] = a[i];
                s++;
            }
        }
        a[i] = x;
        quickSort(a, l, i - 1, s);
        quickSort(a, i + 1, r, s);
    }
}
void quick(int a[10000]){
    int swap =0;
    int start,finish;
    start=(int) clock();
    quickSort(a,0,9999,swap);
    finish=(int)clock();
    int time=finish-start;
    cout<<"选择排序所用时间："<<time<<endl;
    cout<<"选择排序交换次数："<<swap<<endl;
}
void heapSort(int a[], int i, int n, int &s){
    int temp = a[i];
    int j = 2*i;
    while (j <= n)
    {
        if (j < n&&a[j] < a[j + 1])
            j++;
        if (temp>a[j])
            break;
        a[j / 2] = a[j];
        j = j * 2;
        s++;
    }
    a[j / 2] = temp;
    s++;
}
void heap(int a[10000]){
    int swap =0;
    int start,finish;
    start=(int) clock();
    for (int i = 5000; i > 0; i--)
        heapSort(a, i, 10000,swap);
    for (int j = 1000; j > 0; j--)
    {
        int temp = a[j];
        a[j] = a[1];
        a[1] = temp;
        heapSort(a, 1, j - 1,swap);
    }
    finish=(int)clock();
    int time=finish-start;
    cout<<"堆排序所用时间："<<time<<endl;
    cout<<"堆排序交换次数："<<swap<<endl;
}
void mergesort(int a[], int first, int last, int temp[],int &s)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergesort(a, first, mid, temp, s);
        mergesort(a, mid + 1, last, temp, s);
        int i = first, j = mid + 1;
        int m = mid,   n = last;
        int k = 0;
        while (i <= m && j <= n)
        {
            if (a[i] <= a[j]){
                temp[k++] = a[i++];
                s++;
            }
            else{
                temp[k++] = a[j++];
                s++;
            }
        }
        while (i <= m){
            temp[k++] = a[i++];
            s++;
        }
        while (j <= n){
            temp[k++] = a[j++];
            s++;
        }
        for (i = 0; i < k; i++){
            a[first + i] = temp[i];
            s++;
        }
    }
}
void merge(int a[10000]){
    int swap =0;
    int start,finish;
    start=(int) clock();
    int *p = new int[10000];
    mergesort(a, 0, 9999, p,swap);
    finish=(int)clock();
    int time=finish-start;
    cout<<"归并排序所用时间："<<time<<endl;
    cout<<"归并排序交换次数："<<swap<<endl;
}
void radix(int a[10000]){
    int swap =0;
    int start,finish;
    start=(int) clock();
    int d = 1;
    int p = 10;
    for(int i = 0; i < 10000; ++i)
    {
        while(a[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    int temp[10000];
    int count[10];
    int k;
    int radix = 1;
    for(int i = 1; i <= d; i++)
    {
        for(int j = 0; j < 10; j++)
            count[j] = 0;
        for(int j = 0; j < 10000; j++)
        {
            k = (a[j] / radix) % 10;
            count[k]++;
        }
        for(int j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j];
        for(int j = 9999; j >= 0; j--)
        {
            k = (a[j] / radix) % 10;
            temp[count[k] - 1] = a[j];
            swap++;
            count[k]--;
        }
        for(int j = 0; j < 10000; j++)
            a[j] = temp[j];
            swap++;
            radix = radix * 10;
    }
    finish=(int)clock();
    int time=finish-start;
    cout<<"选择排序所用时间："<<time<<endl;
    cout<<"选择排序交换次数："<<swap<<endl;
}
int main(){
cout<<"**         排序算法比较           **"<<endl;
cout<<"=================================="<<endl;
cout<<"**         1-----冒泡排序        **"<<endl;
cout<<"**         2-----选择排序        **"<<endl;
cout<<"**         3-----直接插入排序     **"<<endl;
cout<<"**         4-----希尔排序        **"<<endl;
cout<<"**         5-----快速排序        **"<<endl;
cout<<"**         6-----堆排序          **"<<endl;
cout<<"**         7-----归并排序        **"<<endl;
cout<<"**         8-----基数排序        **"<<endl;
cout<<"**         9-----退出程序        **"<<endl;
cout<<"=================================="<<endl;
cout<<"请输入要产生的随机数的个数："<<endl;
    int i,N;
    int a[10000];
operate1:
    cin >> N;
    if(N>10000||N<=0)
    {
        cout<<"您输入的N不符合要求，请重新输入："<<endl;
        goto operate1;
    }
    srand((unsigned)time(NULL));
    for(i = 0; i < 10000; ++i)
        a[i] = rand() % 10000;
operate:
    cout<<"请选择排序算法："<<endl;
    char ch;
    cin >> ch;
    switch(ch) {
        case '1':
            bubble(a);
            break;
        case '2':
            select(a);
            break;
        case '3':
            insert(a);
            break;
        case '4':
            shell(a);
            break;
        case '5':
            quick(a);
            break;
        case '6':
            heap(a);
            break;
        case '7':
            merge(a);
            break;
        case '8':
            radix(a);
            break;
        case '9':
            break;
        default: cout << "您输入的序号有误，请重新输入！" <<endl;
    }
    goto operate;
}

