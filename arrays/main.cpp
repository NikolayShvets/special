#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

/*Задча:
 * Отсортировать строки
 * двумерного массива случайных размеров
 * i ~ [1,7]; j ~ [1,4]
 * по возрастанию по максимальному
 * элементу в строке.
 * Зарещается использовать циклы for и обращения
 * к элементам массива по индексу.
 * */

const unsigned int ROWS = 7;
const unsigned int COLS = 4;
/*Функция заполнения массива*/
void fillArray(double array[][COLS]);
/*Функция вывода массива на экран*/
void printArray(double array[][COLS]);
/*Функция поиска максимального элемента в строке массива*/
double getMaxElemInRow(const double row[]);
/*Функция перестановки двух строк массива*/
void swapRows(double rowFrom[], double rowTo[]);
/*Функция сортировки строк массива*/
void sortArray(double array[][COLS]);
int main()
{
    srand((int)time(0));
    double array[ROWS][COLS];
    fillArray(array);
    printArray(array);
    sortArray(array);
    printArray(array);
    return 0;
}
void fillArray(double array[][COLS]){
    for (unsigned int i = 0; i < ROWS; i++){
        for (unsigned int j = 0; j < COLS; j++){
            array[i][j] = 0.1 * (rand() % 99 + 1);
        }
    }
}
void printArray(double array[][COLS]){
    for (unsigned int i = 0; i < ROWS; i++){
        for (unsigned int j = 0; j < COLS; j++){
            cout << setw(4) << array[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}
double getMaxElemInRow(const double row[]){
    double maxElem {0.0};
    double *ptr = (double*)row;
    unsigned int i = 0;
    while (i < COLS){
        if ( *ptr > maxElem){
            maxElem = (*ptr);
        }
        ++ptr;
        ++i;
    }
    return maxElem;
}
void swapRows(double rowFrom[], double rowTo[]){
    unsigned int i = 0;
    double *ptr1 = (double*)rowFrom;
    double *ptr2 = (double*)rowTo;
    while (i < COLS){
        double temp = (*ptr1);
        (*ptr1++) = (*ptr2);
        (*ptr2++) = temp;
        ++i;
    }
}
void sortArray(double array[][COLS]){
    bool isSorted{false};
    while(isSorted == false){
        isSorted = true;
        unsigned int i = 0;
        while(i < ROWS - 1){
            double *p1 = (double*)array[i];
            double *p2 = (double*)array[i+1];
            if(getMaxElemInRow(p1) > getMaxElemInRow(p2)){
                swapRows(p1, p2);
                isSorted = false;
            }
            ++i;
        }
    }
}

