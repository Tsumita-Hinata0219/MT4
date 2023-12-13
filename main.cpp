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



	Quaternion qA = { 2.0f, 3.0f, 4.0f, 1.0f };
	Quaternion qB = { 1.0f, 3.0f, 5.0f, 2.0f };

	Quaternion identity = quaternion::Identity();
	Quaternion conj = quaternion::Conjugate(qA);
	Quaternion inv = quaternion::Inverse(qA);
	Quaternion normal = quaternion::Normalize(qA);
	Quaternion mulA = quaternion::Multiply(qA, qB);
	Quaternion mulB = quaternion::Multiply(qB, qA);
	float norm = quaternion::Norm(qA);


	
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
		
		ImGui::Begin("Quaternion");
		ImGui::DragFloat4("Identity", &identity.x);
		ImGui::DragFloat4("Conjugate", &conj.x);
		ImGui::DragFloat4("Inverse", &inv.x);
		ImGui::DragFloat4("Normalize", &normal.x);
		ImGui::DragFloat4("Multiply(q1, q2)", &mulA.x);
		ImGui::DragFloat4("Multiply(q2, q1)", &mulB.x);
		ImGui::DragFloat("norm", &norm);
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
