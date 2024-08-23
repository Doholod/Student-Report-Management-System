#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <vector>

using std::cout;
using std::cin;
using std::string;

class Rating;
class Student;
struct size;

void list_students(size& s);
void add_new_student(size& s);
void read_students(std::vector<Student>& s);
void read_rating(std::vector <Rating>& r);
void show_rating_sudents(size& s);

//структукра рейтинга студента
class Rating {
public:
	int id;
	int math;
	int russ;
	int eng;
	int PE;
	int chem;
	int phis;
	int result;
	void resultat() {
		result = (math + russ + eng + PE + chem + phis) / 6;
	}

};

//структукра студента
class Student{
public:
	int id;
	string Name;
	string lastName;
	int Rating;
	string number_phone;

};
//Базовое выравнивание текста
struct size {
	string void_line = "                              \n";
	string tab = "               ";
	string between = "-------------------------------------";
};


//Измени COLOR на 12, чтобы норм текст был
int main() {
	bool exiteFlag = false;
	system("COLOR 2");//только зеленый текст, черный фон
	//system("COLOR 12"); //обычный фон
	//system("COLOR 14"); //шедевро фон
	while (!exiteFlag) {
		system("cls");
		int command;
		size s;
		cout << s.void_line;
		cout << s.void_line;
		cout << s.void_line;
		cout << s.void_line;
		cout << s.tab << "MENU\n";
		cout << s.tab << "Choose command from show your:\n";
		cout << s.tab << "1. List students\n";
		cout << s.tab << "2. Add new student\n";
		cout << s.tab << "3. Show rating students\n";
		cout << s.tab << "4. Change information about student\n";
		cout << s.tab << "5. Exite\n";
		cout << s.void_line;
		cout << s.void_line;
		cout << s.tab << "Write command (1/2/3/4/5):";
		cin >> command;

		switch (command)
		{
		case 1:
			list_students(s);
			break;
		case 2:
			add_new_student(s);
			break;
		case 3:
			show_rating_sudents(s);
			break;
		case 4:
			break;
		case 5:
			exiteFlag = true;
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}

void list_students(size& s) {
	system("cls");
	std::ifstream f;
	f.open("Students.txt");
	string fg;
	std::vector <Student> students_mass;
	read_students(students_mass);
	cout << s.void_line;
	cout << s.void_line;
	for (size_t i = 0; i < students_mass.size(); ++i) {
		cout << s.void_line;
		cout << s.tab << "Id:" << students_mass[i].id << std::endl;
		cout << s.tab << "Name:" << students_mass[i].Name << std::endl;
		cout << s.tab << "Last Name:" << students_mass[i].lastName << std::endl;
		cout << s.tab << "Place in rating:" << students_mass[i].Rating << std::endl;
		cout << s.tab << "Phone:" << students_mass[i].number_phone << std::endl;
		cout << s.tab << s.between;
	}
	cout << s.void_line;
	cout << s.void_line;
	cout << "Enter anything text for continue:";
	cin >> fg;
	return;
}
void read_students(std::vector <Student>& s) {
	std::ifstream f;
	f.open("Students.txt");
	Student stud;
	f.ignore(1000, 'd');
	while (!f.eof()) {
		f.ignore(1000, ' ');
		f >> stud.id;
		f.ignore(1000, ' ');
		f >> stud.Name;
		f.ignore(1000, ' ');
		f >> stud.lastName;
		f.ignore(1000, ' ');
		f >> stud.Rating;
		f.ignore(1000, ' ');
		f >> stud.number_phone;
		f.ignore(1000, 'd');
		s.push_back(stud);

	}
	f.close();
	return;
}
void read_rating(std::vector <Rating>& r) {
	std::ifstream f;
	f.open("Rating.txt");
	Rating rat;
	f.ignore(1000, 'd');
	while (!f.eof()) {
		f.ignore(1000, ' ');
		f >> rat.id;
		f.ignore(1000, ' ');
		f >> rat.math;
		f.ignore(1000, ' ');
		f >> rat.russ;
		f.ignore(1000, ' ');
		f >> rat.eng;
		f.ignore(1000, ' ');
		f >> rat.PE;
		f.ignore(1000, ' ');
		f >> rat.chem;
		f.ignore(1000, ' ');
		f >> rat.phis;
		f.ignore(1000, ' ');
		f >> rat.result;
		f.ignore(1000, 'd');
		r.push_back(rat);

	}
	f.close();
	return;
}
void loading(size& s) {
	system("cls");
	cout << s.void_line << s.void_line << s.tab << "Loading";
	Sleep(200);
	system("cls");
	cout << s.void_line << s.void_line << s.tab << "Loading.";
	Sleep(200);
	system("cls");
	cout << s.void_line << s.void_line << s.tab << "Loading..";
	Sleep(200);
	system("cls");
	cout << s.void_line << s.void_line << s.tab << "Loading...";
	Sleep(200);
	system("cls");
}
//добавлаяет в базу данных нового студента
void add_new_student(size& s) {
	system("cls");
	string fg;
	std::vector <Student> students_mass;
	std::vector <Rating> rating_mass;
	read_students(students_mass);
	read_rating(rating_mass);
	cout << s.void_line<<s.void_line;
	Student stud;

	cout << "Enter name new student: ";
	cin >> stud.Name;
	cout << "Enter last name new student: ";
	cin >> stud.lastName;
	cout << "Enter phone number new student: ";
	cin >> stud.number_phone;
	stud.id = students_mass.size() + 1;
	Rating rat;
	rat.id = stud.id;

	loading(s);

	cout << s.void_line << s.void_line << s.tab << "Enter rating student every class:\n";
	cout << s.tab<<"Math:";
	cin >> rat.math;
	cout << s.tab << "Russian:";
	cin >> rat.russ;
	cout << s.tab << "English:";
	cin >> rat.eng;
	cout << s.tab << "PE:";
	cin >> rat.PE;
	cout << s.tab << "Chemistry:";
	cin >> rat.chem;
	cout << s.tab << "Phisic:";
	cin >> rat.phis;
	rat.resultat();
	stud.Rating = rat.result;
	students_mass.push_back(stud);
	rat.id = stud.id;
	rating_mass.push_back(rat);

	loading(s);

	//Изменена база данных Student.txt
	std::ofstream fv;
	fv.open("Students.txt");
	fv.clear();
	for (int i = 0; i < students_mass.size(); ++i) {
		fv << "id: " << students_mass[i].id << '\n';
		fv << "Name: " << students_mass[i].Name << '\n';
		fv << "Last_name: " << students_mass[i].lastName<< '\n';
		fv << "Place_in_rating: " << students_mass[i].Rating << '\n';
		fv << "Phone: " << students_mass[i].number_phone << '\n';
		fv << s.between<<'\n';
	}
	fv.close();

	//Изменена база данных Rating.txt
	fv.open("Rating.txt");
	fv.clear();
	for (int i = 0; i < rating_mass.size(); ++i) {
		fv << "Id " << rating_mass[i].id << '\n';
		fv << "Math " << rating_mass[i].math << '\n';
		fv << "Russ " << rating_mass[i].russ << '\n';
		fv << "Eng " << rating_mass[i].eng << '\n';
		fv << "PE " << rating_mass[i].PE << '\n';
		fv << "Chem " << rating_mass[i].chem << '\n';
		fv << "Phis " << rating_mass[i].phis << '\n';
		fv << "Result " << rating_mass[i].result << '\n';
		fv << s.between << '\n';
	}
	cout << s.void_line << s.void_line << s.tab << "Correct did new student";
	Sleep(1000);
	system("cls");
	return;
}

void show_rating_sudents(size& s) {
	system("cls");
	string fg;
	std::vector<Rating> rat_mass;
	read_rating(rat_mass);
	cout << s.void_line;
	cout << s.void_line;
	for (int i = 0; i < rat_mass.size(); ++i) {
		cout<<s.tab << "Id: " << rat_mass[i].id << '\n';
		cout << s.tab << "Math: " << rat_mass[i].math << '\n';
		cout << s.tab << "Russian: " << rat_mass[i].russ << '\n';
		cout << s.tab << "English: " << rat_mass[i].eng << '\n';
		cout << s.tab << "PE: " << rat_mass[i].PE << '\n';
		cout << s.tab << "Chemistry: " << rat_mass[i].chem << '\n';
		cout << s.tab << "Phisic: " << rat_mass[i].phis << '\n';
		cout << s.tab << "Result: " << rat_mass[i].result << '\n';
		cout<<s.tab <<s.between << '\n';
	}
	cout << s.tab<<"Enter anything text for continue:";
	cin >> fg;
	return;

}