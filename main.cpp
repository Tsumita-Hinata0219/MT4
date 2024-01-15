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


	Quaternion rotation0 = MakeRotateAxisAngleQuatenion({ 0.71f, 0.71f, 0.0f }, 0.3f);
	Quaternion rotation1 = { -rotation0.x, -rotation0.y, -rotation0.z, -rotation0.w };

	Quaternion interpolate0 = quaternion::Slerp(rotation0, rotation1, 0.0f);
	Quaternion interpolate1 = quaternion::Slerp(rotation0, rotation1, 0.3f);
	Quaternion interpolate2 = quaternion::Slerp(rotation0, rotation1, 0.5f);
	Quaternion interpolate3 = quaternion::Slerp(rotation0, rotation1, 0.7f);
	Quaternion interpolate4 = quaternion::Slerp(rotation0, rotation1, 1.0f);

	
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
		
		ImGui::Begin("01_05");
		ImGui::DragFloat4("interpolate0 : Slerp(q0, q1, 0.0f)", &interpolate0.x);
		ImGui::DragFloat4("interpolate1 : Slerp(q0, q1, 0.3f)", &interpolate1.x);
		ImGui::DragFloat4("interpolate2 : Slerp(q0, q1, 0.5f)", &interpolate2.x);
		ImGui::DragFloat4("interpolate3 : Slerp(q0, q1, 0.7f)", &interpolate3.x);
		ImGui::DragFloat4("interpolate4 : Slerp(q0, q1, 1.0f)", &interpolate4.x);
		ImGui::End();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///



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
