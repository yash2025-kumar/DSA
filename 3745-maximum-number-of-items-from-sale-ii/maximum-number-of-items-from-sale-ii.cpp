

#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int cheapest = INT_MAX;
        int max_factor = 0;

        // 1. Find the cheapest item price and the maximum factor value
        for (const auto& item : items) {
            max_factor = max(max_factor, item[0]);
            cheapest = min(cheapest, item[1]);
        }

        // 2. Count frequencies of each factor and aggregate multiples (Sieve approach)
        vector<int> freq(max_factor + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }

        for (int i = 1; i <= max_factor; ++i) {
            if (freq[i] > 0) {
                for (int multiple = 2 * i; multiple <= max_factor; multiple += i) {
                    freq[i] += freq[multiple];
                }
            }
        }

        // 3. Group profitable 2-for-1 opportunities by purchase price
        // Buying an item with a freebie yields 2 items, which is only better than 
        // buying the cheapest item twice if cost < 2 * cheapest.
        map<long long, long long> cost_count;
        for (const auto& item : items) {
            long long cost = item[1];
            long long free_items = freq[item[0]] - 1; // Exclude the item itself
            if (free_items > 0 && cost < 2LL * cheapest) {
                cost_count[cost] += free_items;
            }
        }

        // 4. Greedily buy items that yield free copies from lowest to highest cost
        long long total_items = 0;
        long long rem_budget = budget;

        for (const auto& [cost, count] : cost_count) {
            if (rem_budget < cost) break;
            long long buy = min(count, rem_budget / cost);
            total_items += 2 * buy;
            rem_budget -= buy * cost;
        }

        // 5. Spend any remaining budget on the single cheapest item
        total_items += rem_budget / cheapest;

        return static_cast<int>(total_items);
    }
};
