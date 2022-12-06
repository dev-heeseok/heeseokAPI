#pragma once

#include "AddionalDatabase.h"

#include "MTableSpace.h"
#include "MSchema.h"
#include "MSegment.hpp"

template <typename TYPE>
class MSchemaBase : public MSchema
{
public:
	MSchemaBase(MTableSpace* pTableSpace, UINT uiType, int nHashSize)
		: MSchema(pTableSpace, uiType), m_segment(nHashSize)
	{}
	virtual ~MSchemaBase()
	{}

public:
	virtual BOOL ProcessRelation() override
	{
		return TRUE;
	}
	virtual void LazyDelete() override final
	{
		m_segment.ReleaseDel();
	}

	virtual BOOL IsEmpty() const override
	{
		return m_segment.IsEmpty();
	}
	virtual int GetSize() const override
	{
		return m_segment.GetSize();
	}
	virtual int GetKeyList(OUT std::vector<MKEY>& aKey) override
	{
		return m_segment.GetKeyList(aKey);
	}
	virtual int GetItrList(OUT std::vector<MITERATOR>& aItr) override
	{
		return m_segment.GetItrList(aItr);
	}
	virtual MITERATOR Find(MKEY key) const override
	{
		return m_segment.Find(key);
	}
	virtual MITERATOR InsertNU(MBlock* pData) override
	{
		return InsertNU(*(TYPE*)pData);
	}
	virtual BOOL SetAtNU(MITERATOR itr, MBlock* pData) override
	{
		return SetAtNU(itr, *(TYPE*)pData);
	}

protected:
	MITERATOR InsertNU(const TYPE& data)
	{
		MITERATOR itr = m_segment.InsertNU(data);

		if (IS_VALID(itr))
		{
			if (m_pTableSpace && m_pTableSpace->IsTR())
			{
				m_uiFlag |= static_cast<UINT>(SchemaFlag::kADDED);
				m_pTableSpace->PushNotify(tagNotification(
					{ m_uiType, static_cast<UINT>(NAction::kAdd), itr, NULL }
				));
			}
		}

		return itr;
	}
	BOOL SetAtNU(MITERATOR itr, const TYPE& data)
	{
		return m_segment.SetAtNU(itr, data);
	}
	BOOL Remove(MITERATOR itr)
	{
		BOOL bRemove = FALSE;

		if (m_pTableSpace && m_pTableSpace->IsTR())
		{
			MITERATOR itrDel = itr;
			bRemove = m_segment.RemoveWithoutDelete(itr);

			if (bRemove)
			{
				m_segment.PushDel(itrDel);
				m_uiFlag |= static_cast<UINT>(SchemaFlag::kDELETED);
				m_pTableSpace->PushNotify(tagNotification(
					{ m_uiType, static_cast<UINT>(NAction::kDel), itr, NULL }
				));
			}
		}
		else
		{
			bRemove = m_segment.Remove(itr);
		}

		return bRemove;
	}
	BOOL RemoveNext(OUT MITERATOR& itr)
	{
		BOOL bRemove = FALSE;

		if (m_pTableSpace && m_pTableSpace->IsTR())
		{
			MITERATOR itrDel = itr;
			bRemove = m_segment.RemoveNextWithoutDelete(itr);

			if (bRemove)
			{
				m_segment.PushDel(itrDel);
				m_uiFlag |= static_cast<UINT>(SchemaFlag::kDELETED);
				m_pTableSpace->PushNotify(tagNotification(
					{ m_uiType, static_cast<UINT>(NAction::kDel), itr, NULL }
				));
			}
		}
		else
		{
			bRemove = m_segment.Remove(itr);
		}

		return bRemove;
	}
	void ResizeHash(int nHashSize)
	{
		m_segment.ResizeHash(nHashSize);
	}
	MKEY NewKey()
	{
		return m_segment.NewKey();
	}

protected:
	MSegment<TYPE> m_segment;

};