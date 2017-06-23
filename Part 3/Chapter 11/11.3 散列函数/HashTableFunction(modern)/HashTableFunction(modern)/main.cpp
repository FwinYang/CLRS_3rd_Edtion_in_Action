#include <random>

using namespace std;

//ɢ�б���701����
const int m = 701;

//����ɢ�з�
int divisionH(int key)
{
	return key%m;
}

//�˷�ɢ�з�
int multiplicationH(int key)
{
	double kA = 0.6180339887 * key;

	int kAb = kA;
	double kAmod1 = kA - kAb;

	int h = m*kAmod1;

	return h;
}

//ȫ��ɢ�з�
int Hash(int key)
{
	//���ﻹԭ���ϵ����ӣ�ɢ�б���6���ۣ�����p��ֵΪ17��
	//a,b��������ɵġ�
	const int m = 6;
	const int p = 17;

	uniform_int_distribution<unsigned> Za(1, p - 1);
	uniform_int_distribution<unsigned> Zb(0, p - 1);
	static default_random_engine e;

	int a = Za(e);
	int b = Zb(e);

	return ((a*key+b)%p)%m;
}