#include "firebird_winavr.h"
#ifndef STRLEN
#  define STRLEN 81
#endif
#define _true 1
#define _false 0
typedef unsigned char boolean;
typedef int integer;
typedef char* string;
void rangoli_I_IS_DRAW(integer);
void rangoli_I_MOTOR_SHAFT_LEFT(integer);
void rangoli_I_MAX_ROW(integer);
void rangoli_I_MAX_COLUMN(integer);
void rangoli_I_GET_COLOR(integer);
void rangoli_I_GET_LENGTH(integer);
void rangoli_I_IS_FWD(integer);
void rangoli_I_BOT_MOVE(integer);
void rangoli_I_MOVEMENT_STATE(integer);
int rangoli(void);
int rangoli_reset(void);
#ifndef _NO_EXTERN_DEFINITIONS
#  ifndef _NO_CONSTANT_DEFINITIONS
#  endif /* _NO_CONSTANT_DEFINITIONS */
#  ifndef _NO_FUNCTION_DEFINITIONS
#  endif /* _NO_FUNCTION_DEFINITIONS */
#  ifndef _NO_PROCEDURE_DEFINITIONS
#  endif /* _NO_PROCEDURE_DEFINITIONS */
#endif /* _NO_EXTERN_DEFINITIONS */

static struct {
  unsigned int IS_DRAW : 1;
  unsigned int MOTOR_SHAFT_LEFT : 1;
  unsigned int MAX_ROW : 1;
  unsigned int MAX_COLUMN : 1;
  unsigned int GET_COLOR : 1;
  unsigned int GET_LENGTH : 1;
  unsigned int IS_FWD : 1;
  unsigned int BOT_MOVE : 1;
  unsigned int MOVEMENT_STATE : 1;
  unsigned int MOVE_SOFT_RIGHT : 1;
  unsigned int MOVE_FWD : 1;
  unsigned int MOVE_REV : 1;
  unsigned int MOTOR_LEFT_SPEED : 1;
  unsigned int MOTOR_RIGHT_SPEED : 1;
  unsigned int SERVO_A_ON : 1;
  unsigned int SERVO_A_OFF : 1;
  unsigned int SERVO_B_ON : 1;
  unsigned int SERVO_B_OFF : 1;
  unsigned int SERVO_C_ON : 1;
  unsigned int SERVO_C_OFF : 1;
  unsigned int DELAY : 1;
  unsigned int SET_SHAFT_L : 1;
  unsigned int SET_BOT_MOVE : 1;
  unsigned int SET_MOVEMENT_STATE : 1;
  unsigned int INCREASE_CELL_COUNT : 1;
  unsigned int SET_ROW : 1;
} _s = {  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0 };
#define tick tick_timer()
static integer IS_DRAW_v;
static integer MOTOR_SHAFT_LEFT_v;
static integer MAX_ROW_v;
static integer MAX_COLUMN_v;
static integer GET_COLOR_v;
static integer GET_LENGTH_v;
static integer IS_FWD_v;
static integer BOT_MOVE_v;
static integer MOVEMENT_STATE_v;
static integer MOTOR_LEFT_SPEED_v;
static integer MOTOR_RIGHT_SPEED_v;
static integer SERVO_A_ON_v;
static integer SERVO_A_OFF_v;
static integer SERVO_B_ON_v;
static integer SERVO_B_OFF_v;
static integer SERVO_C_ON_v;
static integer SERVO_C_OFF_v;
static integer DELAY_v;
static integer is_Draw;
static integer isFwd;
static integer dist;
static integer isDrawingFinished;
static integer isRowFinished;
static integer color;
static integer length;
static integer move_bot;
static integer state_movement;
static unsigned char _state_1 = 9;
void rangoli_I_IS_DRAW(integer _v) {
  _s.IS_DRAW = 1;
  IS_DRAW_v = _v;
}
void rangoli_I_MOTOR_SHAFT_LEFT(integer _v) {
  _s.MOTOR_SHAFT_LEFT = 1;
  MOTOR_SHAFT_LEFT_v = _v;
}
void rangoli_I_MAX_ROW(integer _v) {
  _s.MAX_ROW = 1;
  MAX_ROW_v = _v;
}
void rangoli_I_MAX_COLUMN(integer _v) {
  _s.MAX_COLUMN = 1;
  MAX_COLUMN_v = _v;
}
void rangoli_I_GET_COLOR(integer _v) {
  _s.GET_COLOR = 1;
  GET_COLOR_v = _v;
}
void rangoli_I_GET_LENGTH(integer _v) {
  _s.GET_LENGTH = 1;
  GET_LENGTH_v = _v;
}
void rangoli_I_IS_FWD(integer _v) {
  _s.IS_FWD = 1;
  IS_FWD_v = _v;
}
void rangoli_I_BOT_MOVE(integer _v) {
  _s.BOT_MOVE = 1;
  BOT_MOVE_v = _v;
}
void rangoli_I_MOVEMENT_STATE(integer _v) {
  _s.MOVEMENT_STATE = 1;
  MOVEMENT_STATE_v = _v;
}

int rangoli(void)
{
  /* Vacuous terminate */;
  switch (_state_1) {
  case 0:
    if (_s.MOVEMENT_STATE) {
      _state_1 = 8;
      isDrawingFinished = MAX_ROW_v;
      is_Draw = IS_DRAW_v;
      dist = MOTOR_SHAFT_LEFT_v;
      isRowFinished = MAX_COLUMN_v;
      color = GET_COLOR_v;
      length = GET_LENGTH_v;
      isFwd = IS_FWD_v;
      move_bot = BOT_MOVE_v;
      state_movement = MOVEMENT_STATE_v;
      if ((is_Draw == 1)) {
        if ((isDrawingFinished == 0)) {
          if ((isRowFinished == 0)) {
            if ((dist < (3 * length))) {
              (MOTOR_LEFT_SPEED_v = 110), (_s.MOTOR_LEFT_SPEED = 1);
              (MOTOR_RIGHT_SPEED_v = 110), (_s.MOTOR_RIGHT_SPEED = 1);
              if ((color == 1)) {
                (SERVO_A_ON_v = 145), (_s.SERVO_A_ON = 1);
              }
              else if ((color == 2)) {
                (SERVO_B_ON_v = 145), (_s.SERVO_B_ON = 1);
              }
              else if ((color == 3)) {
                (SERVO_C_ON_v = 145), (_s.SERVO_C_ON = 1);
              } 
              else {
                (SERVO_A_OFF_v = 160), (_s.SERVO_A_OFF = 1);
                (SERVO_B_OFF_v = 160), (_s.SERVO_B_OFF = 1);
                (SERVO_C_OFF_v = 160), (_s.SERVO_C_OFF = 1);
              }
              if ((isFwd == 1)) {
                _s.MOVE_REV = 1;
              } else {
                _s.MOVE_FWD = 1;
              }
            } else {
              (MOTOR_LEFT_SPEED_v = 0), (_s.MOTOR_LEFT_SPEED = 1);
              (MOTOR_RIGHT_SPEED_v = 0), (_s.MOTOR_RIGHT_SPEED = 1);
              _s.SET_SHAFT_L = 1;
              _s.INCREASE_CELL_COUNT = 1;
              (DELAY_v = 2000), (_s.DELAY = 1);
              if ((isFwd == 1)) {
                _s.MOVE_REV = 1;
              } else {
                _s.MOVE_FWD = 1;
              }
            }
          } else {
            (SERVO_A_OFF_v = 160), (_s.SERVO_A_OFF = 1);
			(SERVO_B_OFF_v = 160), (_s.SERVO_B_OFF = 1);
			(SERVO_C_OFF_v = 160), (_s.SERVO_C_OFF = 1);
              (DELAY_v = 8000), (_s.DELAY = 1);
            if ((state_movement == 1)) {
              /*if ((dist < 1)) {
                if ((move_bot == 1)) {
                  _s.MOVE_FWD = 1;
                  (MOTOR_LEFT_SPEED_v = 150), (_s.MOTOR_LEFT_SPEED = 1);
                  (MOTOR_RIGHT_SPEED_v = 0), (_s.MOTOR_RIGHT_SPEED = 1);
                }
                if ((move_bot == 2)) {
                  _s.MOVE_REV = 1;
                  (MOTOR_LEFT_SPEED_v = 150), (_s.MOTOR_LEFT_SPEED = 1);
                  (MOTOR_RIGHT_SPEED_v = 0), (_s.MOTOR_RIGHT_SPEED = 1);
                }
                if ((move_bot == 3)) {
                  _s.MOVE_FWD = 1;
                  (MOTOR_LEFT_SPEED_v = 150), (_s.MOTOR_LEFT_SPEED = 1);
                  (MOTOR_RIGHT_SPEED_v = 150), (_s.MOTOR_RIGHT_SPEED = 1);
                }
                if ((move_bot == 4)) {
                  _s.MOVE_REV = 1;
                  (MOTOR_LEFT_SPEED_v = 150), (_s.MOTOR_LEFT_SPEED = 1);
                  (MOTOR_RIGHT_SPEED_v = 150), (_s.MOTOR_RIGHT_SPEED = 1);
                }
                if ((move_bot == 5)) {
                  _s.SET_MOVEMENT_STATE = 1;
                  _s.SET_SHAFT_L = 1;
                  _s.SET_BOT_MOVE = 1;
                  _s.SET_ROW = 1;
                }
              }
              */
              
               if ((dist < 15)) {
					_s.MOVE_REV = 1;
					(MOTOR_LEFT_SPEED_v = 100), (_s.MOTOR_LEFT_SPEED = 1);
					(MOTOR_RIGHT_SPEED_v = 0), (_s.MOTOR_RIGHT_SPEED = 1);
				} else {
                _s.SET_MOVEMENT_STATE = 1;
                  _s.SET_SHAFT_L = 1;
                  _s.SET_BOT_MOVE = 1;
                  _s.SET_ROW = 1;
                   
               
               
               /*else{
                 _s.MOVE_FWD = 1;
                (MOTOR_LEFT_SPEED_v = 0), (_s.MOTOR_LEFT_SPEED = 1);
                (MOTOR_RIGHT_SPEED_v = 0), (_s.MOTOR_RIGHT_SPEED = 1);
                _s.SET_SHAFT_L = 1;
                _s.SET_BOT_MOVE = 1;
              */}
            }
            if ((state_movement == 0)) {
              if ((dist < 15)) {
                _s.MOVE_FWD = 1;
                (MOTOR_LEFT_SPEED_v = 100), (_s.MOTOR_LEFT_SPEED = 1);
                (MOTOR_RIGHT_SPEED_v = 0), (_s.MOTOR_RIGHT_SPEED = 1);
              } else {
                _s.MOVE_FWD = 1;
                (MOTOR_LEFT_SPEED_v = 0), (_s.MOTOR_LEFT_SPEED = 1);
                (MOTOR_RIGHT_SPEED_v = 0), (_s.MOTOR_RIGHT_SPEED = 1);
                if ((dist < 22)) {
                  _s.MOVE_FWD = 1;
                  (MOTOR_LEFT_SPEED_v = 100), (_s.MOTOR_LEFT_SPEED = 1);
                  (MOTOR_RIGHT_SPEED_v = 100), (_s.MOTOR_RIGHT_SPEED = 1);
                } else {
                  _s.MOVE_FWD = 1;
                  (MOTOR_LEFT_SPEED_v = 0), (_s.MOTOR_LEFT_SPEED = 1);
                  (MOTOR_RIGHT_SPEED_v = 0), (_s.MOTOR_RIGHT_SPEED = 1);
                  _s.SET_SHAFT_L = 1;
                  _s.SET_MOVEMENT_STATE = 1;
                  (DELAY_v = 8000), (_s.DELAY = 1);
                }
              }
            }
          }
        } else {
          (MOTOR_LEFT_SPEED_v = 0), (_s.MOTOR_LEFT_SPEED = 1);
          (MOTOR_RIGHT_SPEED_v = 0), (_s.MOTOR_RIGHT_SPEED = 1);
          if ((isFwd == 0)) {
            _s.MOVE_FWD = 1;
          } else {
            _s.MOVE_REV = 1;
          }
        }
      }
    } else {
      _state_1 = 0;
    }
    break;
  case 1:
    if (_s.BOT_MOVE) {
      _state_1 = 0;
    } else {
      _state_1 = 1;
    }
    break;
  case 2:
    if (_s.IS_FWD) {
      _state_1 = 1;
    } else {
      _state_1 = 2;
    }
    break;
  case 3:
    if (_s.GET_LENGTH) {
      _state_1 = 2;
    } else {
      _state_1 = 3;
    }
    break;
  case 4:
    if (_s.GET_COLOR) {
      _state_1 = 3;
    } else {
      _state_1 = 4;
    }
    break;
  case 5:
    if (_s.MAX_COLUMN) {
      _state_1 = 4;
    } else {
      _state_1 = 5;
    }
    break;
  case 6:
    if (_s.MAX_ROW) {
      _state_1 = 5;
    } else {
      _state_1 = 6;
    }
    break;
  case 7:
    if (_s.MOTOR_SHAFT_LEFT) {
      _state_1 = 6;
    } else {
      _state_1 = 7;
    }
    break;
  case 8:
    if (_s.IS_DRAW) {
      _state_1 = 7;
    } else {
      _state_1 = 8;
    }
    break;
  case 9:
    _s.SET_ROW = 0;;
    _s.INCREASE_CELL_COUNT = 0;;
    _s.SET_MOVEMENT_STATE = 0;;
    _s.SET_BOT_MOVE = 0;;
    _s.SET_SHAFT_L = 0;;
    _s.DELAY = 0;;
    _s.SERVO_C_OFF = 0;;
    _s.SERVO_C_ON = 0;;
    _s.SERVO_B_OFF = 0;;
    _s.SERVO_B_ON = 0;;
    _s.SERVO_A_OFF = 0;;
    _s.SERVO_A_ON = 0;;
    _s.MOTOR_RIGHT_SPEED = 0;;
    _s.MOTOR_LEFT_SPEED = 0;;
    _s.MOVE_REV = 0;;
    _s.MOVE_FWD = 0;;
    _s.MOVE_SOFT_RIGHT = 0;;
    (SERVO_A_OFF_v = 160), (_s.SERVO_A_OFF = 1);
    (SERVO_B_OFF_v = 160), (_s.SERVO_B_OFF = 1);
    (SERVO_C_OFF_v = 160), (_s.SERVO_C_OFF = 1);
    _state_1 = 8;
    break;
  default: break;
  }
  if (_s.MOVE_SOFT_RIGHT) { rangoli_O_MOVE_SOFT_RIGHT(); _s.MOVE_SOFT_RIGHT = 0; }
  if (_s.MOVE_FWD) { rangoli_O_MOVE_FWD(); _s.MOVE_FWD = 0; }
  if (_s.MOVE_REV) { rangoli_O_MOVE_REV(); _s.MOVE_REV = 0; }
  if (_s.MOTOR_LEFT_SPEED) { rangoli_O_MOTOR_LEFT_SPEED(MOTOR_LEFT_SPEED_v); _s.MOTOR_LEFT_SPEED = 0; }
  if (_s.MOTOR_RIGHT_SPEED) { rangoli_O_MOTOR_RIGHT_SPEED(MOTOR_RIGHT_SPEED_v); _s.MOTOR_RIGHT_SPEED = 0; }
  if (_s.SERVO_A_ON) { rangoli_O_SERVO_A_ON(SERVO_A_ON_v); _s.SERVO_A_ON = 0; }
  if (_s.SERVO_A_OFF) { rangoli_O_SERVO_A_OFF(SERVO_A_OFF_v); _s.SERVO_A_OFF = 0; }
  if (_s.SERVO_B_ON) { rangoli_O_SERVO_B_ON(SERVO_B_ON_v); _s.SERVO_B_ON = 0; }
  if (_s.SERVO_B_OFF) { rangoli_O_SERVO_B_OFF(SERVO_B_OFF_v); _s.SERVO_B_OFF = 0; }
  if (_s.SERVO_C_ON) { rangoli_O_SERVO_C_ON(SERVO_C_ON_v); _s.SERVO_C_ON = 0; }
  if (_s.SERVO_C_OFF) { rangoli_O_SERVO_C_OFF(SERVO_C_OFF_v); _s.SERVO_C_OFF = 0; }
  if (_s.DELAY) { rangoli_O_DELAY(DELAY_v); _s.DELAY = 0; }
  if (_s.SET_SHAFT_L) { rangoli_O_SET_SHAFT_L(); _s.SET_SHAFT_L = 0; }
  if (_s.SET_BOT_MOVE) { rangoli_O_SET_BOT_MOVE(); _s.SET_BOT_MOVE = 0; }
  if (_s.SET_MOVEMENT_STATE) { rangoli_O_SET_MOVEMENT_STATE(); _s.SET_MOVEMENT_STATE = 0; }
  if (_s.INCREASE_CELL_COUNT) { rangoli_O_INCREASE_CELL_COUNT(); _s.INCREASE_CELL_COUNT = 0; }
  if (_s.SET_ROW) { rangoli_O_SET_ROW(); _s.SET_ROW = 0; }
  _s.IS_DRAW = 0;
  _s.MOTOR_SHAFT_LEFT = 0;
  _s.MAX_ROW = 0;
  _s.MAX_COLUMN = 0;
  _s.GET_COLOR = 0;
  _s.GET_LENGTH = 0;
  _s.IS_FWD = 0;
  _s.BOT_MOVE = 0;
  _s.MOVEMENT_STATE = 0;
  return 1;
}

int rangoli_reset(void)
{
  _s.IS_DRAW = 0;
  _s.MOTOR_SHAFT_LEFT = 0;
  _s.MAX_ROW = 0;
  _s.MAX_COLUMN = 0;
  _s.GET_COLOR = 0;
  _s.GET_LENGTH = 0;
  _s.IS_FWD = 0;
  _s.BOT_MOVE = 0;
  _s.MOVEMENT_STATE = 0;
  return 0;
}
/****************************** Fire Bird Specific part ***************************/
static int  IR_THRESHHOLD[3] = {50, 50, 50};
rangoli_O_INCREASE_CELL_COUNT(void)
{
	increase_cell_count();
}
rangoli_O_MOTOR_LEFT_SPEED(int val)
{
	MOTOR_LEFT_SPEED(val);
}
rangoli_O_DELAY(integer val)
{
	DELAY(val);
}
rangoli_O_SERVO_C_ON(integer val)
{
	SERVO_C_DIRECTION(val);
}
rangoli_O_SERVO_B_ON(integer val)
{
	SERVO_B_DIRECTION(val);
}
 rangoli_O_MOVE_REV(void)
{
	MOVE_REV();
}
rangoli_O_SET_ROW(void)
{
	set_currentCol();
}
rangoli_O_SERVO_A_ON(integer val)
{
	SERVO_A_DIRECTION(val);
}
rangoli_O_SERVO_A_OFF(integer val)
{
	SERVO_A_DIRECTION(val);
}
rangoli_O_MOVE_FWD(void)
{
	MOVE_FWD();
}
rangoli_O_SET_MOVEMENT_STATE(void)
{
	set_movement_state();
}
rangoli_O_SET_SHAFT_L(void)
{
	set_shaft_l();
}
rangoli_O_SET_BOT_MOVE(void)
{
	set_bot_move();
}
rangoli_O_MOTOR_RIGHT_SPEED(int val)
{
	MOTOR_RIGHT_SPEED(val);
}
 rangoli_O_MOVE_SOFT_RIGHT(void)
{
	MOVE_SOFT_RIGHT();
}
rangoli_O_SERVO_B_OFF(integer val)
{
	SERVO_B_DIRECTION(val);
}
rangoli_O_SERVO_C_OFF(integer val)
{
	SERVO_C_DIRECTION(val);
}


void help(){
rangoli_I_IS_DRAW(1);
    rangoli_I_MOTOR_SHAFT_LEFT(0);
    rangoli_I_MAX_ROW(0);
    rangoli_I_MAX_COLUMN(1);
    rangoli_I_GET_COLOR(1);
    rangoli_I_GET_LENGTH(5);
    rangoli_I_IS_FWD(0);
    rangoli_I_BOT_MOVE(5);
    rangoli_I_MOVEMENT_STATE(0);
}


void help2(){
rangoli_I_IS_DRAW(1);
    rangoli_I_MOTOR_SHAFT_LEFT(0);
    rangoli_I_MAX_ROW(0);
    rangoli_I_MAX_COLUMN(0);
    rangoli_I_GET_COLOR(0);
    rangoli_I_GET_LENGTH(5);
    rangoli_I_IS_FWD(0);
    rangoli_I_BOT_MOVE(5);
    rangoli_I_MOVEMENT_STATE(0);
}

/****************************** Main function ***************************/
void main()
{
 init_devices();
 rangoli_reset();
 rangoli();
//i = 0;

 while(1)
 {
	//botMove = 5;
	rangoli_I_IS_DRAW(ISDRAW);
    rangoli_I_MOTOR_SHAFT_LEFT(MOTOR_SHAFT_L);
    rangoli_I_MAX_ROW(MAXROW);
    rangoli_I_MAX_COLUMN(MAXCOLUMN);
    rangoli_I_GET_COLOR(GETCOLOR);
    rangoli_I_GET_LENGTH(GETLENGTH);
    rangoli_I_IS_FWD(ISFWD);
    rangoli_I_BOT_MOVE(BOTMOVE);
    rangoli_I_MOVEMENT_STATE(MOVEMENTSTATE);
    
		    
   // if (i==0) help();
	//	if(i == 1) help2();
	
    
    rangoli();
 }
}
