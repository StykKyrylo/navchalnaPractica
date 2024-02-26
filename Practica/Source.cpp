#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#define A 100
#pragma warning(disable :4996)
#define _CRT_SECURE_NO_WARNINGS
FILE* f;
struct  CAR
{
	char mark[20];
	char number[20];
	char capacity[20];
};

struct ROAD
{
	char point[20];
	char datedis[40];
	char datearr[40];
};
struct  Futo
{
	CAR car;
	ROAD road;
	char uncost[20];
	char totcost[20];
};
Futo* read_struct(Futo* z, int* N);
void add_to_file(Futo* z, int j);// добавить к файлу
void sorting(Futo* z, int j);// сортировка
void delete_data(Futo* z, int j);


void edit_record(Futo* z, int i);// редактирование
void edit_data(Futo* z, int j);
void search_by_factor(Futo* z, int j);
void show_by_factor(Futo* z, int j);
void display_rec(Futo* z, int j);
void display_1_rec(Futo z, int i);
void menu(Futo* z, int i);
void add_record(Futo* str, int i);


int main()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	setlocale(LC_ALL, "Rus");
	Futo z[A];
	int i = 0;
	menu(z, i);
	_getch;
}
void add_record(Futo* z, int i)
{
	char trick[10];
	printf("\t\t\tМарка автомобиля:"); gets_s(trick); gets_s(z[i].car.mark);
	printf("\t\t\tНомер автомобиля:"); gets_s(z[i].car.number);
	printf("\t\t\tПункт назначения:"); gets_s(z[i].car.capacity);
	printf("\t\t\tГрузоподьемность(т):"); gets_s(z[i].uncost);
	printf("\t\t\tСтоимость единицы груза:"); gets_s(z[i].road.point);
	printf("\t\t\tОбщая стоимость груза:"); gets_s(z[i].road.datedis);
	printf("\t\t\tДата отправления:"); gets_s(z[i].road.datearr);
	printf("\t\t\tДата прибытия:"); gets_s(z[i].totcost);
	i++;
	menu(z, i);
}
void menu(Futo* z, int i)
{
	int sw;
	Futo* arr1 = NULL;
	printf("\t\t\t|1|   - |Список|\n");
	printf("\t\t\t|2|   - |Добавить запись|\n");
	printf("\t\t\t|3|   - |Выведение данных за параметром|\n");
	printf("\t\t\t|4|   - |Поиск данных за параметром|\n");
	printf("\t\t\t|5|   - |Сортировка|\n");
	printf("\t\t\t|6|   - |Удалить запись|\n");
	printf("\t\t\t|7|   - |Редактировка|\n");
	printf("\t\t\t|8|   - |Добавить запись к файлу|\n");
	printf("\t\t\t|9|   - |Читать запись с файла|\n");
	printf("\t\t\t|10|  - |Удалить файл|\n");
	printf("\t\t\t|-0-| - |Выход|\n");
	printf("\t\t\t-Введите число:- "); scanf_s("%d", &sw);
	switch (sw)
	{
	case 1: display_rec(z, i); break;
	case 2: add_record(z, i); break;
	case 3: show_by_factor(z, i); break;
	case 4: search_by_factor(z, i); break;
	case 5: sorting(z, i); break;
	case 6: delete_data(z, i); break;
	case 7: edit_data(z, i); break;
	case 8: add_to_file(z, i); break;
	case 9: z = read_struct(z, &i); menu(z, i); break;
	case 10:remove("carsfile.bin"); menu(z, i); break;
	default:break;
	}
}
void display_rec(Futo* z, int j)
{
	for (int i = 0; i < j; i++)
	{
		printf("\nЗапись: %d\nМарка автомобиля: %s\nНомер автомобиля: %s\nПункт назначения: %s\nГрузоподьемность(т): %s\nСтоимость еденицы груза: %s\nОбщая стоимость груза: %s\nДата отправки: %s\nДата прибытия:\n %s\n----------------------------------------------------------------------------------\n", i + 1, z[i].car.mark, z[i].car.number, z[i].car.capacity, z[i].uncost, z[i].road.point, z[i].road.datedis, z[i].road.datearr, z[i].totcost);

	}
	menu(z, j);
}
void show_by_factor(Futo* z, int j)
{
	int task;
	printf("\t\t\t1 - Марка автомобиля\n");
	printf("\t\t\t2 - Номер автомибиля\n");
	printf("\t\t\t3 - Единица стоимость товара\n");
	printf("Введите число: "); scanf_s("%d", &task);
	switch (task)
	{
	case 1:
		for (int i = 0; i < j; i++)
		{
			printf("\t\t\tМарка автомобиля: %s\n", z[i].car.mark);
		}break;
	case 2:
		for (int i = 0; i < j; i++)
		{
			printf("\t\t\tНомер автомибиля: %s\n", z[i].car.number);
		}break;
	case 3:
		for (int i = 0; i < j; i++)
		{
			printf("\t\t\tЕдиница стоимость товара: %s\n", z[i].car.capacity);
		}break;
	default:printf("\t\t\tОшибка!Неверное число!\n");
	}menu(z, j);
}
void search_by_factor(Futo* z, int j)
{
	int task, count = 0, num;
	char trick[10], str[30];
	printf("\t\t\t1 - Марка автомобился\n");
	printf("\t\t\t2 - Номер автомобиля\n");
	printf("\t\t\t3 - Грузоподьемность\n");
	printf("Введите число :"); scanf_s("%d", &task);
	switch (task)
	{
	case 1: printf("\t\t\tВведите имя которое желаете найти:"); gets_s(trick); gets_s(str);
		for (int i = 0; i < j; i++)
			if (strcmp(z[i].car.mark, str) == 0)
			{
				count++;
				if (count == 1)
					display_1_rec(z[i], i);
				else
					display_1_rec(z[i], i);
			}
		if (count == 0)
			printf("\t\t\tНет такой марки автомобиля!\n");
		menu(z, j);
		break;
	case 2:
		printf("\t\t\tВведите номер автомобиля которое желаете найти :");
		gets_s(trick); gets_s(str);
		for (int i = 0; i < j; i++)
			if (strcmp(z[i].car.number, str) == 0)
			{
				count++;
				if (count == 1)
					display_1_rec(z[i], i);
				else display_1_rec(z[i], i);
			}
		if (count == 0)
			printf("\t\t\tТакого номера автомобиля не найдено!\n");
		menu(z, j);
		break;
	case 3:
		printf("\t\t\tВведите Грузоподьемность которую желаете найти:"); gets_s(trick);
		gets_s(str);
		for (int i = 0; i < j; i++)
			if (strcmp(z[i].car.capacity, str) == 0)
			{
				count++;
				if (count == 1)
					display_1_rec(z[i], i);
				else display_1_rec(z[i], i);
			}
		if (count == 0)
			printf("\t\t\tНе найдено!\n");
		menu(z, j);
		break;
	default:printf("\t\t\tОшибка !Неверное число!\n"); menu(z, j);

	}
}
void display_1_rec(Futo z, int i)
{
	printf("nЗапись: %d \nМарка автомобиля: %s\nНомер автомобиля: %s\nПункт назначения: %s\nГрузоподьемность(т): %s\nСтоимость еденицы груза: %s\nОбщая стоимость груза: %s\nДата отправки: %s\nДата прибытия: %s\n----------------------------------------------------------------------------------\n", i + 1, z.car.mark, z.car.number, z.car.capacity, z.uncost, z.road.point, z.road.datedis, z.road.datearr, z.totcost);
}
void edit_data(Futo* z, int j)
{
	int num;
	printf("\t\t\t\nКоличество запросов %d\n", j);
	printf("\t\t\tВведите номер записи которую хотите редактировать :"); scanf_s("%d", &num);
	display_1_rec(z[num - 1], num - 1);
	if (num > j) printf("\t\t\tОшибка!Нету такой записи!\n");
	else edit_record(z, num - 1); menu(z, j);
}
void edit_record(Futo* z, int i)
{
	char trick[10];
	printf("\t\t\tМарка автомобиля:"); gets_s(trick); gets_s(z[i].car.mark);
	printf("\t\t\tНомер автомобиля:"); gets_s(z[i].car.number);
	printf("\t\t\tПункт назначения:"); gets_s(z[i].car.capacity);
	printf("\t\t\tГрузоподьемность(т):"); gets_s(z[i].uncost);
	printf("\t\t\tСтоимость единицы груза:"); gets_s(z[i].road.point);
	printf("\t\t\tОбщая стоимость груза:"); gets_s(z[i].road.datedis);
	printf("\t\t\tДата отправления:"); gets_s(z[i].road.datearr);
	printf("\t\t\tДата прибытия:"); gets_s(z[i].totcost);
}
void delete_data(Futo* z, int j)
{
	int num;
	printf("\nКоличество запросов: %d\n", j);
	printf("Введите номер записи которую желаете удалить :"); scanf_s("%d", &num);
	display_1_rec(z[num - 1], num - 1);
	if (num <= j)
	{
		for (int i = num - 1; i < j - 1; i++)
			z[i] = z[i + 1];
	}
	else printf("Ошибка!Такой записи не существует!\n");
	j--;
	menu(z, j);
}

void sorting(Futo* z, int j)
{
	Futo tmp;
	int task, task1, f1 = 0;
	printf("1 - Марка автомобиля\n");
	printf("2 - Номер автомобиля\n");
	printf("Введите число : "); scanf_s("%d", &task);
	switch (task)
	{
	case 1:
		printf("Введите:\n 1-По убыванию\n2-По возростанию\n"); scanf_s("%d", &task1);
		switch (task1)
		{
		case 1:
			for (int k = 0; k < j; k++)
				for (int i = 0; i < j; i++)
					if (strcmp(z[i].car.mark, z[i + 1].car.mark) > 0)
					{
						tmp = z[i];
						z[i] = z[i + 1];
						z[i + 1] = tmp;

					}
			display_rec(z, j);
		case 2:
			for (int k = 0; k < j; k++)
				for (int i = 1; i < j; i++)
					if (strcmp(z[i].car.mark, z[i - 1].car.mark) > 0)
					{
						tmp = z[i];
						z[i] = z[i - 1];
						z[i - 1] = tmp;
					}
			display_rec(z, j);
		default:printf("Ошибка!Выберите от 1-2!\n");

		}
	case 2:
		printf("Введите:\n1-По упадению \n2-По возростанию\n"); scanf_s("%d", &task1);
		switch (task1)
		{
		case 1:
			for (int k = 0; k < j; k++)
				for (int i = 0; i < j; i++)
					if (strcmp(z[i].car.mark, z[i + 1].car.mark) > 0)
					{
						tmp = z[i];
						z[i] = z[i + 1];
						z[i + 1] = tmp;

					}
			display_rec(z, j);
		case 2:
			for (int k = 0; k < j; k++)
				for (int i = 1; i < j; i++)
					if (strcmp(z[i].car.mark, z[i - 1].car.mark) > 0)
					{
						tmp = z[i];
						z[i] = z[i - 1];
						z[i - 1] = tmp;
					}
			display_rec(z, j);
		default:printf("Ошибка!Выберите от 1-2!\n");

		}
	}

}
void add_to_file(Futo* z, int j)
{
	f = fopen("carsfile.bin", "wb");
	if (f == NULL)
	{
		printf("File doesn't exist!\n");

		menu(z, j);
	}
	else printf("           Success!\n");
	for (int i = 0; i < j; i++)
		fwrite(&z[i], sizeof(Futo), 1, f);
	fclose(f); menu(z, j);
}
Futo* read_struct(Futo* z, int* N)
{
	Futo* arr = NULL;
	FILE* f = fopen("carsfile.bin", "rb");
	if (f == NULL)
	{
		printf("File doesn't exist!\n");
		menu(z, *N);
	}
	else printf("            Success!\n");
	fseek(f, 0, SEEK_END);
	*N = ftell(f) / sizeof(Futo);
	rewind(f);
	arr = (Futo*)malloc(*N * sizeof(Futo));
	fread(arr, sizeof(Futo), *N, f);
	fclose(f);
	return arr;
}
