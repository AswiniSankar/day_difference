/*
ip:
12
01
2000
16
01
2000
op:
12:1:2000
16:1:2000
Difference between two dates is 4
*/
#include<stdio.h>  
struct Date 
{ 
	int d, m, y; 
}; 
int  countLeapYears(struct Date);
int getDifference(struct Date,struct Date);
void valid_date(struct Date);  
const int monthDays[12] = {31, 28, 31, 30, 31, 30, 
						31, 31, 30, 31, 30, 31}; 
int countLeapYears(struct Date d) 
{ 
	int years = d.y;  
	if (d.m <= 2) 
		years--; 
	return years / 4 - years / 100 + years / 400; 
} 
 
int getDifference(struct Date dt1,struct Date dt2) 
{
	long int n1 = dt1.y*365 + dt1.d; 
	for (int i=0; i<dt1.m - 1; i++) 
		n1 += monthDays[i];  
	n1 += countLeapYears(dt1);

	long int n2 = dt2.y*365 + dt2.d; 
	for (int i=0; i<dt2.m - 1; i++) 
		n2 += monthDays[i]; 
	n2 += countLeapYears(dt2); 
	return (n2 - n1); 
} 
int main() 
{ 
	struct Date dt1,dt2;
        int res;
        scanf("%d%d%d",&dt1.d,&dt1.m,&dt1.y);
        scanf("%d%d%d",&dt2.d,&dt2.m,&dt2.y);
        printf("%d:%d:%d\n",dt1.d,dt1.m,dt1.y);
        printf("%d:%d:%d\n",dt2.d,dt2.m,dt2.y);
        res= getDifference(dt1, dt2);
	(res>0)?printf("Difference between two dates is %d\n",res):printf("the second date must be greater then first date so diff is %d\n",res); 
	return 0; 
} 

