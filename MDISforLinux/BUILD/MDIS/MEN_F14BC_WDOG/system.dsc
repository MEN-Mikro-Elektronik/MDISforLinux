#
# Automatically generated by mdiswiz 1.5.012_beta-linux-5
# 2006-06-18
#

cpu {

    # ------------------------------------------------------------------------
    #        general parameters (don't modify)
    # ------------------------------------------------------------------------
    DESC_TYPE = U_INT32 0x0
    HW_TYPE = STRING PC
}
smb2bb {

    # ------------------------------------------------------------------------
    #        general parameters (don't modify)
    # ------------------------------------------------------------------------
    DESC_TYPE = U_INT32 0x2
    HW_TYPE = STRING SMB2
    SMB_BUSNBR = U_INT32 0
    DEVICE_ID_0 = U_INT32 0x0

    # ------------------------------------------------------------------------
    #        debug levels (optional)
    #        these keys have only effect on debug drivers
    # ------------------------------------------------------------------------
    DEBUG_LEVEL = U_INT32 0xc0008007
    DEBUG_LEVEL_BK = U_INT32 0xc0008000
    DEBUG_LEVEL_OSS = U_INT32 0xc0008000
    DEBUG_LEVEL_DESC = U_INT32 0xc0008000
}

f14bc_1 {

    # ------------------------------------------------------------------------
    #        general parameters (don't modify)
    # ------------------------------------------------------------------------
    DESC_TYPE = U_INT32 0x1
    HW_TYPE = STRING f14bc

    # ------------------------------------------------------------------------
    #        reference to base board
    # ------------------------------------------------------------------------
    BOARD_NAME = STRING smb2bb
    DEVICE_SLOT = U_INT32 0x0

    # ------------------------------------------------------------------------
    #        device parameters
    # ------------------------------------------------------------------------

    # SMBus bus number
    SMB_BUSNBR = U_INT32 0

    # SMBus address of f14bc
    # Mind: Linux SMBus addresses are 7bit LSB aligned (original value 0x9a>>1 = 0x4d)

    SMB_DEVADDR = U_INT32 0x4d

    # poll period for voltage supervision
    # Range: 50..5000
    POLL_PERIOD = U_INT32 500

    # ------------------------------------------------------------------------
    #        debug levels (optional)
    #        these keys have only effect on debug drivers
    # ------------------------------------------------------------------------
    DEBUG_LEVEL = U_INT32 0xc0008007
    DEBUG_LEVEL_MK = U_INT32 0xc0008007
    DEBUG_LEVEL_OSS = U_INT32 0xc0008000
    DEBUG_LEVEL_DESC = U_INT32 0xc0008000
}
smb2_1 {

    # ------------------------------------------------------------------------
    #        general parameters (don't modify)
    # ------------------------------------------------------------------------
    DESC_TYPE = U_INT32 0x1
    HW_TYPE = STRING SMB2

    # ------------------------------------------------------------------------
    #        reference to base board
    # ------------------------------------------------------------------------
    BOARD_NAME = STRING SMB2BB
    DEVICE_SLOT = U_INT32 0x0

    # ------------------------------------------------------------------------
    #        device parameters
    # ------------------------------------------------------------------------
    # complete set of AD78 Parameters with their default Values:
    SMB_BUSNBR = U_INT32 0x0
    # Mind: Linux SMBus addresses are 7bit LSB aligned (0x12>>1 = 0x09)
	SMB_DEVADDR = U_INT32 0x50

    # ------------------------------------------------------------------------
    #        debug levels (optional)
    #        these keys have only effect on debug drivers
    # ------------------------------------------------------------------------
    DEBUG_LEVEL = U_INT32 0xc0008007
    DEBUG_LEVEL_MK = U_INT32 0xc0008003
    DEBUG_LEVEL_OSS = U_INT32 0xc0008000
    DEBUG_LEVEL_DESC = U_INT32 0xc0008000
}
# EOF