#include <iostream>
#include <array>
#include <algorithm>
#include <ctime>

using namespace std;

class Comparator {
public:
     virtual bool templateMethod(char &obj_one, char &obj_two) final {
        return compare(obj_one, obj_two);
    }

    virtual bool compare(char &obj_one, char &obj_two) = 0;
};

class Comp : public Comparator {
    bool compare(char &obj_one, char &obj_two) override {
        if (obj_one < obj_two)
            return true;
        else
            return false;
    }
};

class ArraySort {
public:
    void sortArr(array<string, 5> &arr, Comp &cmp) {
        int posi = 0;

        for (int j = 0; j < arr.size(); ++j) {
            for (int i = j+1; i < arr.size(); i++) {
                if (cmp.templateMethod(arr[i][arr[i].size()-1], arr[posi][arr[posi].size()-1]))
                    posi = i;
            }
            string aux = arr[j];
            arr[j] = arr[posi];
            arr[posi] = aux;
        }
    }
};

int main() {
    srand(time(0));
    array<string, 5> coisas;
    Comp comparator;
    ArraySort sorting_arr;

    for (int i = 0; i < 5; ++i)
        coisas[i] = "palavra_grande_pra_chuchu" + i;


    for (int i = 0; i < 5; ++i)
        random_shuffle(coisas[i].begin(), coisas[i].end());

    cout << endl;
    cout << "------------no order array--------------" << endl;
    for (int i = 0; i < 5; ++i)
        cout << coisas[i] << endl;

    sorting_arr.sortArr(coisas, comparator);

    cout << endl;
    cout << "------------in order array---------------" << endl;
    for (int i = 0; i < 5; ++i)
        cout << coisas[i] << endl;

    return 0;
}