#include <iostream>
#include <time.h>
#include <locale.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

/*int main(void)
{
    clock_t start, end; // объявляем переменные для определения времени выполнения
    int** matra;
    int m = 1000;
    int n = 1000;
    cout << "m = " << m << endl << "n = " << n << endl;
    matra = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        matra[i] = (int*)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matra[i][j] = rand() % 101 + 1;
        }
    }
    cout << endl;
    int** matrb;
    matrb = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        matrb[i] = (int*)malloc(sizeof(int) * n);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrb[i][j] = rand() % 101 + 1;
        }
    }
    int** matrc;
    matrc = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++)
    {
        matrc[i] = (int*)malloc(sizeof(int) * n);
    }
    start = clock();
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            k = 0;
            for (int r = 0; r < m; r++)
            {
                k += matra[i][r] * matrb[r][j];
                matrc[i][j] = k;
            }
        }
    }
    end = clock();
    cout << "Raznica: " << (end - start) / 1000.0;
    return(0);
}*/

// Функция сравнения для qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}


void shell(int* items, int count) {

    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}


void qs(int* items, int left, int right) { //вызов функции: qs(items, 0, count-1);

    int i, j;
    int x, y;



    i = left; j = right;

    //выбор компаранда
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}



int main(void)
{
    setlocale(LC_ALL, "");

    clock_t start, end;

    int* mass;
    int n = 200011;

    mass = (int*)malloc(n * sizeof(int));

    char ch;

    do
    {
        system("cls");

        cout << "1. Случайный набор (Шелл)" << endl << "2. Прямая последовательность (Шелл)" << endl << "3. Обратная последовательность (Шелл)" << endl << "4. Половина прямая, половина обратная (Шелл)" << endl << "5. Случайный набор (qsort)" << endl << "6. Прямая последовательность (qsort)" << endl << "7. Обратная последовательность (qsort)" << endl << "8. Половина прямая, половина обратная (qsort)" << endl;

        ch = _getch();

        switch (ch) {
        case '1':
            system("cls");
            for (int i = 0; i < 11; i++)
            {
                mass[i] = rand() % 101 + 1;
            }

            start = clock();
            shell(mass, n);
            end = clock();

            cout << endl << "Время сортировки Шелла (10): " << (end - start) / 1000.0 << endl;

            for (int i = 0; i < 101; i++)
            {
                mass[i] = rand() % 101 + 1;
            }

            start = clock();
            shell(mass, n);
            end = clock();

            cout << endl << "Время сортировки Шелла (100): " << (end - start) / 1000.0 << endl;

            for (int i = 0; i < 1001; i++)
            {
                mass[i] = rand() % 101 + 1;
            }

            start = clock();
            shell(mass, n);
            end = clock();

            cout << endl << "Время сортировки Шелла (1000): " << (end - start) / 1000.0 << endl;

            system("pause");

            break;
        case '2':
            system("cls");

            for (int i = 0; i < 11; i++)
            {
                mass[i] = i + 1;
            }

            start = clock();
            shell(mass, n);
            end = clock();

            cout << endl << "Время сортировки Шелла (10): " << (end - start) / 1000.0 << endl;
            for (int i = 0; i < 101; i++)
            {
                mass[i] = i + 1;
            }

            start = clock();
            shell(mass, n);
            end = clock();

            cout << endl << "Время сортировки Шелла (100): " << (end - start) / 1000.0 << endl;
            for (int i = 0; i < 1001; i++)
            {
                mass[i] = i + 1;
            }

            start = clock();
            shell(mass, n);
            end = clock();

            cout << endl << "Время сортировки Шелла (1000): " << (end - start) / 1000.0 << endl;

            system("pause");

            break;
        case '3':
            system("cls");

            for (int i = 0; i < 11; i++)
            {
                mass[i] = 11 - i;
            }

            start = clock();
            shell(mass, n);
            end = clock();

            cout << endl << "Время сортировки Шелла (10): " << (end - start) / 1000.0 << endl;

            for (int i = 0; i < 101; i++)
            {
                mass[i] = 101 - i;
            }

            start = clock();
            shell(mass, n);
            end = clock();

            cout << endl << "Время сортировки Шелла (100): " << (end - start) / 1000.0 << endl;

            for (int i = 0; i < 1001; i++)
            {
                mass[i] = 1001 - i;
            }

            start = clock();
            shell(mass, n);
            end = clock();

            cout << endl << "Время сортировки Шелла (1000): " << (end - start) / 1000.0 << endl;

            system("pause");

            break;
        case '4':
            system("cls");

            for (int i = 0; i < 5; i++)
            {
                mass[i] = i + 1;
            }

            for (int i = 5; i < 11; i++)
            {
                mass[5 + i] = 5 - i;
            }

            start = clock();
            shell(mass, n);
            end = clock();

            cout << endl << "Время сортировки Шелла (10): " << (end - start) / 1000.0 << endl;

            for (int i = 0; i < 51; i++)
            {
                mass[i] = i + 1;
            }

            for (int i = 51; i < 101; i++)
            {
                mass[51 + i] = 51 - i;
            }

            start = clock();
            shell(mass, n);
            end = clock();

            cout << endl << "Время сортировки Шелла (100): " << (end - start) / 1000.0 << endl;

            for (int i = 0; i < 501; i++)
            {
                mass[i] = i + 1;
            }

            for (int i = 501; i < 1001; i++)
            {
                mass[501 + i] = 501 - i;
            }

            start = clock();
            shell(mass, n);
            end = clock();

            cout << endl << "Время сортировки Шелла (1000): " << (end - start) / 1000.0 << endl;

            system("pause");

            break;
        case '5':
            system("cls");

            for (int i = 0; i < 11; i++) {
                mass[i] = rand() % 101 + 1;
            }

            start = clock();
            qsort(mass, n, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки qsort (10): " << (end - start) / 1000.0 << endl;

            for (int i = 0; i < 101; i++)
            {
                mass[i] = rand() % 101 + 1;
            }

            start = clock();
            qsort(mass, n, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки qsort (100): " << (end - start) / 1000.0 << endl;

            for (int i = 0; i < 10001; i++)
            {
                mass[i] = rand() % 101 + 1;
            }

            start = clock();
            qsort(mass, n, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки qsort (1000): " << (end - start) / 1000.0 << endl;

            system("pause");

            break;
        case '6':
            system("cls");

            for (int i = 0; i < 11; i++)
            {
                mass[i] = i + 1;
            }

            start = clock();
            qsort(mass, n, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки qsort (10): " << (end - start) / 1000.0 << endl;

            for (int i = 0; i < 101; i++)
            {
                mass[i] = i + 1;
            }

            start = clock();
            qsort(mass, n, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки qsort (100): " << (end - start) / 1000.0 << endl;

            for (int i = 0; i < 10001; i++)
            {
                mass[i] = i + 1;
            }

            start = clock();
            qsort(mass, n, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки qsort (1000): " << (end - start) / 1000.0 << endl;

            system("pause");

            break;
        case '7':
            system("cls");

            for (int i = 0; i < 11; i++)
            {
                mass[i] = 11 - i;
            }

            start = clock();
            qsort(mass, n, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки qsort (10): " << (end - start) / 1000.0 << endl;

            for (int i = 0; i < 101; i++)
            {
                mass[i] = 101 - i;
            }

            start = clock();
            qsort(mass, n, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки qsort (100): " << (end - start) / 1000.0 << endl;

            for (int i = 0; i < 10001; i++)
            {
                mass[i] = 10001 - i;
            }

            start = clock();
            qsort(mass, n, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки qsort (1000): " << (end - start) / 1000.0 << endl;

            system("pause");

            break;
        case '8':
            system("cls");

            for (int i = 0; i < 5; i++)
            {
                mass[i] = i + 1;
            }

            for (int i = 5; i < 11; i++)
            {
                mass[5 + i] = 5 - i;
            }

            start = clock();
            qsort(mass, n, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки qsort (10): " << (end - start) / 1000.0 << endl;

            for (int i = 0; i < 51; i++)
            {
                mass[i] = i + 1;
            }

            for (int i = 51; i < 101; i++)
            {
                mass[51 + i] = 51 - i;
            }

            start = clock();
            qsort(mass, n, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки qsort (100): " << (end - start) / 1000.0 << endl;

            for (int i = 0; i < 501; i++)
            {
                mass[i] = i + 1;
            }

            for (int i = 501; i < 1001; i++)
            {
                mass[501 + i] = 501 - i;
            }

            start = clock();
            qsort(mass, n, sizeof(int), compare);
            end = clock();

            cout << endl << "Время сортировки qsort (1000): " << (end - start) / 1000.0 << endl;
            system("pause");

            break;
        }


    } while (ch != 27);


    free(mass);

    return 0;
}