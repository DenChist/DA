#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

double Area(int s1, int s2, int s3) {
    double p = (s1 + s2 + s3) * 0.5;
    return sqrt(p * (p - s1) * (p - s2) * (p - s3));
}

bool ValidTriangle(int s1, int s2, int s3) {
    return (s1 < (s2 + s3)) && (s2 < (s1 + s3)) && (s3 < (s1 + s2));
}

int main() {
    std::vector<int> data;
    int n = 0;
    int s = 0;
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    double max_area = 0.0;
    double cur_area = 0.0;

    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> s;
        data.push_back(s);
    }

    std::sort(data.begin(), data.end(), std::greater<int>());

    for (int i = 1; i < int(data.size() - 1); ++i) {
        if (data.size() < 3) {
            break;
        }
        if (ValidTriangle(data[i - 1], data[i], data[i + 1])) {
            cur_area = Area(data[i - 1], data[i], data[i + 1]);
            if (cur_area > max_area) {
                max_area = cur_area;
                s1 = data[i + 1];
                s2 = data[i];
                s3 = data[i - 1];
            }
        }
    }

    if (max_area == 0.0) {
        std::cout << 0 << '\n';
    }
    else {
        printf("%.3f\n", max_area);
        std::cout << s1 << ' ' << s2 << ' ' << s3 << '\n';
    }
    return 0;
}