#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main()

{
	int array[10] = { 0 };
	int i = 0, num, operation, mindiap, maxdiap, prov;
	int min;
	printf("Menu:\n1.Filling in an array using the keyboard\n2.Filling in an array using a randomizer\n \nChose something: ");
	scanf_s("%d", &operation);

	while (operation != 1 && operation != 2)
	{
		rewind(stdin);
		printf("\nWrong operation!\nPls chose something again: ");
		scanf_s("%d", &operation);
	}

	switch (operation)
	{
	case 1:
		while (i < 10)
		{
			printf("\nEnter number %d: ", i);
			prov = scanf_s("%d", &array[i]);

			while (prov <= 0 && prov >= 0)
			{
				rewind(stdin);
				printf("\nWrong number!");
				printf("\nEnter number %d: ", i);
				prov = scanf_s("%d", &array[i]);
			}
			i++;
		}
		break;

	case 2:

		printf("Range of numbers from ");
		scanf_s("%d to %d", &mindiap, &maxdiap);

		for (i = 0; i < 10; i++)
		{
			array[i] = rand() % (maxdiap - mindiap + 1) + mindiap;
			printf("\nNumber %d: %d\n", i, array[i]);
		}
		break;
	}

	min = array[0];

	for (i = 0; i < 10; i++)
	{
		if (min >= array[i])
		{
			min = array[i];
			num = i;
		}
	}

	if (array[9] != min)
	{
		printf("\nNumber: %d", num);
		printf("\nThe minimum number of the array is: %d", min);

		num = num + 1;
		int sum = 0;
		for (num; num < 10; num++)
		{
			sum = sum + abs(array[num]);
		}
		printf("\nAnswer = %d\n", sum);

	}

	else
	{
		printf("\nEROR 404");
	}
	return 0;
}