#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 1e3 + 9;
ll dp[N][N];
ll maxProfit(int n, int w, int weight[], int value[])
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    if (weight[n] <= w)
    {
        int op1 = maxProfit(n - 1, w - weight[n], weight, value) + value[n];
        int op2 = maxProfit(n - 1, w, weight, value);
        return dp[n][w] = max(op1, op2);
    }
    else
    {
        return dp[n][w] = maxProfit(n-1, w, weight, value);
    }
}
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, w;
        cin >> n >> w;
        int weight[n], value[n];
        for (int i = 1; i <= n; i++)
        {
            cin >> weight[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> value[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << maxProfit(n, w, weight, value) << endl;
    }
    return 0;
}



// #include <bits/stdc++.h> // সবচেয়ে বেশি ব্যবহৃত হেডার ফাইলগুলি ইমপোর্ট করুন
// #define ll long long int // ll নামক লং লং ইন্টিজার টাইপ ডিফাইন করুন
// using namespace std; // স্ট্যান্ডার্ড নামস্পেস ব্যবহার করুন
// const ll N = 1e3 + 9; // কন্সট্যান্ট ডিফাইন করুন
// ll dp[N][N]; // ডাইনামিক প্রোগ্রামিং অ্যারে ডিক্লেয়ার করুন
// ll maxProfit(int n, int w, int weight[], int value[])
// {
//     if (n == 0 || w == 0) // কেস বের করুন যদি n বা w শূন্য হয়
//     {
//         return 0; // ফলাফল হিসেব করুন
//     }
//     if(dp[n][w]!=-1){ // যদি প্রিভিওস ক্যালকুলেটেড ডাটা থাকে
//         return dp[n][w]; // সেটা রিটার্ন করুন
//     }
//     if (weight[n] <= w) // যদি বর্তমান জিনিসের ওজন অধিকতম ওজনের সমান বা কম হয়
//     {
//         int op1 = maxProfit(n - 1, w - weight[n], weight, value) + value[n]; // বর্তমান জিনিস নিয়ে একটি অপশন নেন
//         int op2 = maxProfit(n - 1, w, weight, value); // বর্তমান জিনিস নিয়ে আরেকটি অপশন নিয়েন
//         return dp[n][w] = max(op1, op2); // সর্বোচ্চ মূল্য রিটার্ন করুন
//     }
//     else
//     {
//         return dp[n][w] = maxProfit(n-1, w, weight, value); // যদি বর্তমান জিনিসের ওজন অধিকতম ওজনের চেয়ে বেশি হয়
//     }
// }
// int main()
// {
//     int tc; // টেস্ট কেসের সংখ্যা নিন
//     cin >> tc; // ইনপুট নিন
//     while (tc--)
//     {
//         int n, w; // জিনিসের সংখ্যা এবং অধিকতম ওজন নিন
//         cin >> n >> w; // ইনপুট নিন
//         int weight[n], value[n]; // জিনিসের ওজন এবং মূল্য ডাটার জন্য অ্যারে ডিক্লেয়ার করুন
//         for (int i = 1; i <= n; i++) // জিনিসের ওজন ইনপুট নিন
//         {
//             cin >> weight[i]; // ইনপুট নিন
//         }
//         for (int i = 1; i <= n; i++) // জিনিসের মূল্য ইনপুট নিন
//         {
//             cin >> value[i]; // ইনপুট নিন
//         }
//         memset(dp, -1, sizeof(dp)); // ডাইনামিক প্রোগ্রামিং অ্যারেকে আনসেট করুন
//         cout << maxProfit(n, w, weight, value) << endl; // ম্যাক্সিমাম মূল্য প্রিন্ট করুন
//     }
//     return 0; // প্রোগ্রাম সফলভাবে সমাপ্ত হয়েছে
// }
