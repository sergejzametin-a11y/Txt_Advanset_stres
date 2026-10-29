#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

enum Menu { Move, Shop, Fight, In_place, Inventar };
Menu State = Move;
Menu mem_state;

struct Stuff
{
    string name;
    string original;
    string unic;
    int sress;
    int id;
};

struct world
{
    string name;
    string origin;
    string desc_loot;
    string check_peiper;
    int id;
    int steps;
    vector<int> list_loot;
    
};

struct door {

    string name;
    int loc1;
    int loc2;
    int lock;

};


struct PC {
    string name;
    int locate_current;
    int Hp;
    int Sre;
};


struct invent {
    vector<int> loot;
    


};



int Kilometr;
int memr_kilo;


int use;

int cloc;

invent invetar;
string does;

Stuff thing[10];

world locate[5];

door step[10];

vector<Stuff> loot;

PC me[3];
void init_world() {
    locate[0].name = "Поляна";
    locate[0].origin = "Тихое место, наполненое травой, запах свежести и вызженной травы сучут вам в нос ";
    locate[0].desc_loot = "Обычно много сухой травы и камней ";
    locate[0].check_peiper = "Вера, Кроль ";
    locate[0].id =0;
    locate[0].steps = 1;
    locate[0].list_loot.push_back({1});
    locate[0].list_loot.push_back({2});
    locate[0].list_loot.push_back({3});
   

    locate[1].name = "Озеро";
    locate[1].origin = "Небольшое тихое место в глубине леса, пахнет водой, под кроной деревьев здесь почти всегда тень ";
    locate[1].desc_loot = "Много мха, и более нежных цветов ";
    locate[1].check_peiper = "Кроль ";
    locate[1].id = 1;
    locate[1].steps = 1;

    locate[2].name = "Дом";
    locate[2].origin = "Пустой и маленький, холоный подва, пыльный зал, спальня, лишь кухня с постаяным звоном посуды тут наполнена жизнью";
    locate[2].desc_loot = "Еда, одежда ";
    locate[2].check_peiper = "Михаил ";
    locate[2].id = 2;
    locate[2].steps = 1;
   
    locate[3].name = "Главная площядь";
    locate[3].origin = "Когда-то шумное место, но в последнее время никого кроме 2 стариков тут и нет ";
    locate[3].desc_loot = "Садовые приборы, дрова ";
    locate[3].check_peiper = "Георгий Флорит, Фристон ";
    locate[3].id = 3;
    locate[3].steps = 2;

    locate[4].name = "Крышная улица";
    locate[4].origin = "Старая уличка, судя по колличеству народа скоро станет новой Главной площадью ";
    locate[4].desc_loot = "Здесь может найти что угодно, жаль не всегда ";
    locate[4].check_peiper = "Только Кроля здесь не найти ";
    locate[4].id = 4;
    locate[4].steps = 1;
  
    Kilometr = 2;
    memr_kilo = 2;
    me[0].locate_current = 0;

    step[0].name = "Свороток";
    step[0].loc1 = locate[3].id;
    step[0].loc2 = locate[4].id;
    step[0].lock = 0;

    step[1].name = "Лес";
    step[1].loc1 = locate[3].id;
    step[1].loc2 = locate[0].id;
    step[1].lock = 0;

    step[2].name = "Кусты";
    step[2].loc1 = locate[0].id;
    step[2].loc2 = locate[1].id;
    step[2].lock = 1;

    step[3].name = "Назад";
    step[3].loc1 = locate[me[0].locate_current].id;
    step[3].loc2 = locate[Kilometr].id;
    step[3].lock = 0;

    step[4].name = "Площядь";
    step[4].loc1 = locate[2].id;
    step[4].loc2 = locate[3].id;
    step[4].lock = 0;

    loot.push_back({ "","","",0,-1 });
    loot.push_back({ "","","",0,0 });
    loot.push_back({"Стекло","Остый кусок стекла, для боя не подойдёт, сам изрежишь руку","Однаразовый",10,1});
    loot.push_back({ "Мох","Мягкий, зелёный, очень приятный на ощуп","Нет",-2,2 });
    loot.push_back({ "Цветок","Нежный и маленький елый бутон пахнет мёдом","Однаразовый",-5,3 });

    

    cloc = 10;
    invetar.loot.push_back({ 0 });
    invetar.loot.push_back({ 1 });
    invetar.loot.push_back({ 2 });
    use = 0;
    mem_state = Move;
}



void was() {
    cout << "\n Кстати ты здесь " << locate[me[0].locate_current].name << "\n\n";
    while (true)
    {
        
        step[3].loc1 = locate[me[0].locate_current].id;
        step[3].loc2 = locate[Kilometr].id;
        cout << "Куда же ты пойдёшь? \n Перед тобой \n\n";
        for (size_t i = 0; i < 10; i++)
        {
            if (step[i].loc1 == locate[me[0].locate_current].id) {

                
                    cout << " " << step[i].name << "\n";
              

            };

        }
        cout << "Или хочешь остаться?\n\nСуммка\n\n";

        
        cin >> does;
        cout << "\n\n";
        if (does == "Суммка")
        {
            mem_state = State;
            State = Inventar;
        }
        if (Kilometr == locate[me[0].locate_current].id) {
            Kilometr = memr_kilo;
            step[3].loc2 = locate[Kilometr].id;
        }
        else
        { 
            memr_kilo = Kilometr;
            Kilometr = locate[me[0].locate_current].id;
            
        }

        if (does != "Остаться") 
        {
            for (size_t j = 0; j < 10; j++) 
            {
            

                if (does == step[j].name) { 

                    if (step[j].lock == 0)
                    {
                        me[0].locate_current = step[j].loc2;
                    }
                    else {
                        for (size_t iv = 0; iv < invetar.loot.size(); iv++)
                        {
                            if (invetar.loot[iv] == step[j].lock) {
                                cout<< "\tТы используешь " << loot[iv-1].name << "\n\n";
                                invetar.loot.erase(remove(invetar.loot.begin(), invetar.loot.end(), iv), invetar.loot.end());
                                cout << "Что бы пройти " << step[j].name << "\n";
                                use = 1;
                                me[0].locate_current = step[j].loc2;

                            }
                            
                        }
                        if (use == 0)
                        {
                            
                            cout << "Нет нужного предмета\n\n";
                        }
                        else 
                        {
                            use = 0;
                        }

                    }

                    
                }
            }
        }
        else { 

            
            State = In_place;
        }
        cout << "\nЛокация " << locate[me[0].locate_current].name << "\n\n" << "Описание: " << locate[me[0].locate_current].origin << "\n\n" << "Что есть: " << locate[me[0].locate_current].desc_loot << "\n\n" << "Кто есть: " << locate[me[0].locate_current].check_peiper << "\n\n";
        return;

        
    }

    
};
void plase() {

    while (true)
    {
        cout << "Ваши действия?\n\n  Осматрерться \n  Уйти \n  Подаждать\n\nСуммка\n\n";
        cin >> does;
        cout << "\n\n";
        if (does == "Суммка")
        {
            mem_state = State;
            State = Inventar;
        }
        if (does != "Уйти") {
            if (does == "Подаждать") {
                cloc += 1;
            }
            else {
                while (true)
                {
                    cout << "Ты видишь:\n-------------------------------------------\n";
                    for (size_t z = 0; z < locate[me[0].locate_current].list_loot.size(); z++)
                    {
                        cout << loot[z].name << "\n";

                    }
                    cout << "Ничего\n-------------------------------------------\n";
                    cout << "Что взять?\n\n";
                    cin >> does;
                    cout << "\n\n";
                    if (does!="Ничего")
                    {
                        for (size_t z = 0; z < locate[me[0].locate_current].list_loot.size(); z++)
                        {
                            if (does == loot[z].name) {
                                invetar.loot.push_back({ loot[z].id });
                                cout << "\tТы взял " << loot[z].name << "\n\n";
                            }

                        }
                    }
                    else {
                        State = Move;
                        break;
                    }
                    
                    




                }
                

            






            }

        }
        else {
            State = Move;
            return;
        }





    }
    





};
void bag() 
{
    while (true)
    {
        cout << "\nУ тебя в карманах\n\n---------------------------------------\n";
        for (size_t y = 0; y < invetar.loot.size(); y++)
        {
            cout << loot[y].name << "\n";


        }

        cout << "---------------------------------------\n\n";
        State = mem_state;
        return;
    }
    



}




int main() {
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    init_world();
    
    

    while (true)
    {
        switch (State)
        {
        case Move:
        {
            was();
            break;
        }
        case In_place:
        {
            plase();
            break;
        }
        case Inventar:
        {
            bag();
            break;
        }

        default:
            break;
        }
    } 
  











}
