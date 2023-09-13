#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void create(int amount, int type, int* arr) {
    int k = amount;
    switch (type) {
    case 1:
        srand(time(NULL));
        for (int i = 0; i < amount; i++)
            arr[i]=  rand() % 2001 - 1000;
        break;
    case 2:
        for (int i = 0; i < amount; i++)
            arr[i] = i;
        break;
    case 3:
        for (int i = 0; i < amount; i++) {
            arr[i] = k;
            k--;
        }
        break;
    case 4:
        for (int i = 0; i < amount / 2; i++) 
            arr[i] = i;
        
        for (int i = amount / 2; i < amount; i++) 
            arr[i] = amount - i;
        
        break;
    }
}

void shell(int* items, int count)
{

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

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
    int i, j;
    int x, y;

    i = left; j = right;

    /* выбор компаранда */
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

int comp(const void* x1, const void* x2)   // функция сравнения элементов массива
{
    return (*(int*)x1 - *(int*)x2);         
}


int main() {
    int size = 0;
    int type = 0;
    int* arr;
    int n = 0;
    bool close = false;
    clock_t start, end;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (!close) {
        system("cls");
        do {
            printf("[1]Сортировка Шелла\n[2]Быстрая Сортировка\n[3]qsort\n\n[0]Выход\n");
            scanf("%d", &n);
            system("cls");
        } while (n < 0 && n > 3);
        if (n == 0) {
            close = true;
            break;
        }
        printf("Введите кол-во элементов: ");
        scanf("%d", &size);
        do {
            printf("1 - случайный\n2 - отсортированный\n3 - в обратном порядке\n4 - /\\\nВыберите вид входного массива : ");
            scanf("%d", &type);
        } while (type > 4 && type < 1);
        arr = (int*)malloc(size * sizeof(int));

        create(size, type, arr);

        start = clock();
        double seconds;
        switch (n) {
        case 1:
            shell(arr, size);
            end = clock();
            seconds = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Сортировка Шелла: %f\n", seconds);
            break;
        case 2:
            qs(arr, 0, size - 1);
            end = clock();
            seconds = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Быстрая сортировка: %f\n", seconds);
            break;
        case 3:
            qsort(arr, size, sizeof(int), comp);
            end = clock();
            seconds = (double)(end - start) / CLOCKS_PER_SEC;
            printf("qsort: %f\n", seconds);
            break;
        }
        system("pause");
    }
    return 0;
}

