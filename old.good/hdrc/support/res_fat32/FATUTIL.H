
#define SEPERATE_LINE				\
	"-----------------------------------------------------------\n"
#define DUMP_TITLE(title)			\
	cout << "\n" << title << "\n" << SEPERATE_LINE;
#define DUMP_IF_BIT(v, b)			\
	if ((v) & (b)) printf("\t" #b "\n");
#define DUMP_PROPERTY(obj, member)		\
	printf("%-30s= %12d (%Xh)\n", #member,	\
		obj->member, obj->member);
#define DUMP_PROPNAME(obj, member)              \
	printf("%-30s= ", #member);
#define DUMP_PROPERTY_BINARY(obj, member, l) {	\
	DUMP_PROPNAME(obj, member);		\
	printf("\n\t");				\
	DumpBytes((PFAR)obj->member, l);	\
	printf("\n"); }
#define DUMP_PROPERTY_STRING(obj, member, l) {	\
	DUMP_PROPNAME(obj, member);		\
	printf("\n\t");				\
	DumpString((PFAR)obj->member, l);	\
	printf("\n"); }

void DumpBytes(PFAR pv, int len) {
	BYTE far *p = (BYTE far *)pv;
	for (int i = 0; i < len; i++) {
		printf("%02x ", p[i]);
		if (i % 16 == 15) printf("\n\t");
	}
}
void DumpBytes(WORD seg, WORD off, int len) {
	DumpBytes((PFAR)MK_FP(seg, off), len);
}
void DumpString(PFAR pv, int len, int bSZ = 1) {
	char far *pbuf = (char far *)pv;
	for (int i = 0; i < len; i++) {
		int c = pbuf[i];
		if (bSZ && c == 0) break;
		printf("%c", c);
	}
}

void DumpDriveParameters(DriveParameters *pDP) {
	DUMP_TITLE("Drive Parameters: ");
	DUMP_PROPERTY(pDP, wFlags);
		DUMP_IF_BIT(pDP->wFlags, DPF_DMA_ERROR);
		DUMP_IF_BIT(pDP->wFlags, DPF_CHS_VALID);
		DUMP_IF_BIT(pDP->wFlags, DPF_REMOVABLE);
		DUMP_IF_BIT(pDP->wFlags, DPF_WRITE_VERIFY_SUPP);
		DUMP_IF_BIT(pDP->wFlags, DPF_CHANGE_LINE_SUPP);
		DUMP_IF_BIT(pDP->wFlags, DPF_CAN_BE_LOCKED);
		DUMP_IF_BIT(pDP->wFlags, DPF_CHS_OVERFLOW);
	DUMP_PROPERTY(pDP, nCylinders);
	DUMP_PROPERTY(pDP, nHeads);
	DUMP_PROPERTY(pDP, nSectors);
	DUMP_PROPNAME(pDP, nTotalSectors);
		cout 	<< pDP->nTotalSectors.high << "<<32 + "
			<< pDP->nTotalSectors.low
			<< "\n";
	DUMP_PROPERTY(pDP, nSectorSize);
	DUMP_PROPERTY(pDP, pEDDConfig);
	DUMP_PROPERTY(pDP, wSign);
	DUMP_PROPERTY(pDP, cbDevicePathInfo);
	DUMP_PROPERTY(pDP, fccBus);
	DUMP_PROPERTY(pDP, xInterface);
	DUMP_PROPERTY(pDP, xInterfacePath);
	DUMP_PROPERTY(pDP, xDevicePath);
	DUMP_PROPERTY(pDP, Checksum);
}

void DumpEnhancedDiskDriveSpec(EDD_Spec *pEDD) {
	DUMP_TITLE("Enhanced Disk Drive Spec: ");
	DUMP_PROPERTY(pEDD, wIOBase)
	DUMP_PROPERTY(pEDD, wControlPort);
	DUMP_PROPERTY(pEDD, Flags);
		DUMP_IF_BIT(pEDD->Flags, EDDF_SLAVE);
		DUMP_IF_BIT(pEDD->Flags, EDDF_LBA_ENABLED);
	DUMP_PROPERTY(pEDD, Proprietary);
	DUMP_PROPERTY(pEDD, IRQ);
	DUMP_PROPERTY(pEDD, nMultiSectors);
	DUMP_PROPERTY(pEDD, DMA);
	DUMP_PROPERTY(pEDD, PIO);
	DUMP_PROPERTY(pEDD, wOptions);
		DUMP_IF_BIT(pEDD->wOptions, EDD_OPT_FAST_PIO);
		DUMP_IF_BIT(pEDD->wOptions, EDD_OPT_FAST_DMA);
		DUMP_IF_BIT(pEDD->wOptions, EDD_OPT_BLOCK_PIO);
		DUMP_IF_BIT(pEDD->wOptions, EDD_OPT_CHS);
		DUMP_IF_BIT(pEDD->wOptions, EDD_OPT_LBA);
		DUMP_IF_BIT(pEDD->wOptions, EDD_OPT_REMOVABLE);
		DUMP_IF_BIT(pEDD->wOptions, EDD_OPT_ATAPI);
		DUMP_IF_BIT(pEDD->wOptions, EDD_OPT_32_BIT);
		DUMP_IF_BIT(pEDD->wOptions, EDD_OPT_ATAPI_DRQ);
		DUMP_IF_BIT(pEDD->wOptions, EDD_OPT_TRANS_MASK);
		DUMP_IF_BIT(pEDD->wOptions, EDD_OPT_UDMA);
	DUMP_PROPERTY(pEDD, nRevLevel);
	DUMP_PROPERTY(pEDD, Checksum);
};

void DumpDriveInformation(DriveInformation *pDI) {
	DUMP_TITLE("Drive Information: ");
	DUMP_PROPERTY(pDI, wFlags);
		DUMP_IF_BIT(pDI->wFlags, DIF_HARD_SECTORED);
		DUMP_IF_BIT(pDI->wFlags, DIF_SOFT_SECTORED);
		DUMP_IF_BIT(pDI->wFlags, DIF_NOT_MFM_ENCODED);
		DUMP_IF_BIT(pDI->wFlags, DIF_SLOW_HEAD_SWITCH);
		DUMP_IF_BIT(pDI->wFlags, DIF_IMP_SPINDLE_MOTOR);
		DUMP_IF_BIT(pDI->wFlags, DIF_FIXED);
		DUMP_IF_BIT(pDI->wFlags, DIF_REMOVABLE_CART);
		DUMP_IF_BIT(pDI->wFlags, DIF_LOW_DTR);
		DUMP_IF_BIT(pDI->wFlags, DIF_MIDDLE_DTR);
		DUMP_IF_BIT(pDI->wFlags, DIF_HIGH_DTR);
		DUMP_IF_BIT(pDI->wFlags, DIF_HIGH_ROT_SPEED_TOL);
		DUMP_IF_BIT(pDI->wFlags, DIF_DATA_STROBE_OFF);
		DUMP_IF_BIT(pDI->wFlags, DIF_TRACK_OFF);
		DUMP_IF_BIT(pDI->wFlags, DIF_FORMAT_TOL_GAP);
		DUMP_IF_BIT(pDI->wFlags, DIF_NON_MAGNETIC_DRIVE);
	DUMP_PROPERTY(pDI, nCylinders);
	DUMP_PROPERTY(pDI, nHeads);
	DUMP_PROPERTY(pDI, nTrackSize);
	DUMP_PROPERTY(pDI, nSectorSize);
	DUMP_PROPERTY(pDI, nSectorsPerTrack);
	DUMP_PROPERTY_STRING(pDI, szSerialNumber, 20);
	DUMP_PROPERTY(pDI, wBufferType);
	DUMP_PROPERTY(pDI, nBufferSize512);
	DUMP_PROPERTY(pDI, cbECC_RWLongCmds);
	DUMP_PROPERTY_STRING(pDI, szFirmwareRev, 8);
	DUMP_PROPERTY_STRING(pDI, szModel, 40);
	DUMP_PROPERTY(pDI, nMaxSectorsPerInt);
	DUMP_PROPERTY(pDI, bDoublewordIO);
	DUMP_PROPERTY(pDI, wCapabilities);
		DUMP_IF_BIT(pDI->wCapabilities, DIC_DMA_SUPPORTED);
	DUMP_PROPERTY(pDI, timeCyclePIO);
	DUMP_PROPERTY(pDI, timeCycleDMA);
	DUMP_PROPERTY(pDI, bTranslationModeValid);
	DUMP_PROPERTY(pDI, nCurCylinders);
	DUMP_PROPERTY(pDI, nCurSectorsPerTrack);
	DUMP_PROPERTY(pDI, nCurCapacityInSectors);
};
