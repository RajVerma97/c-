#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string a[1000][3];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    for (int i = 0; i < n; i++)
    {
        string n1 = a[i][0];
        string n2 = a[i][1];
        string n3 = a[i][2];

        bool isDerived = true;

        for (char note : n3)
        {
            if (n1.find(note) == string::npos && n2.find(note) == string::npos)
            {
                isDerived = false;
                break;
            }
        }

        if (isDerived)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}