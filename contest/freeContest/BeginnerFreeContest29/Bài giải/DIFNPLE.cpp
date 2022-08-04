#include <iostream>
int main() {
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	if (a + b > c + d)
		std::cout << "Yes";
	else
		std::cout << "No";
}