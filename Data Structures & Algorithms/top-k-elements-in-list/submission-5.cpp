class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Tối ưu 1: Dùng vòng lặp range-based for để code ngắn và nhanh hơn
        unordered_map<int, int> repeated;
        for (int num : nums) {
            repeated[num]++;
        }
        
        // Tối ưu 2: Khởi tạo vector trực tiếp từ map, tránh tạo mảng phụ không cần thiết
        vector<pair<int, int>> frequency(repeated.begin(), repeated.end());
        
        // Tối ưu 3: Thay vì sort toàn bộ danh sách, chỉ cần sort K phần tử lớn nhất (Tiết kiệm thời gian)
        nth_element(frequency.begin(), frequency.begin() + k, frequency.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second;
            });

        // Tối ưu 4: Khởi tạo trước kích thước mảng kết quả để tránh tốn thời gian reallocation
        vector<int> storage;
        storage.reserve(k);
        for (int i = 0; i < k; i++) {
            storage.push_back(frequency[i].first);
        }

        return storage;  
    }
};
