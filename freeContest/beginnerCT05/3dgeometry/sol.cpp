#include <bits/stdc++.h>
#define int long long
using namespace std;

class Vector {
private:
	int x, y, z;
public:
	Vector(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Vector operator+(Vector v);
	Vector operator-(Vector v);
	int operator^(Vector v);
	Vector operator*(Vector v);
	double magnitude()
	{
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}
	friend ostream& operator<<(ostream& out, const Vector& v);
};

Vector Vector::operator+(Vector v)
{
	int x1, y1, z1;
	x1 = x + v.x;
	y1 = y + v.y;
	z1 = z + v.z;
	return Vector(x1, y1, z1);
}

Vector Vector::operator-(Vector v)
{
	int x1, y1, z1;
	x1 = x - v.x;
	y1 = y - v.y;
	z1 = z - v.z;
	return Vector(x1, y1, z1);
}

int Vector::operator^(Vector v)
{
	int x1, y1, z1;
	x1 = x * v.x;
	y1 = y * v.y;
	z1 = z * v.z;
	return (x1 + y1 + z1);
}

Vector Vector::operator*(Vector v)
{
	int x1, y1, z1;
	x1 = y * v.z - z * v.y;
	y1 = z * v.x - x * v.z;
	z1 = x * v.y - y * v.x;
	return Vector(x1, y1, z1);
}

ostream& operator<<(ostream& out, const Vector& v) {
	out << v.x << "i ";
	if (v.y >= 0)
		out << "+ ";
	out << v.y << "j ";
	if (v.z >= 0)
		out << "+ ";
	out << v.z << "k" << endl;
	return out;
}

double shortDistance(Vector line_point1, Vector line_point2, Vector point) {
	Vector AB = line_point2 - line_point1;
	Vector AC = point - line_point1;
	double area = Vector(AB * AC).magnitude();
	double CD = area / AB.magnitude();
	return CD;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int ax, ay, az; cin >> ax >> ay >> az;
		int bx, by, bz; cin >> bx >> by >> bz;
		int cx, cy, cz; cin >> cx >> cy >> cz;
		cout << setprecision(2) << fixed;
		Vector point(ax, ay, az);
		Vector line_point1(bx, by, bz), line_point2(cx, cy, cz);
		double res = shortDistance(line_point1, line_point2, point); 
		cout << res << "\n";
	}
}