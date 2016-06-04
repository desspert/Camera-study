#pragma once
#include "cinder/app/AppNative.h"
using namespace ci;
using namespace ci::app;
static bool collisionBoxToBox(Vec3f box_pos1,Vec3f box_size1,Vec3f box_pos2,Vec3f box_size2) {
	box_pos1 -= box_size1 / 2;
	box_pos2 -= box_size2 / 2;
	if (box_pos2.x < box_pos1.x + box_size1.x) {
		if (box_pos2.x + box_size2.x > box_pos1.x) {
			if (box_pos2.y < box_pos1.y + box_size1.y) {
				if (box_pos2.y + box_size2.y > box_pos1.y) {
					if (box_pos2.z < box_pos1.z + box_size1.z) {
						if (box_pos2.z + box_size2.z > box_pos1.z) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

//box1Ç…ìñÇΩÇËÇ…çsÇ≠Ç‡ÇÃ
//box2Ç…ìñÇƒÇÁÇÍÇÈÇ‡ÇÃ
static Vec3f returnBoxToBox(Vec3f box_pos1, Vec3f box_size1, Vec3f box_pos2, Vec3f box_size2) {
	if (collisionBoxToBox(box_pos1, box_size1, box_pos2, box_size2)) {
		box_pos1 -= box_size1 / 2;
		box_pos2 -= box_size2 / 2;

		if (box_pos2.y + (box_size2.y * 3) / 4 < box_pos1.y) {
			if (box_pos2.y + box_size2.y > box_pos1.y) {
				box_pos1 += box_size1 / 2;
				return Vec3f(box_pos1.x, box_pos2.y + box_size2.y + box_size1.y / 2, box_pos1.z);
			}
		}



		if (box_pos2.y  < box_pos1.y + box_size1.y) {
			if (box_pos2.y + box_size2.y / 4 > box_pos1.y + box_size1.y) {
				box_pos1 += box_size1 / 2;
				return Vec3f(box_pos1.x, box_pos2.y - box_size1.y / 2, box_pos1.z);
			}
		}


		if (box_pos2.x  < box_pos1.x + box_size1.x) {
			if (box_pos2.x + box_size2.x / 2 > box_pos1.x + box_size1.x) {
				box_pos1 += box_size1 / 2;
				return Vec3f(box_pos2.x - box_size1.x / 2, box_pos1.y, box_pos1.z);
			}
		}
		

		if (box_pos2.x + box_size2.x / 2 < box_pos1.x) {
			if (box_pos2.x + box_size2.x > box_pos1.x) {
				box_pos1 += box_size1 / 2;
				return Vec3f(box_pos2.x + box_size2.x + box_size1.x / 2, box_pos1.y, box_pos1.z);
			}
		}

		if (box_pos2.z  < box_pos1.z + box_size1.z) {
			if (box_pos2.z + box_size2.z / 2 > box_pos1.z + box_size1.z) {
				box_pos1 += box_size1 / 2;
				return Vec3f(box_pos1.x, box_pos1.y, box_pos2.z - box_size1.z / 2);
			}
		}

		if (box_pos2.z + box_size2.z / 2 < box_pos1.z) {
			if (box_pos2.z + box_size2.z > box_pos1.z) {
				box_pos1 += box_size1 / 2;
				return Vec3f(box_pos1.x, box_pos1.y, box_pos2.z + box_size2.z + box_size1.z / 2);
			}
		}
		box_pos1 += box_size1 / 2;
		box_pos2 += box_size2 / 2;
	}
	
	return box_pos1;
}
	
