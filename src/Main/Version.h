#pragma once

#ifndef _VERSION_H_
#define _VERSION_H_

#define TO_STR(_STR_) #_STR_
#define TO_STR_VER(_MAJOR_, _MINOR_, _PATCH_, _BUILD_) TO_STR(_MAJOR_._MINOR_._PATCH_._BUILD_)

#define PRODUCT_NAME	"HEESEOK API"
#define DESCRIPTION		"HEESEOK API"
#define COMPANY_NAME	"dev-heeseok"
#define COPYRIGHT		"dev-heeseok. All rights reserved."

#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_PATCH 0
#define VERSION_BUILD 2
#define FULL_VERSION TO_STR_VER(VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, VERSION_BUILD)

#endif // !_VERSION_H_
