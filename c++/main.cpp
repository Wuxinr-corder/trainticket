#include<iostream>
#include<string.h>
using namespace std;
struct tick{
	string name,in[100],out[100];
	long long int iden; 
	int price[100];
	int index=0;
	int count=0;
};
tick people[100];
string be,dao;
int temp,all=0,i,j;
int tic[9][9]={10,10,10,10,10,10,10,10,10,
				10,10,10,10,10,10,10,10,0,
				10,10,10,10,10,10,10,0,0,
				10,10,10,10,10,10,0,0,0,
				10,10,10,10,10,0,0,0,0,
				10,10,10,10,0,0,0,0,0,
				10,10,10,0,0,0,0,0,0,
				10,10,0,0,0,0,0,0,0,
				10,0,0,0,0,0,0,0,0,};
void welcome()
{
	cout<<"��ӭ����𳵹�Ʊϵͳ"<<endl;
	cout<<"�������������ǣ�"<<endl;
	cout<<"A.����Ʊ       B.��Ϣ��ѯ       C.��Ʊ       D.�˳�ϵͳ"<<endl;
} 
void buy();
void check()
{
	cout<<"������������ʼվ��"<<endl;
	cin>>be>>dao;
	cout<<"��ʼ��ѯ��Ʊ"<<endl;
	if(dao[2]=='\0')
	{
		cout<<"��Ʊ����Ϊ��";
		temp=dao[1]-be[1];
		cout<<tic[be[1]-'0'-1][temp-1]<<endl;
		if(tic[be[1]-'0'-1][temp-1]==0)
		{
			cout<<"��ǰ��Ʊ�����꣬������ת����һ�����²�ѯ��";
			check();
		}
		else{
			cout<<"Ʊ��Ϊ��"<<temp*100<<endl;
			cout<<"�Ƿ������ѯ��Ʊ��"<<endl;
			string ans;
			cin>>ans;
			if(ans=="��")
			check();
			else buy();
		}	
	}
	else{
		cout<<"��Ʊ����Ϊ��";
		temp=10-be[1]+'0';
		cout<<tic[be[1]-'0'-1][temp-1]<<endl;
		if(tic[be[1]-'0'-1][temp-1]==0)
		{
			cout<<"��ǰ��Ʊ�����꣬������ת����һ�����²�ѯ��";
			check();
		}
		else{
			cout<<"Ʊ��Ϊ��"<<temp*100<<endl;
			cout<<"�Ƿ������ѯ��Ʊ��"<<endl;
			string ans;
			cin>>ans;
			if(ans=="��")
			check();
			else buy();
		}	
	}
} 
void buy()
{
	int jud=0;
	cout<<"������ʼ��Ʊ"<<endl;
	cout<<"����������������";
	string p_name;
	cin>>p_name;
	cout<<"�������������֤�ţ�";
	long long int p_iden;
	cin>>p_iden;
	cout<<"������������ʼվ��";
	cin>>be;
	cout<<"�����������յ�վ��" ;
	cin>>dao;
	if(dao[2]=='\0')
	temp=dao[1]-be[1];
	else temp=10-be[1]+'0';
	cout<<endl<<"��������ȷ����Ϣ��"<<endl;
	cout<<"������"<<p_name<<endl;
	cout<<"���֤�ţ�"<<p_iden<<endl;
	cout<<"��ʼվΪ��"<<be<<"	"<<"�յ�վΪ��"<<dao<<endl;
	cout<<"Ʊ��Ϊ��"<<temp*100<<endl;
	cout<<"��Ϣ�Ƿ���ȷ��"<<endl;
	string ans;
	cin>>ans;
	if(ans=="��")
	{
		cout<<"��ϲ����Ʊ�ɹ�����������"<<endl<<endl;
		for(i=0;i<all;i++)
		{
			if(people[i].name==p_name)
			{
				people[i].index++;
				people[i].count++;
				people[i].in[people[i].index]=be;
				people[i].out[people[i].index]=dao;
				people[i].price[people[i].index]=temp*100;
				jud=1;
				break;
			}
		 } 
		if(jud==0)
		{
			people[all].name=p_name;
			people[all].iden=p_iden;
			people[all].in[people[all].index]=be;
			people[all].out[people[all].index]=dao;
			people[all].price[people[all].index]=temp*100;
			all++;
		}
		if(be[1]!='1')
		{
			for(i=0;i<be[1]-'0';i++)
			{
				for(j=be[1]-'0'-i-1;j<10-i;j++)
				tic[i][j]--;
			}
			for(i=be[1]-'0';i<9;i++)
			{
				for(j=0;j<10-i-1;j++)
				tic[i][j]--;
			}
		}
		else{
			for(i=0;i<dao[1]-'0'-1;i++)
			{
				for(j=0;j<10-i-1;j++)
				tic[i][j]--;
			}
		}
	 } 
	 else{
	 	buy();
	 }
	 
}
void infor()
{
	
} 
void refund()
{
	
}
int main()
{
	char m;
	while(1)
	{
		welcome();
		cin>>m;
		if(m=='A')
		{
			cout<<endl<<"���ѽ��빺Ʊϵͳ"<<endl;
			check();
		}
		else if(m=='B')
		{
			infor();
		}
		else if(m=='C')
		{
			refund();
		}
		else{
			return 0;
		}
	}
	
	return 0;
}

