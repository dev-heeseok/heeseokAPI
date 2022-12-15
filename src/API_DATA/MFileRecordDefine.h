#pragma once

#ifndef RECORD_DEF
#define RECORD_DEF

enum class RecordType
{
	kFileVer = 0,
	//kDB,
	//kEOF,
	kNum
};

enum class RecordVer
{
	k100 = 100,

};

#define RECORD_VERSION_LATEST	RecordVer::k100

#endif // !RECORD_DEF
