//
//  main.cpp
//  Price and delta of American call option.
//
//  Created by WILLIAM on 4/16/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.

//  (BOPM) Write a program to price American-style arithmetic average-rate calls based on the CRR binomial tree. Please output the delta, too. The payoff function is max(average - X, 0). Of course, if the holder exercises early, then average means the average up to that node.
//  Inputs: S (stock price at time = 0), X (strike price), t (maturity in years), s (%) (annual volatility, aka sigma), r (%) (continuously compounded annual interest rate), n (number of periods), and k (number of states per node).
//  Outputs: price, delta.

//  For example, when S = 100, X = 70, t = 2 (years), s = 20%, r = 5%, n = 40, and k = 5, the price is about 36.308 and the delta is about 0.9515.
//  IN: 100 70 2 20 5 40 5
//  Out: 36.308 0.9515

#include <iostream>
#include <math.h>
using namespace std;
int main(int argc, const char * argv[])
{
    double initialStockPrice = 100;
    double strikePrice = 70;
    double maturity = 2;
    double volatility = 0.2;
    double interestRate = 0.05;
    double numberOfPeriods = 40;
    double numberOfStates = 5; 
/*
    cout << "Enter stock price at time 0: " ;
    cin >> initialStockPrice;
    cout << "Enter strike price: ";
    cin >> strikePrice;
    cout << "Enter maturity: ";
    cin >> maturity;
    cout << "Enter volatility: ";
    cin >> volatility;
    cout << "Enter interest rate: ";
    cin >> interestRate;
    cout << "Enter number of periods: ";
    cin >> numberOfPeriods;
    cout << "Enter number of states per nodes: ";
    cin >> numberOfStates;
*/    
    double deltaT = maturity / numberOfPeriods;
    double up = exp(volatility * sqrt(deltaT));
    
    double q = 0;
    double p0 = ( up * exp(-interestRate * deltaT) - exp(-q * deltaT)) * up / (pow(up, 2) - 1);
    double p1 = exp(-interestRate * deltaT) - p0;
    
    double p[1000] = {0};
    
    // initial value at time T.
    for (int i = 0; i <= numberOfPeriods; i++){
        p[i] = initialStockPrice * pow(up, 2*i -numberOfPeriods) - strikePrice;
        if (p[i] < 0){
            p[i] = 0;
        }
    }
    
    // move to earlier times
    for (int j = numberOfPeriods-1; j >= 0; j--){
        for (int i = 0; i <= j; i++){
            p[i] = p0 * p[i] + p1 * p[i+1];
            double exercise = initialStockPrice * pow(up, 2*i - j) - strikePrice;
            if (p[i] < exercise){
                p[i] = exercise;
            }
        }
    }
    
    printf("%.10f", p[0]);
//    cout << p[0] <<  endl;
    
    return 0;
}