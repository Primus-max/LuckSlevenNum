

#include <iostream>
using namespace std;

/// <summary>
/// Метод подсчёта числа на удачу
/// </summary>
/// <param name="num">Введённое пользователем число</param>
/// <returns>bool счастливое число или нет</returns>
bool CalcLuckNumber(int num) 
{
    const int maxSize = 6;    
    int count = 0;
    int number = num; // Создаю отдельную переменную, изменять входящий параметр - плохая практика
    int leftSide = 0;
    int rightSide = 0;

    while (number > 0 && count < maxSize)
    {
        int digit = number % 10; // Получаю последнюю циифру        

        if (count < (maxSize / 2))
            leftSide += digit;
        else
            rightSide += digit;
        
        ++count;

        number /= 10; // Убираю последнюю цифру из числа
    }

    return leftSide == rightSide ? true : false;
   
}

/// <summary>
/// Метод проверки введённого числа на его длину
/// </summary>
/// <param name="num">Введённое пользователем число</param>
/// <returns>bool валидность введённого числа</returns>
bool CheckLengthNum(int num) 
{
    const int maxSize = 6;
    int digits[maxSize];
    int count = 0;
    int number = num; // Создаю отдельную переменную, изменять входящий параметр - плохая практика

    while (number > 0 && count < maxSize)
    {
        int digit = number % 10; // Получаю последнюю циифру
        digits[count] = digit;

        ++count;

        number /= 10; // Убираю последнюю цифру из числа
    }
    
    return count == maxSize ? true : false;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    int userInputNum = 0;
    bool isInputValid = false;

    // Получаю ввод от пользователя
    while (!isInputValid)
    {
        cout << "Давай проверим твоё счастливое число, введи любое шестизначное число, например 123456 : ";
        cin >> userInputNum;

        isInputValid = CheckLengthNum(userInputNum);

        if (!isInputValid)
            cout << "Воодить нужно только шестизначное число, иначе удачу не проверить, попробуй ещё раз";
        else
            break;
    }
    
    bool isLuckNumber = CalcLuckNumber(userInputNum);

    if(isLuckNumber)
        cout << "Поздравляю, это число - счастливое, пользуйтесь им повсюду!" << endl;
    else
        cout << "К сожалению это не счастливое число, старайтесь его избегать" << endl;

    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;

}

