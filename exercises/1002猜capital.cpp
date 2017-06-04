#include <stdio.h>
#include <string.h>
char data[][50] = {"Alabama, Montgomery",
"Alaska, Juneau",
"Arizona, Phoenix",
"Arkansas, Little Rock",
"California, Sacramento",
"Colorado, Denver",
"Connecticut, Hartford",
"Delaware, Dover",
"Florida, Tallahassee",
"Georgia, Atlanta",
"Hawaii, Honolulu",
"Idaho, Boise",
"Illinois, Springfield",
"Maryland, Annapolis",
"Minnesota, Saint Paul",
"Iowa, Des Moines",
"Maine, Augusta",
"Kentucky, Frankfort",
"Indiana, Indianapolis",
"Kansas, Topeka",
"Louisiana, Baton Rouge",
"Oregon, Salem",
"Oklahoma, Oklahoma City",
"Ohio, Columbus",
"North Dakota, Bismark",
"New York, Albany",
"New Mexico, Santa Fe",
"New Jersey, Trenton",
"New Hampshire, Concord",
"Nevada, Carson City",
"Nebraska, Lincoln",
"Montana, Helena",
"Missouri, Jefferson City",
"Mississippi, Jackson",
"Massachusettes, Boston",
"Michigan, Lansing",
"Pennslyvania, Harrisburg",
"Rhode Island, Providence",
"South Carolina, Columbia",
"South Dakota, Pierre",
"Tennessee, Nashville",
"Texas, Austin",
"Utah, Salt Lake City",
"Vermont, Montpelier",
"Virginia, Richmond",
"Washington, Olympia",
"West Virginia, Charleston",
"Wisconsin, Madison",
"Wyoming, Cheyenne"
};
int main() {
	int test_num;
	scanf("%d", &test_num);
	while(test_num--) {
		int i = 0;
		int j;
		char a;
		char test[50], temp[25];
		scanf("%s", test);
		while(test[i] != 0) {
			i++;
		}
		test[i] = ',';
		test[i + 1] = ' ';
		test[i + 2] = 0;
		scanf("%c", &a);
		gets(temp);
		char *test1 = strcat(test, temp);
		for(i = 0; i < 49; i++) {
			int n = 0;
			for(j = 0; test1[j] != 0 && data[i][j] != 0; j++) {
				if(test1[j] == ',') {
					n = 1;
				}
				if(test1[j] != data[i][j]) {
					break;
				}
			}
			if(test1[j] == 0 && data[i][j] == 0) {
				break;
			}
			if(test1[j] != data[i][j] && n) {
				break;
			}
		}
		int m = j;
		if(test1[j] != data[i][j]) {
			j = 0;
			while(test1[j] != ',' && data[i][j] != ',') {
				if(test1[j] != data[i][j]) {
					break;
				}
				j++;
			}
			if(test1[j] == data[i][j]) {
				printf("The capital of ");
				for(j = 0; data[i][j] != ','; j++) {
					printf("%c", data[i][j]);
				}
				printf(" is ");
				for(j = j + 2; data[i][j] != 0; j++) {
					printf("%c", data[i][j]);
				}
				printf("\n");
			}
		}
		else {
			printf("Your anwswer is correct\n");
		}
	}
}
