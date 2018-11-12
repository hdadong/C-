#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;
#include<string>

	int main()
{	
		vector<double>numbers{ 2.5,10.0,3.5,6.5,8.0,12.0,1.5,6.0 };
		/*make_heap(begin(numbers), end(numbers));
		numbers.push_back(11);
		push_heap(begin(numbers), end(numbers));

		*/
		make_heap(begin(numbers), end(numbers), greater<>());
	/*	numbers.push_back(1.2);
		push_heap(begin(numbers), end(numbers), greater<>());
		*/
		pop_heap(begin(numbers), end(numbers),greater<>());//将第一个元素移动到最后
		numbers.pop_back();//用VECTOR的成员函数移除最后一个元素,如果不移除则不是堆，部分元素为堆
		if (is_heap(begin(numbers), end(numbers), greater<>()))
		{
			cout << "哈哈" << endl;

		}
		auto iter = is_heap_until(begin(numbers), end(numbers), greater<>());
		//检查是否有部分元素为堆，若所有元素都为堆，则返回一个结束迭代器end(numbers)
		//若元素少于2个也会返回结束迭代器
		if (iter != end(numbers))
			cout << *iter<< endl;



		
		getchar();
		return 0;
}