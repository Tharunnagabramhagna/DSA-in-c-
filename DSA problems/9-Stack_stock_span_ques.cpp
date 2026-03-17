#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> stockSpan(vector<int> &price, vector<int> &ans, stack<int> &s)
{ // T.C = O(n + n) = O(2n) = O(n) and S.C = O(n)
    for (int i = 0; i < price.size(); i++)
    {
        while (s.size() > 0 && price[s.top()] <= price[i])
            s.pop(); // remove lower values

        // starting span value and Edge Case
        if (s.empty())
            ans[i] = i + 1;
        else                      // span found case
            ans[i] = i - s.top(); // i - prevHigh

        s.push(i); // normal insertions
    }
    return ans;
}

int main()
{
    // stock prices
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    // solution
    vector<int> ans(price.size(), 0);
    stack<int> s;

    stockSpan(price, ans, s);
    cout << "Elements of the Span : \n";
    for (int i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}