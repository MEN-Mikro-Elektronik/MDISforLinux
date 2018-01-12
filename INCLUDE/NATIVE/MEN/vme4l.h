/***********************  I n c l u d e  -  F i l e  ************************/
/*!
 *        \file  vme4l.h
 *
 *      \author  klaus.popp@men.de
 *        $Date: 2014/09/30 16:50:22 $
 *    $Revision: 2.6 $
 *
 *  	 \brief  VME4L definitions/structure shared between user/kernel-mode
 *
 *     Switches: -
 */
/*-------------------------------[ History ]---------------------------------
 *
 * $Log: vme4l.h,v $
 * Revision 2.6  2014/09/30 16:50:22  ts
 * R: Address modifiers (AM) can now be set dynamically in Z002
 * M: added 2 new ioctl codes for AM get and set
 *
 * Revision 2.5  2009/06/03 19:37:12  rt
 * R: 1.) Cosmetics.
 * M: 1.) Tsi148 comment removed.
 *
 * Revision 2.4  2009/04/30 22:00:05  rt
 * R: 1) Support for TSI148 VME bridge.
 * M: 1) Comments for TSI148 added.
 *
 * Revision 2.3  2009/03/24 12:47:56  rt
 * R: 1. Support for TSI148 VMEbus-bridge
 * M: 1. A64/slave windows defines added (by sv)
 *
 * Revision 2.2  2004/07/26 16:31:30  kp
 * added support for slave windows, mailbox, location
 *
 * Revision 2.1  2003/12/15 15:02:16  kp
 * Initial Revision
 *
 * (c) Copyright 2003 by MEN Mikro Elektronik GmbH, Nuremberg, Germany
 ******************************************************************************/
/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _VME4L_H
#define _VME4L_H

#  ifdef __cplusplus
      extern "C" {
#  endif

/* include header for original VME4L */
#include <MEN/vme4l_old.h>

typedef unsigned long vmeaddr_t;

/**********************************************************************/
/** VME space definitions
 *
 */
typedef enum {
	VME4L_SPC_A16_D16=0,		/**< Short non priviledged (D16) */
	VME4L_SPC_A24_D64_BLT=1,	/**< Extended non priviledged (D64-BLT) */
	VME4L_SPC_A16_D32=2,		/**< Short non priviledged (D32) */
	/* empty line contained VME4L_SPC_A16_D32_BLT */
	VME4L_SPC_A24_D16=4,		/**< Standard non priviledged (D16) */
	VME4L_SPC_A24_D16_BLT=5,	/**< Standard non priviledged (D16-BLT) */
	VME4L_SPC_A24_D32=6,		/**< Standard non priviledged (D32) */
	VME4L_SPC_A24_D32_BLT=7,	/**< Standard non priviledged (D32-BLT) */
	VME4L_SPC_A32_D32=8,		/**< Extended non priviledged (D32) */
	VME4L_SPC_A32_D32_BLT=9,	/**< Extended non priviledged (D32-BLT) */
	VME4L_SPC_A32_D64_BLT=10,	/**< Extended non priviledged (D64-BLT) */

	VME4L_SPC_SLV0=11,			/**< slave (inbound) window #0 */
	VME4L_SPC_SLV1=12,			/**< slave (inbound) window #1 */
	VME4L_SPC_SLV2=13,			/**< slave (inbound) window #2 */
	VME4L_SPC_SLV3=14,			/**< slave (inbound) window #3 */
	VME4L_SPC_SLV4=15,			/**< slave (inbound) window #4 */
	VME4L_SPC_SLV5=16,			/**< slave (inbound) window #5 */
	VME4L_SPC_SLV6=17,			/**< slave (inbound) window #6 */
	VME4L_SPC_SLV7=18,			/**< slave (inbound) window #7 */
	VME4L_SPC_MST0=19,			/**< master (outbound) window #0 */
	VME4L_SPC_MST1=20,			/**< master (outbound) window #1 */
	VME4L_SPC_MST2=21,			/**< master (outbound) window #2 */
	VME4L_SPC_MST3=22,			/**< master (outbound) window #3 */
	VME4L_SPC_MST4=23,			/**< master (outbound) window #4 */
	VME4L_SPC_MST5=24,			/**< master (outbound) window #5 */
	VME4L_SPC_MST6=25,			/**< master (outbound) window #6 */
	VME4L_SPC_MST7=26,			/**< master (outbound) window #7 */
	VME4L_SPC_A64_D32=27,		/**< Long non priviledged (D32) */
	VME4L_SPC_A64_2EVME=28,		/**< Long non priviledged (2eVME) */
	VME4L_SPC_A64_2ESST=29,		/**< Long non priviledged (2eSST) */
	VME4L_SPC_CR_CSR=30,		/**< Special CR/CSR config space (r/o) */
	VME4L_SPC_INVALID=255
} VME4L_SPACE;

/**********************************************************************/
/** \defgroup VME4L_IRQVEC VME interrupt vectors.
 * Numbers 0 to 0x100 correspond to VME vectors.
 * Numbers above 0x100 are pseudo vectors for interrupts generated by the VME
 * bridge.
 *  @{
 */
/** spurious VME interrupt */
#define VME4L_IRQVEC_SPUR	 		0x100
/** fake vector for bus error interrupt */
#define VME4L_IRQVEC_BUSERR 		0x101
/** fake vector for ACFAIL interrupt */
#define VME4L_IRQVEC_ACFAIL 		0x102
/** fake vector for SYSFAIL interrupt */
#define VME4L_IRQVEC_SYSFAIL 		0x103
/** fake vector for mailbox _n interrupt caused by VME read access */
#define VME4L_IRQVEC_MBOXRD(_n)		(0x110+((_n)*2))
/** fake vector for mailbox _n interrupt caused by VME write access */
#define VME4L_IRQVEC_MBOXWR(_n)		(0x111+((_n)*2))
/** fake vector for location monitor n interrupt */
#define VME4L_IRQVEC_LOCMON(_n)		(0x120+(_n))

#define VME4L_NUM_VECTORS			0x130
/*! @} */

/***********************************************************************/
/** \defgroup VME4L_IRQLEV VME interrupt levels.
 * Numbers 1 to 7 correspond to the VME IRQ lines 1 to 7.
 * Numbers above 7 are special VME interrupts generated by the VME
 * bridge.
 *  @{
 */
#define VME4L_IRQLEV_UNKNOWN		0 /**< IRQ level unknown */
#define VME4L_IRQLEV_1				1 /**< VME IRQ level 1  */
#define VME4L_IRQLEV_2				2 /**< VME IRQ level 2  */
#define VME4L_IRQLEV_3				3 /**< VME IRQ level 3  */
#define VME4L_IRQLEV_4				4 /**< VME IRQ level 4  */
#define VME4L_IRQLEV_5				5 /**< VME IRQ level 5  */
#define VME4L_IRQLEV_6				6 /**< VME IRQ level 6  */
#define VME4L_IRQLEV_7				7 /**< VME IRQ level 7  */

/** fake level for bus error interrupt */
#define VME4L_IRQLEV_BUSERR 		8
/** fake level for ACFAIL interrupt */
#define VME4L_IRQLEV_ACFAIL 		9
/** fake level for SYSFAIL interrupt */
#define VME4L_IRQLEV_SYSFAIL 		10
/** fake level for mailbox _n interrupt caused by VME read access */
#define VME4L_IRQLEV_MBOXRD(_n)		(0x10+((_n)*2))
/** fake level for mailbox _n interrupt caused by VME write access */
#define VME4L_IRQLEV_MBOXWR(_n)		(0x11+((_n)*2))
/** fake level for location monitor n interrupt */
#define VME4L_IRQLEV_LOCMON(_n)		(0x20+(_n))

#define VME4L_NUM_LEVELS			0x30
/*! @} */

/**********************************************************************/
/** \defgroup VME4L_RWFLAGS flags for VME_Read() and VME_Write()
 * The following flags can be combined (binary ORed):
 *  @{
 */
/** no flags */
#define VME4L_RW_NOFLAGS			0
/* use posted writes in PIO mode, if available */
/*#define VME4L_RW_USE_POSTED_WR 		0x01*/
/** use DMA engine for non-BLT spaces */
#define VME4L_RW_USE_DMA 			0x02
#define VME4L_RW_KERNEL_SPACE_DMA 		0x04

/*! @} */

/**********************************************************************/
/** \defgroup VME4L_IRQFLAGS flags for VME_SigInstall()
 * The following flags can be combined (binary ORed):
 *  @{
 */
/** no flags */
#define VME4L_IRQ_NOFLAGS	0x00
/** interrupt is cleared by VMEbus IACK */
#define VME4L_IRQ_ROAK 		0x01
/** enable specified interrupt level */
#define VME4L_IRQ_ENBL		0x02
/*! @} */


/**********************************************************************/
/** \defgroup VME4L_SWAPMODE swap mode for VME4L_SwapModeSet()
 * The following flags can be combined (binary ORed):
 *
 * \tsi148 TSI148 VME bridge does not support hardware swapping! User
 * application has to care for swapping by its own!
 *
 *  @{
 */
/** no hardware swapping */
#define VME4L_NO_SWAP		0x00

/** X86 systems only: use hardware swap mode1.
 * Applicable for VME4L_Read(), VME4L_Write(), VME4L_Map()
 * VME4L_RmwCycle() and VME4L_AOnlyCycle()
 *
 * mutual exclusive with #VME4L_SW_ADR_SWAP
 */
#define VME4L_HW_SWAP1				0x01

/** X86 systems only: perform address swapping in software.
 * Applicable for VME4L_Read(), VME4L_Write() non-DMA modes,
 * VME4L_RmwCycle() and VME4L_AOnlyCycle().
 *
 * This mode corrects low order address bits.
 *
 * mutual exclusive with #VME4L_HW_SWAP1
 */
#define VME4L_SW_ADR_SWAP			0x02

/*! @} */

/* definitions shared between driver and API lib */

typedef struct {
	vmeaddr_t vmeAddr;
	int direction; /**< 0 for read, 1 for write */
	int accWidth;
	size_t size;
	void *dataP;
	int flags;
} VME4L_RW_BLOCK;

typedef struct {
	int vector;
	int level;
	int signal;
	int flags;
} VME4L_SIG_INSTALL2;

typedef struct {
	int attr;
	vmeaddr_t 	addr;
	int clear;
} VME4L_BUS_ERROR_INFO;

typedef struct {
	vmeaddr_t vmeAddr;
	int accWidth;
	uint32_t mask;
	uint32_t rv;
} VME4L_RMW_CYCLE;

typedef struct {
	vmeaddr_t vmeAddr;
} VME4L_AONLY_CYCLE;

typedef struct {
	vmeaddr_t vmeAddr;
	size_t size;
} VME4L_SLAVE_WINDOW_CTRL;

typedef struct {
	int mbox;
	int direction; /**< 0 for read, 1 for write */
	uint32_t val;
} VME4L_MBOX_RW;				/* used also for VME4L_IO_LOCMON_REG_RW */


#define VME4L_IO_RW_BLOCK			_IOW( VME4L_IOC_MAGIC, 10, VME4L_RW_BLOCK )
#define VME4L_IO_SIG_INSTALL2 		_IOW( VME4L_IOC_MAGIC, 11, VME4L_SIG_INSTALL2 )
#define VME4L_IO_SIG_UNINSTALL 			_IO( VME4L_IOC_MAGIC, 12 )
#define VME4L_IO_SYS_CTRL_FUNCTION_GET 	_IO( VME4L_IOC_MAGIC, 13 )
#define VME4L_IO_SYS_CTRL_FUNCTION_SET 	_IO( VME4L_IOC_MAGIC, 14 )
#define VME4L_IO_POSTED_WRITE_MODE_GET 	_IO( VME4L_IOC_MAGIC, 15 )
#define VME4L_IO_POSTED_WRITE_MODE_SET 	VME4L_IO_SET_POSTED_WRITE
#define VME4L_IO_SYS_RESET				_IO( VME4L_IOC_MAGIC, 16 )
#define VME4L_IO_ARBITRATION_TIMEOUT_GET _IO( VME4L_IOC_MAGIC, 17 )

#define VME4L_IO_BUS_ERROR_GET	 	_IOWR( VME4L_IOC_MAGIC, 18, VME4L_BUS_ERROR_INFO )

#define VME4L_IO_REQUESTER_MODE_GET 	_IO( VME4L_IOC_MAGIC, 19 )
#define VME4L_IO_REQUESTER_MODE_SET 	_IO( VME4L_IOC_MAGIC, 20 )
#define VME4L_IO_IRQ_GENERATE2			_IO( VME4L_IOC_MAGIC, 21 )
#define VME4L_IO_IRQ_GEN_ACKED			_IO( VME4L_IOC_MAGIC, 22 )
#define VME4L_IO_IRQ_GEN_CLEAR			_IO( VME4L_IOC_MAGIC, 23 )
#define VME4L_IO_RMW_CYCLE  			_IOWR( VME4L_IOC_MAGIC, 24, VME4L_RMW_CYCLE )
#define VME4L_IO_AONLY_CYCLE  			_IOW( VME4L_IOC_MAGIC, 25, VME4L_AONLY_CYCLE )
#define VME4L_IO_SWAP_MODE_SET  		_IO( VME4L_IOC_MAGIC, 26 )
#define VME4L_IO_IRQ_ENABLE2	  		_IO( VME4L_IOC_MAGIC, 27 )
#define VME4L_IO_SLAVE_WINDOW_CTRL		_IO( VME4L_IOC_MAGIC, 28 )
#define VME4L_IO_MBOX_RW				_IO( VME4L_IOC_MAGIC, 29 )
#define VME4L_IO_LOCMON_REG_RW			_IO( VME4L_IOC_MAGIC, 30 )
#define VME4L_IO_ADDR_MOD_SET			_IO( VME4L_IOC_MAGIC, 31 )
#define VME4L_IO_ADDR_MOD_GET 			_IO( VME4L_IOC_MAGIC, 32 )
#define VME4L_IO_GEO_ADDR_GET    	 	_IO( VME4L_IOC_MAGIC, 33 )
#define VME4L_IO_REQUESTER_LVL_SET   	_IO( VME4L_IOC_MAGIC, 34 )
#define VME4L_IO_REQUESTER_LVL_GET 	 	_IO( VME4L_IOC_MAGIC, 35 )
#define VME4L_IO_CRCSR_BAR_SET			_IO( VME4L_IOC_MAGIC, 36 )
#define VME4L_IO_CRCSR_BAR_GET			_IO( VME4L_IOC_MAGIC, 37 )
#define VME4L_IOC_MAXNR 	         37

#  ifdef __cplusplus
       }
#  endif

#endif /* _VME4L_H */
