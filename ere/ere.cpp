#include <iostream>

void TTK() {

    srand(time(0));
    int streng = 100;
    int base_damag_tool = 50;
    int crit_chan = 15;
    int crit_mun = 2;
    int k = 1;

    int border = 30;
    int resistant = 20;
    int chent_doje = 15;
    int hp = 500;

    int random = 1 + rand() % 100;
    int random_dj = 1 + rand() % 100;

    int final_damage = streng + base_damag_tool;
    if (random <= crit_chan) {
        final_damage *= crit_mun;
    }

    float mu_resist = ((float)resistant / 100);

    int final_resist = (final_damage)*mu_resist;

    int final_damage_result = (final_damage)-mu_resist - border;

    if (random_dj <= chent_doje) {
        final_damage_result *= 0;

    }

    hp -= final_damage_result;

    std::cout << hp;
}

void Rule_Systems() {

    srand(time(0));
    int wihs = rand() % 2;
    int money = rand() % 151;
    int pass = 0;//rand() % 2;
    int уhrlichkeit = 1 + rand() % 100;
    int stop = 0;

    if (pass > 0) {
        std::cout << "Good, go in -sec";

    }
    else {

        if (уhrlichkeit <= 30) {
            std::cout << "To take a bribe? -sec \n";
            if (money >= 100) {
                std::cout << "Good, money, go in -sec";
                stop += 1;
            }
            else {
                std::cout << "Bad -sec";
                stop += 1;
            }
        }
        if (wihs > 0 and money >= 75 and stop < 1) {
            std::cout << "To take a bribe? -you \n";
            if (уhrlichkeit < 70) {
                std::cout << "Ok, go in -sec";
                stop += 1;
            }
            else {
                std::cout << "You'r a stupid, NO -sec";
                stop += 1;
            }
        }
        if (stop < 1) {
            std::cout << "no pass? go out -sec";
        }
    }

}

void Gussenum() 
{
    srand(time(0));
    int plaer_num =1;
    int life = 5;
    int passvort = 1 + rand() % 100;
    int lair;
    int got = 0;
    std::cout << "trau: 5. Range: 1-100 \n ";

    while (life > 0) {
        std::cin >> plaer_num;
        lair = 1 + rand() % 100;
        if (plaer_num == passvort) {
            std::cout << "Dotha\n";
            life = 0;
            got = 1;
        }
        else if (plaer_num > passvort) {
            if (lair > 69) {
                std::cout << "small(l) \n";
                life -= 1;
            }
            else {
                std::cout << "big\n";
                life -= 1;
            
            }
            
            
        }
        else if (plaer_num < passvort) {
            if (lair > 69) {
                std::cout << "big(l) \n";
                life -= 1;
            }
            else {
                std::cout << "small\n";
                life -= 1;

            }

        }
       

    }
    if (got == 0) {
        std::cout << passvort;
    }

}

void mlv() {

    int mele;
    int range;
    int kon;

    struct Unit {

        std::string name;
        int damage;
        int Hp;

    };

    Unit Pers[4];

    Pers[0].name = "kon";
    Pers[0].Hp = 100;
    Pers[0].damage = 12;

    Pers[1].name = "Mele";
    Pers[1].Hp = 100;
    Pers[1].damage = 10;

    Pers[2].name = "rangar";
    Pers[2].Hp = 100;
    Pers[2].damage = 14;

    Pers[3].name = "Sper";
    Pers[3].Hp = 100;
    Pers[3].damage = 13;

    //int itog[3][3]
    //{
    //    {0,1,2},
    //    {2,0,1},
    //    {1,2,0}
    //
    //};

    for (int i = 0; i < 4;i++) {

        std::cout << "name " << Pers[i].name << "\t Hp " << Pers[i].Hp << "\t Damage " << Pers[i].damage << "\n";

    }
    int plaer1;
    int plaer2;
    std::cout << "coohes player 1 \n 1-kon \n 2-mele \n 3-rangar\n 4-Sper \n";
    std::cin >> plaer1;
    std::cout << "coohes player 2 \n 1-kon \n 2-mele \n 3-rangar\n 4-Sper \n";
    std::cin >> plaer2;

    plaer1 -= 1;
    plaer2 -= 1;


    if ((plaer1 == 2 || plaer1 == 1) && (plaer2 == 2 || plaer2 == 1)) {
        Pers[1].damage = Pers[1].damage * 1.5;
    }

    //if (itog[plaer1][plaer2] == 0) {
    //
    //
    //}

    std::cout << "Hp1 " << Pers[plaer1].Hp << "\n";
    std::cout << "Dm1 " << Pers[plaer1].damage << "\n";   //ПРОВЕРКА СТАТ БЛОКА ПЕРЕД БОЕМ
    std::cout << "Hp2 " << Pers[plaer2].Hp << "\n";
    std::cout << "Dm2 " << Pers[plaer2].damage << "\n";

    while (Pers[0].Hp > 0 && Pers[1].Hp > 0 && Pers[2].Hp > 0)
    {
        Pers[plaer1].Hp -= Pers[plaer2].damage;
        //std::cout << "Hp1 " << Pers[plaer1].Hp << "\n";  //ПРОВЕРКА ХП В БОЮ
        Pers[plaer2].Hp -= Pers[plaer1].damage;
        //std::cout << "Hp2 " << Pers[plaer2].Hp << "\n";  //ПРОВЕРКА ХП В БОЮ
    }
    if (Pers[plaer1].Hp == Pers[plaer2].Hp) {
        std::cout << "Draw!";
    }
    else if (Pers[plaer1].Hp > Pers[plaer2].Hp)
    {
        std::cout << "Plaer 1 Win";
    }
    else if (Pers[plaer2].Hp > Pers[plaer1].Hp) {

        std::cout << "Plaer 2 Win";

    }

}


void Resource_Management() {

    struct Store {
        std::string name;
        int price;
        int heft;
        int col;
    };

    Store Stuff[3];

    Stuff[0].name = "Poison";
    Stuff[0].heft = 1;
    Stuff[0].col = 10;
    Stuff[0].price = 500;

    Stuff[1].name = "Sowrld";
    Stuff[1].heft = 10;
    Stuff[1].col = 10;
    Stuff[1].price = 3000;

    Stuff[2].name = "Shield";
    Stuff[2].heft = 8;
    Stuff[2].col = 10;
    Stuff[2].price = 2500;

    int helf = 15;
    int money = 400;
    int does = -1;

    //на вопрос первый да
    //на второй вопрос ответ 2 зелья и 1 меч

    while (does != 9)
    {
        for (size_t i = 0; i < 3; i++)
        {
            if (Stuff[i].col <= 0) {
                Stuff[i].col = 1;
            }

            Stuff[0].price = 500 / Stuff[0].col;
            Stuff[1].price = 3000 / Stuff[1].col;
            Stuff[2].price = 2500 / Stuff[2].col;
            std::cout << "Name " << Stuff[i].name << "\nHelf " << Stuff[i].heft << "\nPrice " << Stuff[i].price << "\n \n";
            if (i == 2) {
                std::cout << "buy poisen-1 \n" << "buy sworld-2 \n" << "buy shield-3 \n \n" << "Sell poisen-4 \n" << "Sell sworld-5 \n" << "Sell shield-6 \n" << "Money " << money << "\n" << "Helf " << helf << "\n \n";
                std::cin >> does;
            }
        }
        if (does < 3) {
            if (does == 1) {
                money -= 500 / Stuff[0].col;
                helf -= 1;
                Stuff[0].col -= 1;
            }
            if (does == 2) {
                money -= 3000 / Stuff[1].col;
                helf -= 10;
                Stuff[1].col -= 1;
            }
            if (does == 3) {
                money -= 5000 / Stuff[2].col;
                helf -= 8;
                Stuff[2].col -= 1;
            }

        }
        else
        {
            if (does == 4) {

                money += 500 / Stuff[0].col;
                Stuff[0].col += 1;
            }
            if (does == 5) {

                money += 3000 / Stuff[1].col;
                Stuff[1].col += 1;

            }
            if (does == 6) {

                money += 2500 / Stuff[2].col;
                Stuff[2].col += 1;

            }

        }
        if (money < 0) {
            does = 9;
            std::cout << "you are in credit!";
        }
        if (money == 0) {
            std::cout << "sell stuff for money";
        }
        if (helf < 0) {
            does = 9;
            std::cout << "died from being overweight";
        }
        if (money == 0) {
            std::cout << "you are full";
            does = 9;
        }



    }
}

void tree() {

    float damage = 10;
    float protect = 0;
    int Was = 0;
    int Skill_sworld = 0;
    int Skill_Shild = 0;
    int f = 0;
    int skill_point = 0;

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "Ll " << i + 1 << "\n" << "Sword skill lv " << Skill_sworld << "\n" << "shild skill lv " << Skill_Shild << "\n";
        skill_point += 1;
        std::cout << "press 1 to lv up sworld\t press 2 to lv up shild\n\n";
        if (Skill_sworld > -1) {
            std::cout << "Sword +\n Damege +10% \n";
            if (Skill_sworld > 0) {
                std::cout << "Have\n\n";
            }
            else
            {
                std::cout << "price: 1\n\n";
            }
            if (Skill_sworld >= 1) {
                std::cout << "Sword master? \n Damege +20%\n";
                if (Skill_sworld >= 2) {
                    std::cout << "Have\n\n";
                }
                else
                {
                    std::cout << "price: 1\n\n";
                }
            }
            if (Skill_sworld >= 2) {
                std::cout << "Sword MASTER! \n Damege +30%\n New hit\n";
                if (Skill_sworld >= 3) {
                    std::cout << "Have\n\n";
                }
                else
                {
                    std::cout << "price: 1\n\n";
                }
            }
        }
        if (Skill_Shild > -1) {
            std::cout << "Shild +\n protect +5% \n";
            if (Skill_Shild > 0) {
                std::cout << "Have\n\n";
            }
            else
            {
                std::cout << "price: 1\n\n";
            }
            if (Skill_Shild >= 1) {
                std::cout << "Streel shild \n protect +10%\n";
                if (Skill_Shild >= 2) {
                    std::cout << "Have\n\n";
                }
                else
                {
                    std::cout << "price: 1\n\n";
                }
            }
            if (Skill_Shild >= 2) {
                std::cout << "GODNESS PROTECT! \n protect +30%\n Bloc shild\n";
                if (Skill_Shild >= 3) {
                    std::cout << "Have\n\n";
                }
                else
                {
                    std::cout << "price: 1\n\n";
                }
            }
        }
        std::cout << "Skill point: " << skill_point << "\n\n";





        std::cin >> Was;
        std::cout << "/////////////////////////////////\n";

        if (Was == 1) {
            Skill_sworld += 1;
            skill_point -= 1;

            damage = 10 * (1 + (float)Skill_sworld / 10);

        }
        else {
            Skill_Shild += 1;
            skill_point -= 1;
            protect = 5 * Skill_Shild;
        }

    }

    std::cout << "\nSats \n Damage " << damage << "\n defence " << protect << "%";
    if (Skill_sworld >= 3) {
        std::cout << "\nHit 2\n";
    }
    if (Skill_Shild >= 3)
    {
        std::cout << "\nBloc shild\n";
    }

}



void Itog() {

   
    struct RPS {
        std::string name;
        int Strengit;
        int Hp;
        int Speed;
    };
    int pers = 0;
    RPS Units[3];

    Units[0].name = "Paper";
    Units[0].Strengit = 10;
    Units[0].Hp = 100;
    Units[0].Speed = 1;

    Units[1].name = "Rock";
    Units[1].Strengit = 10;
    Units[1].Hp = 100;
    Units[1].Speed = 1;

    Units[2].name = "Scissors";
    Units[2].Strengit = 10;
    Units[2].Hp = 100;
    Units[2].Speed = 1;

    for (int i = 0; i < 3;i++) {

        std::cout << "name " << Units[i].name << "\t Hp " << Units[i].Hp << "\t Strengit " << Units[i].Strengit << "\nSpeed " << Units[i].Speed << "\n";

    }

    srand(time(0));
    int Var = rand() % 3;


    std::cout << "\n Your aponent a " << Units[Var].name << "\nshooce the unit and a poison\n Perper -1 \n Rokc -2\n Scissors -3\n";
    int money = 0;
    int stuff;
    int memori = 0;
    int memori_plaer = 0;
    int skill_point = 0;
    int k_win = 0;
    std::cin >> pers;
    pers -= 1;



    std::cout << "1-water: Perper Hp -50 \t 2-Pressa: Rokc Hp -50 \t 3-Rust: Scissors Hp -50\n";
    std::cin >> stuff;
    Units[stuff - 1].Hp -= 50;
    std::cout << "\nRaund 1\n";
    memori = Units[Var].Hp;
    memori_plaer = Units[pers].Hp;
    while (Units[Var].Hp > 0 && Units[pers].Hp > 0)
    {
        
        Units[Var].Hp -= Units[pers].Strengit;
        Units[pers].Hp -= Units[Var].Strengit;
        std::cout << "Hp Vrraga " << Units[Var].Hp << "\n";
        std::cout << "Hp plear " << Units[pers].Hp <<"\n\n";
    }
    if (Units[Var].Hp < Units[pers].Hp) {
        std::cout << "\nWIN\n";
        k_win = 1;
    }
    else
    {
        std::cout << "\nLOSE\n";
    }
    Units[Var].Hp = memori;
    Units[pers].Hp= memori_plaer;
    std::cout << "\nRaund 2";
    srand(time(0));
    Var = rand() % 3;
    std::cout << "\n Your aponent a " << Units[Var].name;
    memori = Units[Var].Hp;
    if (k_win > 0) {
        std::cout << "\nYou are Lvl up!\n Chosse skill\n Paint: Peipar +50 strenget \t Rock&Roll: Rokc +50 strenget\t Glass: Scissors Strenget +50 \n";
        std::cin >> stuff;
        Units[stuff - 1].Strengit += 50;
    }
    std::cout << "\nshooce the unit and a poison\n Perper -1 \n Rokc -2\n Scissors -3\n";
    std::cin >> pers;
    pers -= 1;
    memori_plaer = Units[pers].Hp;
    while (Units[Var].Hp > 0 && Units[pers].Hp > 0)
    {
        
        Units[Var].Hp -= Units[pers].Strengit;
        Units[pers].Hp -= Units[Var].Strengit;
        std::cout << "Hp Vrraga " << Units[Var].Hp << "\n";
        std::cout << "Hp plear " << Units[pers].Hp << "\n\n";
        
    }
    if (Units[Var].Hp < Units[pers].Hp) {
        std::cout << "\nWIN\n Yre are still s money\n";
        money += 100;
    }
    else
    {
        std::cout << "\nLOSE\n";
    }
    Units[Var].Hp=memori;
    Units[pers].Hp=memori_plaer;
    std::cout << "\nRaund 3";
    srand(time(0));
    Var = rand() % 3;
    std::cout << "\n Your aponent a " << Units[Var].name;
    memori = Units[Var].Hp;
    Units[pers].Hp = memori_plaer;
    if (k_win > 0) {
        std::cout << "\nYou in the store\n Chosse stuff\n Pen: Peipar +1 speed \t Balls: Rokc +1 seed\t Oil: Scissors +1 speed \n pries 100\n money"<< money<< "\n";
        std::cin >> stuff;
        if (money == 100) { Units[stuff - 1].Speed += 1; }
        else
        {
            std::cout << "YOU ARE BROAT";
        }
    }
    std::cout << "\nshooce the unit and a poison\n Perper -1 \n Rokc -2\n Scissors -3\n";
    std::cin >> pers;
    pers -= 1;
    while (Units[Var].Hp > 0 && Units[pers].Hp > 0)
    {
        
        Units[Var].Hp -= Units[pers].Strengit*Units[pers].Speed;
        Units[pers].Hp -= Units[Var].Strengit*Units[Var].Speed;
        std::cout << "Hp Vrraga " << Units[Var].Hp << "\n";
        std::cout << "Hp plear " << Units[pers].Hp << "\n\n";
        
    }
    if (Units[Var].Hp < Units[pers].Hp) {
        std::cout << "\nWIN\n Yre are still s money";
        money += 100;
    }
    else
    {
        std::cout << "\nLOSE\n";
    }
    
}



int main() {

    //Itog();
    //tree();
    //Resource_Management();
    //mlv();
    //TTK();
    //Gussenum();
    //Rule_Systems();
}
