#include <stdio.h>

enum Type {NOVEL, COMICS, MANUAL, TEXTBOOK};
 
struct Book {
    char title[128];
    enum Type type;
    char ISBN[128];
    char authors[128];
    unsigned int importance;
};
 
struct Date {
    unsigned int year;
    unsigned int month;
    unsigned int day;
};

int datecount(int year1, int month1, int day1, int year2, int month2, int day2){
	int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int count = 0;

	if(year1 != year2){
		for(int i=year1+1 ; i<year2 ; i++){
			printf("year\n");
			if(i%4 == 0 && (i%100 != 0 || i%400 == 0)){
				count += 366;
			}
			else{
				count += 365;
			}
		}

		if(year1%4 == 0 && (year1%100 != 0 || year1%400 == 0)) month[1] = 29;

		for(int i=month1 ; i<=12 ; i++)
			count += month[i-1];

		count -= day1;

		month[1] = 28;
		if(year2%4 == 0 && (year2%100 != 0 || year2%400 == 0)) month[1] = 29;
		
		for(int i=1 ; i<=month2 ; i++)
			count += month[i-1];

		count -= (month[month2] - day2);
	}
	else{
		if(year1%4 == 0 && (year1%100 != 0 || year1%400 == 0)) month[1] = 29;

		for(int i=month1 ; i<=month2 ; i++)
			count += month[i-1];

		count -= day1;
		count -= (month[month2-1] - day2);
	}

	return count+1;
}

unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned){
	int due;
	switch(book.type){
		case 0:
			due = 90;
			break;
		case 1:
			due = 10;
			break;
		case 2:
			due = 100;
			break;
		case 3:
			due = 5;
			break;
	}

	due = datecount(date_borrowed.year, date_borrowed.month, date_borrowed.day
					,date_returned.year, date_returned.month, date_returned.day) - due; 
	if(due <= 0) return 0;

	int start = -1, end;

	for(int i=0 ; i<32 ; i++){
		if((book.importance & 1) == 1){
			if(start == -1){
				start = i;
			}
			else{
				end = i;
			}
		}
		book.importance >>= 1;
	}

	return due * (end-start-1);
}
 
int main(){
    struct Book book = {
        "Neon Genesis Evangelion",
        COMICS,
        "978-159-116-400-5",
        "Yoshiyuki Sadamoto",
        17
    };
    struct Date date_borrowed, date_returned;
    date_borrowed.year  = 2007;
    date_borrowed.month = 12;
    date_borrowed.day   = 29;
    date_returned.year  = 2008;
    date_returned.month = 1;
    date_returned.day   = 2;
    printf("The fine is $%d.\n", library_fine(book, date_borrowed, date_returned));
    return 0;
}