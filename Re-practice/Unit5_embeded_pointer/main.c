#include <stdio.h>
#include <stdint.h>
typedef struct BASE
{
    volatile const uint32_t MODE;
    volatile uint32_t SET;
    uint32_t CLEAR;
} BASE_t;
int main()
{
    // volatile const uint32_t * REG = (volatile const uint32_t *)0x40000000; // Example address
    BASE_t reg;
    BASE_t *reg_ptr = &reg;

    printf("address of MODE in BASE_t: %x\n", (unsigned int)(void *)&reg.MODE);
    printf("address of SET in BASE_t: %x\n", (unsigned int)(void *)&reg.SET);
    printf("address of CLEAR in BASE_t: %x\n", (unsigned int)(void *)&reg.CLEAR);

    printf("address of MODE in BASE_t: %x\n", (unsigned int)(void *)&reg_ptr->MODE);

    printf("address of SET in BASE_t: %x\n", (unsigned int)(void *)&reg_ptr->SET);
    printf("address of CLEAR in BASE_t: %x\n", (unsigned int)(void *)&reg_ptr->CLEAR);

    // gan gia tri CLEAR = 5
    reg_ptr->CLEAR = 5;
    //gan gia tri SET = 10
    reg_ptr->SET = 10;
    //gan gia tri MODE = 15 khog duoc vi MODE la volatile const
    // reg_ptr->MODE = 15; 

        printf("Gia tri of MODE in BASE_t: %u\n", (unsigned int)(void *)reg_ptr->MODE);

    printf("Gia tri of SET in BASE_t: %u\n", (unsigned int)(void *)reg_ptr->SET);
    printf("Gia tri of CLEAR in BASE_t: %u\n", (unsigned int)(void *)reg_ptr->CLEAR);
    return 0;
}