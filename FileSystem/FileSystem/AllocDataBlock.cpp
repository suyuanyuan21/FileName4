#include "head.h"

void IntoSuperStack()  // free数组进入超级栈
{
	for(int i=0;i<INDEX_LIST_LENGTH;i++)
	{
		int param = myFileSystem.free_list[next_free_list_index][i];
		myFileSystem.superStack.push(param);
		myFileSystem.free_list[next_free_list_index][i] = -1;  //正在用的那组置为-1
	}

	super_stack_number = INDEX_LIST_LENGTH;

	if(next_free_list_index < INDEX_LIST_NUMBER)  // 如果没到最后一块就+1
	{
		next_free_list_index++;
	}
	
}

int AllocDataBlock()   //分配数据块
{
	if(myFileSystem.superStack.empty())
	{
		IntoSuperStack();   // 从free组进入超级栈
	}
	int result = myFileSystem.superStack.top();
	myFileSystem.superStack.pop();
	super_stack_number--;
	return result;

}