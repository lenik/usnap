

#pragma once


// namespace DeviceType {

/*
    设备类型    (--> POS)
    ------------------------------------------------------

    主要设备(计算机设备) - 32 bit
        设备类型/Device
            设备子类型
                厂商特性
    其它设备
*/

enum enumDevice {
    devUnknown,
    devSystem,                          // (主要是软件驱动)
    devProcessor,                       // 处理器:  CPU, FPU, BMP, ...
    devMonitor,                         // 显示器:  CRT, LCD, ...
    devPower,                           // 电源:    高级电源, UPS, ...
    devDisplay,                         // 显示卡:  CGA, VGA, SVGA, ...
    devMemory,                          // 内存:    SDRAM, DDR, L2 Cache, ROM, ...
    devStorage,                         // 存储器:  硬驱, 软驱, 移动存储, ...
    devInterface,                       // 接口:    ISA, PCI, I2C, AGP, 桥, ...
    devController,                      // 控制器:
    devPort,                            // 端口:    COM, LPT, USB, PS/2, 1394, ...
    devInput,                           // 输入:    键盘, 鼠标, 手写板, 摇杆, ...
    devOutput,                          // 输出:    力反馈,
    devMultimedia,                      // 多媒体:  声卡,
    devNetwork,                         // 网卡
    devMedia,                           // 介质:
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
