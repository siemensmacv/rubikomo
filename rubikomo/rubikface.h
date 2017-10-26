#pragma once
#include <QColor>

enum class RubikFace
{
	Up = 0,
    Right,
    Front,
    Down,
	Left,
    Back,
    Grey
};

#ifdef __cplusplus
extern "C" {
#endif
int colorLetterToDigit(char c);
char colorDigitToLetter(int d);
char colorEnumToLetter(RubikFace face);
QColor colorDigitToQColor(int d);
QColor colorEnumToQColor(RubikFace face);
RubikFace qColorToEnum(QColor color);
#ifdef __cplusplus
}
#endif
