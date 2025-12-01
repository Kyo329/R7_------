#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

void delay(int millseconds) {
	clock_t start_time = clock();
	while (clock() < start_time + millseconds);
}

int main(void) {
	double pay, work_time, day_of_work, toll;

	FILE *file;
	errno_t error;

	error = fopen_s(&file,"pay_log.txt", "a+");

	char str[10];

	rewind(file);

	char isNULL;
	if (isNULL=fgetc(file) == EOF) {
		printf("時給を入力してください。\n");
		scanf_s("%lf", &pay);
		printf_s("%lf\n", pay);
		fseek(file, 0, SEEK_END);
		fprintf(file, "%lf\n", pay);
		//pay = atof(str);
	}
	else {
		pay = atof(str);
		//printf("時給を入力してください。\n");
		//scanf_s("%lf", &pay);
		//printf_s("%lf\n",pay);
		//fseek(file, 0,SEEK_END);
		//fprintf(file, "%lf\n", pay);
	}

	fclose(file);
	
	
	//printf("時給を入力してください。\n");
	//scanf_s("%lf",&pay);
	printf("１か月の労働時間を入力してください。\n");
	scanf_s("%lf",&work_time);
	printf("1か月の出勤日数を入力してください。\n");
	scanf_s("%lf",&day_of_work);
	printf("1回の出勤における交通費を入力してください。\n");
	scanf_s("%lf",&toll);
	
	
	printf("%lf\n", pay);
	printf("%lf\n", work_time);
	printf("%lf\n", day_of_work);
	printf("%lf\n\n", toll);
	double month_pay, month_toll, all_pay, diffarence, ALL;

	month_pay = pay * work_time;
	printf("%lf\n", month_pay);
	month_toll = day_of_work * toll;
	printf("%lf\n" ,month_toll);
	ALL = month_pay + month_toll;
	printf("%lf\n", ALL);

	printf("1か月の給料は%d円です。\n交通費が%d円です。\n合計で%d円です。",(int)month_pay, (int)month_toll, (int)ALL);

	FILE *file2;
	errno_t error2;
	error2 = fopen_s(&file2, "difarance.txt", "a+");



	delay(10000);
	return 0;
}
//print
