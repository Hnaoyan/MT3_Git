﻿#pragma once
#include"Matrix.h"
#include "Render.h"
#include <stdint.h>
#define _USE_MATH_DEFINES
#include <math.h>

struct Sphere {
	Vector3 center;	// 中心点
	float radius;	// 半径
};

struct Line {
	Vector3 origin;	// 始点
	Vector3 diff;	// 終点への差分ベクトル
};

struct Ray {
	Vector3 origin;	// 始点
	Vector3 diff;	// 終点への差分ベクトル
};

struct Segment {
	Vector3 origin;	// 始点
	Vector3 diff;	// 終点への差分ベクトル
};

struct Plane {
	Vector3 normal;	// 法線
	float distance;	// 距離
};

struct Triangle {
	Vector3 vertices[3];
};

class DrawSet
{
public:
	/// <summary>
	/// グリッド線描画
	/// </summary>
	/// <param name="viewProjectionMatrix"></param>
	/// <param name="viewportMatrix"></param>
	static void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix);
	/// <summary>
	/// 球描画
	/// </summary>
	/// <param name="sphere"></param>
	/// <param name="viewProjectionMatrix"></param>
	/// <param name="viewportMatrix"></param>
	/// <param name="color"></param>
	static void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);
	/// <summary>
	/// 平面描画
	/// </summary>
	/// <param name="plane"></param>
	/// <param name="viewProjectionMatrix"></param>
	/// <param name="viewportMatrix"></param>
	/// <param name="color"></param>
	static void DrawPlane(const Plane& plane, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

	/// <summary>
	/// 三角形描画
	/// </summary>
	/// <param name="triangle"></param>
	/// <param name="viewProjectionMatrix"></param>
	/// <param name="viewportMatrix"></param>
	/// <param name="color"></param>
	static void DrawTriangle(const Triangle& triangle, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color);

	static Vector3 Project(const Vector3& v1, const Vector3& v2);
	static Vector3 ClosetPoint(const Vector3& point, const Segment& segment);
	
	static Vector3 Perpendicular(const Vector3& vector);

};
