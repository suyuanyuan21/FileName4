#include"head.h"
#include <stdlib.h>
#include <stdio.h>

fileSystem myFileSystem;
int memory_index;
char memory[MAX_FILE_LENGTH][DATA_BLOCK_LENGTH];
int current_director_index;
int next_free_list_index;
int super_stack_number;

void Initialize_dataBlock()  //��ʼ�����ݿ�
{
	for(int i=0;i<DATA_BLOCK_NUMBER;i++)
	{
		dataBlock temp ;
		temp.next = -1;
		temp.used = 0;
		for(int j=0;j<DATA_BLOCK_LENGTH+1;j++)
		{
			temp.content[j] = '\0';
		}
		myFileSystem.dataArea.push_back(temp);
		//cout<<"ÿ���С"<<sizeof(temp)<<endl;
	}
	//cout<<"���ݿ���Ŀ"<<myFileSystem.dataArea.size()<<endl;
	cout<<"��ʼ��������ɹ���"<<endl;
	return ;
}


void Initialize_Index_List()  //��ʼ��������
{
	
	next_free_list_index = 0;
	super_stack_number = 0;
	while(!myFileSystem.superStack.empty())
	{
		myFileSystem.superStack.pop();
	}
	for(int i=0;i<INDEX_LIST_NUMBER;i++)
	{
		for(int j=INDEX_LIST_LENGTH-1;j>=0;j--)
		{
			myFileSystem.free_list[i][j] = i*INDEX_LIST_LENGTH + INDEX_LIST_LENGTH - j -1;
			//cout<<i<<","<<j<<myFileSystem.free_list[i][j]<<endl;
		}
	}
	cout<<"��ʼ���������ɹ���"<<endl;
	return ;
}


void Initialize_User_Info()   // ��ʼ���û���Ϣ
{
	char temp[6]; 
	strcpy_s(temp,"user");
	for(int i=0;i<MAX_User_NUMBER;i++)
	{
		temp[4] = (char)i+49;
		temp[5] = '\0';
		myFileSystem.user_info[i].name = temp ; 
		myFileSystem.user_info[i].password = temp;
		//cout<<"ת��������"<<myFileSystem.user_info[i].name<<endl;
	}
	cout<<"��ʼ���û���Ϣ�ɹ�!"<<endl;
}


void Initialize_Vector_Director()   //��ʼ��Ŀ¼��Ϣ
{
	myFileSystem.vector_director.clear();
	director first;
	first.last_director = -1;
	first.id = 0;
	first.name = "home";
	first.owner = "empty";
	myFileSystem.vector_director.push_back(first);
	cout<<"��ʼ��Ŀ¼��Ϣ�ɹ�!"<<endl;
}


void Initialize_Memory()  // ��ʼ���ڴ�
{
	memory_index = 0;
	for(int i=0;i<MAX_FILE_LENGTH;i++)
	{
		for(int j=0;j<DATA_BLOCK_LENGTH;j++)
		{
			memory[i][j]='\0';
		}
	}
	cout<<"��ʼ���ڴ�ɹ�!"<<endl;
}


bool Initialize()  // ��ʼ��
{
	
	Initialize_Vector_Director();   // ��ʼ���ļ�����Ϣ
	current_director_index = 0;
	open_file_list.clear();
	myFileSystem.vector_file.clear();
	
	Initialize_dataBlock();		 // ��ʼ�����ݿ�
	Initialize_Index_List();		// ��ʼ��������
	Initialize_User_Info();			// ��ʼ���û���Ϣ
	print();
	return true;
		
}



