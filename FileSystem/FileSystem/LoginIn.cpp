#include "head.h"
user current_user;

bool CheckUser(string name,string password) // �����û��Ƿ��ǳ�ʼ�����û�
{
	for(int i=0;i<MAX_User_NUMBER;i++)
	{
		if(myFileSystem.user_info[i].name == name && myFileSystem.user_info[i].password == password)
		{
			return true;
		}

	}
	return false;
}

bool LoginIn()    //��¼ģ��
{

	int chance = 5;
	string name;
	string password;
	while(chance > 0)
	{
		cout<<"�������û���:";
		cin>>name;
		cout<<"���������룺";
		cin>>password;
		if(CheckUser(name,password))
		{
			current_user.name = name;
			current_user.password = password;
			return true;
		}
		else
		{
			cout<<"�û������������������"<<--chance<<"�λ���"<<endl;
			print();
		}
	}
	return false;
	
}


