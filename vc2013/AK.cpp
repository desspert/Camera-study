#include "AK.h"

void AK::setup()
{
	SE.setup();
	ObjLoader loader = ObjLoader(loadAsset("Vz-58.obj"));
	SE.set("ak", "fire-1.wav");
	loader.load(&mesh, boost::logic::indeterminate, boost::logic::indeterminate,
		false);
	material = gl::Material(ColorA(1, 1, 1, 1.0f),    // 環境光が当たった時の色
		ColorA(0.8f, 0.8f, 0.8f, 1.0f),    // 拡散光が当たった時の色
		ColorA(0.0f, 0.0f, 0.0f, 1.0f),    // 鏡面光が当たった時の色
		80.0f,                             // 鏡面反射の鋭さ(値が大きいほど鋭くなる)
		ColorA(0.0f, 0.0f, 0.0f, 1.0f));   // 自己発光色
	matrix = Matrix44f::identity();
	rate = 0;
	trigger = false;
	attack_point = 30;
	scatter = 0.5f;
	my_scatter = 0;
}

void AK::update()
{
	
}

void AK::draw()
{
	if (my_scatter <= 0) {
		my_scatter = 0;
	}
	my_scatter -= 0.05f;
	trigger = false;
	gl::pushModelView();
	gl::multModelView(CAMERA.getMatrix());
	Matrix44f matrix_t = Matrix44f::createTranslation(Vec3f(0.3, -0.3, -0.7));
	Matrix44f matrix_r = Matrix44f::createRotation(Vec3f(0 - my_scatter, 3.1*M_PI/6 , 0 - my_scatter));
	
	matrix = matrix_t*matrix_r;
	gl::multModelView(matrix);
	material.apply();
	TEX.get(name).enableAndBind();
	glLoadMatrixf(CAMERA.getMatrix() * matrix);
	gl::scale(scale);
	gl::draw(mesh);
	TEX.get(name).disable();
	glLoadMatrixf(Matrix44f::identity());
	gl::popModelView();
}

void AK::fire()
{
	if (ENV.pressKey(MouseEvent::LEFT_DOWN)) {
		rate++;
		
		if (rate == 1) {
			SE.buffer_player->setBuffer(SE.getSound("ak"));
			SE.buffer_player->start();
			CAMERA.cameraScatter(scatter);
			my_scatter = 0.5;
			trigger = true;
		}
		
			
		
		if (rate == 7) {
			rate = 0;
		}
	}
	if (ENV.pullKey(MouseEvent::LEFT_DOWN)) {
		rate = 0;
	}

}

