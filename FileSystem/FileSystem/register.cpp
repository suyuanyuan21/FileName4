#include "head.h"
user current_user1;

bool CheckUser1(string name, string password) // �����û��Ƿ��ǳ�ʼ�����û�
{
	for (int i = 0; i<MAX_User_NUMBER; i++)
	{
		if (myFileSystem.user_info[i].name == name && myFileSystem.user_info[i].password == password)
		{
			return true;
		}

	}
	return false;
}

bool Register()    //��¼ģ��
{

	int j = MAX_User_NUMBER+1;
	string name;
	string password;

	    cout << "�������µ��û���:";
		cin >> name;
		cout << "�����������룺";
		cin >> password;
		if (CheckUser1(name, password))
		{
			current_user1.name = name;
			current_user1.password = password;
			cout << "��ǰ�û��Ѵ��ڣ��������µ��û�������";
			return false;
		}
		else
		{   
			myFileSystem.user_info[2].name == name;
			myFileSystem.user_info[2].password == password;
			cout << "���û������ɹ�"<< endl;
			return true;
		}
	

}