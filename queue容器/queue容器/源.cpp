#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
#include<random>
#include<utility>

#include"Checkout.h"
#include"Customer.h"

using namespace std;
using distribution = uniform_int_distribution<>;

void histogram(const vector<int> &v, int min)
{
	string bar(60, '*');
	for (size_t i{}; i < v.size(); ++i)
	{
		cout << setw(3) << i + min << " " << setw(4) << v[i] << " " << bar.substr(0, v[i]) << (v[i] > static_cast<int>(bar.size()) ? ". . ." : "") << endl;
	}
}


int main()
{
	random_device random_n;//随机数生成器
	int service_t_min{ 2 }, service_t_max{ 15 };  //服务时常
	distribution service_t_d{ service_t_min,service_t_max };

	int min_customers{ 100 }, max_customers{ 300};//顾客数
	distribution n_1st_customers_d{ min_customers,max_customers };

	int min_arr_interval{ 1 }, max_arr_interval{ 5 };//间隔时间
	distribution arrival_interval_d{ min_arr_interval,max_arr_interval };

	

	size_t n_checkouts{};   //服务台数量
	cout << "输入这家商店的服务台数量:";
	cin >> n_checkouts;
	if (!n_checkouts)
	{
		cout << "服务台数量要大于1，你输入了0，我帮你置成1了." << endl;
		n_checkouts = 1;
	}
	vector<Checkout>checkouts{ n_checkouts };  //服务台数组
	vector<int> service_times(service_t_max - service_t_min + 1); //服务时间数组

	int count{ n_1st_customers_d(random_n) }; //顾客数
	cout << "有多少顾客在没开门的时候就在店门外排好队了:" << count << endl;
	int added{};
	int service_t{};
	while (added++ < count) 
	{
		service_t = service_t_d(random_n);
		min_element(begin(checkouts), end(checkouts))->add(Customer(service_t));//在最短的队伍中 增加这个顾客
		++service_times[service_t - service_t_min];//服务时间数组+1
	}

	size_t time{};
	const size_t total_time{ 600 };//总服务时长
	size_t longest_q{}; //最长的队伍

	//上面是商店没开门之前已经在外面排好队的顾客

	int p = n_checkouts - 1;
	int min_relax_checkout{ 0 }, max_relax_checkout{p};
	distribution relax_checkout{ min_relax_checkout,max_relax_checkout };
	//服务台每天都会随机有一台放假
	int today_relax_checkout{ relax_checkout(random_n) };
	checkouts[today_relax_checkout].let_him_relax();
	cout << "店开门了！" << "第" << today_relax_checkout + 1 << "个服务台放假了，有"<< checkouts[today_relax_checkout].qlength()<<"个顾客在这条队伍，大家请更换服务台！" << endl;
	//以下操作时开门之后要把排在这条服务台的队伍的人疏散到其他队伍去
	
	for (int i = checkouts[today_relax_checkout].qlength(); i != 0; i--)
	{
		int turn_checkout = -1;
		if (turn_checkout == -1)//移动
		{
			int min_turn_checkout{ 0 }, max_turn_checkout{ p };
			distribution turning_checkout{ min_relax_checkout,max_relax_checkout };
			turn_checkout = turning_checkout(random_n);
			
		}
		if (turn_checkout == today_relax_checkout)//移动到不是这台服务台的其他服务台，重新操作一次
		{
			i++;
			continue;

		}
		
		checkouts[turn_checkout].add(checkouts[today_relax_checkout].turn_line());
		cout << "已经移动到第" << turn_checkout + 1 << "号台" << endl;
	}
	cout << "所有顾客换台完毕，开始营业！" << endl;


	checkouts.erase(begin(checkouts) + today_relax_checkout);//从服务台中删除这个休息的服务台，防止下面的min_element又把顾客放进去
	


	//商店开门之后隔一段时间会有顾客到来
	int new_cust_interval{ arrival_interval_d(random_n) };
	while (time < total_time)
	{
		++time;
		if (--new_cust_interval == 0)//每次都会减一直到等于0，然后新的顾客会来
		{



			service_t = service_t_d(random_n);
			min_element(begin(checkouts), end(checkouts))->add(Customer(service_t));//在最短的队伍中 增加这个顾客
			++service_times[service_t - service_t_min];//改变服务时间数组
			for (auto& checkout : checkouts)//改变最长队列
				longest_q = max(longest_q, checkout.qlength());
	
		}
		for (auto & checkout : checkouts)
			checkout.time_increment();//踢掉每条队列的第一个顾客
	}

	cout << "Maximum queue length=" << longest_q << endl;
	cout << "\nHistogram of service times:\n";
		histogram(service_times, service_t_min);
	cout << "\nTotal number of customers today:" << accumulate(begin(service_times), end(service_times), 0) << endl;

	
	getchar();
	getchar();	getchar();
	getchar();
	getchar();
	return 0;






}