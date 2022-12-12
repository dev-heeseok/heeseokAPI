#include "pch.h"
#include "MFileBulk.h"

MFileBulk::MFileBulk()
    : m_pFile(nullptr)
{
}

MFileBulk::~MFileBulk()
{
}

BOOL MFileBulk::Open(CString strFilePath, CString strMode)
{
    errno_t err = _tfopen_s(&m_pFile, strFilePath, strMode);

    if (err == EACCES || err != 0)
    {
        // err == EACCESS, Permission Denied
        ASSERT(FALSE);
        return FALSE;
    }

    return TRUE;
}

void MFileBulk::Close()
{
    if (m_pFile)
        fclose(m_pFile);

    m_pFile = nullptr;
}
