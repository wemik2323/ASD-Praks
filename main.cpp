#include <iostream>
#include <time.h>
using namespace std;
void vivod(int n, int* x);
void randomim(int n, int* x);
void InSort (int n, int* x);
void Shell(int n, int x[]);

int main() {
    system("chcp 65001");
    int n, choice;
    cout << "Введите кол-во элементов\n";
    cin >> n;
    int x[n];
    randomim(n, x);
    vivod(n, x);
    while (true) {
        cout << "Выберите способ сортировки\n"
                "1 - Сортировка выбором\n"
                "2 - Сортировка Шелла\n";
        cin >> choice;
//--------------------------------------------Set time
        clock_t start = clock();

        if (choice == 1) InSort(n, x);
            else if (choice == 2) Shell(n, x);
                else return 0;

        clock_t end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
//--------------------------------------------
        vivod(n, x);
        cout << "Время выполнения цикла - " << seconds << endl;
        randomim(n, x);
    }
}

void randomim(int n, int* x) {
//--------------------------------------------RANDOM ARRAY ELEMS
    for (int i = 0; i < n; i++) {
        x[i] = rand() % (100);
    }
//--------------------------------------------
}

void vivod(int n, int* x)
{
    for (int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
}

void InSort (int n, int* x)
{
    for(int i = 1; i < n; i++)
        for(int j = i;j > 0 && x[j-1] > x[j];j--)
            swap(x[j-1],x[j]);
}

void Shell(int n, int x[]) //Shell's method
{
    int d=n;
    d=d / 2;
    while (d > 0)
    {
        for (int i = 0; i < n-d; i++)
        {
            int j = i;
            while (j >= 0 && x[j] > x[j+d])
            {
                int count = x[j];
                x[j] = x[j+d];
                x[j+d] = count;
                j--;
            }
        }
        d=d/2;
    }
    for (int i=0; i<n; i++) cout << x[i] << " ";
    cout << endl;
}