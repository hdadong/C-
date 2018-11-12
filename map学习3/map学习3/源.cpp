#include<map>
#include<iomanip>//isalpha()
#include<iostream>
#include<string>
#include<sstream> //for istringstream
#include<algorithm> //replace_if()&for_each()
#include<iterator>

//#include<cctype>


using std::string;
int main()
{
	std::cout << "Enter some text and enter*to end:\n";
		string text_in{};
		std::getline(std::cin, text_in, '*');


		std::replace_if(std::begin(text_in), std::end(text_in), [](const char&ch) {return !isalpha(ch); }, ' ');
		//删除非字母的字符
		std::istringstream text(text_in);
		std::istream_iterator<string>begin(text);
		std::istream_iterator<string>end;

		std::map<string, size_t>words;
		size_t max_len{};

		std::for_each(begin, end, [&max_len, &words](const string&word) {words[word]++; max_len = std::max(max_len, word.length()); });
		//找到最长的单词
		size_t per_line{ 4 }, count{};
		for (const auto &w : words)
		{
			std::cout << std::left << std::setw(max_len + 1) << w.first << std::setw(3) << std::right << w.second << " ";
			if (++count%per_line == 0)std::cout << std::endl;

		}

		std::cout << std::endl;


		getchar();
		getchar();
		getchar();
		getchar();		return 0;
}