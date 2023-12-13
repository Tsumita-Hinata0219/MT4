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



	Quaternion rotation = MakeRotateAxisAngleQuatenion(
		Normalize(Vector3{ 1.0f, 0.4f, -0.2f }), 0.45f);

	Vector3 pointY = { 2.1f, -0.9f, 1.3f };
	Matrix4x4 rotateMat = MakeRotateMatrix(rotation);
	Vector3 rotateByQuaternion = RotateVector(pointY, rotation);
	Vector3 rotateByMat = TransformByMatrix(pointY, rotateMat);

	
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
		
		ImGui::Begin("01_04");
		ImGui::DragFloat4("Rotation", &rotation.x);
		ImGui::Text("RotateMat");
		ImGui::Text(" %0.3f,  %0.3f,  %0.3f,  %0.3f", rotateMat.m[0][0], rotateMat.m[0][1], rotateMat.m[0][2], rotateMat.m[0][3]);
		ImGui::Text(" %0.3f,  %0.3f,  %0.3f,  %0.3f", rotateMat.m[1][0], rotateMat.m[1][1], rotateMat.m[1][2], rotateMat.m[1][3]);
		ImGui::Text(" %0.3f,  %0.3f,  %0.3f,  %0.3f", rotateMat.m[2][0], rotateMat.m[2][1], rotateMat.m[2][2], rotateMat.m[2][3]);
		ImGui::Text(" %0.3f,  %0.3f,  %0.3f,  %0.3f", rotateMat.m[3][0], rotateMat.m[3][1], rotateMat.m[3][2], rotateMat.m[3][3]);
		ImGui::DragFloat3("rotateByQuaternioon", &rotateByQuaternion.x);
		ImGui::DragFloat3("rotateByMat", &rotateByMat.x);
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
