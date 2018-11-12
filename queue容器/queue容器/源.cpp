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
	random_device random_n;//�����������
	int service_t_min{ 2 }, service_t_max{ 15 };  //����ʱ��
	distribution service_t_d{ service_t_min,service_t_max };

	int min_customers{ 100 }, max_customers{ 300};//�˿���
	distribution n_1st_customers_d{ min_customers,max_customers };

	int min_arr_interval{ 1 }, max_arr_interval{ 5 };//���ʱ��
	distribution arrival_interval_d{ min_arr_interval,max_arr_interval };

	

	size_t n_checkouts{};   //����̨����
	cout << "��������̵�ķ���̨����:";
	cin >> n_checkouts;
	if (!n_checkouts)
	{
		cout << "����̨����Ҫ����1����������0���Ұ����ó�1��." << endl;
		n_checkouts = 1;
	}
	vector<Checkout>checkouts{ n_checkouts };  //����̨����
	vector<int> service_times(service_t_max - service_t_min + 1); //����ʱ������

	int count{ n_1st_customers_d(random_n) }; //�˿���
	cout << "�ж��ٹ˿���û���ŵ�ʱ����ڵ������źö���:" << count << endl;
	int added{};
	int service_t{};
	while (added++ < count) 
	{
		service_t = service_t_d(random_n);
		min_element(begin(checkouts), end(checkouts))->add(Customer(service_t));//����̵Ķ����� ��������˿�
		++service_times[service_t - service_t_min];//����ʱ������+1
	}

	size_t time{};
	const size_t total_time{ 600 };//�ܷ���ʱ��
	size_t longest_q{}; //��Ķ���

	//�������̵�û����֮ǰ�Ѿ��������źöӵĹ˿�

	int p = n_checkouts - 1;
	int min_relax_checkout{ 0 }, max_relax_checkout{p};
	distribution relax_checkout{ min_relax_checkout,max_relax_checkout };
	//����̨ÿ�춼�������һ̨�ż�
	int today_relax_checkout{ relax_checkout(random_n) };
	checkouts[today_relax_checkout].let_him_relax();
	cout << "�꿪���ˣ�" << "��" << today_relax_checkout + 1 << "������̨�ż��ˣ���"<< checkouts[today_relax_checkout].qlength()<<"���˿����������飬������������̨��" << endl;
	//���²���ʱ����֮��Ҫ��������������̨�Ķ��������ɢ����������ȥ
	
	for (int i = checkouts[today_relax_checkout].qlength(); i != 0; i--)
	{
		int turn_checkout = -1;
		if (turn_checkout == -1)//�ƶ�
		{
			int min_turn_checkout{ 0 }, max_turn_checkout{ p };
			distribution turning_checkout{ min_relax_checkout,max_relax_checkout };
			turn_checkout = turning_checkout(random_n);
			
		}
		if (turn_checkout == today_relax_checkout)//�ƶ���������̨����̨����������̨�����²���һ��
		{
			i++;
			continue;

		}
		
		checkouts[turn_checkout].add(checkouts[today_relax_checkout].turn_line());
		cout << "�Ѿ��ƶ�����" << turn_checkout + 1 << "��̨" << endl;
	}
	cout << "���й˿ͻ�̨��ϣ���ʼӪҵ��" << endl;


	checkouts.erase(begin(checkouts) + today_relax_checkout);//�ӷ���̨��ɾ�������Ϣ�ķ���̨����ֹ�����min_element�ְѹ˿ͷŽ�ȥ
	


	//�̵꿪��֮���һ��ʱ����й˿͵���
	int new_cust_interval{ arrival_interval_d(random_n) };
	while (time < total_time)
	{
		++time;
		if (--new_cust_interval == 0)//ÿ�ζ����һֱ������0��Ȼ���µĹ˿ͻ���
		{



			service_t = service_t_d(random_n);
			min_element(begin(checkouts), end(checkouts))->add(Customer(service_t));//����̵Ķ����� ��������˿�
			++service_times[service_t - service_t_min];//�ı����ʱ������
			for (auto& checkout : checkouts)//�ı������
				longest_q = max(longest_q, checkout.qlength());
	
		}
		for (auto & checkout : checkouts)
			checkout.time_increment();//�ߵ�ÿ�����еĵ�һ���˿�
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