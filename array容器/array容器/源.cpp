#include<array>
#include<iostream>
#include<string>
#include<iomanip>
#include<algorithm>
#include<numeric>
using namespace std;

int main()
{
	array<double, 100>data{};
	data.fill(3.1415926);
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << endl;
	}

	array<std::string, 5> words{ "one","two","three","four","five" };
	cout << get<3>(words) << endl;
	cout << get<0>(words) << endl;
	
	const unsigned int min_wt{ 100U };
	const unsigned int max_wt{ 250U };
	const unsigned int wt_step{ 10U };
	const size_t wt_count{ 1 + (max_wt - min_wt) / wt_step };
	const unsigned int min_ht{ 48U };
	const unsigned int max_ht{ 84U };
	const unsigned int ht_step{ 2U };
	const size_t ht_count{ 1 + (max_ht - min_ht) / ht_step };

	const double lbs_per_kg{ 2.20462 };
	const double ins_per_m{ 39.3701 };

	array<unsigned int, wt_count>weight_lbs;
	array<unsigned int, ht_count>height_ins;

	for (size_t i{}, w{ min_wt }; i < wt_count; w += wt_step, i++)
	{
		weight_lbs.at(i) = w;
	}
	
	unsigned int h(min_ht);
	for (auto& height : height_ins)//用hegith代表height_ins的每一个元素
	{
		height = h;
		h += ht_step;
	}

	cout << std::setw(7) << "|";

	for (const auto&w : weight_lbs)//const说明用W表示weight_lbs的每一个元素，但是不能修改
	{
		cout << setw(5) << w << "|";
	}
	cout << endl;


	for (size_t i{ 1 }; i < wt_count; i++)
	{
		std::cout << "--------";
	
	}
	cout << endl;
	double bmi{ };
	unsigned int feet{};
	unsigned int inches{};
	const unsigned int inches_per_foot{ 12U };
	for (const auto&h : height_ins)
	{
		feet = h / inches_per_foot;
		inches = h % inches_per_foot;
		cout<<setw(2)<<feet<<"'"<<setw(2)<<inches<<"\" "<< "|";
		cout << fixed << setprecision(1);
		for (const auto&w : weight_lbs)
		{
			bmi = h / ins_per_m;
			bmi = (w / lbs_per_kg) / (bmi*bmi);
			cout << setw(2) << " " << bmi << " |";

		}
		cout << endl;
	}
	for (size_t i{ 1 }; i < wt_count; ++i)
	{
		cout << "---------";
	}

	cout << "NOmoal";

	//初始化一个数组使其++递增
	array<double, 10>value;
	iota(begin(value), end(value), 10.0);
	for (const auto&w : value)
	{
		cout << w << endl;
	}

	array<char, 10>zimu;
	iota(begin(zimu), end(zimu), 65);
	for (const auto&w : zimu)
	{
		cout << w << endl;
	}


	//指向最后一个元素和第一个元素前面一个位置的方向迭代器 逆序方式处理元素
	array<double, 5>sett{ 10.0,11.0,12.0,13.0,14.0 };
	auto start = rbegin(sett);
	auto finish = rend(sett);
	while (start != finish)
	{
		cout << *(start++);
	}

	for (auto iter = rbegin(sett); iter != rend(sett); ++iter)
	{
		cout << *iter << endl;
	}






	getchar();
	return 0;
}