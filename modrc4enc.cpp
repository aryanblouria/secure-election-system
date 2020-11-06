#include<bits/stdc++.h>
using namespace std;

string enc(vector<int>s, vector<int> t, string p)
{
	int i = 0, j = 0, temp = 0, k = 0, tmp1, tmp2;
	int *encrypt = new int [p.length()];
	string encrypted;
	for (int r = 0; r < p.length(); r++)
    {
		i = (i + 1) % 256;
		j = (j + s[i]) % 256;

		tmp1 = s[i];
		s[i] = s[i+j+1];
		s[i+j+1] = tmp1;

		temp = (s[i] + s[j]) % 256;
		k = s[temp];
		tmp2 = ((int)p[r] ^ k ^ j);

		encrypt[r] = tmp2;
		encrypted += (char)encrypt[r];
	}
	return encrypted;
}


vector<int> permute(vector<int> s, vector<int> t)
{
	int j = 0, temp;
	for (int i = 0; i< 256; i++)
    {
		j = (j + s[i] + t[i]) % 256;
        temp = s[i];
        s[i] = s[j];
		s[j] = temp;
	}
    return s;
}

int main()
{
	string data;
	vector<int> S(256);
	vector<int> T(256);
	int key[] = {2,3,4,6};
	for (int i = 0; i < 256; i++)
    {
		S[i] = i;
		T[i] = key[(i%(sizeof(key)/sizeof(*key)))];
	}

    S = permute(S,T);

	ifstream input;
	input.open("Input.txt",ios::in);
	getline(input,data);
	input.close();

	string es = enc(S, T, data);
	cout << "Input Message: " << data << endl;
	cout << "Encrypted Message:  " << es << endl;

	ofstream enct;
	enct.open("Encrypted.txt",ios::out);
	enct << es;
	enct.close();
	return 0;
}
