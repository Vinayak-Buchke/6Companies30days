#include <iostream>
#include <unordered_map>
using namespace std;

class BullsAndCows
{
public:
    string getHint(string secret, string guess)
    {
        int n = secret.size();
        unordered_map<int, int> h1;
        int cow = 0;
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
            {
                cow++;
            }
            else
            {
                h1[secret[i]]++;
            }
        }

        int bull = 0;
        for (int i = 0; i < n; i++)
        {
            if (secret[i] == guess[i])
            {
                continue;
            }
            else if (h1.find(guess[i]) != h1.end() && h1[guess[i]] > 0)
            {
                bull++;
                h1[guess[i]]--;
            }
        }
        string ans = to_string(cow) + "A" + to_string(bull) + "B";
        return ans;
    }
};
int main()
{
    string secret = "1807";
    string guess = "7810";
    BullsAndCows obj;
    cout << obj.getHint(secret, guess);
    return 0;
}