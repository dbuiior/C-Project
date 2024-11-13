#include <stdio.h>
#include <string.h>

struct ALGOPRO
{
	char loc1[45];
	char loc2[45];
	int Harga;
	int Kamar;
	int KamarMandi;
	int Parkiran;
	char Jenis[50];
	int Area;
	char Furnish[50];
};

void LinearSearch(struct ALGOPRO ALG[],char *DataX, char *NamaKolom)
{
	if(strcmp(NamaKolom,"loc1") == 0)
	{
		int i;
		for (i = 0; i < 3939; i++)
		{
			if(strstr(ALG[i].loc1,DataX))
			{
				printf ("%-20s | %-10s | %d\t | %-2d | %-2d | %-2d | %s\t | %d\t | %s\n",ALG[i].loc1,ALG[i].loc2,ALG[i].Harga,ALG[i].Kamar,ALG[i].KamarMandi,ALG[i].Parkiran,ALG[i].Jenis,ALG[i].Area,ALG[i].Furnish);
				
			}
		}
	}
	else if (strcmp(NamaKolom,"loc2") == 0)
	{
		int i;
		for ( i = 0; i < 3939; i++)
		{
			if (strstr(ALG[i].loc2,DataX))
			{
				printf ("%-20s | %-10s | %d\t | %-2d | %-2d | %-2d | %s\t | %d\t | %s\n",ALG[i].loc1,ALG[i].loc2,ALG[i].Harga,ALG[i].Kamar,ALG[i].KamarMandi,ALG[i].Parkiran,ALG[i].Jenis,ALG[i].Area,ALG[i].Furnish);		
			}
		}
	}
	else if (strcmp(NamaKolom,"rooms") == 0)
	{
		int i;
		int temp;
		sscanf (DataX, "%d", &temp);
		for (i = 0; i < 3939; i++)
		{
			if(ALG[i].Kamar == temp)
			{
				printf ("%-20s | %-10s | %d\t | %-2d | %-2d | %-2d | %s\t | %d\t | %s\n",ALG[i].loc1,ALG[i].loc2,ALG[i].Harga,ALG[i].Kamar,ALG[i].KamarMandi,ALG[i].Parkiran,ALG[i].Jenis,ALG[i].Area,ALG[i].Furnish);
			}
		}
	}
	else if (strcmp(NamaKolom,"Bathroom") == 0)
	{
		int i;
		int temp;
		sscanf (DataX, "%d", &temp);
		for (i = 0; i < 3939; i++)
		{
			if (ALG[i].KamarMandi == temp)
			{
				printf ("%-20s | %-10s | %d\t | %-2d | %-2d | %-2d | %s\t | %d\t | %s\n",ALG[i].loc1,ALG[i].loc2,ALG[i].Harga,ALG[i].Kamar,ALG[i].KamarMandi,ALG[i].Parkiran,ALG[i].Jenis,ALG[i].Area,ALG[i].Furnish);
			}
		}
	}
	else if (strcmp(NamaKolom,"CarParks") == 0)
	{
		int i;
		int temp;
		sscanf (DataX, "%d", &temp);
		for (i = 0; i < 3939; i++)
		{
			if (ALG[i].Parkiran == temp)
			{
				printf ("%-20s | %-10s | %d\t | %-2d | %-2d | %-2d | %s\t | %d\t | %s\n",ALG[i].loc1,ALG[i].loc2,ALG[i].Harga,ALG[i].Kamar,ALG[i].KamarMandi,ALG[i].Parkiran,ALG[i].Jenis,ALG[i].Area,ALG[i].Furnish);	
			}
		}
	}
	
	else if (strcmp(NamaKolom,"Type") == 0)
	{
		int i;
		for ( i = 0; i < 3939; i++)
		{
			if (strstr(ALG[i].Jenis,DataX))
			{
				printf ("%-20s | %-10s | %d\t | %-2d | %-2d | %-2d | %s\t | %d\t | %s\n",ALG[i].loc1,ALG[i].loc2,ALG[i].Harga,ALG[i].Kamar,ALG[i].KamarMandi,ALG[i].Parkiran,ALG[i].Jenis,ALG[i].Area,ALG[i].Furnish);
			}
		}
	}
	
	
	else if (strcmp(NamaKolom,"Furnish") == 0)
	{
		int i;
		for (i = 0; i < 3939; i++)
		{
			if (strstr(ALG[i].Furnish,DataX))
			{
				printf ("%-20s | %-10s | %d\t | %-2d | %-2d | %-2d | %s\t | %d\t | %s\n",ALG[i].loc1,ALG[i].loc2,ALG[i].Harga,ALG[i].Kamar,ALG[i].KamarMandi,ALG[i].Parkiran,ALG[i].Jenis,ALG[i].Area,ALG[i].Furnish);
			}
		}
	}
}

int main()
{
	FILE *jelek=fopen("file.csv","r");
	
	char Kolom[120];
	fscanf(jelek,"%[^\n]\n",Kolom);
	
	struct ALGOPRO ALG[3940];
	
	int i = 0;
	for(i=0;!feof(jelek);i++)
	{
		fscanf(jelek, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%[^\n]\n", ALG[i].loc1, ALG[i].loc2, &ALG[i].Harga, &ALG[i].Kamar, &ALG[i].KamarMandi, &ALG[i].Parkiran, ALG[i].Jenis, &ALG[i].Area, ALG[i].Furnish);
	}
	char DataX[50];
	char NamaKolom[50];
	char PartlyinFurnish[50];
	
	printf ("Input Data: ");
	scanf ("%[^\n]",PartlyinFurnish);
	sscanf (PartlyinFurnish, "%s in %s", DataX,NamaKolom);
	
	LinearSearch(ALG, DataX, NamaKolom);
	return 0;
	fclose(jelek);
}
