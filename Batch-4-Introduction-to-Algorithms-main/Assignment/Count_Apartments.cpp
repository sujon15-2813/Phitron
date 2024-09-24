#include <bits/stdc++.h>
using namespace std;
int n, m;
//এই লাইনে দুটি ইন্টিজার ভ্যারিয়েবল n এবং m ডিক্লেয়ার করা হয়েছে। এই দুটি ভ্যারিয়েবল দ্বারা আমরা ম্যাট্রিক্স এর সাইজ প্রাপ্ত করবো।
vector<vector<char>> apprt;
//apprt নামক একটি 2D ভেক্টর ডিক্লেয়ার করা হয়েছে যেখানে আমরা ম্যাট্রিক্স ইনপুট নিয়ে থাকবো।
bool visit[1005][1005];
//visit নামক একটি 2D বুলিয়ান অ্যারে ডিক্লেয়ার করা হয়েছে যেখানে প্রতিটি সেল সংশ্লিষ্ট কিনা তা চেক করবো।
int cnt_aprt = 0;
//একটি ইন্টিজার ভ্যারিয়েবল cnt_aprt ডিক্লেয়ার করা হয়েছে যার মাধ্যমে আমরা ম্যাট্রিক্সের সংখ্যা গণনা করবো। এটি ম্যাট্রিক্সের সংখ্যা সংরক্ষণের জন্য ব্যবহৃত হয়েছে।
void dfs(int x, int y)
{
    int da[] = {-1, 1, 0, 0};
    int db[] = {0, 0, -1, 1};
    visit[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nr = x + da[i];
        int nc = y + db[i];
        if (nc >= 0 && nc < m && nr >= 0 && nr < n && apprt[nr][nc] == '.' && !visit[nr][nc])
        {
            dfs(nr, nc);
        }
    }
}
//এই ফাংশনে dfs হল ডেপথ ফার্স্ট সার্চ যা আমাদের সংযুক্ত উপাদান গুলো সনাক্ত করবে। এই ফাংশনের মাধ্যমে আমরা প্রতিটি সেল এর চারপাশের সকল সেল চেক করবো।
//যেহেতু চারপাশে চেক করা হয়, তাই চারটি ডায়ারেকশনের জন্য ডায়ারেকশন অ্যারে ডিক্লেয়ার করা হয়েছে: da[] এবং db[]।
//প্রথমে বর্তমান সেলে প্রবেশ করে তার ভেতর চিহ্নিত করা হয়েছে সেলে।
//এরপর, প্রতিটি ডায়ারেকশনের জন্য নতুন সেলের অনুসরণ করা হয়। যদি সেলটি বৈধ হয় এবং পূর্বে পরিদর্শিত না হয়ে থাকে তবে নতুন সেলে ফেরত রয়েছে এবং রিকার্সিভলি কল করা হয়।
//এই প্রক্রিয়াটি সম্পূর্ণ প্রতিটি সেলের জন্য প্রয়োজনীয়।
//এই লজিকের উপরে নির্ভর করে, আমরা ম্যাট্রিক্সের প্রতিটি সেলের জন্য DFS কল করি এবং যে সেলগুলি পরিদর্শিত হয় নি, তাদের জন্য নতুন কাউন্ট করি।
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<char> row;
        for (int j = 0; j < m; j++)
        {
            char a;
            cin >> a;
            row.push_back(a);
        }
        apprt.push_back(row);
    }
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (apprt[i][j] == '.' && !visit[i][j])
            {
                dfs(i, j);
                cnt_aprt++;
            }
        }
    }
    cout << cnt_aprt << endl;
    return 0;
}
//মেইন ফাংশনে আমরা ম্যাট্রিক্সের সাইজ প্রাপ্ত করেছি এবং ম্যাট্রিক্স ইনপুট নেয়া হয়