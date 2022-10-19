#include <iostream>
#include <fstream>
using namespace std;

void Check_Tags(string file);   //проверка тегов
void Chack_Hooks(string file);  //проверка острых скобок



int main()
{
	string file;

	cout << "Enter the path to the file: ";
	cin >> file;
	
	Check_Tags(file);
	Chack_Hooks(file);
}


//проверка тегов
void Check_Tags(string file) {
	string str[20];
	string temp;
	int i = 0;
	fstream obj_file(file, ios::in);
	
	if (obj_file)
	{
		while (!obj_file.eof())   //записываем теги в массив
		{
			obj_file >> temp;
			if (temp == "<html" || temp == "</html>" || temp == "<head>" || temp == "</head>" || temp == "<title>" || temp == "</title>" || temp == "<body>" || temp == "</body>")
			{
				str[i] = temp;
				i++;
			}
		}
	}
	else cout << "Could not open the file" << endl;


	if (str[0] != "<html" && str[7] != "</html>")     //сверяем теги в массиве
	{
		cout << "Error in tag html" << endl;
	}
	else if (str[1] != "<head>" && str[4] != "</head>")
	{
		cout << "Error in tag head" << endl;
	}
	else if (str[2] != "<title>" && str[3] != "</title>")
	{
		cout << "Error in tag title" << endl;
	}
	else if (str[5] != "<body>" && str[6] != "</body>")
	{
		cout << "Error in tag body" << endl;
	}
	else
	{
		cout << "No errors in tags" << endl;
	}
}



//проверка острых скобок
void Chack_Hooks(string file)
{
	char character = '\0';
	bool a = true;

	fstream obj_file(file, ios::in);
	if (obj_file)
	{
		while (!obj_file.eof() && a)
		{
			obj_file.get(character);      //считываем посимвольно
			if (character == '<')         //если находим <, то смещаемся на символ вперёд и проверяем далее на >
			{
				obj_file.seekg(1, ios::cur);
				while (!obj_file.eof())
				{
					obj_file.get(character);
					if (character == '>') break;

					else if (character == '<')
					{
						cout << "Error in hooks";
						a = false;
						break;
					}
				}
			}
			if (obj_file.eof()) cout << "No errors in hooks";
		}
	}
	else cout << "Could not open the file" << endl;
}