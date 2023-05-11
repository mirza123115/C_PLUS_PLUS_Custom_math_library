#include <iostream>
using namespace std;

#define PI 3.141592653589793238462643383279502884197
#define E 2.71828182845904523536028747135266249775724709369995


#define SQ(x) ((x)*(x))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)


#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))


float ABS(float x){
        return x>0?x:-x;
    }

long  double POW(float x,float y){
    long double value=1;
    for (int i=1;i<=ABS(y);i++){
            value*=x;
    }
    if  (y<0){
        return 1/value;
    }
    else if(y==0){
        return 1;
    }
    else {
        return value;
    }
}


/*double POW(double a, double x) {
    return EXP(x * log(a));
}*/

long double SQRT(float x){

}
long double CBRT(float x){

}

long double e(){
    long double n=2000;
    return POW((1+1/n),n);

}
long double e2(){
    long double n=.00001;
    return POW((1+n),1/n);

}
long double LOG(float  x){
    long double sum=0;
    for(int n=1;n<=6;n++){
        sum+=(POW(-1,n+1)*POW(x-1,n))/n;
    }
    return sum;
}

/*long double LOG(float  x){
    long double y=x-1;
    long double sum=0;
    for(int n=1;n<=33;n++){
        sum+=(POW(-1,n-1)*POW(y,n))/n;
    }
    return sum;
}*/


long double  LOG10(float x){

}
long double  LOG2(float x){

}
long double  SIGNUMM(float x){

}
long double  ERF(float x){

}
long long int FACT(int n){
    return n>0?n*FACT(n-1):1;
}
long double A_POW_X(float A,float X){
    long double sum=1;
    for(int i=1;i<=50;i++){
        sum+=POW(X*LOG(A),i)/FACT(i);
    }
    return sum;
}
long double  HYPOT(float x,float y){
    return  SQRT(POW(x,2)+POW(y,2));
}

long long int GAMMA(float x){
    return FACT(x-1);
}
long long int PERM(int  n,int r){
    return FACT(n)/FACT(n-r);
}
long long int COMB(int  n,int r){
    return FACT(n)/(FACT(r)*FACT(n-r));
}
int  CEIL(float x){
    return int(x);
}
int  FLOOR(float x){
    return int(x)+1;
}
int  ROUND(float x){
    return x-CEIL(x)>FLOOR(x)-x?FLOOR(x):CEIL(x);
}
float  COPY_SIGN(float x,float y){
    return (x>0)^(y>0)==0?x:-x;
}
/*long double  EXP(float x){
    long double sum=0;
    for(int i=0;i<=20;i++){
        sum+=POW(x,i)/FACT(i);
    }
    return sum;
    //return POW(E,x);
}*/
long double  EXP(float x){
    long double n=3000;

    return POW((1+x/n),n);
    //return POW(E,x);
}
long double  INVERSE(float x){
    long double sum=0;
    for(int i=0;i<=20;i++){
        sum+=POW(-1,i)/POW(x-1,i);
    }
    return sum;
    //return 1/x;
}
float MAX(float x,float y){
    return x-y>0?x:y;
}
float MIN(float x,float y){
    return x-y<0?x:y;
}
float DEG_2_RAD(float x){
    return (PI*x)/180;
}
float RAD_2_DEG(float x){
    return (180*x)/PI;
}
long double SIN(float  x){
    long double sum=0;
    float  y=DEG_2_RAD(x);
    for(int n=0;n<=20;n++){
        sum+=(POW(-1,n)*POW(y,2*n+1))/FACT(2*n+1);
    }
    return sum;
}
long double COS(float  x){
    long double sum=0;
    float  y=DEG_2_RAD(x);
    for(int n=0;n<=20;n++){
        sum+=(POW(-1,n)*POW(y,2*n))/FACT(2*n);
    }
    return sum;
}
long double TAN(float x){
    return  SIN(x)/COS(x);
}
long double ASIN(float x){
    int val=0;
    long double SUM=x;
    long long int MUL1=1;
    long long int MUL2=1;
    for(int n=1;n<=35;n+=2){
        MUL1*=n;
        MUL2*=n+1;
        SUM+=(MUL1/MUL2)*(POW(x,n+2)/n+2);
        val= int(RAD_2_DEG(SUM))%360;
    }
    return val;
}
long double ACOS(float x){
        return 90-ASIN(x);

}
long double ATAN(float x){
    long double SUM1=0;
    long double SUM2=(PI/2);
    for(int n=0;n<=30;n++){
        SUM1+=(POW(-1,n)*POW(x,2*n+1))/(2*n+1);
        SUM2+=(-POW(-1,n))/(2*n+1)*POW(x,2*n+1);
    }
    return x<1?RAD_2_DEG(SUM1):RAD_2_DEG(SUM2);
}
float SINH(float x){
    return (POW(E,x)-POW(E,-x))/2;
}
float COSH(float x){
    return (POW(E,x)+POW(E,-x))/2;
}
float TANH(float x){
    return SINH(x)/COSH(x);
}
long double ASINH(float x){

}
long double ACOSH(float x){

}
long double ATANH(float x){

}



double power(double base, int exponent) {
    double result = 1.0;
    if (exponent < 0) {
        base = 1.0 / base;
        exponent = -exponent;
    }
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}







int main()
{
    cout<<"E "<<E<<endl;
    cout<<"PI "<<PI<<endl;
    cout<<"ABS(-4.3) "<<ABS(-4.3)<<endl;
    cout<<"POW(2,127) "<<POW(2,127)<<endl;
    cout<<"e() "<<e()<<endl;
    cout<<"e2() "<<e2()<<endl;
    cout<<"A_POW_X(2,3) "<<A_POW_X(2,3)<<endl;
    cout<<"FACT(20) "<<FACT(20)<<endl;
    cout<<"GAMMA(20) "<<GAMMA(20)<<endl;
    cout<<"PERM(5,3)  "<<PERM(5,3)<<endl;
    cout<<"COMB(6,3)  "<<COMB(6,3)<<endl;
    cout<<"CEIL(5.6) "<<CEIL(5.6)<<endl;
    cout<<"FLOOR(5.6) "<<FLOOR(5.6)<<endl;
    cout<<"ROUND(5.4)  "<<ROUND(5.4)<<endl;
    cout<<"COPY_SIGN(2,-4)  "<<COPY_SIGN(2,-4)<<endl;
    cout<<"EXP(2.3) "<<EXP(10.7)<<endl;
    cout<<"MAX(E,3)  "<<MAX(E,3)<<endl;
    cout<<"MIN(E,3) "<<MIN(E,3)<<endl;
    cout<<"LOG(3) "<<LOG(3)<<endl;
    cout<<"DEG_2_RAD(180) "<<DEG_2_RAD(180)<<endl;
    cout<<"RAD_2_DEG(1)  "<<RAD_2_DEG(1)<<endl;
    cout<<"SIN(30) "<<SIN(30)<<endl;
    cout<<"ASIN(.5) "<<ASIN(.5)<<endl;
    cout<<"COS(60)  "<<COS(60)<<endl;
    cout<<"ACOS(.5)  "<<ACOS(.5)<<endl;
    cout<<"TAN(45)  "<<TAN(45)<<endl;
    cout<<"ATAN(1)  "<<ATAN(1)<<endl;
    cout<<"SINH(1) "<<SINH(1)<<endl;
    cout<<"COSH(1) "<<COSH(1)<<endl;
    cout<<"TANH(1) "<<TANH(1)<<endl;
    cout<<"SQ(2) "<<SQ(2)<<endl;
    cout<<"INVERSE(2) "<<INVERSE(2) <<endl;
    std::cout << power(2.0, 5.5) << std::endl; // output: 1024




    return 0;
}
