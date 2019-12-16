#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector <string> przyjecie_dzialania();
bool czy_dzielenie_lub_mnozenie(vector <string> dane);
bool czy_dodawanie_lub_odejmowanie(vector <string> dane);
vector <string> dzielenie_mnozenie(vector <string> dane);
vector <string> odejmowanie_dodawanie(vector <string> dane);
void wynik(vector <string> dane, vector <string> dane2);

int main()
{
	while (1)
	{
		vector <string> dzialanie_p = przyjecie_dzialania();
		vector <string> dzialanie = dzialanie_p;
		/*for (int i = 0; i < dzialanie.size(); i++)
				cout << dzialanie[i] << "\n";*/
		dzialanie = dzielenie_mnozenie(dzialanie);
		/*for (int i = 0; i < dzialanie.size(); i++)
			cout << dzialanie[i] << "\n";*/
		dzialanie = odejmowanie_dodawanie(dzialanie);
		/*for (int i = 0; i < dzialanie.size(); i++)
			cout << dzialanie[i] << "\n";*/
		wynik(dzialanie_p, dzialanie);
		return 0;
	};
}
	
vector <string> przyjecie_dzialania()
{
	cout << "Wpisz dzialanie do rozwiazania.\n";
	cout << "Odzielaj znaki spacja oraz zakoncz nia dzialanie.\n";
	cout << "Przyklad: 2 + 2 .\n";
	string dzialanie;
	getline(cin, dzialanie);

	vector <string> dane;
	string temp;
	temp.clear();
	int i = 0;

	while (i < dzialanie.length())
	{
		if (dzialanie[i] != 32)
		{
			temp += dzialanie[i];
			i++;
		}
		else
		{
			dane.push_back(temp);
			temp.clear();
			i++;
		}
	}
	system("cls");
	return dane;
}

bool czy_dzielenie_lub_mnozenie(vector <string> dane)
{
	for (int i = 0; i < dane.size(); i++)
	{
		if (dane[i] == "/" || dane[i] == "*")
			return true;
	}
	return false;
}

bool czy_dodawanie_lub_odejmowanie(vector <string> dane)
{
	for (int i = 0; i < dane.size(); i++)
	{
		if (dane[i] == "+" || dane[i] == "-")
			return true;
	}
	return false;
}

vector <string> dzielenie_mnozenie(vector <string> dane)
{
	vector <string> dane2;
	vector <string> dane3;
	for (int i = 0; i < dane.size(); i++)
	{
		if (dane[i] == "/")
		{
			istringstream iss(dane[i - 1]);
			float temp;
			iss >> temp;
			istringstream iss2(dane[i + 1]);
			float temp2;
			iss2 >> temp2;
			temp /= temp2;
			ostringstream ss;
			ss << temp;
			string str = ss.str();
			dane[i + 1] = str;
			dane2.push_back(str);
			i++;
			continue;
		}
		else if (dane[i] == "*")
		{
			istringstream iss(dane[i - 1]);
			float temp;
			iss >> temp;
			istringstream iss2(dane[i + 1]);
			float temp2;
			iss2 >> temp2;
			temp *= temp2;
			ostringstream ss;
			ss << temp;
			string str = ss.str();
			dane[i + 1] = str;
			dane2.push_back(str);
			i++;
			continue;
		}
		else
			dane2.push_back(dane[i]);
	}
	string koniec;
	for (int i = 0; i < dane2.size(); i++)
	{
		if (dane2[i] == "+" || dane2[i] == "-")
		{
			dane3.push_back(dane2[i - 1]);
			dane3.push_back(dane2[i]);
		}
		koniec = dane2[i];
	}
	dane3.push_back(koniec);
	return dane3;
}

vector <string> odejmowanie_dodawanie(vector <string> dane)
{
	vector <string> dane2;
	for (int i = 0; i < dane.size(); i++)
	{
		if (dane[i] == "-")
		{
			istringstream iss(dane[i - 1]);
			float temp;
			iss >> temp;
			istringstream iss2(dane[i + 1]);
			float temp2;
			iss2 >> temp2;
			temp -= temp2;
			ostringstream ss;
			ss << temp;
			string str = ss.str();
			dane[i + 1] = str;
			dane2.push_back(str);
			i++;
			continue;
		}
		else if (dane[i] == "+")
		{
			istringstream iss(dane[i - 1]);
			float temp;
			iss >> temp;
			istringstream iss2(dane[i + 1]);
			float temp2;
			iss2 >> temp2;
			temp += temp2;
			ostringstream ss;
			ss << temp;
			string str = ss.str();
			dane[i + 1] = str;
			dane2.push_back(str);
			i++;
			continue;
		}
		else
			dane2.push_back(dane[i]);
	}
	return dane2;
}

void wynik(vector <string> dane, vector <string> dane2)
{
	for (int i = 0; i < dane.size(); i++)
		cout << dane[i] << " ";
	cout << "= ";
	string wynik;
	for (int i = 0; i < dane2.size(); i++)
		wynik = dane2[i];
	cout << wynik;
}