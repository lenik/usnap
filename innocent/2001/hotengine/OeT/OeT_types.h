
#pragma once

#include "resource.h"
#include "OeT.h"

typedef std::pair<_bstr_t, _bstr_t>	_hash_bstr_t;
typedef std::vector<_bstr_t>		_bstr_vector_t;
typedef std::vector<_hash_bstr_t>	_hash_bstr_vector_t;
typedef std::vector<_variant_t>		_variant_vector_t;
typedef std::vector<_variant_vector_t>	_variant_table_t;
//typedef std::vector<_

typedef CComObject<OeTVariant>		COeTVariant;
typedef CComObject<OeTString>		COeTString;
typedef CComObject<OeTArray>		COeTArray;
typedef CComObject<OeTChain>		COeTChain;
typedef CComObject<OeTQueue>		COeTQueue;
typedef CComObject<OeTStack>		COeTStack;
typedef CComObject<OeTQueue>		COeTQueue;
typedef CComObject<OeTSet>		COeTSet;
typedef CComObject<OeTTable>		COeTTable;
typedef CComObject<OeTHash>		COeTHash;
typedef CComObject<OeTTree2>		COeTTree2;
typedef CComObject<OeTTree>		COeTTree;
typedef CComObject<OeTGraph>		COeTGraph;
typedef CComObject<OeTCodedStream>	COeTCodedStream;

#include "OeTVariant.h"
#include "OeTString.h"
#include "OeTArray.h"
#include "OeTChain.h"
#include "OeTQueue.h"
#include "OeTStack.h"
#include "OeTSet.h"
#include "OeTTable.h"
#include "OeTHash.h"
#include "OeTTree2.h"
#include "OeTTree.h"
#include "OeTGraph.h"
#include "OeTCodedStream.h"
