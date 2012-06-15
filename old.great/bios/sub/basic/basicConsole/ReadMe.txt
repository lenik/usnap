

控制台作为输入输出设备与输入设备和输出设备的连接方式

〉如果以 DLL 方式编译控制台，则系统控制台窗口不会弹出。
〉如果以 EXE 方式编译控制台，则系统不能带动控制台启动。控制台与系统无法进行进程内的交互。

不管以何种方式，basicConsole只是作为一种用户界面。
它负责将键盘输入传递给basicInput设备，接受basicOutput设备的输出。


〉如果能够以进程内的方式启动控制台，则控制台的任务就是
〉负责将键盘输入传递给basicInput设备，接受basicOutput设备的输出。


〉远程工作的可行模式：
通过spool/input, output缓冲池与模块间交互，则这种池必须是模块间独立的。
可以在/proc/$module/spool中设置数据实现。
添加spoolInput, spoolOutput设备后台检测数据


〉通过系统控制台API实现进程内控制台。
