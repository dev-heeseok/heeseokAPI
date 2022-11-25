#pragma once

#pragma pack(push, 4)

template <class T>
union tagMatrix3 {
	T mat[3][3];
	T _mat[9];

	void Init()
	{
		memset(mat, 0, sizeof(T) * 9);
		mat[0][0] = T(1.f);	mat[1][1] = T(1.f);	mat[2][2] = T(1.f);
	}

	template<class Type0>
	tagMatrix3<T>& operator=(const tagMatrix3<Type0>& src)
	{
		Set(src.mat);
		return *this;
	}

	template<class Type0>
	void Get(Type0 dst[3][3]) const
	{
		dst[0][0] = Type0(mat[0][0]);	dst[0][1] = Type0(mat[0][1]);	dst[0][2] = Type0(mat[0][2]);
		dst[1][0] = Type0(mat[1][0]);	dst[1][1] = Type0(mat[1][1]);	dst[1][2] = Type0(mat[1][2]);
		dst[2][0] = Type0(mat[2][0]);	dst[2][1] = Type0(mat[2][1]);	dst[2][2] = Type0(mat[2][2]);
	}

	template<class Type0>
	void Set(const Type0 src[3][3])
	{
		mat[0][0] = T(src[0][0]);	mat[0][1] = T(src[0][1]);	mat[0][2] = T(src[0][2]);
		mat[1][0] = T(src[1][0]);	mat[1][1] = T(src[1][1]);	mat[1][2] = T(src[1][2]);
		mat[2][0] = T(src[2][0]);	mat[2][1] = T(src[2][1]);	mat[2][2] = T(src[2][2]);
	}
};

using MMatrix3l = tagMatrix3<long>;
using MMatrix3f = tagMatrix3<float>;
using MMatrix3d = tagMatrix3<double>;

template <class T>
union tagMatrix4 {
	T mat[4][4];
	T _mat[16];

	void Init()
	{
		memset(mat, 0, sizeof(T) * 16);
		mat[0][0] = T(1.f);	mat[1][1] = T(1.f);	mat[2][2] = T(1.f);	mat[3][3] = T(1.f);
	}

	template<class Type0>
	tagMatrix4<T>& operator=(const tagMatrix4<Type0>& src)
	{
		Set(src.mat);
		return *this;
	}

	template<class Type0>
	void Get(Type0 dst[4][4]) const
	{
		dst[0][0] = Type0(mat[0][0]);	dst[0][1] = Type0(mat[0][1]);	dst[0][2] = Type0(mat[0][2]);	dst[0][3] = Type0(mat[0][3]);
		dst[1][0] = Type0(mat[1][0]);	dst[1][1] = Type0(mat[1][1]);	dst[1][2] = Type0(mat[1][2]);	dst[1][3] = Type0(mat[1][3]);
		dst[2][0] = Type0(mat[2][0]);	dst[2][1] = Type0(mat[2][1]);	dst[2][2] = Type0(mat[2][2]);	dst[2][3] = Type0(mat[2][3]);
		dst[3][0] = Type0(mat[3][0]);	dst[3][1] = Type0(mat[3][1]);	dst[3][2] = Type0(mat[3][2]);	dst[3][3] = Type0(mat[3][3]);
	}

	template<class Type0>
	void Set(const Type0 src[4][4])
	{
		mat[0][0] = T(src[0][0]);	mat[0][1] = T(src[0][1]);	mat[0][2] = T(src[0][2]);	mat[0][3] = T(src[0][3]);
		mat[1][0] = T(src[1][0]);	mat[1][1] = T(src[1][1]);	mat[1][2] = T(src[1][2]);	mat[1][3] = T(src[1][3]);
		mat[2][0] = T(src[2][0]);	mat[2][1] = T(src[2][1]);	mat[2][2] = T(src[2][2]);	mat[2][3] = T(src[2][3]);
		mat[3][0] = T(src[3][0]);	mat[3][1] = T(src[3][1]);	mat[3][2] = T(src[3][2]);	mat[3][3] = T(src[3][3]);
	}
};

using MMatrix4l = tagMatrix4<long>;
using MMatrix4f = tagMatrix4<float>;
using MMatrix4d = tagMatrix4<double>;

#pragma pack(pop)