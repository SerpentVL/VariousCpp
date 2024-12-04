/// Быки и коровы - консоль
/// Герб Саттер. Решение сложных задач на С++. Задча 1.18.

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
// -----
#include <ctime>
#include <cstdlib>
// -----
using namespace std;

using M = map<int, int>;

class ChoosePeg{
};

class CountPlace{
};

class CountColor{
};

int main(){
    cout << "Bulls and Cows\n";
    const string colors ("RGB");
    M cm, gm;
    int cok, pok = 0;
    string comb(4,'.'),
           guess;
    /// инициализация гсч
    generate(comb.begin(), comb.end(), ChoosePeg(colors));

    while(pok < comb.size())
        cout << "\n\nguess-->",
        cin >> guess,
        guess.resize(comb.size()),      /// это поменять
        cm = gm = M(),
        transform(comb.begin(), comb.end(),
                  guess.begin(), guess.end(),
                  CountPlace(cm,gm,pok)),
        for_each(colors.begin(), colors.end(),
                 CountColor(cm,gm,cok)),
        cout << cok << ' ' << pok;
    cout << " - solved!\n";
    return 0;
}
