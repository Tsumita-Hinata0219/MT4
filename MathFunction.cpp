#include "MathFunction.h"



// 表示
void VectorScreenPrintf(int x, int y, const Vector3 vector, const char* label) {

	Novice::ScreenPrintf(x + kColumnWidth * 0, y, "%6.02f", vector.x);
	Novice::ScreenPrintf(x + kColumnWidth * 1, y, "%6.02f", vector.y);
	Novice::ScreenPrintf(x + kColumnWidth * 2, y, "%6.02f", vector.z);

	Novice::ScreenPrintf(x + kColumnWidth * 4, y, "%s", label);
}
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label)
{
	for (int row = 0; row < 4; ++row) {
		for (int column = 0; column < 4; ++column) {
			Novice::ScreenPrintf(x, y, "%s\n", label);
			Novice::ScreenPrintf(
				x + column * kColumnWidth, y + (row + 1) * kRowHeight, "%.3f", matrix.m[row][column]);
		}
	}
}



// 3次元ベクトル
namespace vector {

	// 加算
	Vector3 Add(const Vector3 v1, const Vector3 v2) {
		Vector3 result{};
		result.x = v1.x + v2.x;
		result.y = v1.y + v2.y;
		result.z = v1.z + v2.z;

		return result;
	}


	// 減算
	Vector3 Subtract(const Vector3 v1, const Vector3 v2) {
		Vector3 result{};
		result.x = v1.x - v2.x;
		result.y = v1.y - v2.y;
		result.z = v1.z - v2.z;
		return result;
	}


	// 乗算
	Vector3 Multiply(float scalar, const Vector3 v) {
		Vector3 result{};
		result.x = scalar * v.x;
		result.y = scalar * v.y;
		result.z = scalar * v.z;
		return result;
	}
}


// 内積
float Dot(const Vector3 v1, const Vector3 v2) {
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}


// 長さ
float Length(const Vector3 v) {
	float result;
	result = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	return result;
}


// 正規化
Vector3 Normalize(const Vector3 v) {
	Vector3 result{};
	float length = Length(v);
	result.x = v.x;
	result.y = v.y;
	result.z = v.z;

	if (length != 0.0f) {
		result.x = v.x / length;
		result.y = v.y / length;
		result.z = v.z / length;
	}

	return result;
}



// 行列
namespace matrix {

	// 加算
	Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2) {
		Matrix4x4 result{};

		result.m[0][0] = m1.m[0][0] + m2.m[0][0];
		result.m[0][1] = m1.m[0][1] + m2.m[0][1];
		result.m[0][2] = m1.m[0][2] + m2.m[0][2];
		result.m[0][3] = m1.m[0][3] + m2.m[0][3];

		result.m[1][0] = m1.m[1][0] + m2.m[1][0];
		result.m[1][1] = m1.m[1][1] + m2.m[1][1];
		result.m[1][2] = m1.m[1][2] + m2.m[1][2];
		result.m[1][3] = m1.m[1][3] + m2.m[1][3];

		result.m[2][0] = m1.m[2][0] + m2.m[2][0];
		result.m[2][1] = m1.m[2][1] + m2.m[2][1];
		result.m[2][2] = m1.m[2][2] + m2.m[2][2];
		result.m[2][3] = m1.m[2][3] + m2.m[2][3];

		result.m[3][0] = m1.m[3][0] + m2.m[3][0];
		result.m[3][1] = m1.m[3][1] + m2.m[3][1];
		result.m[3][2] = m1.m[3][2] + m2.m[3][2];
		result.m[3][3] = m1.m[3][3] + m2.m[3][3];

		return result;
	}


	// 減算
	Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2) {
		Matrix4x4 result{};

		result.m[0][0] = m1.m[0][0] - m2.m[0][0];
		result.m[0][1] = m1.m[0][1] - m2.m[0][1];
		result.m[0][2] = m1.m[0][2] - m2.m[0][2];
		result.m[0][3] = m1.m[0][3] - m2.m[0][3];

		result.m[1][0] = m1.m[1][0] - m2.m[1][0];
		result.m[1][1] = m1.m[1][1] - m2.m[1][1];
		result.m[1][2] = m1.m[1][2] - m2.m[1][2];
		result.m[1][3] = m1.m[1][3] - m2.m[1][3];

		result.m[2][0] = m1.m[2][0] - m2.m[2][0];
		result.m[2][1] = m1.m[2][1] - m2.m[2][1];
		result.m[2][2] = m1.m[2][2] - m2.m[2][2];
		result.m[2][3] = m1.m[2][3] - m2.m[2][3];

		result.m[3][0] = m1.m[3][0] - m2.m[3][0];
		result.m[3][1] = m1.m[3][1] - m2.m[3][1];
		result.m[3][2] = m1.m[3][2] - m2.m[3][2];
		result.m[3][3] = m1.m[3][3] - m2.m[3][3];

		return result;
	}


	// 乗算
	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
		Matrix4x4 result{};

		result.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] +
			m1.m[0][2] * m2.m[2][0] + m1.m[0][3] * m2.m[3][0];

		result.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] +
			m1.m[0][2] * m2.m[2][1] + m1.m[0][3] * m2.m[3][1];

		result.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] +
			m1.m[0][2] * m2.m[2][2] + m1.m[0][3] * m2.m[3][2];

		result.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] +
			m1.m[0][2] * m2.m[2][3] + m1.m[0][3] * m2.m[3][3];


		result.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] +
			m1.m[1][2] * m2.m[2][0] + m1.m[1][3] * m2.m[3][0];

		result.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] +
			m1.m[1][2] * m2.m[2][1] + m1.m[1][3] * m2.m[3][1];

		result.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] +
			m1.m[1][2] * m2.m[2][2] + m1.m[1][3] * m2.m[3][2];

		result.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] +
			m1.m[1][2] * m2.m[2][3] + m1.m[1][3] * m2.m[3][3];


		result.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] +
			m1.m[2][2] * m2.m[2][0] + m1.m[2][3] * m2.m[3][0];

		result.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] +
			m1.m[2][2] * m2.m[2][1] + m1.m[2][3] * m2.m[3][1];

		result.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] +
			m1.m[2][2] * m2.m[2][2] + m1.m[2][3] * m2.m[3][2];

		result.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] +
			m1.m[2][2] * m2.m[2][3] + m1.m[2][3] * m2.m[3][3];


		result.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] +
			m1.m[3][2] * m2.m[2][0] + m1.m[3][3] * m2.m[3][0];

		result.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] +
			m1.m[3][2] * m2.m[2][1] + m1.m[3][3] * m2.m[3][1];

		result.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] +
			m1.m[3][2] * m2.m[2][2] + m1.m[3][3] * m2.m[3][2];

		result.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] +
			m1.m[3][2] * m2.m[2][3] + m1.m[3][3] * m2.m[3][3];


		return result;
	}
}


// 逆行列
Matrix4x4 Inverse(const Matrix4x4& m) {
	Matrix4x4 result{};

	float as =
		m.m[0][0] * m.m[1][1] * m.m[2][2] * m.m[3][3] +
		m.m[0][0] * m.m[1][2] * m.m[2][3] * m.m[3][1] +
		m.m[0][0] * m.m[1][3] * m.m[2][1] * m.m[3][2] -

		m.m[0][0] * m.m[1][3] * m.m[2][2] * m.m[3][1] -
		m.m[0][0] * m.m[1][2] * m.m[2][1] * m.m[3][3] -
		m.m[0][0] * m.m[1][1] * m.m[2][3] * m.m[3][2] -

		m.m[0][1] * m.m[1][0] * m.m[2][2] * m.m[3][3] -
		m.m[0][2] * m.m[1][0] * m.m[2][3] * m.m[3][1] -
		m.m[0][3] * m.m[1][0] * m.m[2][1] * m.m[3][2] +

		m.m[0][3] * m.m[1][0] * m.m[2][2] * m.m[3][1] +
		m.m[0][2] * m.m[1][0] * m.m[2][1] * m.m[3][3] +
		m.m[0][1] * m.m[1][0] * m.m[2][3] * m.m[3][2] +

		m.m[0][1] * m.m[1][2] * m.m[2][0] * m.m[3][3] +
		m.m[0][2] * m.m[1][3] * m.m[2][0] * m.m[3][1] +
		m.m[0][3] * m.m[1][1] * m.m[2][0] * m.m[3][2] -

		m.m[0][3] * m.m[1][2] * m.m[2][0] * m.m[3][1] -
		m.m[0][2] * m.m[1][1] * m.m[2][0] * m.m[3][3] -
		m.m[0][1] * m.m[1][3] * m.m[2][0] * m.m[3][2] -

		m.m[0][1] * m.m[1][2] * m.m[2][3] * m.m[3][0] -
		m.m[0][2] * m.m[1][3] * m.m[2][1] * m.m[3][0] -
		m.m[0][3] * m.m[1][1] * m.m[2][2] * m.m[3][0] +

		m.m[0][3] * m.m[1][2] * m.m[2][1] * m.m[3][0] +
		m.m[0][2] * m.m[1][1] * m.m[2][3] * m.m[3][0] +
		m.m[0][1] * m.m[1][3] * m.m[2][2] * m.m[3][0];

	assert(as != 0.0f);
	float determinantRecp = 1.0f / as;

	// 一行目
	result.m[0][0] = (m.m[1][1] * m.m[2][2] * m.m[3][3] + m.m[1][2] * m.m[2][3] * m.m[3][1] +
		m.m[1][3] * m.m[2][1] * m.m[3][2] - m.m[1][3] * m.m[2][2] * m.m[3][1] -
		m.m[1][2] * m.m[2][1] * m.m[3][3] - m.m[1][1] * m.m[2][3] * m.m[3][2]) *
		determinantRecp;

	result.m[0][1] = (-m.m[0][1] * m.m[2][2] * m.m[3][3] - m.m[0][2] * m.m[2][3] * m.m[3][1] -
		m.m[0][3] * m.m[2][1] * m.m[3][2] + m.m[0][3] * m.m[2][2] * m.m[3][1] +
		m.m[0][2] * m.m[2][1] * m.m[3][3] + m.m[0][1] * m.m[2][3] * m.m[3][2]) *
		determinantRecp;

	result.m[0][2] = (
		m.m[0][1] * m.m[1][2] * m.m[3][3] + m.m[0][2] * m.m[1][3] * m.m[3][1] +
		m.m[0][3] * m.m[1][1] * m.m[3][2] - m.m[0][3] * m.m[1][2] * m.m[3][1] -
		m.m[0][2] * m.m[1][1] * m.m[3][3] - m.m[0][1] * m.m[1][3] * m.m[3][2]) *
		determinantRecp;

	result.m[0][3] = (-m.m[0][1] * m.m[1][2] * m.m[2][3] - m.m[0][2] * m.m[1][3] * m.m[2][1] -
		m.m[0][3] * m.m[1][1] * m.m[2][2] + m.m[0][3] * m.m[1][2] * m.m[2][1] +
		m.m[0][2] * m.m[1][1] * m.m[2][3] + m.m[0][1] * m.m[1][3] * m.m[2][2]) *
		determinantRecp;


	// 二行目
	result.m[1][0] = (-m.m[1][0] * m.m[2][2] * m.m[3][3] - m.m[1][2] * m.m[2][3] * m.m[3][0] -
		m.m[1][3] * m.m[2][0] * m.m[3][2] + m.m[1][3] * m.m[2][2] * m.m[3][0] +
		m.m[1][2] * m.m[2][0] * m.m[3][3] + m.m[1][0] * m.m[2][3] * m.m[3][2]) *
		determinantRecp;

	result.m[1][1] = (
		m.m[0][0] * m.m[2][2] * m.m[3][3] + m.m[0][2] * m.m[2][3] * m.m[3][0] +
		m.m[0][3] * m.m[2][0] * m.m[3][2] - m.m[0][3] * m.m[2][2] * m.m[3][0] -
		m.m[0][2] * m.m[2][0] * m.m[3][3] - m.m[0][0] * m.m[2][3] * m.m[3][2]) *
		determinantRecp;

	result.m[1][2] = (-m.m[0][0] * m.m[1][2] * m.m[3][3] - m.m[0][2] * m.m[1][3] * m.m[3][0] -
		m.m[0][3] * m.m[1][0] * m.m[3][2] + m.m[0][3] * m.m[1][2] * m.m[3][0] +
		m.m[0][2] * m.m[1][0] * m.m[3][3] + m.m[0][0] * m.m[1][3] * m.m[3][2]) *
		determinantRecp;

	result.m[1][3] = (
		m.m[0][0] * m.m[1][2] * m.m[2][3] + m.m[0][2] * m.m[1][3] * m.m[2][0] +
		m.m[0][3] * m.m[1][0] * m.m[2][2] - m.m[0][3] * m.m[1][2] * m.m[2][0] -
		m.m[0][2] * m.m[1][0] * m.m[2][3] - m.m[0][0] * m.m[1][3] * m.m[2][2]) *
		determinantRecp;


	// 三行目
	result.m[2][0] = (
		m.m[1][0] * m.m[2][1] * m.m[3][3] + m.m[1][1] * m.m[2][3] * m.m[3][0] +
		m.m[1][3] * m.m[2][0] * m.m[3][1] - m.m[1][3] * m.m[2][1] * m.m[3][0] -
		m.m[1][1] * m.m[2][0] * m.m[3][3] - m.m[1][0] * m.m[2][3] * m.m[3][1]) *
		determinantRecp;

	result.m[2][1] = (-m.m[0][0] * m.m[2][1] * m.m[3][3] - m.m[0][1] * m.m[2][3] * m.m[3][0] -
		m.m[0][3] * m.m[2][0] * m.m[3][1] + m.m[0][3] * m.m[2][1] * m.m[3][0] +
		m.m[0][1] * m.m[2][0] * m.m[3][3] + m.m[0][0] * m.m[2][3] * m.m[3][1]) *
		determinantRecp;

	result.m[2][2] = (
		m.m[0][0] * m.m[1][1] * m.m[3][3] + m.m[0][1] * m.m[1][3] * m.m[3][0] +
		m.m[0][3] * m.m[1][0] * m.m[3][1] - m.m[0][3] * m.m[1][1] * m.m[3][0] -
		m.m[0][1] * m.m[1][0] * m.m[3][3] - m.m[0][0] * m.m[1][3] * m.m[3][1]) *
		determinantRecp;

	result.m[2][3] = (-m.m[0][0] * m.m[1][1] * m.m[2][3] - m.m[0][1] * m.m[1][3] * m.m[2][0] -
		m.m[0][3] * m.m[1][0] * m.m[2][1] + m.m[0][3] * m.m[1][1] * m.m[2][0] +
		m.m[0][1] * m.m[1][0] * m.m[2][3] + m.m[0][0] * m.m[1][3] * m.m[2][1]) *
		determinantRecp;


	// 四行目
	result.m[3][0] = (-m.m[1][0] * m.m[2][1] * m.m[3][2] - m.m[1][1] * m.m[2][2] * m.m[3][0] -
		m.m[1][2] * m.m[2][0] * m.m[3][1] + m.m[1][2] * m.m[2][1] * m.m[3][0] +
		m.m[1][1] * m.m[2][0] * m.m[3][2] + m.m[1][0] * m.m[2][2] * m.m[3][1]) *
		determinantRecp;

	result.m[3][1] = (

		m.m[0][0] * m.m[2][1] * m.m[3][2] + m.m[0][1] * m.m[2][2] * m.m[3][0] +
		m.m[0][2] * m.m[2][0] * m.m[3][1] - m.m[0][2] * m.m[2][1] * m.m[3][0] -
		m.m[0][1] * m.m[2][0] * m.m[3][2] - m.m[0][0] * m.m[2][2] * m.m[3][1]) *
		determinantRecp;

	result.m[3][2] = (-m.m[0][0] * m.m[1][1] * m.m[3][2] - m.m[0][1] * m.m[1][2] * m.m[3][0] -
		m.m[0][2] * m.m[1][0] * m.m[3][1] + m.m[0][2] * m.m[1][1] * m.m[3][0] +
		m.m[0][1] * m.m[1][0] * m.m[3][2] + m.m[0][0] * m.m[1][2] * m.m[3][1]) *
		determinantRecp;

	result.m[3][3] = (

		m.m[0][0] * m.m[1][1] * m.m[2][2] + m.m[0][1] * m.m[1][2] * m.m[2][0] +
		m.m[0][2] * m.m[1][0] * m.m[2][1] - m.m[0][2] * m.m[1][1] * m.m[2][0] -
		m.m[0][1] * m.m[1][0] * m.m[2][2] - m.m[0][0] * m.m[1][2] * m.m[2][1]) *
		determinantRecp;

	return result;
}


// 転置行列
Matrix4x4 Transpose(const Matrix4x4& m) {
	Matrix4x4 result{};

	result.m[0][0] = m.m[0][0];
	result.m[0][1] = m.m[1][0];
	result.m[0][2] = m.m[2][0];
	result.m[0][3] = m.m[3][0];

	result.m[1][0] = m.m[0][1];
	result.m[1][1] = m.m[1][1];
	result.m[1][2] = m.m[2][1];
	result.m[1][3] = m.m[3][1];

	result.m[2][0] = m.m[0][2];
	result.m[2][1] = m.m[1][2];
	result.m[2][2] = m.m[2][2];
	result.m[2][3] = m.m[3][2];

	result.m[3][0] = m.m[0][3];
	result.m[3][1] = m.m[1][3];
	result.m[3][2] = m.m[2][3];
	result.m[3][3] = m.m[3][3];

	return result;
}


// 単位行列の作成
Matrix4x4 MakeIdentity4x4() {
	Matrix4x4 result{};

	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;
	result.m[2][3] = 0.0f;

	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;

	return result;
}


// 座標変換
Vector3 TransformByMatrix(const Vector3 vector, const Matrix4x4 matrix)
{
	Vector3 result{};

	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z *
		matrix.m[2][0] + 1.0f * matrix.m[3][0];

	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z *
		matrix.m[2][1] + 1.0f * matrix.m[3][1];

	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z *
		matrix.m[2][2] + 1.0f * matrix.m[3][2];

	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z *
		matrix.m[2][3] + 1.0f * matrix.m[3][3];

	assert(w != 0.0f);

	result.x /= w;
	result.y /= w;
	result.z /= w;

	return  result;
}


// 拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3 scale) {
	Matrix4x4 result{};

	result.m[0][0] = scale.x;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = scale.y;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = scale.z;
	result.m[2][3] = 0.0f;

	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = 0.0f;
	result.m[3][3] = 1.0f;


	return result;
}


// X軸回転行列
Matrix4x4 MakeRotateXMatrix(float radian) {
	Matrix4x4 result{};

	result.m[0][0] = 1;
	result.m[0][1] = 0;
	result.m[0][2] = 0;
	result.m[0][3] = 0;

	result.m[1][0] = 0;
	result.m[1][1] = std::cos(radian);
	result.m[1][2] = std::sin(radian);
	result.m[1][3] = 0;

	result.m[2][0] = 0;
	result.m[2][1] = -std::sin(radian);
	result.m[2][2] = std::cos(radian);
	result.m[2][3] = 0;

	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;

	return result;
}


// Y軸回転行列
Matrix4x4 MakeRotateYMatrix(float radian) {
	Matrix4x4 result{};

	result.m[0][0] = std::cos(radian);
	result.m[0][1] = 0;
	result.m[0][2] = -std::sin(radian);
	result.m[0][3] = 0;

	result.m[1][0] = 0;
	result.m[1][1] = 1;
	result.m[1][2] = 0;
	result.m[1][3] = 0;

	result.m[2][0] = std::sin(radian);
	result.m[2][1] = 0;
	result.m[2][2] = std::cos(radian);
	result.m[2][3] = 0;

	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;

	return result;

}


// Z軸回転行列
Matrix4x4 MakeRotateZMatrix(float radian) {
	Matrix4x4 result{};

	result.m[0][0] = std::cos(radian);
	result.m[0][1] = std::sin(radian);
	result.m[0][2] = 0;
	result.m[0][3] = 0;

	result.m[1][0] = -std::sin(radian);
	result.m[1][1] = std::cos(radian);
	result.m[1][2] = 0;
	result.m[1][3] = 0;

	result.m[2][0] = 0;
	result.m[2][1] = 0;
	result.m[2][2] = 1;
	result.m[2][3] = 0;

	result.m[3][0] = 0;
	result.m[3][1] = 0;
	result.m[3][2] = 0;
	result.m[3][3] = 1;

	return result;

}


// Rotate(all)
Matrix4x4 MakeRotateXYZMatrix(float radianX, float radianY, float radianZ) {
	Matrix4x4 result{};

	Matrix4x4 rotateXMatrix = MakeRotateXMatrix(radianX);
	Matrix4x4 rotateYMatrix = MakeRotateYMatrix(radianY);
	Matrix4x4 rotateZMatrix = MakeRotateZMatrix(radianZ);

	result = matrix::Multiply(rotateXMatrix, matrix::Multiply(rotateYMatrix, rotateZMatrix));

	return result;
}


// 任意軸回転行列
Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle) {

	float cosTheta = cosf(angle);
	float sinTheta = sinf(angle);

	Matrix4x4 result{};
	result = MakeIdentity4x4();


	//result.m[0][0] = (axis.x * axis.x) * (1 - cosTheta) + cosTheta;
	//result.m[0][1] = (axis.x * axis.y) * (1 - cosTheta) - axis.z * sinTheta;
	//result.m[0][2] = (axis.x * axis.z) * (1 - cosTheta) + axis.y * sinTheta;
	//result.m[1][0] = (axis.x * axis.y) * (1 - cosTheta) + axis.z * sinTheta;
	//result.m[1][1] = (axis.y * axis.y) * (1 - cosTheta) + cosTheta;
	//result.m[1][2] = (axis.y * axis.z) * (1 - cosTheta) - axis.x * sinTheta;
	//result.m[2][0] = (axis.x * axis.z) * (1 - cosTheta) - axis.y * sinTheta;
	//result.m[2][1] = (axis.y * axis.z) * (1 - cosTheta) + axis.x * sinTheta;
	//result.m[2][2] = (axis.z * axis.z) * (1 - cosTheta) + cosTheta;


	result.m[0][0] = (axis.x * axis.x) * (1 - cosTheta) + cosTheta;
	result.m[0][1] = (axis.x * axis.y) * (1 - cosTheta) + axis.z * sinTheta;
	result.m[0][2] = (axis.x * axis.z) * (1 - cosTheta) - axis.y * sinTheta;

	result.m[1][0] = (axis.x * axis.y) * (1 - cosTheta) - axis.z * sinTheta;
	result.m[1][1] = (axis.y * axis.y) * (1 - cosTheta) + cosTheta;
	result.m[1][2] = (axis.y * axis.z) * (1 - cosTheta) + axis.x * sinTheta;

	result.m[2][0] = (axis.x * axis.z) * (1 - cosTheta) + axis.y * sinTheta;
	result.m[2][1] = (axis.y * axis.z) * (1 - cosTheta) - axis.x * sinTheta;
	result.m[2][2] = (axis.z * axis.z) * (1 - cosTheta) + cosTheta;


	return result;
}


// 平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3 translate) {
	Matrix4x4 result{};

	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;
	result.m[2][3] = 0.0f;

	result.m[3][0] = translate.x;
	result.m[3][1] = translate.y;
	result.m[3][2] = translate.z;
	result.m[3][3] = 1.0f;


	return result;
}


// 3次元アフィン変換行列 (W = SRT)
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {
	Matrix4x4 result{};

	// 拡大縮小行列
	Matrix4x4 scaleMatrix;
	scaleMatrix = MakeScaleMatrix(scale);

	// 回転行列(all)
	Matrix4x4 rotateMatrix;
	rotateMatrix = MakeRotateXYZMatrix(rotate.x, rotate.y, rotate.z);

	// 平行移動行列
	Matrix4x4 translateMatrix;
	translateMatrix = MakeTranslateMatrix(translate);

	result = matrix::Multiply(scaleMatrix, matrix::Multiply(rotateMatrix, translateMatrix));

	return result;
}


// 透視投影行列
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspecrRatio, float nearClip, float farClip) {
	Matrix4x4 result{};

	result.m[0][0] = (1 / aspecrRatio) * 1 / std::tan(fovY / 2);
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = 1 / std::tan(fovY / 2);
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = farClip / (farClip - nearClip);
	result.m[2][3] = 1.0f;

	result.m[3][0] = 0.0f;
	result.m[3][1] = 0.0f;
	result.m[3][2] = -nearClip * farClip / (farClip - nearClip);
	result.m[3][3] = 0.0f;

	return result;
}


// 正射影行列
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip) {

	assert(left != right);
	assert(top != bottom);

	Matrix4x4 result{};

	result.m[0][0] = 2 / (right - left);
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = 2 / (top - bottom);
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1 / (farClip - nearClip);
	result.m[2][3] = 0.0f;

	result.m[3][0] = (left + right) / (left - right);
	result.m[3][1] = (top + bottom) / (bottom - top);
	result.m[3][2] = nearClip / (nearClip - farClip);
	result.m[3][3] = 1.0f;

	return result;
}


// ビューポート変換行列
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth) {
	Matrix4x4 result{};

	result.m[0][0] = width / 2;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;
	result.m[0][3] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = -height / 2;
	result.m[1][2] = 0.0f;
	result.m[1][3] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = maxDepth - minDepth;
	result.m[2][3] = 0.0f;

	result.m[3][0] = left + (width / 2);
	result.m[3][1] = top + (height / 2);
	result.m[3][2] = minDepth;
	result.m[3][3] = 1.0f;

	return result;
}


// クロス積
Vector3 Cross(const Vector3& v1, const Vector3& v2) {

	Vector3 result = {
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
	};

	return result;
}


// 正射影ベクトル
Vector3 Project(const Vector3 v1, const Vector3 v2) {
	Vector3 result;
	result = vector::Multiply(Dot(v1, Normalize(v2)), Normalize(v2));
	return result;
}


// 最近接点
Vector3 ClosestPoint(const Vector3 point, const Segment segment) {
	Vector3 result{};

	float length = sqrt(segment.diff.x * segment.diff.x + segment.diff.y * segment.diff.y + segment.diff.z * segment.diff.z);
	Vector3 normaliseSegment = { segment.diff.x / length,segment.diff.y / length,segment.diff.z / length };

	float distance = Dot(vector::Subtract(point, segment.origin), normaliseSegment);
	distance = std::clamp(distance, 0.0f, length);
	Vector3 proj = vector::Multiply(distance, normaliseSegment);

	result = vector::Add(segment.origin, proj);

	return result;
}


// 
Vector3 Perpendicular(const Vector3& vector)
{
	if (vector.x != 0.0f || vector.y != 0.0f) {
		return { -vector.y,vector.x,0.0f };
	}
	return { 0.0f,-vector.z,vector.y };
}


// OBBのワールドマトリックス作成
Matrix4x4 CreateOBBWorldMatrix(const OBB& obb) {

	Matrix4x4 worldMatrix{};

	for (int i = 0; i < 3; ++i) {
		worldMatrix.m[i][0] = obb.orientations[i].x;
		worldMatrix.m[i][1] = obb.orientations[i].y;
		worldMatrix.m[i][2] = obb.orientations[i].z;
		worldMatrix.m[i][3] = 0.0f;
	}

	worldMatrix.m[3][0] = obb.center.x;
	worldMatrix.m[3][1] = obb.center.y;
	worldMatrix.m[3][2] = obb.center.z;
	worldMatrix.m[3][3] = 1.0f;


	return worldMatrix;
}


// 射影の重複チェック
bool TestAxis(const Vector3& axis, const OBB& obb1, const OBB& obb2) {

	// OBBの射影を計算
	auto projection1 = obbProjection(obb1, axis);
	auto projection2 = obbProjection(obb2, axis);

	// 射影が重なっているかチェック
	return projectionOverlap(projection1, projection2);
}


// 頂点を軸に射影
std::pair<float, float> obbProjection(const OBB& obb, const Vector3& axis) {

	float val = std::sqrt(axis.x * axis.x + axis.y * axis.y + axis.z * axis.z); // 正規化
	float newAxis = 0.0f;
	newAxis = newAxis / val;

	// OBB上の頂点を取得
	std::array<Vector3, 8> vertices{};
	for (int i = 0; i < 8; ++i) {
		Vector3 sign = { (i & 1) ? 1.0f : -1.0f, (i & 2) ? 1.0f : -1.0f, (i & 4) ? 1.0f : -1.0f };
		vertices[i] = {
			obb.center.x + obb.orientations[0].x * sign.x * obb.size.x +
						  obb.orientations[1].x * sign.y * obb.size.y +
						  obb.orientations[2].x * sign.z * obb.size.z,
			obb.center.y + obb.orientations[0].y * sign.x * obb.size.x +
						  obb.orientations[1].y * sign.y * obb.size.y +
						  obb.orientations[2].y * sign.z * obb.size.z,
			obb.center.z + obb.orientations[0].z * sign.x * obb.size.x +
						  obb.orientations[1].z * sign.y * obb.size.y +
						  obb.orientations[2].z * sign.z * obb.size.z
		};
	}

	// 頂点を軸に射影
	std::array<float, 8> projections{};
	for (int i = 0; i < 8; ++i) {
		projections[i] = vertices[i].x * axis.x + vertices[i].y * axis.y + vertices[i].z * axis.z;
	}

	auto minmax = std::minmax_element(projections.begin(), projections.end());
	return std::make_pair(*minmax.first, *minmax.second);
}


// 実際に重なってるかの計算
bool projectionOverlap(const std::pair<float, float>& projection1, const std::pair<float, float>& projection2) {

	// 射影が重なっているかチェック
	return projection1.second >= projection2.first && projection2.second >= projection1.first;
}


// グリッドの描画
void DrawGrid(const Matrix4x4& viewMatrix, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix) {
	//Gridの半分の幅
	const float gridHalfWidth = 1.0f;

	//分割数
	const uint32_t subDivision = 10;

	//一つ分の長さ
	const float gridEvery = (gridHalfWidth * 2.0f) / float(subDivision);


	//縦
	Vector3 LocalVerticesStartColumn[11]{};
	Vector3 LocalVerticesEndColumn[11]{};
	Matrix4x4 WorldMatrixStartColumn[11]{};
	Matrix4x4 WorldMatrixEndColumn[11]{};
	Vector3 ScreenVerticesColumn{};
	Vector3 ndcVerticesStartColumn{};
	Vector3 ndcVerticesEndColumn{};
	Vector3 screenVerticesStartColumn[11]{};
	Vector3 screenVerticesEndColumn[11]{};

	//横
	Vector3 LocalVerticesStartLine[11]{};
	Vector3 LocalVerticesEndLine[11]{};
	Matrix4x4 WorldMatrixStartLine[11]{};
	Matrix4x4 WorldMatrixEndLine[11]{};
	Vector3 ScreenVerticesLine{};
	Vector3 ndcVerticesStartLine{};
	Vector3 ndcVerticesEndLine{};
	Vector3 screenVerticesStartLine[11]{};
	Vector3 screenVerticesEndLine[11]{};


	//奥から手前への線を順々に引いてくる(縦)
	for (int xIndex = 0; xIndex <= subDivision; ++xIndex) {

		LocalVerticesStartColumn[xIndex].x = xIndex * gridEvery - gridHalfWidth;
		LocalVerticesStartColumn[xIndex].y = 0.0f;
		LocalVerticesStartColumn[xIndex].z = -gridHalfWidth;

		LocalVerticesEndColumn[xIndex].x = xIndex * gridEvery - gridHalfWidth;
		LocalVerticesEndColumn[xIndex].y = 0.0f;
		LocalVerticesEndColumn[xIndex].z = gridHalfWidth;

		WorldMatrixStartColumn[xIndex] = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, LocalVerticesStartColumn[xIndex]);
		WorldMatrixEndColumn[xIndex] = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, LocalVerticesEndColumn[xIndex]);


		Matrix4x4 worldViewProjectionMatrixStart = matrix::Multiply(WorldMatrixStartColumn[xIndex], matrix::Multiply(viewMatrix, viewProjectionMatrix));
		Matrix4x4 worldViewProjectionMatrixEnd = matrix::Multiply(WorldMatrixEndColumn[xIndex], matrix::Multiply(viewMatrix, viewProjectionMatrix));


		ndcVerticesStartColumn = TransformByMatrix(LocalVerticesStartColumn[xIndex], worldViewProjectionMatrixStart);
		ndcVerticesEndColumn = TransformByMatrix(LocalVerticesEndColumn[xIndex], worldViewProjectionMatrixEnd);

		screenVerticesStartColumn[xIndex] = TransformByMatrix(ndcVerticesStartColumn, viewportMatrix);
		screenVerticesEndColumn[xIndex] = TransformByMatrix(ndcVerticesEndColumn, viewportMatrix);


		Novice::DrawLine(
			int(screenVerticesStartColumn[xIndex].x),
			int(screenVerticesStartColumn[xIndex].y),
			int(screenVerticesEndColumn[xIndex].x),
			int(screenVerticesEndColumn[xIndex].y),
			BLACK);

		Novice::DrawLine(
			int(screenVerticesStartColumn[0].x),
			int(screenVerticesStartColumn[0].y),
			int(screenVerticesEndColumn[0].x),
			int(screenVerticesEndColumn[0].y),
			BLUE);
	}

	//左から右も同じように順々に引いていく(横)
	for (uint32_t zIndex = 0; zIndex <= subDivision; ++zIndex) {

		LocalVerticesStartLine[zIndex].x = -gridHalfWidth;
		LocalVerticesStartLine[zIndex].y = 0.0f;
		LocalVerticesStartLine[zIndex].z = zIndex * gridEvery - gridHalfWidth;

		LocalVerticesEndLine[zIndex].x = gridHalfWidth;
		LocalVerticesEndLine[zIndex].y = 0.0f;
		LocalVerticesEndLine[zIndex].z = zIndex * gridEvery - gridHalfWidth;

		WorldMatrixStartLine[zIndex] = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, LocalVerticesStartLine[zIndex]);
		WorldMatrixEndLine[zIndex] = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, LocalVerticesEndLine[zIndex]);


		Matrix4x4 worldViewProjectionMatrixStartLine = matrix::Multiply(WorldMatrixStartLine[zIndex], matrix::Multiply(viewMatrix, viewProjectionMatrix));
		Matrix4x4 worldViewProjectionMatrixEndLine = matrix::Multiply(WorldMatrixEndLine[zIndex], matrix::Multiply(viewMatrix, viewProjectionMatrix));


		ndcVerticesStartLine = TransformByMatrix(LocalVerticesStartLine[zIndex], worldViewProjectionMatrixStartLine);
		ndcVerticesEndLine = TransformByMatrix(LocalVerticesEndLine[zIndex], worldViewProjectionMatrixEndLine);

		screenVerticesStartLine[zIndex] = TransformByMatrix(ndcVerticesStartLine, viewportMatrix);
		screenVerticesEndLine[zIndex] = TransformByMatrix(ndcVerticesEndLine, viewportMatrix);


		Novice::DrawLine(
			int(screenVerticesStartLine[zIndex].x),
			int(screenVerticesStartLine[zIndex].y),
			int(screenVerticesEndLine[zIndex].x),
			int(screenVerticesEndLine[zIndex].y),
			BLACK);

		Novice::DrawLine(
			int(screenVerticesStartLine[0].x),
			int(screenVerticesStartLine[0].y),
			int(screenVerticesEndLine[0].x),
			int(screenVerticesEndLine[0].y), BLUE);
	}
}


// 球の描画
void DrawSphere(
	const Sphere& sphere,
	const Matrix4x4& viewProjectionMatrix,
	const Matrix4x4& viewportMatrix,
	unsigned int color) {

	const uint32_t subDivision = 30;
	const float lonEvery = 2.0f * (float)M_PI / float(subDivision);
	const float lLatEvery = (float)M_PI / float(subDivision);

	for (uint32_t latIndex = 0; latIndex < subDivision; ++latIndex) {
		float lat = -1.0f * (float)M_PI / 2.0f + lLatEvery * latIndex;

		for (uint32_t lonIndex = 0; lonIndex < subDivision; ++lonIndex) {
			float lon = lonIndex * lonEvery;

			Vector3 a, b, c;
			a = {
				sphere.radius * std::cosf(lat) * std::cosf(lon),
				sphere.radius * std::sinf(lat),
				sphere.radius * std::cosf(lat) * std::sinf(lon) };
			a = vector::Add(a, sphere.center);

			b = {
				sphere.radius * std::cosf(lat + lLatEvery) * std::cosf(lon),
				sphere.radius * std::sinf(lat + lLatEvery),
				sphere.radius * std::cosf(lat + lLatEvery) * std::sinf(lon) };
			b = vector::Add(b, sphere.center);

			c = { sphere.radius * std::cosf(lat) * std::cosf(lon + lonEvery),
				sphere.radius * std::sinf(lat),
				sphere.radius * std::cosf(lat) * std::sinf(lon + lonEvery) };
			c = vector::Add(c, sphere.center);

			a = TransformByMatrix(a, viewProjectionMatrix);
			a = TransformByMatrix(a, viewportMatrix);
			b = TransformByMatrix(b, viewProjectionMatrix);
			b = TransformByMatrix(b, viewportMatrix);
			c = TransformByMatrix(c, viewProjectionMatrix);
			c = TransformByMatrix(c, viewportMatrix);


			Novice::DrawLine(
				int(a.x), int(a.y),
				int(b.x), int(b.y),
				color
			);

			Novice::DrawLine(
				int(a.x), int(a.y),
				int(c.x), int(c.y),
				color
			);

		}
	}
}


// 平面の描画
void DrawPlane(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, unsigned int color) {
	Vector3 center = {
		plane.normal.x * plane.distance,
		plane.normal.y * plane.distance,
		plane.normal.z * plane.distance, };

	Vector3 perpendiculars[4]{};
	perpendiculars[0] = Normalize(Perpendicular(plane.normal));
	perpendiculars[1] = { -perpendiculars[0].x,-perpendiculars[0].y,-perpendiculars[0].z };
	perpendiculars[2] = Cross(plane.normal, perpendiculars[0]);
	perpendiculars[3] = { -perpendiculars[2].x,-perpendiculars[2].y,-perpendiculars[2].z };

	Vector3 points[4]{};
	for (int32_t index = 0; index < 4; ++index) {
		Vector3 extend = {
			perpendiculars[index].x * 2.0f,
			perpendiculars[index].y * 2.0f,
			perpendiculars[index].z * 2.0f, };
		Vector3 point = vector::Add(center, extend);
		points[index] = TransformByMatrix(TransformByMatrix(point, viewProjectionMatrix), viewportMatrix);
	}

	Novice::DrawLine((int)points[0].x, (int)points[0].y, (int)points[2].x, (int)points[2].y, color);
	Novice::DrawLine((int)points[1].x, (int)points[1].y, (int)points[3].x, (int)points[3].y, color);
	Novice::DrawLine((int)points[2].x, (int)points[2].y, (int)points[1].x, (int)points[1].y, color);
	Novice::DrawLine((int)points[3].x, (int)points[3].y, (int)points[0].x, (int)points[0].y, color);
}


// 三角形の描画
void DrawTriAngle(
	const Triangle& triangle,
	const Matrix4x4& viewProjectionMatrix,
	const Matrix4x4& viewportMatrix,
	unsigned int color) {

	Vector3 verticle[3]{};

	for (int i = 0; i < 3; i++) {
		verticle[i] = TransformByMatrix(TransformByMatrix(triangle.vertices[i], viewProjectionMatrix), viewportMatrix);
	}

	Novice::DrawTriangle(
		(int)verticle[0].x, (int)verticle[0].y,
		(int)verticle[1].x, (int)verticle[1].y,
		(int)verticle[2].x, (int)verticle[2].y,
		color, kFillModeWireFrame);
}


// AABBの描画
void DrawAABB(
	const AABB& aabb,
	const Matrix4x4& viewProjection,
	const Matrix4x4& viewport,
	uint32_t color) {

	Vector3 verticles[8]{};
	verticles[0] = { aabb.min.x, aabb.min.y, aabb.min.z };
	verticles[1] = { aabb.min.x, aabb.min.y, aabb.max.z };
	verticles[2] = { aabb.min.x, aabb.max.y, aabb.min.z };
	verticles[3] = { aabb.max.x, aabb.min.y, aabb.min.z };
	verticles[4] = { aabb.max.x, aabb.max.y, aabb.min.z };
	verticles[5] = { aabb.min.x, aabb.max.y, aabb.max.z };
	verticles[6] = { aabb.max.x, aabb.min.y, aabb.max.z };
	verticles[7] = { aabb.max.x, aabb.max.y, aabb.max.z };

	Vector3 screenVerticles[8]{};
	for (int i = 0; i < 8; i++) {
		verticles[i] = TransformByMatrix(verticles[i], viewProjection);
		screenVerticles[i] = TransformByMatrix(verticles[i], viewport);
	}

	Novice::DrawLine(int(screenVerticles[0].x), int(screenVerticles[0].y), int(screenVerticles[1].x), int(screenVerticles[1].y), color);
	Novice::DrawLine(int(screenVerticles[0].x), int(screenVerticles[0].y), int(screenVerticles[2].x), int(screenVerticles[2].y), color);
	Novice::DrawLine(int(screenVerticles[0].x), int(screenVerticles[0].y), int(screenVerticles[3].x), int(screenVerticles[3].y), color);

	Novice::DrawLine(int(screenVerticles[1].x), int(screenVerticles[1].y), int(screenVerticles[5].x), int(screenVerticles[5].y), color);
	Novice::DrawLine(int(screenVerticles[1].x), int(screenVerticles[1].y), int(screenVerticles[6].x), int(screenVerticles[6].y), color);

	Novice::DrawLine(int(screenVerticles[2].x), int(screenVerticles[2].y), int(screenVerticles[4].x), int(screenVerticles[4].y), color);
	Novice::DrawLine(int(screenVerticles[2].x), int(screenVerticles[2].y), int(screenVerticles[5].x), int(screenVerticles[5].y), color);

	Novice::DrawLine(int(screenVerticles[3].x), int(screenVerticles[3].y), int(screenVerticles[4].x), int(screenVerticles[4].y), color);
	Novice::DrawLine(int(screenVerticles[3].x), int(screenVerticles[3].y), int(screenVerticles[6].x), int(screenVerticles[6].y), color);

	Novice::DrawLine(int(screenVerticles[4].x), int(screenVerticles[4].y), int(screenVerticles[7].x), int(screenVerticles[7].y), color);
	Novice::DrawLine(int(screenVerticles[5].x), int(screenVerticles[5].y), int(screenVerticles[7].x), int(screenVerticles[7].y), color);

	Novice::DrawLine(int(screenVerticles[6].x), int(screenVerticles[6].y), int(screenVerticles[7].x), int(screenVerticles[7].y), color);
}


// OBBの描画
void DrawOBB(
	const OBB& obb,
	const Matrix4x4& viewProjection,
	const Matrix4x4& viewport,
	uint32_t color) {

	Vector3 verticles[8]{};

	for (int i = 0; i < 8; ++i) {
		Vector3 sign{};
		sign.x = (i & 1) ? 1.0f : -1.0f;
		sign.y = (i & 2) ? 1.0f : -1.0f;
		sign.z = (i & 4) ? 1.0f : -1.0f;

		verticles[i].x = obb.center.x +
			sign.x * obb.orientations[0].x * obb.size.x +
			sign.y * obb.orientations[1].x * obb.size.y +
			sign.z * obb.orientations[2].x * obb.size.z;

		verticles[i].y = obb.center.y +
			sign.x * obb.orientations[0].y * obb.size.x +
			sign.y * obb.orientations[1].y * obb.size.y +
			sign.z * obb.orientations[2].y * obb.size.z;

		verticles[i].z = obb.center.z +
			sign.x * obb.orientations[0].z * obb.size.x +
			sign.y * obb.orientations[1].z * obb.size.y +
			sign.z * obb.orientations[2].z * obb.size.z;
	};


	Vector3 screenVerticles[8]{};
	for (int i = 0; i < 8; i++) {
		verticles[i] = TransformByMatrix(verticles[i], viewProjection);
		screenVerticles[i] = TransformByMatrix(verticles[i], viewport);
	}


	Novice::DrawLine(int(screenVerticles[0].x), int(screenVerticles[0].y), int(screenVerticles[1].x), int(screenVerticles[1].y), color);
	Novice::DrawLine(int(screenVerticles[0].x), int(screenVerticles[0].y), int(screenVerticles[2].x), int(screenVerticles[2].y), color);
	Novice::DrawLine(int(screenVerticles[0].x), int(screenVerticles[0].y), int(screenVerticles[4].x), int(screenVerticles[4].y), color);

	Novice::DrawLine(int(screenVerticles[1].x), int(screenVerticles[1].y), int(screenVerticles[3].x), int(screenVerticles[3].y), color);
	Novice::DrawLine(int(screenVerticles[1].x), int(screenVerticles[1].y), int(screenVerticles[5].x), int(screenVerticles[5].y), color);

	Novice::DrawLine(int(screenVerticles[2].x), int(screenVerticles[2].y), int(screenVerticles[3].x), int(screenVerticles[3].y), color);
	Novice::DrawLine(int(screenVerticles[2].x), int(screenVerticles[2].y), int(screenVerticles[6].x), int(screenVerticles[6].y), color);

	Novice::DrawLine(int(screenVerticles[3].x), int(screenVerticles[3].y), int(screenVerticles[7].x), int(screenVerticles[7].y), color);

	Novice::DrawLine(int(screenVerticles[4].x), int(screenVerticles[4].y), int(screenVerticles[5].x), int(screenVerticles[5].y), color);
	Novice::DrawLine(int(screenVerticles[4].x), int(screenVerticles[4].y), int(screenVerticles[6].x), int(screenVerticles[6].y), color);

	Novice::DrawLine(int(screenVerticles[5].x), int(screenVerticles[5].y), int(screenVerticles[7].x), int(screenVerticles[7].y), color);

	Novice::DrawLine(int(screenVerticles[6].x), int(screenVerticles[6].y), int(screenVerticles[7].x), int(screenVerticles[7].y), color);
}


// 球の当たり判定
bool SphereToShere::isCollision(const Sphere& s1, const Sphere& s2) {

	// 中心からの距離
	float distance = Length(vector::Subtract(s2.center, s1.center));

	// 距離と半径を比べる
	if (distance <= s1.radius + s2.radius) {

		// 当たってる
		return true;
	}
	// 当たってない
	return false;
}


// 球と面の当たり判定
bool SphereToPlane::isCollision(const Sphere& s, const Plane& p) {

	// 距離
	Vector3 newVector = {
		s.center.x - p.distance,
		s.center.y - p.distance,
		s.center.z - p.distance, };
	float distance = Dot(Normalize(p.normal), newVector);

	// 距離を比べる
	if (std::abs(distance) <= s.radius) {

		// 当たってる
		return true;
	}
	else {
		// 当たってない
		return false;
	}
}


// 線と平面の衝突判定
bool LineToPlane::isCollision(const Segment& s, const Plane& p) {

	// 法線と線の内積
	float dot = Dot(s.diff, p.normal);

	// 衝突 = 平行であるので、衝突しているはずがない
	if (dot == 0.0f) {

		// 当たってない
		return false;
	}

	// tを求める
	float t = (p.distance - Dot(s.origin, p.normal)) / dot;

	// tの値と線の種類で衝突判定
	if (0.0f <= t && t <= 1.0f) {

		// 当たってる
		return true;
	}
	// 当たってない
	return false;
}


// 三角形と線の当たり判定
bool TriangleToLine::isCollision(const Triangle& t, const Segment& s) {

	// 平面を作る
	Plane p1{};
	p1.normal = Normalize(
		Cross(vector::Subtract(t.vertices[1], t.vertices[0]),
			vector::Subtract(t.vertices[2], t.vertices[1])));
	p1.distance = Dot(t.vertices[0], p1.normal);


	// 法線と線の内積
	float dot = Dot(s.diff, p1.normal);

	// 衝突 = 平行であるので、衝突しているはずがない
	if (dot == 0.0f) {

		// 当たってない
		return false;
	}

	// tを求める
	float t1 = (p1.distance - Dot(s.origin, p1.normal)) / dot;

	// tの値と線の種類で衝突判定
	if (0.0f <= t1 && t1 <= 1.0f) {

		// 衝突点
		Vector3 td = {
			s.diff.x * t1,
			s.diff.y * t1,
			s.diff.z * t1, };
		Vector3 p = vector::Add(s.origin, td);

		// 各辺を結んだベクトルと、頂点と衝突点pを結んだベクトルのクロス積をとる
		Vector3 cross01 = Cross(
			vector::Subtract(t.vertices[1], t.vertices[0]),
			vector::Subtract(p, t.vertices[1]));

		Vector3 cross12 = Cross(
			vector::Subtract(t.vertices[2], t.vertices[1]),
			vector::Subtract(p, t.vertices[2]));

		Vector3 cross20 = Cross(
			vector::Subtract(t.vertices[0], t.vertices[2]),
			vector::Subtract(p, t.vertices[0]));


		// すべての小三角形のクロス積と法線が同じ方向を向いていたら衝突	
		if (Dot(cross01, p1.normal) >= 0.0f &&
			Dot(cross12, p1.normal) >= 0.0f &&
			Dot(cross20, p1.normal) >= 0.0f) {

			// 当たっている
			return true;
		}
	}
	// 当たってない
	return false;
}


// AABBとAABBの当たり判定
bool AABBToAABB::isCollision(const AABB& aabb1, const AABB& aabb2) {

	if ((aabb1.min.x <= aabb2.max.x && aabb1.max.x >= aabb2.min.x) &&
		(aabb1.min.y <= aabb2.max.y && aabb1.max.y >= aabb2.min.y) &&
		(aabb1.min.z <= aabb2.max.z && aabb1.max.z >= aabb2.min.z)
		) {

		// 当たっている
		return true;
	}
	// 当たってない
	return false;
}


// AABBと球の当たり判定
bool AABBToSphere::isCollision(const AABB& aabb, const Sphere& s) {

	// 最近接点を求める
	const Vector3 ClosestPoint = {
		std::clamp(s.center.x, aabb.min.x, aabb.max.x),
		std::clamp(s.center.y, aabb.min.y, aabb.max.y),
		std::clamp(s.center.z, aabb.min.z, aabb.max.z), };

	// 最近接点と球の中心と距離を求める
	float dist = Length(vector::Subtract(ClosestPoint, s.center));

	// 距離が半径よりも小さければ衝突
	if (dist <= s.radius) {

		// 当たってる
		return true;
	}
	else {
		// 当たってない
		return false;
	}
}


// AABBと線の当たり判定
bool AABBToSegment::isCollision(const AABB& aabb, const Segment& s) {

	Vector3 tMin = {
		.x = (aabb.min.x - s.origin.x) / s.diff.x,
		.y = (aabb.min.y - s.origin.y) / s.diff.y,
		.z = (aabb.min.z - s.origin.z) / s.diff.z,
	};
	Vector3 tMax = {
		.x = (aabb.max.x - s.origin.x) / s.diff.x,
		.y = (aabb.max.y - s.origin.y) / s.diff.y,
		.z = (aabb.max.z - s.origin.z) / s.diff.z,
	};


	if (std::isnan(tMin.x) || std::isnan(tMax.x) ||
		std::isnan(tMin.y) || std::isnan(tMax.y) ||
		std::isnan(tMin.z) || std::isnan(tMax.z)) {
		return true;
	}


	Vector3 tNear = {
		.x = min(tMin.x, tMax.x),
		.y = min(tMin.y, tMax.y),
		.z = min(tMin.z, tMax.z),
	};
	Vector3 tFar = {
		.x = max(tMin.x, tMax.x),
		.y = max(tMin.y, tMax.y),
		.z = max(tMin.z, tMax.z),
	};

	// AABBとの衝突点(貫通点)のtが小さいほう
	float ntMin = max(max(tNear.x, tNear.y), tNear.z);
	// AABBとの衝突点(貫通点)のtが大きいほう
	float ntMax = min(min(tFar.x, tFar.y), tFar.z);


	if (ntMin < 0.0f && ntMax < 0.0f || ntMin > 1.0f && ntMax > 1.0f) {
		return false;
	}

	if (ntMin < ntMax) {

		// 当たってる
		return true;
	}
	else {

		// 当たってない
		return false;
	}
}


// OBBと球の当たり判定
bool OBBToSphere::isCollision(const OBB& obb, const Sphere& s) {

	Vector3 centerInOBBLocalSpace = {
		TransformByMatrix(s.center, Inverse(CreateOBBWorldMatrix(obb))) };

	AABB abbOBBLocal = {
		.min = { -obb.size.x, -obb.size.y, -obb.size.z },
		.max = { obb.size.x, obb.size.y, obb.size.z }
	};
	Sphere sphereOBBLocal = {
		centerInOBBLocalSpace,
		s.radius
	};

	// ローカル座標で衝突判定
	if (AABBToSphere::isCollision(abbOBBLocal, sphereOBBLocal)) {

		// 当たってる
		return true;
	}
	else {

		// 当たってない
		return false;
	}
}


// OBBと線の当たり判定
bool OBBToSegment::isCollision(const OBB& obb, const Segment& s) {

	Matrix4x4 obbInverse = Inverse(CreateOBBWorldMatrix(obb));

	AABB aabbOBBLocal = {
		.min = { -obb.size.x, -obb.size.y, -obb.size.z },
		.max = { obb.size.x, obb.size.y, obb.size.z }
	};


	Vector3 localOrigin = TransformByMatrix(s.origin, obbInverse);
	Vector3 LocalEnd = TransformByMatrix(vector::Add(s.origin, s.diff), obbInverse);

	Segment localSegment = {
		.origin = localOrigin,
		.diff = vector::Subtract(LocalEnd, localOrigin),
	};


	// AABBとSegmentの当たり判定を使う
	if (AABBToSegment::isCollision(aabbOBBLocal, localSegment)) {

		// 当たってる
		return true;
	}
	else {

		// 当たってない
		return false;
	}
}


// OBBとOBBの当たり判定
bool OBBToOBB::isCollision(const OBB& obb1, const OBB& obb2) {

	// 分離軸テスト
	for (const auto& axis : obb1.orientations) {
		if (!TestAxis(axis, obb1, obb2)) {
			return false;
		}
	}

	for (const auto& axis : obb2.orientations) {
		if (!TestAxis(axis, obb1, obb2)) {
			return false;
		}
	}

	// OBB1の軸とOBB2の軸に垂直な軸をテスト
	for (const auto& axis : {
			Vector3{obb1.orientations[1].x * obb2.orientations[2].x - obb1.orientations[2].x * obb2.orientations[1].x,
					obb1.orientations[1].y * obb2.orientations[2].y - obb1.orientations[2].y * obb2.orientations[1].y,
					obb1.orientations[1].z * obb2.orientations[2].z - obb1.orientations[2].z * obb2.orientations[1].z},
			Vector3{obb1.orientations[2].x * obb2.orientations[0].x - obb1.orientations[0].x * obb2.orientations[2].x,
					obb1.orientations[2].y * obb2.orientations[0].y - obb1.orientations[0].y * obb2.orientations[2].y,
					obb1.orientations[2].z * obb2.orientations[0].z - obb1.orientations[0].z * obb2.orientations[2].z},
			Vector3{obb1.orientations[0].x * obb2.orientations[1].x - obb1.orientations[1].x * obb2.orientations[0].x,
					obb1.orientations[0].y * obb2.orientations[1].y - obb1.orientations[1].y * obb2.orientations[0].y,
					obb1.orientations[0].z * obb2.orientations[1].z - obb1.orientations[1].z * obb2.orientations[0].z} }) {
		if (!TestAxis(axis, obb1, obb2)) {
			return false;
		}
	}

	return true;
}