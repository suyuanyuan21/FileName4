#include "head.h"
user current_user1;

bool CheckUser1(string name, string password) // 检查该用户是否是初始化的用户
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

bool Register()    //登录模块
{

	int j = MAX_User_NUMBER+1;
	string name;
	string password;

	    cout << "请输入新的用户名:";
		cin >> name;
		cout << "请输入新密码：";
		cin >> password;
		if (CheckUser1(name, password))
		{
			current_user1.name = name;
			current_user1.password = password;
			cout << "当前用户已存在，请输入新的用户和密码";
			return false;
		}
		else
		{   
			myFileSystem.user_info[2].name == name;
			myFileSystem.user_info[2].password == password;
			cout << "新用户创建成功"<< endl;
			return true;
		}
	

}