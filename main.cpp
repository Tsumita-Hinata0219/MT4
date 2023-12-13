#include <Novice.h>
#include "MathFunction.h"
#include "imgui.h"

const char kWindowTitle[] = "LE2B_13_ツミタ_ヒナタ_MT4";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	const int ScreenWidth = 1280;
	const int ScreenHeight = 720;
	Novice::Initialize(kWindowTitle, ScreenWidth, ScreenHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//Affine
	Vector3 scale = { 1.0f,1.0f,1.0f };
	Vector3 rotate = { 0.0f,0.0f,0.0f };
	Vector3 translate = { 0.0f,0.0f,0.0f };

	//カメラ
	Vector3 cameraTranslate = { 0.0f,1.9f,-6.49f };
	Vector3 cameraRotate = { 0.26f,0.0f,0.0f };

	Plane plane = { {0.0f,1.0f,0.0f}, 1.0f };

	Segment segment = { 
		.origin {-0.8f,0.3f,0.0f},
		.diff {0.5f,0.5f,0.5f} 
	};

	AABB aabb = {
		.min {-0.5f, -0.5f, -0.5f},
		.max {0.5f, 0.5f, 0.5f},
	};
	Vector3 obbrotate1{ 0.0f, 0.0f, 0.0f };
	OBB obb1 = {
		.center { 0.0f, 0.0f, 0.0f },
		.orientations = {
			{1.0f, 0.0f, 0.0f},
			{0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 1.0f},},
		.size {0.83f, 0.26f, 0.24f},
	};
	Vector3 obbrotate2{ -0.05f, -2.49f, 0.15f };
	OBB obb2 = {
		.center { 0.9f, 0.66f, 0.78f },
		.orientations = {
			{1.0f, 0.0f, 0.0f},
			{0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 1.0f},},
		.size {0.5f, 0.37f, 0.5f},
	};

	int Color = WHITE;

	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		//計算
		Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, rotate, translate);
		Matrix4x4 cameraMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
		Matrix4x4 viewMatrix = Inverse(cameraMatrix);
		Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(ScreenWidth) / float(ScreenHeight), 0.1f, 100.0f);
		Matrix4x4 WorldViewProjectionMatrix = matrix::Multiply(worldMatrix, matrix::Multiply(viewMatrix, projectionMatrix));
		Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, float(ScreenWidth), float(ScreenHeight), 0.0f, 1.0f);


		Matrix4x4 rotateMat1 = MakeRotateXYZMatrix(obbrotate1.x, obbrotate1.y, obbrotate1.z);
		obb1.orientations[0].x = rotateMat1.m[0][0];
		obb1.orientations[0].y = rotateMat1.m[0][1];
		obb1.orientations[0].z = rotateMat1.m[0][2];
		obb1.orientations[1].x = rotateMat1.m[1][0];
		obb1.orientations[1].y = rotateMat1.m[1][1];
		obb1.orientations[1].z = rotateMat1.m[1][2];
		obb1.orientations[2].x = rotateMat1.m[2][0];
		obb1.orientations[2].y = rotateMat1.m[2][1];
		obb1.orientations[2].z = rotateMat1.m[2][2];

		Matrix4x4 rotateMat2 = MakeRotateXYZMatrix(obbrotate2.x, obbrotate2.y, obbrotate2.z);
		obb2.orientations[0].x = rotateMat2.m[0][0];
		obb2.orientations[0].y = rotateMat2.m[0][1];
		obb2.orientations[0].z = rotateMat2.m[0][2];
		obb2.orientations[1].x = rotateMat2.m[1][0];
		obb2.orientations[1].y = rotateMat2.m[1][1];
		obb2.orientations[1].z = rotateMat2.m[1][2];
		obb2.orientations[2].x = rotateMat2.m[2][0];
		obb2.orientations[2].y = rotateMat2.m[2][1];
		obb2.orientations[2].z = rotateMat2.m[2][2];

		ImGui::Begin("window");
		ImGui::DragFloat3("CameraTranslate", &cameraTranslate.x, 0.01f);
		ImGui::DragFloat3("CameraRotate", &cameraRotate.x, 0.01f);
		//PlaneのImGui
		ImGui::Text("OBB1");
		ImGui::DragFloat3("OBB1.center", &obb1.center.x, 0.01f);
		ImGui::DragFloat3("OBB1.rotate", &obbrotate1.x, 0.01f);
		ImGui::DragFloat3("OBB1.size", &obb1.size.x, 0.01f);
		ImGui::Text("OBB2");
		ImGui::DragFloat3("OBB2.center", &obb2.center.x, 0.01f);
		ImGui::DragFloat3("OBB2.rotate", &obbrotate2.x, 0.01f);
		ImGui::DragFloat3("OBB2.size", &obb2.size.x, 0.01f);
		Vector3 start = TransformByMatrix(TransformByMatrix(segment.origin, WorldViewProjectionMatrix), viewportMatrix);
		Vector3 end = TransformByMatrix(TransformByMatrix(vector::Add(segment.origin, segment.diff), WorldViewProjectionMatrix), viewportMatrix);
		if (OBBToOBB::isCollision(obb1, obb2) == true) {
			Color = RED;
		}
		else {
			Color = WHITE;
		}
		ImGui::End();
		plane.normal = Normalize(plane.normal);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		DrawGrid(viewMatrix, projectionMatrix, viewportMatrix);
		//Novice::DrawLine(int(start.x), int(start.y), int(end.x), int(end.y), Color);
		DrawOBB(obb1, WorldViewProjectionMatrix, viewportMatrix, WHITE);
		DrawOBB(obb2, WorldViewProjectionMatrix, viewportMatrix, Color);
		//DrawPlane(plane, WorldViewProjectionMatrix, viewportMatrix, WHITE);
		//DrawAABB(aabb, WorldViewProjectionMatrix, viewportMatrix, WHITE);


		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
