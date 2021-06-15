#include "Patient.h"
void main(void)
{
    signed int SearchIndex;
    char size ;
    int userSearch  ; // temp variable to store user input for search 
    printf("Please Enter the number of Patients:");
    scanf("%d",&size);
    patient_t *pArr = (patient_t*)malloc(size*sizeof(patient_t));
    for(int i =0 ;i<size ;i++)
    {
        Get_Patient_Data(&pArr[i]);

    }
    printf("Please Enter the ID you want to Search: ");
    scanf("%d",&userSearch);
    SearchIndex=Get_Patient_Index(&pArr,size,userSearch);
    if ( SearchIndex ==-1 ) 
    {
        printf("Error, Not Found \n\r") ;

    }
    else  
    {
        printf("Patient Index = %d \n\r ",SearchIndex);
        Print_Patient_Data(&pArr[SearchIndex]);
        
    }
    
    
    




}