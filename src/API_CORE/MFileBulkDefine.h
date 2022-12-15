#pragma once

#ifndef BULK_DEF
#define BULK_DEF

enum class BulkIO
{
	kEmpty = 0,
	kUnknown,
	kSkip,
	kFixed,
	kIterator,
	kStruct,
	kArray,
	kNum
};

struct tagBulkIO
{
	TCHAR szName[20];
	
	UINT uiType;
	UINT uiSize;
	UINT uiOffset;
	
	UINT uiAType;
	UINT uiASize;

	const tagBulkIO* pBulkIO;
};

#define BULK_IO_DEF_LAST()\
{ _T(""), static_cast<UINT>(BulkIO::kEmpty), 0, 0, static_cast<UINT>(BulkIO::kEmpty), 0, nullptr }
#define BULK_IO_DEF_FIXED(_name, _class_name, _type, _value)\
{ _name, static_cast<UINT>(BulkIO::kFixed), sizeof(_type), offsetof(_class_name, _value), static_cast<UINT>(BulkIO::kEmpty), 0, nullptr },
#define BULK_IO_DEF_ITERATOR(_name, _class_name, _type, _value)\
{ _name, static_cast<UINT>(BulkIO::kIterator), sizeof(_type), offsetof(_class_name, _value), static_cast<UINT>(BulkIO::kEmpty), 0, nullptr },
#define BULK_IO_DEF_STRUCT(_name, _class_name, _type, _value)\
{ _name, static_cast<UINT>(BulkIO::kStruct), sizeof(_type), offsetof(_class_name, _value), static_cast<UINT>(BulkIO::kEmpty), 0, _type::GetBulkIO() },
#define BULK_IO_ARR_FIXED(_name, _class_name, _type, _value, _arr_type)\
{ _name, static_cast<UINT>(BulkIO::kArray), sizeof(_type), offsetof(_class_name, _value), static_cast<UINT>(BulkIO::kFixed), sizeof(_arr_type), nullptr },
#define BULK_IO_ARR_ITERATOR(_name, _class_name, _type, _value, _arr_type)\
{ _name, static_cast<UINT>(BulkIO::kArray), sizeof(_type), offsetof(_class_name, _value), static_cast<UINT>(BulkIO::kIterator), sizeof(_arr_type), nullptr },
#define BULK_IO_ARR_STRUCT(_name, _class_name, _type, _value, _arr_type)\
{ _name, static_cast<UINT>(BulkIO::kArray), sizeof(_type), offsetof(_class_name, _value), static_cast<UINT>(BulkIO::kStruct), sizeof(_arr_type), _type::GetBulkIO() },


#define BEGIN_BULK_IO(_class_name)\
static const _class_name& GetDefault() { static _class_name _instance; return _instance; }\
static const tagBulkIO* GetBulkIO() { static const tagBulkIO _instance[] = {
#define END_BULK_IO() BULK_IO_DEF_LAST() }; return _instance; }


struct tagBulkHead
{
	int nID;
	int nValue;
};

struct tagBulkData
{
	CString strName;
	BulkIO kBulkIO;


};

struct tagBulkBundle
{

};



#endif // !BULK_DEF