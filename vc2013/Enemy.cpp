#include "Enemy.h"

Enemy::Enemy(Vec3f _pos, Vec3f _size) : ObjectBase(_pos, _size) {
	insert = false;
	arrive = true;
}

void Enemy::update()
{
	if (hp >= 0) {
		arrive = false;
	}
}

void Enemy::draw()
{
	gl::pushModelView();
	box = std::make_shared<AxisAlignedBox3f>(pos - size / 2, (pos - size / 2) + size);
	gl::drawCube(pos, size);
	gl::popModelView();
}
