//Егорова Анна М8О-107Б-18
//Создать класс BitString для работы с 96-битовыми строками. Битовая строка должна быть представлена
//двумя полями: старшая часть unsigned long long, младшая часть unsigned int. Должны быть
//реализованы все традиционные операции для работы с битами: and, or, xor, not. Реализовать сдвиг влево
//shiftLeft и сдвиг вправо shiftRight на заданное количество битов. Реализовать операцию вычисления
//количества единичных битов, операции сравнения по количеству единичных битов. Реализовать операцию
//проверки включения.

#include <iostream>
#include <cmath>

using namespace std;

class BitString{
    public: unsigned long long m1;
    unsigned int m2;
    unsigned long long n1;
    unsigned int n2;
    unsigned long long o;
};

int perevod(unsigned long long m1) {
        const int size = sizeof(unsigned long long)*8;
    unsigned long long i;
    int binNum[size] = {0};
    for (i = 0; i < size; i++) {
        binNum[i] = m1 % 2;
        m1 /= 2;
    }
    for (int i = size - 1; i >= 0; i--) {
        cout << binNum[i];
        if (i%8 == 0)
            cout << " ";
    }
    cout << "\n";
}

int perevod2(unsigned int n1) {
        const int size = sizeof(unsigned int)*8;
    unsigned int i;
    int binNum[size] = {0};
    for (i = 0; i < size; i++) {
        binNum[i] = n1 % 2;
        n1 /= 2;
    }
    for (int i = size - 1; i >= 0; i--) {
        cout << binNum[i];
        if (i%8 == 0)
            cout << " ";
    }
    cout << "\n";
}

int main() {
    BitString a;
    cout << "Старшая часть 1 строки:" << endl;
    cin >> a.m1;
    cout << "Младшая часть 1 строки:" << endl;
    cin >> a.n1;
    BitString b;
    cout << "Старшая часть 2 строки:" << endl;
    cin >> a.m2;
    cout << "Младшая часть 2 строки:" << endl;
    cin >> a.n2;
    int kol, koll, kol2, koll2;

    int key = 0;
    while(key != 14) {
        cout << "Нажмите (1) для операции and с битами" <<endl
            << "Нажмите (2) для операции or с битами" << endl
            << "Нажмите (3) для операции xor с битами " << endl
            << "Нажмите (4) для операции not с битами" <<endl
            << "Нажмите (5) для сдвига вправо" << endl
            << "Нажмите (6) для сдвига влево" <<endl
            << "Нажмите (7) для подсчета единичных битов в старшей части 1 числа" <<endl
            << "Нажмите (8) для подсчета единичных битов в старшей части 2 числа" <<endl
            << "Нажмите (9) для подсчета единичных битов в младшей части 1 числа" <<endl
            << "Нажмите (10) для подсчета единичных битов в младшей части 2 числа" <<endl
            << "Нажмите (11) для равнения по количеству единичных битов" <<endl
            << "Нажмите (12) для проверки на включение старшей части" <<endl
            << "Нажмите (13) для проверки на включение младшей части" <<endl
            << "Нажмите (14) если хотите выйти"<<endl;
        cin >> key;

        switch(key) {
            case 1: {
                unsigned long long c1 = a.m1 & a.m2;
                unsigned int c2 = a.n1 & a.n2; //and
                printf("%llu %u\n", c1, c2);
                perevod(c1);
                perevod2(c2);
                break;}

            case 2: {
                unsigned long long d1 = a.m1 | a.m2;
                unsigned int d2 = a.n1 | a.n2; //or
                printf("%llu %u\n", d1, d2);
                perevod(d1);
                perevod2(d2);
                break;}

            case 3: {
                unsigned long long e1 = a.m1 ^ a.m2;
                unsigned int e2 = a.n1 ^ a.n2; //xor
                printf("%llu %u\n", e1, e2);
                perevod(e1);
                perevod2(e2);
                break;}

            case 4: {
                int u1 = ~a.m1;
                int u2 = ~a.n1;
                int u3 = ~a.m2;
                int u4 = ~a.n2; //not
                printf("%d %d\n", -u1, -u2);
                perevod(-u1);
                perevod2(-u2);
                printf("%d %d\n", -u3, -u4);
                perevod(-u3);
                perevod2(-u4);
                break;}

            case 5: {
                unsigned long long y1 = a.m1, p1;
                unsigned int y2 = a.n1, p2;
                unsigned long long y3 = a.m2, p3;
                unsigned int y4 = a.n2, p4;
                printf("%llu >> 1 == %llu\n", y1, y1 >> 1);
                p1 = (y1 >> 1);
                perevod(p1);
                printf("%u >> 1 == %u\n", y2, y2 >> 1);
                p2 = (y2 >> 1);
                perevod2(p2);
                printf("%llu >> 1 == %llu\n", y3, y3 >> 1);
                p3 = (y3 >> 1);
                perevod(p3);
                printf("%u >> 1 == %u\n", y4, y4 >> 1);
                p4 = (y4 >> 1);
                perevod2(p4);
                break;}

            case 6: {
                unsigned long long y1 = a.m1, q1;
                unsigned int y2 = a.n1, q2;
                unsigned long long y3 = a.m2, q3;
                unsigned int y4 = a.n2, q4;
                printf("%llu << 1 == %llu\n", y1, y1 << 1);
                q1 = (y1 << 1);
                perevod(q1);
                printf("%u << 1 == %u\n", y2, y2 << 1);
                q2 = (y2 << 1);
                perevod2(q2);
                printf("%llu << 1 == %llu\n", y3, y3 << 1);
                q3 = (y3 << 1);
                perevod(q3);
                printf("%u << 1 == %u\n", y4, y4 << 1);
                q4 = (y4 << 1);
                perevod2(q4);
                break;}

            case 7: {
                const int size = sizeof(unsigned long long)*8;
                unsigned long long i;
                kol = 0;
                int binNum[size] = {0};
                for (i = 0; i < size; i++) {
                    binNum[i] = a.m1 % 2;
                    a.m1 /= 2;
                }
                for (int i = size - 1; i >= 0; i--)
                {
                    cout << binNum[i];
                    if (binNum[i] == 1) {
                        kol++;}
                    if (i%8 == 0)
                        cout << " ";
                    }
                    cout << "\n" << kol << endl;
                break; }

            case 8: {
                    const int size = sizeof(unsigned long long)*8;
                    unsigned long long i;
                    koll = 0;
                    int binNum[size] = {0};
                    for (i = 0; i < size; i++) {
                        binNum[i] = a.m2 % 2;
                        a.m2 /= 2;
                    }
                    for (int i = size - 1; i >= 0; i--) {
                        cout << binNum[i];
                        if (binNum[i] == 1) {
                            koll++;}
                        if (i%8 == 0)
                            cout << " ";
                        }
                    cout << "\n" << koll << endl;
                break; }

            case 9: {
                    const int size = sizeof(unsigned int)*8;
                    unsigned int j;
                    kol2 = 0;
                    int binNum[size] = {0};
                    for (j = 0; j < size; j++)
                    {
                        binNum[j] = a.n1 % 2;
                        a.n1 /= 2; }
                    for (int j = size - 1; j >= 0; j--)
                    {
                            cout << binNum[j];
                            if (binNum[j] == 1) {
                                    kol2++;}
                            if (j%8 == 0)
                            cout << " ";
                    }
                    cout << "\n" << kol2 << endl;
                break; }

            case 10: {
                    const int size = sizeof(unsigned int)*8;
                    unsigned int j;
                    koll2 = 0;
                    int binNum[size] = {0};
                    for (j = 0; j < size; j++)
                    {
                        binNum[j] = a.n2 % 2;
                        a.n2 /= 2; }
                    for (int j = size - 1; j >= 0; j--)
                    {
                        cout << binNum[j];
                        if (binNum[j] == 1) {
                            koll2++;}
                        if (j%8 == 0)
                            cout << " ";
                    }
                        cout << "\n" << koll2 << endl;
                break; }

            case 11: {
                    if ((kol+kol2) > (koll+koll2)) {
                        cout << "Первое число больше второго по количеству единичных битов." << endl;
                    }
                    if ((kol+kol2) < (koll+koll2)) {
                        cout << "Первое число меньше второго по количеству единичных битов."<< endl;
                    }
                    if ((kol+kol2) == (koll+koll2)) {
                        cout << "Первое число равно второму по количеству единичных битов." << endl;
                        }
                break; }

            case 12: { if ((a.m1 | a.m2) == a.m1) {
                    cout << "Включено." << endl; }
                    else if ((a.m1 | a.m2) != a.m1) {
                    cout << "Не включено." << endl; }
                break; }

            case 13: {
                if ((a.n1 | a.n2) == a.n1) {
                    cout << "Включено." << endl; }
                    else if ((a.n1 | a.n2) != a.n1) {
                        cout << "Не включено." << endl; }
                break; }
            }
        }
    return 0;
}
	 