
#include <stdio.h>
#include <stdint.h>

#define ACCUPPERLIMIT   65
#define ACCLOWERLIMIT   (-65)
#define ACC_VAL_LIMIT   180
int8_t check_limit(int8_t val)
{
    int8_t ret_val = val;
    
    if( val > ACCUPPERLIMIT ) 
        ret_val = ACCUPPERLIMIT;
    else if( val < ACCLOWERLIMIT ) 
        ret_val = ACCLOWERLIMIT;

    return ret_val;
}


int16_t checkOver180limit(int16_t val)
{
    int16_t ret_val = val;
    
    if( val > ACC_VAL_LIMIT ) 
        ret_val = val-360;
    return ret_val;
}

int main()
{
    uint16_t temp;
    float test_val;
    float square_val;
    int8_t temp_limit_val;

    int8_t AcceXValue=-90;
    int8_t AcceYValue=60;
    int8_t AcceZValue=10;

    int16_t CalcedXValue;
    int16_t CalcedYValue;
    int16_t CalcedZValue;

    temp_limit_val = check_limit(AcceXValue);
    test_val = (float)(temp_limit_val*((float)90.0/(float)65.0));
    if(AcceZValue > 0) {
        test_val = 180.0 - test_val;
    }
    CalcedXValue = (int16_t)(test_val*1.0);
    CalcedXValue = checkOver180limit(CalcedXValue);
    //DBGERR(SEN,"X: test(%f), orig(%d),Calced(%d)\r\n",test_val,AcceXValue,CalcedXValue);

    temp_limit_val = check_limit(AcceYValue);
    test_val = (float)(temp_limit_val*((float)90.0/(float)65.0));
    if(AcceZValue > 0) {
        test_val = 180.0 - test_val;
    }
    CalcedYValue = (int16_t)(test_val*1.0);
    CalcedYValue = checkOver180limit(CalcedYValue);
    //DBGERR(SEN,"Y: test(%f), orig(%d),Calced(%d)\r\n",test_val,AcceYValue,CalcedYValue);

    temp_limit_val = check_limit(AcceZValue);

    square_val = (float)temp_limit_val/(float)65.0;
    square_val = square_val * square_val;

    if(AcceZValue < 0)
        test_val = (float)(90 - square_val*90.0);
    else
        test_val = (float)(90 + square_val*90.0);  

    CalcedZValue = (int16_t)(test_val*1.0);

    return 0;
}