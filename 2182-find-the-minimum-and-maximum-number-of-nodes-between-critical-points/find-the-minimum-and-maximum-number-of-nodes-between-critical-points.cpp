class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;
        ListNode* prev = head;
        ListNode* curr = head->next;
        int index = 1;

        while (curr && curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                critical.push_back(index);
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if (critical.size() < 2)
            return {-1, -1};

        int minDist = INT_MAX;

        for (int i = 1; i < critical.size(); i++) {
            minDist = min(minDist, critical[i] - critical[i - 1]);
        }

        return {minDist, critical.back() - critical.front()};
    }
};