#include <iostream>
using namespace std;

int findmax1(int arr[], int arrlen) {
    int max = arr[0];
    for (int i = 1; i < arrlen; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int digit(int arr[], int arrlen) {
    int d = 0;
    int maxnum = findmax1(arr, arrlen);
    while (maxnum != 0) {
        maxnum = maxnum / 10;
        d++;
    }
    //cout << "最大值的位数是：" << d << endl;
    return d;
}

void radix(int arr[], int arrlen) {
    int maxdigit = digit(arr, arrlen);
    int num;   // 对应的是数值位数对应的值
    int Y = 1;
    // 构建桶即二维数组,第一维是桶的序号，第二维是每个桶的大小 即能放多少数 ，每个桶的第一个元素用于记录该个桶中元素的个数 
    int b[10][100];
    // i表示位数
    for (int i = 1; i <= maxdigit; i++) {  // 修改循环条件
        // 清空桶的标记， 
        for (int j = 0; j < 10; j++) {
            b[j][0] = 0;
        }
        // 将原数组的数据放入对应的桶b中
        for (int j = 0; j < arrlen; j++) {
            num = arr[j] / Y % 10;
            b[num][0]++;
            b[num][b[num][0]] = arr[j];
            
        }
        // 将b中的数据依次拿出放置原数组中
        int a_len = 0;
        for (int n = 0; n < 10; n++) {
            for (int m = 1; m <= b[n][0]; m++) {
                arr[a_len++] = b[n][m];
            }
        }
        Y = Y * 10;
    }
    
    // 输出最终排序结果
    for (int k = 0; k < arrlen; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = { 65,98,654,321,145,852,9522,1,6,854,741,2585,950,753,654,325 };
    int arrlen = sizeof(arr) / sizeof(arr[0]);

    radix(arr, arrlen);

    return 0;
}
