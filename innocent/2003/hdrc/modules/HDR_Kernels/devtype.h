

#pragma once


// namespace DeviceType {

/*
    �豸����    (--> POS)
    ------------------------------------------------------

    ��Ҫ�豸(������豸) - 32 bit
        �豸����/Device
            �豸������
                ��������
    �����豸
*/

enum enumDevice {
    devUnknown,
    devSystem,                          // (��Ҫ���������)
    devProcessor,                       // ������:  CPU, FPU, BMP, ...
    devMonitor,                         // ��ʾ��:  CRT, LCD, ...
    devPower,                           // ��Դ:    �߼���Դ, UPS, ...
    devDisplay,                         // ��ʾ��:  CGA, VGA, SVGA, ...
    devMemory,                          // �ڴ�:    SDRAM, DDR, L2 Cache, ROM, ...
    devStorage,                         // �洢��:  Ӳ��, ����, �ƶ��洢, ...
    devInterface,                       // �ӿ�:    ISA, PCI, I2C, AGP, ��, ...
    devController,                      // ������:
    devPort,                            // �˿�:    COM, LPT, USB, PS/2, 1394, ...
    devInput,                           // ����:    ����, ���, ��д��, ҡ��, ...
    devOutput,                          // ���:    ������,
    devMultimedia,                      // ��ý��:  ����,
    devNetwork,                         // ����
    devMedia,                           // ����:
};

enum enumDevProcessor {
    procCPU,
    procFPU,
    procGPU,
};
enum enumDevMonitor {
    monCRT,
    monLCD,
};

struct DeviceFeature {
    int bSoftware: 1;
    int bBlock: 1;
    int bSingleton: 1;
    int bReady_: 1;
    int bLock: 1;
    int bPNP: 1;
    int bRealtime: 1;
};
