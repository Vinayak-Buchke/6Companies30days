#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<algorithm>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        for(int i = 0; i < lists.size(); i++){
            ListNode* head = lists[i];
            while(head != nullptr){
                ans.push_back(head->val);
                head = head->next;
            }
        }
        sort(ans.begin(), ans.end(), greater<int>());
        ListNode *answer = NULL;
        for (int x: ans){
            ListNode* temp = new ListNode;
            temp->val = x;
            temp->next = answer;
            answer = temp;
        }
        return answer;
    }
};