
#include "StdAfx.h"

#include "resource.h"

#include "EBSink1.h"

EBSink1::EBSink1() {
	this->m_eb1.CreateInstance(_T("CampoAccelerate.CaEventByref.1"));
}

EBSink1::~EBSink1() {
	this->m_eb1	= NULL;
}

void EBSink1::connect() {
	this->DispEventAdvise(this->m_eb1);
			//, &__uuidof(EventByrefLib::ICaEventByrefEvents));
}

void EBSink1::disconnect() {
	this->DispEventUnadvise(this->m_eb1);
}
