#include <cstdio>

#include "monster.h"
#include "global.h"

Monster::Monster(const char* name, int heart, int attack, int defence, int money, std::vector<PIMAGE>* FS) {
    transparent = 0;
    sprintf(this->name, "%s", name);
    this->heart = heart;
    this->attack = attack;
    this->defence = defence;
    this->money = money;
    FACE = FS;
    time = 0;
    selected = 0;
}

int Monster::react() {
    int enemyHurt = ((attack - Defence) > 0 ? (attack - Defence) : 0);
    int myHurt = ((Attack - defence) > 0 ? (Attack - defence) : 0);
    int tmpMonsterHeart = heart;
    while (Health > 0) {
        tmpMonsterHeart -= myHurt;
        if(tmpMonsterHeart <= 0)
            break;
        Health -= enemyHurt;
    }

    if (tmpMonsterHeart > 0){
        Health = 0;
        return -1;
    }

    Money += money;
    sprintf(underWord, "Beat %s, get %d coin", name, money);
    return 1;
}

int Monster::putSelfImg(int x, int y) {
    putimage_withalpha(NULL, (*FACE)[selected], x, y);
    time ++;
    if(time > 30){
        selected = (selected+1)%((*FACE).size());
        time = 0;
    }
    return 0;
}

Space* Monster::death(){
    return new Monster_Death();
}

Monster* monsterGroup[monsterNum];

Boss::Boss(const char* name, int heart, int attack, int defence, int money, std::vector<PIMAGE>* FS) {
    transparent = 0;
    sprintf(this->name, "%s", name);
    this->heart = heart;
    this->attack = attack;
    this->defence = defence;
    this->money = money;
    FACE = FS;
    time = 0;
    selected = 0;
}

int Boss::react() {
    int enemyHurt = ((attack - Defence) > 0 ? (attack - Defence) : 0);
    int myHurt = ((Attack - defence) > 0 ? (Attack - defence) : 0);
    int tmpBossHeart = heart;
    while (Health > 0) {
        tmpBossHeart -= myHurt;
        if(tmpBossHeart <= 0)
            break;
        Health -= enemyHurt;
    }

    if (tmpBossHeart > 0){
        Health = 0;
        return -1;
    }

    Money += money;
    sprintf(underWord, "Beat %s, get %d coin", name, money);
    return 1;
}

int Boss::putSelfImg(int x, int y) {
    putimage_withalpha(NULL, (*FACE)[selected], x, y);
    time ++;
    if(time > 30){
        selected = (selected+1)%((*FACE).size());
        time = 0;
    }
    return 0;
}

Space* Boss::death(){
    return new Monster_Death();
}

Boss * bossp = NULL;