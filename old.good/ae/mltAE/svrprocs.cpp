
#include "stdafx.h"
#include "mltAE.h"
#include "AEplugin.h"
#include "SmartShape.h"
#include "fontdata.h"


void _sp_init() {
	g_Config.svrproc._get_plugin_hdr = _sp_get_plugin_hdr;
}


PluginHeader *_stdcall _sp_get_plugin_hdr(void *plistentry) {
	return (PluginHeader *)(
		(long)plistentry + sizeof(List) + sizeof(InstalledPluginHeader)
		);
}
