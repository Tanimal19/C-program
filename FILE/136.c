#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;

int main(){
	
	char bin[80], html[80];
	scanf("%s%s", bin, html);

	FILE *fin = fopen(bin, "rb");
	FILE *fout = fopen(html, "w");
	assert(fin != NULL && fout != NULL);
	int i = 0;

	fputs("<table border=\"1\">\n", fout);
	fputs("<tbody>\n", fout);

	while(87){
		fseek(fin, sizeof(Student)*i ,SEEK_SET);

		Student std = {};
		// process name
		char c;
		int len = 0;
		fread(&c, sizeof(char), 1, fin);
		while(c >= 32 && c < 128){
			std.name[len] = c;
			len ++;
			fread(&c, sizeof(char), 1, fin);
		}

		// process id
		fseek(fin, sizeof(Student)*i + 20, SEEK_SET);
		fread(&(std.id), sizeof(int), 1, fin);

		// process phone
		len = 0;
		fread(&c, sizeof(char), 1, fin);
		while(c >= 32 && c < 128){
			std.phone[len] = c;
			len ++;
			fread(&c, sizeof(char), 1, fin);
		}

		//process grade
		fseek(fin, sizeof(Student)*i + 36, SEEK_SET);
		fread(std.grade, sizeof(float), 4, fin);
		
		//process birth
		fread(&(std.birth_year), sizeof(int), 1, fin);
		fread(&(std.birth_month), sizeof(int), 1, fin);
		fread(&(std.birth_day), sizeof(int), 1, fin);
		
		// output html
		fprintf(fout, "<tr>\n<td>%s</td>\n<td>%d</td>\n<td>%s</td>\n<td>%f, %f, %f, %f</td>\n<td>%d, %d, %d</td>\n</tr>\n",
			std.name, std.id, std.phone, std.grade[0], std.grade[1], std.grade[2], std.grade[3], std.birth_year, std.birth_month, std.birth_day);

		// check if EOF 
		i++;
		fseek(fin, sizeof(Student)*i ,SEEK_SET);
		if(fgetc(fin) == EOF) break;
	}

	fputs("</tbody>\n", fout);
	fputs("</table>", fout);
	
	fclose(fin);
	fclose(fout);
	return 0;
}