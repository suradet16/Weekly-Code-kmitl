#include<stdio.h>
#include<stdlib.h>

int main()
{

	char* c; 	 //ประกาศ character pointer
	c = (char*)malloc(sizeof(char));	// ให้ memory ที่ c

	*c = 'A';	//เก็บ A ไว้ที่ memory  ที่ pointer c เก็บไว้

	//เช็คค่า ASCII ของตัวอักษรจาก c 
	while (*c <= 'Z') {

		printf("%c\n", *c);
		*c = *c + 1;	// การเพิ่ม ค่า ASCII ของ charachter

	}

}