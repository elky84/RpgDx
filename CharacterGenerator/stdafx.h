#pragma once

#include "light-view.h"
#include "RMTypeDefinition.h"

static const int WINDOW_WIDTH = 1024;
static const int WINDOW_HEIGHT = 768;

static const int IMAGE_UNIT = 80;
static const int TEXT_UNIT = 20;
static const int FONT_SIZE = 10;

static const int GAME_UI_TOP = 60;
static const int GAME_UI_BOTTOM = WINDOW_HEIGHT - GAME_UI_TOP;

static const int GAME_UI_LEFT = 0;
static const int GAME_UI_RIGHT = GAME_UI_LEFT + RM::MAX_PARTY_CHARACTER * (IMAGE_UNIT + 5) - 5;