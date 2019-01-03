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
    {          cout<<"�ռ䲻�㣬����"<<word<<"����ʧ��"<<endl;
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
    cout << "����Ҫ�������ļ�����"<<endl;
    cin >> filename;
    ofstream myfile;
    myfile.open(filename, std::ios::out | std::ios::app);
    while(yon!='y'&&yon!='Y')
    {
        cout<<"������һ���ı���"<<endl;
        string ch;
        if(!myfile.eof())
        {
            getline(cin,ch,'\n');
            cin>>ch;
            myfile << ch << endl;
        }
        cout<<"����������?y or n"<<endl;
        cin>>yon;
    }
    myfile.close();
    cout<<"�����ļ�����!"<<endl;
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
    cout<<"�������ļ�����"<<endl;
    cin>>filename;
    ifile.open( "filename" );
    while(!feof(fp))
    {
        add(&sq, et, word);
    }
    fclose(fp);
    cout<<"==================���ʸ���=================="<<endl;
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
    cout<<"=================="<<filename<<"�ĵ�������Ϊ"<<j<<"��"<<endl;
    cout<<"=================="<<filename<<"�ķǵ��ʸ���Ϊ"<<q<<"��"<<endl;
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
    cout<<"�����ı��ļ�����"<<endl;
    cin>>fname;
    cout<<"����Ҫͳ�Ƽ����ĵ��ʣ�"<<endl;
    cin>>t;
    ifstream infile("fname");
    while(infile>>s)
    {
        if(s==t) ++times;
    }
    ofstream outfile;
    outfile.open("fname");
    outfile<<times;
    cout<<"����"<<t<<"���ı��ļ�"<<fname<<"�й�����"<<times<<"��"<<endl;
}
void information() 
{
    FILE *fp;
    string s,t; 
    char filename[20];
    int word[20]; 
    cout<<"�����ı��ļ�����"<<endl;
    cin>>filename;
    fp=fopen(filename,"r");
    cout<<"����Ҫ�����ĵ��ʣ�"<<endl;
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
            cout<<"�кţ�"<<l<<"������"<<i<<"��ʼλ�÷ֱ�Ϊ��";
            for(int m=1;m<=i;m++)
                cout<<"��"<<word[m]+1<<"���ַ�";
        }
        cout<<endl;
    }
}
void location()
{
    cout<<"**  �ı��ļ������ִ��Ķ�λͳ�Ƽ���λ  **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"**                              **"<<endl;
    cout<<"**         a-----���ʳ��ִ���     **"<<endl;
    cout<<"**                              **"<<endl;
    cout<<"**         b-----���ʳ���λ��     **"<<endl;
    cout<<"**                              **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"������a��b��"<<endl;
    char ch;
    cin>>ch;
    switch(ch){
        case 'a':
            timescount();
            break;
        case 'b':
            information();
            break;
        default: cout << "��������ȷ�Ĳ�����" <<endl;
    }
}
int main()
{
    cout<<"**     �ı��ļ����ʵļ��������     **"<<endl;
    cout<<"=================================="<<endl;
    cout<<"**         ��ѡ��Ҫִ�еĲ���      **"<<endl;
    cout<<"**         1-----�����ı��ĵ�     **"<<endl;
    cout<<"**         2-----�ı����ʻ���     **"<<endl;
    cout<<"**         3-----���ʶ�λ        **"<<endl;
    cout<<"**         4-----�˳�����        **"<<endl;
    cout<<"=================================="<<endl;
operate:
    cout<<"��ѡ��Ҫִ�еĲ�����"<<endl;
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
        default: cout << "��������ȷ�Ĳ�����" <<endl;
    }
    goto operate;
}


