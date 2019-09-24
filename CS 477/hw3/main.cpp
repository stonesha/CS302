#include <iostream>

#define SIZE 12

void swap(char* a, char* b)
{
	if ((*a == '\0') || (*b == '\0'))
		return;

	char temp = *a;
	*a = *b;
	*b = temp;
}

int min(char x, char y)
{
	return (x < y) ? x : y;
}

void printArr(char a[])
{
	for (int i = 0; i < SIZE; i++)
		std::cout << a[i] << " ";

	std::cout << std::endl;
}

void bubble_sort(char a[])
{

	for (int i = 0; i < SIZE / 2; i++)
	{
		for (int j = i; j < SIZE - i; j++)
		{
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);	
		}
		std::cout << "Left to right pass: ";
		printArr(a);
		for (int j = SIZE - i - 1; j > i; j--)
		{
			if (a[j] < a[j - 1])
				swap(&a[j], &a[j - 1]);
		}
		std::cout << "Right to left pass: ";
		printArr(a);
	}
}

void merge(char a[], int l, int m, int r)
{
	int k = l, i, j;
	int size1 = m - l + 1;
	int size2 = r - m;

	char* left = new char[size1];
	char* right = new char[size2];

	std::cout << "Left Half" << std::endl;
	for (i = 0; i < size1; i++)
	{
		left[i] = a[l + i];
		std::cout << " " << left[i];
	}
	std::cout << std::endl;
		
	std::cout << "Right Half" << std::endl;
	for (j = 0; j < size1; j++)
	{
		right[j] = a[m + 1 + j];
		std::cout << " " << right[j];
	}
	std::cout << std::endl;

	std::cout << "Merging Both Halves" << std::endl;

	i = 0;
	j = 0;

	while (i < size1 && j < size2)
	{
		if (left[i] <= right[j])
		{
			a[k] = left[i];
			i++;
		}
		else
		{
			a[k] = right[j];
			j++;
		}
		k++;
		std::cout << " " << a[k];
	}
	std::cout << std::endl;

	while (i < size1)
	{
		a[k] = left[i];
		i++;
		k++;
	}

	while (j < size2)
	{
		a[k] = right[j];
		j++;
		k++;
	}

	delete[] left;
	delete[] right;
}

void merge_sort(char a[])
{
	for (int i = 1; i <= SIZE - 1; i = 2 * i)
	{
		for (int j = 0; j < SIZE - 1; j += 2 * i)
		{
			int m = j + i - 1;

			int r = min(j + 2 * i - 1, SIZE - 1);

			merge(a, j, m, r);
		}
	}
}

int main() {

	char second[] = "EASYQUESTION";
	char third[] = "ASORTINGEXAMPLE";

	std::cout << "\n\n=====Question 2=====" << std::endl;

	printArr(second);

	bubble_sort(second);

	printArr(second);

	std::cout << "\n\n=====Question 3=====" << std::endl;

	printArr(third);

	merge_sort(third);

	printArr(third);

	return 0;
}