#include <iostream>
#include <random>
#include <sstream>

using namespace std;

/**
 * \brief Функциия инициализации массива
 * \param size - размер массива
 * \return. values - указатель на массив
 */
char* input_values(size_t const size);

/**
 * \brief Функциия вывода массива
 * \param values - указатель на массив, size - размер массива
 * \return. строка, содержащая массив
 */
string output_values(char* values, const size_t size);

/**
 * \brief Функциия нахождения среднего значения массива
 * \param values - указатель на массив, size - размер массива
 * \return. mid - среднее значение массива
 */
char avg_values(char* values, const size_t size);

/**
 * \brief Функциия освобождения памяти от массива
 * \param values - указатель на массив
 */
void delete_values(char*& values);

int main()
{
	setlocale(LC_ALL, "Russian");

	int size;
	cout << "Введите размерность массива: ";
	cin >> size;

	if (size <= 0)
	{
		throw invalid_argument("Ошибка размерности массива!");
	}

	// Создаем массив
	char* values = input_values(size);
	// Выводим полученный массив
	cout << "Полученный массив:\n" << output_values(values, size);
	// Находим среднее значения массива
	cout << "Среднее значение элементов массива: " << avg_values(values, size) << endl;
	// Удаляем массив
	delete_values(values);

	return 0;
}

char* input_values(const size_t size)
{
	char* values = new char[size];

	const size_t min_range = 0;
	const size_t max_range = 26;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> uniformIntDistribution(min_range, max_range);

	for (size_t i = 0; i < size; i++)
	{
		size_t temp = uniformIntDistribution(gen);
		values[i] = temp + 'a';
	}

	return values;
}

string output_values(char* values, const size_t size)
{
	ostringstream tmpStream;

	for (size_t i = 0; i < size; i++)
	{
		tmpStream << values[i] << "\t";
	}
	tmpStream << endl;

	return tmpStream.str();
}

char avg_values(char* values, const size_t size)
{
	size_t summ = 0;

	for (size_t i = 0; i < size; i++)
	{
		summ += values[i];
	}
	char mid = summ / size;

	return mid;
}

void delete_values(char*& values)
{
	if (values != nullptr)
	{
		delete[] values;
		values = nullptr;
	}
}