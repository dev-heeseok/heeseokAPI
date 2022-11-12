#pragma once

#ifndef _VERSION_H_
#define _VERSION_H_

#define TO_PGM_VER(v1, v2, v3, v4) (((v1) << 24) + ((v2) << 16) + ((v3) << 8) + (v4))

#define TO_STR(_STR_) #_STR_
#define TO_STR_VER(_MAJOR_, _MINOR_, _PATCH_, _BUILD_) TO_STR(_MAJOR_._MINOR_._PATCH_._BUILD_)

#define PRODUCT_CODE		1 // TODO. Original Project		
#define PRODUCT_VER_MAJOR	1
#define PRODUCT_VER_MINOR	0
#define PRODUCT_VER_PATCH	0
#define PRODUCT_VER_BUILD	2

#define PRODUCT_NAME		"HEESEOK API"
#define PRODUCT_DESC		"HEESEOK API"
#define PRODUCT_VER			TO_STR_VER(PRODUCT_VER_MAJOR, PRODUCT_VER_MINOR, PRODUCT_VER_PATCH, PRODUCT_VER_BUILD)
#define PRODUCT_FULL_VER	TO_PGM_VER(PRODUCT_VER_MAJOR, PRODUCT_VER_MINOR, PRODUCT_VER_PATCH, PRODUCT_VER_BUILD)

#define COMPANY				"dev-heeseok"
#define COPYRIGHT			"dev-heeseok. All rights reserved."

#define FILE_EXT			".heeseok"
#define FILE_FILTER			"HEESEOK API(*.heeseok)|*.heeseok|All Files(*.*)|*.*||"

#endif // !_VERSION_H_
