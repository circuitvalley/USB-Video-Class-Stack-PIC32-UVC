#ifndef __TEMPLATE_ADCHS_REGISTERS_PIC32WK_H_
#define __TEMPLATE_ADCHS_REGISTERS_PIC32WK_H_

typedef struct adchs_cmp_reg {
    uint32_t ADCCMPEN;
	uint32_t ADCCMPENCLR;
	uint32_t ADCCMPENSET;
	uint32_t ADCCMPENINV;
    uint32_t ADCCMP;
	uint32_t ADCCMPCLR;
	uint32_t ADCCMPSET;
	uint32_t ADCCMPINV;	
} adchs_cmp_register_t;

typedef struct adchs_flt_reg {
    __ADCFLTR1bits_t ADCFLTRx;
	uint32_t ADCFLTRxCLR;
	uint32_t ADCFLTRxSET;
	uint32_t ADCFLTRxINV;
} adchs_flt_register_t;

typedef struct adchs_trg_reg {
    uint32_t ADCTRGx;
	uint32_t ADCTRGxCLR;
	uint32_t ADCTRGxSET;
	uint32_t ADCTRGxINV;
} adchs_trg_register_t;


typedef struct adchs_cmpcon_reg {
    __ADCCMPCON0bits_t ADCCMPCONx;
	uint32_t ADCCMPCONxCLR;
	uint32_t ADCCMPCONxSET;
	uint32_t ADCCMPCONxINV;
} adchs_cmpcon_register_t;

typedef struct adchs_adcxtim_reg {
    uint32_t ADCxTIME;
	uint32_t ADCxTIMECLR;
	uint32_t ADCxTIMESET;
	uint32_t ADCxTIMEINV;
} adchs_adcxtim_register_t;

typedef struct adchs_adcxcfg_reg {
    uint32_t ADCxCFG;
	uint32_t ADCxCFGCLR;
	uint32_t ADCxCFGSET;
	uint32_t ADCxCFGINV;
} adchs_adcxcfg_register_t;

typedef struct adchs_adcdata_reg {
    uint32_t ADCDATA;
	uint32_t DONTUSE[3];
} adchs_adcdata_register_t;

typedef struct adchs_regs {
    __ADCCON1bits_t ADCCON1;
	volatile unsigned int ADCCON1CLR;
	volatile unsigned int ADCCON1SET;
	volatile unsigned int ADCCON1INV;
    __ADCCON2bits_t ADCCON2;
	volatile unsigned int ADCCON2CLR;
	volatile unsigned int ADCCON2SET;
	volatile unsigned int ADCCON2INV;	
    __ADCCON3bits_t ADCCON3;
	volatile unsigned int ADCCON3CLR;
	volatile unsigned int ADCCON3SET;
	volatile unsigned int ADCCON3INV;	
    uint32_t ADCTRGMODE;
	volatile unsigned int ADCTRGMODECLR;
	volatile unsigned int ADCTRGMODESET;
	volatile unsigned int ADCTRGMODEINV;		
    uint32_t ADCIMCONx[1];
	volatile unsigned int ADCIMCONxCLR;
	volatile unsigned int ADCIMCONxSET;
	volatile unsigned int ADCIMCONxINV;			
    uint32_t DONTUSE1[12];
    uint32_t ADCGIRQENx[1];
	volatile unsigned int ADCGIRQENxCLR;
	volatile unsigned int ADCGIRQENxSET;
	volatile unsigned int ADCGIRQENxINV;				
	uint32_t DONTUSE2[4];
    uint32_t ADCCSSx[1];
	volatile unsigned int ADCCSSxCLR;
	volatile unsigned int ADCCSSxSET;
	volatile unsigned int ADCCSSxINV;	
	uint32_t DONTUSE3[4];
    uint32_t ADCSTATx[1];
	volatile unsigned int ADCSTATxCLR;
	volatile unsigned int ADCSTATxSET;
	volatile unsigned int ADCSTATxINV;	
	uint32_t DONTUSE4[4];	
    adchs_cmp_register_t adccmpx[2];
	uint32_t DONTUSE5[32];
    adchs_flt_register_t ADCFLTRx[2];
	uint32_t DONTUSE6[16];
    adchs_trg_register_t ADCTRGx[2];
    uint32_t DONTUSE7[24];
    adchs_cmpcon_register_t ADCCMPCONx[2];
	uint32_t DONTUSE8[16];
    __ADCFSTATbits_t ADCFSTAT;
	volatile unsigned int ADCFSTATCLR;
	volatile unsigned int ADCFSTATSET;
	volatile unsigned int ADCFSTATINV;		
    uint32_t ADCFIFO;
	volatile unsigned int ADCFIFOCLR;
	volatile unsigned int ADCFIFOSET;
	volatile unsigned int ADCFIFOINV;		
    uint32_t ADCBASE;
	volatile unsigned int ADCBASECLR;
	volatile unsigned int ADCBASESET;
	volatile unsigned int ADCBASEINV;	
	__ADCDMASTbits_t ADCDMAST;
	volatile unsigned int ADCDMASTCLR;
	volatile unsigned int ADCDMASTSET;
	volatile unsigned int ADCDMASTINV;	
	uint32_t ADCCNTB;
	volatile unsigned int ADCCNTBCLR;
	volatile unsigned int ADCCNTBSET;
	volatile unsigned int ADCCNTBINV;	
	uint32_t ADCDMAB;
	volatile unsigned int ADCDMABCLR;
	volatile unsigned int ADCDMABSET;
	volatile unsigned int ADCDMABINV;	
    uint32_t ADCTRGSNS;
	volatile unsigned int ADCTRGSNSCLR;
	volatile unsigned int ADCTRGSNSSET;
	volatile unsigned int ADCTRGSNSINV;		
    adchs_adcxtim_register_t ADCxTIME[1];
    uint32_t DONTUSE9[40]; /* Early Interrupt not supported */
    uint32_t ADCANCON;
	volatile unsigned int ADCANCONCLR;
	volatile unsigned int ADCANCONSET;
	volatile unsigned int ADCANCONINV;			
    uint32_t DONTUSE10[124]; 
    adchs_adcxcfg_register_t ADCxCFG[8];  /* ADCxCFG[1] -- ADCxCFG[6] are unused */
    uint32_t DONTUSE11[32];  
    uint32_t ADCSYSCFGx[1];
    uint32_t DONTUSE12[191]; /* Gap includes ADCSYSCFGx SET, CLR and INV register */
    adchs_adcdata_register_t ADCDATAx[16];
} adchs_register_t;

#ifndef BIT
#define BIT(x)   (1 << (x))
#endif

//******************************************************************************
/* Function :  ADCHS_ExistsRegisters_pic32wk

  Summary:
    Implements default variant of ADCHS_ExistsRegisters_pic32wk

  Description:
    This template implements the default variant of the ADCHS_ExistsRegisters_pic32wk function.
*/

PLIB_TEMPLATE bool ADCHS_ExistsRegisters_pic32wk( ADCHS_MODULE_ID index )
{
    return true;
}

#endif /* __TEMPLATE_ADCHS_REGISTERS_PIC32WK_H_ */
