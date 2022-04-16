#include <stdio.h>

int main(void) {
	while(true) {
		int year = 0;
		int month = 0;
		const int BASEYEAR = 1900;
		int numOfLeapYear = 0;
		int yearMonthDays = 0;
		int totalDays = 0;
			
		printf("Input a year : ");
		scanf("%d", &year);
		if (year == 0) {
			printf("exit");
			break;
		}
		printf("Input a month : ");
		scanf("%d", &month);
		printf("\n======= %d / %d =======\n",year, month);
		printf("sun\tmon\ttue\twed\tthu\tfri\tsat\n",year, month);
		
		int yearDiff = year - BASEYEAR; 
		int dayDiff = yearDiff * 365; 
		
		int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //leap years are not being considered at this line
	 	for (int index = 0; index < month - 1; index++) {
	 		yearMonthDays += monthDays[index];
		}
				
		for(int yearTmp = BASEYEAR; yearTmp < year; yearTmp++) {
			if ((yearTmp % 4 == 0 && yearTmp % 100 != 0) || (yearTmp % 400 == 0)) 
				numOfLeapYear++;		
		} 
		dayDiff = dayDiff + numOfLeapYear; //to add leap years' days
		
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))  {
			totalDays = dayDiff + yearMonthDays + 1; //to add leap year's day to toalDays (when the year of int year)
		} else {
			totalDays = dayDiff + yearMonthDays; 
		}
	
		if (totalDays % 7 <= 5) { 
			for (int numOfTab = 0; numOfTab <= (totalDays % 7); numOfTab++) {
			printf("\t");
			} 
		} 
		
		for (int day = 0; day < monthDays[month-1]; day++) {
			printf("%2d\t", day + 1);	
			if ((day + 1) % 7 == (6 - totalDays % 7)){
				printf("\n");
			}		
		}
		printf("\n\n");
	}
	return 0;
}
