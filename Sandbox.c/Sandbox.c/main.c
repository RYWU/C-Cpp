//
//  main.c
//  Sandbox.c
//
//  Created by WILLIAM on 2/15/14.
//  Copyright (c) 2014 吳瑞洋公司. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <assert.h>
int main(int argc, const char * argv[]){
	FILE *fp;
	fp = fopen("input", "w");
	assert(fp != NULL);
	int i = 0;
	for(i = 32000; i <= 32460; i++){
		fprintf(fp, "32460 %d\n", i);
	}
    fprintf(fp, "0 0");
    fclose(fp);

}
