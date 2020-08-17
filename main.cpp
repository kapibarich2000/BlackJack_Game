#include <iostream>
#include <Game.h>
#include <UsefulFunctions.h>
#include <memory>

# define maxPlayers 7

// Future additions:

// Multiplayer
// GUI
// Make bet: 0,5 \ 1 \ 5 \ 10 \ 20 \ 50 \ 100



void showWelcomingSpeech(){
    std::cout<<"---------------------------------------------\n";

    std::cout<<"\n\n////  Welcome to the honest world of cards :) ////\n"<<
             "////  BlackJack, created by kapibarich2000, greet you ////\n\n";

    std::cout<<"Please Enter for control:\nh - for hit, s - for stand, d - for double "<<
             "e - for exit, c - for continue, i - for insurance, p - for payment\n\n";
}

void  start_SinglePlayer_Game(){

    showWelcomingSpeech();

    BlackJackGame game;

    game.addPlayers(std::make_shared<BlackJack_RealPlayer>());

    int number_of_AIPlayers;
    do {
        std::cout << "\nHow many AI players will play? :";
        number_of_AIPlayers = EnterInt();
        if (1+number_of_AIPlayers>maxPlayers) {
            std::cout << "The game didn't support so many participants !\n\n";
            continue;
        }
        break;
    }
    while (true);

    for (int i = 0; i < number_of_AIPlayers; ++i) {
        game.addPlayers(std::make_shared<BlackJack_AIPlayer>());
        std::cout<<std::endl; // For beauty
    }

    game.startGame();
}

void  start_Cooperative_Game(){

    showWelcomingSpeech();

    int number_of_humanPlayers;
    int number_of_AIPlayers;
    do{
        std::cout << "\nHow many real players will play? :";
        number_of_humanPlayers = EnterInt();
        std::cout << "\nHow many AI players will play? :";
        number_of_AIPlayers = EnterInt();
        if (number_of_humanPlayers+number_of_AIPlayers>maxPlayers){
        std::cout<<"The game didn't support so many participants !\n\n";
        continue;
        }
        break;
    }
    while (true);

    std::cout<<std::endl;

    BlackJackGame game;

    // Add humanPlayers
    for (int i = 0; i < number_of_humanPlayers; ++i) {
        game.addPlayers(std::make_shared<BlackJack_RealPlayer>());
        std::cout<<std::endl; // For beauty
    }


    for (int i = 0; i < number_of_AIPlayers; ++i) {
        game.addPlayers(std::make_shared<BlackJack_AIPlayer>());
        std::cout<<std::endl; // For beauty
    }

    game.startGame();
}


int main() {
    int Selection_of_games;
    std::cout<<"SinglePlayer: 1\n"
                <<"Cooperative: 2\n"
                <<"Multiplayer: 3\n"
                <<"Please enter a game mode:";
    std::cin>>Selection_of_games;
    switch (Selection_of_games) {
        case 1:
            start_SinglePlayer_Game();
            break;
        case 2:
            start_Cooperative_Game();
            break;
        case 3:
            std::cout<<"Expected in the following patches!\n";
            break;
        default:
            break;
    }

    std::cout<<"\nAll the best!\n";

    return 0;
}