#include "Person.h"
#include "Magician.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Knight.h"
#include "Monster.h"
#include <iostream>
int main (){
    //testing initializers and get functions

    //testing the default constructors
    //testing the get HP function, increase HP and decrease HP functions
    {//testing the get HP function for the Magician class 
    Person* Bot = new Magician("bot");
    if (Bot->getHP()!=100){
        std::cout<<"Test 1 failed"<<std::endl;
    }
    }
    {//testing the get HP function for the Warrior class 
        Person* Bot = new Warrior("bot");
        if (Bot->getHP()!=200){
            std::cout<<"Test 1.1 failed"<<std::endl;
        }
    }
    {//testing the get HP function-equivalence class for the Magician class 
        Person* Bot = new Magician("bot");
        Bot->decreaseHP(90);
        Bot->increaseHP(10);
        if (Bot->getHP()!=20){
            std::cout<<"Test 2 failed"<<std::endl;
        }
    }
    {//testing the get HP function-equivalence class for the Warrior class
    Person* Bot = new Warrior("bot");
    Bot->decreaseHP(190);
    Bot->increaseHP(10);
    if (Bot->getHP()!=20){
        std::cout<<"Test 2.1 failed"<<std::endl;
    }
    }
    {//testing the get HP function-neg Magician
    Person* Bot = new Magician("bot");
    Bot->decreaseHP(110);
    //Bot->increaseHP(10);
    if (Bot->getHP()!=0){
        std::cout<<"Test 3 failed"<<std::endl;
    }
    }
    {//testing the get HP function-neg Warrior
    Person* Bot = new Magician("bot");
    Bot->decreaseHP(210);
    //Bot->increaseHP(10);
    if (Bot->getHP()!=0){
        std::cout<<"Test 3.1 failed"<<std::endl;
    }
    }
    {//testing the get HP function-pos Magician
    Person* Bot = new Magician("bot");
    Bot->increaseHP(100);
    if (Bot->getHP()!=100){
        std::cout<<"Test 4 failed"<<std::endl;
    }
    }
    {//testing the get HP function-pos Warrior
    Person* Bot = new Warrior("bot");
    Bot->increaseHP(200);
    if (Bot->getHP()!=200){
        std::cout<<"Test 4.1 failed"<<std::endl;
    }
    }

    //testing the get MP function, increase MP and decrease MP functions
    {//testing the get MP function for the Magician class 
    Person* Bot = new Magician("bot");
    if (Bot->getMP()!=100){
        std::cout<<"Test 5 failed"<<std::endl;
    }
    }
    {//testing the get MP function for the Warrior class 
    Person* Bot = new Warrior("bot");
    if (Bot->getHP()!=200){
        std::cout<<"Test 5.1 failed"<<std::endl;
    }
    }
    {//testing the get  MP function-equivalence class for the Magician class 
    Person* Bot = new Magician("bot");
    Bot->decreaseMP(90);
    Bot->increaseMP(10);
    if (Bot->getMP()!=20){
        std::cout<<"Test 6 failed"<<std::endl;
    }
    }
    {//testing the get MP function-equivalence class for the Warrior class
    Person* Bot = new Warrior("bot");
    Bot->decreaseMP(190);
    Bot->increaseMP(10);
    if (Bot->getMP()!=20){
        std::cout<<"Test 6.1 failed"<<std::endl;
    }
    }
    {//testing the get MP function-neg Magician
    Person* Bot = new Magician("bot");
    Bot->decreaseMP(110);
    //Bot->increaseHP(10);
    if (Bot->getMP()!=0){
        std::cout<<"Test 7 failed"<<std::endl;
    }
    }
    {//testing the get MP function-neg Warrior
    Person* Bot = new Magician("bot");
    Bot->decreaseMP(210);
    //Bot->increaseHP(10);
    if (Bot->getMP()!=0){
        std::cout<<"Test 7.1 failed"<<std::endl;
    }
    }
    {//testing the get MP function-pos Magician
    Person* Bot = new Magician("bot");
    Bot->increaseMP(100);
    if (Bot->getMP()!=100){
        std::cout<<"Test 8 failed"<<std::endl;
    }
    }
    {//testing the get MP function-pos Warrior
    Person* Bot = new Warrior("bot");
    Bot->increaseMP(200);
    if (Bot->getMP()!=200){
        std::cout<<"Test 8.1 failed"<<std::endl;
    }
    }

    //testing the get Strength function for all classes
    {
        Person* Bot1 = new Magician("magician");
        Person* Bot2 = new Warrior("warrior");
        Person* Bot3 = new Wizard("wizard");
        Person* Bot4 = new Knight("knight");

        if (Bot1->getStrength()!=50){
            std::cout<<"Test 9 failed"<<std::endl;
        }
        if (Bot2->getStrength()!=100){
            std::cout<<"Test 9.1 failed"<<std::endl;
        }
        if (Bot3->getStrength()!=150){
            std::cout<<"Test 9.2 failed"<<std::endl;
        }
        if (Bot4->getStrength()!=200){
            std::cout<<"Test 9.3 failed"<<std::endl;
        }
    }


//testing the specific skills of different characters/classes

//testing the heal skill for macgician
    {
        Magician* Player = new Magician("Player");//equivalence class of positive reduction
        Player->decreaseHP(60);
        Player->heal();//Magician has a fixed strength of healing by 50 MP
        if (Player->getHP()!=90){
            std::cout<<"Test 10 failed!"<<std::endl;
        }
    }
    {   
        Magician* Player = new Magician("Player");//boundary class of transcending into negatives
        Player->decreaseHP(160);
        Player->heal();//Magician has a fixed strength of healing by 50 MP
        if (Player->getHP()!=50){
            std::cout<<"Test 10.1 failed!"<<std::endl;
        }
    }

    //testing the attack skill for magician and warrior
    {//for the Magician class
        Monster*  Bot = new Monster ("Bot");//equivalence class of positive remainder
        int n=Bot->getHP();
        Magician* Player = new Magician("Player");
        int m=Player->getStrength();
        Player->attack(Bot);//Magician has a fixed strength of attack by 50 MP
        if (Bot->getHP()!=(n-m)){
            std::cout<<"Test 11 failed!"<<std::endl;
        }
    }
    {//for the Magician class
        Monster*  Bot = new Monster (40,100,20,"Bot");//equivalence class of negative remainder
        int n=Bot->getHP();
        Magician* Player = new Magician("Player");
        int m=Player->getStrength();
        Player->attack(Bot);//Magician has a fixed strength of attack by 50 MP
        if (Bot->getHP()!=0){
            std::cout<<"Test 11.1 failed!"<<std::endl;
        }
    }
    {//for the Warrior class
        Monster*  Bot = new Monster ("Bot");//equivalence class of positive remainder
        int n=Bot->getHP();
        Warrior* Player = new Warrior("Player");
        int m=Player->getStrength();
        Player->attack(Bot);//Warrior has a fixed strength of attack by 100 MP
        if (Bot->getHP()!=(n-m)){
            std::cout<<"Test 11.2 failed!"<<std::endl;
        }
    }
    {//for the Warrior class
        Monster*  Bot = new Monster (90,100,20,"Bot");
        int n=Bot->getHP();
        Warrior* Player = new Warrior("Player");
        int m=Player->getStrength();
        Player->attack(Bot);//Warrior has a fixed strength of attack by 100 MP
        if (Bot->getHP()!=0){
            std::cout<<"Test 11.3 failed!"<<std::endl;
        }
    }

    //testing the advanced skill options
    //advanced heal for class wizard
    {
        Monster*  Bot = new Monster ("Bot");
        int n=Bot->getHP();
        Wizard* Player = new Wizard("Player");
        int m=Player->getStrength();
        int p= Player->getHP();
        Player->advancedHeal(Bot);
        if (Bot->getHP()!=(n-m)){
            std::cout<<"Test 12.a  failed!"<<std::endl;
        }
        if (Player->getHP()!=(300)){
            std::cout<<"Test 12.b  failed!"<<std::endl;
        }
    }
    {
        Monster*  Bot = new Monster ("Bot");
        int n=Bot->getHP();
        Wizard* Player = new Wizard("Player");
        Player->decreaseHP(100);
        int m=Player->getStrength();
        int p= Player->getHP();
        Player->advancedHeal(Bot);
        if (Bot->getHP()!=(n-m)){
            std::cout<<"Test 12.1.a  failed!"<<std::endl;
        }
        if (Player->getHP()!=(p+50)){
            std::cout<<"Test 12.1.b  failed!"<<std::endl;
        }
    }
    //advanced attack for class knight
    {//for the Warrior class
        Monster*  Bot = new Monster ("Bot");
        int n=Bot->getHP();
        Knight* Player = new Knight("Player");
        int m=Player->getStrength();
        Player->attack(Bot);//Warrior has a fixed strength of attack by 100 MP
        if (Bot->getHP()!=(n-m)){
            std::cout<<"Test 12.2 failed!"<<std::endl;
        }
    }
    }