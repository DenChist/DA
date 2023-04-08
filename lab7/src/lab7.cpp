#include <iostream>
#include <vector>

const int OP_MINUS_ONE = 0;
const int OP_DIVIDE_TWO = 1;
const int OP_DIVIDE_THREE = 2;

int main() {
    int n;
    std::cin >> n;
    std::vector<int> coast(n + 1);
    std::vector<int> res(n + 1);

    for (int i = 2; i <= n; i++) {
        coast[i] = coast[i - 1] + i;
        res[i] = OP_MINUS_ONE;

        if (i % 2 == 0 && coast[i / 2] + i < coast[i]) {
            coast[i] = coast[i / 2] + i;
            res[i] = OP_DIVIDE_TWO;
        }
        if (i % 3 == 0 && coast[i / 3] + i < coast[i]) {
            coast[i] = coast[i / 3] + i;
            res[i] = OP_DIVIDE_THREE;
        }

    }    
    std::cout << coast.back() << '\n';
    
    for (int i = n; i > 1;) {
        switch (res[i]) {
            case OP_MINUS_ONE:
                std::cout << "-1";
                i--;
                break;
            case OP_DIVIDE_TWO:
                std::cout << "/2";
                i /= 2;
                break;
            case OP_DIVIDE_THREE:
                std::cout << "/3";
                i /= 3;
            break;
        }
        if (i != 1) {
            std::cout << " ";
        }
    }
    std::cout << '\n';
	
    return 0;
}