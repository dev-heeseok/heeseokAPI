#include "pch.h"
#include "MRelationalDatabase.h"

#include "../API_LIB/StandardFuncLibrary.h"
#include "../API_DATA/MRelationalDatabaseType.h"
#include "../API_DATA/MProjectSettingSchema.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace util;

MRelationalDatabase::MRelationalDatabase()
{
}

MRelationalDatabase::~MRelationalDatabase()
{
}

void MRelationalDatabase::PrebuildSchema()
{
	// Schema 등록 순서 중요

}

void MRelationalDatabase::PostbuildSchema()
{
	// Schema 등록 순서 중요

}

void MRelationalDatabase::BuildSchema()
{
	// Schema 등록 순서 중요

	AppendSchema(new MProjectSettingSchema(this, EnumIndex(MRelationalDatabaseType::kProjectSetting)));
}
