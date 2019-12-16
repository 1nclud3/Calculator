#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector <string> operation_acceptation();
bool is_multi_or_div(vector <string> data);
bool is_add_or_subtr(vector <string> data);
vector <string> multi_div(vector <string> data);
vector <string> add_subtr(vector <string> data);
void result(vector <string> data, vector <string> data2);

int main()
{
	vector <string> primary_operation = operation_acceptation();
	vector <string> operation = primary_operation;
	if (is_multi_or_div(operation) == true)
		operation = multi_div(operation);
	if (is_add_or_subtr(operation) == true)
		operation = add_subtr(operation);
	result(primary_operation, operation);
	return 0;
}
	
vector <string> operation_acceptation()
{
	cout << "Type a math operation to solve.\n";
	cout << "Remember to separate the characters with SPACE.\n";
	cout << "Remember to end your operation with SPACE.\n";
	cout << "Example: 2 + 2 .\n";
	string operation;
	getline(cin, operation);

	vector <string> data;
	string temp;
	temp.clear();
	int i = 0;

	while (i < operation.length())
	{
		if (operation[i] != 32)
		{
			temp += operation[i];
			i++;
		}
		else
		{
			data.push_back(temp);
			temp.clear();
			i++;
		}
	}
	system("cls");
	return data;
}

bool is_multi_or_div(vector <string> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == "/" || data[i] == "*")
			return true;
	}
	return false;
}

bool is_add_or_subtr(vector <string> data)
{
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == "+" || data[i] == "-")
			return true;
	}
	return false;
}

vector <string> multi_div(vector <string> data)
{
	vector <string> data2;
	vector <string> data3;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == "/")
		{
			istringstream iss(data[i - 1]);
			float temp;
			iss >> temp;
			istringstream iss2(data[i + 1]);
			float temp2;
			iss2 >> temp2;
			temp /= temp2;
			ostringstream ss;
			ss << temp;
			string str = ss.str();
			data[i + 1] = str;
			data2.push_back(str);
			i++;
			continue;
		}
		else if (data[i] == "*")
		{
			istringstream iss(data[i - 1]);
			float temp;
			iss >> temp;
			istringstream iss2(data[i + 1]);
			float temp2;
			iss2 >> temp2;
			temp *= temp2;
			ostringstream ss;
			ss << temp;
			string str = ss.str();
			data[i + 1] = str;
			data2.push_back(str);
			i++;
			continue;
		}
		else
			data2.push_back(data[i]);
	}
	string end;
	for (int i = 0; i < data2.size(); i++)
	{
		if (data2[i] == "+" || data2[i] == "-")
		{
			data3.push_back(data2[i - 1]);
			data3.push_back(data2[i]);
		}
		end = data2[i];
	}
	data3.push_back(end);
	return data3;
}

vector <string> add_subtr(vector <string> data)
{
	vector <string> data2;
	for (int i = 0; i < data.size(); i++)
	{
		if (data[i] == "-")
		{
			istringstream iss(data[i - 1]);
			float temp;
			iss >> temp;
			istringstream iss2(data[i + 1]);
			float temp2;
			iss2 >> temp2;
			temp -= temp2;
			ostringstream ss;
			ss << temp;
			string str = ss.str();
			data[i + 1] = str;
			data2.push_back(str);
			i++;
			continue;
		}
		else if (data[i] == "+")
		{
			istringstream iss(data[i - 1]);
			float temp;
			iss >> temp;
			istringstream iss2(data[i + 1]);
			float temp2;
			iss2 >> temp2;
			temp += temp2;
			ostringstream ss;
			ss << temp;
			string str = ss.str();
			data[i + 1] = str;
			data2.push_back(str);
			i++;
			continue;
		}
		else
			data2.push_back(data[i]);
	}
	return data2;
}

void result(vector <string> data, vector <string> data2)
{
	for (int i = 0; i < data.size(); i++)
		cout << data[i] << " ";
	cout << "= ";
	string result;
	for (int i = 0; i < data2.size(); i++)
		result = data2[i];
	cout << result;
}