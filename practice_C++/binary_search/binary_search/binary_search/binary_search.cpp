#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct account {
    int indexUser;
    char emailUser[255];
    // нижеперечисленные поля не заполняются
    char passwordUser[255];
    char firstName[255];
    char secondName[255];
};

int binarySearch_found_index(vector<account>& array, char* email, int& count);
void sort_emailUsers(vector<account>& array);
void read_emails(vector<account>& array, string path);
int simple_search(vector<account>& array, char* email, int& count);

int main()
{
    vector<account> array;
    int countIteration = 0;
    int countIterationSimple = 0;
    char emailUser[] = "zackary20@yahoo.com";

    read_emails(array, "emails(1).txt");
    sort_emailUsers(array);
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i].indexUser << ": " << array[i].emailUser << endl;
    }
    cout << "\n";
    int resultBinarySearch = binarySearch_found_index(array, emailUser, countIteration);
    int resultSimpleSearch = simple_search(array, emailUser, countIterationSimple);

    cout << emailUser << ": " << resultBinarySearch << endl;
    cout << emailUser << ": " << resultSimpleSearch << endl;
    cout << "Amount of iterations by binary_search: " << countIteration << endl;
    cout << "Amount of iterations by simple_search: " << countIterationSimple << endl;



    return 0;
}

int binarySearch_found_index(vector<account>& array, char* email, int& count) {
    // находит индекс пользователя по его email'у.
    int resultIndexUser;

    int startIndex = 0;
    int endIndex = array.size() - 1;
    int curIndex;

    while (startIndex <= endIndex)
    {
        curIndex = (endIndex + startIndex) / 2;
        count++;
        if (strcmp(email, array[curIndex].emailUser) == 1)
        {
            startIndex = curIndex + 1;
        }
        else if (strcmp(email, array[curIndex].emailUser) == -1) {
            endIndex = curIndex - 1;
        }
        else {
            return array[curIndex].indexUser;
        }
    }
    cout << "Email was not found" << endl;
}

void read_emails(vector<account>& array, string path) {
    int i = 0;
    account man;
    ifstream emails(path, ios_base::in);

    char email[255];
    if (emails.is_open())
    {
        while (!emails.eof())
        {
            array.push_back(man);
            emails >> email;
            array[i].indexUser = 10000 + i;
            strcpy(array[i++].emailUser, email);
        }
        emails.close();
    }
    else {
        cout << "\nSomething get wrong!" << endl;
    }

}

void sort_emailUsers(vector<account>& array) {
    int key = array.size() - 1;
    account user;

    while (key > 0)
    {
        for (int i = 0; i < array.size() - key; i++)
        {
            if ((strcmp(array[i].emailUser, array[i + key].emailUser)) == 1)
            {
                user = array[i + key];
                array[i + key] = array[i];
                array[i] = user;
            }
        }
        key /= 1.2473309;
    }
}


int simple_search(vector<account>& array, char* email, int& count) {
    for (int i = 0; i < array.size(); i++)
    {
        count++;
        if (strcmp(email, array[i].emailUser) == 0)
        {
            return array[i].indexUser;
        }
    }
    cout << "Email was not found" << endl;
}