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
    //cout << "���ֵ��λ���ǣ�" << d << endl;
    return d;
}

void radix(int arr[], int arrlen) {
    int maxdigit = digit(arr, arrlen);
    int num;   // ��Ӧ������ֵλ����Ӧ��ֵ
    int Y = 1;
    // ����Ͱ����ά����,��һά��Ͱ����ţ��ڶ�ά��ÿ��Ͱ�Ĵ�С ���ܷŶ����� ��ÿ��Ͱ�ĵ�һ��Ԫ�����ڼ�¼�ø�Ͱ��Ԫ�صĸ��� 
    int b[10][100];
    // i��ʾλ��
    for (int i = 1; i <= maxdigit; i++) {  // �޸�ѭ������
        // ���Ͱ�ı�ǣ� 
        for (int j = 0; j < 10; j++) {
            b[j][0] = 0;
        }
        // ��ԭ��������ݷ����Ӧ��Ͱb��
        for (int j = 0; j < arrlen; j++) {
            num = arr[j] / Y % 10;
            b[num][0]++;
            b[num][b[num][0]] = arr[j];
            
        }
        // ��b�е����������ó�����ԭ������
        int a_len = 0;
        for (int n = 0; n < 10; n++) {
            for (int m = 1; m <= b[n][0]; m++) {
                arr[a_len++] = b[n][m];
            }
        }
        Y = Y * 10;
    }
    
    // �������������
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
