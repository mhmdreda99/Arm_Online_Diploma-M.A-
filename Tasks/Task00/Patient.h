#ifndef PATIENT_H_
#define PATIENT_H_
/*****************************************************************************
*                               COMMON HEADER FILE
*
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct patient {
	int SID;
	char Sname[20];
	float SWidth;
}patient_t;

/*****************************************************************************
*                               FUNCTIONS PROTOTYPES
*
*****************************************************************************/

int Get_Patient_Index(patient_t pArr[], unsigned int ArrSize, unsigned int SearchID);
void Print_Patient_Data(patient_t* pArr);
void Get_Patient_Data(patient_t* pArr);



#endif 
