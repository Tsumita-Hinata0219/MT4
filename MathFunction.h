#pragma once

#include "Structure.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>
#include <Novice.h>
#include <iostream>
#include <cassert>
#include "imgui.h"
#include <algorithm>
#include <Windows.h>
#include <array>



// 表示
static const int kRowHeight = 20;
static const int kColumnWidth = 60;
void VectorScreenPrintf(int x, int y, const Vector3 vector, const char* label);
void MatrixScreenPrintf(int x, int y, const Matrix4x4& matrix, const char* label);


inline Quaternion operator*(const Quaternion& a, const float b);
inline Quaternion operator*(const float b, const Quaternion& a);
inline Quaternion operator+ (const Quaternion& a, const Quaternion& b);


// 3次元ベクトル
namespace vector {

	// 加算
	Vector3 Add(const Vector3 v1, const Vector3 v2);

	// 減算
	Vector3 Subtract(const Vector3 v1, const Vector3 v2);

	// スカラー倍
	Vector3 Multiply(float scalar, const Vector3 v);
}

// 内積
float Dot(const Vector3 v1, const Vector3 v2);
float Dot(const Quaternion& qA, const Quaternion& qB);

// 長さ
float Length(const Vector3 v);
float Length(const Quaternion v);

// 正規化
Vector3 Normalize(const Vector3 v);

// 座標変換
Vector3 TransformByMatrix(const Vector3 vector, const Matrix4x4 matrix);

// 行列
namespace matrix {

	// 加算
	Matrix4x4 Add(const Matrix4x4& m1, const Matrix4x4& m2);

	// 減算
	Matrix4x4 Subtract(const Matrix4x4& m1, const Matrix4x4& m2);

	// 乗算
	Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

	// 逆行列
	Matrix4x4 Inverse(const Matrix4x4& m);
}

// 転置行列
Matrix4x4 Transpose(const Matrix4x4& m);

// 単位行列の作成
Matrix4x4 MakeIdentity4x4();

// 平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3 translate);

// 拡大縮小行列
Matrix4x4 MakeScaleMatrix(const Vector3 scele);

// 回転行列(X,Y,Z)
Matrix4x4 MakeRotateXMatrix(float radian);

Matrix4x4 MakeRotateYMatrix(float radian);

Matrix4x4 MakeRotateZMatrix(float radian);

// 回転行列(all)
Matrix4x4 MakeRotateXYZMatrix(float radianX, float radianY, float radianZ);

// 任意軸回転行列
Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float angle);
Matrix4x4 MakeRotateAxisAngle(const Vector3& axis, float cos, float sin);

// ある方向からある方向への回転
Matrix4x4 DirectionToDirection(const Vector3& from, const Vector3& to);

// Quaternion
namespace quaternion {

	// Quaternionの積
	Quaternion Multiply(const Quaternion& lhs, const Quaternion& rhs);

	// 単位Quaternionを返す
	Quaternion Identity();

	// 共役Quaternionを返す
	Quaternion Conjugate(const Quaternion& quaternion);

	// Quaternionのnormを返す
	float Norm(const Quaternion& quaternion);

	// 正規化したQuaternionを返す
	Quaternion Normalize(const Quaternion& quaternion);

	// 逆Quatenionを返す
	Quaternion Inverse(const Quaternion& quaternion);

	// 球面線形補間
	Quaternion Slerp(const Quaternion& qA, const Quaternion& qB, float t);
}

// 任意軸回転を表すQuaternionの生成
Quaternion	MakeRotateAxisAngleQuatenion(const Vector3& axis, float angle);

// ベクトルをQuaternionで回転させた結果のベクトルを求める
Vector3 RotateVector(const Vector3& vector, const Quaternion& quaternion);

// Quaternionから回転行列を求める
Matrix4x4 MakeRotateMatrix(const Quaternion& quaternion);

// 平行移動行列
Matrix4x4 MakeTranslateMatrix(const Vector3 translate);

// 3次元アフィン変換行列 (W = SRT)
Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

// 透視投影行列
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspecrRatio, float nearClip, float farClip);

// 正射影行列
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);

// ビューポート変換行列
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);

// クロス積
Vector3 Cross(const Vector3& v1, const Vector3& v2);

// 正射影ベクトル
Vector3 Project(const Vector3 v1, const Vector3 v2);

// 最近接点
Vector3 ClosestPoint(const Vector3 point, const Segment segment);

// 
Vector3 Perpendicular(const Vector3& vector);

// OBBのワールドマトリックス作成
Matrix4x4 CreateOBBWorldMatrix(const OBB& obb);

// 射影の重複チェック
bool TestAxis(const Vector3& axis, const OBB& obb1, const OBB& obb2);

// 実際に重なってるかの計算
bool projectionOverlap(const std::pair<float, float>& projection1, const std::pair<float, float>& projection2);

// 頂点を軸に射影
std::pair<float, float> obbProjection(const OBB& obb, const Vector3& axis);

// グリッドの描画
void DrawGrid(const Matrix4x4& viewMatrix, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);

// 球の描画
void DrawSphere(
	const Sphere& sphere,
	const Matrix4x4& viewProjectionMatrix,
	const Matrix4x4& viewportMatrix,
	unsigned int color);

// 平面の描画
void DrawPlane(
	const Plane& plane,
	const Matrix4x4& viewProjectionMatrix,
	const Matrix4x4& viewportMatrix,
	unsigned int color);

// 三角形の描画
void DrawTriAngle(
	const Triangle& triangle,
	const Matrix4x4& viewProjectionMatrix,
	const Matrix4x4& viewportMatrix,
	unsigned int color);

// AABBの描画
void DrawAABB(
	const AABB& aabb,
	const Matrix4x4& viewProjection,
	const Matrix4x4& viewport,
	uint32_t color);

// OBBの描画
void DrawOBB(
	const OBB& obb,
	const Matrix4x4& viewProjection,
	const Matrix4x4& viewport,
	uint32_t color);

// 球と球の当たり判定
namespace SphereToShere {

	bool isCollision(const Sphere& s1, const Sphere& s2);
}

// 球と面の当たり判定
namespace SphereToPlane {

	bool isCollision(const Sphere& s, const Plane& p);
}

// 線と平面の衝突判定
namespace LineToPlane {

	bool isCollision(const Segment& s, const Plane& p);
}

// 三角形と線の当たり判定
namespace TriangleToLine {

	bool isCollision(const Triangle& t, const Segment& s);
}

// AABBとAABBの当たり判定
namespace AABBToAABB {

	bool isCollision(const AABB& aabb1, const AABB& aabb2);
}

// AABBと球の当たり判定
namespace AABBToSphere {

	bool isCollision(const AABB& aabb, const Sphere& s);
}

// AABBと線の当たり判定
namespace AABBToSegment {

	bool isCollision(const AABB& aabb, const Segment& s);
}

// OBBと球の当たり判定
namespace OBBToSphere {

	bool isCollision(const OBB& obb, const Sphere& s);
}

// OBBと線の当たり判定
namespace OBBToSegment {

	bool isCollision(const OBB& obb, const Segment& s);
}

// OBBとOBBの当たり判定
namespace OBBToOBB {

	bool isCollision(const OBB& obb1, const OBB& obb2);
}