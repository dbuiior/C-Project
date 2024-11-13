#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ALGOPRO {
    char loc1[50];
	char loc2[50];
    int Harga; 
	int rooms; 
	int bathrooms; 
	int carparks; 
	char type[50]; 
	int Area;
	char furnish[50];
};

void Integer(struct ALGOPRO ALG[], int count, char *fang) {
    int i;
    int MinValue;
	int MaxValue;
    long long int Total=0;
    
    if (strcmp(fang, "area") == 0)
	{
    	MaxValue = ALG[0].Area;
    	MinValue = ALG[0].Area;
    	Total=ALG[0].Area;
    }
	else
	{      
    	MaxValue = ALG[0].Harga;
    	MinValue= ALG[0].Harga;
    	Total=ALG[0].Harga;    
    }
    
    for (i = 1; i < count; i++) 
	{ 
    
        if (strcmp(fang, "area") == 0)
		{
            if (ALG[i].Area > MaxValue) 
			{
               MaxValue = ALG[i].Area;
            }
            if (ALG[i].Area < MinValue)
			{
               MinValue = ALG[i].Area;
            }
            Total += ALG[i].Area;
        }
        if (strcmp(fang, "Harga") == 0)
		{
            if (ALG[i].Harga > MaxValue) 
			{
               MaxValue = ALG[i].Harga;
            }
            if (ALG[i].Harga < MinValue) 
			{
               MinValue = ALG[i].Harga;
            }
            Total += ALG[i].Harga;
        }
    }
    
    printf("Maximum %s : %d\n",fang,MaxValue);
    printf("Minimum %s : %d\n",fang,MinValue);
    printf("Average %s : %.02lf\n",fang, (double)Total/count);
}

void substring(struct ALGOPRO ALG[], int count, char *fang) {
    
    int i;
	int j;
	int uniqueCount = 0;
    char uniqueval[300][100]; 
    int Frequency[300];
    char MaxValue[100], MinValue[100];
    int MaxFreq = 0, MinFreq = count;
    
    for (i = 0; i < count; i++)
	{       
        int found=0;  
        for (j = 0; j < uniqueCount; j++) 
		{ 
            if (strcmp(fang, "loc1") == 0) 
			{       
                if (strcmp(ALG[i].loc1, uniqueval[j]) == 0)
				{      
                    Frequency[j]++;
                    found = 1;
                    break;
                }
            } 
			else if (strcmp(fang, "loc2") == 0) 
			{
                if (strcmp(ALG[i].loc2, uniqueval[j]) == 0)
				{
                    Frequency[j]++;
                    found = 1;
                    break;
                }
            } 
			else if (strcmp(fang, "rooms") == 0)
			{
                if (ALG[i].rooms == atoi(uniqueval[j])) 
				{  
                    Frequency[j]++;
                    found = 1;
                    break;
                }
            } 
			else if (strcmp(fang, "bathrooms") == 0)
			{
                if (ALG[i].bathrooms == atoi(uniqueval[j])) 
				{
                    Frequency[j]++;
                    found = 1;
                    break;
                }
            } 
			else if (strcmp(fang, "carparks") == 0) 
			{
                if (ALG[i].carparks == atoi(uniqueval[j]))
				{
                    Frequency[j]++;
                    found = 1;
                    break;
                }
            }
			else if (strcmp(fang, "type") == 0) 
		    {
                if (strcmp(ALG[i].type, uniqueval[j]) == 0) 
				{
                    Frequency[j]++;
                    found = 1;
                    break;
                }
            } 
			else if (strcmp(fang, "furnish") == 0) 
			{
                if (strcmp(ALG[i].furnish, uniqueval[j]) == 0)
				{
                    Frequency[j]++;
                    found = 1;
                    break;
                }
            }
        } 
        
        if (!found)
			{          
            if (strcmp(fang, "loc1") == 0) 
			{
                strcpy(uniqueval[uniqueCount], ALG[i].loc1);
            } 
			else if (strcmp(fang, "loc2") == 0) 
			{
                strcpy(uniqueval[uniqueCount], ALG[i].loc2);
            } 
			else if (strcmp(fang, "rooms") == 0)
			{
                sprintf(uniqueval[uniqueCount], "%d", ALG[i].rooms);
            } 
			else if (strcmp(fang, "bathrooms") == 0) 
			{
                sprintf(uniqueval[uniqueCount], "%d", ALG[i].bathrooms);
            } 
			else if (strcmp(fang, "carparks") == 0) 
			{
                sprintf(uniqueval[uniqueCount], "%d", ALG[i].carparks);
            }
			else if (strcmp(fang, "type") == 0) 
			{
                strcpy(uniqueval[uniqueCount], ALG[i].type);
            }
			else if (strcmp(fang, "furnish") == 0) 
			{
                strcpy(uniqueval[uniqueCount], ALG[i].furnish);
            }
            Frequency[uniqueCount] = 1;
            uniqueCount++;
        }
        
    }
    
    
    for (i = 0; i < uniqueCount; i++) 
	{  
        if (Frequency[i] >= MaxFreq) 
		{    
            MaxFreq = Frequency[i];
            strcpy(MaxValue, uniqueval[i]);    
        }
        if (Frequency[i] <= MinFreq) 
		{      
            MinFreq = Frequency[i];
            strcpy(MinValue, uniqueval[i]);
        }
        printf("%s: %d\n", uniqueval[i], Frequency[i]); 
    }
    
    printf("Maximum value: %s with frequency: %d\n", MaxValue, MaxFreq);
    printf("Minimum value: %s with frequency: %d\n", MinValue, MinFreq);
    
}


int main()
{
        
    struct ALGOPRO ALG[4000]; 
    int count;
    char Kolom[1024];
    int i = 0;
    
    
    FILE *jelek = fopen("file.csv", "r");  
    if(jelek == NULL)
	{
        printf("file not found");
        return 0;
    }
    
    fgets(Kolom, 1024, jelek); 
    while (fgets(Kolom, 1024, jelek) && i < 4000)
	{
        sscanf(Kolom, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%s", ALG[i].loc1, ALG[i].loc2, &ALG[i].Harga, &ALG[i].rooms, &ALG[i].bathrooms, &ALG[i].carparks, ALG[i].type, &ALG[i].Area, ALG[i].furnish);
        i++;
    }
    count = i; 
    fclose(jelek);
    
    char fang[100];
    printf("loc1/loc2/rooms/bathrooms/carparks/type/furnish/area/Harga):\n");
    scanf("%s", fang);

    if (strcmp(fang,"area") == 0|| strcmp(fang,"Harga") == 0)
	{
        Integer(ALG, count, fang);  
    } 
	else if (strcmp(fang, "loc1") == 0  || strcmp(fang, "loc2") == 0 ||strcmp(fang, "rooms") == 0  || strcmp(fang, "bathrooms") == 0  ||strcmp(fang, "carparks") == 0  || strcmp(fang, "type") == 0 || strcmp(fang, "furnish") == 0) 
	{
    	substring(ALG, count, fang);  
    } else
	{
        puts("Invalid input!\n");
    }
    
    return 0;
}

