#pragma once

#ifndef DATA_BASE_DEF
#define DATA_BASE_DEF

#define SEGMENT_FLAG_UNKNOWN	0x0000
#define SEGMENT_FLAG_ADDED		0x0001
#define SEGMENT_FLAG_DELETED	0x0002
#define SEGMENT_FLAG_MODIFIED	0x0004
#define SEGMENT_FLAG_CHANGED	0x0008

#define IS_VALID(x) ((x) > 0)
#define VFPTR_SIZE	sizeof(DWORD_PTR)

using MITERATOR	= DWORD_PTR;
using MKEY = int; // TODO. based on 1

#endif // !DATA_BASE_DEF
