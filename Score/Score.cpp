// Score.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class Score {

public:
    static const int MaxN = 10;
    int N;
    int a[MaxN][MaxN];
    bool Free[MaxN][MaxN];
    unsigned int v[MaxN];
    int c[MaxN];
    int Sorted[MaxN];
    int cv;
    int i, j;

    void inputData() {

        cout << "Input N and press Enter\n";
        cin >> N;
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                cin >> a[i][j];
            }
        }

        for (i = 1; i <= N; i++) {
            cin >> v[i];
        }

        for (i = 1; i <= N; i++) {
            cin >> c[i];
        }
    };

    int next(int cv) {
        int dd = cv;
        for (i = N; i >= 1; i--)
        {
            if (a[cv][Sorted[i]] == 1 && v[Sorted[i]] == 1 && Free[cv][Sorted[i]]) {
                Free[cv][Sorted[i]] = false;
                dd = Sorted[i];
                break;
            }
        }

        for (i = 1; i <= N; i++) {
            if (a[cv][Sorted[i]] == 1 && v[Sorted[i]] == 2 && Free[cv][Sorted[i]]) {
                Free[cv][Sorted[i]] = false;
                dd = Sorted[i];
                break;
            }
        }
        return dd;
    };

    void calculate() {
        for (i = 1; i <= N; i++) {
            Sorted[c[i]] = i;
        }

        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                Free[i][j] = true;
            }
        }
    }

    void play() {
        inputData();
        calculate();
        cv = 1;
        while (true)
        {
            if (v[cv] == 1) {
                cv = next(cv);
                cout << cv << endl;
            }
            else {
                cin >> cv;
            }

            if (cv == 1)
                break;
        }
    }
};

int main()
{
    Score s;
    s.play();
    cout << "End" << endl;
    return 0;
}