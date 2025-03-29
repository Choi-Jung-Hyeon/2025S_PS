#include <bits/stdc++.h>
using namespace std;


int cmp1(const void* a, const void* b) { return strcmp((const char*)a, (const char*)b); }
int cmp2(const void* b, const void* a) { return strcmp((const char*)a, (const char*)b); }

int main()
{
    const char *arr[5] = { "사과", "오렌지", "딸기", "수박", "메로나" };
    qsort(arr, 5, sizeof(*arr), cmp1);
    for (int i = 0; i < 5; i++) printf("%s ", arr[i]);

    puts("");
    qsort(arr, 5, sizeof(*arr), cmp2);
    for (int i = 0; i < 5; i++) printf("%s ", arr[i]);
    return 0;
}