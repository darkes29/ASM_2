#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "");
    int x, rez = 0; 
    cout << "Введите переменную x ";
    cin >> x;
    _asm {

    //        |x-1, if x<0 
    //     y =|2x + 2, if x>0
    //        |34x-5, if x=0

        XOR EAX,EAX
        XOR EBX, EBX
        MOV EAX, x
        PUSH EAX
        cmp x, 0
        jl Low1
        jg Great
        je Zero
        Low1:
        SUB EAX, 1
        MOV EBX, EAX
        jmp EXIT
        Great:
        IMUL EAX, 2
        ADD EAX, 2
        MOV EBX, EAX
        jmp EXIT
        Zero:
        IMUL EAX, 34
        SUB EAX, 5
        MOV EBX,EAX
        jmp EXIT
        EXIT:
        MOV rez, EBX
        XOR EAX, EAX
        POP EAX
    }
    cout << "Введеное число " << x  << ", результат = " << rez  << endl;
}