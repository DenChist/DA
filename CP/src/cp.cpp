#include <iostream>
#include <vector>

class LZ77 {
public:
    struct Node {
        int offset;
        int size;
        char symbol;
    };
    
    static inline const char EOM = ' ';

    static void Encode(std::string& input, std::vector<LZ77::Node>& output) {
        int pos = 0;
        while (pos < input.size()) {
            LZ77::Node n = {0, 0, input[pos]};

            for (int i = 0; i < pos; i++) {
                if (input[i] != input[pos]) {
                    continue;
                }
                int size = 1;
                while (pos + size < input.size() && input[i + size] == input[pos + size]) {
                    size++;
                }
                if (size >= n.size) {
                    n.size = size;
                    n.offset = pos - i;
                }
            }

            if (pos + n.size >= input.size()) {
                n.symbol = LZ77::EOM;
            }
            else {
                n.symbol = input[pos + n.size];
            }
            output.push_back(n);
            pos += n.size + 1;
        }
    }

    static void Decode(std::vector<LZ77::Node>& input, std::string& output) {
        for (LZ77::Node& n : input) {
            if (n.offset != 0) {
                int pos = output.size();
                for(int i = 0; i < n.size; i++) {
                    output.push_back(output[pos - n.offset + i]);
                }
            }
            
            if (n.symbol != EOM) {
                output.push_back(n.symbol);
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    
    std::string cmd;
    std::cin >> cmd;
    
    if (cmd == "compress") {
        std::string text;
        std::cin >> text;

        std::vector<LZ77::Node> res;
        LZ77::Encode(text, res);

        for (LZ77::Node& n : res) {
            std::cout << n.offset << " " << n.size << " " << n.symbol << "\n";
        }
    }

    if (cmd == "decompress") {
        std::vector<LZ77::Node> code;
        LZ77::Node n;
        while (std::cin >> n.offset >> n.size) {
            if (!(std::cin >> n.symbol)) {
                n.symbol = LZ77::EOM;
            }
            code.push_back(n);
        }
        
        std::string res;
        LZ77::Decode(code, res);

        std::cout << res << "\n";
    }

    return 0;
}
