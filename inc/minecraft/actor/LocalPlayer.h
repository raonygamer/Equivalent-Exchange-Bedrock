#pragma once
#include "Player.h"

class NetworkIdentifier;
class Certificate;
namespace mce {
	class UUID {};
}

class LocalPlayer : public Player {
public:
	LocalPlayer(IClientInstance&, Level&, std::string const&, GameType, NetworkIdentifier const&, unsigned char, mce::UUID, std::string const&, std::unique_ptr<Certificate>);
};