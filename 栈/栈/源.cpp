#include"SeqStack.h"
#include"stack.h"

int main()
{
	SeqStack<int>SB(10);
	for (int i = 0; i < 10; i++)
	{
		SB.Push(i);
		
	}
	cout << SB;


	getchar();+++++
	return 0;
	
}