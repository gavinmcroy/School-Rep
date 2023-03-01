#include <iostream>
#include "Player.h"

using namespace std;

int main() {
    Player player;
    player.is_dead();
    player.talk("this means nothing");
    cout<<"Player health --->"<<player.get_health()<<endl;
    cout<<"Player XP "<<player.get_xp()<<endl;
    cout<<__cplusplus<<endl;

    return 0;
}
