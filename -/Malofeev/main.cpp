#include<iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

string enter()
{
    string file;
    getline(cin, file);
    file += ' ';
    return file;
}

vector <string> WholeSubstitution(string file)
{
    string a;
    vector <string> alphabet;
    while (file.size() != 0)
    {
        a = file.substr(0, file.find_first_of(' '));
        alphabet.push_back(a);
        file = file.substr(file.find(' ') + 1, file.size() - 1);
    }
    return alphabet;
}

string getWord(vector <string> alphabet)
{
    string word;
    word = alphabet[alphabet.size() - 1];
    alphabet.pop_back();
    cout << word;
    return word;
}

string WordBeginning(string word, string BeforeSubstitution)
{
    string beginning;
    beginning = word.substr(0, word.find_first_of(BeforeSubstitution) - 1);
    return beginning;
}

string WordEnding(string word, string BeforeSubstitution)
{
    string ending;
    ending = word.substr(word.find_first_of(BeforeSubstitution) + BeforeSubstitution.size() + 1, word.size() - 1);
    return ending;
}

string ApplySubstitutionOnce(string word, string BeforeSubstitution, string AfterSubstitution)
{
    word = WordBeginning(word, BeforeSubstitution) + AfterSubstitution + WordEnding(word, BeforeSubstitution);
    return word;
}

bool IsSubstitutionAble(string word, string substitution)
{
    return word.find(substitution) != word.size() - 1;
}

string ApplySubstitution(string word, string BeforeSubstitution, string AfterSubstitution)
{
    while (IsSubstitutionAble(word, BeforeSubstitution))
    {
        ApplySubstitutionOnce(word, BeforeSubstitution, AfterSubstitution);
    }
    return word;
}


void output(string word)
{
    cout << word;
}

int main()
{
    vector <string> alphabet;
    string file;
    file = enter();
    cout << 1 << endl;
    alphabet = WholeSubstitution(file);
    cout << 2 << endl;
    cout << alphabet[0];
    string word;
    word = getWord(alphabet);
    cout << 3;
    for (int i = 0; i < (int)alphabet.size() - 2; i += 2)
    {
        string BeforeSubstitution = alphabet[i];
        string AfterSubstitution = alphabet[i + 1];
        word = ApplySubstitution(word, BeforeSubstitution, AfterSubstitution);
    }
    output(word);
    return 0;
}
