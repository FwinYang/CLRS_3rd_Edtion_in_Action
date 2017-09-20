#include <random>

using namespace std;

//散列表共有701个槽
const int m = 701;

//除法散列法
int divisionH(int key)
{
	return key%m;
}

//乘法散列法
int multiplicationH(int key)
{
	double kA = 0.6180339887 * key;

	int kAb = kA;
	double kAmod1 = kA - kAb;

	int h = m*kAmod1;

	return h;
}

//全域散列法
int Hash(int key)
{
	//这里还原书上的例子，散列表共有6个槽，素数p的值为17。
	//a,b是随机生成的。
	const int m = 6;
	const int p = 17;

	uniform_int_distribution<unsigned> Za(1, p - 1);
	uniform_int_distribution<unsigned> Zb(0, p - 1);
	static default_random_engine e;

	int a = Za(e);
	int b = Zb(e);

	return ((a*key+b)%p)%m;
}