//
//  main.c
//  ETC
//
//  Created by WILLIAM on 3/27/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#define DATA_SIZE 500000000
typedef struct car{
    char plate[7];
    char time[21];
    char station[6];
}Car;
int compare(const void *car1, const void *car2);
int possiblePlate(char plate1[7], char plate2[7]);
void anomaly(char plate[7], Car data[DATA_SIZE], int dataCount);
void possible(char plate[7], char startTime[20], char endTime[20], Car data[DATA_SIZE], int dataCount);
int main(int argc, const char * argv[])
{
    char temp[64] = {0};
    char *strptr = 0;
    FILE *fp;
    
    Car data[DATA_SIZE];
    int i = 0;
    int count = 0;
    char path[32] = {0};
	strcpy(path, argv[1]);
	char tempPath[48] = {0};
    char fileName1[16] = {0};
    char fileName2[16] = {0};
    char stationn[6] = {0};
    
    for (i = 1; i <= 100; i++){
        sprintf(fileName1, "%dSN.txt", i);
        sprintf(fileName2, "%dNS.txt", i);
		strcpy(tempPath, path);
        fp = fopen(strcat(tempPath, fileName1), "r");
		assert(fp != NULL);
        while (fgets(temp, 27, fp)) {
            strncpy(data[count].time, temp, 19);
            strncpy(data[count].plate, temp+20, 6);
            sprintf(stationn, "%dSN", i);
            strcpy(data[count].station, stationn);
            count++;
			bzero(stationn, 7);
			bzero(temp, 64);
        }
		bzero(tempPath, 48);
        fclose(fp);
        
		strcpy(tempPath, path);
        fp = fopen(strcat(tempPath, fileName2), "r");
		assert(fp != NULL);
        while (fgets(temp, 27, fp)) {
            strncpy(data[count].time, temp, 19);
            strncpy(data[count].plate, temp+20, 6);
            sprintf(stationn, "%dNS", i);
            strcpy(data[count].station, stationn);
			count++;
			bzero(stationn, 7);
			bzero(temp, 64);
        }
        bzero(fileName1, 16);
        bzero(fileName2, 16);
		bzero(tempPath, 48);
        fclose(fp);
    }
   	
    qsort(data, count, sizeof(Car), compare);
    
    strcpy(tempPath, path);
	fp = fopen(strcat(tempPath, "query.txt"), "r");
    assert(fp != NULL);
   	bzero(tempPath, 32);
    
    while (fgets(temp, 63, fp)) {
        if ((strptr = strstr(temp, "anomaly"))){
            char plate[7] = {0};
            strncpy(plate, strptr+8, 6);
            anomaly(plate, data, count);
            bzero(plate, 7);
        }else if( (strptr = strstr(temp, "possible")) ){
            char plate[7] = {0};
            char startTime[20] = {0};
            char endTime[20] = {0};
            strncpy(plate, strptr+9, 6);
            strncpy(startTime, strptr+17, 19);
            strncpy(endTime, strptr+39, 19);
            possible(plate, startTime, endTime, data, count);
            bzero(plate, 7);
            bzero(startTime, 20);
            bzero(endTime, 20);
        }
        bzero(temp, 64);
    }
    fclose(fp);
    
    return 0;
}
void anomaly(char plate[7], Car data[DATA_SIZE], int dataCount){
    int i = 0, j = 0;
    for (i = 0; i < dataCount; i++){
        if (strcmp(data[i].plate, plate) == 0){
            for (j = i+1; j < dataCount; j++){
                if (strcmp(data[j].plate, plate) == 0){
                    if (strstr(data[i].station, "NS")){
                        if (strstr(data[j].station, "NS")){
                            if (atoi(data[i].station) - atoi(data[j].station) != 1){
                                printf("%s %s - %s %s\n", data[i].time, data[i].station, data[j].time, data[j].station);
                            }
                        }else if (strstr(data[j].station, "SN")){
                            if (atoi(data[i].station) - atoi(data[j].station) != 0){
                                printf("%s %s - %s %s\n", data[i].time, data[i].station, data[j].time, data[j].station);
                            }
                        }
                    }else if(strstr(data[i].station, "SN")){
                        if (strstr(data[j].station, "NS")){
                            if (atoi(data[i].station) - atoi(data[j].station) != 0){
                                printf("%s %s - %s %s\n", data[i].time, data[i].station, data[j].time, data[j].station);
                            }
                        }else if (strstr(data[j].station, "SN")){
                            if (atoi(data[i].station) - atoi(data[j].station) != -1){
                                printf("%s %s - %s %s\n", data[i].time, data[i].station, data[j].time, data[j].station);
                            }
                        }
                    }
                    break;
                }
            }
        }
    }
    printf("--\n");
}
int possiblePlate(char plate1[7], char plate2[7]){
    int i = 0;
    int count = 0;
    for(i = 0; i < 6; i++){
        if (plate1[i] == plate2[i]){
            count++;
        }
    }
    if (count >= 4){
        return 1;
    }else{
        return 0;
    }
}
void possible(char plate[7], char startTime[20], char endTime[20], Car data[DATA_SIZE], int dataCount){
    int i = 0;
    for (i = 0; i < dataCount; i++){
        if ( strcmp(data[i].time, startTime) >= 0 && strcmp(data[i].time, endTime) <= 0 && possiblePlate(plate, data[i].plate)){
            printf("%s %s %s\n", data[i].time, data[i].plate, data[i].station);
        }
    }
    printf("--\n");
}
int compare(const void *car1, const void *car2){
    return strcmp( (*(const Car*)car1).time , (*(const Car*)car2).time  );
}
