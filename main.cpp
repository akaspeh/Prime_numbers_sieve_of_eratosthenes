#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;
float sizeOfArrayFunc(float count,int countForSum){ // ����������� �������� ���� � ������� n/ln(x)
    if(countForSum==10){                             // � ��������� ������� �������� ��� W-1(x) �� � 2 ��������
        return 1;
    }
    if(countForSum==1){
        float a = sizeOfArrayFunc(count,countForSum+1);
        return log((1/count)/a);
    }
    else{
        float a = sizeOfArrayFunc(count,countForSum+1);
        return -log((1/count)/a);
    }
}



int main() {
    int count;
    cin >> count;
    int sizeforArray=-count * sizeOfArrayFunc(count,1);
    int sizeOfArray = (sizeforArray)/2+1;
    int *arr = new int[sizeOfArray];
    clock_t startTime = clock();
// ��� ���, ��� ��������� ����� ����������
    int x = 0;
    while(x<100000){
        arr[0] = 2;
        for (int number = 3, j = 1; number < sizeforArray; number += 2, j++) { // �������� ����� �� 3 �� ���������� ����� � ������ ���� ��� �� �������
            arr[j] = number;
        }
        for (int placeOfNum = 1, step = 3;
             placeOfNum < sqrt(sizeOfArray); placeOfNum++, step += 2) { // ������ ����������
            if (arr[placeOfNum] != 0) {  // ����� ����� ���� ��� �� 0
                for (int i = placeOfNum + step; i < sizeOfArray; i += step) { // �����, � ��� ������� ����� �����
                    arr[i] = 0;// ����� ������� ���� ����� ���������� 0
                }
            }
        }
        x++;
    }

    clock_t endTime = clock();
    double seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;
    cout << "time:" << seconds << endl;
    for (int i = 0,j=0;j < count; i++){ // ������� �� ��������� �����
        if (arr[i] != 0) {  // ����� ����� ���� ��� �� 0
            cout << arr[i] <<'\t';
            j++;
        }
    }
    delete [] arr;
    return 0;
}