// AliceAndBob.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <array>
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;

class AliceAndBob {

public:
    static const int MaxN = 1000;
    static const int MaxM = 10000;
    static const int MaxK = 20;
    int i, N, M, T, from, tov;
    bool Changed;
    int S[MaxN], Ka[MaxN];
    unsigned int B[MaxN];
    int a[MaxN][MaxK];

    bool exitArc(int i) {
        bool result = false;

        for (int j = 0; j < Ka[i]; j++) {
            if (S[a[i][j]] == 1) {
                result = true;
                break;
            }
        }

        return result;
    }

    bool allArcs(int i) {
        bool result = true;

        for (int j = 0; j < Ka[i]; j++) {
            if (S[a[i][j]] == 0) {
                result = false;
                break;
            }
        }

        return result;
    }

    void inputDataConsole() {

        for ( i = 0; i < MaxN; i++)
        {
            Ka[i] = 0;
        }

        std::cin >> N;
        std::cin >> M;
        std::cin >> T;
        std::cout << "Cin B \n";

        for (i = 0; i < N; i++)
            std::cin >> B[i];

        std::cout << "Cin from tov Ka \n";

        for (i = 0; i < M; i++) {
            std::cin >> from;
            std::cin >> tov;
            Ka[from]++;
            a[from][Ka[from]] = tov;
        }

        for (i = 0; i < N; i++) {
            S[i] = 0;
        }
        S[T-1] = 1;
    }

    void outputData() {
        for (i = 0; i < N; i++) {
           cout << " " << S[i];
        }
    }

    void init() {

        for (i = 0; i < MaxN; i++){
            S[i] = 0;
            Ka[i] = 0;
        }

        for (i = 0; i < MaxN; i++)
            for (int j = 0; j < MaxK; j++)
                a[i][j] = 0;
    }

    void outputIntoFile() {
        ofstream outFile;
        outFile.open("d.out");
        for (i = 0; i < N; i++) {
            outFile<< S[i] << " ";
        }
        outFile.close();
    }

    void fileInput() {
        init();
        ifstream indata; 
        indata.open("d.in"); 

        if (!indata) {
            cout << "file couldn't be opened";
            exit(-1);
        }

        indata >> N;
        indata >> M;
        indata >> T;
        T--;
        for (i = 0; i < N; i++)
            indata >> B[i];

        while (!indata.eof()) {
            indata >> from;
            from--;
            indata >> tov;       
            Ka[from]++;
            tov--;
            a[from][Ka[from]-1] = tov;
        }
        indata.close();
        for (i = 0; i < N; i++) {
            S[i] = 0;
        }
        S[T] = 1;
    }

    void print() {
        cout << N << " " << M << " " << T << endl;
      
        for (int l = 0; l < N; l++)
        {
            cout << B[l] << " ";
        }
        cout << endl;
       
    }

    void play() { 
         fileInput();
         Changed = true;
         while (Changed)
         {
             Changed = false;
             for (int i = 0; i < N; i++)
             {
                 if ((S[i] == 0) && (((B[i] == 1) && exitArc(i)) || ((B[i] == 0) && allArcs(i)))) {
                     S[i] = 1;
                     Changed = true;
                 }
             }
         }
         outputIntoFile();
    }
};

int main()
{
    AliceAndBob game;
    game.play();
    return 0;
}