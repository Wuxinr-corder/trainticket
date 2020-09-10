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
	cout<<"欢迎进入火车购票系统"<<endl;
	cout<<"请问您的需求是："<<endl;
	cout<<"A.购买车票       B.信息查询       C.退票       D.退出系统"<<endl;
} 
void buy();
void check()
{
	cout<<"请输入您的起始站："<<endl;
	cin>>be>>dao;
	cout<<"开始查询余票"<<endl;
	if(dao[2]=='\0')
	{
		cout<<"余票数量为：";
		temp=dao[1]-be[1];
		cout<<tic[be[1]-'0'-1][temp-1]<<endl;
		if(tic[be[1]-'0'-1][temp-1]==0)
		{
			cout<<"当前车票已售完，即将跳转回上一级重新查询。";
			check();
		}
		else{
			cout<<"票价为："<<temp*100<<endl;
			cout<<"是否继续查询余票？"<<endl;
			string ans;
			cin>>ans;
			if(ans=="是")
			check();
			else buy();
		}	
	}
	else{
		cout<<"余票数量为：";
		temp=10-be[1]+'0';
		cout<<tic[be[1]-'0'-1][temp-1]<<endl;
		if(tic[be[1]-'0'-1][temp-1]==0)
		{
			cout<<"当前车票已售完，即将跳转回上一级重新查询。";
			check();
		}
		else{
			cout<<"票价为："<<temp*100<<endl;
			cout<<"是否继续查询余票？"<<endl;
			string ans;
			cin>>ans;
			if(ans=="是")
			check();
			else buy();
		}	
	}
} 
void buy()
{
	int jud=0;
	cout<<"即将开始购票"<<endl;
	cout<<"请输入您的姓名：";
	string p_name;
	cin>>p_name;
	cout<<"请输入您的身份证号：";
	long long int p_iden;
	cin>>p_iden;
	cout<<"请输入您的起始站：";
	cin>>be;
	cout<<"请输入您的终点站：" ;
	cin>>dao;
	if(dao[2]=='\0')
	temp=dao[1]-be[1];
	else temp=10-be[1]+'0';
	cout<<endl<<"现在请您确认信息："<<endl;
	cout<<"姓名："<<p_name<<endl;
	cout<<"身份证号："<<p_iden<<endl;
	cout<<"起始站为："<<be<<"	"<<"终点站为："<<dao<<endl;
	cout<<"票价为："<<temp*100<<endl;
	cout<<"信息是否正确？"<<endl;
	string ans;
	cin>>ans;
	if(ans=="是")
	{
		cout<<"恭喜您购票成功！即将返回"<<endl<<endl;
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
			cout<<endl<<"您已进入购票系统"<<endl;
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

