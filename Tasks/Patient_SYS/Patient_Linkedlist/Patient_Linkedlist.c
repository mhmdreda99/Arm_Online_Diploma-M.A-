/****************************************************************************
* Title                 :   Patient management System   
* Filename              :   Patient_Linkedlist.c
* Author                :   Mohamed Reda
* Origin Date           :   29/06/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO:TARGET GOES HERE
* Notes                 :   None
*Description            :.                                    
*                         
*****************************************************************************/
/*************************************************************************
*                         Include Header Files
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*************************************************************************
*                         Declared Structures 
*************************************************************************/
typedef struct patient {
	int SID;
	char Sname[20];
	float SWieght;
    patient_t *Snext ;
    int Sindex ;
}patient_t;

/*************************************************************************
*                         Public Function Prototypes
*************************************************************************/
int Get_Patient_Index(patient_t pArr[], unsigned int ArrSize, unsigned int SearchID);
void Print_Patient_Data(patient_t* pArr);
void Get_Patient_Data(patient_t* pArr);

/*************************************************************************************/

void main(void) 
{
    char size ;
    int index ;
    patient_t *pLastPatient ;
    patient_t *pPatient ;  
    patient_t *pNewPatient ;
    printf("Please Enter the number of Patients:");
    scanf("%d",&size);

    for (int i = 0;i < size;i++) 
    {
		if (i == 0) {
			pPatient = (patient_t*)malloc(sizeof(patient_t));
			pLastPatient = pPatient ;
		}
        else
        {
            pNewPatient= (patient_t*)malloc(sizeof(patient_t);)
            pPatient->Snext=pNewPatient ;
            pPatient=pNewPatient ;
        }
        Get_Patient_Data(pPatient);
        pNewPatient->Snext=NULL ;
        pPatient->Sindex = i ;
        printf("\n\n\r")

    }

    printf("Please Enter ID to Search for :");
    int TsearchID ; // temp search id 
    scanf("%d",&TsearchID) ;
    index = Get_Patient_Data(pLastPatient, size,TsearchID);
    printf("index is %d\n", index);

    patient_t pSearch = pLastPatient ;
    for (int i =0 ; i< index ; i++)
    {
        pSearch= pSearch->Snext ;

    }
    Print_Patient_Data(pSearch);

    



    
}


/*************************************************************************
*                           Function definitions
*************************************************************************/
int Get_Patient_Index(patient_t pArr[], unsigned int ArrSize, unsigned int SearchID)
{
    signed int result= -1 ;
    patient_t * ptr =pArr ;
    for(signed int i= 0 ; i< ArrSize ; i++)
    {
        if(ptr->SID== SearchID)
        {
            result= ptr->Sindex ;
            break ;
        }
        ptr=ptr->Snext ;
    }    

    return result ;

}

void Print_Patient_Data(struct patient* pArr) 
{

    printf("Name: %s\n",pArr->Sname);
    printf("ID: %d \n",pArr->SID) ;
    printf("wieght: %d \n",pArr(SWieght))
}

void Get_Patient_Data(struct patient* pArr) {
	int ID;
	float wieght;
	char name[20];
	printf("enter user ID:");
	scanf("%d", &ID);
	printf("enter name :");
	scanf("%s", name);
	printf("enter weight:");
	scanf("%f", &wieght);
	pArr->SID = ID;
	pArr->SWieght = W;
	strcpy(pArr->Sname, name);
}
