#include <iostream>
#include <math.h>
using namespace std;

int func1(int n)
{

    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int func2(int arr[], int N) {
    int flag = 0;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            if(arr[i] + arr[j] == 100) {
                flag = 1;
            }
        }
    }
    return flag;
}

int func3(unsigned long n) {
    for(unsigned long i=1; i<=sqrt(n); i++) {
        if(i * i == n) {
            return 1;
        }
    }
    return 0;
}

int func4(int n) {
    int result = 1;
    while(2*result <= n) {
//        cout << result << endl;
        result *= 2;
    }
    return result;
}

int main()
{
//    int n;
//    cin >> n;
//    int result = func1(n);
//    cout << result << endl;
//    int arr[] = {4, 13, 63, 87};
//    cout << func2(arr, 4) << endl;
//    cout << func3(693953651) << endl;
    cout << func4(97615282) << endl;
}