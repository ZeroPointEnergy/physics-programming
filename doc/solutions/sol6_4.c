#include "stdio.h"

//in this solution we only show how to read the data
//you can use your own code to do the caclulations

int main()
{
	FILE *f;

	float bernt[10000]; //preallocate 10000 entries for bern measurements temp
	float bernh[10000]; //preallocate 10000 entries for bern measurements humi
	int bern_num = 0; //her we will store how many measurments we have so far
	float zuricht[10000]; //same for other stations
	float zurichh[10000];
	int zurich_num = 0;
	float genevat[10000];
	float genevah[10000];
	int geneva_num = 0;
	float baselt[10000];
	float baselh[10000];
	int basel_num = 0;
	

	f = fopen("weather.txt","r");
	int num_station_report; //we will read how many 
													//stations reported into this variable
	int minute;							//we will read the minute id into this var
		
		
	while ( !feof(f) )
	{
		fscanf(f,"%d %d", &minute, &num_station_report);
		//reading minute id and how many stations reported		
		
		int stat;
		
		
		for (stat=0; stat < num_station_report; stat++)
		{
			
			//we know from num_station_report how many stations reported, so 
			//we loop over that number of stations nd read the data from file
			int cstat; //curretn station
			float temp;
			float hum;
			fscanf(f, "%d %f %f", &cstat, &temp, &hum);

			//printf("%d\n", line);
			if (cstat == 1) 
			{
				bernt[bern_num] = temp;
				bernh[bern_num] = hum;
				bern_num++;
			}
			if (cstat == 2)
			{
				zuricht[zurich_num] = temp;
				zurichh[zurich_num] = hum;
				zurich_num++;
			}
			
			if (cstat == 3)
			{
				genevat[geneva_num] = temp;
				genevah[geneva_num] = hum;
				geneva_num++;
			}

			if (cstat == 4)
			{
				baselt[basel_num] = temp;
				baselh[basel_num] = hum;
				basel_num++;
			}
			
		}
		printf("finished\n");
	
	}
	
	//example loop to print bern data
	int l;
	for (l = 0; l < bern_num; l++)
		printf("%f %f\n", bernt[l], bernh[l]);
	
	
	return 0;
}