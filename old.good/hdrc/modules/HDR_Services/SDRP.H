

#pragma once


/*
    SDR Procedure
    ---------------------------------------------------------------------------

        P - User Interface Parameters
        K - Kernel Function Factor Values
        R - Analyse Report
*/

struct BrokenInfo {
    enum BrokenCourseType {
        cuzPhysical,                    // 一般物理原因
        cuzPhysicalFall,                // 摔坏
        cuzPhysicalShake,               // 振动过渡
        cuzPhysicalShock,               // 强电流电击
        cuzPhysicalUpsideDown,          // 运行时倒置或垂直放置
        cuzPhysicalEnvironment,         // 温湿度超过指标等
        cuzVirus,                       // 被病毒破坏
        cuzToolsForFormat,              // 使用了格式化工具
        cuzToolsForPartition,           // 使用了分区工具, 如fdisk, pqmagic,
        cuzToolsForRecover,             // 使用了恢复工具, 如KV300分区表恢复, RecoverNTFS文件恢复, CHKDSK丢失簇恢复等
        cuzToolsForLowCopy,             // 使用了低级拷贝工具, 如HDCOPY, Norton Ghost
        cuzExpired,                     // 超过了可靠使用的年限
        cuzAbnormalShutdown,            // 非正常关机
    };

    enum BrokenBehaviorType {
        beDiskNotFound,                 // 电路或磁头等故障, BIOS不支持, 或电源/数据线未连接
        beDiskNotMount,                 // MBR损坏
        bePartNotFound,                 // MBR或扩展分区记录中丢失该分区信息, 或分区的文件系统无法识别
        bePartNotMount,                 // 分区BPB损坏, 或根目录未找到, 操作系统不承认根目录有效性
        bePartNotBootUp,                // 非活动分区, 分区系统文件丢失等
        beDirectoryClobber,             // 目录乱码, (分主目录和其它目录)
        beDataError,                    // 数据错误
        beDataInstability,              // 数据不稳定
        beIOLatency,                    // I/O 延时
    };

    // 相关参数
    enum BrokenBehaviorValues {
        DC_Root,                        // 根目录乱码
        DC_Other,                       // 其它目录乱码(如子目录, 或不止一个等)
        DE_LotsOfLostClusters,          // 数据错误 - 发现大量丢失簇
        DE_Recently,                    // 数据错误 - 最近
        DE_Ago,                         // 数据错误 - 以前
        DI_LotsOfBadSectors,            // 数据不稳定 - 坏道过多
        DI_OldFiles,                    // 数据不稳定 - 特别是早期的文件经常无故出错
        IOL_Aware,                      // I/O 延时 - 可察觉的
        IOL_Anxious,                    // I/O 延时 - 严重干扰的
    };

    BrokenCourseType        m_Course;
    BrokenBehaviorType      m_Behavior;
    BrokenBehaviorValues    m_Detail;
};


// P0 - Overview Analyse

    // Disk rather than Partition
    struct Disk_P0 {
    };

    struct FATx_P0 {
        struct Parameters {
            BOOL bDetectClusterSize;                // 字节单位
            BOOL bDetectFATxSubSystem;              // FAT-12, FAT-16, FAT-32 之一
            BOOL bDetectFATMirroring;
            BOOL bDetectActiveFAT;                  // 哪一个FAT拷贝是活动的
            BOOL bDetectFSI;                        // 识别 FSI
            BOOL bDetectBootBackup;                 // 识别 BPB 备份
        } P;
        struct Kernel {
        } K;
        struct Report {
        } R;
    };


// P1 - Structured Analyse

    struct FATx_P1 {
        struct Parameters {
            BOOL bDetectRootCluster;                // 根目录所在簇
            BOOL bDetectRootSize;                   // 根目录的最大文件数
        } P;
        struct Kernel {
        } K;
        struct Report {
        } R;
    };

// P2 - Review & Dump


    struct FATx_P2 {
        struct Parameters {
        } P;
        struct Kernel {
        } K;
        struct Report {
        } R;
    };


// SDR Procedures

    struct FATx_SDRP {
        FATx_P0 P0;
        FATx_P1 P1;
        FATx_P2 P2;
    };


    struct ServiceFeatures {
        BOOL    FileAccessSupport;
        //BOOL
    };


    struct IFSAccess {
        ILockByts *Open(ID);
    };
