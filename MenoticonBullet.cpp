#include "MenoticonBullet.h"
#include "constants.h"

bool MenoticonBullet::CollidesWith(GameObject* go) {
	switch(go->type) {
		case PLAYER:
			return Collides(go);
			break;
		case RUNOTICON:
		case MENOTICON: 
		case SHIPWRECK: 
		case PLAYER_BULLET:
		case MENOTICON_BULLET:
	    case SPIKOTICON:
			return false; // no collision
			break;
	}
	return false; // default too no collision
}
