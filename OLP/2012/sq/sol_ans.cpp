// Bai_3: Tam Sao That Bon: su dung cay Fenwick

#include <fstream>
#include <iostream>
#include <stdint.h>
#include <ctime>
#include <string.h>
using namespace std;

//ifstream fi("D:\\Olympic\\Test\\SQ\\TEST01\\SQ.INP");
//ofstream fo("SQ.OUT");
int a[1000001], s[1000001] = { 0 };	// s[i] = tong cac phan tu co goc la i
int n,				// so phan tu mang a	
num,			// so phan tu nap vao cay				
p0,				// bien tam dung de danh dau vi tri p2 xem co thay doi khong
p1,				// chi so nguoi dau tien tim thay
p2, p3;			// chi so nguoi o giua thu 1 và thu 2
bool done;			// cho biet dieu kien duoc thoa man khong
int64_t res = 0;	// chua ket qua

void insert_t(int x)	// nap x vao cay
{
	while (x <= n)
	{
		s[x]++;				// tang so phan tu trong cay co goc la x luu vao s
		x += (x & (-x));	// nhay den nut cha cua x
	}
}
int sum_t(int x)			// đem so phan tu <= x trong mang cay s
{
	int r = 0;
	while (x > 0)
	{
		r += s[x];
		x = x & (x - 1);	// nhay sang nut dung lien truoc nhanh cay goc x
	}
	return r;
}
void khoiTaoNhomA()
{
	int i;
	p2 = p3 = 0;				// khoi tao chi so nguoi o giua thu 1 va thu 2 
	for (i = 1; i <= n; i++)	// tim so duong dau tien
		if (a[i] > 0)
		{
			p1 = i;				// chi so cua so duong dau tien tim thay
			break;
		}
	if (p1 >= n - 2)			// khong thoa dieu kien	
		done = false;
	i = p1;
	while (i <= n && done)
	{
		if (a[i] > 0)			// chi so SQ cua nam
		{
			insert_t(a[i]);		// them vao cay va tang so phan tu trong cay co goc a[i]
			num++;				// tăng so phan tu nap vao cay
		}
		else					// chi so SQ cua nu
		{
			p0 = p2 = i; 		// luu lai vi tri a[i] < 0 thu 1 va danh dau vao p0
			break;
		}
		i++;
	}
	if (p2 == 0 || p2 >= n - 1)	// khong thoa dieu kien
		done = false;
	i = p2 + 1;
	while (i <= n && done)		// tim phan tu a[i] < 0 thu 2
	{
		if (a[i] < 0)
		{
			p3 = i;				// luu lai vi tri a[i] < 0 thu 2
			break;
		}
		i++;
	}
	if (p3 == 0 || p3 == n)		// khong thoa dieu kien
		done = false;
}
void khoiTaoNhomB()
{
	int i;
	p2 = p3 = 0;				// khoi tao chi so nguoi o giua thu 1 va thu 2
	for (i = 1; i <= n; i++)	// tim so am dau tien
		if (a[i] < 0)
		{
			p1 = i;			// chi so cua so am dau tien tim thay
			break;
		}
	if (p1 >= n - 2)		// khong thoa dieu kien
		done = false;
	i = p1;
	while (i <= n && done)
	{
		if (a[i] < 0)
			insert_t(-a[i]);
		else
		{
			p0 = p2 = i;	// luu lai vi tri a[i] > 0 thu 1 vao p2 va danh dau vao p0
			break;
		}
		i++;
	}
	if (p2 == 0 || p2 >= n - 1)	// khong thoa dieu kien
		done = false;
	i = p2 + 1;
	while (i <= n && done)		// tim phan tu a[i] > 0 thu 2
	{
		if (a[i] > 0)
		{
			p3 = i;				// luu lai vi tri a[i] > 0 thu 2
			break;
		}
		i++;
	}
	if (p3 == 0 || p3 == n)		// khong thoa dieu kien	
		done = false;
}
int main()
{
	clock_t aa = clock();
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	num = 0;			// khoi tao so phan tu da nap vao cay
	done = true;		// gia su dieu kien chon nhom A duoc thoa	
	khoiTaoNhomA();
	cout << "p0 = " << p0 << "\n";
	cout << "p1 = " << p1 << "\n";
	cout << "p2 = " << p2 << "\n";
	cout << "p3 = " << p3 << "\n";
	// for (int i = 1; i <= 18; ++i)
	// 	cout << s[i] << " ";
	// cout << "\n";
	if (done)			// neu khong vi pham dieu kien
	{
		for (int i = p3 + 1; i <= n; i++)	// tim cac phan tu duong p4
			if (a[i] < 0)
			{
				p2 = p3;
				p3 = i;
			}
			else		// tim thay p4 => dem so nhom A 
			{
				if (p0 < p2)	// neu p2 thay doi so voi ban dau (co nhieu hon 2 phan tu am o giua)
				{
					for (int j = p0 + 1; j < p2; j++)
						if (a[j] > 0)
						{
							cout << "nap " << a[j] << "\n";
							insert_t(a[j]);		// nap vao cay
							num++;				// tang so phan tu da nap
						}
					p0 = p2;
				}
				for (int i = 1; i <= 18; ++i)
					cout << s[i] << " ";
				cout << "\n";
				cout << "res += num - sum_t(a[i]) = " << num << " - " << sum_t(a[i]) << "\n";
				res += (num - sum_t(a[i]));		// res += (so phan tu da nap - so phan tu <= a[i])
			}
	}
	memset(s, 0, sizeof(s));	// reset  mang s
	done = true;		// gia su dieu kien chon nhom B duoc thoa	
	cout << res << " ";
	res = 0;
	khoiTaoNhomB();
	if (done)			// neu khong vi pham dieu kien	
	{
		for (int i = p3 + 1; i <= n; i++)	// tim cac phan tu am p4
			if (a[i] > 0)
			{
				p2 = p3;
				p3 = i;
			}
			else			// tim thay p4 => dem so nhom B
			{
				if (p0 < p2)
				{
					for (int j = p0 + 1; j < p2; j++)
						if (a[j] < 0)
							insert_t(-a[j]);	// nap tri tuyet doi (khong can dem so phan tu da nap)
					p0 = p2;
				}
				res += sum_t(-a[i] - 1);	// res += (so phan tu <= (-a[i] - 1) <=> < -a[i]
			}
	}
	cout << res << endl;
	clock_t bb = clock();
	//cout << "Time: " << (double)(bb - aa) / 1000 << " sec\n";
}
