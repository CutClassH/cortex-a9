#include <stdint.h>
#include <stdio.h>
#include "pl011.h"
#include "pl050.h"
#include "pl111.h"
#include "sp804.h"
#include "interrupt.h"

extern void MMU_TestSetup();
int main(void){
 	//interrupt_init();
	int i;
 	//timer_init();
	printf("Hello,World!\n");

	for(i = 0; i < 64; i=i+4){
		*(volatile uint32_t*)(0x63000000+i) = i << 16;
	}
	MMU_TestSetup();
	// for(i = 0; i < 64/4; i++){
	// 	printf("%8lx ",*(volatile uint32_t*)(0x61000000+i));
	// 	if (i % 8 == 7)
	// 		printf("\n");
	// }
	for(i = 0; i < 64; i=i+4){
		printf("%8lx ",*(volatile uint32_t*)(0x62000000+i));
		if (i % 32 == 28)
			printf("\n");
	}
	printf("\n");
	for(i = 0; i < 64; i=i+4){
		printf("%8lx ",*(volatile uint32_t*)(0x63000000+i));
		if (i % 32 == 28)
			printf("\n");
	}
	printf("\n");
	for(i = 0; i < 64; i=i+4){
		printf("%8lx ",*(volatile uint32_t*)(0x64000000+i));
		if (i % 32 == 28)
			printf("\n");
	}

	for(i = 0; i < 64; i=i+4){
		*(volatile uint32_t*)(0x64000000+i) = i << 8;
	}

	printf("\n\n");
	for(i = 0; i < 64; i=i+4){
		printf("%8lx ",*(volatile uint32_t*)(0x63000000+i));
		if (i % 32 == 28)
			printf("\n");
	}
	printf("\n");
	for(i = 0; i < 64; i=i+4){
		printf("%8lx ",*(volatile uint32_t*)(0x64000000+i));
		if (i % 32 == 28)
			printf("\n");
	}
 	asm volatile("SVC 0x05");
 	for(;;);
	return 0;
}
