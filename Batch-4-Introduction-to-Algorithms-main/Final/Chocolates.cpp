#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll N = 1e3 + 9;
int dp[N][N];
bool equalSum(int n, int s, int ar[])
{
    if (n == 0)
    {
        if (s == 0)
        {
            return 1;
        }
        else
            return 0;
    }
    if (dp[n][s] != -1)
    {
        return dp[n][s];
    }
    if (ar[n] <= s)
    {
        return dp[n][s] =(equalSum(n - 1, s - ar[n], ar)) || (equalSum(n - 1, s, ar));
    }
    else
    {
        return dp[n][s] = equalSum(n - 1, s, ar);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll sum = 0;
        cin >> n;
        int ar[n];
        for (int i = 1; i <= n; i++)
        {
            cin >> ar[i];
            sum += ar[i];
        }
        memset(dp, -1, sizeof(dp));
       
        if (sum % 2 == 0)
        {
            if(equalSum(n, sum / 2, ar)){
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}




// #include <bits/stdc++.h> // সবগুলি প্রিমারি হেডার ফাইল ইমপোর্ট করুন
// #define ll long long int // ll নামক লং লং ইন্টিজার টাইপ ডিফাইন করুন
// using namespace std; // স্ট্যান্ডার্ড নামস্পেস ব্যবহার করুন
// const ll N = 1e3 + 9; // কন্সট্যান্ট ডিফাইন করুন
// int dp[N][N]; // ডাইনামিক প্রোগ্রামিং অ্যারে ডিক্লেয়ার করুন
// bool equalSum(int n, int s, int ar[]) // সমান যোগফল নির্নায়ক ফাংশন
// {
//     if (n == 0) // যদি n শূন্য হয়
//     {
//         if (s == 0) // যদি s শূন্য হয়
//         {
//             return true; // সত্যি রিটার্ন করুন
//         }
//         else
//             return false; // মিথ্যা রিটার্ন করুন
//     }
//     if (dp[n][s] != -1) // যদি প্রিভিওস ক্যালকুলেটেড ডাটা থাকে
//     {
//         return dp[n][s]; // রিটার্ন করুন
//     }
//     if (ar[n] <= s) // যদি বর্তমান সংখ্যাটি s এর সমান বা কম হয়
//     {
//         return dp[n][s] = (equalSum(n - 1, s - ar[n], ar)) || (equalSum(n - 1, s, ar)); // মোট ব্যবহার করুন
//     }
//     else
//     {
//         return dp[n][s] = equalSum(n - 1, s, ar); // মোট ব্যবহার করুন
//     }
// }
// int main()
// {
//     int t; // টেস্ট কেসের সংখ্যা
//     cin >> t; // ইনপুট নিন
//     while (t--)
//     {
//         int n; // সংখ্যাগুলির সংখ্যা
//         ll sum = 0; // যোগফল রাখতে
//         cin >> n; // ইনপুট নিন
//         int ar[n]; // সংখ্যাগুলির জন্য অ্যারে ডিক্লেয়ার করুন
//         for (int i = 1; i <= n; i++) // সংখ্যা প্রদান করুন
//         {
//             cin >> ar[i]; // ইনপুট নিন
//             sum += ar[i]; // যোগ করুন
//         }
//         memset(dp, -1, sizeof(dp)); // ডাইনামিক প্রোগ্রামিং অ্যারেকে আনসেট করুন
       
//         if (sum % 2 == 0) // যদি সংখ্যাগুলির যোগফল জোড় হয়
//         {
//             if(equalSum(n, sum / 2, ar)){ // যদি সমান যোগফল সম্পন্ন হয়
//                 cout << "YES" << endl; // প্রিন্ট করুন
//             }
//             else cout << "NO" << endl; // অন্যথায়, "NO" প্রিন্ট করুন
//         }
//         else
//             cout << "NO" << endl; // যদি যোগফল বিজোড় হয়, "NO" প্রিন্ট করুন
//     }
//     return 0; // প্রোগ্রাম সফলভাবে সমাপ্ত হয়েছে
// }
