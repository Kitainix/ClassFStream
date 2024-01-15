#include <iostream>
#include <fstream>
#include <string>


bool file_insert(std::string path, int pos, std::string str);


int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	const std::string path = "file.txt";
	
	// Класс "fstream" для чтения и записи в файл.
	/*
	std::fstream fs;
	fs.open(path, std::ios::in | std::ios::app); // Открытие файла в нескольких режимах с помощью перегрузки операции битового ИЛИ ( | ).

	if (fs.is_open()) {
		std::cout << "Файл открыт.\n";

		// Ввод данных в файл.
		std::cout << "Введите строку: ";
		std::string str;
		std::getline(std::cin, str);
		fs << str << '\n';

		// Перемещение курсора для считывания в начало файла.
		fs.seekg(0, std::ios::beg);

		// Чтение данных из файла.
		std::cout << "Содержимое файла:\n";
		char sym;
		while (fs.get(sym))
			std::cout << sym;
		std::cout << std::endl;

	}
	else {
		std::cout << "Ошибка открытия файла.\n";
	}

	fs.close();
	*/


	// Задание "Вставка в середину файла".
	/*
	if (file_insert(path, 3, "###"))
		std::cout << "Строка вставлена успешно.\n\n";
	else
		std::cout << "Ошибка выполнения функции.\n\n";
	*/


	// Задача 1. "Парсинг даты".
	std::cout << "Задача 1.\nДата: ";
	std::ifstream in;
	in.open("date.txt");
	if (in.is_open()) {
		std::string date;
		in >> date;
		std::cout << date << std::endl;

		int day = std::stoi(date);
		int month = std::stoi(date.substr(date.find('.') + 1));
		int year = std::stoi(date.substr(date.rfind('.') + 1));

		std::cout << "День: " << day << std::endl;
		std::cout << "Месяц: " << month << std::endl;
		std::cout << "Год: " << year << std::endl;
	}

	in.close();



	return 0;
}


bool file_insert(std::string path, int pos, std::string str) {
	static std::fstream fs;
	fs.open(path, std::ios::in);
	if (!fs.is_open())
		return false;

	std::string file, line; // Строка для содержимого файла (file), строка для построчного считывания (line).

	while (std::getline(fs, line))
		file += line + '\n';
	
	fs.close();

	file.insert(pos, str);

	fs.open(path, std::ios::out);
	if (!fs.is_open())
		return false;

	fs << file;
	fs.close();
	return true;
}
