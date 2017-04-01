/**
 * Дано два натуральных числа A и B (A<B). Найти значение
 * поразрядной операции "или-исключающее" (xor) для натуральных
 * чисел от A до B. Сложность алгоритма должна быть O(1), т. е. не
 * должна зависеть от количества натуральных чисел, входящих в
 * интервал [A;B].
 * */
#include <stdio.h>

#define A 7
#define B 17

/**
 * Вычисление xor для каждого элемента на [0, b]
 * @param b - правая граница отрезка
 * @return значение (...((0 ^ 1) ^ 2) ^ ... ^ b)
 */
int xor(int b)
{
    switch (b % 4)
    {
        case 0:
            return b;
        case 1:
            return 1;
        case 2:
            return b + 1;
        default:
            return 0;
    }
}

int main(void)
{
    ///Эталонная реализация O(n) для проверки
    int xor_n = 0;
    for (int i = A; i <= B; i++)
        xor_n ^= i;

    ///Решение O(1)
    /**
     * Для получения xor[a,b] мы должны избавиться от влияния
     * xor[0, a-1] на xor[0,b]. Так как a ^ a == 0, то получаем
     * следующее:
     */
    int x = xor(A - 1) ^ xor(B);
    /**
     * На вычисление xor[0,a-1] и xor [0,b] требуется конечное
     * число операций (% и переход по одному из case при вычислении
     * на каждом отрезке) + еще один xor для получения итогого
     * результата.
     * Итого: количество операций не зависит от n => O(1)
     */
    printf("%d\n", x);
    return 0;
}
