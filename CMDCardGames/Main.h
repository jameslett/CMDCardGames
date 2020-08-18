#pragma once
#include <iostream>
#include "Dealer.h"
#include <vector>

std::vector<std::shared_ptr<Player>> players;

void AddPlayers(int numPlayers);