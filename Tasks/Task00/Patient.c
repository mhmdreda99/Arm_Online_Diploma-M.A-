#include "Patient.h"
/**
 * @brief 
 * 
 * @param pArr 
 * @param ArrSize 
 * @param SearchID 
 * @return int 
 */
int Get_Patient_Index(patient_t pArr[], unsigned int ArrSize, unsigned int SearchID)
{
   signed int index , i;
   for ( i = 0; i < ArrSize; i++)
   {
       /* code */
       if ((&pArr[i])->SID==SearchID)
       {
           index=i ;
           break;

       }
       return index ;
   }
   

}
/**
 * @brief 
 * this function is to print patient data 
 * @param pArr 
 */
void Print_Patient_Data(patient_t* pArr)
{
    printf("ID:%d\n", pArr->SID);
	printf("name:%s\n", pArr->Sname);
	printf("weight:%.2f\n", pArr->SWidth);

}
/**
 * @brief 
 * this function is to take the input data from user 
 * return nothong  
 * @param pArr pointer to array  
 */
void Get_Patient_Data(patient_t* pArr)
{
     int ID;
	float width;
	char name[20];
    printf("Please Enter Patient ID :");
    scanf("%d",&ID);
    printf("Please Enter Patient Name :");
    scanf("%c",name);
    printf("Please Enter Patient ID :");
    scanf("%f",&width);
    pArr->SID = ID;
	pArr->SWidth = width;
	strcpy(pArr->Sname, name);


}