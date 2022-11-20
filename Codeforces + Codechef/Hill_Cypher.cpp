#include<bits/stdc++.h>
using namespace std;

string cypher_text;
string calculated_plain_Text;

void getKeyMatrix(string key, vector<vector<int>> &keyMatrix)
{
	int k = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			keyMatrix[i][j] = (key[k]) % 65;
			k++;
		}
	}
}

void encrypt(vector<vector<int>> &cipherMatrix,vector<vector<int>> &keyMatrix,vector<vector<int>> &messageVector)
{
	int x, i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 1; j++)
		{
			cipherMatrix[i][j] = 0;

			for (x = 0; x < 3; x++)
				cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];

            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
		}
	}
}

void HillCipher(string message, string key,bool ed) //if ed == 0 calculating cypher text else calculating plan text
{

	vector<vector<int>> keyMatrix(3,vector<int>(3));

	getKeyMatrix(key, keyMatrix);

    vector<vector<int>>  messageVector(3,vector<int>(3));

	for (int i = 0; i < 3; i++)
		messageVector[i][0] = (message[i]) % 65;

	vector<vector<int>> cipherMatrix(3,vector<int>(1));
	encrypt(cipherMatrix, keyMatrix, messageVector);

	string Text;
	for (int i = 0; i < 3; i++)
		Text += cipherMatrix[i][0] + 65;

    if(ed == 0)
        cypher_text +=  Text;
    else
        calculated_plain_Text += Text;
}

int main()
{
	string message;
	string key = "BACKUPABC";

	cout<<"Enter Message (plain text) : ";
	cin>>message;


    if(message.length()%3 == 1)
    {
        message += 'X';
        message += 'X';
    }
    else if(message.length()%3 == 2)
        message += "X";

	for(int i=0;i<message.length();i+=3)
    {
        string block;
        block += message[i+0];
        block += message[i+1];
        block += message[i+2];
        HillCipher(block, key,0);
    }

    cout<<"Plain Text = "<<message<<"\n";
    cout<<"Cypher Text = "<<cypher_text<<"\n";
    string key_inverse = "PWCOWDGPM";

    for(int i=0;i<cypher_text.length();i+=3)
    {
        string block;
        block += cypher_text[i+0];
        block += cypher_text[i+1];
        block += cypher_text[i+2];
        HillCipher(block,key_inverse,1);
    }

    cout<<"Decrypted text = "<<calculated_plain_Text<<"\n";



	return 0;
}
