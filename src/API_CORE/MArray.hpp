#pragma once

template <typename T>
class MArray
{
public:
	MArray() : m_aData(NULL), m_nSize(0)
	{}
	MArray(int size) : m_aData(NULL), m_nSize(0)
	{
		this->SetSize(size);
	}
	MArray(int size, T Val) : m_aData(NULL), m_nSize(0)
	{
		this->SetSize(size);
		for (int i = 0; i < size; i++)
			(*this)[i] = Val;
	}
	MArray(const MArray<T>& src) : m_aData(NULL), m_nSize(0)
	{
		if (src.m_nSize)
		{
			size_t sztype = sizeof(T);
			size_t szbuffer = src.m_nSize * sztype;

			m_aData = (T*)malloc(szbuffer);
			memcpy_s(m_aData, szbuffer, src.m_aData, szbuffer);

			m_nSize = src.m_nSize;
		}
	}
	~MArray() { RemoveAll(); }

	MArray<T>& operator=(const MArray<T>& src)
	{
		if (&src.m_aData == &m_aData)
			return *this;

		if (m_aData)
			free(m_aData);

		size_t sztype = sizeof(T);
		size_t szbuffer = src.m_nSize * sztype;

		m_aData = (T*)malloc(szbuffer);
		memcpy_s(m_aData, szbuffer, src.m_aData, szbuffer);

		m_nSize = src.m_nSize;

		return *this;
	}

	// Operations

	long GetSize() const { return m_nSize; }
	long GetCount() const { return m_nSize; }
	void Copy(const MArray<T>& src)
	{
		if (&src.m_aData == &m_aData)
			return;

		if (m_aData)
			free(m_aData);

		size_t sztype = sizeof(T);
		size_t szbuffer = src.m_nSize * sztype;

		m_aData = (T*)malloc(szbuffer);
		memcpy_s(m_aData, szbuffer, src.m_aData, szbuffer);

		m_nSize = src.m_nSize;
	}

	void Append(const MArray<T>& src)
	{
		if (src.IsEmpty())
			return;

		size_t sztype = sizeof(T);
		size_t szbuffer = src.m_nSize * sztype;

		long nPrevSize = m_nSize;
		reSize(m_nSize + src.m_nSize);

		memcpy_s(m_aData + nPrevSize, szbuffer, src.m_aData, szbuffer);
	}

	const T& operator[](long nIndex) const
	{
		ASSERT(nIndex >= 0 && nIndex < m_nSize);
		return m_aData[nIndex];
	}

	T& operator[](long nIndex)
	{
		ASSERT(nIndex >= 0 && nIndex < m_nSize);
		return m_aData[nIndex];
	}

	void SetSize(const long nSize)
	{
		if (nSize != m_nSize)
		{
			if (m_aData) free(m_aData);
			if (nSize > 0)
			{
				m_nSize = nSize;
				m_aData = (T*)malloc(m_nSize * sizeof(T));
				memset((void*)m_aData, 0, (size_t)m_nSize * sizeof(T));
			}
			else {
				m_nSize = 0;
				m_aData = NULL;
			}
		}
	}

	void RemoveAll()
	{
		if (m_aData) {
			free(m_aData);
			m_aData = NULL;
		}
		m_nSize = 0;
	}

	BOOL IsEmpty() const
	{
		return (m_nSize == 0);
	}

	void reSize(const long nSize) // resize the array but maintain data
	{
		if (nSize != m_nSize)
		{
			size_t sztype = sizeof(T);

			// backup
			TArray<Type> arTmp;
			arTmp.SetSize(m_nSize);
			memcpy_s(arTmp.m_aData, m_nSize * sztype, m_aData, m_nSize * sztype);

			// copy
			if (m_aData) free(m_aData);
			if (nSize > 0)
			{
				m_nSize = nSize;
				m_aData = (Type*)malloc(m_nSize * sztype);

				if (m_nSize > arTmp.m_nSize)
				{
					memset((void*)m_aData, 0, (size_t)m_nSize * sztype);
					memcpy_s(m_aData, arTmp.m_nSize * sztype, arTmp.m_aData, arTmp.m_nSize * sztype);
				}
				else
				{
					memcpy_s(m_aData, m_nSize * sztype, arTmp.m_aData, m_nSize * sztype);
				}
			}
			else {
				m_nSize = 0;
				m_aData = NULL;
			}
		}
	}

	T* GetData() const { return m_aData; }

protected:
	T* m_aData;
	long m_nSize;

};

using MArrayB = MArray<BOOL>;
using MArrayub = MArray<unsigned char>;
using MArrayl = MArray<long>;
using MArrayi = MArray<int>;
using MArrayui = MArray<UINT>;
using MArrayul = MArray<ULONG>;
using MArrayf = MArray<float>;
using MArrayd = MArray<double>;
using MArrayK = MArray<MKEY>;
using MArrayITR = MArray<MITERATOR>;
using MArrayShortStr = MArray<MShortString>;
using MArrayStr = MArray<MString>;
using MArrayLongStr = MArray<MLongString>;
using MArrayColor = MArray<COLORREF>;

using MArrayVec2l = MArray<MVector2l>;
using MArrayVec2f = MArray<MVector2f>;
using MArrayVec2d = MArray<MVector2d>;

using MArrayVec3b = MArray<MVector3b>;
using MArrayVec3l = MArray<MVector3l>;
using MArrayVec3f = MArray<MVector3f>;
using MArrayVec3d = MArray<MVector3d>;
using MArrayVec3i = MArray<MVector3i>;

using MArrayVec4b = MArray<MVector4b>;
using MArrayVec4l = MArray<MVector4l>;
using MArrayVec4f = MArray<MVector4f>;
using MArrayVec4d = MArray<MVector4d>;

using MArrayMat3l = MArray<MMatrix3l>;
using MArrayMat3f = MArray<MMatrix3f>;
using MArrayMat3d = MArray<MMatrix3d>;

using MArrayMat4l = MArray<MMatrix4l>;
using MArrayMat4f = MArray<MMatrix4f>;
using MArrayMat4d = MArray<MMatrix4d>;
