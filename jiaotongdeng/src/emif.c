/********************************************************************************/
/*	Filename:	emif.c															*/
/*	Function:	Config emif														*/
/********************************************************************************/

#include <csl.h>
#include <csl_emif.h>

/*FLASH��EMIF����*/
EMIF_Config MyEmifConfig = {
EMIF_GBLCTL1_RMK(					// EMIF Global Control Register 1
  EMIF_GBLCTL1_NOHOLD_HOLD_ENABLED,	// Hold enable
  EMIF_GBLCTL2_EK2HZ_HIGHZ,			// EMIF_GBLCTL1_EK1HZ_EK1ENHigh-Z control
  EMIF_GBLCTL1_EK1EN_ENABLED		// ECLKOUT1 Enable
  ),
EMIF_GBLCTL2_RMK(					// EMIF Global Control Register 2
  EMIF_GBLCTL2_EK2RATE_1XCLK,		// ECLKOUT2 Rate
  EMIF_GBLCTL2_EK2HZ_HIGHZ,			// EMIF_GBLCTL2_EK2HZ_EK2ENEK2HZ = 0, ECLKOUT2 is driven with value specified by EKnEN during
  EMIF_GBLCTL2_EK2EN_DISABLED		// ECLKOUT2 Enable (enabled by default)
  ), 
EMIF_CE1CTL1_RMK(					// CE1 Space Control Register 1
  EMIF_CE1CTL1_TA_OF(3),			// Turn-Around time
  EMIF_CE1CTL1_READ_STROBE_OF(6),	// Read strobe width
  EMIF_CE1CTL1_MTYPE_16BIT_ASYNC,	// Access type
  EMIF_CE1CTL1_WRITE_HOLD_MSB_LOW,	// Write hold width MSB bitHIGH
  EMIF_CE1CTL1_READ_HOLD_OF(3)		// Read hold width
  ),
EMIF_CE1CTL2_RMK(					// CE1 Space Control Register 2
  EMIF_CE1CTL2_WRITE_SETUP_OF(4),	// Write setup width
  EMIF_CE1CTL2_WRITE_STROBE_OF(10),	// Write strobe width
  EMIF_CE1CTL2_WRITE_HOLD_OF(2),	// Write hold width
  EMIF_CE1CTL2_READ_SETUP_OF(2)		// Read setup width
  ),
EMIF_CE0CTL1_RMK(					// CE0 Space Control Register 1
  EMIF_CE0CTL1_TA_DEFAULT,
  EMIF_CE0CTL1_READ_STROBE_DEFAULT,
  EMIF_CE0CTL1_MTYPE_DEFAULT,
  EMIF_CE0CTL1_WRITE_HOLD_MSB_DEFAULT,
  EMIF_CE0CTL1_READ_HOLD_DEFAULT
  ),
EMIF_CE0CTL2_RMK(					// CE0 Space Control Register 2
  EMIF_CE0CTL2_WRITE_SETUP_DEFAULT,
  EMIF_CE0CTL2_WRITE_STROBE_DEFAULT,
  EMIF_CE0CTL2_WRITE_HOLD_DEFAULT,
  EMIF_CE0CTL2_READ_SETUP_DEFAULT
  ),
EMIF_CE2CTL1_RMK(					// CE2 Space Control Register 1
  EMIF_CE2CTL1_TA_DEFAULT,			// Not use for SDRAM (asynchronous memory types only)
  EMIF_CE2CTL1_READ_STROBE_DEFAULT,	// Read strobe width
  EMIF_CE2CTL1_MTYPE_32BIT_SDRAM,	// 32-bit-wide SDRAM
  EMIF_CE2CTL1_WRITE_HOLD_DEFAULT,	// Write hold width
  EMIF_CE2CTL1_READ_HOLD_DEFAULT	// Read hold width
  ),
EMIF_CE2CTL2_RMK(					// CE2 Space Control Register 2
  EMIF_CE2CTL2_WRITE_SETUP_DEFAULT,	// Write setup width
  EMIF_CE2CTL2_WRITE_STROBE_DEFAULT,// Write strobe width
  EMIF_CE2CTL2_WRITE_HOLD_DEFAULT,	// Write hold width
  EMIF_CE2CTL2_READ_SETUP_DEFAULT	// Read setup width
  ),
EMIF_CE3CTL1_RMK(					// CE3 Space Control Register 1
  EMIF_CE3CTL1_TA_OF(3),			// Turn-Around time
  EMIF_CE3CTL1_READ_STROBE_OF(6),	// Read strobe width
  EMIF_CE3CTL1_MTYPE_16BIT_ASYNC,	// Access type
  EMIF_CE3CTL1_WRITE_HOLD_MSB_LOW,	// Write hold width MSB bitHIGH
  EMIF_CE3CTL1_READ_HOLD_OF(3)	
  ),
EMIF_CE3CTL2_RMK(					// CE3 Space Control Register 2
  EMIF_CE3CTL2_WRITE_SETUP_OF(4),	// Write setup width
  EMIF_CE3CTL2_WRITE_STROBE_OF(10),	// Write strobe width
  EMIF_CE3CTL2_WRITE_HOLD_OF(2),	// Write hold width
  EMIF_CE3CTL2_READ_SETUP_OF(2)		// Read setup width
  ),
EMIF_SDCTL1_RMK(					// SDRAM Control Register 1
  EMIF_SDCTL1_TRC_OF(6),			// Specifies tRC value of the SDRAM in EMIF clock cycles.
  EMIF_SDCTL1_SLFRFR_DISABLED		// Auto-refresh mode
  ),
EMIF_SDCTL2_RMK(					// SDRAM Control Register 2
  0x11,								// 4 banks,11 row address, 8 column address
  EMIF_SDCTL2_RFEN_ENABLED,			// Refresh enabled
  EMIF_SDCTL2_INIT_INIT_SDRAM,
  EMIF_SDCTL2_TRCD_OF(1),			// Specifies tRCD value of the SDRAM in EMIF clock cycles
  EMIF_SDCTL2_TRP_OF(1)				// Specifies tRP value of the SDRAM in EMIF clock cycles
  ),
0x61B,								// SDRAM Refresh Control Register 1
0x0300,								// SDRAM Refresh Control Register 2
EMIF_SDEXT1_RMK(					// SDRAM Extension Register 1
  EMIF_SDEXT1_R2WDQM_1CYCLE,
  EMIF_SDEXT1_RD2WR_3CYCLES,
  EMIF_SDEXT1_RD2DEAC_1CYCLE,
  EMIF_SDEXT1_RD2RD_1CYCLE,
  EMIF_SDEXT1_THZP_OF(1),			// tPROZ2=2
  EMIF_SDEXT1_TWR_OF(0),			//
  EMIF_SDEXT1_TRRD_2CYCLES,
  EMIF_SDEXT1_TRAS_OF(4),
  EMIF_SDEXT1_TCL_2CYCLES
  ),
EMIF_SDEXT2_RMK(					// SDRAM Extension Register 2
  EMIF_SDEXT2_WR2RD_0CYCLES,
  EMIF_SDEXT2_WR2DEAC_1CYCLE,
  0,
  EMIF_SDEXT2_R2WDQM_1CYCLE
  ),
EMIF_CE1SEC1_DEFAULT,				// CE1 Secondary Control Register 1
EMIF_CE0SEC1_DEFAULT,				// CE0 Secondary Control Register 1
EMIF_CE2SEC1_DEFAULT,				// CE2 Secondary Control Register 1
EMIF_CE3SEC1_DEFAULT,				// CE3 Secondary Control Register 1
EMIF_CESCR_DEFAULT					// CE Size Control Register								
  };

/********************************************************************************/
/*	Functionname:	void Emif_Config(void)										*/
/*	Function:		Realize emif configuration									*/
/********************************************************************************/

extern void Emif_Config(void)
{
	/*EMIFΪȫEMIF�ӿ�*/
    CHIP_RSET(XBSR,0x0001);
    
    /*����ϵͳ��EMIF�ӿ�*/
    EMIF_config(&MyEmifConfig);
}

/****************************************************************************************************/
//	No	more
/****************************************************************************************************/
