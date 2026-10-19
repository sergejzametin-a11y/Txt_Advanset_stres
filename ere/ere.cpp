#include <iostream>
#include <windows.h>

using namespace std;


struct world
{
    string name;
    string origin;
    string loot;
    string check_peiper;
    int id;
};

struct PC {
    string name;
    int locate_current;
    int Hp;
    int Sre;
};

int Kilometr;


string does;



world locate[5];
PC me[3];
void init_world() {
    locate[0].name = "Поляна";
    locate[0].origin = "Тихое место, наполненое травой, запах свежести и вызженной травы сучут вам в нос ";
    locate[0].loot = "Обычно много сухой травы и камней ";
    locate[0].check_peiper = "Вера, Кроль ";
    locate[0].id = 0;

    locate[1].name = "Озеро";
    locate[1].origin = "Небольшое тихое место в глубине леса, пахнет водой, под кроной деревьев здесь почти всегда тень ";
    locate[1].loot = "Много мха, и более нежных цветов ";
    locate[1].check_peiper = "Кроль ";
    locate[1].id = 1;

    locate[2].name = "Дом";
    locate[2].origin = "Пустой и маленький, холоный подва, пыльный зал, спальня, лишь кухня с постаяным звоном посуды тут наполнена жизнью";
    locate[2].loot = "Еда, одежда ";
    locate[2].check_peiper = "Михаил ";
    locate[2].id = 2;
   
    locate[3].name = "Главная площядь";
    locate[3].origin = "Когда-то шумное место, но в последнее время никого кроме 2 стариков тут и нет ";
    locate[3].loot = "Садовые приборы, дрова ";
    locate[3].check_peiper = "Георгий Флорит, Фристон ";
    locate[3].id = 3;

    locate[4].name = "Крышная улица";
    locate[4].origin = "Старая уличка, судя по колличеству народа скоро станет новой Главной площадью ";
    locate[4].loot = "Здесь может найти что угодно, жаль не всегда ";
    locate[4].check_peiper = "Только Кроля здесь не найти ";
    locate[4].id = 4;
  
    Kilometr = 0;
    me[0].locate_current = 3;

}



void was() {
    cout << "Кстати ты здесь " << locate[me[0].locate_current].name << "\n";
    while (true)
    {
        


        cout << "Куда же ты пойдёшь? \n в памяти у тебя лишь \n";
        for (size_t i = 0; i < 5; i++)
        {
            cout<< "\t" << locate[i].name << " \t" << locate[i].origin << "\n";
        }
        cin >> does;
        
        if (does != locate[me[0].locate_current].name) {
            for (size_t j = 0; j < 5; j++)
            {
                if (does == locate[j].name) {
                    me[0].locate_current = locate[j].id;
                }
            }
            if (locate[me[0].locate_current].id == locate[1].id && Kilometr == 0) {
                cout << "Путь лежит через Поляну поэто мы ты направляещься туда ";
                me[0].locate_current = locate[0].id;
                Kilometr = 1;
           }
            
        }
        if (Kilometr == 1) {
            Kilometr = 0;
        }
  
        cout << "\nЛокация " << locate[me[0].locate_current].name << "\n\n" << "Описание: "<< locate[me[0].locate_current].origin<< "\n\n" << "Что есть: " << locate[me[0].locate_current].loot << "\n\n" << "Кто есть: " << locate[me[0].locate_current].check_peiper <<"\n\n";


    }




}







int main() {
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    init_world();
    was();
}
