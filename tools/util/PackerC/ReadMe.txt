
将会用于生成安装程序的软件基础
----------------------------------------------------------------
Packer C

	打包工作环境	Packer Studio
	打包编译器	Packer Compiler


计划方案

	1、提出 PDS 打包描述脚本
	2、打包文件规范
	3、PC的扩充方法


1、包描述脚本 Packer Description Script (working)
	PDS/0 基本规范
	PDS/1 原始数据描述
	PDS/2 数据类型扩展		对数据类型的解释及获取
	PDS/3 初级编码 块流变换		形式转换
	PDS/4 数据编码 流处理		有效提高压缩律及安全性
	PDS/5 后端扩展			发送到媒体以及扩展
	PDS/6 前端扩展			用户设置解包配制过程


	PDS/0 基本规范
		结构式程序

	PDS/1
		* 原始数据类型和结构体
		* 扩充类型:xtype
			# xtype file;
			# xtype registry;
		* 数据定义
			* 脚本数据
				int x = 3, y = 4;
				file f1 = file::open(...);
			* 输出数据
				int://3;
				int://4;
				file://d:\data\abc.dat;
	PDS/2 数据类型扩展(I/O)
		* 将数据类型的实现连结至DLL::API
			xtype file(setupass.dll::FileApi)
		* 在脚本内实现
			xtype file {
				string filename;
				in {
					long hf = file::open(filename);
					read(hf, buf);
				}
				out {
					long hf = file::open(filename);
					write(hf, buf);
				}
			}
	PDS/3 初级编码
		PDS/3A 初级编码 快/流
		PDS/3B 初级解码 流/块
	PDS/4 数据编码
		PDS/4A 数据编码
		PDS/4B 数据解码
	PDS/5 后端扩展

	PDS/6 前端扩展


2、打包文件规范

	* 打包流程
	* 打包方法接口
