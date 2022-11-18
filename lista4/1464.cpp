#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define endl '\n'
#define _ ios::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

typedef long long ll;

struct pt {
	int x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ll sarea2(pt p, pt q, pt r) {
	return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r) {
	return sarea2(p, q, r) >= 0;
}

vector<pt> convex_hull(vector<pt> v) {
	if (v.size() <= 1) return v;
	vector<pt> l, u;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		while (l.size() > 1 and !ccw(l[l.size()-2], l.back(), v[i]))
			l.pop_back();
		l.push_back(v[i]);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		while (u.size() > 1 and !ccw(u[u.size()-2], u.back(), v[i]))
			u.pop_back();
		u.push_back(v[i]);
	}
	l.pop_back(); u.pop_back();
	for (pt i : u) l.push_back(i);
	return l;
}

double distance(pt p, pt q) {
    return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
}

double triangle_area(pt a, pt b, pt c) {
    double side_a = distance(a, b);
	double side_b = distance(b, c);
	double side_c = distance(c, a);
    double semi_perimeter = (side_a + side_b + side_c) / 2.0;
	return sqrt(semi_perimeter * (semi_perimeter - side_a) * (semi_perimeter - side_b) * (semi_perimeter - side_c));
}

int main() { _
    int N;

    while (cin >> N && N != 0) {
        int x, y;

        vector<pt> points(N);
        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            points[i] = pt(x, y);
        }

        int counter = 0;

        while (!points.empty()) {
            vector<pt> hull = convex_hull(points);

            for (pt hull_point : hull) {
                points.erase(std::remove(points.begin(), points.end(), hull_point), points.end());
            }
            counter++;
        }
        if (counter % 2 == 0) {
            cout << "Do not take this onion to the lab!" << endl;
        } else {
            cout << "Take this onion to the lab!" << endl;
        }
    }
    
    return 0;
}
