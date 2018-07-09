#include "head.h"

void IntoFreeArray()   // ��superstack����ʱ������freeArray
{
	next_free_list_index--;
	int index = INDEX_LIST_LENGTH - 1;           // ��ջ����ʼ������Ӵ�С����
	while(!myFileSystem.superStack.empty())
	{
		int temp = myFileSystem.superStack.top();
		myFileSystem.free_list[next_free_list_index][index] = temp;
		myFileSystem.superStack.pop();
		index--;
	}
	super_stack_number = 0;
}

void IntoSuperStack(int id)
{
	myFileSystem.superStack.push(id);
	super_stack_number ++;
	if(super_stack_number >= INDEX_LIST_LENGTH)  // ��superstack����ʱ������freeArray
	{
		IntoFreeArray();
	}
}

void ReleaseDataBlock(int index)
{
	int temp = myFileSystem.vector_file[index].beginning_in_dataArea;
	dataBlock block = myFileSystem.dataArea[temp];
	while(1)
	{
		IntoSuperStack(temp);
		cout<<"�ͷ���"<<temp<<"�����ݿ�"<<endl;
		if(block.next != -1)
		{
			temp = block.next;
			block = myFileSystem.dataArea[block.next];
		}
		else
		{
			return;
		}

	}
	{
		IntoSuperStack(temp);
		block = myFileSystem.dataArea[block.next];
	}while(block.next != -1);
}