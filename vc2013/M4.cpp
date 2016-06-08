#include "M4.h"

void M4::setup()
{
	ObjLoader loader = ObjLoader(loadAsset("Vz-58.obj"));
	loader.load(&mesh, boost::logic::indeterminate, boost::logic::indeterminate,
		false);
	material = gl::Material(ColorA(1, 1, 1, 1.0f),    // �����������������̐F
		ColorA(0.8f, 0.8f, 0.8f, 1.0f),    // �g�U���������������̐F
		ColorA(0.0f, 0.0f, 0.0f, 1.0f),    // ���ʌ��������������̐F
		80.0f,                             // ���ʔ��˂̉s��(�l���傫���قǉs���Ȃ�)
		ColorA(0.0f, 0.0f, 0.0f, 1.0f));   // ���Ȕ����F
	matrix = Matrix44f::identity();

}

void M4::update()
{
	
}

void M4::draw()
{
	gl::pushModelView();
	gl::multModelView(CAMERA.getMatrix());
	Matrix44f matrix_t = Matrix44f::createTranslation(Vec3f(0.3, -0.3, -0.7));
	Matrix44f matrix_r = Matrix44f::createRotation(Vec3f(0, 3.1*M_PI/6, 0));
	
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

void M4::fire()
{
}

