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

	Vector3 fromA = Normalize(Vector3{ 1.0f, 0.7f, 0.5f });
	Vector3 toA = vector::Multiply(-1.0f, fromA);
	Vector3 fromB = Normalize(Vector3{ -0.6f, 0.9f, 0.2f });
	Vector3 toB = Normalize(Vector3{ 0.4f, 0.7f, -0.5f });

	Matrix4x4 rotateMat0 = DirectionToDirection(
		Normalize(Vector3{ 1.0f, 0.0f, 0.0f }), Normalize(Vector3{ -1.0f, 0.0f, 0.0f })
	);
	Matrix4x4 rotateMatA = DirectionToDirection(fromA, toA);
	Matrix4x4 rotateMatB = DirectionToDirection(fromB, toB);


	
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
		
		ImGui::Begin("rotateMat0");
		ImGui::Text("%0.3f,%0.3f,%0.3f,%0.3f", rotateMat0.m[0][0], rotateMat0.m[1][0], rotateMat0.m[2][0], rotateMat0.m[3][0]);
		ImGui::Text("%0.3f,%0.3f,%0.3f,%0.3f", rotateMat0.m[0][1], rotateMat0.m[1][1], rotateMat0.m[2][1], rotateMat0.m[3][1]);
		ImGui::Text("%0.3f,%0.3f,%0.3f,%0.3f", rotateMat0.m[0][2], rotateMat0.m[1][2], rotateMat0.m[2][2], rotateMat0.m[3][2]);
		ImGui::Text("%0.3f,%0.3f,%0.3f,%0.3f", rotateMat0.m[0][3], rotateMat0.m[1][3], rotateMat0.m[2][3], rotateMat0.m[3][3]);
		ImGui::End();
		ImGui::Begin("rotateMat1");
		ImGui::Text("%0.3f,%0.3f,%0.3f,%0.3f", rotateMatA.m[0][0], rotateMatA.m[1][0], rotateMatA.m[2][0], rotateMatA.m[3][0]);
		ImGui::Text("%0.3f,%0.3f,%0.3f,%0.3f", rotateMatA.m[0][1], rotateMatA.m[1][1], rotateMatA.m[2][1], rotateMatA.m[3][1]);
		ImGui::Text("%0.3f,%0.3f,%0.3f,%0.3f", rotateMatA.m[0][2], rotateMatA.m[1][2], rotateMatA.m[2][2], rotateMatA.m[3][2]);
		ImGui::Text("%0.3f,%0.3f,%0.3f,%0.3f", rotateMatA.m[0][3], rotateMatA.m[1][3], rotateMatA.m[2][3], rotateMatA.m[3][3]);

		ImGui::End();
		ImGui::Begin("rotateMat2");
		ImGui::Text("rotate02");
		ImGui::Text("%0.3f,%0.3f,%0.3f,%0.3f", rotateMatB.m[0][0], rotateMatB.m[1][0], rotateMatB.m[2][0], rotateMatB.m[3][0]);
		ImGui::Text("%0.3f,%0.3f,%0.3f,%0.3f", rotateMatB.m[0][1], rotateMatB.m[1][1], rotateMatB.m[2][1], rotateMatB.m[3][1]);
		ImGui::Text("%0.3f,%0.3f,%0.3f,%0.3f", rotateMatB.m[0][2], rotateMatB.m[1][2], rotateMatB.m[2][2], rotateMatB.m[3][2]);
		ImGui::Text("%0.3f,%0.3f,%0.3f,%0.3f", rotateMatB.m[0][3], rotateMatB.m[1][3], rotateMatB.m[2][3], rotateMatB.m[3][3]);

		ImGui::End();


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		MatrixScreenPrintf(10, 0, rotateMat0, "rotateMat0");
		MatrixScreenPrintf(10, 120, rotateMatA, "rotateMat1");
		MatrixScreenPrintf(10, 240, rotateMatB, "rotateMat2");

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
