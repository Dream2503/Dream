#include <algorithm>
#include <unordered_map>

int maxValue(const std::string& t) {
    const int size = t.length();
    int res = 0;
    std::unordered_map<std::string, int> hash;

    for (int i = 0; i < size; i++) {
        std::string sub_string(t.begin() + i, t.end());

        for (int j = i; j < size; j++) {
            hash[sub_string]++;
            sub_string.pop_back();
        }
    }
    for (const auto& [key, value] : hash) {
        res = std::max(res, static_cast<int>(key.length()) * value);
    }
    return res;
}
