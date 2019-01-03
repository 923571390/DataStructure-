#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdio.h>
using namespace std;
struct frequency
{
    char word[20];
    int times;
};
struct wordlist{
    frequency *elem;
    int length;
};
void add(wordlist *sq, frequency *et, char *word) {
    int i;
    for (int i = 0; i < sq->length; i++)
    {
        if (strcmp(et[i].word, word) == 0)
        {
            et[i].times++;
        }
        if (strcmp(et[i].word, word) > 0)
            
        {
            break;
        }
    }
    if (sq->length == 500)
    {          cout<<"空间不足，单词"<<word<<"插入失败"<<endl;
    }
    for (int j = sq->length; j > i; j--)
    {
        memcpy(et+j, et+j-1, sizeof(frequency));
    }
    sq->length++;
    strcpy(et[i].word, word);
    et[i].times = 1;
}
int wordprint(wordlist *sq, frequency *et)
{
    int i, j = 0;
    for(i=0;i<sq->length;i++)
        j=j+et[i].times;
    return j;
}
void create()
{
    frequency w;
    wordlist s;
    char filename[20];
    char yon; 
    cout << "输入要建立的文件名："<<endl;
    cin >> filename;
    ofstream myfile;
    myfile.open(filename, std::ios::out | std::ios::app);
    while(yon!='y'&&yon!='Y')
    {
        cout<<"请输入一行文本："<<endl;
        string ch;
        if(!myfile.eof())
        {
            getline(cin,ch,'\n');
            cin>>ch;
            myfile << ch << endl;
        }
        cout<<"结束输入吗?y or n"<<endl;
        cin>>yon;
    }
    myfile.close();
    cout<<"建立文件结束!"<<endl;
}
void gather()
{
    char filename[20];
    char word[20];
    ifstream ifile;
    FILE *fp;
    int i;
    int j,q=0;
    int w,x,y=0;
    frequency et[500];
    wordlist sq;
    sq.elem = et;
    sq.length = 0;
    cout<<"请输入文件名："<<endl;
    cin>>filename;
    ifile.open( "filename" );
    while(!feof(fp))
    {
        add(&sq, et, word);
    }
    fclose(fp);
    cout<<"==================单词个数=================="<<endl;
    for (i = 0; i < sq.length; i++)
    {
        x=sizeof(et[i].word);
        for(w=x-1;w>=0;w--)
            if(et[i].word[w]<65||(et[i].word[w]>90&&et[i].word[w]<97)||et[i].word[w]>122)
            {
                et[i].word[w]=' ';
            }
        for(w=0;w<x;w++)
            if (et[i].word[w]==' ')
                y++;
        if(y==x)
        {
            et[i].times=0;
            y=0;
        }
        else y=0;
        if(et[i].times!=0)
            cout << et[i].word << et[i].times;
        else q++;
    }
    j=wordprint(&sq, et);
    cout<<"=================="<<filename<<"的单词总数为"<<j<<"个"<<endl;
    cout<<"=================="<<filename<<"的非单词个数为"<<q<<"种"<<endl;
}
int position (string s1,string s2,int k) 
{
    int i=k-1;  
    int j=0; 
    while(i<s1.length() && j<s2.length())
    {
        if(s1[i]==s2[j])
        {
            i++;
			j++;  
        }    else
        {
            i=i-j+1; 
			j=0;
        }
    }
    if (j>=s2.length()) return i-s2.length();
    else return -1; 
}
void timescount() 
{
    string s,t; 
    char fname[10];
    int times=0;
    cout<<"输入文本文件名："<<endl;
    cin>>fname;
    cout<<"输入要统计计数的单词："<<endl;
    cin>>t;
    ifstream infile("fname");
    while(infile>>s)
    {
        if(s==t) ++times;
    }
    ofstream outfile;
    outfile.open("fname");
    outfile<<times;
    cout<<"单词"<<t<<"在文本文件"<<fname<<"中共出现"<<times<<"次"<<endl;
}
void information() 
{
    FILE *fp;
    string s,t; 
    char filename[20];
    int word[20]; 
    cout<<"输入文本文件名："<<endl;
    cin>>filename;
    fp=fopen(filename,"r");
    cout<<"输入要检索的单词："<<endl;
    cin>>t;
    int l=0;
    while(!feof(fp))
    {
        l++;
        int k=0;
        int i=0;
        while(k<s.length()-1)  
        {
            int j=position(s,t,k);
            if(j<0) break;
            else
            {
                i++; 
				word[i]=j;
                k=j+t.length(); 
            }
        }
        if(i>0)
        {
            cout<<"行号："<<l<<"次数："<<i<<"起始位置分别为：";
            for(int m=1;m<=i;m++)
                cout<<"第"<<word[m]+1<<"个字符";
        }
        cout<<endl;
    }
}
void location()
{
    cout<<"**  文本文件单词字串的定位统计及定位  **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"**                              **"<<endl;
    cout<<"**         a-----单词出现次数     **"<<endl;
    cout<<"**                              **"<<endl;
    cout<<"**         b-----单词出现位置     **"<<endl;
    cout<<"**                              **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"请输入a或b："<<endl;
    char ch;
    cin>>ch;
    switch(ch){
        case 'a':
            timescount();
            break;
        case 'b':
            information();
            break;
        default: cout << "请输入正确的操作！" <<endl;
    }
}
int main()
{
    cout<<"**     文本文件单词的检索与计数     **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"**         请选择要执行的操作      **"<<endl;
    cout<<"**         1-----建立文本文档     **"<<endl;
    cout<<"**         2-----文本单词汇总     **"<<endl;
    cout<<"**         3-----单词定位        **"<<endl;
    cout<<"**         4-----退出程序        **"<<endl;
    cout<<"=================================="<<endl;
operate:
    cout<<"请选择要执行的操作："<<endl;
    char ch;
    cin>>ch;
    switch(ch) {
        case '1':
            create();
            break;
        case '2':
            gather();
            break;
        case '3':
            location();
            break;
        case '4':
            break;
        default: cout << "请输入正确的操作！" <<endl;
    }
    goto operate;
}


