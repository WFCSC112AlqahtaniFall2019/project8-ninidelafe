#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <string>
#include "Data.h"

using namespace std;

int main() {

    Data other;
    stack <Data> stack1;
    queue <Data> queue1;
    priority_queue <Data> priorityQueue1;

    ifstream in;
    ofstream outStack;
    ofstream outQueue;
    ofstream outPriority;

    //Opens all the files
    in.open ("../WorldHappiness2015.csv");
    outStack.open("Stack.txt");
    outQueue.open("Queue.txt");
    outPriority.open("Sorted.txt");

    //checks to make sure the files opened correctly
    if(!in.is_open()){
        cout<<"Input file did not open!!"<<endl;
        return 1;
    }
    if(!outStack.is_open()){
        cout<<"Stack output file did not open!!"<<endl;
        return 2;
    }
    if(!outQueue.is_open()){
        cout<<"Queue output file did not open!!"<<endl;
        return 3;
    }
    if(!outPriority.is_open()){
        cout<<"Sorted output file did not open!!"<<endl;
        return 4;
    }

    cout<<"All files are opened!"<<endl<< "../WorldHappiness2015.csv is being read"<<endl;

    //prints a title line in each file
    outQueue<<"Country: Happiness Rate, Happiness Score, GDP per Capita, Life Expectancy"<<endl;
    outStack<<"Country: Happiness Rate, Happiness Score, GDP per Capita, Life Expectancy"<<endl;
    outPriority<<"This list is sorted by GDP per Capita"<<endl;
    outPriority<<"Country: Happiness Rate, Happiness Score, GDP per Capita, Life Expectancy"<<endl;


    while (!in.eof()) {
        //i++;
        //cout<<"In while loop! i= "<< i; //<< endl;

        //getline will go until the comma then move on
        string crty, haprate, hapscor, GDP, lifeExpec;
        getline(in, crty, ',');
        getline(in, haprate, ',');
        getline(in, hapscor, ',');
        getline(in, GDP, ',');
        getline(in, lifeExpec, '\n');


        //changes from string to double
        double rating = stod(haprate);
        double score = stod(hapscor);
        double gdp = stod(GDP);
        double life = stod(lifeExpec);


        Data info = Data(crty, rating, score, gdp, life);

        stack1.push(info);
        queue1.push(info);
        priorityQueue1.push(info);

    }

    //prints then removes the element from stack
    cout << "Writing data in stack into Stack.txt" << endl;
    while (!stack1.empty()){
        outStack << stack1.top() << endl;
        stack1.pop();
    }
    //prints then removes the element from queue
    cout << "Writing data in queue into Queue.txt" << endl;
    while (!queue1.empty()){
        outQueue << queue1.front() << endl;
        queue1.pop();
    }
    //prints then removes the element from the priority queue
    cout << "Writing data in priority queue into Sorted.txt" << endl;
    while (!priorityQueue1.empty()){
        outPriority << priorityQueue1.top() << endl;
        priorityQueue1.pop();
    }

    //Closes all the files!
     in.close();
     outQueue.close();
     outPriority.close();
     outStack.close();
     cout<<"All files are closed!"<<endl;

     return 0;

}