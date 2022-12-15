#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

/*
    Класс Number -- класс положительных больших чисел
    Большое число будет храниться в динамическом массиве data
    Каждый элемент этого массива содержит разряд числа в 100-ричной системе счисления
    (так как base = 100)
    По сути, каждый элемент data хранит две цифры числа в десятичной записи
    Значение 100 для системы счисления выбрано как компромис между
    эффективностью и удобством написания программы.
    Если выбрать значения базы 10 - то программа будет не так эффективна по памяти
    Если выбрать значения базы 256 (максимально эффективное использование памяти для типа char),
    то алгоритм печати на экран сильно усложнится
    В качестве альтернативы, можно было выбрать базу 1e9,
    изменив при этом тип элементов c char на int
    capacity - размер массива data
    size - сколько ячеек занимет число в массиве data
    size <= capacity
    Для удобства разряды числа хранятся в обратном порядке
    Например, число 12345678 соответствует массиву
    data = {78, 56, 34, 12}
    (это упрощает многие алгоритмы с такими числами)
*/


class Number
{
private:
    static const int base = 100;
    std::size_t size;
    std::size_t capacity;
    char* data;

public:

    Number(int a)
    {
        // Находим размер необходимой памяти под это число
        int temp = a;
        capacity = 0;
        while (temp != 0)
        {
            temp /= base;
            capacity += 1;
        }

        // Отдельно обрабатываем случай, когда число равно 0
        if (capacity == 0)
            capacity = 1;

        // Выделяем память и записывем число a в массив data
        // Например, число 12345678 представится в виде массива [78, 56, 34, 12]

        data = new char[capacity];

        for (int i = 0; i < capacity; ++i)
        {
            data[i] = a % base;
            a /= base;
        }

        // В данном случае размер будет равен вместимости
        size = capacity;
    }

    Number() {
        Number(0);
    }

    Number(const Number& n) {
        size = n.size;
        capacity = n.capacity;
        data = new char[capacity];
        for (int i = 0; i < capacity; i++) {
            data[i] = n.data[i];
        }
    }

    Number(const char* str) {
        int sizeStr = 0;
        while (str[sizeStr] != '\0') {
            sizeStr++;
        }
        if (sizeStr % 2) {
            size = sizeStr / 2 + 1;
        }
        else {
            size = sizeStr / 2;
        }
        capacity = size;
        data = new char[capacity];
        for (int i = 0; i < capacity; i++) {
            int now = 0;
            for (int j = 0; j < 2; j++) {
                now += (str[sizeStr - 2 * i - j - 1] - '0') * pow(10, j);
                if (sizeStr - 2 * i - j - 1 == 0) {
                    break;
                }
            }
            data[i] = char(now);
        }
    }

    Number& operator=(const Number& right) {
        size = right.size;
        capacity = right.capacity;
        data = new char[capacity];
        for (int i = 0; i < capacity; i++) {
            data[i] = right.data[i];
        }
        return *this;
    }

   /*  Number& operator+(const Number& right) const {
        Number result;
        result.size = std::max(size, right.size);
        result.capacity = result.size + 1;
        result.data = new char[result.capacity];
        int inMind = 0;
        int time;
        if (std::min(size, right.size) != std::max(size, right.size)) {//числа отличаются на несколько порядков
            for (int i = 0; i < std::min(size, right.size); i++) {//Складываем пока не кончаться разряды наименьшего числа
                time = 0;
                time += data[i];
                time += right.data[i];
                result.data[i] = (time + inMind) % base;
                if (time + inMind > 100) {
                    inMind = 1;
                }
                else {
                    inMind = 0;
                }
            }

            if (size > right.size) {//левое больше на несколько порядков
                for (int i = std::min(size, right.size); i < std::max(size, right.size); i++) {
                    time = 0;
                    time += (data[i] + inMind);
                    result.data[i] = time % base;
                    if (time >= 100) {
                        inMind = 1;
                    }
                    else {
                        inMind = 0;
                    }
                }
            }
            else if (size < right.size) {//правое больше на несколько разрядов
                for (int i = std::min(size, right.size); i < std::max(size, right.size); i++) {
                    time = 0;
                    time += (right.data[i] + inMind);
                    result.data[i] = time % base;
                    if (time >= 100) {
                        inMind = 1;
                    }
                    else {
                        inMind = 0;
                    }
                }
            }
        }
        else if (size == right.size) {
            for (int i = 0; i < result.size; i++) {//равное количество разрядов в обоих числах
                time = 0;
                time += data[i];
                time += right.data[i];
                result.data[i] = (time + inMind) % base;
                if (time + inMind > 100) {
                    inMind = 1;
                }
                else {
                    inMind = 0;
                }
            }
            if (inMind >= 1) {
                result.data[size] = 1;
            }
        }
            return result;
    }
    */
    // это моя неудачная попытка написать operator+

    Number operator+(const Number& right) //Это Гришина удачная 
    {
        Number res;

        if (size < right.size)
        {
            res.size = right.size;
            res.capacity = right.size + 1;
        }
        else
        {
            res.size = size;
            res.capacity = size + 1;
        }

        res.data = new char[res.capacity];
        for (int i = 0; i < size; ++i)
            res.data[i] = data[i];

        if (right.size > size)
        {
            for (int i = size; i < res.capacity; ++i)
                res.data[i] = 0;
        }


        int add = 0;
        int sum = 0;

        for (int i = 0; i < right.size; ++i)
        {
            sum = res.data[i] + right.data[i] + add;
            res.data[i] = sum % base;
            add = sum / base;
        }

        for (int i = right.size; i < res.size; ++i)
        {
            sum = res.data[i] + add;
            res.data[i] = sum % base;
            add = sum / base;
        }

        if (add != 0)
        {
            res.data[res.size] = add;
            ++res.size;
        }

        return res;
    }

    Number& operator+=(const Number& right) {
        *this = *this +right;
        return *this;
    }

    bool isEven() {
        return !(data[0] % 2);
    }

    Number operator*(const Number& right) {
        Number result;
        if (data[size - 1] * right.data[right.size - 1] / 100 >= 1) {
            result.size = size + right.size;
        }
        else  if (data[size - 1] * right.data[right.size - 1] / 100 < 1) {
            result.size = size + right.size - 1;
        }
        result.capacity = result.size + 1;
        result.data = new char[result.capacity];
        for (int i = 0; i < result.size; i++) {
            result.data[i] = 0;
        }
        if (size >= right.size) {
            for (int i = 0; i < right.size; i++) {
                int inMind = 0;
                int k = i;
                for (int j = 0; j < size; j++) {
                    int time = 0;
                    time = (data[j] * right.data[i] + result.data[k] + inMind);
                    result.data[k] = time % base;
                    inMind = time / base;
                    k++;
                }
                result.data[k] = inMind;
            }
        }
        else if (size < right.size) {
            for (int i = 0; i < size; i++) {
                int inMind = 0;
                int k = i;
                for (int j = 0; j < right.size; j++) {
                    int time = 0;
                    time = (data[i] * right.data[j] + result.data[k] + inMind);
                    result.data[k] = time % base;
                    inMind = time / base;
                    k++;
                }
                result.data[k] = inMind;
            }
        }
        return result;
    }

    ~Number()
    {
        delete[] data;
    }


    friend std::ostream& operator<<(std::ostream& stream, const Number& right);
};



std::ostream& operator<<(std::ostream& stream, const Number& right)
{
    // Печатаем самый большой разряд
    stream << (int)right.data[right.size - 1];

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw это то же самое, что и в языке C спецификатор %02d
    for (std::size_t i = 0; i < right.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << (int)right.data[right.size - 2 - i];

    return stream;
}

Number fib(int n) {
   Number* result = new Number[n + 1];
   result[0] = 0;
   result[1] = 1;
   result[2] = 1;
   for (int i = 2; i <= n; i++) {
       result[i] = result[i - 1] + result[i - 2];
   }
   return result[n];
}

Number fact(int n) {
    Number result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * Number(i);
        std::cout << result << std::endl;
    }
    return result;
}
void num_grad(int n) {
    Number step = 0;
    Number max = 0;
}


int main()
{
    Number x = "123456789135792468";
    Number y = 0;
    std::cout << x << " " << y << std::endl;
 
    Number a = 2346;
    std::cout << a + x << std::endl;
    a += x;
    Number b = "987654321975318642";
    std::cout << a << std::endl;
    std::cout << "fib:" << fib(1000) << std::endl;
    std::cout <<"iseven: " << a.isEven() << std::endl;
    Number c = b * x;
    std::cout << "b * x = " << c << std::endl;
    std::cout << "factorial(10) =" << fact(100) << std::endl;
}