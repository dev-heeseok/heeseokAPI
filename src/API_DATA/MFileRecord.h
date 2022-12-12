#pragma once

class MRelationalDatabase;
class AFX_EXT_CLASS MFileRecord : public CObject
{
public:
	MFileRecord();
	virtual ~MFileRecord();

public:
	virtual BOOL Read(MRelationalDatabase* pRDBMS) = 0;
	virtual BOOL Write(MRelationalDatabase* pRDBMS) = 0;

};

