#ifndef __TEMPLATE_ADCHS_REGISTERS_PIC32MZ_EF_H_
#define __TEMPLATE_ADCHS_REGISTERS_PIC32MZ_EF_H_

typedef struct adchs_cmp_reg {
    uint32_t ADCCMPEN;
    uint32_t ADCCMP;
} adchs_cmp_register_t;

typedef struct adchs_regs {
    __ADCCON1bits_t ADCCON1;            /* 0x00 */
    __ADCCON2bits_t ADCCON2;            /* 0x04 */
    __ADCCON3bits_t ADCCON3;            /* 0x08 */
    uint32_t ADCTRGMODE;                /* 0x0C */
    uint32_t ADCIMCONx[3];              /* 0x10 - 0x18 */
    uint32_t DONTUSE1;                  /* 0x1C */
    uint32_t ADCGIRQENx[2];             /* 0x20 - 0x24 */
    uint32_t ADCCSSx[2];                /* 0x28 - 0x2C */
    uint32_t ADCSTATx[2];               /* 0x30 - 0x34 */
    adchs_cmp_register_t adccmpx[6];    /* 0x38 - 0x64 */
    __ADCFLTR1bits_t ADCFLTRx[6];       /* 0x68 - 0x7C */
    uint32_t ADCTRGx[3];                /* 0x80 - 0x88 */
    uint32_t DONTUSE2[5];               /* 0x8C - 0x9C */
    __ADCCMPCON1bits_t ADCCMPCONx[6];   /* 0xA0 - 0xB4 */   
    __ADCFSTATbits_t ADCFSTAT;          /* 0xB8 */
    uint32_t ADCFIFO;                   /* 0xBC */
    uint32_t ADCBASE;                   /* 0xC0 */
    uint32_t DONTUSE3[3];               /* 0xC4 - 0xCC */
    uint32_t ADCTRGSNS;                 /* 0xD0 */
    uint32_t ADCxTIME[5];               /* 0xD4 - 0xE4 */
    uint32_t DONTUSE4[2];               /* 0xE8 - 0xEC */
    uint32_t ADCEIENx[2];               /* 0xF0 - 0xF4 */
    uint32_t ADCEISTATx[2];             /* 0xF8 - 0xFC */
    uint32_t ADCANCON;                  /* 0x100 */
    uint32_t DONTUSE5[31];              /* 0x104 - 0x17C */
    uint32_t ADCxCFG[8];                /* 0x180 - 0x19C */
    uint32_t DONTUSE6[8];               /* 0x620 - 0x63C */
    uint32_t ADCSYSCFGx[2];             /* 0x1C0 - 0x1C4 */
    uint32_t DONTUSE7[14];             /* 0x1C8 - 0x1FC */
    uint32_t ADCDATAx[44];              /* 0x200 - 0x2B0 */
} adchs_register_t;

#ifndef BIT
#define BIT(x)   (1 << (x))
#endif

//******************************************************************************
/* Function :  ADCHS_ExistsRegisters_PIC32MZ_EF

  Summary:
    Implements default variant of ADCHS_ExistsRegisters_PIC32MZ_EF

  Description:
    This template implements the default variant of the ADCHS_ExistsRegisters_PIC32MZ_EF function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsRegisters_PIC32MZ_EF( ADCHS_MODULE_ID index )
{
    return true;
}

#endif /* __TEMPLATE_ADCHS_REGISTERS_PIC32MZ_EF_H_ */
