#include <stdio.h>
#include <string.h>

struct ALGOPRO
{
	char Tempat1[45];
	char Tempat2[45];
	int Harga;
	int Kamar;
	int KamarMandi;
	int Parkiran;
	char Jenis[50];
	int Area;	
	char Furnish[50];
};

void Merge(struct ALGOPRO ALG[], int start, int mid, int end){
	
	struct ALGOPRO tempArr[end-start+1];
	int tempInd=0;
	int leftInd=start;
	int leftLimit=mid;
	int rightInd=mid+1;
	int rightLimit=end;
	
	
	while(leftInd<=leftLimit && rightInd<=rightLimit)
	{
		if(strcmp(ALG[rightInd].Tempat1, ALG[leftInd].Tempat1)>0)
		{
			tempArr[tempInd]=ALG[leftInd];
			tempInd++;
			leftInd++;
		}
		else
		{
			tempArr[tempInd]=ALG[rightInd];
			tempInd++;
			rightInd++;
		}
	}
	
	while(rightInd<=rightLimit)
	{
		tempArr[tempInd]=ALG[rightInd];
		tempInd++;
		rightInd++;
	}
	
	while(leftInd<=leftLimit)
	{
		tempArr[tempInd]=ALG[leftInd];
		tempInd++;
		leftInd++;
	}
	
	tempInd=0;
	int i;
	for(i=start;i<=end;i++)
	{
		ALG[i]=tempArr[tempInd];
		tempInd++;
	}
}

void MergeSort(struct ALGOPRO ALG[], int start, int end){
	
	if(start==end)
	{
		return;
	}
	int mid=(end-start)/2+start;
	MergeSort(ALG, start, mid); 
	MergeSort(ALG, mid+1, end); 
	Merge(ALG, start, mid, end);
	
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
		fscanf(jelek, "%[^,],%[^,],%d,%d,%d,%d,%[^,],%d,%[^\n]\n", ALG[i].Tempat1 , ALG[i].Tempat2, &ALG[i].Harga, &ALG[i].Kamar, &ALG[i].KamarMandi, &ALG[i].Parkiran, ALG[i].Jenis, &ALG[i].Area, ALG[i].Furnish);
	}
	MergeSort(ALG, 0, 3939);
	int f;
	for(f=0;f<i;f++)
	{
		int count = 0;
		if (strcmp(ALG[f].Tempat1, ALG[f+1].Tempat1)==0)
		{
			count++;
		}
		else if (count == 0)
		{
		printf("%s\n",ALG[f].Tempat1);	
		}
	}
	return 0;
	fclose(jelek);
}
