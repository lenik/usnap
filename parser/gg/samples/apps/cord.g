



#
# [Cordillera] 脉系语言
#







#

	- 承载关系树

	- 单元的预处理与反处理

	- 容器数据的生成与容器分解

	- BSD by Cord

	- 集成到 G 泛化语言中



# x@a.epfs segment [sample 1]

BITMAP Root {

	external link "./large_bitmap.bmp";


	# 左上角单元重载定义
	BITMAP unit_NWcorner {
		override parent.region(0, 0, 50, 50);
	}

	TEXT unit_caption {
		position at parent.coord(parent.width / 2 - 50, 20);
	}

}
