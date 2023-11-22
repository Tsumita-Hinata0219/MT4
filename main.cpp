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


	AABB aabb = {
		.min = {-0.5f, -0.5f, -0.5f},
		.max = {0.5f, 0.5f, 0.5f},
	};
	Segment segment = {
		.origin = {-0.7f, 0.3f, 0.0f},
		.diff = {2.0f, -0.5f, 0.0f},
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

		Vector3 start = Transform(Transform(segment.origin, WorldViewProjectionMatrix), viewportMatrix);
		Vector3 end = Transform(Transform(vector::Add(segment.origin, segment.diff), WorldViewProjectionMatrix), viewportMatrix);

		



		ImGui::Begin("window");
		ImGui::DragFloat3("CameraTranslate", &cameraTranslate.x, 0.01f);
		ImGui::DragFloat3("CameraRotate", &cameraRotate.x, 0.01f);
		ImGui::Text("AABB");
		ImGui::DragFloat3("AABB.Min", &aabb.min.x, 0.01f);
		ImGui::DragFloat3("AABB.Max", &aabb.max.x, 0.01f);
		ImGui::Text("Segment");
		ImGui::DragFloat3("Segment.origin", &segment.origin.x, 0.01f);
		ImGui::DragFloat3("Segment.diff", &segment.diff.x, 0.01f);
		if (AABBToSegment::isCollision(aabb, segment)) {
			Color = RED;
		}
		else {
			Color = WHITE;
		}
		ImGui::End();


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///


		DrawGrid(viewMatrix, projectionMatrix, viewportMatrix);
		DrawAABB(aabb, WorldViewProjectionMatrix, viewportMatrix, Color);
		Novice::DrawLine(int(start.x), int(start.y), int(end.x), int(end.y), WHITE);


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
