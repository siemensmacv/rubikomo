#include "rubikfaceutils.h"

int RubikFaceUtils::colorLetterToDigit(char c)
{
    RubikFace face;
    switch(c)
    {
    case 'U':
        face = RubikFace::Up;
        break;
    case 'R':
        face = RubikFace::Right;
        break;
    case 'F':
        face = RubikFace::Front;
        break;
    case 'D':
        face = RubikFace::Down;
        break;
    case 'L':
        face = RubikFace::Left;
        break;
    case 'B':
        face = RubikFace::Back;
        break;
    default:
        face = RubikFace::Grey;
    }

    return static_cast<int>(face);
}

char RubikFaceUtils::colorDigitToLetter(int d)
{
    RubikFace face = static_cast<RubikFace>(d);
    return colorEnumToLetter(face);
}

char RubikFaceUtils::colorEnumToLetter(RubikFace face)
{
    switch(face)
    {
    case RubikFace::Back:
        return 'B';
    case RubikFace::Down:
        return 'D';
    case RubikFace::Front:
        return 'F';
    case RubikFace::Left:
        return 'L';
    case RubikFace::Right:
        return 'R';
    case RubikFace::Up:
        return 'U';
    default:
        return 'G';
    }
}

QColor RubikFaceUtils::colorDigitToQColor(int d)
{
    RubikFace face = static_cast<RubikFace>(d);
    return colorEnumToQColor(face);
}

QColor RubikFaceUtils::colorEnumToQColor(RubikFace face)
{
    switch(face)
    {
    case RubikFace::Up:
        return QColor(255, 255, 0);
    case RubikFace::Right:
        return QColor(255, 130, 0);
    case RubikFace::Front:
        return QColor(0, 255, 0);
    case RubikFace::Down:
        return QColor(255, 255, 255);
    case RubikFace::Left:
        return QColor(255, 0, 0);
    case RubikFace::Back:
        return QColor(0, 0, 255);
    default:
        return QColor(128,128,128);
    }
}

RubikFace RubikFaceUtils::qColorToEnum(QColor color)
{
    if(color == QColor(255, 255, 0))
        return RubikFace::Up;

    if(color == QColor(255, 130, 0))
        return RubikFace::Right;

    if(color == QColor(0, 255, 0))
        return RubikFace::Front;

    if(color == QColor(255, 255, 255))
        return RubikFace::Down;

    if(color == QColor(255, 0, 0))
        return RubikFace::Left;

    if(color == QColor(0, 0, 255))
        return RubikFace::Back;

    return RubikFace::Grey;
}
