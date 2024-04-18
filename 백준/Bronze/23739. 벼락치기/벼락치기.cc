#include <stdio.h>

int main(void)
{
    int n;
    int sum = 0, cnt = 0;
    int arr[101] = {0};

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);

        if ((arr[i] + 1) / 2 <= 30 - sum)
        {
            cnt++;
        }
        sum += arr[i];
        if (sum >= 30)
        {
            sum = 0;
        }
    }
    printf("%d", cnt);
}