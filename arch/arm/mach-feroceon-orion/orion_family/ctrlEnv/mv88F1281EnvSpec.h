/*******************************************************************************
Copyright (C) Marvell International Ltd. and its affiliates

This software file (the "File") is owned and distributed by Marvell 
International Ltd. and/or its affiliates ("Marvell") under the following
alternative licensing terms.  Once you have made an election to distribute the
File under one of the following license alternatives, please (i) delete this
introductory statement regarding license alternatives, (ii) delete the two
license alternatives that you have not elected to use and (iii) preserve the
Marvell copyright notice above.

********************************************************************************
Marvell Commercial License Option

If you received this File from Marvell and you have entered into a commercial
license agreement (a "Commercial License") with Marvell, the File is licensed
to you under the terms of the applicable Commercial License.

********************************************************************************
Marvell GPL License Option

If you received this File from Marvell, you may opt to use, redistribute and/or 
modify this File in accordance with the terms and conditions of the General 
Public License Version 2, June 1991 (the "GPL License"), a copy of which is 
available along with the File in the license.txt file or by writing to the Free 
Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 or 
on the worldwide web at http://www.gnu.org/licenses/gpl.txt. 

THE FILE IS DISTRIBUTED AS-IS, WITHOUT WARRANTY OF ANY KIND, AND THE IMPLIED 
WARRANTIES OF MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE ARE EXPRESSLY 
DISCLAIMED.  The GPL License provides additional details about this warranty 
disclaimer.
********************************************************************************
Marvell BSD License Option

If you received this File from Marvell, you may opt to use, redistribute and/or 
modify this File under the following licensing terms. 
Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    *   Redistributions of source code must retain the above copyright notice,
	    this list of conditions and the following disclaimer. 

    *   Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution. 

    *   Neither the name of Marvell nor the names of its contributors may be 
        used to endorse or promote products derived from this software without 
        specific prior written permission. 
    
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR 
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON 
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*******************************************************************************/


#ifndef __IN88F1281CtrlEnvSpech
#define __IN88F1281CtrlEnvSpech


#define MV_ARM_SOC

#define SOC_NAME_PREFIX	"MV88F"

#define INTER_REGS_SIZE	 	 	_1M

#define MV_ETH_REG_BASE(port)      	0
#define USB_REG_BASE(dev)		0

/* This define describes the maximum controller supported DRAM chip select 	*/
/* also known as banks                                                     	*/
#define MV_DRAM_MAX_CS      4
#define MV_INCLUDE_SDRAM_CS0
#define MV_INCLUDE_SDRAM_CS1
#define MV_INCLUDE_SDRAM_CS2
#define MV_INCLUDE_SDRAM_CS3

/* This define describes the maximum controller supported DEVICE chip select 	*/
/* also known as banks                                                     	*/
#define MV_DEVICE_MAX_CS      2
#define MV_INCLUDE_DEVICE_CS0
#define MV_INCLUDE_DEVICE_CS1
#define MV_BOOTDEVICE_INDEX   1



/* This define describes maximum of GPP groups supported by controller. 	*/
#define MV_GPP_MAX_GROUP    1


/* This define describes the maximum number of available Timer/counters.  	*/
#define MV_CNTMR_MAX_COUNTER 2

/* This define describes the maximum number of available UART channels.  	*/
#define MV_UART_MAX_CHAN	 2


/* This define describes maximum number of MPP groups.                      */
/* Each group describes an MPP register.  	                                */
#define MV_MPP_MAX_GROUP    2

/* This define describes the maximum number of supported PCI\PCIX Interfaces*/
#define MV_PCI_MAX_IF		0
#define MV_PCI_START_IF		0

/* This define describes the maximum number of supported PEX Interfaces 	*/
#if defined(MV_INCLUDE_PEX)
#define MV_PEX_MAX_IF		2
#else
#define MV_PEX_MAX_IF		0
#endif
#define MV_PEX_START_IF		MV_PCI_MAX_IF

/* This define describes the maximum number of supported PCI Interfaces 	*/
#define MV_PCI_IF_MAX_IF   	(MV_PEX_MAX_IF+MV_PCI_MAX_IF)

#define PEX_HOST_BUS_NUM(pciIf)		(pciIf)
#define PEX_HOST_DEV_NUM(pciIf)		0

#define PCI_HOST_BUS_NUM(pciIf)		MV_PEX_MAX_IF + (pciIf)
#define PCI_HOST_DEV_NUM(pciIf)		0


/* This define describes the maximum number of supported Ethernet ports 	*/
#define MV_ETH_MAX_PORTS	0
#define MV_ETH_PORT_SGMII   {}

/* This define describes the maximum number of supported IDMA channels. 	*/
#define MV_IDMA_MAX_CHAN    0

/* This define describes the the support of USB 	*/
#define MV_USB_MAX   	0

/* This define describes the support of the NAND -Flash */
#define MV_NAND_MAX		1


#define SATA_REG_BASE           0x80000

/* Controler environment registers offsets */
#define MPP_CONTROL_REG0				0x10000
#define MPP_CONTROL_REG1				0x10004
#define MPP_CONTROL_REG2				0x10050
#define DEV_MULTI_CONTROL				0x10008
#define MPP_SAMPLE_AT_RESET				0x10010
#define MV_UART_CHAN_BASE(chanNum)			(0x12000 + (chanNum * 0x100))

#define MSAR_TCLCK_OFFS					10
#define MSAR_TCLCK_MASK				    	(0x3 << MSAR_TCLCK_OFFS)
#define MSAR_TCLCK_133					(0x0 << MSAR_TCLCK_OFFS)
#define MSAR_TCLCK_150					(0x1 << MSAR_TCLCK_OFFS)
#define MSAR_TCLCK_166					(0x2 << MSAR_TCLCK_OFFS)

/* This array is beening call from several files. 
   mvCpuArm.c, mvBoardEnvLib.c, mvCpuIfInit.S */
/* ARM CPU clock vs. DDR clock */
#define MV_CPU_IF_ARMDDRCLCK_TBL    {\
    /* CPU FREQ, DDR FREQ, RATIO */\
    {333333333, 166666667, 2},\
    {500000000, 166666667, 3},\
    {666666666, 166666667, 4},\
    {833333333, 166666667, 5},\
    {1000000000, 166666667, 6},\
    {1166666666, 166666667, 7},\
    {400000000, 200000000, 2},\
    {600000000, 200000000, 3},\
    {800000000, 200000000, 4},\
    {1000000000, 200000000, 5},\
    {1050000000, 150000000, 10},\
    {466666666, 233333334, 2},\
    {700000000, 233333334, 3},\
    {933333333, 233333334, 4},\
    {1166666666, 233333334, 5},\
    {500000000, 250000000, 2},\
    {750000000, 250000000, 3},\
    {1000000000, 250000000, 4},\
    {1250000000, 250000000, 5},\
    {533333333, 266666667, 2},\
    {800000000, 266666667, 3},\
    {1066666666, 266666667, 4},\
    {700000000, 100000000, 7},\
    {400000000, 133333334, 3},\
    {533333333, 133333334, 4},\
    {666666666, 133333334, 5},\
    {800000000, 133333334, 6},\
    {933333333, 133333334, 7},\
    {1, 4, 4},\
    {1, 3, 3},\
    {1, 2, 2},\
    {1, 1, 1}\
};

#define MSAR_ARMDDRCLCK_OFFS		   	6

#define MSAR_ARMDDRCLCK_MASK			(0xf << MSAR_ARMDDRCLCK_OFFS)
#define MSAR_ARMDDRCLCK_H_MASK			BIT19


/* These macros help units to identify a target Mbus Arbiter group */
#define MV_TARGET_IS_DRAM(target)   \
                            ((target >= SDRAM_CS0) && (target <= SDRAM_CS3))

#define MV_TARGET_IS_PEX0(target)   \
                            ((target >= PEX0_MEM) && (target <= PEX0_IO))


						
#define MV_TARGET_IS_PEX1(target)   \
                            ((target >= PEX1_MEM) && (target <= PEX1_IO))

#define MV_TARGET_IS_PEX(target) (MV_TARGET_IS_PEX0(target) || MV_TARGET_IS_PEX1(target))

#define MV_TARGET_IS_DEVICE(target) \
                            ((target >= DEVICE_CS0) && (target <= DEVICE_CS1))

#define MV_PCI_DRAM_BAR_TO_DRAM_TARGET(bar)   0


#define MV_TARGET_IS_AS_BOOT(target)	0
#define BOOT_TARGETS_NAME_ARRAY 		{}
#define MV_CHANGE_BOOT_CS(target)		(target)

#define TCLK_TO_COUNTER_RATIO   1   /* counters running in Tclk */
/* typedefs */


#ifndef MV_ASMLANGUAGE
/* This enumerator described the possible Controller paripheral targets.    */
/* Controller peripherals are designated memory/IO address spaces that the  */
/* controller can access. They are also refered as "targets"                */
typedef enum _mvTarget
{
    TBL_TERM = -1, /* none valid target, used as targets list terminator*/
    SDRAM_CS0,      /* SDRAM chip select 0                                  */  
    SDRAM_CS1,      /* SDRAM chip select 1                                  */  
    SDRAM_CS2,      /* SDRAM chip select 2                                  */  
    SDRAM_CS3,      /* SDRAM chip select 3                                  */  
    PEX0_MEM,		/* PCI Express 0 Memory				    */
    PEX0_IO,		/* PCI Express 0 IO				    */
    PEX1_MEM,		/* PCI Express 1 Memory				    */
    PEX1_IO,		/* PCI Express 1 IO				    */
    INTER_REGS,     /* Internal registers                                   */  
    FLASH_CS,     	/* Flash chip select	                            */  
    DEV_BOOCS,    	/* Flash Boot chip select		            */  
    MAX_TARGETS

}MV_TARGET;

/* CV Support */
#define PEX0_MEM0	PEX0_MEM
#define PEX1_MEM0	PEX1_MEM

/* For old competability */
#define DEVICE_CS0	FLASH_CS
#define DEVICE_CS1	DEV_BOOCS

#define START_DEV_CS   DEV_CS0
#define DEV_TO_TARGET(dev)	((dev) + DEVICE_CS0)

/* Device Interface registers offsets */
#define DEV_BANK_PARAM_REG(num)	  		((num) ? 0x1046C : 0x10464)

/* Device Interface NAND Flash Control Register (DINFCR) */
#define DINFCR_NF_CS_MASK(csNum)         (0x1 << (((csNum)+3) * 2))
#define DINFCR_NF_ACT_CE_MASK(csNum)     (0x2 << (((csNum)+3) * 2))


#define PCI_IF0_MEM0		PEX0_MEM
#define PCI_IF0_IO		PEX0_IO
#define PCI_IF1_MEM0		PEX1_MEM
#define PCI_IF1_IO		PEX1_IO


/* This enumerator defines the Marvell controller target ID      */ 
typedef enum _mvTargetId
{
    DRAM_TARGET_ID = 0 ,    /* Port 0 -> DRAM interface         */
    DEV_TARGET_ID  = 1,     /* Port 1 -> PCI Express 		    */
    PEX1_TARGET_ID  = 3 ,    /* Port 4 -> PCI Express0 		    */
    PEX0_TARGET_ID  = 4 ,    /* Port 4 -> PCI Express0 		    */
    MAX_TARGETS_ID
}MV_TARGET_ID;


#define TARGETS_DEF_ARRAY	{					\
    {0x0E,DRAM_TARGET_ID}, /* SDRAM_CS0 */		\
    {0x0D,DRAM_TARGET_ID}, /* SDRAM_CS1 */		\
    {0x0B,DRAM_TARGET_ID}, /* SDRAM_CS2 */		\
    {0x07,DRAM_TARGET_ID}, /* SDRAM_CS3 */		\
    {0x59,PEX0_TARGET_ID}, /* PEX0_MEM */		\
    {0x51,PEX0_TARGET_ID}, /* PEX0_IO */		\
    {0x59,PEX1_TARGET_ID}, /* PEX1_MEM */		\
    {0x51,PEX1_TARGET_ID}, /* PEX1_IO */		\
    {0xFF,	    0xFF}, /* INTER_REGS */		\
    {0x1B,DEV_TARGET_ID}, /* FLASH_CS */		\
    {0x0F,DEV_TARGET_ID} /* DEV_BOOCS*/         \
}


#define TARGETS_NAME_ARRAY	{					\
    "SDRAM_CS0", /* SDRAM_CS0 */		\
    "SDRAM_CS1", /* SDRAM_CS1 */		\
    "SDRAM_CS2", /* SDRAM_CS2 */		\
    "SDRAM_CS3", /* SDRAM_CS3 */		\
    "PEX0_MEM", /* PEX0_MEM */		\
    "PEX0_IO", /* PEX0_IO */		\
    "PEX1_MEM", /* PEX1_MEM */		\
    "PEX1_IO", /* PEX1_IO */		\
    "INTER_REGS", /* INTER_REGS */	\
    "FLASH_CS", /* FLASH_CS */		\
    "DEV_BOOCS" /* DEV_BOOCS*/       \
}

#endif /* MV_ASMLANGUAGE */


#endif /* __IN88F1281CtrlEnvSpech */
