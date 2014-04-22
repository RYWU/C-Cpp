//
//  main.cpp
//  ETC.cpp
//
//  Created by WILLIAM on 3/31/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <assert.h>
using namespace std;

typedef struct car{
    string plate;
    string time;
    string station;
}Car;
int possiblePlate(string plate1, string plate2);
void possible(string plate, string startTime, string endTime, vector <Car>& data, long long int dataCount);
void anomaly(string plate, vector <Car>& data, long long int dataCount);
int main(int argc, const char * argv[])
{
    vector <Car> data;
    Car push = {"WWWWWW", "2022 22 22", "11NS"};
    
    int i = 0, j = 0, k = 0;
    string temp;
    string path = argv[1];
    string tempPath;
    string fileName1;
    string fileName2;
    string stationn;
    
    Car tempp;
    for (i = 1; i <= 100; i++){
        fileName1 = to_string(i);
        fileName1.append("SN.txt");
        fileName2 = to_string(i);
        fileName2.append("NS.txt");
        
        tempPath = path;
        tempPath.append(fileName1);
        ifstream file (tempPath);
        assert(file.is_open());
        while (getline(file, temp)) {
            stationn = to_string(i);
            stationn.append("SN");
            push = {temp.substr(20, 6), temp.substr(0, 19), stationn};
            data.push_back(push);
            for (j = 0; j < (int)data.size()-1; j++){
                if (data[j].time.compare( data[data.size()-1].time ) > 0){
                    tempp = data[data.size()-1];
                    for (k = (int)data.size()-1; k >= j; k--){
                        data[k] = data[k-1];
                    }
                    data[k] = tempp;
                }
            }
        }
        file.close();
        
        cout << data[1].time << data[1].plate << data[1].station << endl;
        
        tempPath = path;
        tempPath.append(fileName2);
        file.open(tempPath);
        assert(file.is_open());
        while (getline(file, temp)) {
            stationn = to_string(i);
            stationn.append("NS");
            push = {temp.substr(20, 6), temp.substr(0, 19), stationn};
            data.push_back(push);
            for (j = 0; j < (int)data.size()-1; j++){
                if (data[j].time.compare( data[data.size()-1].time ) > 0){
                    tempp = data[data.size()-1];
                    for (k = (int)data.size()-1; k >= j; k--){
                        data[k] = data[k-1];
                    }
                    data[k] = tempp;
                }
            }
        }
        file.close();
    }
    
    long long int dataCount = data.size();
    string plate;
    string startTime;
    string endTime;
    tempPath = path;
    tempPath.append("query.txt");
    ifstream file (tempPath);
    assert(file.is_open());
    while (getline(file, temp)) {
        if (temp.find("anomaly")){
            plate = temp.substr(8, 6);
            anomaly(plate, data, dataCount);
        }else if (temp.find("possible")){
            plate = temp.substr(9, 6);
            startTime = temp.substr(17, 19);
            endTime = temp.substr(39, 19);
            possible(plate, startTime, endTime, data, dataCount);
        }
    }
    file.close();
    data.clear();
    return 0;
}
void anomaly(string plate, vector <Car>& data, long long int dataCount){
    int i = 0, j = 0;
    for (i = 0; i < dataCount; i++){
        if (data[i].plate.compare(plate) == 0){
            for (j = i+1; j < dataCount; j++){
                if (data[j].plate.compare(plate) == 0){
                    if (data[i].station.find("NS")){
                        if (data[j].station.find("NS")){
                            if (stoi(data[i].station) - stoi(data[j].station) != 1){
                                cout << data[i].time << " " << data[i].station << " - " << data[j].time << " " << data[j].station << endl;
                            }
                        }else if (data[j].station.find("SN")){
                            if (stoi(data[i].station) - stoi(data[j].station) != 0){
                                cout << data[i].time << " " << data[i].station << " - " << data[j].time << " " << data[j].station << endl;
                            }
                        }
                    }else if (data[i].station.find("SN")){
                        if (data[j].station.find("NS")){
                            if (stoi(data[i].station) - stoi(data[j].station) != 0){
                                cout << data[i].time << " " << data[i].station << " - " << data[j].time << " " << data[j].station << endl;
                            }
                        }else if (data[j].station.find("SN")){
                            if (stoi(data[i].station) - stoi(data[j].station) != -1){
                                cout << data[i].time << " " << data[i].station << " - " << data[j].time << " " << data[j].station << endl;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "--" << endl;
}
int possiblePlate(string plate1, string plate2){
    int i = 0;
    int count = 0;
    for (i = 0; i < 6; i++){
        if (plate1[i] == plate2[i]){
            count++;
        }
    }
    if (count >= 4){
        return 1;
    }else {
        return 0;
    }
}
void possible(string plate, string startTime, string endTime, vector <Car>& data, long long int dataCount){
    int i = 0;
    for (i = 0; i < dataCount; i++){
        if (data[i].time.compare(startTime) >= 0 && data[i].time.compare(endTime) <= 0 && possiblePlate(plate, data[i].plate)){
            cout << data[i].time << " " << data[i].plate << data[i].station << endl;
        }
    }
    cout << "--" << endl;
}