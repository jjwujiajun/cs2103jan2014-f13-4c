#include "Headers.h"
#pragma once

ref struct Theme {
	System::Drawing::Color background;
	System::Drawing::Color label;
	System::Drawing::Color index;
	System::Drawing::Color taskListHeadings;
	System::Drawing::Color words;
};

static array<Theme^>^ prepareThemes() {
	array <Theme^> ^ themeArray = gcnew array<Theme^> (THEME_NUMBER);

	Theme ^whiteTheme;
	whiteTheme = gcnew Theme;
	whiteTheme->background = System::Drawing::Color::White;
	whiteTheme->label = System::Drawing::Color::CornflowerBlue;
	whiteTheme->index = System::Drawing::Color::Gray;
	whiteTheme->taskListHeadings = System::Drawing::Color::CornflowerBlue;
	whiteTheme->words = System::Drawing::Color::Black;
		 
	Theme ^blueTheme;
	blueTheme = gcnew Theme;
	blueTheme->background = System::Drawing::Color::CornflowerBlue;
	blueTheme->label = System::Drawing::Color::White;
	blueTheme->index = System::Drawing::Color::White;
	blueTheme->taskListHeadings = System::Drawing::Color::White;
	blueTheme->words = System::Drawing::Color::Black;
		 
	Theme ^metallicTheme;
	metallicTheme = gcnew Theme;
	metallicTheme->background = System::Drawing::Color::Gray;
	metallicTheme->label = System::Drawing::Color::Black;
	metallicTheme->index = System::Drawing::Color::White;
	metallicTheme->taskListHeadings = System::Drawing::Color::Black;
	metallicTheme->words = System::Drawing::Color::WhiteSmoke;

	themeArray[0] = whiteTheme;
	themeArray[1] = blueTheme;
	themeArray[2] = metallicTheme;

	return themeArray;
}

ref class Themes
{
public:
	Themes(void);
};

