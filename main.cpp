//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <windows.h>
//
//#define size 4000
//
//void start()
//{
//	setvbuf(stdin, NULL, _IONBF, 0);
//	setvbuf(stdout, NULL, _IONBF, 0);
//
//	clock_t start, end; // объявляем переменные для определения времени выполнения
//
//	int i = 0, j = 0, r;
//	int a[size][size], b[size][size], c[size][size], elem_c;
//	start = clock();
//	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
//	while (i < size)
//	{
//		while (j < size)
//		{
//			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
//			j++;
//		}
//		i++;
//	}
//	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
//	i = 0; j = 0;
//	while (i < size)
//	{
//		while (j < size)
//		{
//			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
//			j++;
//		}
//		i++;
//	}
//
//	for (i = 0; i < size; i++)
//	{
//		for (j = 0; j < size; j++)
//		{
//			elem_c = 0;
//			for (r = 0; r < size; r++)
//			{
//				elem_c = elem_c + a[i][r] * b[r][j];
//				c[i][j] = elem_c;
//			}
//		}
//	}
//	end = clock();
//	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
//	printf("%f\n", seconds);
//
//}
//
//
//int main()
//{
//
//	start();
//
//	system("pause");
//	return 0;
//}
