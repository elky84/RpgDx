#pragma once

#include "weak_raw_ptr.hpp"
#include <memory>

#include "Position.h"

namespace RM
{

struct ModeID
{
	enum Type
	{
		NONE = -1,
		OPENING = 0,
		SETTING = 1,
		GAME = 2,
	};
};

static const int MAX_SCROLL_X = 1280;
static const int MAX_SCROLL_Y = 1280;
static const int TILE_SIZE = 32;

typedef INT CHARACTER_INDEX;

const int MAX_PARTY_CHARACTER = 4;

const int MAX_DECK = 6;

class Turn;
typedef std::unique_ptr<Turn> UNIQUE_TURN;
typedef light::weak_raw_ptr<Turn> WEAK_TURN;

class Action;
typedef std::shared_ptr<Action> SHARED_ACTION;
typedef std::unique_ptr<Action> UNIQUE_ACTION;
typedef light::weak_raw_ptr<Action> WEAK_ACTION;

class Map;
typedef std::unique_ptr<Map> UNIQUE_MAP;
typedef light::weak_raw_ptr<Map> WEAK_MAP;

class Character;
typedef std::shared_ptr<Character> SHARED_CHARACTER;
typedef std::unique_ptr<Character> UNIQUE_CHARACTER;
typedef light::weak_raw_ptr<Character> WEAK_CHARACTER;

class Player;
typedef std::shared_ptr<Player> SHARED_PLAYER;
typedef std::unique_ptr<Player> UNIQUE_PLAYER;
typedef light::weak_raw_ptr<Player> WEAK_PLAYER;

class Party;
typedef std::unique_ptr<Party> UNIQUE_PARTY;
typedef light::weak_raw_ptr<Party> WEAK_PARTY;

typedef std::vector<WEAK_PARTY> VECTOR_PARTY;
typedef std::unique_ptr< VECTOR_PARTY > UNIQUE_VECTOR_PARTY;
typedef light::weak_raw_ptr< VECTOR_PARTY > WEAK_VECTOR_PARTY;

class Game;
typedef std::unique_ptr<Game> UNIQUE_GAME;
typedef light::weak_raw_ptr<Game> WEAK_GAME;

} // namespace RM

namespace ExcelData
{

class Class;
typedef std::unique_ptr<Class> UNIQUE_CLASS;
typedef light::weak_raw_ptr<Class> WEAK_CLASS;

class Tribe;
typedef std::unique_ptr<Tribe> UNIQUE_TRIBE;
typedef light::weak_raw_ptr<Tribe> WEAK_TRIBE;

} // namespace ExcelData