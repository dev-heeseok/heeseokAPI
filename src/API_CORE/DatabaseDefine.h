#pragma once

#ifndef DATABASE_DEF
#define DATABASE_DEF

typedef struct tagMParam
{
	DWORD idx : 29;		// bind seqeunce index
	DWORD removed : 1;	// delete flag
	DWORD modified : 1;	// modify flag
	DWORD mark : 1;		// conditional flag

	tagMParam() : idx(0), removed(0), modified(0), mark(0)
	{}

} MPARAM, * LPMPARAM;

enum class SchemaFlag : UINT
{
	kUNKNOWN = 0x0000,
	kADDED = 0x0001,
	kDELETED = 0x0002,
	kMODIFIED = 0x0004,
	kCHANGED = 0x0008,
};

using MITERATOR = DWORD_PTR;
using MKEY = int; // TODO. based on 1

constexpr auto VFPTR_SIZE = sizeof(DWORD_PTR);
constexpr auto DEFAULT_HASH_SIZE = 100;
constexpr auto PARAM_OFF = 0x0000;
constexpr auto PARAM_ON = 0x0001;

#define SAFE_DELETE(x) {if((x)){delete (x); (x) = NULL;}}
#define SAFE_DELETE_ARRAY(x) {if((x)){delete[] (x); (x) = NULL;}}

#define HASH_INDEX(x, size) ((x) % (size))
#define IS_VALID(x) ((x) > 0)

#define ITR_TO_PRIMARY_KEY(class_name, x) ((class_name*)((BYTE*)(x) + sizeof(MPARAM))->GetPrimaryKey())
#define DECLARE_PRIMARY_KEY(class_name, key_name)\
public:\
virtual MKEY GetPrimaryKey() const override { return *reinterpret_cast<MKEY*>(((BYTE*)this) + offsetof(class_name, key_name)); }\
virtual void SetPrimaryKey(MKEY _pk) override { *reinterpret_cast<MKEY*>(((BYTE*)this) + offsetof(class_name, key_name)) = _pk; }

#endif // !DATABASE_DEF
