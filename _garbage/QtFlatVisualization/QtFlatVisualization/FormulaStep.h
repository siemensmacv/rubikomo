#pragma once

// define a formula step
// each step is defined by one of the face movements and the type
class FormulaStep
{
public:
    typedef enum _FormulaStepMoveEnum {FSM_U, FSM_R, FSM_F, FSM_D, FSM_L, FSM_B} FormulaStepMoveEnum;
    typedef enum _FormulaStepTypeEnum {FST_CLOCK, FST_COUNTER, FST_DOUBLE} FormulaStepTypeEnum;

    FormulaStep( FormulaStepMoveEnum FSE, FormulaStepTypeEnum FST );
    FormulaStep( char desc[3] );
    FormulaStep( );

private:
    FormulaStepMoveEnum mFSE;
    FormulaStepTypeEnum mFST;
    char mDesc[3];
};
