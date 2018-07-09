#include "head.h"		//chen

bool ParsePath(string path)  // ��·����������
{
	int begin = 0;
	int ending = 0;
	string accessed;  // �Ѿ�����·��
	bool flag = true;  // ��ʾ�Ƿ��ǵ�һ��Ŀ¼
	while(ending < strlen(path.c_str()))
	{
		if(path[ending] == '\\')
		{
			string director = path.substr(begin,ending-begin);
			if(flag)
			{
				if(director != "home")             // ��Ŀ¼������home
				{
					cout<<"�����·������ȷ��"<<endl;
					cout<<"���������·�����磺home\\one\\two"<<endl;
					return false;
				}
				accessed += director;
				flag = false;
			}
			else
			{
				if(!ntdir(director))  //����һĿ¼
				{
					cout<<"�޷�����"<<accessed<<"·���µ�"<<director<<"�ļ���"<<endl;
					return false;
				}
				accessed += director;
			}
			
			begin = ending+1;
			//cout<<"�õ���Ŀ¼��"<<director<<endl;
			
		}
		ending ++;
	}
	string director = path.substr(begin,ending - begin);
	if(!ntdir(director))
	{
		cout<<"�޷�����"<<accessed<<"·���µ�"<<director<<"�ļ���"<<endl;
		return false;
	}
	cout<<"��ת��"<<path<<"�ɹ���"<<endl;
	return true;
}


void CopyDirector(int pos,int limit)   //����pos����Ŀ¼   limit��Ϊ�˷�ֹ �½���Ŀ¼���ظ��½� �������Ҫ�½���Ŀ¼�������ڻ����
	//limit�Ͳ������½���
{
	//��pos��Ŀ¼�����������ļ���ȫ���½�������last_director
	
	director current = myFileSystem.vector_director[pos];
	director temp;
	temp.id = myFileSystem.vector_director.size();
	
	temp.name = current.name;
	temp.owner = current.owner;
	temp.last_director = current_director_index;   //����last_director
	
	
	list<int>::iterator p = current.file_list.begin();  //�ļ���������ͬ  
	while(p != current.file_list.end())
	{
		temp.file_list.push_back(*p);
		p++;
	}

	
	myFileSystem.vector_director[current_director_index].director_list.push_back(temp.id);  // �ڵ�ǰĿ¼�м����µ�Ŀ¼
	myFileSystem.vector_director.push_back(temp);//��Ŀ¼��Ϣ�м����µ�Ŀ¼
	current_director_index = temp.id;	//���µ�ǰĿ¼
	
	p = current.director_list.begin();  // �ڵ�ǰĿ¼����Ŀ¼�м�������
	while(p != current.director_list.end())
	{
		if(*p != -1 && *p < limit)
		{
			CopyDirector(*p,limit);
		}
		p++;
	}
	
}

bool copy(string name,string path)
{
	int strore_director = current_director_index;  //�ݴ�
	current_director_index = 0;
	int pos = IsFileInCurrentDirector(name);
	if(pos == -1)
	{
		pos = IsDirectorInCurrentDirector(name);
		if(pos == -1)
		{
			cout<<"��ǰĿ¼û��"<<name<<"���ļ����ļ���"<<endl;
			cout<<"����ʧ�ܣ�"<<endl;
			return false;
		}
		else// ���Ƶ����ļ���
		{
			if(myFileSystem.vector_director[pos].owner != current_user.name && myFileSystem.vector_director[pos].owner != "empty")//��֤Ȩ��
			{
				cout<<"��û�в���"<<name<<"�ļ��е�Ȩ��"<<endl;
				cout<<"����ʧ��!"<<endl;
				return false;
			}

			if(!ParsePath(path))  //��ת��Ҫ���Ƶ���Ŀ¼��
			{
				cout<<"����ʧ�ܣ�"<<endl;
				return false;
			}
			CopyDirector(pos,myFileSystem.vector_director.size());

		}
	}
	else  // ���Ƶ����ļ�
	{
		if(myFileSystem.vector_file[pos].owner != current_user.name && myFileSystem.vector_file[pos].owner != "empty")//��֤Ȩ��
		{
			cout<<"��û�в���"<<name<<"�ļ��е�Ȩ��"<<endl;
			cout<<"����ʧ��!"<<endl;
			return false;
		}

		if(!ParsePath(path))    //��ת��Ҫ���Ƶ���Ŀ¼��
		{
			cout<<"����ʧ�ܣ�"<<endl;
			return false;
		}
		myFileSystem.vector_director[current_director_index].file_list.push_back(pos);     //�ڸ�Ŀ¼����Ӷ�Ӧ�ļ�����������
	}

	cout<<"���Ƴɹ�!"<<endl;
	current_director_index = strore_director;  //�ָ���ǰĿ¼
	return true;
}