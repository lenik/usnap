
#pragma once

LPCTSTR	spaces(int level);
OLECHAR	*towcs(LPCTSTR mbs);
LPCTSTR	tombs(OLECHAR *wcs);
void	saveFile(IStorage *pStg, LPCTSTR basePath, LPCTSTR fileName);
