#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

using namespace std;

const string INPUT_DATA_FILENAME = "data.csv";
const int MAX_WEIGHT = 15;

void read_csv(string filename, vector<int> &weights, vector<int> &prices)
{

	ifstream inFile(filename);
	if (!inFile) //Check for errors
	{
		cout << "Problem encountered during the opening of the file" << endl;
		return;
	}

	string strTemp;
	getline(inFile, strTemp); // To remove first row of description

	while (getline(inFile, strTemp, ','))
	{
		weights.push_back(stoi(strTemp));
		getline(inFile, strTemp, ',');
		prices.push_back(stoi(strTemp));
	}
	inFile.close();
}
int solve_bagRichest(int max_weight, vector<int> &weight, vector<int> &price, int n)
{
	if (weight.at(n - 1) > max_weight)
		return solve_bagRichest(max_weight, weight, price, n - 1);
	else
		return max(price.at(n - 1) + solve_bagRichest(max_weight - weight.at(n - 1),weight, price, n - 1),solve_bagRichest(max_weight, weight, price, n - 1));
}
int main()
{
	vector<int> weight;
	vector<int> price;
	read_csv(INPUT_DATA_FILENAME, weight, price);
	cout << solve_bagRichest(MAX_WEIGHT, weight, price, weight.size()) << endl;
	return 0;
}
