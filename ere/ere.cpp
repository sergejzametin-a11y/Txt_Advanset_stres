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
    int steps;
};

struct door {

    string name;
    int loc1;
    int loc2;

};

struct PC {
    string name;
    int locate_current;
    int Hp;
    int Sre;
};

int Kilometr;
int memr_kilo;

string does;



world locate[5];

door step[10];



PC me[3];
void init_world() {
    locate[0].name = "Поляна";
    locate[0].origin = "Тихое место, наполненое травой, запах свежести и вызженной травы сучут вам в нос ";
    locate[0].loot = "Обычно много сухой травы и камней ";
    locate[0].check_peiper = "Вера, Кроль ";
    locate[0].id =0;
    locate[0].steps = 1;

    locate[1].name = "Озеро";
    locate[1].origin = "Небольшое тихое место в глубине леса, пахнет водой, под кроной деревьев здесь почти всегда тень ";
    locate[1].loot = "Много мха, и более нежных цветов ";
    locate[1].check_peiper = "Кроль ";
    locate[1].id = 1;
    locate[1].steps = 1;

    locate[2].name = "Дом";
    locate[2].origin = "Пустой и маленький, холоный подва, пыльный зал, спальня, лишь кухня с постаяным звоном посуды тут наполнена жизнью";
    locate[2].loot = "Еда, одежда ";
    locate[2].check_peiper = "Михаил ";
    locate[2].id = 2;
    locate[2].steps = 1;
   
    locate[3].name = "Главная площядь";
    locate[3].origin = "Когда-то шумное место, но в последнее время никого кроме 2 стариков тут и нет ";
    locate[3].loot = "Садовые приборы, дрова ";
    locate[3].check_peiper = "Георгий Флорит, Фристон ";
    locate[3].id = 3;
    locate[3].steps = 2;

    locate[4].name = "Крышная улица";
    locate[4].origin = "Старая уличка, судя по колличеству народа скоро станет новой Главной площадью ";
    locate[4].loot = "Здесь может найти что угодно, жаль не всегда ";
    locate[4].check_peiper = "Только Кроля здесь не найти ";
    locate[4].id = 4;
    locate[4].steps = 1;
  
    Kilometr = 2;
    memr_kilo = 2;
    me[0].locate_current = 3;

    step[0].name = "Свороток";
    step[0].loc1 = locate[3].id;
    step[0].loc2 = locate[4].id;

    step[1].name = "Лес";
    step[1].loc1 = locate[3].id;
    step[1].loc2 = locate[0].id;

    step[2].name = "Тропа";
    step[2].loc1 = locate[0].id;
    step[2].loc2 = locate[1].id;

    step[3].name = "Назад";
    step[3].loc1 = locate[me[0].locate_current].id;
    step[3].loc2 = locate[Kilometr].id;

    step[4].name = "Площядь";
    step[4].loc1 = locate[2].id;
    step[4].loc2 = locate[3].id;

    


}



void was() {
    cout << "Кстати ты здесь " << locate[me[0].locate_current].name << "\n";
    while (true)
    {

        step[3].loc1 = locate[me[0].locate_current].id;
        step[3].loc2 = locate[Kilometr].id;
        cout << "Куда же ты пойдёшь? \n Перед тобой \n";
        for (size_t i = 0; i < 10; i++)
        {
            if (step[i].loc1 == locate[me[0].locate_current].id) {
                cout << " " << step[i].name << "\n";

            };

        }
        cin >> does;

        if (Kilometr == locate[me[0].locate_current].id) {
            Kilometr = memr_kilo;
            step[3].loc2 = locate[Kilometr].id;
        }
        else
        { 
            memr_kilo = Kilometr;
            Kilometr = locate[me[0].locate_current].id;
            
        }

        if (does != "Остаться") {
            for (size_t j = 0; j < 10; j++)
            {
                if (does == step[j].name) { 
                    me[0].locate_current = step[j].loc2;
                }
            }

        }
        
        cout << "\nЛокация " << locate[me[0].locate_current].name << "\n\n" << "Описание: " << locate[me[0].locate_current].origin << "\n\n" << "Что есть: " << locate[me[0].locate_current].loot << "\n\n" << "Кто есть: " << locate[me[0].locate_current].check_peiper << "\n\n";


    }
};
int main() {
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    init_world();
    
    enum Menu{ Move, Shop ,Fight };
    Menu State = Move;

    switch (State)
    {
    case Move:{
        was();
        break;
    }

    default:
        break;
    }
  











}
