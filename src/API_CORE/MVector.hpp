#pragma once

#pragma pack(push, 4)

template <typename T>
struct tagVector2
{
	T vec[2];

	tagVector2<T>(const T& v0 = 0, const T& v1 = 0)
	{
		vec[0] = v0;
		vec[1] = v1;
	}
	tagVector2<T>(const T v[2])
	{
		vec[0] = v[0];
		vec[1] = v[1];
	}
	tagVector2<T>& operator=(const tagVector2<T>& src)
	{
		vec[0] = src.vec[0];
		vec[1] = src.vec[1];
		return *this;
	}
	tagVector2<T>& operator+=(const tagVector2<T>& src)
	{
		vec[0] += src.vec[0];
		vec[1] += src.vec[1];
		return *this;
	}
	tagVector2<T>& operator-=(const tagVector2<T>& src)
	{
		vec[0] -= src.vec[0];
		vec[1] -= src.vec[1];
		return *this;
	}
	tagVector2<T> operator+(const tagVector2<T>& src) const
	{
		tagVector2<T> tmp = *this;
		tmp += src;
		return tmp;
	}

	tagVector2<T> operator-(const tagVector2<T>& src) const
	{
		tagVector2<T> tmp = *this;
		tmp -= src;
		return tmp;
	}
	void Set(const T& src)
	{
		vec[0] = src;
		vec[1] = src;
	}
};

using MVector2b = tagVector2<BYTE>;
using MVector2l = tagVector2<long>;
using MVector2i = tagVector2<int>;
using MVector2f = tagVector2<float>;
using MVector2d = tagVector2<double>;

template <typename T>
struct tagVector3
{
	T vec[3];

	tagVector3<T>(const T& v0 = 0, const T& v1 = 0, const T& v2 = 0)
	{
		vec[0] = v0;
		vec[1] = v1;
		vec[2] = v2;
	}

	tagVector3<T>(const T v[3])
	{
		vec[0] = v[0];
		vec[1] = v[1];
		vec[2] = v[2];
	}

	template<class Type0>
	tagVector3<T>& operator=(const tagVector3<Type0>& src)
	{
		vec[0] = T(src.vec[0]);
		vec[1] = T(src.vec[1]);
		vec[2] = T(src.vec[2]);
		return *this;
	}

	template<class Type0>
	tagVector3<T>& operator+=(const tagVector3<Type0>& src)
	{
		vec[0] += T(src.vec[0]);
		vec[1] += T(src.vec[1]);
		vec[2] += T(src.vec[2]);
		return *this;
	}

	template<class Type0>
	tagVector3<T>& operator-=(const tagVector3<Type0>& src)
	{
		vec[0] -= T(src.vec[0]);
		vec[1] -= T(src.vec[1]);
		vec[2] -= T(src.vec[2]);
		return *this;
	}

	template<class Type>
	tagVector3<T>& operator*=(const Type& src)
	{
		vec[0] *= src;
		vec[1] *= src;
		vec[2] *= src;
		return *this;
	}

	template<class Type0>
	tagVector3<T> operator+(const tagVector3<Type0>& src) const
	{
		tagVector3<T> tmp = *this;
		tmp += src;
		return tmp;
	}

	template<class Type0>
	tagVector3<T> operator-(const tagVector3<Type0>& src) const
	{
		tagVector3<T> tmp = *this;
		tmp -= src;
		return tmp;
	}

	void Set(const T& src)
	{
		vec[0] = src;
		vec[1] = src;
		vec[2] = src;
	}

	T Distance() const
	{
		T dist = 0;
		for (int i = 0; i < 3; i++)
		{
			dist += (vec[i] * vec[i]);
		}
		return sqrt(dist);
	}

	T Normalize()
	{
		T dist = Distance();
		if (fabs(dist) < 1.0e-12)
			return 0;

		for (int i = 0; i < 3; i++)
			vec[i] /= dist;

		return dist;
	}

	T Dot(const tagVector3<T>& src)
	{
		T dotProd = 0;
		for (int i = 0; i < 3; i++)
			dotProd += vec[i] * src.vec[i];

		return dotProd;
	}

	void Inverse()
	{
		for (int i = 0; i < 3; ++i)
		{
			this->vec[i] = -this->vec[i];
		}
	}
};

using MVector3b = tagVector3<BYTE>;
using MVector3l = tagVector3<long>;
using MVector3i = tagVector3<int>;
using MVector3f = tagVector3<float>;
using MVector3d = tagVector3<double>;

template <typename T>
struct tagVector4
{
	T vec[4];

	tagVector4<T>(const T& v0 = 0, const T& v1 = 0, const T& v2 = 0, const T& v3 = 0)
	{
		vec[0] = v0;
		vec[1] = v1;
		vec[2] = v2;
		vec[3] = v3;
	}
	tagVector4<T>(const T v[4])
	{
		vec[0] = v[0];
		vec[1] = v[1];
		vec[2] = v[2];
		vec[3] = v[3];
	}
	tagVector4<T>& operator=(const tagVector4<T>& src)
	{
		vec[0] = src.vec[0];
		vec[1] = src.vec[1];
		vec[2] = src.vec[2];
		vec[3] = src.vec[3];
		return *this;
	}
	tagVector4<T>& operator+=(const tagVector4<T>& src)
	{
		vec[0] += src.vec[0];
		vec[1] += src.vec[1];
		vec[2] += src.vec[2];
		vec[3] += src.vec[3];
		return *this;
	}

	void Set(const T& src)
	{
		vec[0] = src;
		vec[1] = src;
		vec[2] = src;
		vec[3] = src;
	}
};

using MVector4b = tagVector4<BYTE>;
using MVector4l = tagVector4<long>;
using MVector4i = tagVector4<int>;
using MVector4f = tagVector4<float>;
using MVector4d = tagVector4<double>;

#pragma pack(pop)