//德国坦克问题
#include <iostream>
#include <random>
using namespace std;
int randInt(int min, int max) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}
int main() {
	int number[10]; int max = 0; int randnumsToGet = 10; float deviation;
	int total = 100; //总共的坦克数
	cout << "Total number of tanks: " << total << endl;
    for (int i = 0; i < randnumsToGet; i++) {
		number[i] = randInt(1, total);//我们假设随机数的范围是1到total
		cout << number[i] << " ";//输出随机数
		if (number[i] > max) {
			max = number[i];
		}
    }
	cout << endl;
	float estimated = max + max / randnumsToGet - 1;
	cout << "The biggest number of tanks: " << max << endl;
	cout << "Estimated number of tanks: " << estimated << endl;
	deviation = (estimated - total) / static_cast<float>(total) * 100;
	cout << "Deviation: " << deviation << "%" << endl;
	cin.get();
	return 0;
}
