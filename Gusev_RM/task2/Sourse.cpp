#include <iostream>
#include <array>
#include <string>
#include <locale.h>
#include <windows.h>
class kalendar {
	std::array<std::array<int, 4>, 30> kalend = {};
	std::array<std::string, 30> sobytia = {};
	int chek = 0;
public:
	void yst_sob() {
		std::cout << "Введите название события" << "\n";
		std::string name;
		std::cin.ignore();
		std::getline(std::cin, name);
		int god,mes,den;
		std::cout << "Введите год события" << "\n";
		std::cin >> god;
		std::cout << "Введите номер месяца события" << "\n";
		std::cin >> mes;
		std::cout << "Введите день события" << "\n";
		std::cin >> den;
		for (int i = 0; i <= 30; i++) {
			if (sobytia[i] == "" && chek<30) {
				sobytia[i] = name;
				kalend[i][0] = i + 1;
				kalend[i][1] = god;
				kalend[i][2] = mes;
				kalend[i][3] = den;
				chek += 1;
				break;
			}
			if (chek==30){
				std::cout << "Предел событий!!!\n\n";
				break;
			}
			
		}
	}
	void raznicha() {
		int nom;
		std::cout << "\n";
		for (int i = 0; i < chek; i++) {
			std::cout << i + 1 << " - " << sobytia[i] << "\n";
		}
		std::cout << "Введите номер события с которым хотите сравнить\n\n";
		std::cin >> nom;
		int god, mes, den;
		std::cout << "Введите год\n";
		std::cin >> god;
		std::cout << "Введите номер месяца\n";
		std::cin >> mes;
		std::cout << "Введите день\n";
		std::cin >> den;
		std::cout << "Разница:\n" << "В годах - " << abs(kalend[nom - 1][1] - god) << "\n"\
			<< "В месяцах - " << abs(kalend[nom - 1][2] - mes) << "\n"\
			<< "В днях - " << abs(kalend[nom - 1][3] - den)<<"\n\n";
	}
	void smeshenie() {
		int nom, nom1, param, param2;
		bool izm = true;
		std::cout << "\n";
		for (int i = 0; i < chek; i++) {
			std::cout << i + 1 << " - " << sobytia[i] << "\n";
		}
		std::cout << "Введите номер события которое хотите изменить\n\n";
		std::cin >> nom;
		nom -= 1;
		while (izm){
			std::cout << "Введите номер который хотите сместить\n";
			std::cout << "1 - Год" << "\n" << "2 - Месяц\n" << "3 - День\n"<<"4 - Выйти\n\n";
			std::cin >> nom1;
			if (nom1 == 4) {
				break;
			}
			std::cout << "Введите смещение\n\n";
			std::cin >> param;
			std::cout << "1 - Вверх\n2 - Вниз\n\n";
			std::cin >> param2;
			if (param2 == 1) {
				if (nom1 == 1) {
					kalend[nom][1] += param;
				}
				if (nom1 == 2) {
					kalend[nom][2] += param;
				}
				if (nom1 == 3) {
					kalend[nom][3] += param;
				}
			}
			else{
				if (nom1 == 1) {
					kalend[nom][1] -= param;
				}
				if (nom1 == 2) {
					kalend[nom][2] -= param;
				}
				if (nom1 == 3) {
					kalend[nom][3] -= param;
				}
			}		
		}
	}
	void print() {
		int nom;
		std::cout << "\n";
		for (int i = 0; i < chek; i++) {
			std::cout << i+1<< " - " << sobytia[i] << "\n";
		}
		std::cout << "введите номер события про которое хотите узнать\n\n";
		std::cin >> nom;
		std::cout << sobytia[nom-1] <<"\n";
		std::cout << "Год-" << kalend[nom-1][1] << "\n"\
			<< "Месяц-" << kalend[nom-1][2] << "\n" << "День-" << kalend[nom-1][3] << "\n\n";
	}
	~kalendar(){}
};
int main(){
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	kalendar kalend;
	bool chek = true;
	while (chek){
		int deyst;
		std::cout << "Выберите действие\n" << "1 - Ввести событие \n"\
			<< "2 - Посмотреть события\n"<<"3 - Посчитать разницу\n"<<"4 - Изменить событие\n" << "5 - Выйти\n\n";
		std::cin >> deyst;
		if (deyst == 1) {
			kalend.yst_sob();
		}
		if (deyst == 2) {
			kalend.print();
		}
		if (deyst == 3) {
			kalend.raznicha();
		}
		if (deyst == 4) {
			kalend.smeshenie();
		}
		if (deyst == 5) {
			break;
		}
	}
	system("pause");
	return 0;
}