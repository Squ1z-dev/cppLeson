#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void write(string & file, string text) {
	fstream obj;
	obj.open(file, ios::out);
	obj << text << endl;
}
void read(string& file){
	fstream obj;
	obj.open(file, ios::in);
	if (obj.is_open()) {
		string txt;
		while (getline(obj, txt)) {
			cout << txt<< " ";

		}
		obj.close();
	}
	else {
		cout << "Crit eror";
	}
}
void random(string& file) {
	fstream obj;
	obj.open(file, ios::out);
	
	for (size_t i = 0; i < 10; i++)
	{
		obj << rand() % 50 + 1 << endl;
	}
	obj.close();
}
struct Student { 
	string name;
	int age;
	bool lovecpp;
	void writeToFile(string& file) {
		
		fstream obj;
		obj.open(file, ios::app);
		if (obj.is_open()) {

			

			obj << name << " " << age << " " << lovecpp << endl;
			obj.close();
		}
		else {
			obj.open(file, ios::out);
			return writeToFile(file);
		}

	}
};
int main()
{
	
	string nameFile = "IIIIII.txt";
	random(nameFile);
	read(nameFile);



	Student stud1 = { "Maks", 16, true };
	stud1.writeToFile(nameFile);
	read(nameFile);



	Student group[3] = {
		{"Misha", 15, true},
		{"Maks" , 14, false},
		{"Nika", 14, false}
	};

	string nameFile2 = "student.txt";
	for (size_t i = 0; i < 3; i++)
	{
		group[i].writeToFile(nameFile2);
		
	}
 
	
	/*fstream obj;
	obj.open("IIIIII.txt", ios::out);

		obj << "Hellow wirld " << endl;
		obj.close();
	
	obj.open("IIIIII.txt", ios::in);
	string txt;
	while (getline(obj, txt)) {
		cout << txt;
	}
	obj.close();*/

}

