#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
#include<random>
#include<memory>
#include"Checkout.h"
#include"Customer.h"

void histogram(const vector<int>&v, int min)
{
	string bar(60, '*');
	for (size_t i{}; i < v.size(); ++i)
	{
		cout << setw(3) << i + min << " " << setw(4) << v[i] << " " << bar.substr(0, v[i]) << (v[i] > static_cast<int>(bar.size()) ? ". . ." : "") << endl;

	}
}


int main()
{
	random_device random_n;

	int service_t_min{ 2 }, service_t_max{ 15 };
	uniform_int_distribution<>service_t_d{ service_t_min,service_t_max };

	int min_customer{ 15 }, max_customer{ 20 };
	uniform_int_distribution<> n_1st_customers_d{ min_customer,max_customer };


	int min_arr_interval{ 1 }, max_arr_interval{ 5 };
	uniform_int_distribution<>arrival_interval_d{ min_arr_interval,max_arr_interval };

	size_t n_checkouts{};
	cout << "输入有多少个服务台" << endl;
	cin >> n_checkouts;
	if (!n_checkouts)
	{
		cout << "你输入的服务台不符合现实，被置为1" << endl;
		n_checkouts = 1;
	}

	vector < unique_ptr<Checkout>>checkouts;
	checkouts.reserve(n_checkouts);

	for (size_t i{}; i < n_checkouts; i++)
	{
		checkouts.push_back(make_unique<Checkout>());
	}

	//不用创建太多的数组，直接用索引节省空间
	vector<int>service_times(service_t_max - service_t_min + 1);

	int count{ n_1st_customers_d(random_n) };//当店没开门有多少顾客在等待
	cout << "当店没开门有" << count << "个顾客在等待" << endl;

	int added{};
	int service_t{};
	
	auto comp = [](const unique_ptr<Checkout>&pc1, const unique_ptr<Checkout>&pc2) {return *pc1 < *pc2; };

	while (added++ < count)
	{
		service_t = service_t_d(random_n);
		auto iter = min_element(begin(checkouts), end(checkouts), comp);
		(*iter)->add(make_unique<Customer>(service_t));//把这个顾客安排在这条队列
		++service_times[service_t - service_t_min];//表明服务时间在这个时间的顾客数量+1
		
	}
	
	size_t time{};
	const size_t total_time{ 600 };
	size_t longest_q{};

	int new_cust_interval{ arrival_interval_d(random_n) };
	
	while (time < total_time)
	{
		++time;
		
		if (--new_cust_interval == 0)
		{
			service_t = service_t_d(random_n);
			(*min_element(begin(checkouts), end(checkouts)))->add(make_unique<Customer>(service_t));//把这个顾客安排在这条队列
			++service_times[service_t - service_t_min];//表明服务时间在这个时间的顾客数量+1

			for (auto& pcheckout : checkouts)
				longest_q = max(longest_q, pcheckout->qlength());
			
			new_cust_interval = arrival_interval_d(random_n);//重新设置下一个顾客到的时间间隔
			
			
			
		}
		
		for (int i = 0; i < checkouts.size(); i++)
		{
			if (checkouts[i]->if_customer())//如果vector的某个元素的队列是空的，对它进行操作会出错
			{
				checkouts[i]->time_increment();
			}
		}
			

	}
	//checkouts[10]->time_increment();
	cout << "最长队伍的长度为：" << longest_q << endl;
	cout << "服务时间的直方图为" << endl;

	histogram(service_times,service_t_min);

	cout << "今天的总顾客为" << accumulate(begin(service_times), end(service_times), 0) << endl;

	getchar(); getchar();
	getchar();
	return 0;

}